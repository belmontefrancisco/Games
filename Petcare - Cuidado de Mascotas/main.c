#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PAUSA system("pause")
#define LIMPIEZA system("cls")
#define MAX_LETRAS 15

//ESTRUCTURA
typedef struct{
    int especie;
    char nombre[MAX_LETRAS];
    char sexo;
    int salud;
    int hambre;
    int sed;
    int diversion;
    int animo;
} stMascota;

//PROTOTIPOS
void gameManager();
void inicio();
void instrucciones();
void juego(stMascota mascota[]);
void salir();

void crearMascota(stMascota mascota[]);
void asignarNecesidades(stMascota mascota[]);
int restarTiempo(int tiempoVictoria);
void restarNecesidades(stMascota mascoota[]);
void controlDeMinimos(stMascota mascota[]);
int subirSalud(stMascota mascota[]);
int subirHambre(stMascota mascota[]);
int subirSed(stMascota mascota[]);
int subirDiversion(stMascota mascota[]);
int subirAnimo(stMascota mascota[]);
void imprimirAnimal(stMascota mascota[]);

void victoria();
void gameOver();

//MAIN
int main()
{
    srand(time(NULL));

    system("color 80");

    gameManager();

    return 0;
}

//FUNCIONES
void gameManager(){
    //VARIABLES
    stMascota mascota[0];

    inicio();
    crearMascota(mascota);
    juego(mascota);
}

void inicio(){
    int menu=0;

    printf("\t PET CARE - CUIDADO DE MASCOTAS C\n");
    printf("\t CRIA, ALIMENTA Y PROTEGE A TU MASCOTA \n\n");
    printf("1. Comenzar \n 2.Instrucciones \n 3. Salir \n");
    fflush(stdin);
    scanf("%i", &menu);

    printf("\t\n Presione el numero correspondiente para usar el menu \n");

    LIMPIEZA;

    switch(menu){

    case 1:
        break;
    break;

    case 2:
        instrucciones();
    break;

    case 3:
        salir();
    break;

    default:
        printf("HA PRESIONADO TECLA INVALIDA. \n");
        fflush(stdin);
        inicio();
    break;

    }
}

void instrucciones(){
    printf("\t\n En este juego deberas crear y cuidar a tu mascota virtual. \n La mascota virtual tendra 5 estados: \n SALUD \n HAMBRE \n SED \n DIVERSION \n ANIMO \n\n Deberas mantener esos cinco estados en optimas condiciones durante el tiempo de juego, o te quitaran \n a tu mascota por descuidarla.\n\n");
    printf("\t\n GANAR: Mantener las necesidades de tu mascota por encima de cero en el tiempo estipulado.\n\n");
    printf("\t\n PERDER: Perderas si se da alguna de las siguientes condiciones:\n 1.Salud llega a cero. \n 2. Hambre y sed llegan a 0 ambas.\n 3. Diversion y animo llegan a 0 ambos.");
    PAUSA;
    LIMPIEZA;

    inicio();
}

void crearMascota(stMascota mascota[]){

        printf("Selecciona que tipo de mascota quieres:\n");

        int decisionEspecie=0;
        printf("Elige el tipo de mascota que quieres tener: \n");
        printf("\t\n 1. Perro \n Esta especie requiere mucho acompanamiento, pero tiene mucha salud. \t\n\n 2. Gato \n Es una especie muy independiente, que se entretiene y mantiene buen animo sola. \t\n\n 3. Conejo \n Es un animal fragil, pero que no requiere mucha alimentacion.\n");
        fflush(stdin);
        scanf("%i", &decisionEspecie);

        switch(decisionEspecie){

        case 1:
            mascota[0].especie=1;
            printf("Has elegido un perro. \n");
        break;

        case 2:
            mascota[0].especie=2;
            printf("Has elegido un gato. \n");
            printf("Especie: %i \n", mascota[0].especie);
        break;

        case 3:
            mascota[0].especie=3;
            printf("Has elegido un conejo. \n");
            printf("Especie: %i \n", mascota[0].especie);
        break;

        default:
            printf("HA PRESIONADO TECLA INVALIDA. \n");
            fflush(stdin);
            inicio();
        break;

        }

        LIMPIEZA;

        printf("Ingrese el nombre de tu mascota:\n");
        fflush(stdin);
        gets(mascota[0].nombre);

        LIMPIEZA;

        printf("Ingresa sexo de la mascota M/F :\n");
        fflush(stdin);
        scanf("%c", &mascota[0].sexo);
        mascota[0].sexo=toupper(mascota[0].sexo);

        LIMPIEZA;
    }

