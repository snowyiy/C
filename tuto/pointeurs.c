#include <stdio.h>

int main() {
    int a = 10;
    int * pa = &a;

    printf("'a' vaut %d (adresse : %p)\n", a, &a);
    printf("-> %p\n", pa);

    a = 20;

    printf("la valeur stockee à l'adresse %p est %d\n", pa, *pa);

    *pa = 30;

    printf("la valeur stockee à l'adresse %p est %d\n", pa, *pa);


    return 0;
}