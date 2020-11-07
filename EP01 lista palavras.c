#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp;
    char str[255];
    char *p;
    #define MAX_STR     255

    fp = fopen("D:\\Aulas\\ED\\Alice.txt", "r");
    if (fp == NULL) {
        printf ("Arquivo nao encontrado\n");
        exit (-1);
    }
    while (fgets (str, MAX_STR, fp) != NULL){
        p = str;
        
    }
    fclose (fp);
}
