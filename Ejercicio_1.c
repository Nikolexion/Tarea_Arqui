#include <stdio.h>
#include <string.h>

void intercambio(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void invertir(char *s) {
    int i, j;

    for (i = 0, j = strlen(*s); i < j; i++, j--) {
        intercambio(&s[i], &s[j]);
    }
}