void juego(stMascota mascota[]){
    asignarNecesidades(mascota);

    int activo=1;
    int tiempoVictoria=120;
    int actualizacionNecesidades=0;
    int decision=0;

    while(activo==1){
        imprimirAnimal(mascota);

        tiempoVictoria=restarTiempo(tiempoVictoria);


        printf("--------------------------------- ");   printf("------------------------------- \n");
        printf("Nombre: %s ", mascota[0].nombre);       printf("\t\t\t|Salud: %i PUNTOS \t\t|\n", mascota[0].salud);
        printf("Sexo: %c ", mascota[0].sexo);           printf("\t\t\t|Hambre: %i PUNTOS \t\t|\n", mascota[0].hambre);
        printf("Especie: %i ", mascota[0].especie);     printf("\t\t\t|Sed: %i PUNTOS \t\t|\n", mascota[0].sed);
                                                        printf("\t\t\t\t|Diversion: %i PUNTOS \t\t|\n", mascota[0].diversion);
                                                        printf("\t\t\t\t|Animo: %i PUNTOS \t\t|\n", mascota[0].animo);

        printf("--------------------------------- ");   printf("-------------------------------\n ");
        printf("| Que accion quieres tomar? \t| \n");
        printf("| 1.Dar comida. \t\t| \n");
        printf("| 2.Poner agua en el tazon. \t| \n");
        printf("| 3.Jugar. \t\t\t| \n");
        printf("| 4.Acariciar. \t\t\t\| \n");
        printf("| 5.Dar medicacion. \t\t|\n");
        printf("--------------------------------- \n");
        fflush(stdin);
        scanf("%i", &decision);

        if(decision==1){
            mascota[0].hambre=mascota[0].hambre+subirHambre(mascota);
        }
        else if(decision==2){
            mascota[0].sed=mascota[0].sed+subirSed(mascota);
        }
        else if(decision==3){
            mascota[0].diversion=mascota[0].diversion+subirDiversion(mascota);
        }
        else if(decision==4){
            mascota[0].animo=mascota[0].animo+subirAnimo(mascota);
        }
        else if(decision==5){
            mascota[0].salud=mascota[0].salud+subirSalud(mascota);
        }
        else{
            printf("Has ingresado un comando incorrecto.\n");
        }

    restarNecesidades(mascota);

    controlDeMinimos(mascota);


    if((mascota[0].salud<=0) || mascota[0].hambre<=0 && mascota[0].sed<=0 || mascota[0].diversion<=0 && mascota[0].animo<=0){
            activo=0;
            gameOver();
        }

    if(tiempoVictoria<=0){
            activo=0;
            victoria();
        }

    PAUSA;
    LIMPIEZA;

    }
}

int subirSalud(stMascota mascota[]){
    int sumarPuntos=0;

    sumarPuntos=rand()%25-1;

    printf("Has atendido clinicamente a %s.\n", mascota[0].nombre);
    printf("Ha recuperado %i puntos de salud.\n", sumarPuntos);

    return sumarPuntos;
}

int subirHambre(stMascota mascota[]){
    int sumarPuntos=0;

    sumarPuntos=rand()%25-1;

    printf("Has dado de comer a %s.\n", mascota[0].nombre);
    printf("Ha recuperado %i puntos de hambre.\n", sumarPuntos);

    return sumarPuntos;
}

int subirSed(stMascota mascota[]){
    int sumarPuntos=0;

    sumarPuntos=rand()%25-1;

    printf("%s ha bebido agua.\n", mascota[0].nombre);
    printf("Ha recuperado %i puntos de sed.\n", sumarPuntos);

    return sumarPuntos;
}

int subirDiversion(stMascota mascota[]){
    int sumarPuntos=0;

    sumarPuntos=rand()%25-1;

    printf("Has jugado con %s.\n", mascota[0].nombre);
    printf("Ha recuperado %i puntos de diversion.\n", sumarPuntos);

    return sumarPuntos;
}

