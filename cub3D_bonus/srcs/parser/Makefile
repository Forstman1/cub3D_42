# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 18:33:31 by rel-fagr          #+#    #+#              #
#    Updated: 2022/09/30 19:04:26 by rel-fagr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# --------------------------- Terminal Color Codes --------------------------- #
NC := \033[0m
RED := \033[31m
YEL := \033[33m
GRA := \033[37m
CYN := \033[36m
GRN := \033[32m
MGN := \033[35m
BLU := \033[34m

# ---------------------------------------------------------------------------- #
CC			:= gcc
CC_FLAGS	:= -Wall -Wextra -Werror -fno-signed-zeros -mtune=intel -Ofast -march=native -fno-trapping-math

SRCS_DIR := srcs/
SRCS_LST := parser.c get_next_line_utils.c  get_next_line.c parse_map.c  remp_color_texture.c  creat_map.c \
		check_map_syntax.c  virtual_walls.c check_doors.c remp_color.c
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

PROJECT 	:= parser
HEADER		:= parser.h
NAME		:= libCubparser.a

# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re title 

all: title ${NAME}
title:
	@printf "\n${YEL}\033[4mEntering ${GRA}${PROJECT}${YEL}'s makefile:${NC} "

${NAME}: ${OBJS_DIR} ${OBJS} ${HEADER}
	@ar -rcs ${NAME} ${OBJS}
	@printf "$(CYN)Archive file $(GRA)$(NAME)$(CYN) created $(NC)\n"

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER}
	@${CC} ${CC_FLAGS} -c $< -o $@

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean:
	@rm -rf ${OBJS_DIR}
	@echo "${GRA}${PROJECT}${RED}\t\tobject files have been deleted${NC}"

fclean:
	@rm -f ${NAME}
	@echo "${GRA}${PROJECT}${RED}\t\tarchive file ${GRA}${NAME}${RED}\t"\
		"has been deleted${NC}"

re: fclean all
