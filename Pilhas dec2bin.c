#include <stdio.h>
#include <stdlib.h>

int main(void){
    int p[32];
    int t = 0;
    int n = 18;	
    
    while (n != 0){
        p[t++] = n % 2;
        n = n / 2;
    }
    while (t != 0)
        printf ("%d", p[--t]);

    system("pause");
}
