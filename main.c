#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include "op.h"
#include "libft.h"
# define PATTERN_NAME_CHAMPS "^[\\\\*;]$"
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
# define PATTERN "^[ 	]*([a-z0-9_]+:)?[ 	]*((live|zjmp|fork|lfork)[ 	]*(%-?[0-9]+|%:[0-9a-z_]+)|(ld|lld)([ 	]*(%-?[0-9]+|%:[0-9a-z_]+)|[ 	]+(-?[0-9]+|:[0-9a-z_]+))[ 	]*,[ 	]*r[0-9]{1,2}|st[ 	]+r[0-9]{1,2}[ 	]*,[ 	]*(r[0-9]{1,2}|-?[0-9]+|:[0-9a-z_]+)|(add|sub)[ 	]+r[0-9]{1,2}[ 	]*,[ 	]*r[0-9]{1,2}[ 	]*,[ 	]*r[0-9]{1,2}|(and|or|xor)([ 	]+(r[0-9]{1,2}|-?[0-9]+|:[0-9a-z_]+)|[ 	]*(%-?[0-9]+|%:[0-9a-z_]+))[ 	]*,[ 	]*(r[0-9]{1,2}|%-?[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*r[0-9]{1,2}|(ldi|lldi)([ 	]+(r[0-9]{1,2}|-?[0-9]+|:[0-9a-z_]+)|[ 	]*(%-?[0-9]+|%:[0-9a-z_]+))[ 	]*,[ 	]*(r[0-9]{1,2}|%-?[0-9]+|%:[0-9a-z_]+)[ 	]*,[ 	]*r[0-9]{1,2}|sti[ 	]+r[0-9]{1,2}[ 	]*,[ 	]*(r[0-9]{1,2}|%-?[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*(r[0-9]{1,2}|%-?[0-9]+|%:[0-9a-z_]+)|aff[ 	]+r[0-9]{1,2})?[ 	]*([\\*;].*)?$"
# define PATTERN_NAME_OR_COMMENT_CHAMPS "^[ 	]*(\\[[\\][\\|][\"]\\][\\*]ab|\\.comment)[ 	]*\".*$"
# define FIRST_CASE "(live|ld|and|or|xor|zjmp|ldi|fork|lld|lldi|lfork)"
# define PATTERN_HELP_VALIDATION_FIFTH_CASE "^[0-9a-z_]+:[#;].*$"

int		parse(char *str, char *pattern)
{
	int			err;
	regex_t		reg1;
	regmatch_t	pm;
	// printf("%lu\n", strlen(str));
	// printf("reg - %s\n", PATTERN_NAME_OR_COMMENT_CHAMPS);

	err = regcomp(&reg1, pattern, REG_EXTENDED);
	if (err != 0)
	{
		regfree(&reg1);
		write(1, "error with regex in file\n", 25);
		return (0);
	}
	if (!regexec(&reg1, str, 0, &pm, 0))
	{
		printf("good match\n");
		regfree(&reg1);
		return (1);
	}
	printf("bad match\n");
	regfree(&reg1);
	return (0);
}

char	*screen(char symbol)
{
	char *result;

	if (!(result = ft_strnew(1)))
		printf("error\n");
	result[0] = symbol;
	return (result);
}

char    *screening(char symbol)
{
	char	*result_str;
	char	*str;
	int     length;

	if(!(str = ft_strnew(1)))
		printf("error\n");
	str[0] = symbol;
	if (symbol == '*' || symbol == '+' || symbol == '?' 
	|| symbol == '.' || symbol == '[' || symbol == ']' 
	|| symbol == '|' || symbol == '^' || symbol == '$' 
	|| symbol == '{' || symbol == '}' || symbol == '(' 
	|| symbol == ')')
	{
		length = ft_strlen(SQUARE_BRACKET_OPEN) + 
		ft_strlen(BACK_SLASH) + ft_strlen(BACK_SLASH) + 
		ft_strlen(str) + ft_strlen(SQUARE_BRACKET_CLOSE);
		if (!(result_str = ft_strnew(length)))
			printf("error\n");
		ft_strcat(result_str, SQUARE_BRACKET_OPEN);
		if (symbol != ']' && symbol != '[')
			ft_strcat(result_str, BACK_SLASH);
		if (symbol != ']' && symbol != '[')
			ft_strcat(result_str, BACK_SLASH);
		ft_strcat(result_str, str);
		ft_strcat(result_str, SQUARE_BRACKET_CLOSE);
		ft_strdel(&str);
	}
	else if (symbol == '\\' || symbol == '\'' || symbol == '\"')
	{
		length = ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(BACK_SLASH) + 
		ft_strlen(str) + ft_strlen(SQUARE_BRACKET_CLOSE);
		if (!(result_str = ft_strnew(length)))
			printf("error\n");
		ft_strcat(result_str, SQUARE_BRACKET_OPEN);
		ft_strcat(result_str, BACK_SLASH);
		ft_strcat(result_str, str);
		ft_strcat(result_str, SQUARE_BRACKET_CLOSE);
		ft_strdel(&str);
		// printf("%s\n", result_str);
		// printf("%lu\n", strlen(result_str));
	}
	else
		result_str = str;
	return (result_str);
}

