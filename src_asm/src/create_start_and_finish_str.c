/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_start_and_finish_str.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:42:56 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:43:31 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*create_start_and_finish_str(char *str, t_asm_content *content)
{
	char	*result;
	int		length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(str) +
	ft_strlen(DOLLAR);
	if (!(result = ft_strnew(length)))
		error(content);
	ft_strcat(result, CIRCUMFLEXUS);
	ft_strcat(result, str);
	ft_strcat(result, DOLLAR);
	return (result);
}

char	*create_label_result(t_asm_content *content)
{
	char	*label;
	char	*result_label;

	label = create_label_first_stage(content);
	result_label = create_start_and_finish_str(label, content);
	ft_strdel(&label);
	return (result_label);
}

char	*create_t_reg(t_asm_content *content)
{
	char	*reg;
	char	*t_reg;

	reg = create_reg(content);
	t_reg = create_start_and_finish_str(reg, content);
	ft_strdel(&reg);
	return (t_reg);
}

char	*create_t_dir(t_asm_content *content)
{
	char	*t_dir;
	char	*dir;
	char	*dir_result;
	char	*dir_label;
	char	*dir_label_result;

	dir = create_dir(content);
	dir_result = create_start_and_finish_str(dir, content);
	dir_label = create_dir_label(content);
	dir_label_result = create_start_and_finish_str(dir_label, content);
	if (!(t_dir = ft_strnew(ft_strlen(dir) + ft_strlen(PIPELINE) +
					ft_strlen(dir_label))))
		error(content);
	ft_strcat(t_dir, dir);
	ft_strcat(t_dir, PIPELINE);
	ft_strcat(t_dir, dir_label);
	ft_strdel(&dir);
	ft_strdel(&dir_result);
	ft_strdel(&dir_label);
	ft_strdel(&dir_label_result);
	return (t_dir);
}

char	*create_t_ind(t_asm_content *content)
{
	char	*t_ind;
	char	*indir;
	char	*indir_label;
	char	*indir_start;
	char	*indir_label_start;

	indir_start = create_indir(content);
	indir = create_start_and_finish_str(indir_start, content);
	indir_label_start = create_indir_label(content);
	indir_label = create_start_and_finish_str(indir_label_start, content);
	if (!(t_ind = ft_strnew(ft_strlen(indir) + ft_strlen(PIPELINE) +
					ft_strlen(indir_label))))
		error(content);
	ft_strcat(t_ind, indir);
	ft_strcat(t_ind, PIPELINE);
	ft_strcat(t_ind, indir_label);
	ft_strdel(&indir);
	ft_strdel(&indir_label);
	ft_strdel(&indir_label_start);
	ft_strdel(&indir_start);
	return (t_ind);
}
