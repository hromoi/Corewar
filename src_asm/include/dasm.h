/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:52:05 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/02/20 19:45:32 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DASM_H
# define DASM_H

# define MAGIC_NUMBER_SIZE 4
# define NULL_SIZE 4
# define CHMP_CODE_VAR_SIZE 4
# define NAME_CMD_LEN 5
# define COMMENT_CMD_LEN 8
# define SPACE_LEN 1
# define D_QUOTE_LEN 1
# define SLASH_N_LEN 1
# define ARGS_TYPES_COUNT 3
# define BUFF_SIZE_FOR_DIS 4096
# define OP_TAB_SIZE 17

typedef struct			s_op
{
	char				*op_name;
	u_int8_t			args_num;
	u_int8_t			args_types[3];
	u_int8_t			op_code;
	int					op_cycles;
	char				*op_comment;
	t_bool				args_types_code;
	u_int8_t			t_dir_size;
	u_int8_t			oname_size;
}						t_op;

static t_op				g_tab[17] = {
	{
		.op_name = 0,
		.args_num = 0,
		.args_types = {0},
		.op_code = 0,
		.op_cycles = 0,
		.op_comment = 0,
		.args_types_code = 0,
		.t_dir_size = 0,
		.oname_size = 0,
	},
	{
		.op_name = "live",
		.args_num = 1,
		.args_types = {T_DIR},
		.op_code = 1,
		.op_cycles = 10,
		.op_comment = "alive",
		.args_types_code = 0,
		.t_dir_size = 4,
		.oname_size = 4,
	},
	{
		.op_name = "ld",
		.args_num = 2,
		.args_types = {T_DIR | T_IND, T_REG},
		.op_code = 2,
		.op_cycles = 5,
		.op_comment = "load",
		.args_types_code = 1,
		.t_dir_size = 4,
		.oname_size = 2,
	},
	{
		.op_name = "st",
		.args_num = 2,
		.args_types = {T_REG, T_IND | T_REG},
		.op_code = 3,
		.op_cycles = 5,
		.op_comment = "store",
		.args_types_code = 1,
		.t_dir_size = 4,
		.oname_size = 2,
	},
	{
		.op_name = "add",
		.args_num = 3,
		.args_types = {T_REG, T_REG, T_REG},
		.op_code = 4,
		.op_cycles = 10,
		.op_comment = "addition",
		.args_types_code = 1,
		.t_dir_size = 4,
		.oname_size = 3,
	},
	{
		.op_name = "sub",
		.args_num = 3,
		.args_types = {T_REG, T_REG, T_REG},
		.op_code = 5,
		.op_cycles = 10,
		.op_comment = "soustraction",
		.args_types_code = 1,
		.t_dir_size = 4,
		.oname_size = 3,
	},
	{
		.op_name = "and",
		.args_num = 3,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		.op_code = 6,
		.op_cycles = 6,
		.op_comment = "et (and  r1, r2, r3   r1&r2 -> r3",
		.args_types_code = 1,
		.t_dir_size = 4,
		.oname_size = 3,
	},
	{
		.op_name = "or",
		.args_num = 3,
		.args_types = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.op_code = 7,
		.op_cycles = 6,
		.op_comment = "ou  (or   r1, r2, r3   r1 | r2 -> r3",
		.args_types_code = 1,
		.t_dir_size = 4,
		.oname_size = 2,
	},
	{
		.op_name = "xor",
		.args_num = 3,
		.args_types = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.op_code = 8,
		.op_cycles = 6,
		.op_comment = "ou (xor  r1, r2, r3   r1^r2 -> r3",
		.args_types_code = 1,
		.t_dir_size = 4,
		.oname_size = 3,
	},
	{
		.op_name = "zjmp",
		.args_num = 1,
		.args_types = {T_DIR},
		.op_code = 9,
		.op_cycles = 20,
		.op_comment = "jump if zero",
		.args_types_code = 0,
		.t_dir_size = 2,
		.oname_size = 4,
	},
	{
		.op_name = "ldi",
		.args_num = 3,
		.args_types = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.op_code = 10,
		.op_cycles = 25,
		.op_comment = "load index",
		.args_types_code = 1,
		.t_dir_size = 2,
		.oname_size = 3,
	},
	{
		.op_name = "sti",
		.args_num = 3,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.op_code = 11,
		.op_cycles = 25,
		.op_comment = "store index",
		.args_types_code = 1,
		.t_dir_size = 2,
		.oname_size = 3,
	},
	{
		.op_name = "fork",
		.args_num = 1,
		.args_types = {T_DIR},
		.op_code = 12,
		.op_cycles = 800,
		.op_comment = "fork",
		.args_types_code = 0,
		.t_dir_size = 2,
		.oname_size = 4,
	},
	{
		.op_name = "lld",
		.args_num = 2,
		.args_types = {T_DIR | T_IND, T_REG},
		.op_code = 13,
		.op_cycles = 10,
		.op_comment = "long load",
		.args_types_code = 1,
		.t_dir_size = 4,
		.oname_size = 3,
	},
	{
		.op_name = "lldi",
		.args_num = 3,
		.args_types = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.op_code = 14,
		.op_cycles = 50,
		.op_comment = "long load index",
		.args_types_code = 1,
		.t_dir_size = 2,
		.oname_size = 4,
	},
	{
		.op_name = "lfork",
		.args_num = 1,
		.args_types = {T_DIR},
		.op_code = 15,
		.op_cycles = 1000,
		.op_comment = "long fork",
		.args_types_code = 0,
		.t_dir_size = 2,
		.oname_size = 5,
	},
	{
		.op_name = "aff",
		.args_num = 1,
		.args_types = {T_REG},
		.op_code = 16,
		.op_cycles = 2,
		.op_comment = "aff",
		.args_types_code = 1,
		.t_dir_size = 4,
		.oname_size = 3,
	}
};

#endif
