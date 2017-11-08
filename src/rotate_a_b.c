/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:37:04 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:37:06 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rotate_a(t_pile **pilea, int i)
{
	t_pile		*tmp;

	tmp = *pilea;
	if (tmp && tmp->next != NULL && tmp->next->next != NULL)
	{
		while (tmp && tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *pilea;
		tmp = *pilea;
		*pilea = tmp->next;
		tmp->next = NULL;
	}
	else
		swap_a(&tmp, 0);
	if (i == 1)
		ft_putstr("ra\n");
}

void			rotate_b(t_pile **pileb, int i)
{
	t_pile		*tmp;

	tmp = *pileb;
	if (tmp && tmp->next != NULL && tmp->next->next != NULL)
	{
		while (tmp && tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *pileb;
		tmp = *pileb;
		*pileb = tmp->next;
		tmp->next = NULL;
	}
	else
		swap_b(&tmp, 0);
	if (i == 1)
		ft_putstr("rb\n");
}

void			rotate_a_et_b(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;
	t_pile		*tmpb;

	tmpa = *pilea;
	tmpb = *pileb;
	if (tmpa)
		rotate_a(pilea, 0);
	if (tmpb)
		rotate_b(pileb, 0);
	ft_putstr("rr\n");
}

void			rotate_a_et_b_checker(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;
	t_pile		*tmpb;

	tmpa = *pilea;
	tmpb = *pileb;
	if (tmpa)
		rotate_a(pilea, 0);
	if (tmpb)
		rotate_b(pileb, 0);
}
