#include "Io.h"
#include "Manufactura.h"
#include "Robot.h"
#include "Mundo.h"
#include <stdio.h>
#include <stdlib.h>

void step_craft(void *estructura, int x){
    manufactura* new_manufacter = (manufactura*)estructura;
    ((casilla*)mundo[x])->tipo_estructura = 'M';
    mundo[x] = new_manufacter;
}
//Falta ponerle condicionales

int *operar_suma(int *a, int *b){
    int *suma = malloc(sizeof(int));
    *suma = *a + *b;
    return suma; 
    //Acordarse que despues en el main hay que liberar la memoria cuando se llame la funcion,
    //ej: int *resultado = operar_suma(&x, &y); free(resultado);
}
int *operar_resta(int *a, int *b){
    int *resta = malloc(sizeof(int));
    *resta = *a + *b;
    return resta;
    //Acordarse que despues en el main hay que liberar la memoria cuando se llame la funcion,
    //ej: int *resultado = operar_resta(&x, &y); free(resultado);
}
int *operar_division(int *a, int *b){
    int *div = malloc(sizeof(int));
    *div = *a / *b;
    return div; 
    //Acordarse que despues en el main hay que liberar la memoria cuando se llame la funcion,
    //ej: int *resultado = operar_division(&x, &y); free(resultado);
}
int *operar_multiplicacion(int *a, int *b){
    int *multi = malloc(sizeof(int));
    *multi = *a * *b;
    return multi; 
    //Acordarse que despues en el main hay que liberar la memoria cuando se llame la funcion,
    //ej: int *resultado = operar_suma(&x, &y); free(resultado);
}
