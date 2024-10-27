#include <stdio.h>
#include <stdlib.h>


enum {dead, alive};


void drawMatrix(char *matrix, const int lines, const int columns) {
    for (int i = 0; i < columns + 2; i++) { printf("--"); }
    printf("\n");

    for (int i = 0; i < lines; i++) {
        printf("| ");
        for (int j = 0; j < columns; j++) {
            if (*(matrix + i * columns + j))  // matrix[i][j]
                printf("\033[105m  \033[0m");
            else
                printf("  ");
        }
        printf(" |\n");
    }

    for (int i = 0; i < columns + 2; i++) { printf("--"); }
    printf("\n");

}

int main() {

    // define matrix
    const int lines = 80;
    const int columns = 180;
    
    char matrix[lines][columns];
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 0;
        }
    }
 
    // draw matrix
    drawMatrix(&matrix[0][0], lines, columns);

    return 0;
}