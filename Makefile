NAME = fdf

#Directory names
DIR_SRCS	= src
DIR_OBJS	= objs

SRCS_DIRS	= $(addprefix $(DIR_SRCS)/, $(dir))
OBJS_DIRS	= $(addprefix $(DIR_OBJS)/, $(dir))

SRCS = $(addprefix src/, $(addsuffix .c, \
		ft_draw_line \
		ft_parse \
		main))

#Object destination for .c files
OBJS	= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

#Color codes
GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
BOLD = \033[1m
RESET = \033[0m

all: $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@printf "$(MAGENTA)Compiling: $(BLUE)$<\n$(RESET)"
	@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
	@$(CC) $(CFLAGS) -c $< -o $@