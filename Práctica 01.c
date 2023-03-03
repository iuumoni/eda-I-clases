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

void mover_alfil(char tablero[][9], int x, int y) {
    reiniciar_tablero(tablero);

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (abs(i - x) == abs(j - y)) {
                tablero[i][j] = 'X';
            }
        }
    }
    tablero[x][y] = 'A';
    imprimir_tablero(tablero);
}

void mover_torre(char tablero[][9], int x, int y) {
    reiniciar_tablero(tablero);

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (i == x || j == y) {
                tablero[i][j] = 'X';
            }
        }
    }
    tablero[x][y] = 'T';
    imprimir_tablero(tablero);
}

int main() {
    char tablero[9][9];
    reiniciar_tablero(tablero);

    int opcion = 0;
    while (opcion != 3) {
        printf("Menu de opciones:\n");
        printf("1.- Alfil\n");
        printf("2.- Torre\n");
        printf("3.- Salir\n");
        printf("Ingrese la opcion elegida: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            int x, y;
            printf("Ingrese la coordenada x del alfil (1-8): ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y del alfil (1-8): ");
            scanf("%d", &y);
            mover_alfil(tablero, x, y);
        }
        else if (opcion == 2) {
            int x, y;
            printf("Ingrese la coordenada x de la torre (1-8): ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y de la torre (1-8): ");
            scanf("%d", &y);
            mover_torre(tablero, x, y);
        }
        else if (opcion == 3) {
            printf("Saliendo del programa...\n");
        }
        else {
            printf("Opcion no valida, intente de nuevo.\n");
        }
    }

    return 0;
}