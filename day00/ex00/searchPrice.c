#include "header.h"
#include <string.h>

int searchPrice(struct s_art **arts,char *name)
{
    if (!arts)
        return (-1);
    for (int i = 0; arts[i]; i++)
    {
        if (strcmp(arts[i]->name, name) == 0)
            return (arts[i]->price);
    }
    return (-1);
}
