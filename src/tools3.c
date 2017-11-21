/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:16:07 by jpascal           #+#    #+#             */
/*   Updated: 2017/11/19 17:16:12 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_struct(t_pile **pilex)
{
	t_pile *tmp;
	t_pile *tamp;

	tmp = *pilex;
	tamp = *pilex;
	while (tamp != NULL)
	{
		tmp = tamp;
		free(tamp);
		tamp = tmp->next;
	}
}