char    *str_screening(char *str_symbols)
{
	char	*result_str;

	if (!*str_symbols)
		return (ft_strnew(0));
	if (!(result_str = ft_strnew(1)))
		printf("error\n");
	while (*str_symbols)
	{
		result_str = ft_strjoinwcm(result_str, screening(*str_symbols));
		str_symbols++;
	}
	return (result_str);
}

char	*create_reg()
{
	char	*t_reg;
	int		length;

	length = ft_strlen(REG_SYMBOL) + ft_strlen(NUMBERS) + 
	ft_strlen(CURLY_BRACKET_OPEN) + ft_strlen(ONE) + 
	ft_strlen(COMMA) + ft_strlen(TWO) + 
	ft_strlen(CURLY_BRACKET_CLOSE);
	if (!(t_reg = ft_strnew(length)))
		printf("error\n");
	ft_strcat(t_reg, REG_SYMBOL);
	ft_strcat(t_reg, NUMBERS);
	ft_strcat(t_reg, CURLY_BRACKET_OPEN);
	ft_strcat(t_reg, ONE);
	ft_strcat(t_reg, COMMA);
	ft_strcat(t_reg, TWO);
	ft_strcat(t_reg, CURLY_BRACKET_CLOSE);
	return (t_reg);
}

char	*create_dir_label()
{
	char	*dir_label;
	char    *direct_char;
	char    *label_char;
	int		length;

	direct_char = screening(DIRECT_CHAR);
	label_char = screening(LABEL_CHAR);
	length = ft_strlen(direct_char) + ft_strlen(label_char) + 
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(LABEL_CHARS) + 
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(PLUS);
	if (!(dir_label = ft_strnew(length)))
		printf("error\n");
	ft_strcat(dir_label, direct_char);
	ft_strcat(dir_label, label_char);
	ft_strcat(dir_label, SQUARE_BRACKET_OPEN);
	ft_strcat(dir_label, LABEL_CHARS);
	ft_strcat(dir_label, SQUARE_BRACKET_CLOSE);
	ft_strcat(dir_label, PLUS);
	ft_strdel(&direct_char);
	ft_strdel(&label_char);
	return (dir_label);
}

char	*create_dir()
{
	char	*dir;
	char    *direct_char;
	int		length;

	direct_char = screening(DIRECT_CHAR);
	length = ft_strlen(direct_char) + ft_strlen(MINUS) + 
	ft_strlen(QUESTION) + 
	ft_strlen(NUMBERS) + ft_strlen(PLUS);
	if (!(dir = ft_strnew(length)))
		printf("error\n");
	ft_strcat(dir, direct_char);
	ft_strcat(dir, MINUS);
	ft_strcat(dir, QUESTION);
	ft_strcat(dir, NUMBERS);
	ft_strcat(dir, PLUS);
	ft_strdel(&direct_char);
	return (dir);
}

char	*create_label_first_stage()
{
	char	*label;
	char	*label_char;
	int		length;

	label_char = screening(LABEL_CHAR);
	length = ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(LABEL_CHARS) + 
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(PLUS) + 
	ft_strlen(label_char);
	if (!(label = ft_strnew(length)))
		printf("error\n");
	ft_strcat(label, SQUARE_BRACKET_OPEN);
	ft_strcat(label, LABEL_CHARS);
	ft_strcat(label, SQUARE_BRACKET_CLOSE);
	ft_strcat(label, PLUS);
	ft_strcat(label, label_char);
	ft_strdel(&label_char);
	return (label);
}

