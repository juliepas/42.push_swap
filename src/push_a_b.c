/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:34:21 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:34:24 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push_a(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpb;

	tmpb = *pileb;
	if (tmpb)
	{
		*pileb = tmpb->next;
		if (*pilea != NULL)
			tmpb->next = *pilea;
		else
			tmpb->next = NULL;
		*pilea = tmpb;
		ft_putstr("pa\n");
	}
}

void			push_b(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;

	tmpa = *pilea;
	if (tmpa)
	{
		*pilea = tmpa->next;
		if (*pileb != NULL)
			tmpa->next = *pileb;
		else
			tmpa->next = NULL;
		*pileb = tmpa;
		ft_putstr("pb\n");
	}
}

void			push_a_checker(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpb;

	tmpb = *pileb;
	if (tmpb)
	{
		if (tmpb->next)
			*pileb = tmpb->next;
		else
			*pileb = NULL;
		if (*pilea != NULL)
			tmpb->next = *pilea;
		else
			tmpb->next = NULL;
		*pilea = tmpb;
	}
}

void			push_b_checker(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;

	tmpa = *pilea;
	if (tmpa)
	{
		*pilea = tmpa->next;
		if (*pileb != NULL)
			tmpa->next = *pileb;
		else
			tmpa->next = NULL;
		*pileb = tmpa;
	}
}
