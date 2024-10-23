// https://www.youtube.com/watch?v=ipxT2_2T3qs&list=PLEagTQfI6nPOWS4JPnxW5pRVgeyLuS5oC&index=14

#include <stdio.h>


void remplirTableau(int * tab, int size) {
    int i;
    for (i = 0; i < size; i++) {
        tab[i] = 100 * i;
    }
}


int main() {
    char name[50];
    int age;
    int tabEntier[50];
    int taille = 50;

    // name == &(name[0])

    // printf("%p\n", name);
    // printf("%p\n", &name[0]);

    for (int i = 0; i < taille; i++) {
        printf("tabEntier[%d] = %d \n", i, tabEntier[i]);
    }

    remplirTableau(tabEntier, taille);
    printf("\n=====================\n");

    for (int i = 0; i < taille; i++) {
        printf("tabEntier[%d] = %d \n", i, tabEntier[i]);
    }



    /*
    printf("Quel est votre prenom ?    ");
    scanf("%s", name);

    printf("Quel age avez-vous ?     ");
    scanf("%d", &age);

    printf("Nom -> %s | Age -> %d\n", name, age);
    */

    return 0;
}