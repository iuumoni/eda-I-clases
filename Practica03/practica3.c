#include <stdio.h>
#include <stdlib.h>

void imprimir_tablero(char tablero[][9]) {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void reiniciar_tablero(char tablero[][9]) {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if ((i + j) % 2 == 0) {
                tablero[i][j] = 'B';
            } else {
                tablero[i][j] = 'N';
            }
        }
    }
}
void mover_caballo(char tablero[][9], int x, int y) {
    reiniciar_tablero(tablero);

    if (x + 2 <= 8 && y + 1 <= 8) {
        tablero[x + 2][y + 1] = 'X';
    }
    if (x + 2 <= 8 && y - 1 >= 1) {
        tablero[x + 2][y - 1] = 'X';
    }
    if (x - 2 >= 1 && y + 1 <= 8) {
        tablero[x - 2][y + 1] = 'X';
    }
    if (x - 2 >= 1 && y - 1 >= 1) {
        tablero[x - 2][y - 1] = 'X';
    }
    if (x + 1 <= 8 && y + 2 <= 8) {
        tablero[x + 1][y + 2] = 'X';
    }
    if (x + 1 <= 8 && y - 2 >= 1) {
        tablero[x + 1][y - 2] = 'X';
    }
    if (x - 1 >= 1 && y + 2 <= 8) {
        tablero[x - 1][y + 2] = 'X';
    }
    if (x - 1 >= 1 && y - 2 >= 1) {
        tablero[x - 1][y - 2] = 'X';
    }

    tablero[x][y] = 'C';
    imprimir_tablero(tablero);
}

void mover_alfil(char tablero[][9], int x, int y) {
    reiniciar_tablero(tablero);

    for (int i = 1; i <= 8; i++) {
        if (x+i <= 8 && y+i <= 8) {
            tablero[x+i][y+i] = 'X';
        }
        if (x-i >= 1 && y-i >= 1) {
            tablero[x-i][y-i] = 'X';
        }
        if (x+i <= 8 && y-i >= 1) {
            tablero[x+i][y-i] = 'X';
        }
        if (x-i >= 1 && y+i <= 8) {
            tablero[x-i][y+i] = 'X';
        }
    }
    tablero[x][y] = 'A';
    imprimir_tablero(tablero);
}

void mover_torre(char tablero[][9], int x, int y) {
    reiniciar_tablero(tablero);

    for (int i = 1; i <= 8; i++) {
        if (i != y) {
            tablero[x][i] = 'X';
        }
    }
    for (int i = 1; i <= 8; i++) {
        if (i != x) {
            tablero[i][y] = 'X';
        }
    }
    tablero[x][y] = 'T';
    imprimir_tablero(tablero);
}

void mover_reyna(char tablero[][9], int x, int y) {
    reiniciar_tablero(tablero);

    for (int i = 1; i <= 8; i++) {
        if (i != y) {
            tablero[x][i] = 'X';
        }
    }
    for (int i = 1; i <= 8; i++) {
        if (i != x) {
            tablero[i][y] = 'X';
        }
    }
    for (int i = 1; i <= 8; i++) {
        if (x+i <= 8 && y+i <= 8) {
            tablero[x+i][y+i] = 'X';
        }
        if (x-i >= 1 && y-i >= 1) {
            tablero[x-i][y-i] = 'X';
        }
        if (x+i <= 8 && y-i >= 1) {
            tablero[x+i][y-i] = 'X';
        }
        if (x-i >= 1 && y+i <= 8) {
            tablero[x-i][y+i] = 'X';
        }
    }
    tablero[x][y] = 'Q';
    imprimir_tablero(tablero);
}
void mover_rey(char tablero[][9], int x, int y) {
    reiniciar_tablero(tablero);

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x+i >= 1 && x+i <= 8 && y+j >= 1 && y+j <= 8) {
                tablero[x+i][y+j] = 'X';
            }
        }
    }
    tablero[x][y] = 'R';
    imprimir_tablero(tablero);
}

int main() {
    char tablero[9][9];
    reiniciar_tablero(tablero);

    int opcion = 0;
    while (opcion != 6) {
        printf("Menu de opciones:\n");
        printf("1.- Caballo\n");
        printf("2.- Alfil\n");
        printf("3.- Torre\n");
        printf("4.- Reina\n");
        printf("5.- Rey\n");
        printf("6.- Salir\n");
        printf("Ingrese la opcion elegida: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            int x, y;
            printf("Ingrese la coordenada x del caballo (1-8): ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y del caballo (1-8): ");
            scanf("%d", &y);
            mover_caballo(tablero, x, y);
        }
        else if (opcion == 2) {
            int x, y;
            printf("Ingrese la coordenada x del alfil (1-8): ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y del alfil (1-8): ");
            scanf("%d", &y);
            mover_alfil(tablero, x, y);
        }
        else if (opcion == 3) {
            int x, y;
            printf("Ingrese la coordenada x de la torre (1-8): ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y de la torre (1-8): ");
            scanf("%d", &y);
            mover_torre(tablero, x, y);
        }
        else if (opcion == 4) {
            int x, y;
            printf("Ingrese la coordenada x de la reina (1-8): ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y de la reina (1-8): ");
            scanf("%d", &y);
            mover_reyna(tablero, x, y);
        }
        else if (opcion == 5) {
            int x, y;
            printf("Ingrese la coordenada x del rey (1-8): ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y del rey (1-8): ");
            scanf("%d", &y);
            mover_rey(tablero, x, y);
        }
        else if (opcion == 6) {
            printf("Saliendo del programa...\n");
        }
        else {
            printf("Opcion invalida.\n");
        }
    }
    return 0;
}