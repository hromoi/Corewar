/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info_about_players.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 22:41:47 by astanton          #+#    #+#             */
/*   Updated: 2020/02/25 15:35:06 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char			*save_name(int fd, t_game *game)
{
	char	buff[PROG_NAME_LENGTH + 1];
	char	*name;
	int		ret;

	lseek(fd, sizeof(COREWAR_EXEC_MAGIC), SEEK_SET);
	ret = read(fd, buff, PROG_NAME_LENGTH);
	buff[ret] = '\0';
	name = (char *)malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (!name)
		ft_print_error_message("Memory for name is not allocated.", NULL,
								game);
	return (ft_strcpy(name, buff));
}

char			*save_comment(int fd, t_game *game)
{
	char	buff[COMMENT_LENGTH + 1];
	char	*comment;
	int		ret;

	ret = read(fd, buff, COMMENT_LENGTH);
	buff[ret] = '\0';
	comment = (char *)malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (!comment)
		ft_print_error_message("Memory for comment is not allocated.", NULL,
								game);
	return (ft_strcpy(comment, buff));
}

int				save_size_of_code(int fd)
{
	int				ret;
	unsigned char	buff[sizeof(COREWAR_EXEC_MAGIC) + 1];
	unsigned int	cur_res;
	unsigned int	tmp;

	lseek(fd, sizeof(COREWAR_EXEC_MAGIC), SEEK_CUR);
	tmp = 0;
	ret = read(fd, buff, sizeof(COREWAR_EXEC_MAGIC));
	buff[ret] = '\0';
	cur_res = *((unsigned int *)ft_memcpy(&tmp, buff,
				sizeof(COREWAR_EXEC_MAGIC)));
	cur_res = (cur_res & BYTE_1) << 24 | (cur_res & BYTE_2) << 8
				| (cur_res & BYTE_3) >> 8 | (cur_res & BYTE_4) >> 24;
	return (cur_res);
}

unsigned char	*save_exec_code(int fd, int size_of_code, t_game *game)
{
	char	buff[size_of_code];
	char	*code;
	int		ret;

	lseek(fd, sizeof(COREWAR_EXEC_MAGIC), SEEK_CUR);
	code = (char *)malloc(sizeof(char) * size_of_code);
	if (!code)
		ft_print_error_message("Memory for exec_code is not allocated.", NULL,
								game);
	ret = read(fd, buff, size_of_code);
	return ((unsigned char *)ft_memcpy(code, buff, size_of_code));
}
