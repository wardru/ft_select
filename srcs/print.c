/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:11:03 by agouby            #+#    #+#             */
/*   Updated: 2018/02/12 12:47:31 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			print_selected(t_al *list)
{
	while (list && !list->select)
		list = list->next;
	if (list)
		ft_printf("%s", list->name);
	else
		return ;
	while ((list = list->next))
	{
		if (list->select)
			ft_printf(" %s", list->name);
	}
}

void			print_index(t_al *list, t_al *sel, int index, int longest)
{
	int		i;
	t_al	*arg;

	i = 0;
	while (list && index != i)
	{
		list = list->next;
		i++;
	}
	if (!list)
		return ;
	arg = list;
	if (arg == sel)
		write(STDOUT, UNDERLINE, 4);
	if (arg->select)
		write(STDOUT, SELECT_CLR, LEN_CLR);
	if (arg == sel && arg->select)
		write(STDOUT, COMBI_CLR, LEN_CLR);
	write(STDOUT, arg->name, arg->name_len);
	write(STDOUT, CLEAR_CLR, LEN_CLR);
	write(STDOUT, "\e[0m", 4);
	write_spaces(longest - arg->name_len + 1);
}

static void		print_loop(t_args args, int nb_per_line, int nb_lines)
{
	int		i;
	int		j;
	int		decal;
	int		tmp;

	i = 0;
	decal = 0;
	while (i < nb_lines)
	{
		j = decal;
		tmp = nb_per_line;
		while (tmp)
		{
			print_index(args.list, args.sel, j, args.longest);
			j += nb_lines;
			--tmp;
		}
		ft_printf("\n");
		++i;
		++decal;
	}
}

void			print_args(t_args args, int nb_lines)
{
	int	nb_per_line;

	if (!nb_lines)
	{
		write(STDOUT, TOO_SMALL, ft_strlen(TOO_SMALL));
		return ;
	}
	nb_per_line = args.nb_args / nb_lines;
	if (args.nb_args % nb_lines)
		++nb_per_line;
	print_loop(args, nb_per_line, nb_lines);
}

void			print_bar(t_bar bar)
{
	if (ft_strlen(bar.buf) > bar.len)
		return ;
	write(STDOUT, BAR_CLR, LEN_CLR);
	write(STDOUT, bar.buf, bar.i);
	if (bar.len - bar.i > 0)
		write_spaces(bar.len - bar.i);
	write(STDOUT, CLEAR_CLR, LEN_CLR);
}
