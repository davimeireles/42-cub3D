#!/bin/bash

# Nome do programa
NAME="cub3d"

# Diretório dos mapas
MAP_DIR="maps/valid"

# Verifica se o diretório de mapas existe
if [ ! -d "$MAP_DIR" ]; then
  echo "Diretório $MAP_DIR não encontrado!"
  exit 1
fi

# Itera sobre todos os arquivos .cub no diretório de mapas
for map in "$MAP_DIR"/*.cub; do
  if [ -f "$map" ]; then
    echo "Executando Valgrind no mapa: $map"
    valgrind --leak-check=full --show-leak-kinds=all ./$NAME "$map"
  fi
done
