/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:37:35 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:37:36 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			add_struct(t_pile **pilea, int argv)
{
	t_pile		*new;
	t_pile		*tmpa;

	tmpa = *pilea;
	if (!(new = ft_memalloc(sizeof(t_pile))))
		exit(-1);
	new->ent = argv;
	new->next = NULL;
	if (*pilea != NULL)
		new->next = tmpa;
	*pilea = new;
}

int				check_sort(t_pile **pilex)
{
	t_pile *tmp;

	tmp = *pilex;
	while (tmp && tmp->next)
	{
		if (tmp->ent > tmp->next->ent)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				find_index(t_pile **pilea, int value)
{
	t_pile		*tmpa;
	int			i;

	i = 0;
	tmpa = *pilea;
	while (tmpa && tmpa->ent != value)
	{
		i++;
		tmpa = tmpa->next;
	}
	return (i);
}

int				find_value(t_pile **pilex, int index)
{
	t_pile		*tmp;
	int			i;

	i = 0;
	tmp = *pilex;
	while (tmp && i < index)
	{
		i++;
		tmp = tmp->next;
	}
	return (tmp->ent);
}

void			afficher_liste(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmpa;
	t_pile		*tmpb;

	tmpa = *pilea;
	tmpb = *pileb;
	while (tmpa)
	{
		ft_putnbr(tmpa->ent);
		ft_putchar('|');
		tmpa = tmpa->next;
	}
	ft_putchar('\n');
	while (tmpb)
	{
		ft_putnbr(tmpb->ent);
		ft_putchar('|');
		tmpb = tmpb->next;
	}
}
