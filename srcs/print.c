/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 03:02:46 by agouby            #+#    #+#             */
/*   Updated: 2017/11/27 00:37:00 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_selected(t_al *list)
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

void	write_spaces(int n)
{
	while (n)
	{
		write(STDOUT, " ", 1);
		n--;
	}
}

void	print_args(t_al *args, t_al *sel, int longest)
{
	while (args)
	{
		if (args == sel)
			write(STDOUT, UNDERLINE, 4);
		if (args->select)
			write(STDOUT, SELECT_CLR, LEN_CLR);
		if (args == sel && args->select)
			write(STDOUT, COMBI_CLR, LEN_CLR);
		write(STDOUT, args->name, args->name_len);
		write(STDOUT, CLEAR_CLR, LEN_CLR);
		write(STDOUT, "\e[0m", 4);
		write_spaces(longest - args->name_len);
		if (args->next)
			write(STDOUT, " ", 1);
		args = args->next;
	}
}

void	print_bar(t_bar bar)
{
	char	*pr;

	pr = tgetstr("cm", NULL);
	tputs(tgoto(pr, 0, bar.pos), 0, putc);
	write(STDOUT, BAR_CLR, LEN_CLR);
	write(STDOUT, bar.buf, bar.i);
	write_spaces(bar.len - bar.i);
	write(STDOUT, CLEAR_CLR, LEN_CLR);
}
