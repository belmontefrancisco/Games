#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PAUSA system("pause")
#define LIMPIEZA system("cls")
#define MAX_LETRAS 15

//PROTOTIPOS
void gameManager();
void inicio();
void instrucciones();
void nivel1(char nombre[MAX_LETRAS]);
void salir();

void elegirNombre(char nombre[MAX_LETRAS], int *validosNombre);
int elegirClase(int clase);
int asignarVida(int clase);
void dragon(char nombre[MAX_LETRAS], int clase);
int atacar(int clase, int dano);
int defender(int clase, int defensa);
int pocion(int clase, int curar);
int dragonAtaca(int dano);
int dragonDefiende(int defensa);

void victoria();
void gameOver();

//MAIN
int main()
{
    srand(time(NULL));

    gameManager();

    return 0;
}

//FUNCIONES
void gameManager(){
    //VARIABLES

    char nombre[MAX_LETRAS];
    int claseSeleccionada[3];
    int comandos[2];

    int validosNombre=0;
    int clase=0;

    inicio();
    elegirNombre(nombre, &validosNombre);
    clase=elegirClase(clase);
    nivel1(nombre);
    dragon(nombre, clase);
}

void inicio(){
    int menu=0;

    printf("\t AVENTURA DE ROL C\n");
    printf("\t   Una pequena historia \n\n");
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
    printf("\t\n Esta es una aventura de rol en la que tendras que seleccionar tus acciones utilizando los numeros. \n\n");

    PAUSA;
    LIMPIEZA;

    inicio();
}

void elegirNombre(char nombre[MAX_LETRAS], int *validosNombre){
    printf("Elige el nombre de tu personaje:");
    fflush(stdin);
    gets(nombre);

    for (int i = 0; nombre[i] != '\0'; i++)
        nombre[i] = toupper(nombre[i]);

    printf("El nombre del personaje es: %s \n", nombre);

    PAUSA;
    LIMPIEZA;
}

int elegirClase(int clase){

    int decisionClase=0;
    printf("Elige una clase: \n");
    printf("\t\n 1. Guerrero \n Es una clase defensiva especializada en supervivencia. \t\n\n 2. Mago \n Es una clase centrada en recuperacion de salud. \t\n\n 3. Arquero \n Esta clase puede atacar dos veces seguidas en un turno.\n");
    fflush(stdin);
    scanf("%i", &decisionClase);

    switch(decisionClase){

    case 1:
        clase=1;
        printf("Has elegido ser Guerrero. \n");
    break;

    case 2:
        clase=2;
        printf("Has elegido ser mago. \n");
        printf("Clase: %i \n", clase);
    break;

    case 3:
        clase=3;
        printf("Has elegido ser arquero. \n");
        printf("Clase: %i \n", clase);
    break;

    default:
        printf("HA PRESIONADO TECLA INVALIDA. \n");
        fflush(stdin);
        inicio();
    break;

    }
    PAUSA;
    LIMPIEZA;

    return clase;

}

void nivel1(char nombre[MAX_LETRAS]){
        printf("Cuenta la leyenda, que en un tiempo muy lejano, un heroe legendario llamado %s se enfrento a un dragon...", nombre);
        PAUSA;
}

