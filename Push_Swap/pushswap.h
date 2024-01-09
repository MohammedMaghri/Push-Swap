/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:54:30 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/09 18:54:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSHSWAP_H
# define	PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct swap
{
	int		index;
	int		increment;
	char	*allocation;
	int		counter;
	int		total;
} t_fac;

typedef struct forparcing
{
	int		index;
	int		increment;
	char	*allocation;
} t_parc;
void putstr(char *string);

#endif 