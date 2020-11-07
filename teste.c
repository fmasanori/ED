#include <stdio.h>
#include <stdlib.h>

int Max, Min;


int mdc(int a, int b){
    if (a % b == 0)
        return b;
    else
        return mdc(b, a%b);
}

int main(void){
    int a = 21, b = 15;
    printf("mdc(%d, %d) = %d\n", a, b, mdc(a, b));
    system("pause");
}
