#include "header.h"
#include <string.h>

int recursiveSearch(int start, int end, char *name, struct s_art **arts)
{
	if (end <= start)
	{
		return ((arts[start] && strcmp(arts[start]->name, name) == 0) ? arts[start]->price : -1);
	}
	int mid = (start + end) / 2;
	int cmp = strcmp(arts[mid]->name, name);
	if (cmp == 0)
		return (arts[mid]->price);
	else if (cmp > 0)
		return (recursiveSearch(start, mid, name, arts));
	return (recursiveSearch(mid + 1, end, name, arts));
}

int searchPrice(struct s_art **arts, int n, char *name)
{
	return (recursiveSearch(0, n - 1, name, arts));
}
