# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 22:24:23 by rde-mour          #+#    #+#              #
#    Updated: 2024/02/01 20:42:23 by rde-mour         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

RED					= $(shell tput setaf 1)
GREEN				= $(shell tput setaf 2)
YELLOW				= $(shell tput setaf 3)
BLUE				= $(shell tput setaf 4)
MAGENT				= $(shell tput setaf 5)
RESET				= $(shell tput sgr0)

NAME				= push_swap

FILES				= push_swap.c \
					  push_swap_utils.c

SRCSDIR				= ./srcs
OBJSDIR				= ./objs
LIBFTXDIR			= ./libs/libftx

LIBS				= $(LIBFTXDIR)/libftx.a

SRCS				= $(FILES:%.c=$(SRCSDIR)/%.c)
OBJS				= $(FILES:%.c=$(OBJSDIR)/%.o)
SRCS_BONUS			= $(FILES:%.c=$(SRCsDIR)/bonus/%_bonus.c)
OBJS_BONUS			= $(FILES:%.c=$(OBJSDIR)/bonus/%_bonus.o)

DELETE				= $(OBJS_BONUS)

INCLUDES			= -I ./includes \
					  -I $(LIBFTXDIR)/includes

COMPILER			= cc
CFLAGS				= -Wall -Wextra -Werror -g3
MESSAGE				= mandatory

ifdef				WITH_BONUS
					DELETE := $(OBJS)
					SRCS := $(SRCS_BONUS)
					OBJS := $(OBJS_BONUS)
					MESSAGE	= bonus
endif

all: 				$(NAME)

$(NAME): 			$(LIBS) $(OBJS)
					@rm -rf $(DELETE)
					@$(COMPILER) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)
					@echo "$(BLUE)Compiled $(NAME) successfully$(RESET)"

$(LIBS):
					@make -sC $(LIBFTXDIR)

$(OBJSDIR)/%.o: 	$(SRCSDIR)/%.c
					@mkdir -p $(@D)
					@$(COMPILER) $(CFLAGS) -c $< $(INCLUDES) -o $@
					@echo "$(GREEN)Compiled$(RESET) $(notdir $<)"

bonus:
					@make WITH_BONUS=TRUE --no-print-directory

clean:
					@echo "$(RED)Removing$(RESET) $(NAME) objects"
					@rm -rf $(OBJSDIR)

fclean:				clean
					@echo "$(RED)Removing$(RESET) $(NAME)"
					@rm -rf $(NAME)

re:					fclean all

.PHONY: all bonus clean fclean re
