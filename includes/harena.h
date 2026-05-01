/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harena.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:01:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/02 02:32:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARENA_H
# define HARENA_H

# include <libft.h>
# include <stdint.h>

typedef struct s_harena
{
	uint8_t	*base;
	size_t	offset;
	size_t	capacity;
}			t_harena;

t_harena	*harena_create(const size_t capacity);
t_bool		harena_init(t_harena *h, const size_t size);
void		*harena_alloc(t_harena *h, const size_t bytes);
void		*harena_calloc(t_harena *h, const size_t bytes);

size_t		harena_save(t_harena *h);
void		harena_restore(t_harena *h, const size_t size);

void		harena_reset(t_harena *h);
void		harena_destroy(t_harena *h);
void		harena_free(t_harena *h);

#endif
