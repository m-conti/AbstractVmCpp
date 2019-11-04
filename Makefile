# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/02 14:00:49 by tbehra            #+#    #+#              #
#    Updated: 2018/06/29 13:09:21 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= clang++
CFLAGS	= -Wall -Werror -Wextra
NAME	= avm
NAMEP	= ./$(NAME)
DEBUG	= ./debug_$(NAME)

OBJDIR	= obj

FAN		= -fsanitize=address,undefined -g

GREEN	= \x1b[32m

WHITE	= \x1b[0m

SRC		=	Vm.cpp  Factory.cpp main.cpp

OBJ		= $(SRC:.cpp=.o)

INC		=	Vm.hpp	Factory.hpp EOperandType.hpp	IOperand.hpp

INC_PATH = ./

OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(addprefix $(INC_PATH)/, $(INC))

all:  $(OBJDIR) $(NAMEP)
	@echo > /dev/null

$(NAMEP): obj $(OBJP)
	@$(CC) $(CFLAGS) -o $@ $(OBJP) -I$(INC_PATH)
	@echo "${WHITE}$(NAMEP)			${GREEN}DONE${WHITE}"

test: all
	@$(NAMEP)

debug: obj $(OBJP)
	@$(CC) $(CFLAGS) -o $(DEBUG) $(OBJP) -I$(INC_PATH) $(FAN)
	@echo "${WHITE}$(DEBUG)			${GREEN}DONE${WHITE}"

obj :
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp $(INCP)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC_PATH)

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf $(OBJDIR)
	@rm -f $(NAMEP) $(DEBUG)

re: fclean all
