// https://www.youtube.com/watch?v=xAf5xznfBUQ

#include <stdio.h>
#include <stdlib.h>

int main() {
    // int * pa = malloc(sizeof(int));
    // if (pa == NULL) {
    //     printf("ERROR malloc\n");
    //     return 1;
    // }

    // *pa = 10;

    // printf("adresse de pa : %p\n", pa);
    // printf("Valeur à l'adresse pointee par pa : %d\n", *pa);

    // free(pa);


    // int tab[5];
    int n = 10;
    int * tab = malloc(n * sizeof(int));

    tab[0] = 0;
    tab[1] = 10;
    tab[2] = 20;
    tab[3] = 30;
    tab[4] = 44;

    for (int i = 0; i < n; i++) {
        printf("tab[%d] = %d\n" , i, tab[i]);
    }

    free(tab);

    return 0;
}
