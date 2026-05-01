/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harena_calloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 01:19:36 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/02 01:44:56 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <harena.h>

void	*harena_calloc(t_harena *h, const size_t bytes)
{
	void	*ptr;

	if (!h || !h->base || bytes == 0)
        return (NULL);
	ptr = harena_alloc(h, bytes);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, bytes);
	return (ptr);
}
