FRACTOL		=	fractol

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
C_MLXFLAGS	=	-I/usr/include -Imlx_linux
MLXFLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LIBRARIES	=	-L./libft -lft
INCLUDES	=	-I./includes

LIBFT		=	./libft/libft.a
HEADER		=	./includes/fractol.h
HEADER_KEYS	=	./includes/keycode_linux.h

SRCS_DIR	=	srcs
SRCS_LIST	=	fractol.c \
				validation_input_data.c \
				parsing_input_data.c \
				draw_fractol.c \
				get_color.c \
				fractal_mandelbrot.c \
				fractal_julia.c \
				fractal_mandelbar.c \
				fractal_celtic_perpendicular.c \
				fractal_celtic_mandelbar.c \
				mouse_control.c \
				keyboard_control.c \
				utils_1.c \
				utils_2.c
SRCS		=	$(addprefix $(SRCS_DIR)/,$(SRCS_LIST))

OBJS_DIR	=	objs
OBJS		=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST:.c=.o))

NORMAL		=	\033[0m
BOLD		=	\033[1m
UNDERLINE	=	\033[4m
BLACK		=	\033[1;30m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
VIOLET		=	\033[1;35m
CYAN		=	\033[1;36m
WHITE		=	\033[1;37m

all : $(OBJS_DIR) $(FRACTOL)

$(FRACTOL) : Makefile $(HEADER) $(HEADER_KEYS) $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(MLXFLAGS) -o $@ $(LIBRARIES) $(INCLUDES)
	@echo "$(GREEN)Project succesfully compiled$(NORMAL)"

$(LIBFT) : ./libft/Makefile ./libft/libft.h ./libft/*.c
	@make -C ./libft
	@make bonus -C ./libft
	@echo "$(CYAN)'libft' was compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(HEADER) $(HEADER_KEYS)
	@$(CC) $(CFLAGS) $(C_MLXFLAGS) -O3 -c $< -o $@ $(INCLUDES)
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR) :
	@mkdir -p objs
	@echo "$(CYAN)Creating directory for objects file$(WHITE) --> $@ --> $(GREEN)[Done]$(NORMAL)"

clean :
	@make clean -C ./libft
	@rm -rf $(OBJS_DIR)
	@echo "$(VIOLET)Removing objects files$(WHITE) --> *.o --> $(GREEN)[Done]$(NORMAL)"

fclean : clean
	@make fclean -C ./libft
	@rm -rf $(FRACTOL)
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME) --> $(GREEN)[Done]$(NORMAL)"

re : fclean all

.PHONY: all clean fclean re bonus