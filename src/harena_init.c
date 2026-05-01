/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harena_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:34:42 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/02 02:32:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <harena.h>

t_bool  harena_init(t_harena *h, const size_t capacity)
{
    if (!h || capacity == 0)
        return (FALSE);
    h->base = malloc(capacity);
    if (!h->base)
        return (FALSE);
    h->offset = 0;
    h->capacity = capacity;
    return (TRUE);
}
