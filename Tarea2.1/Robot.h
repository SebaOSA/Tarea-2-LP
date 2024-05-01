#ifndef ROBOT_H
#define ROBOT_H

#include "Manufactura.h"


typedef struct robot
{
    int *inventario;
    char tiene_inventario;
    int direccion;
} robot;



void step_robot(void *estructura, int x);
void interactuar_manufactura(manufactura *manf, robot *rob);
void interactuar_io(io *io, robot *rob);


#endif