#include <stdio.h>

int main(void){
    unsigned char c;
    for (c = 10; c < 255; c++){
        putchar(c);
        //printf("%d ", (int) c);
        if (c % 20 == 0)
            system("pause");
    }
        //putchar(c);
    system("pause");
}
