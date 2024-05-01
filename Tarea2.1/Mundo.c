#include "Io.h"
#include "Manufactura.h"
#include "Robot.h"
#include "Mundo.h"
#include <stdio.h>
#include <stdlib.h>

int Tamanio_mundo;

void crear_mundo(int tamanio){
    Tamanio_mundo = tamanio;
    mundo = (void **)malloc(tamanio * sizeof(void *));
    // Ejemplo de uso
    for (int i = 0; i < tamanio; i++) {
        mundo[i] = (casilla *)malloc(sizeof(casilla));
        casilla *actual = (casilla *)mundo[i];
        // Asignación de valores para cada casilla
        if (i == 0) {
            // Casilla de entrada
            actual->tipo_estructura = 'I';
            actual->estructura = malloc(sizeof(io));
            io *input = (io *)actual->estructura;
            input->entrada_o_salida = 'I';
            // No se asigna ninguna función step a la casilla de entrada
        } 
        else if (i == tamanio - 1) {
            // Casilla de salida
            actual->tipo_estructura = 'I';
            actual->estructura = malloc(sizeof(io));
            io *output = (io *)actual->estructura;
            output->entrada_o_salida = 'O';
            // No se asigna ninguna función step a la casilla de salida
        }
    }

}
void mostrar_mundo(){
    printf("------------------------\n");
    printf("[");
    for(int i = 0; i < Tamanio_mundo; i++){
        casilla* aux = (casilla*)mundo[i];
        if (aux->tipo_estructura == 'M' && i!= 0 && i!= Tamanio_mundo-1){
            printf("M");
            manufactura* manf = aux->estructura;
            if(manf->operar != NULL){
                if(manf->operar == &operar_suma){
                    printf("+");
                }
                else if(manf->operar == &operar_resta){
                    printf("-");
                }
                else if(manf->operar == &operar_multiplicacion){
                    printf("*");
                }
                else if(manf->operar == &operar_division){
                    printf("/");
                }
            }
            if (i > 0){
            printf(" | ");
            }
        }

        else if (aux->tipo_estructura== 'R' && i!= 0 && i!= Tamanio_mundo-1){
            printf("R");
            robot* robo = aux->estructura;
            if(robo->direccion == 0){
                printf("<");
            }
            else if (robo->direccion== 1){
                printf(">");
            }
            if (i > 0){
            printf(" | ");
            }
        }

        else if (aux->tipo_estructura == 'I'){
            io* IO;
            IO = aux->estructura;
            if(IO->entrada_o_salida =='I'){
                printf("I ");
                printf("|");
            }
            else if (IO->entrada_o_salida == 'O'){
                printf(" O");
            }
        }
        else{
            printf(" ");
            printf("|");
        }
    
    }
    printf("]\n");
    printf("--------------------------\n");
}
//poner condiciones de que si las casillas corresponden a un struct poner el tipo_estructura en pantalla

void borrar_mundo(){
    for (int i = 0; i < Tamanio_mundo; i++) {
        free(((casilla *)mundo[i])->estructura);
        free(mundo[i]);
    }
    free(mundo);
}
void simular(int ticks){
    for(int i=0;i<ticks;i++){
        int flag = 0;
        for(int j=0;j<Tamanio_mundo;j++){
            casilla* aux = (casilla*)mundo[j];
            if(aux == NULL) continue;
            if(aux->tipo_estructura =='M'){
                manufactura* manf = aux->estructura;
                if(manf == NULL) continue;
                //step_craft(manf,j);
            }
            else if(aux->tipo_estructura =='R' && flag == 0){
                robot* robo = aux->estructura;
                if(robo == NULL) continue;
                step_robot(robo,j);
                flag = 1;
            }
            else if(aux->tipo_estructura =='I'){
                io* IO = aux->estructura;
                if(IO == NULL) continue;
                if(IO->entrada_o_salida == 'I'){
                }
                else if(IO->entrada_o_salida == 'O'){
 
                }
            }
        }
    }

}