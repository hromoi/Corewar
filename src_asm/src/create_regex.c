/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_regex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:28:33 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 21:12:20 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*create_instraction(t_asm_content *content)
{
	char	*instraction_first_stage;
	char	*result;

	instraction_first_stage = create_instraction_first_stage(content);
	result = create_start_and_finish_str(instraction_first_stage, content);
	ft_strdel(&instraction_first_stage);
	return (result);
}

void	create_regex(t_asm_content *content)
{
	content->regex_array[PATTERN_T_REG] = create_t_reg(content);
	content->regex_array[PATTERN_T_DIR] = create_t_dir(content);
	content->regex_array[PATTERN_T_IND] = create_t_ind(content);
	content->regex_array[INSTRACTION] = create_instraction(content);
	content->regex_array[LABEL] = create_label_result(content);
	content->regex_array[REGISTER] = create_t_reg(content);
	content->regex_array[DIRECT_LABEL] = create_dir_label_result(content);
	content->regex_array[DIRECT] = create_dir_result(content);
	content->regex_array[INDIRECT_LABEL] = create_indir_label_result(content);
	content->regex_array[INDIRECT] = create_indir_result(content);
	content->regex_array[PATTERN_NAME_CHAMPS] = create_name_champ(content);
	content->regex_array[PATTERN_COMMENT_CHAMPS] =
	create_comment_champ(content);
	content->regex_array[PATTERN_COMMENT] = create_comment(content);
	content->regex_array[PATTERN_SPACE_OR_EMPTY_LINE] =
	create_pattern_space_or_empty_line(content);
	content->regex_array[PATTERN] = create_pattern(content);
	content->regex_array[PATTERN_NAME_OR_COMMENT_CHAMPS] =
	create_pattern_name_or_comment_champs(content);
	content->regex_array[PATTERN_HELP_VALIDATION_FIRST_CASE] =
	create_pattern_first(content);
	content->regex_array[PATTERN_HELP_VALIDATION_SECOND_CASE] =
	create_pattern_second(content);
	content->regex_array[PATTERN_HELP_VALIDATION_THIRD_CASE] =
	create_pattern_third(content);
}
