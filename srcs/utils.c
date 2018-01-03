/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:11:29 by agouby            #+#    #+#             */
/*   Updated: 2018/01/03 19:45:51 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_longest_arg(t_al *list)
{
	int		big;

	big = 0;
	while (list)
	{
		if (big < list->name_len)
			big = list->name_len;
		list = list->next;
	}
	return (big);
}

void	get_and_put(char *cmd)
{
	char	*s;

	s = tgetstr(cmd, NULL);
	tputs(s, 0, &putchar);
}

void	write_spaces(int n)
{
	char	str[n];

	ft_memset(str, ' ', n);
	write(STDOUT, str, n);
}

int		putchar(int c)
{
		return (write(STDOUT, &c, 1));
}
