/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harena_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:55:41 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/02 02:19:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <harena.h>

void        harena_destroy(t_harena *h)
{
    if (!h || !h->base)
        return ;
    free(h->base);
    ft_memset(h, 0, h->offset);
    h->offset = 0;
}
