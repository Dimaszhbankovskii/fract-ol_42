FRACTOL		=	fractol

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
LIBRARIES	=	-L./libft -lft
INCLUDES	=	-I./includes

LIBFT		=	./libft/libft.a
HEADER		=	./includes/fractol.h

SRCS_DIR	=	srcs/
SRCS_LIST	=	mlx.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS		=	$(patsubst %.c, %.o, $(SRCS_LIST))

all : $(FRACTOL)

$(FRACTOL) : Makefile $(HEADER) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLXFLAGS) $(INCLUDES)
	printf "'$(FRACTOL)' was compiled\n"

%.o : $(addprefix $(SRCS_DIR), %.c)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ $(INCLUDES)

clean :
	@rm -rf $(OBJS)
	@printf "command 'clean' was done\n"

fclean : clean
	@rm -rf $(FRACTOL)
	@printf "command 'fclean' was done\n"

re : fclean all
	@printf "command 're' was done\n"

.PHONY: all clean fclean re bonus
