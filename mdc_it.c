#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b){
    int t;
    while (a % b != 0){
        t = b;
        b = a % b;
        a = t;
    }
    return b;
}

int main(void) {
    printf ("mdc(%d, %d) = %d\n", 15, 21, mdc(15, 21));
    system("pause");    
}
