/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:21:29 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 21:09:57 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "dasm.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <regex.h>
# include <stdint.h>
# include <inttypes.h>

# define ASSEMBLE 'c'
# define DISASSEMBLE 's'
# define EXP_ASM ".s"
# define EXP_COR ".cor"
# define EXP_ASM_LEN 2
# define EXP_COR_LEN 4
# define BUFF_S 2048
# define OCTET_SIZE 8
# define HEADER_SIZE 2192
# define FOURTH_BYTE 3
# define SQUARE_BRACKET_OPEN "["
# define SQUARE_BRACKET_CLOSE "]"
# define CIRCUMFLEXUS "^"
# define MINUS "-"
# define QUESTION "?"
# define NUMBERS "[0-9]"
# define PLUS "+"
# define DOLLAR "$"
# define SPACE_OR_TAB "[ 	]"
# define ROUND_BRACKET_OPEN "("
# define ROUND_BRACKET_CLOSE ")"
# define POINT "."
# define PIPELINE "|"
# define MULTIPLIER "*"
# define BACK_SLASH "\\"
# define QUOTATION_MARK "\""
# define CURLY_BRACKET_OPEN "{"
# define CURLY_BRACKET_CLOSE "}"
# define REG_SYMBOL "r"
# define SPACE " "
# define TAB "	"
# define COMMA ","
# define ONE "1"
# define TWO "2"
# define THREE "3"
# define FOUR "4"
# define FIVE "5"
# define SIX "6"
# define SEVEN "7"
# define EIGHT "8"
# define NINE "9"
# define INSTRACTION_FIRST "(live|zjmp|fork|lfork)"
# define INSTRACTION_SECOND "(ld|lld)"
# define INSTRACTION_THIRD "(add|sub)"
# define INSTRACTION_FOURTH "(and|or|xor)"
# define INSTRACTION_FIFTH "(ldi|lldi)"
# define FIRST_CASE "(live|ld|and|or|xor|zjmp|ldi|fork|lld|lldi|lfork)"

# define LIVE 0x01
# define LD 0x02
# define ST 0x03
# define ADD 0x04
# define SUB 0x05
# define AND 0x06
# define OR 0x07
# define XOR 0x08
# define ZJMP 0x09
# define LDI 0x0a
# define STI 0x0b
# define FORK 0x0c
# define LLD 0x0d
# define LLDI 0x0e
# define LFORK 0x0f
# define AFF 0x10

# define LIVE_NAME "live"
# define LD_NAME "ld"
# define ST_NAME "st"
# define ADD_NAME "add"
# define SUB_NAME "sub"
# define AND_NAME "and"
# define OR_NAME "or"
# define XOR_NAME "xor"
# define ZJMP_NAME "zjmp"
# define LDI_NAME "ldi"
# define STI_NAME "sti"
# define FORK_NAME "fork"
# define LLD_NAME "lld"
# define LLDI_NAME "lldi"
# define LFORK_NAME "lfork"
# define AFF_NAME "aff"

# define ONE_BYTE 1
# define TWO_BYTE 2
# define FOUR_BYTE 4

# define UNCERTAIN_NAME "UNCERTAIN"
# define LABEL_NAME "LABEL"
# define INSTRACTION_NAME "INSTRACTION"
# define REGISTER_NAME "REGISTER"
# define DIRECT_LABEL_NAME "DIRECT_LABEL"
# define DIRECT_NAME "DIRECT"
# define INDIRECT_LABEL_NAME "INDIRECT_LABEL"
# define INDIRECT_NAME "INDIRECT"

typedef enum			s_enum
{
	PATTERN_T_REG,
	PATTERN_T_DIR,
	PATTERN_T_IND,
	INSTRACTION,
	LABEL,
	REGISTER,
	DIRECT_LABEL,
	DIRECT,
	INDIRECT_LABEL,
	INDIRECT,
	PATTERN_NAME_CHAMPS,
	PATTERN_COMMENT_CHAMPS,
	PATTERN_COMMENT,
	PATTERN_SPACE_OR_EMPTY_LINE,
	PATTERN,
	PATTERN_NAME_OR_COMMENT_CHAMPS,
	PATTERN_HELP_VALIDATION_FIRST_CASE,
	PATTERN_HELP_VALIDATION_SECOND_CASE,
	PATTERN_HELP_VALIDATION_THIRD_CASE,
	PATTERN_HELP_VALIDATION_FOURTH_CASE,
	PATTERN_HELP_VALIDATION_FIFTH_CASE
}						t_enum;

typedef struct			s_norminette
{
	char				*alt_comment_char;
	char				*comment_char;
	char				*reg;
	char				*dir;
	char				*dir_label;
	char				*indir;
	char				*indir_label;
	char				*label;
	char				*separator;
	char				*comment_cmd_string;
	char				*name_cmd_string;
}						t_norminette;