int subirAnimo(stMascota mascota[]){
    int sumarPuntos=0;

    sumarPuntos=rand()%25-1;

    printf("Has acariciado a %s.\n", mascota[0].nombre);
    printf("Ha recuperado %i puntos de animo.\n", sumarPuntos);

    return sumarPuntos;
}

void asignarNecesidades(stMascota mascota[]){
    mascota[0].salud=100;
    mascota[0].hambre=50;
    mascota[0].sed=30;
    mascota[0].diversion=20;
    mascota[0].animo=30;

    if(mascota[0].especie==1){
        mascota[0].salud=150;
    }
    else if(mascota[0].especie==2){
        mascota[0].diversion=60;
        mascota[0].animo=60;
    }
    else if(mascota[0].especie==3){
        mascota[0].hambre=75;
        mascota[0].sed=60;
    }
}

int restarTiempo(int tiempoVictoria){
    int restaTiempo=rand()%5+1;
    tiempoVictoria=tiempoVictoria-restaTiempo;

    if(tiempoVictoria<0){
        tiempoVictoria=0;
    }

    printf("Tu mascota crecera en: %i dias. \n", tiempoVictoria);

    return tiempoVictoria;
}

void restarNecesidades(stMascota mascota[]){
    int restarPuntos=5;

    restarPuntos=rand()%10;

    mascota[0].salud=mascota[0].salud-restarPuntos;
    mascota[0].hambre=mascota[0].hambre-restarPuntos;
    mascota[0].sed=mascota[0].sed-restarPuntos;
    mascota[0].diversion=mascota[0].diversion-restarPuntos;
    mascota[0].animo=mascota[0].animo-restarPuntos;
}

void controlDeMinimos(stMascota mascota[]){
    if(mascota[0].salud<0){
        mascota[0].salud=0;
    }
    if(mascota[0].hambre<0){
        mascota[0].hambre=0;
    }
   if(mascota[0].sed<0){
        mascota[0].sed=0;
    }
    if(mascota[0].diversion<0){
        mascota[0].diversion=0;
    }
    if(mascota[0].animo<0){
        mascota[0].animo=0;
    }
}

void imprimirAnimal(stMascota mascota[]){
    if(mascota[0].especie==1){
        printf("\n             ____     \n");
        printf("              /    \__  \n");
        printf("  |\         /    @   \ \n");
        printf("  \ \_______|    \  .:|>\n");
        printf("   \      ##|    | \__/ \n");
        printf("    |    ####\__/   \   \n");
        printf("    /  /  ##       \|   \n");
        printf("   /  /__________\  \   \n");
        printf("   L_JJ           \__JJ \n");
    }
    if(mascota[0].especie==2){
        printf("\n _._     _,-'""`-._       \n");
        printf("  (,-.`._,'(       |\`-/|   \n");
        printf("      `-.-' \ )-`( , o o)   \n");
        printf("            `-    \`_`-'-   \n");
    }
    if(mascota[0].especie==3){
         printf("\n             ((`\       \n");
         printf("            ___ \\ '--._  \n");
         printf("         .'`   `'    o  ) \n");
         printf("        /    \   '. __.'  \n");
         printf("       _|    /_  \ \_\_   \n");
         printf("      {_\______\-'\__\_\  \n");
    }
}

void victoria(){
    LIMPIEZA;
    printf("FELICIDADES! \n\n TU MASCOTA HA CRECIDO MUY FELIZ! \n\n HAS GANADO EL JUEGO.\n\n");
    PAUSA;
    LIMPIEZA;
    gameManager();
}

void gameOver(){
    LIMPIEZA;
    printf("GAME OVER. \n\n LA ASOCIACION DE PROTECCION ANIMAL TE HA QUITADO \n A TU MASCOTA POR NO CUMPLIR CON LOS CUIDADOS. \n\n PERDISTE EL JUEGO\n\n");
    PAUSA;
    LIMPIEZA;
    gameManager();
}

void salir(){
    printf("SALISTE DEL JUEGO. \n\n");

    PAUSA;

    exit(1);
}
