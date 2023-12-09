#include <stdio.h>
#include <string.h>
#include <time.h>

//Funcion inicial que invierte una string
void invertir(char *s) {
    int i;

    for (i = 0; i < strlen(s)/2; i++) {
        char temp1 = s[i];
        s[i] = s[strlen(s) - 1 - i];
        s[strlen(s) - 1 - i] = temp1;

    }
}

//Version optimizada numero 1 con loop unrolling con 1 via
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

//Version optimizada numero 2 con loop unrolling con 2 vias
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

//Version optimizada numero 3 con loop unrolling con 3 vias
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
    //Se inicia el primer reloj
    ini1 = clock();

//Se ejecuta multiples veces la funcion para que el numero de ciclos sea significativo
    for (int i = 0; i < 1000001; i++)
    {
        invertir(str);
    }
    
    //Se finaliza el primer reloj
    fin1 = clock();
    printf("\nInvertido: %s\n", str);
    printf("\nCiclos sin optimizar: %ld", fin1-ini1);

    //Se inicia el segundo reloj
    ini2 = clock();

    //Se ejecuta multiples veces la funcion para que el numero de ciclos sea significativo
    for (int i = 0; i < 1000001; i++)
    {
        invertir_optimizado_1(str);
    }
    
    //Se finaliza el segundo reloj
    fin2 = clock();
    printf("\nInvertido: %s\n", str);
    printf("\nCiclos optimizado1: %ld",  fin2-ini2);

    //Se inicia el tercer reloj
    ini3 = clock();

    //Se ejecuta multiples veces la funcion para que el numero de ciclos sea significativo
    for (int i = 0; i < 1000001; i++)
    {
        invertir_optimizado_2(str);
    }
    
    //Se finaliza el tercer reloj
    fin3 = clock();
    printf("\nInvertido: %s\n", str);
    printf("\nCiclos optimizado2: %ld",  fin3-ini3);

//Se inicia el cuarto reloj
    ini4 = clock();

//Se ejecuta multiples veces la funcion para que el numero de ciclos sea significativo
    for (int i = 0; i < 1000001; i++)
    {
        invertir_optimizado_3(str);
    }

    //Se finaliza el cuarto reloj
    fin4 = clock();

    printf("\nInvertido: %s\n", str);
    printf("\nCiclos optimizado3: %ld\n",  fin4-ini4);
    
    return 0;
}