char	*create_indir_label()
{
	char	*indir_label;
	char    *label_char;
	int		length;

	label_char = screening(LABEL_CHAR);
	length = ft_strlen(label_char) + ft_strlen(SQUARE_BRACKET_OPEN) + 
	ft_strlen(LABEL_CHARS) + ft_strlen(SQUARE_BRACKET_CLOSE) + 
	ft_strlen(PLUS);
	if (!(indir_label = ft_strnew(length)))
		printf("error\n");
	ft_memset(indir_label, '\0', length + 1);
	ft_strcat(indir_label, label_char);
	ft_strcat(indir_label, SQUARE_BRACKET_OPEN);
	ft_strcat(indir_label, LABEL_CHARS);
	ft_strcat(indir_label, SQUARE_BRACKET_CLOSE);
	ft_strcat(indir_label, PLUS);
	ft_strdel(&label_char);
	return (indir_label);
}

char	*create_indir()
{
	char	*indir;
	int		length;

	length = ft_strlen(MINUS) + ft_strlen(QUESTION) + 
	ft_strlen(NUMBERS) + ft_strlen(PLUS);
	if (!(indir = ft_strnew(length)))
		printf("error\n");
	ft_strcat(indir, MINUS);
	ft_strcat(indir, QUESTION);
	ft_strcat(indir, NUMBERS);
	ft_strcat(indir, PLUS);
	return (indir);
}

char	*create_pattern()
{
	char	*pattern;
	char    *alt_comment_char;
	char	*comment_char;
	char    *reg;
	char    *dir;
	char    *dir_label;
	char    *indir;
	char    *indir_label;
	char    *label;
	char	*separator;
	int		length;

	reg = create_reg();
	dir = create_dir();
	dir_label = create_dir_label();
	indir = create_indir();
	indir_label = create_indir_label();
	label = create_label_first_stage();
	separator = screen(SEPARATOR_CHAR);
	alt_comment_char = screen(ALT_COMMENT_CHAR);
	comment_char = screen(COMMENT_CHAR);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(QUESTION) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(INSTRACTION_FIRST) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(INSTRACTION_SECOND) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(indir) + 
	ft_strlen(PIPELINE) + ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(ST_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(reg) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(indir) + 
	ft_strlen(PIPELINE) + ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(INSTRACTION_THIRD) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(reg) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(reg) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(INSTRACTION_FOURTH) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + 
	ft_strlen(indir) + ft_strlen(PIPELINE) + 
	ft_strlen(indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(PIPELINE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(dir) + ft_strlen(PIPELINE) + 
	ft_strlen(dir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(PIPELINE) + ft_strlen(indir) + 
	ft_strlen(PIPELINE) + ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(INSTRACTION_FIFTH) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + 
	ft_strlen(indir) + ft_strlen(PIPELINE) + 
	ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(STI_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(reg) + ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + 
	ft_strlen(dir) + ft_strlen(PIPELINE) + 
	ft_strlen(dir_label) + ft_strlen(PIPELINE) + 
	ft_strlen(indir) + ft_strlen(PIPELINE) + 
	ft_strlen(indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(AFF_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(reg) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(QUESTION) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(comment_char) + 
	ft_strlen(alt_comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) + 
	ft_strlen(POINT) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(QUESTION) + 
	ft_strlen(DOLLAR);
	if (!(pattern = ft_strnew(length)))
		printf("error\n");
	ft_strcat(pattern, CIRCUMFLEXUS);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, INSTRACTION_FIRST);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_SECOND);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, ST_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_THIRD);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_FOURTH);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_FIFTH);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, STI_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, AFF_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SQUARE_BRACKET_OPEN);
	ft_strcat(pattern, comment_char);
	ft_strcat(pattern, alt_comment_char);
	ft_strcat(pattern, SQUARE_BRACKET_CLOSE);
	ft_strcat(pattern, POINT);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, DOLLAR);
	return (pattern);
}

