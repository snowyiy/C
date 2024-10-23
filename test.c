#include <stdio.h>

typedef enum {False, True} bool;


int askUser(bool ask_user) {
    int max = 10;
    if (ask_user == True) {
        printf("how far do you want to count ?   ");
        scanf("%d", &max);
    } else {
        printf("skip user\n");
    }

    return max;
}


int carre(int n) {
    return n * n;
}

int main() {
    // int age = 10;
    // char lettre;
    // float decimal;
    int i;
    bool ask_user = True;
    // char name[6] = "eneko";

    // lettre = 'a';
    // decimal = 1.2;

    // printf("Hello World\n");
    //printf("%d\n", age);
    //printf("%f\n", decimal);
    //printf("%c\n", lettre);

    int max = askUser(ask_user);
    
    for (i = 0; i <= max; i++) {
        printf("%d\n", i);
    }
    printf("\n");

    // int n;
    // printf("entrer un nombre : ");
    // scanf("%d", &n);
    // printf("Le carre de %d est %d \n", n, carre(n));

    return 0;
}
