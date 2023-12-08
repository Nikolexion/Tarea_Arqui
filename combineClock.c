#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Se definen las variables globales las cuales se pueden modificar para obtener distintos resultados. Para
// calcular la sumatoria, utilice IDENT 0 y OP +, para calcular el productorio, IDENT 1 y OP *. Para cambiar
// el tipo de dato de retorno, cambie la tercera línea typedef entre long long int o double según se desee.

#define IDENT 0
#define OP +
typedef double data_t;

// Las siguientes funciones son de utilidad para el trabajo con el vector. Se han utilizado las entregadas en
// los códigos vistos en clase según dice el enunciado.

typedef struct {
    long int len;
    data_t *data;
} vec_rec, *vec_ptr;

/* Create vector of specified length */
 vec_ptr new_vec(int len) {
    /* allocate header structure */
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    if (!result) return NULL; /* Couldn’t allocate storage */
    result->len = len;
    /* Allocate array */
    if (len > 0) {
        data_t *data = (data_t *)calloc(len, sizeof(data_t));
        if (!data) {
            free((void *) result);
            return NULL; /* Couldn’t allocate storage */
        }
        result->data = data;
    } else result->data = NULL;
    return result;
}

data_t *get_vec_start(vec_ptr v){
    return v->data;
}

/*
 * Retrieve vector element and store at dest.
 * Return 0 (out of bounds) or 1 (successful)
*/
int get_vec_element(vec_ptr v, int index, data_t *dest) {
    if (index < 0 || index >= v->len) return 0;
    *dest = v->data[index];
    return 1;
}

/*
 * Put vector element and store at vector.
 * Return 0 (out of bounds) or 1 (successful)
*/

int put_vec_element(vec_ptr v, int index, data_t data) {
    if (index < 0 || index >= v->len) return 0;
    v->data[index] = data;
    return 1;
}

/* Return length of vector */
int vec_length(vec_ptr v) {
    return v->len;
}

// Combine1 no optimizado
void combine1(vec_ptr v, data_t *dest) {
    int i;
    *dest = IDENT;
    for (i = 0; i < vec_length(v); i++) {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OP val;
    }
}

// Combine5 usando loop unrolling con 4 vias
void combine5(vec_ptr v, data_t *dest) {
    long long int i;
    long long int length = vec_length(v);
    long long int limit = length - 3;
    data_t *data = get_vec_start(v);
    data_t resultado = IDENT;

    for (i = 0; i < limit; i += 4) {
        resultado = (((resultado OP data[i]) OP data[i + 1]) OP data[i + 2]) OP data[i + 3];
    }

    for (; i < length; i++) {
        resultado = resultado OP data[i];
    }

    *dest = resultado;
}

// Combine6 usando loop unrolling con paralelismo y 4-vias
void combine6(vec_ptr v, data_t *dest) {
    long long int i;
    long long int length = vec_length(v);
    long long int limit = length - 3;
    data_t *data = get_vec_start(v);
    data_t resultado1 = IDENT;
    data_t resultado2 = IDENT;
    data_t resultado3 = IDENT;
    data_t resultado4 = IDENT;

    for (i = 0; i < limit; i += 4) {
        resultado1= resultado1 OP data[i];
        resultado2= resultado2 OP data[i + 1];
        resultado3= resultado3 OP data[i + 2];
        resultado4= resultado4 OP data[i + 3];
    }

    for (; i < length; i++) {
        resultado1 = resultado1 OP data[i];
    }

    *dest = resultado1 OP resultado2 OP resultado3 OP resultado4;
}

int main() {
    clock_t secs1, secs5, secs6, sum_secs1 = 0.0, sum_secs5 = 0.0, sum_secs6 = 0.0;
    clock_t start1, end1, start5, end5, start6, end6;
    int hora = time(NULL);
    vec_ptr vector;
    data_t aux;
    int i, n, m, k;
    data_t res;

    printf("\n Ingrese cantidad de elementos del arreglo:");
    scanf("%lld", &n);
    vector = new_vec(n);
    srand(hora);

    if(vector != NULL) {
        for(i = 0; i < vec_length(vector); i++) {
            aux = rand()%10;
            put_vec_element(vector,i,(data_t)aux);
        }
        
        printf("\n Ingrese cantidad pruebas con %d elementos:",n);
        scanf("%d", &m);
        // Hacemos un for para calcular un promedio de ciclos dadas las m pruebas pedidas anteriormente
        for(k = 0; k < m; k++) {

            start1 = clock();
            combine1(vector, &res);
            end1 = clock();
            secs1 = end1 - start1;
            sum_secs1 = sum_secs1 + secs1;
            //printf("\nResultado=%lld\nEjecucion de combine1 desde %lld hasta %lld\nCiclos transcurridos:%lld", res, start1, end1,/*CLOCKS_PER_SEC*/secs1);
            
            start5 = clock();
            combine5(vector, &res);
            end5 = clock();
            secs5 = end5 - start5;
            sum_secs5 = sum_secs5 + secs5;
            //printf("\nResultado=%lld\nEjecucion de combine5 desde %lld hasta %lld\nCiclos transcurridos:%lld", res, start5, end5,/*CLOCKS_PER_SEC*/secs5);
            
            start6 = clock();      
            combine6(vector, &res);
            end6 = clock();
            secs6 = end6 - start6;
            sum_secs6 = sum_secs6 + secs6;
            //printf("\nResultado=%lld\nEjecucion de combine6 desde %ld hasta %ld\nCiclos transcurridos:%ld", res, start6, end6,/*CLOCKS_PER_SEC*/secs6);
        }
        printf("\nResultado=%lld\nEjecucion de combine1 desde %lld hasta %lld\nCiclos transcurridos:%f", res, start1, end1,/*CLOCKS_PER_SEC*/(float)sum_secs1/m);
        printf("\nResultado=%lld\nEjecucion de combine5 desde %lld hasta %lld\nCiclos transcurridos:%f", res, start5, end5,/*CLOCKS_PER_SEC*/(float)sum_secs5/m);
        printf("\nResultado=%lld\nEjecucion de combine6 desde %lld hasta %lld\nCiclos transcurridos:%f", res, start6, end6,/*CLOCKS_PER_SEC*/(float)sum_secs6/m);
     } else
        printf("\n\nNo se pudo crear el arreglo");

    return 0;
}
