#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Io.h"
#include "Manufactura.h"
#include "Mundo.h"
#include "Robot.h"

extern int Tamanio_mundo;

void step_robot(void *estructura, int x){

    robot* new_robot = (robot*)estructura;
    casilla* aux = (casilla*)mundo[x];
    
    if (new_robot->direccion == 1 && x + 1 < Tamanio_mundo) {
        casilla* next_cell = (casilla*)mundo[x+1];
        
        if (next_cell->tipo_estructura == 'M') {
            manufactura* manf = (manufactura*)next_cell->estructura;
            interactuar_manufactura(manf , new_robot);

        } else if (next_cell->tipo_estructura == 'I') {
            io* IO = (io*)next_cell->estructura;
            interactuar_io(IO , new_robot);    

        } else if (aux->tipo_estructura == 'R' && next_cell->estructura == NULL) {
            next_cell->estructura = aux->estructura;
            next_cell->tipo_estructura = 'R';
            robot* robo = next_cell->estructura;
            robo->direccion = 1;
            free(aux->estructura);
            aux->estructura = NULL;
            aux->tipo_estructura = ' ';
            next_cell->step = &step_robot;
        }

    }

    else if (new_robot->direccion == 0 && x - 1 >= 0) {
        casilla* prev_cell = (casilla*)mundo[x-1];

        if (prev_cell->tipo_estructura == 'M') {
            manufactura* manf = (manufactura*)prev_cell->estructura;
            interactuar_manufactura(manf , new_robot);

        } else if (prev_cell->tipo_estructura == 'I') {
            io* IO = (io*)prev_cell->estructura;
            interactuar_io(IO , new_robot);

        } else if (prev_cell != NULL && prev_cell->tipo_estructura == ' ') {
            mundo[x - 1] = mundo[x]; // Mover el robot a la casilla anterior
            mundo[x] = NULL;
            prev_cell->step = &step_robot; // Actualizar la función que se ejecuta en la casilla anterior

            // Actualizar la casilla original
            aux->estructura = NULL;
            aux->tipo_estructura = ' ';
            aux->step = NULL;
        }

    }

}

void interactuar_manufactura(manufactura *manf, robot *rob){
    //Cuando se encuentre con una manufactura sea en la izquierda o derecha cambiar el sentido en cada caso
}
void interactuar_io(io *io, robot *rob){
    //Cuando se encuentre con una salida o entrada y cambiar el sentido en cada caso
}
