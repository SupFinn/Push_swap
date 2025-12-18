/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 23:55:10 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/17 16:06:38 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_list *stack, int size)
{
	int		*arr;
	t_list	*tmp;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	tmp = stack;
	while (i < size && tmp)
	{
		arr[i] = tmp->index;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}
int	*compute_lis_dp(int *arr, int size)
{
	int	i;
	int	j;
	int	*dp;

	dp = malloc(sizeof(int) * size);
	if (!dp)
		return (NULL);

	i = 0;
	while (i < size)
	{
		dp[i] = 1;
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
			j++;
		}
		i++;
	}
	return (dp);
}


int *reconstruct_lis(int *arr, int *dp, int size, int lis_length)
{
    int *lis;
    int i;
    int current_length;

    lis = malloc(sizeof(int) * lis_length);
    if (!lis)
        return (NULL);

    current_length = lis_length;
    i = size - 1;
    while (i >= 0)
    {
        if (dp[i] == current_length)
        {
            lis[current_length - 1] = arr[i];
            current_length--;
        }
        i--;
    }
    return lis;
}

static int  find_max_dp(int *dp, int size)
{
    int i;
    int max;

    i = 0;
    max = 0;
    while (i < size)
    {
        if (dp[i] > max)
            max = dp[i];
        i++;
    }
    return max;
}

int *get_lis(t_list *stack, int size, int *lis_length)
{
    int *arr;
    int *dp;
    int *lis;
    int max;

    arr = stack_to_array(stack, size);
    if (!arr)
        return NULL;
    dp = compute_lis_dp(arr, size);
    if (!dp)
    {
        free(arr);
        return NULL;
    }
    max = find_max_dp(dp, size);
    *lis_length = max;
    lis = reconstruct_lis(arr, dp, size, max);
    free(arr);
    free(dp);
    return lis;
}
