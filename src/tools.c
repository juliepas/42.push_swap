/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:37:28 by jpascal           #+#    #+#             */
/*   Updated: 2017/08/24 18:37:30 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int			ft_longatoi(const char *str)
{
	int				i;
	int				s;
	long long int	nb;

	s = 1;
	nb = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == 45)
	{
		s = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * s);
}

int					find_smallest(t_pile **pilea)
{
	t_pile			*tmpa;
	int				smaller;

	tmpa = *pilea;
	smaller = tmpa->ent;
	while (tmpa)
	{
		if (tmpa->ent < smaller)
			smaller = tmpa->ent;
		tmpa = tmpa->next;
	}
	return (smaller);
}

int					find_mediane(t_pile **pilea, int height, int argc)
{
	t_pile			*tmpa;
	int				tab[height];
	int				i;
	int				entier;

	i = height;
	while (i >= 0)
	{
		tmpa = *pilea;
		entier = find_smallest(pilea);
		while (tmpa != NULL)
		{
			if ((i == height) && tmpa->ent > entier)
				entier = tmpa->ent;
			else if (i < (height) && tmpa->ent > entier
				&& tmpa->ent < tab[i + 1])
				entier = tmpa->ent;
			tmpa = tmpa->next;
		}
		tab[i] = entier;
		i--;
	}
	i = 0;
	return (tab[(height / ((argc / 100) + 2))]);
}

int					list_height(t_pile **pilex)
{
	t_pile			*tmp;
	int				i;

	i = 0;
	tmp = *pilex;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int					find_place_value_b(t_pile **pilex, int value)
{
	int				i;
	t_pile			*tmp;
	int				height;
	t_pile			*lastmp;

	i = 1;
	tmp = *pilex;
	height = list_height(pilex);
	lastmp = *pilex;
	while (lastmp->next)
		lastmp = lastmp->next;
	if (lastmp->ent > value && tmp->ent < value)
		return (0);
	while (tmp && tmp->next != NULL)
	{
		if (tmp->ent > value && tmp->next->ent < value)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
