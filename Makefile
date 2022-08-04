PUSHSWAP	= push_swap
CHECKER		= checker

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

INCLUDES	= ./includes

SRC_PATH	= ./src
OBJ_PATH	= ./obj

PUSHSWAP_SRCS	= $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/$(PUSHSWAP)/*,.c*)))
CHECKER_SRCS	= $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/$(CHECKER)/*,.c*)))

PUSHSWAP_OBJS	= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(PUSHSWAP_SRCS)))))
CHECKER_OBJS	= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(CHECKER_SRCS)))))

all: $(PUSHSWAP)

bonus: $(CHECKER)

$(PUSHSWAP):	libft $(OBJ_PATH) $(PUSHSWAP_OBJS)
				$(CC) $(CFLAGS) -g $(PUSHSWAP_OBJS) -Llibft -lft -o $(PUSHSWAP) -fsanitize=address

$(CHECKER):		libft $(OBJ_PATH) $(CHECKER_OBJS)
				$(CC) $(CFLAGS) $(CHECKER_OBJS) -Llibft -lft -o $(CHECKER)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/*/%.c*
					$(CC) $(CFLAGS) -g -c -I$(INCLUDES) $< -o $@

$(OBJ_PATH):
				mkdir -p $(OBJ_PATH)

libft:
			make -C libft

clean:
			make -C libft clean
			rm -rf $(OBJ_PATH)

fclean:
			make -C libft fclean
			rm -f $(PUSHSWAP) $(CHECKER)

re:			fclean all

.PHONY:		all clean fclean re bonus libft $(PUSHSWAP) $(CHECKER)