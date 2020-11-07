int main (void){
    int p[128];
    int t = 0;
    unsigned int n = 18;

    while (n!=0){
        p[t++]= n % 2;
        n = n / 2;
    }
    while (t != 0)
        printf("%d", p[--t]);
    putchar('\n');
    system("pause");
}