char	*create_pattern_name_or_comment_champs()
{
	char	*pattern_name_or_comment;
	char	*name_cmd_string;
	char	*comment_cmd_string;
	int		length;

	name_cmd_string = str_screening(NAME_CMD_STRING);
	comment_cmd_string = str_screening(COMMENT_CMD_STRING);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(name_cmd_string) + 
	ft_strlen(PIPELINE) + 
	ft_strlen(comment_cmd_string) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(QUOTATION_MARK) + ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(pattern_name_or_comment = ft_strnew(length)))
		printf("error\n");
	ft_strcat(pattern_name_or_comment, CIRCUMFLEXUS);
	ft_strcat(pattern_name_or_comment, SPACE_OR_TAB);
	ft_strcat(pattern_name_or_comment, MULTIPLIER);
	ft_strcat(pattern_name_or_comment, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_name_or_comment, name_cmd_string);
	ft_strcat(pattern_name_or_comment, PIPELINE);
	ft_strcat(pattern_name_or_comment, comment_cmd_string);
	ft_strcat(pattern_name_or_comment, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_name_or_comment, SPACE_OR_TAB);
	ft_strcat(pattern_name_or_comment, MULTIPLIER);
	ft_strcat(pattern_name_or_comment, QUOTATION_MARK);
	ft_strcat(pattern_name_or_comment, POINT);
	ft_strcat(pattern_name_or_comment, MULTIPLIER);
	ft_strcat(pattern_name_or_comment, DOLLAR);
	ft_strdel(&name_cmd_string);
	ft_strdel(&comment_cmd_string);
	return (pattern_name_or_comment);
}

char	*create_name_champ()
{
	char	*name;
	char    *name_cmd_string;
	char    *alt_comment_char;
	char	*comment_char;
	int		length;

	name_cmd_string = str_screening(NAME_CMD_STRING);
	alt_comment_char = screen(ALT_COMMENT_CHAR);
	comment_char = screen(COMMENT_CHAR);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(name_cmd_string) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(QUOTATION_MARK) + ft_strlen(SQUARE_BRACKET_OPEN) + 
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(QUOTATION_MARK) + 
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(MULTIPLIER) + 
	ft_strlen(QUOTATION_MARK) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(alt_comment_char) + 
	ft_strlen(comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) +  
	ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(QUESTION) + ft_strlen(DOLLAR);
	if (!(name = ft_strnew(length)))
		printf("error\n");
	ft_strcat(name, CIRCUMFLEXUS);
	ft_strcat(name, SPACE_OR_TAB);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, name_cmd_string);
	ft_strcat(name, SPACE_OR_TAB);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, QUOTATION_MARK);
	ft_strcat(name, SQUARE_BRACKET_OPEN);
	ft_strcat(name, CIRCUMFLEXUS);
	ft_strcat(name, QUOTATION_MARK);
	ft_strcat(name, SQUARE_BRACKET_CLOSE);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, QUOTATION_MARK);
	ft_strcat(name, SPACE_OR_TAB);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, ROUND_BRACKET_OPEN);
	ft_strcat(name, SQUARE_BRACKET_OPEN);
	ft_strcat(name, alt_comment_char);
	ft_strcat(name, comment_char);
	ft_strcat(name, SQUARE_BRACKET_CLOSE);
	ft_strcat(name, POINT);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, ROUND_BRACKET_CLOSE);
	ft_strcat(name, QUESTION);
	ft_strcat(name, DOLLAR);
	ft_strdel(&alt_comment_char);
	ft_strdel(&comment_char);
	return (name);
}

char	*create_comment_champ()
{
	char	*comment;
	char    *comment_cmd_string;
	char    *alt_comment_char;
	char	*comment_char;
	int		length;

	comment_cmd_string = str_screening(COMMENT_CMD_STRING);
	alt_comment_char = screen(ALT_COMMENT_CHAR);
	comment_char = screen(COMMENT_CHAR);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(comment_cmd_string) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(QUOTATION_MARK) + ft_strlen(SQUARE_BRACKET_OPEN) + 
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(QUOTATION_MARK) + 
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(MULTIPLIER) + 
	ft_strlen(QUOTATION_MARK) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(alt_comment_char) + 
	ft_strlen(comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) + 
	ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(QUESTION) + ft_strlen(DOLLAR);
	if (!(comment = ft_strnew(length)))
		printf("error\n");
	ft_strcat(comment, CIRCUMFLEXUS);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, comment_cmd_string);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, QUOTATION_MARK);
	ft_strcat(comment, SQUARE_BRACKET_OPEN);
	ft_strcat(comment, CIRCUMFLEXUS);
	ft_strcat(comment, QUOTATION_MARK);
	ft_strcat(comment, SQUARE_BRACKET_CLOSE);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, QUOTATION_MARK);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, ROUND_BRACKET_OPEN);
	ft_strcat(comment, SQUARE_BRACKET_OPEN);
	ft_strcat(comment, alt_comment_char);
	ft_strcat(comment, comment_char);
	ft_strcat(comment, SQUARE_BRACKET_CLOSE);
	ft_strcat(comment, POINT);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, ROUND_BRACKET_CLOSE);
	ft_strcat(comment, QUESTION);
	ft_strcat(comment, DOLLAR);
	ft_strdel(&alt_comment_char);
	ft_strdel(&comment_char);
	return (comment);
}

