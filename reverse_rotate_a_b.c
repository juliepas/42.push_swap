/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:36:55 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:36:56 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			reverse_rotate_a(t_pile **pilea, int i)
{
	t_pile		*tmp;

	tmp = *pilea;
	if (tmp && tmp->next != NULL && tmp->next->next != NULL)
	{
		while (tmp && tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = *pilea;
		*pilea = tmp->next;
		tmp->next = NULL;
	}
	else
		swap_a(&tmp, 0);
	if (i == 1)
		ft_putstr("rra\n");
}

void			reverse_rotate_b(t_pile **pileb, int i)
{
	t_pile		*tmp;

	tmp = *pileb;
	if (tmp && tmp->next != NULL && tmp->next->next != NULL)
	{
		while (tmp && tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = *pileb;
		*pileb = tmp->next;
		tmp->next = NULL;
	}
	else
		swap_a(&tmp, 0);
	if (i == 1)
		ft_putstr("rrb\n");
}

void			reverse_rotate_a_et_b(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;
	t_pile		*tmpb;

	tmpa = *pilea;
	tmpb = *pileb;
	if (tmpa)
		reverse_rotate_a(pilea, 0);
	if (tmpb)
		reverse_rotate_b(pileb, 0);
	ft_putstr("rrr\n");
}

void			reverse_rotate_a_et_b_checker(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;
	t_pile		*tmpb;

	tmpa = *pilea;
	tmpb = *pileb;
	if (tmpa)
		reverse_rotate_a(pilea, 0);
	if (tmpb)
		reverse_rotate_b(pileb, 0);
}
