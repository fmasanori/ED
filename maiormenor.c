#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

int maior,menor;

void maxmin(int n,int v[]){
    if (n == 1) maior = menor = v[0];  
    else {
        maxmin(n - 1,v);
        if (maior < v[n - 1]) maior = v[n - 1];
        if (menor > v[n - 1]) menor = v[n - 1];
        }            
}

main(){
    int lista[] = {60,13,12,9,2,19,80};
    maxmin(7,lista);
    printf("%i,%i",maior,menor);
    getch();
}
