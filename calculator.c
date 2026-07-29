#include <stdio.h>
#include "cs50.h"

int main(void)
{
    char op = get_char("enter operator(+,-,*,/); ");
    float num1 = get_float("enter first number: ");
    float num2 = get_float("enter second number: ");
    float result;
    if (op == '+'){
        result = num1 + num2;
        printf("result:%f\n", result);
    }
    else if(op == '-'){
        result = num1 - num2;
        printf("result: %f\n", result);
    }
    else if(op == '*'){
         result = num1 * num2;
        printf("result: %f\n", result);
    }
    else if(op == '/')
    {
        if(num2 == '0')

           { printf("output error.\n");
            return 1;
        }
        else{
            result = num1 / num2;
            printf("result: %f\n", result);
        }
    }
        else{
            printf("output error: invalid operator selected.\n");
            return 1;
        }
        return 0;
    }

