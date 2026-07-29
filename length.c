#include <stdio.h>
#include "cs50.h"
#include <ctype.h>
#include <string.h>

int main(void)
{
    string name = get_string("what is your name? ");
    int length = strlen(name);
    printf("the length of your name is: %i\n",length);
}