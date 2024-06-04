################################################################################
#                                 Main Config                                  #
################################################################################

NAME = cub3d 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3
DFLAGS	= -MMD -MF $(@:.o=.d)
RM = rm -rf
AUTHOR	= dmeireles
DATE	= 08/04/2024
HASH	= 
NOVISU 	= 0

################################################################################
#                     Makefile Sources and Objects Config                      #
################################################################################


FILE_EXTENSION	= .c

SRCS_PATH		= ./srcs
INCLUDE_PATH	= ./srcs

SRCS			= map_checker.c
MAIN			= main.c

SHELL := /bin/bash

OBJS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
OBJ_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.o})
DEPS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.d})
DEPS_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.d})

LIBFT = libft/libft.a
LIBFT_DIR = libft/

################################################################################
#                                 Colors/String                                #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m
COM_STRING  = "compiling"

################################################################################
#                                 Check OS                                     #
################################################################################

## A linha de comando define a variável detected_OS com base no sistema operacional em que o script está sendo executado.
## Se for Windows, a variável detected_OS será definida como "Windows". 
## Caso contrário, será definida como o resultado do comando uname, que fornece informações sobre o sistema operacional em sistemas Unix/Linux.
## Se o comando uname falhar, será definido como "Unknown".

ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

################################################################################
#                         Define Commands for OS/GIT                           #
################################################################################

## As linhas de comando condicionais definem diferentes comandos para serem executados com base no sistema operacional detectado (detected_OS).
## Isso permite que o Makefile seja mais flexível e execute comandos específicos dependendo do ambiente em que está sendo executado.

ifeq ($(detected_OS),Darwin) 
	RUN_CMD = script -q $@.log $1 > /dev/null; \
				RESULT=$$?
else ifeq ($(detected_OS),Linux)
	RUN_CMD = script -q -e -c "$(1)" $@.log > /dev/null; \
				RESULT=$$?; \
				sed -i '1d' $@.log; \
				sed -i "$$(($$(wc -l < $@.log)-1)),\$$d" $@.log
else
	RUN_CMD = $(1) 2> $@.log; \
				RESULT=$$?
endif

## As linhas de comando estão condicionadas para serem executadas apenas se o diretório atual for um repositório Git.
## Se for o caso, elas obtêm informações úteis sobre o repositório, como o autor, a data e o hash do último commit.

ifeq ($(shell git rev-parse HEAD &>/dev/null; echo $$?),0)
	AUTHOR	:= $(shell git log --format='%aN' | sort -u | awk '{printf "%s, ", $$0}' | rev | cut -c 3- | rev)
	DATE	:= $(shell git log -1 --date=format:"%Y/%m/%d %T" --format="%ad")
	HASH	:= $(shell git rev-parse --short HEAD)
endif

## Esta macro é usada para executar comandos e testar se a execução foi bem-sucedida, fornecendo feedback visual na saída do Makefile. 
## Dependendo do resultado da execução, mensagens de sucesso, aviso ou erro são exibidas, e o conteúdo do arquivo de log é exibido e removido.

define run_and_test
printf "%b%-46b" "$(COM_COLOR)$(COM_STRING) " "$(OBJ_COLOR)$(@F)$(NO_COLOR)"; \
$(RUN_CMD); \
if [ $$RESULT -ne 0 ]; then \
	printf "%b\n" "$(ERROR_COLOR)[✖]$(NO_COLOR)"; \
	rm -rf .files_changed; \
	if [ $(NOVISU) -eq 0 ]; then \
		echo; \
	fi; \
elif [ -s $@.log ]; then \
	printf "%b\n" "$(WARN_COLOR)[⚠]$(NO_COLOR)"; \
else  \
	printf "%b\n" "$(OK_COLOR)[✓]$(NO_COLOR)"; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

## Essa macro é usada para otimizar o processo de compilação
## Evitando recompilações desnecessárias quando apenas arquivos de cabeçalho modificados precisam ser reconstruídos.

define save_files_changed
	FILE_C=`echo $(SRCS) $(MAIN)`; \
	FILE_OBJ=`find objs -type f -name '*.o' 2>/dev/null | sed 's/objs\///'`; \
	TO_COMPILE=`echo $$FILE_C | wc -w`; \
	for FILE in $$FILE_C; do \
		for OBJ in $$FILE_OBJ; do \
			if [ $${FILE%$(FILE_EXTENSION)} = $${OBJ%.o} ]; then \
				if [ $(SRCS_PATH)/$$FILE -ot objs/$$OBJ ]; then \
					FILE_DEP=`echo objs/$$OBJ | sed 's/\.o/\.d/'`; \
					HEAD_FILES=`< $$FILE_DEP xargs | grep -oh "\w*.h\w*"`; \
					RECOMPILE=0; \
					for HEAD in $$HEAD_FILES; do \
						if [ $(SRCS_PATH)/$$HEAD -nt objs/$$OBJ ]; then \
							RECOMPILE=1; \
							break; \
						fi; \
					done; \
					if [ $$RECOMPILE -eq 0 ]; then \
						((TO_COMPILE=$$TO_COMPILE-1)); \
					fi;\
				fi; \
			fi; \
		done; \
	done; \
	echo 0/$$TO_COMPILE > .files_changed
