/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:10:44 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/17 14:50:00 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reverse_arr(int *arr, int size)
{
	int i;
	int tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
		i++;
	}
}
