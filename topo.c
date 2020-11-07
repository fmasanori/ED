#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int i, n;
    float x;

    printf("%d argumentos: ", argc);
    for (i = 1; i < argc; i++) 
        printf("%s ", argv[i]);
    putchar ('\n');

    n = atoi(argv[1]);
    x = atof(argv[2]);
    printf("Depois de transformados: %d %f\n", n, x); 
    return 1;
}
