/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:33:49 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:33:51 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				actions2(t_pile **pilea, t_pile **pileb, char *line)
{
	if (ft_strcmp(line, "rrr") == 0)
		reverse_rotate_a_et_b_checker(pilea, pileb);
	else if (ft_strcmp(line, "pa") == 0)
		push_a_checker(pilea, pileb);
	else if (ft_strcmp(line, "pb") == 0)
		push_b_checker(pilea, pileb);
	else
	{
		ft_putstr_fd("Error", 2);
		exit(-1);
	}
}

void				actions(t_pile **pilea, t_pile **pileb, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate_a(pilea, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(pileb, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_a_et_b_checker(pilea, pileb);
	else if (ft_strcmp(line, "sa") == 0)
		swap_a(pilea, 0);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(pileb, 0);
	else if (ft_strcmp(line, "ss") == 0)
		swap_a_et_b_checker(pilea, pileb);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate_a(pilea, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate_b(pileb, 0);
	else
		actions2(pilea, pileb, line);
}

int					main(int argc, char **argv)
{
	t_pile			*pilea;
	t_pile			*pileb;
	char			*line;

	line = NULL;
	pileb = NULL;
	pilea = NULL;
	parseur(&pilea, argc, argv, 0);
	if (pilea != NULL)
	{
		while (get_next_line(0, &line) == 1)
			actions(&pilea, &pileb, line);
		while (pilea && pilea->next != NULL)
		{
			if (pilea->ent > pilea->next->ent || pileb != NULL)
			{
				ft_putstr("KO");
				exit(-1);
			}
			pilea = pilea->next;
		}
		ft_putstr("OK");
	}
	return (0);
}
