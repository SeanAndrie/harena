/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harena_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:34:42 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/02 01:36:10 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <harena.h>

t_harena	harena_create(const size_t capacity)
{
	t_harena	h;

	if (capacity == 0)
		return ((t_harena){NULL, 0, 0});
	h.base = malloc(capacity);
	if (!h.base)
		return ((t_harena){NULL, 0, 0});
	h.offset = 0;
	h.capacity = capacity;
	return (h);
}
