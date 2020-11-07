int Divide (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++)
        if (v[k] <= c) {
           t = v[j], v[j] = v[k], v[k] = t;
           j++;
        }
    v[r] = v[j], v[j] = c;
    return j;
}
void Quicksort (int p, int r, int v[]) {
     int j;
     if (p < r) {
        j = Divide (p, r, v);
        Quicksort (p, j - 1, v);
        Quicksort (j + 1, r, v);
     }
}

int RandomInteger (int low, int high)
{
    int k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

void gera_vetor(int v[]){
    int j;
    int i; 
    int k;
    for (i = 0; i< TAM; i++){
         j = RandomInteger (10, 100);
         for (k = 0; k < i; k++)
             if( v[k] == j ) break;
         if(k == i) v[i] = j;
         else i--;}
}

int main (void){
    int v[TAM]; // = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    gera_vetor(v);
    Quicksort(0, TAM - 1, v);
    debug("Final: ", v);
    system ("pause");
}
