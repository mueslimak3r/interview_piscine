#include "header.h"
#include <string.h>

int get_len(struct s_art **arts)
{
	int i = 0;
	if (!arts)
		return (0);
	while (arts[i])
		i++;
	return (i);
}

void	merge_sort_arts(int start, int end, struct s_art **arts, struct s_art **aux)
{
	if (end <= start)
		return ;
	int mid = (start + end) / 2;
	merge_sort_arts(start, mid, arts, arts);
	merge_sort_arts(mid + 1, end, arts, aux);

	int pointer_left = start;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter

    // we loop from i to j to fill each element of the final merged array
    for (k = start; k <= end; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = arts[pointer_right];
            pointer_right++;
        } else if (pointer_right == end + 1) {        // right pointer has reached the limit
            aux[k] = arts[pointer_left];
            pointer_left++;
        } else if (strcmp(arts[pointer_left]->name, arts[pointer_right]->name) < 0) {        // pointer left points to smaller element
            aux[k] = arts[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = arts[pointer_right];
            pointer_right++;
        }
    }

    for (k = start; k <= end; k++) {      // copy the elements from aux[] to a[]
        arts[k] = aux[k];
    }
}

#include <stdio.h> //printf, scanf, ...

void sortArts(struct s_art **arts)
{
	int len = get_len(arts);
	struct s_art *aux[len];
	if (len > 1)
		merge_sort_arts(0, len - 1, arts, aux);
	int len2 = get_len(arts);
	printf("len1: %d len2: %d\n", len, len2);
}
