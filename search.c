#include "cs50.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
string strings[] = {"call", "ball", "tall", "all"};

string s = get_string("String: ");
for( int i = 0; i < 4; i++)
{
    if (strcmp(strings[i], s) == 0)
    {
        printf("found\n");
        return 0;
    }
}
printf("not found\n");
return 1
}