void dragon(char nombre[MAX_LETRAS], int clase){
    int vidaMaxima=asignarVida(clase);

    int vidaActual=vidaMaxima;
    int vidaDragon=100;
    int dano=0;
    int defensa=0;
    int curar=0;
    int decision=0;
    int decisionDragon=0;


    while(vidaActual>0 && vidaDragon>0){

    printf("            ( _)                ( _)            \n");
    printf("           / / \\              / /\_\_          \n");
    printf("          / /   \\            / / | \ \         \n");
    printf("         / /     \\          / /  |\ \ \        \n");
    printf("        /  /   ,  \ ,       / /   /|  \ \       \n");
    printf("       /  /    |\_ /|      / /   / \   \_\      \n");
    printf("      /  /  |\/ _ '_| \   / /   /   \    \\     \n");
    printf("     |  /   |/  o \o\    / |    |    \    \\    \n");
    printf("     |    |\|      \_\_ /  /    |     \    \\   \n");
    printf("     |  | |/    \.\ o\o)  /      \     |    \\  \n");
    printf("    \    |     /\\`v-v  /        |    |     \\  \n");
    printf("     | \/    /_| \\_|  /         |    | \    \\ \n");
    printf("    | |    /__/_ `-` /   _____  |    |  \    \\ \n");
    printf("     \|    [__]  \_/  |_________  \   |   \    ()\n");
    printf("      /    [___] (    \         \  |\ |   |   //\n");
    printf("      |    [___]                  |\| \|   /  |/\n");
    printf("     /|    [____]                  \  |/\ / / ||\n");
    printf("   (  \   [____ /     ) _\      \  \    \| | || \n");
    printf("    \  \  [_____|    / /     __/    \   / / //  \n");
    printf("    |   \ [_____/   / /        \    |   \/ //   \n");
    printf("    |   /  '----|   /=\____   _/    |   / //    \n");
    printf(" __ /  /        |  /   ___/  _/\    \  | ||     \n");
    printf(" (/-(/-\)       /   \  (/\/\)/  |    /  | /     \n");
    printf("              (/\/\)           /   /   //       \n");
    printf("                     _________/   /    /        \n");
    printf("                   \____________/    (          \n");


        decision=0;
        printf("------------------------------- \n");
        printf("|Salud de %s: %i PUNTOS |\n", nombre, vidaActual);
        printf("------------------------------- \n");
        printf("Clase: %i \n", clase);

        printf("------------------------------- \n");
        printf("|Salud del dragon: %i PUNTOS |\n", vidaDragon);
        printf("------------------------------- \n");

        printf("--------------------------------- \n");
        printf("| Que accion quieres tomar? \t| \n");
        printf("| 1.Atacar. \t\t\t| \n");
        printf("| 2.Defender. \t\t\t| \n");
        printf("| 3.Usar pocion. \t\t| \n");
        printf("--------------------------------- \n");
        fflush(stdin);
        scanf("%i", &decision);

        decisionDragon=rand()%2+1;

        if(decision==1){

                if(decisionDragon==1){
                    printf("El dragon te ha atacado.\n");
                    vidaActual=vidaActual-(dano=dragonAtaca(dano));
                    printf("Te quedan %i puntos de vida.\n", vidaActual);

                    printf("Has atacado al dragon.\n");
                    vidaDragon=vidaDragon-(dano=atacar(clase, dano));
                    printf("El dragon tiene %i puntos de vida.\n", vidaDragon);

                    if (clase==3){
                        printf("Tu habilidad como arquero te otorga un ataque extra.\n");
                        vidaDragon=vidaDragon-(dano=atacar(clase, dano));
                        printf("El dragon tiene %i puntos de vida.\n", vidaDragon);
                    }
                }
                else{
                    printf("El dragon se defiende.\n");
                    printf("Has atacado al dragon.\n");
                    vidaDragon=vidaDragon-(dano=atacar(clase, dano)-(defensa=dragonDefiende(defensa)));
                    printf("El dragon tiene %i puntos de vida.\n", vidaDragon);
                    if (clase=3){
                        printf("Tu habilidad como arquero te otorga un ataque extra.\n");
                        vidaDragon=vidaDragon-(dano=atacar(clase, dano)-(defensa=dragonDefiende(defensa)));
                        printf("El dragon tiene %i puntos de vida.\n", vidaDragon);
                    }
                }
        }
        else if(decision==2){
                if(decisionDragon==1){
                    printf("El dragon te ha atacado.\n");
                    vidaActual=vidaActual-(dano=dragonAtaca(dano)-(defensa=defender(clase, defensa)));
                    printf("Te quedan %i puntos de vida.\n", vidaActual);
                }
                else{
                    printf("Tu y el dragon se defienden.\n");
                }
        }
        else if(decision=3){
                if(decisionDragon==1){
                    vidaActual=vidaActual+pocion(clase, curar);

                    if(vidaActual>vidaMaxima){
                        vidaActual=vidaMaxima;
                    }

                    printf("El dragon te ha atacado.\n");
                    vidaActual=vidaActual-(dano=dragonAtaca(dano));
                    printf("Te quedan %i puntos de vida.\n", vidaActual);
                }
                else{
                    vidaActual=vidaActual+pocion(clase, curar);

                    if(vidaActual>vidaMaxima){
                        vidaActual=vidaMaxima;
                    }

                    printf("El dragon se defiende.\n");
                }
        }
        else{
            printf("Has ingresado un comando incorrecto.\n");
        }

    PAUSA;
    LIMPIEZA;
    }

    if(vidaActual<=0){
        gameOver();
    }

    if(vidaDragon<=0){
        victoria();
    }
}

int atacar(int clase, int dano){
    if(clase==1){
        dano=rand()%10+5;
    }
    else if(clase==2){
        dano=rand()%15+10;
    }
    else if(clase==3){
        dano=rand()%20+1;
    }

    printf("Has obtenido %i puntos de ataque.\n", dano);

    return dano;
}

int defender(int clase, int defensa){
    if(clase==1){
        printf("Tu habilidad como guerrero te otorga 10 puntos mas de defensa.\n");
        defensa=(rand()%5+1)+10;
    }
    else if(clase==2){
        defensa=rand()%5+1;
    }
    else if(clase==3){
        defensa=rand()%5+1;
    }

    printf("Has obtenido %i puntos de reduccion de dano en defensa.\n", defensa);

    return defensa;
}

int pocion(int clase, int curar){
    if(clase==1){
        curar=rand()%15+5;
    }
    else if(clase==2){
        printf("Tu habilidad como mago alquimista te otorga el doble de puntos de curacion.\n");
        curar=(rand()%15+5)*2;
    }
    else if(clase==3){
        curar=rand()%15+5;
    }

    printf("Te has curado %i puntos de vida.\n", curar);

    return curar;
}

int dragonAtaca(int dano){
    dano=rand()%15+2;

    printf("El dragon ha obtenido %i puntos de ataque.\n", dano);

    return dano;
}

int dragonDefiende(int defensa){
    defensa=rand()%5+2;

    printf("El dragon ha obtenido %i puntos de reduccion de dano como defensa.\n", defensa);

    return defensa;
}

int asignarVida(int clase){
    int vidaMaxima=0;

    if(clase==1){
        vidaMaxima=120;
    }
    else if(clase==2){
        vidaMaxima=50;
    }
    else if(clase==3){
        vidaMaxima=75;
    }

    return vidaMaxima;
}

void victoria(){
    printf("FELICIDADES! \n\n HAS GANADO EL JUEGO.\n\n");
    PAUSA;
    LIMPIEZA;
    gameManager();
}

void gameOver(){
    printf("GAME OVER. \n\n PERDISTE EL JUEGO\n\n");
    PAUSA;
    LIMPIEZA;
    gameManager();
}

void salir(){
    printf("SALISTE DEL JUEGO. \n\n");

    PAUSA;

    exit(1);
}
