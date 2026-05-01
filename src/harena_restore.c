/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harena_restore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 01:39:30 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/02 01:44:13 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <harena.h>

void	harena_restore(t_harena *h, const size_t size)
{
	if (!h || !h->base || size > h->capacity)
		return ;
	h->offset = size;
}