char	*create_comment()
{
	char	*comment;
	char    *alt_comment_char;
	char	*comment_char;
	int		length;

	alt_comment_char = screen(ALT_COMMENT_CHAR);
	comment_char = screen(COMMENT_CHAR);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(SQUARE_BRACKET_OPEN) + 
    ft_strlen(alt_comment_char) + ft_strlen(comment_char) + 
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(comment = ft_strnew(length)))
		printf("error\n");
	ft_strcat(comment, CIRCUMFLEXUS);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, SQUARE_BRACKET_OPEN);
	ft_strcat(comment, alt_comment_char);
	ft_strcat(comment, comment_char);
	ft_strcat(comment, SQUARE_BRACKET_CLOSE);
	ft_strcat(comment, POINT);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, DOLLAR);
	ft_strdel(&alt_comment_char);
	ft_strdel(&comment_char);
	return (comment);
}

char	*create_pattern_space_or_empty_line()
{
	char	*space_or_empty_line;
	int		length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(space_or_empty_line = ft_strnew(length)))
		printf("error\n");
	ft_strcat(space_or_empty_line, CIRCUMFLEXUS);
	ft_strcat(space_or_empty_line, SPACE_OR_TAB);
	ft_strcat(space_or_empty_line, MULTIPLIER);
	ft_strcat(space_or_empty_line, DOLLAR);
	return (space_or_empty_line);
}

// char	*create_instraction_first_stage()
// {
// 	char	*instraction;
// 	int		length;

// 	length = ft_strlen(LIVE_NAME) + 
// 	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + 
// 	ft_strlen(LD_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + 
// 	ft_strlen(CIRCUMFLEXUS) + ft_strlen(ST_NAME) + ft_strlen(DOLLAR) + 
// 	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(ADD_NAME) + 
// 	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + 
// 	ft_strlen(SUB_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + 
// 	ft_strlen(CIRCUMFLEXUS) + ft_strlen(AND_NAME) + ft_strlen(DOLLAR) + 
// 	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(OR_NAME) + 
// 	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + 
// 	ft_strlen(XOR_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + 
// 	ft_strlen(CIRCUMFLEXUS) + ft_strlen(ZJMP_NAME) + ft_strlen(DOLLAR) + 
// 	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(LDI_NAME) + 
// 	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + 
// 	ft_strlen(STI_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + 
// 	ft_strlen(CIRCUMFLEXUS) + ft_strlen(FORK_NAME) + ft_strlen(DOLLAR) + 
// 	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(LLD_NAME) + 
// 	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + 
// 	ft_strlen(LLDI_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + 
// 	ft_strlen(CIRCUMFLEXUS) + ft_strlen(LFORK_NAME) + ft_strlen(DOLLAR) + 
// 	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(AFF_NAME);
// 	if (!(instraction = ft_strnew(length)))
// 		printf("error\n");
// 	ft_strcat(instraction, LIVE_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, LD_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, ST_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, ADD_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, SUB_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, AND_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, OR_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, XOR_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, ZJMP_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, LDI_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, STI_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, FORK_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, LLD_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, LLDI_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, LFORK_NAME);
// 	ft_strcat(instraction, DOLLAR);
// 	ft_strcat(instraction, PIPELINE);
// 	ft_strcat(instraction, CIRCUMFLEXUS);
// 	ft_strcat(instraction, AFF_NAME);
// 	return (instraction);
// }

char	*create_pattern_second()
{
	char	*second_case;
	char	*label;
	int		length;
	
	label = create_label_first_stage();
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(label) + 
	ft_strlen(POINT) + ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(second_case = ft_strnew(length)))
		printf("error\n");
	ft_strcat(second_case, CIRCUMFLEXUS);
	ft_strcat(second_case, SPACE_OR_TAB);
	ft_strcat(second_case, MULTIPLIER);
	ft_strcat(second_case, label);
	ft_strcat(second_case, POINT);
	ft_strcat(second_case, MULTIPLIER);
	ft_strcat(second_case, DOLLAR);
	ft_strdel(&label);
	return (second_case);
}