typedef	struct			s_token
{
	int					memory_size;
	char				*content;
	char				*type;
	struct s_token		*next;
	struct s_token		*previous;
}						t_token;

typedef struct			s_strings
{
	t_token				*string;
	struct s_strings	*next;
}						t_strings;

typedef struct			s_asm_content
{
	int					fd_dst;
	int					fd_src;
	char				asm_dsm_flag;
	int					flag_name;
	int					flag_comment;
	int					flag_pattern;
	int					memory_code_size;
	char				*line;
	char				*buf;
	char				*new_filename;
	int					b_pos;
	t_strings			**tokens;
	char				*name;
	char				*comment;
	t_header			*header;
	char				*bytecode;
	char				*regex_array[19];
	unsigned int		exec_code_size;
	unsigned int		asm_size;
	unsigned int		header_size;
}						t_asm_content;

t_asm_content			*init_content(char ad_flag);
void					assemble(t_asm_content **content);
char					*clean_memory_t_strings(t_strings *rows);
void					disassemble(t_asm_content **content);
void					parse_chmp_exec_code(t_asm_content **content);
u_int8_t				get_num_from_1byte(t_asm_content **content, int *i);
int						get_num_from_nbyte(t_asm_content **content, int *i,
u_int8_t t_dir_size);
void					get_args_types(t_asm_content **content, int *i,
u_int8_t cur_op);
void					write_curr_op(t_asm_content **content, int *i,
u_int8_t cur_op);
void					write_reg(t_asm_content **content,
u_int8_t cur_op, int *i, int j);
void					write_dir(t_asm_content **content,
u_int8_t cur_op, int *i, int j);
void					write_ind(t_asm_content **content,
u_int8_t cur_op, int *i, int j);
int						file_is_binary(int fd, t_asm_content **content);
int						parse_name(char *buff, int *b_pos, int fd,
t_asm_content **content);
int						parse_comment(char *buff, int *b_pos, int fd,
t_asm_content **content);
void					skip_null_bytes(t_asm_content **content);
void					parse_chmp_exec_code_size(t_asm_content **content);
void					clear_buff(char **buff);
char					**create_buff(char **line, t_asm_content **content);
void					error(t_asm_content *content);
void					print_output_str(t_asm_content **content);
int						file(const char *filename, t_asm_content **content);
void					what_are_strings(t_strings *rows);
int						skip_simple_comment_emptyline(char **line);
int						check_name_or_comment(char **buff,
t_asm_content **content);
void					tokenizing(char **line, t_strings **row,
t_asm_content **content);
void					add_string(t_token **tokens,
t_strings **row, t_asm_content *content);
void					in_bytecode(t_asm_content **content);
void					interpretation(t_token *tokens, t_asm_content *content);
int						parse(char *str, char *pattern);
char					*help_check_name_or_comment_champs(t_asm_content
*content, int fd);
char					*check_valid(t_asm_content *content, int fd);
char					*search_label(t_strings *rows,
char *content, t_asm_content *content_asm);
char					*check_all_label(t_strings *rows, t_asm_content
**struct_content);
int						check(t_token *pointer);
void					fill_write(t_token *pointer, t_strings *rows,
t_asm_content **content);
void					fill_file(t_strings *rows, t_asm_content
**content);
int						search_instraction_two(t_token *pointer);
int						search_instraction(char *content,
t_strings *rows);
void					write_args(int length, int num,
t_asm_content **content);
int						check_t_dir_size(t_token *pointer);
void					fill_write_arg(t_token *pointer,
t_strings *rows, t_asm_content **content, int flag);
void					fill_write_code_arg(t_token *pointer,
t_asm_content **content);
void					fill_write_code_instraction(char *instraction,
t_asm_content **content);
char					*clean_memory(t_asm_content **content);
char					*rebase_str_first_case(char *content);
char					*rebase_str_second_case(char *content);
char					*rebase_str_third_case(char *content);
char					*label_validation(t_token *pointer,
char *content, t_asm_content *content_asm);
int						check_all_label_size(t_token *pointer,
t_asm_content			**struct_content, int flag);
char					fill_write_code_instraction_help(char *instraction,
char c);
char					*do_w1(t_asm_content *content, char *temp);
char					*do_w2(t_asm_content *content, char *temp);
char					*create_pattern_first(t_asm_content *content);
char					*create_pattern_second(t_asm_content *content);
char					*create_pattern_third(t_asm_content *content);
char					*create_comment_champ(t_asm_content *content);
char					*create_comment(t_asm_content *content);
char					*create_pattern_space_or_empty_line(
	t_asm_content *content);
