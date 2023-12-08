#include <stdio.h>
#include <string.h>
#include <time.h>

void invertir(char *s) {
    int i;

    for (i = 0; i < strlen(s)/2; i++) {
        char temp1 = s[i];
        s[i] = s[strlen(s) - 1 - i];
        s[strlen(s) - 1 - i] = temp1;

    }
}

void invertir_optimizado_1(char *s) {
    int length = strlen(s);
    int i;
    char temp1;
    char temp2;

    for (i = 0; i < length/2; i+=2) {
        temp1 = s[i];
        temp2 = s[i+1];
  
        s[i] = s[length - 1 - i];
        s[i+1] = s[length - 2 - i];

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

    for (i = 0; i < length/2; i+=3) {
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

    for (i = 0; i < length/2; i+=4) {
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
    clock_t ini1,fin1,ini2,fin2,ini3,fin3,ini4,fin4;

    ini1 = clock();

    for (int i = 0; i < 1000001; i++)
    {
        invertir(str);
    }
    
    fin1 = clock();
    //printf("\nInvertido: %s\n", str);
    printf("\nMilisegundos sin optimizar: %d", fin1-ini1);

    ini2 = clock();

    for (int i = 0; i < 1000001; i++)
    {
        invertir_optimizado_1(str);
    }
    
    fin2 = clock();
    //printf("\nInvertido: %s\n", str);
    printf("\nMilisegundos optimizado1: %d",  fin2-ini2);
    ini3 = clock();

    for (int i = 0; i < 1000001; i++)
    {
        invertir_optimizado_2(str);
    }
    
    fin3 = clock();
    //printf("\nInvertido: %s\n", str);
    printf("\nMilisegundos optimizado2: %d",  fin3-ini3);

    ini4 = clock();

    for (int i = 0; i < 1000001; i++)
    {
        invertir_optimizado_3(str);
    }
    
    fin4 = clock();

    //printf("\nInvertido: %s\n", str);
    printf("\nMilisegundos optimizado3: %d",  fin4-ini4);
    
    return 0;
}