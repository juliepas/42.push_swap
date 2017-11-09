/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:37:22 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:37:23 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			swap_a(t_pile **pilea, int i)
{
	t_pile		*tmp;
	t_pile		*tmp2;
	int			tamp;

	tmp = *pilea;
	tmp2 = NULL;
	tamp = 0;
	if (tmp && tmp->next != NULL)
	{
		tmp2 = tmp->next;
		ft_swap(&tmp->ent, &tmp2->ent);
		if (i == 1)
			ft_putstr("sa\n");
	}
}

void			swap_b(t_pile **pileb, int i)
{
	t_pile		*tmp;
	t_pile		*tmp2;
	int			tamp;

	tmp = *pileb;
	tmp2 = NULL;
	tamp = 0;
	if (tmp && tmp->next != NULL)
	{
		tmp2 = tmp->next;
		tamp = tmp->ent;
		tmp->ent = tmp2->ent;
		tmp2->ent = tamp;
		if (i == 1)
			ft_putstr("sb\n");
	}
}

void			swap_a_et_b(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;
	t_pile		*tmpb;

	tmpa = *pilea;
	tmpb = *pileb;
	if (tmpa)
		swap_a(&tmpa, 0);
	if (tmpb)
		swap_b(&tmpb, 0);
	ft_putstr("ss\n");
}

void			swap_a_et_b_checker(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;
	t_pile		*tmpb;

	tmpa = *pilea;
	tmpb = *pileb;
	if (tmpa)
		swap_a(&tmpa, 0);
	if (tmpb)
		swap_b(&tmpb, 0);
}