char					*create_pattern(t_asm_content *content);
char					*create_start_and_finish_str(char *str,
t_asm_content *content);
char					*create_label(t_asm_content *content);
char					*create_t_reg(t_asm_content *content);
char					*create_t_dir(t_asm_content *content);
char					*create_t_ind(t_asm_content *content);
char					*create_pattern_space_or_empty_line(
	t_asm_content *content);
void					create_regex(t_asm_content *content);
char					*create_reg(t_asm_content *content);
char					*create_label_first_stage(t_asm_content *content);
char					*create_dir_label(t_asm_content *content);
char					*create_dir(t_asm_content *content);
char					*create_indir_label(t_asm_content *content);
char					*create_indir(t_asm_content *content);
char					*create_instraction_first_stage(t_asm_content *content);
char					*create_name_champ(t_asm_content *content);
char					*create_pattern_name_or_comment_champs(
	t_asm_content *content);
char					*screen(char symbol, t_asm_content *content);
char					*screening(char symbol, t_asm_content *content);
char					*str_screening(char *str_symbols,
t_asm_content *content);
char					*create_dir_label_result(t_asm_content *content);
char					*create_dir_result(t_asm_content *content);
char					*create_indir_label_result(t_asm_content *content);
char					*create_indir_result(t_asm_content *content);
int						check_line_name_or_comment(char *line,
t_asm_content **content);
int						create_instraction_strlen(void);
void					strcat_instraction(char *instraction);
void					strcat_instraction_first(char *instraction);
void					strcat_instraction_second(char *instraction);
char					*create_instraction_first_stage(t_asm_content *content);
int						create_pattern_first_length(t_norminette *struct_norme);
void					create_pattern_first_strcat(t_norminette *struct_norme,
char *first_case);
char					*create_pattern_first(t_asm_content *content);
char					*create_pattern_second(t_asm_content *content);
void					init_struct_norme_for_pattern_third(t_norminette
*struct_norme, t_asm_content *content);
int						create_pattern_length_fifth(t_norminette *struct_norme);
void					strcat_pattern_first(char *pattern,
t_norminette *struct_norme);
void					strcat_pattern_second(char *pattern,
t_norminette *struct_norme);
void					strcat_pattern_third(char *pattern,
t_norminette *struct_norme);
void					strcat_pattern_fourth(char *pattern,
t_norminette *struct_norme);
char					*create_pattern_space_or_empty_line(t_asm_content
*content);
int						create_pattern_third_length_first(t_norminette
*struct_norme);
int						create_pattern_third_length_second(t_norminette
*struct_norme);
int						create_pattern_third_length_third(t_norminette
*struct_norme);
int						create_pattern_third_length_fourth(t_norminette
*struct_norme);
int						create_pattern_third_length_fifth(t_norminette
*struct_norme);
void					init_create_pattern(t_norminette *struct_norme,
t_asm_content *content);
int						create_pattern_length_first(t_norminette
*struct_norme);
int						create_pattern_length_second(t_norminette
*struct_norme);
int						create_pattern_length_third(t_norminette
*struct_norme);
int						create_pattern_length_fourth(t_norminette
*struct_norme);
void					init_name_champ(t_norminette *struct_norme,
t_asm_content *content);
int						strlen_name_champ(t_norminette *struct_norme);
void					strcat_name_champ(char *name, t_norminette
*struct_norme);
char					*create_name_champ(t_asm_content *content);
int						strlen_pattern_name_or_comment_champs(char
*name_cmd_string, char *comment_cmd_string);
void					pattern_third_strcat_first(char *pattern_third,
t_norminette *struct_norme);
void					pattern_third_strcat_second(char *pattern_third,
t_norminette *struct_norme);
void					pattern_third_strcat_third(char *pattern_third,
t_norminette *struct_norme);
void					pattern_third_strcat_fourth(char *pattern_third,
t_norminette *struct_norme);
void					pattern_third_strcat_fifth(char *pattern_third,
t_norminette *struct_norme);
void					pattern_third_strcat_sixth(char *pattern_third,
t_norminette *struct_norme);
void					pattern_third_strcat_seventh(char *pattern_third,
t_norminette *struct_norme);
void					strcat_pattern_sixth(char *pattern,
t_norminette *struct_norme);
void					strcat_pattern_seventh(char *pattern,
t_norminette *struct_norme);
void					strcat_pattern_eigth(char *pattern,
t_norminette *struct_norme);
void					strcat_pattern_ninth(char *pattern,
t_norminette *struct_norme);
void					strcat_pattern_ten(char *pattern,
t_norminette *struct_norme);
char					*create_label_result(t_asm_content *content);

#endif
