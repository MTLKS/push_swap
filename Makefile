NAME	= push_swap
CHECKER	= checker
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
LIBFT	= libft

INCLUDES	= ./includes
SRC_PATH	= ./src
OBJ_PATH	= ./obj

PUSHSWAP_SRCS	= $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/$(NAME)/*,.c*)))
CHECKER_SRCS	= $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/$(CHECKER)/*,.c*)))

PUSHSWAP_OBJS	= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(PUSHSWAP_SRCS)))))
CHECKER_OBJS	= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(CHECKER_SRCS)))))

all:	$(NAME)

bonus:	$(CHECKER)

$(NAME):	$(PUSHSWAP_OBJS)
			$(MAKE) -C $(LIBFT)
			$(CC) $(CFLAGS) $^ -L$(LIBFT) -lft -o $@

$(CHECKER):		$(CHECKER_OBJS)
				$(MAKE) -C $(LIBFT)
				$(CC) $(CFLAGS) $^ -L$(LIBFT) -lft -o $@

$(OBJ_PATH)/%.o:	$(SRC_PATH)/*/%.c* | $(OBJ_PATH)
					$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@

$(OBJ_PATH):
				mkdir -p $(OBJ_PATH)

clean:
			$(MAKE) -C $(LIBFT) $@
			rm -rf $(OBJ_PATH)

fclean:		clean
			$(MAKE) -C $(LIBFT) $@
			rm -f $(NAME) $(CHECKER)

re:			fclean all

.PHONY:		all clean fclean re bonus