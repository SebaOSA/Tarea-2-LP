#include "Io.h"
#include "Manufactura.h"
#include "Robot.h"
#include "Mundo.h"
#include <stdio.h>
#include <stdlib.h>

void **mundo;
extern int Tamanio_mundo;

void asignar_estructura(casilla *c, char tipo, void *estructura) {
    c->tipo_estructura = tipo;
    c->estructura = estructura;

    // Asignar la función step correspondiente según el tipo de estructura
    if (tipo == 'R') {
        c->step = &step_robot;
    } else if (tipo == 'M') {
        c->step = &step_craft;
    } else {
        // Tipo de estructura no válido
        c->step = NULL;
    }
}

void construir()
{
int pos;
int cons;
int dir;
int ope;
int flag2 = 0;

printf("Ingrese Posicion : ");
scanf("%d", &pos);
if(pos == 1 || pos == Tamanio_mundo){
        while(flag2 == 0){
            printf("No se puede construir en la posicion debido que se encuentra una entrada o una salida, elija nuevamente: ");
            scanf("%d", &pos);
            if(pos != 1){
                if(pos != Tamanio_mundo){
                    flag2 = 1;
                }
            }
        }
        flag2 = 0;
    }


casilla* aux = (casilla *)mundo[pos-1];

printf("Elige una opcion para construir\n");
printf("1.- Robot\n");
printf("2.- Manufactura\n");
scanf("%d", &cons);

if(cons == 1){
    robot* robo = malloc(sizeof(robot));
    printf("Direccion Inicial:\n");
    printf("0.- Izquierda\n");
    printf("1.- Derecha\n");
    scanf("%d", &dir);
    if(dir == 0){
        robo->direccion = 0;
    }
    else if (dir == 1){
        robo->direccion = 1;
    }
    asignar_estructura(aux, 'R', robo);
}
else if(cons == 2){
    manufactura* manf = malloc(sizeof(manufactura));
    printf("Operacion:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    scanf("%d", &ope);
    if(ope == 1){
        manf->operar = &operar_suma;
    }
    else if (ope == 2){
        manf->operar = &operar_resta;
    }
    else if(ope == 3){
        manf->operar = &operar_multiplicacion;
    }
    else if (ope == 4){
        manf->operar = &operar_division;
    }
    asignar_estructura(aux, 'M', manf);
}

}

void destruir()
{
int pos;
int flag3 = 0;
printf("Ingrese la Casilla a destruir: ");
scanf("%d",&pos);
if(pos == 1 || pos == Tamanio_mundo){
        while(flag3 == 0){
            printf("No se puede destruir una entrada/salida, elija nuevamente: ");
            scanf("%d", &pos);
            if(pos != 1){
                if(pos != Tamanio_mundo){
                    flag3 = 1;
                }
            }
        }
        flag3 = 0;
    }
casilla* aux = (casilla *)mundo[pos-1];
    if (aux != NULL) {
        // Liberar la memoria asignada a la estructura contenida en la casilla
        free(aux->estructura);
        // Asignar NULL al puntero estructura para indicar que está vacío
        aux->estructura = NULL;
        aux->tipo_estructura = ' ';
    }
}

void informacion()
{
int pos;
printf("VER INFORMACION EXTRA:\n");
printf("Ingrese Cordenada: ");
scanf("%d",&pos);
casilla* aux = (casilla *)mundo[pos-1];

if(aux->tipo_estructura == 'R'){
    robot* robo = aux->estructura;
    printf("Robot >>\n");
    printf("Direccion actual: %d\n", robo->direccion);

}
else if (aux->tipo_estructura == 'M'){
    printf("Manufactura >>\n");
    manufactura* manf = aux->estructura;
    printf("Operacion: ");
    if(manf->operar == &operar_suma){
        printf("+\n");
    }
    else if (manf->operar == &operar_resta){
        printf("-\n");
    }
    else if(manf->operar == &operar_multiplicacion){
        printf("*\n");
    }
    else if (manf->operar == &operar_division){
        printf("/\n");
    }
}
else if (aux->tipo_estructura == 'I'){
    io* IO = aux->estructura;
    if(IO->entrada_o_salida == 'I'){
        printf("IO >>\n");
        printf("Tipo: Entrada\n");
    }
    else if(IO->entrada_o_salida == 'O'){
        printf("IO >>\n");
        printf("Tipo: Salida\n");
    }
} 

}

void salir(int *flag)
{
*flag = 1;
}

void Eleccion(int eleccion,int *flag){
    if (eleccion == 1){
        construir();
    }
    else if(eleccion == 2) {
        destruir();
    }
    else if (eleccion == 3){
        int ticks;
        printf("Tick : ");
        scanf("%d",&ticks);
        simular(ticks);
    }
    else if(eleccion == 4){
        informacion();
    }
    else if(eleccion== 5){
        salir(flag);
    }
}

int main()
{
    int tamanio;
    int eleccion;
    int flag = 0;

    printf("Factory of Numbers\n");
    printf("Ingrese largo: ");
    scanf("%d", &tamanio);
    if(tamanio < 5){
        while(flag == 0){
            printf("Tamaño incorrecto, ingrese uno mayor o igual a 5: ");
            scanf("%d", &tamanio);
            if(tamanio >= 5){
                flag = 1;
            }
        }
        flag = 0;
    }
    crear_mundo(tamanio);
    // Lo siguiente ira todo dentro de un while que contendra una flag para que
    // cuando se se elija salir se cambie la flag y termine el while
    mostrar_mundo();
    printf("MENU PRINCIPAL\n");
    printf("1.- Construir 2.- Destruir\n");
    printf("3.- Simular 4.- Informacion 5.- Salir\n");
    printf("Ingresa una Accion : ");
    scanf("%d", &eleccion);
    Eleccion(eleccion,&flag);
    while(flag == 0){
        mostrar_mundo();
        printf("MENU PRINCIPAL\n");
        printf("1.- Construir 2.- Destruir\n");
        printf("3.- Simular 4.- Informacion 5.- Salir\n");
        printf("Ingresa una Accion : ");
        scanf("%d", &eleccion);
        Eleccion(eleccion,&flag);
    }







    borrar_mundo();

    return 0;
}
