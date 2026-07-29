#include <stdio.h>
#include "cs50.h"

int main(void)
{
    int size;
    do{
        size = get_int("size of shape: ");
    }
    while(size < 1);
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < i - 2; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}