int	is_unindexed(t_list *stack)
{
	while (stack)
	{
		if (stack->index == -1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	assign_indexes(t_list *stack)
{
	t_list	*tmp;
	t_list	*min_node;
	int		min_value;
	int		index;

	index = 0;
	while (is_unindexed(stack))
	{
		tmp = stack;
		min_node = NULL;
		min_value = INT_MAX;
		while (tmp)
		{
			if (tmp->index == -1 && (min_node == NULL || tmp->value < min_value))
			{
				min_node = tmp;
				min_value = tmp->value;
			}
			tmp = tmp->next;
		}
		min_node->index = index;
		index++;
	}
}