char	*create_pattern_first()
{
	char	*first_case;
	char	*label;
	char	*dir;
	char	*dir_label;
	int		length;

	label = create_label_first_stage();
	dir = create_dir();
	dir_label = create_dir_label();
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(QUESTION) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(FIRST_CASE) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(first_case = ft_strnew(length)))
		printf("error\n");
	ft_strcat(first_case, CIRCUMFLEXUS);
	ft_strcat(first_case, SPACE_OR_TAB);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, ROUND_BRACKET_OPEN);
	ft_strcat(first_case, label);
	ft_strcat(first_case, ROUND_BRACKET_CLOSE);
	ft_strcat(first_case, QUESTION);
	ft_strcat(first_case, SPACE_OR_TAB);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, FIRST_CASE);
	ft_strcat(first_case, ROUND_BRACKET_OPEN);
	ft_strcat(first_case, dir);
	ft_strcat(first_case, PIPELINE);
	ft_strcat(first_case, dir_label);
	ft_strcat(first_case, ROUND_BRACKET_CLOSE);
	ft_strcat(first_case, POINT);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, DOLLAR);
	ft_strdel(&label);
	ft_strdel(&dir);
	ft_strdel(&dir_label);
	return (first_case);
}

char	*create_pattern_third()
{
	char	*pattern_third;
	char    *alt_comment_char;
	char	*comment_char;
	char    *reg;
	char    *dir;
	char    *dir_label;
	char    *indir;
	char    *indir_label;
	char    *label;
	char	*separator;
	int		length;

	reg = create_reg();
	dir = create_dir();
	dir_label = create_dir_label();
	indir = create_indir();
	indir_label = create_indir_label();
	label = create_label_first_stage();
	separator = screen(SEPARATOR_CHAR);
	alt_comment_char = screen(ALT_COMMENT_CHAR);
	comment_char = screen(COMMENT_CHAR);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(QUESTION) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(INSTRACTION_FIRST) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(INSTRACTION_SECOND) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(indir) + 
	ft_strlen(PIPELINE) + ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(ST_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(reg) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(indir) + 
	ft_strlen(PIPELINE) + ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(INSTRACTION_THIRD) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(reg) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(reg) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(INSTRACTION_FOURTH) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + 
	ft_strlen(indir) + ft_strlen(PIPELINE) + 
	ft_strlen(indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(PIPELINE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(dir) + ft_strlen(PIPELINE) + 
	ft_strlen(dir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(PIPELINE) + ft_strlen(indir) + 
	ft_strlen(PIPELINE) + ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(INSTRACTION_FIFTH) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + 
	ft_strlen(indir) + ft_strlen(PIPELINE) + 
	ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(STI_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(reg) + ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + 
	ft_strlen(dir) + ft_strlen(PIPELINE) + 
	ft_strlen(dir_label) + ft_strlen(PIPELINE) + 
	ft_strlen(indir) + ft_strlen(PIPELINE) + 
	ft_strlen(indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(AFF_NAME) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(reg) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(QUESTION) +  
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(comment_char) + 
	ft_strlen(alt_comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) + 
	ft_strlen(POINT) + ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(pattern_third = ft_strnew(length)))
		printf("error\n");
	ft_strcat(pattern_third, CIRCUMFLEXUS);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, QUESTION);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, INSTRACTION_FIRST);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_SECOND);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, ST_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_THIRD);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_FOURTH);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_FIFTH);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, STI_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, AFF_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, QUESTION);
	ft_strcat(pattern_third, SQUARE_BRACKET_OPEN);
	ft_strcat(pattern_third, comment_char);
	ft_strcat(pattern_third, alt_comment_char);
	ft_strcat(pattern_third, SQUARE_BRACKET_CLOSE);
	ft_strcat(pattern_third, POINT);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, DOLLAR);
	return (pattern_third);
}

int main(int ac, char **av){

	// parse("\'\"\\[!");
	// printf("%s\n", create_pattern_name_or_comment_champs());
	printf("%s\n", create_pattern_third());
	parse(*(av + 1), create_pattern_third());
	return (0);
}