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
    int i;
    char temp1;

    for (i = 0; i < strlen(s) - 1; i++) {
        temp1 = s[i];
        s[i] = s[strlen(s) - 1 - i];
        s[strlen(s) - 1 - i] = temp1;

    }
}

void invertir_optimizado_1(char *s) {
    int length = strlen(s);
    int i;
    char temp1;
    char temp2;

    for (i = 0; i < length - 2; i+=2) {
        temp1 = s[i];
        temp2 = s[i+1];
  
        s[i] = s[length - 1 - i];
        s[i+1] = s[length - 1 - i];

        s[length - 1 - i] = temp1;
        s[length - 2 - i] = temp2;

    }
}

void invertir_optimizado_2(char *s) {
    int length = strlen(s);
    int i;
    char temp1;
    char temp2;
    char temp3;

    for (i = 0; i < length - 3; i+=3) {
        temp1 = s[i];
        temp2 = s[i+1];
        temp3 = s[i+2];
  
        s[i] = s[length - 1 - i];
        s[i+1] = s[length - 2 - i];
        s[i+2] = s[length - 3 - i];

        s[length - 1 - i] = temp1;
        s[length - 2 - i] = temp2;
        s[length - 3 - i] = temp3;

    }
}


void invertir_optimizado_3(char *s) {
    int length = strlen(s);
    int i;
    char temp1;
    char temp2;
    char temp3;
    char temp4;

    for (i = 0; i < length - 4; i+=4) {
        temp1 = s[i];
        temp2 = s[i+1];
        temp3 = s[i+2];
        temp4 = s[i+3];
  
        s[i] = s[length - 1 - i];
        s[i+1] = s[length - 2 - i];
        s[i+2] = s[length - 3 - i];
        s[i+3] = s[length - 4 - i];

        s[length - 1 - i] = temp1;
        s[length - 2 - i] = temp2;
        s[length - 3 - i] = temp3;
        s[length - 4 - i] = temp4;

    }
}



int main() {
    char str[500];
    fgets(str,500,stdin);
    double secs1, secs2, secs3, secs4;
    //printf("Original: %s\n", str);
    LARGE_INTEGER t_ini, t_fin;
    clock_t ini,fin;
    srand(time(NULL));

    //ini = clock();
    QueryPerformanceCounter(&t_ini);

    for (int i = 0; i < 1000001; i++)
    {
        invertir(str);
    }
    
    //fin = clock();
    //printf("Invertido: %s\n", str);
    QueryPerformanceCounter(&t_fin);
    secs1=perfomanceCounter_diff(&t_fin, &t_ini);
    printf("\nMilisegundos sin optimizar: %.16g", secs1*1000.0);

        //ini = clock();
    QueryPerformanceCounter(&t_ini);

    for (int i = 0; i < 1000001; i++)
    {
        invertir_optimizado_1(str);
    }
    
    //fin = clock();
    //printf("Invertido: %s\n", str);
    QueryPerformanceCounter(&t_fin);
    secs2 = perfomanceCounter_diff(&t_fin, &t_ini);
    printf("\nMilisegundos optimizado1: %.16g", secs2*1000.0);

            //ini = clock();
    QueryPerformanceCounter(&t_ini);

    for (int i = 0; i < 1000001; i++)
    {
        invertir_optimizado_2(str);
    }
    
    //fin = clock();
    //printf("Invertido: %s\n", str);
    QueryPerformanceCounter(&t_fin);
    secs3 = perfomanceCounter_diff(&t_fin, &t_ini);
    printf("\nMilisegundos optimizado2: %.16g", secs3*1000.0);
            //ini = clock();
    QueryPerformanceCounter(&t_ini);

    for (int i = 0; i < 1000001; i++)
    {
        invertir_optimizado_3(str);
    }
    
    //fin = clock();
    //printf("Invertido: %s\n", str);
    QueryPerformanceCounter(&t_fin);
    secs4 = perfomanceCounter_diff(&t_fin, &t_ini);
    printf("\nMilisegundos optimizado3: %.16g", secs4*1000.0);

    //printf("\n%d",fin-ini);
    return 0;
}