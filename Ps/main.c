/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:04:39 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/20 18:46:22 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void f()
// {
//     system("leaks push_swap");
// }
int	main(int argc, char **argv)
{
    // atexit(f);
	if (argc <= 1)
	{
		putstr("Error");
		exit(1);
	}
	for_main(argv, argc);
}
