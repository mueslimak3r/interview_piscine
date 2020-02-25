#include "header.h"

int     main(int ac, char **av)
{
    int price;
    t_art *arts[5] =
    {
        &(t_art){ "mona lisa", 2000000 },
        &(t_art){ "campbell soup", 1000000 },
        &(t_art){ "blank canvas", 10000000 },
        &(t_art){ "just a plinth", 200000 },
        NULL
    };

    if (ac > 1)
    {
        for (int i = 1; i < ac; i++)
        {
            price = searchPrice(arts, av[i]);
            if (price == -1)
                printf("the absence of art is itself art\n");
            else
                printf("price of %s is %d\n", av[i], price);
        }
    }
    else
    {
        price = searchPrice(arts, "blank canvas");
        if (price == -1)
            printf("the absence of art is itself art\n");
        else
            printf("price of %s is %d\n", "blank canvas", price);
    }
    return (0);
}
