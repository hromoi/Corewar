.PHONY: all libft clean fclean re

OBJDIR = obj
SRCDIR = src
LIBDIR = libft
HEADER = -I ./include
HEADER_LIBFT = -I ./libft/include -I ./libft/src/ft_printf/include
FLAGS = -g -Wall -Wextra -Werror

ASM = ../asm
SRC_ASM_NAME =  asm_content.c \
				assemble.c \
				disassemble.c \
				parse_chmp_exec_code.c \
				write_args.c \
				parse_name_comt_cs.c \
				buffer.c \
				error.c \
				file.c \
				fill_file.c \
				fill_write_arg.c \
				fill_write_code_arg.c \
				fill_write_code_instraction.c \
				in_bytecode.c \
				interpretation.c \
				main.c \
				string.c \
				title.c \
				tokenizing.c \
				validation.c \
				clean_memory.c \
				rebase_str.c \
				label_validation.c \
				do.c \
				case_regex.c \
				create_comment.c \
				create_pattern.c \
				create_regex.c \
				regex_dir_indir.c \
				regex_name_instraction.c \
				screening.c \
				check_line_name_or_comment.c \
				create_indir.c \
				create_instraction_strlen.c \
				create_pattern_first_length.c \
				create_pattern_length_fifth.c \
				create_pattern_space_or_empty_line.c \
				create_pattern_third_length_first.c \
				create_start_and_finish_str.c \
				init_create_pattern.c \
				init_name_champ.c \
				pattern_third_strcat_first.c \
				pattern_third_strcat_sixth.c \
				strcat_pattern_sixth.c

OBJ_ASM_NAME = $(SRC_ASM_NAME:.c=.o);
SRC_ASM = $(addprefix $(OBJDIR)/, $(SRC_ASM_NAME))
OBJ_ASM = $(addprefix $(OBJDIR)/, $(OBJ_ASM_NAME))

all: libft $(ASM)

$(ASM): $(OBJ_ASM)
	gcc $(FLAGS) $^ -o $@ $(HEADER_LIBFT) $(HEADER) -L libft -lft

$(OBJDIR)/%.o: $(SRCDIR)/%.c include/asm.h include/dasm.h include/op.h
	@mkdir -p $(OBJDIR)
	gcc $(FLAGS) $(HEADER_LIBFT) $(HEADER) -o $@ -c $<

libft:
	make -C $(LIBDIR)

clean:
	make clean -C $(LIBDIR)
	rm -Rf $(OBJDIR)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -Rf $(ASM)

re: fclean all

norm:
	norminette $(SRCDIR)
	norminette ./include