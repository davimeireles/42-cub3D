#!/bin/bash

NAME="cub3d"
MAP_DIR="maps/bad"
OUTPUT_FILE="heap_summaries_bad_maps.txt"

if [ ! -d "$MAP_DIR" ]; then
  echo "Diretório $MAP_DIR não encontrado!"
  exit 1
fi

> "$OUTPUT_FILE"

for map in "$MAP_DIR"/*.cub; do
  if [ -f "$map" ]; then
    echo "Executando Valgrind no mapa: $map"
    VALGRIND_OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all ./$NAME "$map" 2>&1)
    HEAP_USAGE=$(echo "$VALGRIND_OUTPUT" | grep "total heap usage")
    ERROR_OUTPUT=$(echo "$VALGRIND_OUTPUT" | grep -A 1 "Error")
    echo -e "$map:\n$ERROR_OUTPUT\n$HEAP_USAGE\n" >> "$OUTPUT_FILE"
  fi
done

echo "Resumos do heap salvos em $OUTPUT_FILE"