endef

## Essa macro é útil para fornecer uma representação visual do progresso do processo de compilação.
## O que pode ser útil especialmente em compilações longas ou complexas.

define draw_bar
	FILE_TOTAL=`bash -c 'cat .files_changed | cut -d"/" -f2'`; \
	FILE_DONE=`bash -c 'cat .files_changed | cut -d"/" -f1'`; \
	if [ $$FILE_TOTAL -eq 0 ]; then \
		FILE_TOTAL=1; \
		FILE_DONE=1; \
	fi; \
	RES=`echo "scale=2; $$FILE_DONE/$$FILE_TOTAL*48" | bc`; \
	RES=`echo $${RES%%.*}`; \
	printf "$(OBJ_COLOR)[$(NO_COLOR)"; \
	i=0; \
	while [ $$i -lt 48 ]; do \
		if [ $$i -lt $$RES ]; then \
			printf "$(OK_COLOR)█$(NO_COLOR)"; \
		else \
			printf "$(COM_COLOR)▒$(NO_COLOR)"; \
		fi; \
		((i=$$i+1)); \
	done; \
	printf "$(OBJ_COLOR)]$(NO_COLOR)"; \
	printf " ($(COM_COLOR)$$FILE_DONE$(NO_COLOR)/$(COM_COLOR)$$FILE_TOTAL$(NO_COLOR))"; \
	printf " "; \
	((FILE_DONE=$$FILE_DONE+1)); \
	echo $$FILE_DONE/$$FILE_TOTAL > .files_changed;
endef

## Essa macro é responsável por gerenciar a exibição visual da barra de progresso durante o processo de compilação.
## Garantindo que ela seja atualizada conforme necessário e não cause problemas de formatação na saída do Makefile.

define display_progress_bar
	if [ $(NOVISU) -eq 0 ]; then \
		line=`bash -c 'oldstty=$$(stty -g); stty raw -echo min 0; tput u7 > /dev/tty; IFS=";" read -r -d R -a pos; stty $$oldstty; row=$$(($${pos[0]:2} - 1)); echo $$row'`; \
		max_line=`tput lines`; \
		((max_line=$$max_line-2));\
		new_line=0; \
		tput sc; \
		i=0; \
		while [ $$i -lt 60 ]; do \
			printf " "; \
			((i=$$i+1)); \
		done; \
		tput rc; \
		if [ $$line -gt $$max_line ]; then \
			new_line=1; \
			echo ; \
		else \
			((line=$$line+1));\
		fi; \
		tput sc; \
		tput cup $$line; \
		$(draw_bar) \
		if [ $$new_line -eq 1 ]; then \
			((line=$$line-1));\
			tput cup $$line; \
		else \
			tput rc; \
		fi; \
	fi
endef

################################################################################
#                                 Makefile                                     #
################################################################################

-include $(DEPS) $(DEPS_MAIN)

all: header setup $(NAME)
	@rm -rf .files_changed

header:
	@printf "%b" "$(OK_COLOR)"
	@echo 
	@echo " ███    ███  █████  ██   ██ ███████ ███████ ██ ██      ███████ "
	@echo " ████  ████ ██   ██ ██  ██  ██      ██      ██ ██      ██      "
	@echo " ██ ████ ██ ███████ █████   █████   █████   ██ ██      █████   "
	@echo " ██  ██  ██ ██   ██ ██  ██  ██      ██      ██ ██      ██      "
	@echo " ██      ██ ██   ██ ██   ██ ███████ ██      ██ ███████ ███████ "
	@echo 


## Verifica se a variável HASH está definida e, se estiver, imprime o nome do projeto seguido pelo hash, destacando as informações com cores.
## Imprime informações sobre o autor, a data da compilação, o compilador utilizado e as flags de compilação.
## Inclui os arquivos de dependência.
## Define uma regra para compilar o executável especificado pelo nome $(NAME), utilizando arquivos de objeto como dependências.
## Chama macros para exibir uma barra de progresso durante a compilação e para compilar o executável.

ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(CFLAGS)\n\033[m"
	@echo

$(NAME): ${LIBFT} ${OBJS} ${OBJ_MAIN}
			@$(call display_progress_bar)
			@$(call run_and_test,$(CC) $(CFLAGS) $(DFLAGS) -I$(INCLUDE_PATH) -o $@ ${LIBFT} ${OBJS} ${OBJ_MAIN})
			@echo

$(LIBFT):
			@${MAKE} --no-print-directory -C ${LIBFT_DIR}

setup:
			@$(call save_files_changed)

objs/%.o: $(SRCS_PATH)/%$(FILE_EXTENSION)
			@mkdir -p $(dir $@)
			@$(call display_progress_bar)
			@$(call run_and_test,$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I$(INCLUDE_PATH))

clean:
			@rm -rf objs
			@${MAKE} --no-print-directory clean -C ${LIBFT_DIR}
			@printf "%-53b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

fclean:		clean
			@rm -rf $(NAME)
			@printf "%-53b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re header
