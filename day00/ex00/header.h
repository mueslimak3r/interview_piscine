#ifndef SEARCH_PRICE_H
# define SEARCH_PRICE_H

# include <stdio.h>
# include <string.h>

typedef struct s_art t_art;

struct s_art
{
    char    *name;
    int     price;
};

int searchPrice(struct s_art **arts,char *name);

#endif
