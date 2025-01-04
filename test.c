#include "push_swap.h"
#include <stdio.h>


void check_int(char *string)
{
    char *max = "2147483647";
    int i = 0;5656
    while (string[i])
        i++;
    if (i > 10)
        exit(-1);
    if(i == 10)
    {
        i = 0;
        while (string[i])
        {
            if (string[i] > max[i])
                exit(-2);
            i++;
        }
    }
}

int main(int ac, char **av)
{
    check_int(av[1]);
    printf("%d\n", ft_atoi(av[1]));
}