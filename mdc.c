#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b){
    if (a % b == 0)
        return b;
    else
        return mdc(b, a % b);
}

int main (void){
    printf ("mdc(21, 15)=%d\n", mdc(15, 21));
    system("pause");
}
