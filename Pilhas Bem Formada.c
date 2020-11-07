int BemFormada (char s[]) {
    char *p; int t;
    int n, i;
    n = strlen (s);
    p = malloc (n * sizeof (char));
    t = 0;
    for (i = 0; s[i] != '\0'; i++) {
    /* p[0..t-1] é uma pilha */
        switch (s[i]) {
            case ')': if (t != 0 && p[t-1] == '(') --t;
                      else return 0;
                      break;
            case '}': if (t != 0 && p[t-1] == '{') --t;
                      else return 0;
                      break;
            default: p[t++] = s[i];
        }
    }
    free (p);
    return t == 0;
}

int main (void) {
    printf ("%s\n", BemFormada ("((){()})") ? "Bem formada" : "Mal formada");
    printf ("%s\n", BemFormada ("({)}") ? "Bem formada" : "Mal formada");
    system ("pause");
}
