#include <stdio.h>
#include <time.h>


/*
Prototipos de las funciones utilizadas.
Se muestra tambien fibonacci_it con el que realizamos test para compararlo con fibonacci_opt.
Lo dejamos comentado debido a que fue un test adicional que realizamos.
*/

//Funcion entregada por el enunciado
long long int fibonacci(long long int *n);
//Fibonacci iterativo sin otras optimizaciones
long long int fibonacci_it(long long int *n);
//Fibonacci iterativo con optimizaciones.
long long int fibonacci_opt(long long int *n);



int main(){
    long long int num;
    long long int resultado;
    long long int numero_test;
    printf("Ingrese el numero de fibonacci que quiere calcular:");
    scanf("%lld", &num);
    printf("Ingrese el total de test que quiere hacer:");
    scanf("%lld", &numero_test);

    clock_t inicial_opt, final_opt, inicial_or, final_or, inicial_it, final_it;
    clock_t tiempo_opt = 0, tiempo_or = 0, tiempo_it = 0;
    long long int real, iterativo;

    for (int i = 0; i < numero_test; i++){
        inicial_opt = clock();
        resultado = fibonacci_opt(&num);
        final_opt = clock();

        inicial_or = clock();
        real = fibonacci(&num);
        final_or = clock();

        //inicial_it = clock();
        //iterativo = fibonacci_it(&num);
        //final_it = clock();

        tiempo_opt += final_opt - inicial_opt;
        tiempo_or += final_or - inicial_or;
        //tiempo_it += final_it - inicial_it;

    }
    printf("Optimizado %lld y toma en promedio %f ciclos\n", resultado,(float)tiempo_opt / (float)numero_test);
    printf("El algoritmo original entrega %lld y %f ciclos\n", real, (float)tiempo_or / (float)numero_test);
    //printf("El algoritmo iterativo entrega %lld y %f ciclos\n", iterativo, (float)tiempo_it / (float)numero_test);

    return 0;
}

long long int fibonacci(long long int *n) {
    
    if(*n==1) return 0;
    if(*n==2) return 1;
    long long int m=*n-1;
    long long int p=*n-2;
    return fibonacci(&m)+fibonacci(&p);
}


long long int fibonacci_opt(long long int *n){
    if (*n == 1) return 0;
    if (*n == 2) return 1;
    if (*n == 3) return 1;

    long long int a = 0, b = 1, c = 1, d = 2;
    long long int i;
    long long int limit = *n - 3;
    for (i = 4; i < limit; i += 4){
        a = c + d;
        b = d + a;
        c = a + b;
        d = b + c;
    }
    for(; i < *n; i++){
        limit = d;
        d = d + c;
        c = limit;
    }
    
    return d;
}

long long int fibonacci_it(long long int *n){
    long long int a = 1;
    long long int b = 0;
    long long int aux;

    int i;

    for (i = 1; i < *n; i++){
        aux = a;
        a = a + b;
        b = aux;
    }


    return b;
}

