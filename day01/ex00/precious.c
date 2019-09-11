#include "header.h"

#include <string.h>
#include <stdlib.h>

void	push(struct s_node **list, char c)
{
	struct s_node	*new;

	if (!(new = malloc(sizeof(struct s_node))))
		return ;
	new->c = c;
	if (*list)
	{
		new->next = *list;
		(*list)->prev->next = new;
		new->prev = (*list)->prev;
		(*list)->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	*list = new;
}

char	pop(struct s_node **list, int offset)
{
	int	turns = offset;
	while ((offset < 0) ? turns < 0 : turns > 0)
	{
		*list = (offset < 0) ? (*list)->prev : (*list)->next;
		turns += offset < 0 ? 1 : -1;
	}
	return ((*list)->c);
}

char	*precious(int *text, int size)
{
	struct s_node	*list;
	char	ret[size + 1];

	list = NULL;
	if (size == 0 || !text)
		return ("");
	for (int i = strlen(CS) - 1; i >= 0; i--)
		push(&list, CS[i]);
	for (int i = 0; i < size; i++)
		ret[i] = pop(&list, text[i]);
	return(strdup(ret));
}