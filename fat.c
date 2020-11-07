#include <stdio.h>
#include <stdlib.h>

int fat(int n){
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fat(n-1);
}

int main (void){
    printf ("fat=%d\n", fat(3));
    system ("pause");
}
