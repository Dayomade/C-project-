#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2){
        printf("usage: ./cipher<keyword>\n");
        return 1;
    }
    string keyword = argv[1];
    int keyword_len = strlen(keyword);
    string plaintext = get_string("plaintext: ");
    printf("ciphertext ");
    int j = 0;
    int plaintext_len = strlen(plaintext);
    for(int i = 0; i < plaintext_len; i++)
    {
        char c = plaintext[i];
        if (isupper(c))
        {
            int key = toupper(keyword[j % keyword_len]) -'A';
            char encrypted =((c - 'A'+ key) % 26) + 'A';
            printf("%c", encrypted);
            j++; 
        }
        else if (islower(c))
        {
            int key = toupper(keyword[j % keyword_len]) -'A';
            char encrypted =((c - 'a'+ key) % 26) + 'a';
            printf("%c", encrypted);
            j++; 
        }
        else
        {
            printf("%c", c);
        }

    }
    printf("\n");
    return 0;
}
