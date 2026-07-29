#include "cs50.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[3];

    people[0].name = "dayo";
    people[0].number = "+234555";

    people[1].name = "mayo";
    people[1].number = "+234666";

     people[2].name = "sayo";
    people[2].number = "+234777";

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("found %s\n", people[i].number);
            return 0;
        }
    }
    printf("not found\n");
    return 1;
}
