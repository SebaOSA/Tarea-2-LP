#ifndef MUNDO_H
#define MUNDO_H
#include "Io.h"
#include "Manufactura.h"
#include "Robot.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct casilla
{
    char tipo_estructura;
    void *estructura;
    void (*step)(void *estructura, int x); //Este sirve para castearlo con los Step_craft o Step_robot cuando se haga la simulacion
} casilla;

extern void **mundo;


void crear_mundo(int tamanio);
void mostrar_mundo();
void borrar_mundo();
void simular(int ticks);

#endif