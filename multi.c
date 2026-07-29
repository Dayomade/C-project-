#include <stdio.h>
#include "cs50.h"

int main(int argc, string argv[]){

if (argc < 2){
    printf("usage: ./multi text1 text2 ...\n");
    return 1;
}

for(int i = 1; i < argc; i++){
        printf("%s\n", argv[i]);
    }
return 0;
}