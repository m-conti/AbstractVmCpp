# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconti <mconti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/02 14:00:49 by mconti            #+#    #+#              #
#    Updated: 2018/06/29 13:09:21 by mconti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= clang++
CVER    = -std=c++11
CFLAGS	= -Wall -Werror -Wextra
NAME	= avm
NAMEP	= ./$(NAME)
DEBUG	= ./debug_$(NAME)

OBJDIR	= obj

FAN		= -fsanitize=address,undefined -g

GREEN	= \x1b[32m

WHITE	= \x1b[0m

SRC		=	main.cpp    Factory.cpp     helpers.cpp         parser.cpp      Vm.cpp

OBJ		= $(SRC:.cpp=.o)

INC		=	AbstractVm.hpp 	Factory.hpp EOperandType.hpp	IOperand.hpp    Vm.hpp  \
            Errors.hpp      helpers.hpp parser.hpp          TOperand.hpp

INC_PATH = ./

OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(addprefix $(INC_PATH)/, $(INC))

all:  $(OBJDIR) $(NAMEP)
	@echo > /dev/null

$(NAMEP): obj $(OBJP)
	@$(CC) $(CVER) $(CFLAGS) -o $@ $(OBJP) -I$(INC_PATH)
	@echo "${WHITE}$(NAMEP)			${GREEN}DONE${WHITE}"

test: all
	@$(NAMEP)

debug: obj $(OBJP)
	@$(CC) $(CVER) $(CFLAGS) -o $(DEBUG) $(OBJP) -I$(INC_PATH) $(FAN)
	@echo "${WHITE}$(DEBUG)			${GREEN}DONE${WHITE}"

obj :
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp $(INCP)
	@$(CC) $(CVER) $(CFLAGS) -o $@ -c $< -I$(INC_PATH)

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf $(OBJDIR)
	@rm -f $(NAMEP) $(DEBUG)

re: fclean all
