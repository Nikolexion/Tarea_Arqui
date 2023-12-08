#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

double perfomanceCounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart-b->QuadPart)/(double)freq.QuadPart;
}

void invertir(char *s) {
    int length = strlen(s);
    char *start = s;
    char *end = s + length - 1;

    while (start < end) {
        *start ^= *end;
        *end ^= *start;
        *start ^= *end;
        start++;
        end--;
    }
}

void intercambiar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void invertir_optimizada_1(char *s) {
    int i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        intercambiar(&s[i], &s[j]);
    }
}


void invertir_optimizada_2(char *s) {
    int length = strlen(s);
    char *start = s;
    char *end = s + length - 1;

    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}


void invertir_optimizada_3(char *s) {
    int length = strlen(s);
    int i;

    for (i = 0; i < length - 6; i += 6) {
        char temp1 = s[i];
        char temp2 = s[i + 1];
        char temp3 = s[i + 2];
        char temp4 = s[i + 3];
        char temp5 = s[i + 4];
        char temp6 = s[i + 5];

        s[i] = s[length - 1 - i];
        s[i + 1] = s[length - 2 - i];
        s[i + 2] = s[length - 3 - i];
        s[i + 3] = s[length - 4 - i];
        s[i + 4] = s[length - 5 - i];
        s[i + 5] = s[length - 6 - i];

        s[length - 1 - i] = temp1;
        s[length - 2 - i] = temp2;
        s[length - 3 - i] = temp3;
        s[length - 4 - i] = temp4;
        s[length - 5 - i] = temp5;
        s[length - 6 - i] = temp6;
    }
}
int main() {
    char str[500];
    fgets(str,500,stdin);
    double secs;
    printf("Original: %s\n", str);
    LARGE_INTEGER t_ini, t_fin;
    clock_t ini,fin;
    srand(time(NULL));

    //ini = clock();
    QueryPerformanceCounter(&t_ini);

    for (int i = 0; i < 1000001; i++)
    {
        invertir_optimizada_3(str);
    }
    

    //fin = clock();
    
    printf("Invertido: %s\n", str);
    QueryPerformanceCounter(&t_fin);
    secs=perfomanceCounter_diff(&t_fin, &t_ini);
    printf("\nMilisegundos: %.16g", secs*1000.0);

    //printf("\n%d",fin-ini);
    return 0;
}