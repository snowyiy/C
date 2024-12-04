#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


struct Turtle {
    int pos;
    int marble_in_pouch;
};
struct Turtle turtle = {0, 0};


void avance(int num_cases2) {
    printf("avance     ");
    turtle.pos += 1;
    if (turtle.pos > num_cases2) {
        printf("ERROR : avance() -> try to escape tab");
    }
}

void prends(int * tab) {
    printf("prends     ");
    tab[turtle.pos] -= 1;
}

bool murDevant(int num_cases2) {
    printf("if murDevant     ");
    if (turtle.pos == num_cases2 - 1) { return true; }
    else { return false; }
}

bool billeAuSol(int * tab) {
    printf("if billeAuSol     ");
    if (tab[turtle.pos] != 0) { return true; }
    else { return false; }
}


void printTab(int num_cases2, int * tab2) {
    printf("|");
    for (int i = 0; i < num_cases2; i++) { printf(" %d |", tab2[i]); }
    printf("\n");
}


int main() {
    // Generate the tab on which the turtle is gonna walk
    int upper_bound_cases = 10;
    int lower_bound_cases = 4;
    int upper_bound_marbles = 7;
    int lower_bound_marbles = 0;

    int num_cases = rand() % (upper_bound_cases - lower_bound_cases + 1) + lower_bound_cases;
    int * tab = malloc(sizeof(int) * num_cases);
    for (int i = 0; i < num_cases; i++) {
        tab[i] = rand() % (upper_bound_marbles - lower_bound_marbles + 1) + lower_bound_marbles;
    }
    
    printTab(num_cases, tab);

    // START OF THE CODE HERE
    while (murDevant(num_cases) == false) {
        while (billeAuSol(tab) == true) {
            prends(tab);
            printTab(num_cases, tab);
            usleep(1000000);
        }
        avance(num_cases);
        printTab(num_cases, tab);
        usleep(1000000);
    }
    while (billeAuSol(tab) == true) {
        prends(tab);
        printTab(num_cases, tab);
        usleep(1000000);
    }
//printTab(num_cases, tab);
//usleep(1000000);


    free(tab);

    return 0;
}
