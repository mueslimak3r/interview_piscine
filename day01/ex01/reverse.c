#include "header.h"
#include <stdio.h>

static void	printRecurse(struct s_node *lst, int nb)
{
	if (lst->next)
		printRecurse(lst->next, nb + 1);
	printf(nb == 0 ? "%s" : "%s ", lst->word);
}

void	printReverse(struct s_node *lst)
{
	printRecurse(lst, 0);
	printf("\n");
}