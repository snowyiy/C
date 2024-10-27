#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


enum {dead, alive};


void drawMatrix(char *matrix, const int lines, const int columns) {
    for (int i = 0; i < columns + 2; i++) { printf("--"); }
    printf("\n");

    for (int i = 0; i < lines; i++) {
        printf("| ");
        for (int j = 0; j < columns; j++) {
            if (*(matrix + i * columns + j))  // matrix[i][j]
                //printf("\033[105m  \033[0m");
                printf("##");
            else
                printf("  ");
        }
        printf(" |\n");
    }

    for (int i = 0; i < columns + 2; i++) { printf("--"); }
    printf("\n");

}


char updateCell(char * matrix, const int l_pos, const int c_pos, const int lines, const int columns) {
    int num_neighbors_cells = 0;
    int i, j;

    for (i = l_pos - 1; i <= l_pos + 1; i++) {
        if (i >= 0 && i < lines) {
            for (j = c_pos - 1; j <= c_pos + 1; j++) {
                if (j >= 0 && j < columns) {
                    if (i != l_pos && j != c_pos) {
                        if (*(matrix + i * columns + j) == alive) {
                            num_neighbors_cells++;
                        }
                    } 
                }
            }
        }
    }

    if (*(matrix + l_pos * columns + c_pos) == alive) {
        if (num_neighbors_cells == 2 || num_neighbors_cells == 3) { return alive; }
        else { return dead; }
    } else {
        if (num_neighbors_cells == 3) { return alive; }
        else { return dead; }
    }
}


void updateMatrixV1(char * matrix, char * matrix_bis, const int lines, const int columns) {
    for (int l = 0; l < lines; l++) {
        for (int c = 0; c < columns; c++)
            // matrix_bis[l][c]
            *(matrix_bis + l * lines + c) = updateCell(matrix, l, c, lines, columns);
    }

    for (int l = 0; l < lines; l++) {
        for (int c = 0; c < columns; c++)
            // matrix[l][c] = matrix_bis[l][c]
            *(matrix + l * lines + c) = *(matrix_bis + l * lines + c);
    }
}


void setupMatrix(char * matrix_m, const int lines_m, const int columns_m, char * matrix_s, const int lines_s, const int columns_s, const int x, const int y) {
    for (int i = y; i < y + lines_s; i++) {
        for (int j = x; j < x + columns_s; j++) {
            *(matrix_m + i * lines_m + j) = *(matrix_s + (i - y) * columns_s + (j - x));
        }
    }
}


int main() {

    // define matrix
    const int lines = 80;
    const int columns = 180;
    
    char matrix[lines][columns];
    char matrix_bis[lines][columns];

    for (int l = 0; l < lines; l++) {
        for (int c = 0; c < columns; c++) {
            matrix[l][c] = dead;
            matrix_bis[l][c] = dead;
        }
    }

    char matrix_setup[3][3] = {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    };
 
    // setup the matrix
    setupMatrix(&matrix[0][0], lines, columns, &matrix_setup[0][0], 3, 3, 20, 5);

    while (1) {
        // refresh the screen
        system("clear");

        // update the matrix
        updateMatrixV1(&matrix[0][0], &matrix_bis[0][0], lines, columns);

        // draw matrix
        drawMatrix(&matrix[0][0], lines, columns);

        // wait
        usleep(5000);
    }

    return 0;
}