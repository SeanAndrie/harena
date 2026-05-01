/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harena_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:51:55 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/02 01:26:45 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <harena.h>

void	*harena_alloc(t_harena *h, const size_t bytes)
{
	void	*ptr;
	size_t	aligned;

	if (!h || !h->base || bytes == 0)
		return (NULL);
	aligned = (bytes + 7) & ~7;
    if (aligned > h->capacity - h->offset)
		return (NULL);
    ptr = h->base + h->offset;
	h->offset += aligned;
	return (ptr);
}
