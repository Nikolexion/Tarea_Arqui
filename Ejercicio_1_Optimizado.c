#include <stdio.h>
#include <string.h>

void invertir(char *s) {
    int i, length = strlen(s);

    for (i = 0; i < length; i+=2) {
        char temp = s[i];
        s[i] = s[length - 1 - i];
        s[length - 1 - i] = temp;
    }
}
