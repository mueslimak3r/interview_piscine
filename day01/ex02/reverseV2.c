#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stack	*stackInit(void)
{
	struct s_stack	*new;
	if (!(new = malloc(sizeof(struct s_stack))))
		return (NULL);
	new->item = NULL;
	return (new);
}

void			*pop(struct s_stack	*stack)
{
	struct s_item	*tmp;
	char			*word;

	if (!stack || !stack->item)
		return (NULL);
	tmp = stack->item;
	stack->item = stack->item->next;
	tmp->next = NULL;
	word = tmp->word;
	free(tmp);
	return (word);
}

void			push(struct s_stack *stack, char *word)
{
	struct s_item	*new;

	if (!stack || !(new = malloc(sizeof(struct s_item))))
		return ;
	new->word = word;
	new->next = stack->item;
	stack->item = new;
}

void	printReverseV2(struct s_node *lst)
{
	struct s_stack	*stack;
	int				i;

	i = 0;
	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (stack->item)
	{
		printf(i == 0 ? "%s" : " %s", (char*)pop(stack));
		i++;
	}
	printf("\n");
	free(stack);
}