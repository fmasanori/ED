#include <stdio.h>

int main(void){
    float F;
    float C;
    printf ("Farenheit: ");
    scanf ("%f", &F);
    C = 5 * (F-32) / 9;
    printf ("Celsius: %2.1f\n", C);
}
