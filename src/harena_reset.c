/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harena_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:54:41 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/02 01:45:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <harena.h>

void	harena_reset(t_harena *h)
{
    if (!h || !h->base)
        return ;
    ft_memset(h->base, 0, h->offset);
    h->offset = 0;
}
