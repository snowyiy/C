// https://www.youtube.com/watch?v=Q_YaKftLRfI

#include <stdio.h>


// int add(int * na, int * nb) {
//     return *na + *nb;
// }

void swap(int * na, int * nb) {
    printf("Swap...\n");
    
    int tmp = *na;
    *na = *nb;
    *nb = tmp;

}

int main() {
    int a = 3;
    int b = 2;

    // printf("a + b = %d\n", add(&a, &b));

    printf("a = %d | b = %d\n", a, b);

    swap(a, b);

    printf("a = %d | b = %d\n", a, b);

    return 0;
}
