/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:33:49 by jpascal           #+#    #+#             */
/*   Updated: 2017/10/11 17:01:31 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				act_on_b(t_pile **pilea, t_pile **pileb, char *line)
{
	if (ft_strcmp(line, "rrr") == 0)
		reverse_rotate_a_et_b_checker(pilea, pileb);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(pileb, 0);
	else if (ft_strcmp(line, "pa") == 0)
		push_a_checker(pilea, pileb);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_a_et_b_checker(pilea, pileb);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(pileb, 0);
	else if (ft_strcmp(line, "ss") == 0)
		swap_a_et_b_checker(pilea, pileb);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate_b(pileb, 0);
	else
	{
		ft_putstr_fd("Error\n", 2);
		if (*pileb != NULL)
			free_struct(pileb);
		free_struct(pilea);
		exit(-1);
	}
}

void				act_on_a(t_pile **pilea, t_pile **pileb, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate_a(pilea, 0);
	else if (ft_strcmp(line, "pb") == 0)
		push_b_checker(pilea, pileb);
	else if (ft_strcmp(line, "sa") == 0)
		swap_a(pilea, 0);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate_a(pilea, 0);
	else
		act_on_b(pilea, pileb, line);
}

int					check_order(t_pile **pilea, t_pile **pileb)
{
	t_pile			*tmp;

	tmp = *pilea;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->ent > tmp->next->ent)
		{
			ft_putstr("KO\n");
			if (*pileb != NULL)
				free_struct(pileb);
			return (0);
		}
		tmp = tmp->next;
	}
	if (*pileb != NULL)
	{
		ft_putstr("KO\n");
		free_struct(pileb);
		return (0);
	}
	ft_putstr("OK\n");
	return (1);
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
		{
			act_on_a(&pilea, &pileb, line);
			ft_strdel(&line);
		}
		if (!check_order(&pilea, &pileb))
		{
			free_struct(&pilea);
			return (1);
		}
		free_struct(&pilea);
	}
	return (0);
}
