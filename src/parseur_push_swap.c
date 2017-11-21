/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:34:13 by jpascal           #+#    #+#             */
/*   Updated: 2017/10/11 17:00:53 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rm_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

int				checkdoublons(t_pile *pilea, char *argv)
{
	t_pile		*tmpa;

	tmpa = pilea;
	while (tmpa != NULL)
	{
		if (tmpa->ent == ft_atoi(argv))
			return (1);
		tmpa = tmpa->next;
	}
	return (0);
}

int				checkerav(int argc, char **argv, int l)
{
	int			i;
	int			j;

	i = 1;
	if (l == 1)
		i = 2;
	while (i < argc)
	{
		j = 0;
		while (ft_isdigit(argv[i][j]) == 1 || argv[i][j] == ' ' ||
			argv[i][j] == '\t' || ((argv[i][j] == '+' || argv[i][j] == '-')
			&& ft_isdigit(argv[i][j + 1]) == 1 &&
			(argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t' || j == 0)))
			j++;
		if (argv[i][j] == '\0')
			i++;
		else
			return (0);
	}
	return (1);
}

void			parseur2(t_pile **pilea, char **tab)
{
	int				j;
	long long int	i;

	i = 0;
	j = 0;
	if (tab[j] != NULL)
	{
		while (tab[j])
			j++;
		while (--j >= 0)
		{
			i = ft_longatoi(tab[j]);
			if (checkdoublons(*pilea, tab[j]) == 1
				|| i > INT_MAX || i < INT_MIN || ft_strlen(tab[j]) > 11)
			{
				ft_putstr_fd("Error\n", 2);
				free_struct(pilea);
				exit(-1);
			}
			add_struct(pilea, ft_atoi(tab[j]));
		}
	}
	rm_tab(tab);
}

void			parseur(t_pile **pilea, int argc, char **argv, int l)
{
	int			i;
	char		**tab;
	int			j;

	i = argc;
	j = 0;
	if (l == 1)
		j = 1;
	if (checkerav(argc, argv, l) == 1)
		while (argv[--i] && i > j)
		{
			if (!(tab = ft_strsplit(argv[i], ' ')))
				exit(-1);
			parseur2(pilea, tab);
		}
	else
	{
		ft_putstr_fd("Error\n", 2);
		free_struct(pilea);
		exit(-1);
	}
}
