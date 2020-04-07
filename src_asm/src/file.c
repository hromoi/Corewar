/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:55:23 by yperra-f          #+#    #+#             */
/*   Updated: 2020/02/29 18:56:38 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_output_str(t_asm_content **content)
{
	write(1, "Writing output program to ", 26);
	write(1, (*content)->new_filename, ft_strlen((*content)->new_filename));
	write(1, "\n", 1);
}

static int	check_slashn_end(const char *filename, t_asm_content **content)
{
	int		fd;
	int		i;
	char	slash_n;

	fd = 0;
	if (!(fd = open(filename, O_RDONLY)))
		error(*content);
	slash_n = 0;
	i = 0;
	while (slash_n != '\n' && lseek(fd, --i, SEEK_END) != -1L)
	{
		if (read(fd, &slash_n, 1) < 0)
			error(*content);
		if (slash_n != ' ' && slash_n != '\f' &&
			slash_n != '\n' && slash_n != '\t' &&
			slash_n != '\r' && slash_n != '\v')
			error(*content);
	}
	return (1);
}

int			create_f(const char *filename, int only_name_len, char *file_type,
														t_asm_content **content)
{
	char	*new_filename;
	int		type_len;

	type_len = file_type[1] == 's' ? EXP_ASM_LEN : EXP_COR_LEN;
	*content = init_content(file_type[1]);
	new_filename = (char *)ft_memalloc((only_name_len + type_len + 1) *
																sizeof(char));
	(*content)->new_filename = ft_strcat(ft_memcpy(new_filename, filename,
													only_name_len), file_type);
	file_type[1] == 'c' ? check_slashn_end(filename, content) : 1;
	if (((*content)->fd_src = open(filename, O_RDONLY)) == -1)
		error(*content);
	return (1);
}

char		*check_name_file(const char *str)
{
	char	*result_str;
	int		i;

	i = 0;
	if (!(result_str = ft_strdup(str)))
		return (NULL);
	while (result_str[i] != '\0')
	{
		if (result_str[i] >= 'A' && result_str[i] <= 'Z')
			result_str[i] = result_str[i] - 'A' + 'a';
		i++;
	}
	if (!ft_strrchr(result_str, '.') || (ft_strcmp(ft_strrchr(result_str, '.'),
	EXP_ASM) && ft_strcmp(ft_strrchr(result_str, '.'), EXP_COR)))
	{
		free(result_str);
		return (NULL);
	}
	return (result_str);
}

int			file(const char *filename, t_asm_content **content)
{
	int		filename_len;
	int		only_name_len;
	char	*result_str;

	result_str = NULL;
	if (!filename || ft_strrchr(filename, '.') == NULL ||
					!(result_str = check_name_file(filename)))
		return (0);
	filename_len = ft_strlen(filename);
	only_name_len = filename_len - ft_strlen(ft_strrchr(filename, '.'));
	if (!ft_strcmp((result_str + only_name_len), EXP_ASM))
		create_f(filename, only_name_len, EXP_COR, content);
	else if (!ft_strcmp((result_str + only_name_len), EXP_COR))
		create_f(filename, only_name_len, EXP_ASM, content);
	free(result_str);
	return (1);
}
