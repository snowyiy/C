#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

void sort(/*int list_input[]*/) {
    int list_input[5] = {1, 8, 5, 12, 3};
    int len_list_input = ARRAY_SIZE(list_input);
    int list_output[len_list_input];
    
    for (int i = 0; i < len_list_input; i++) {
        int rang_min = 0;
        int min = list_input[0];

        for (int j = 1; j < len_list_input; j++) {
            //printf("min : %d > list_input[%d] : %d\n", min, j, list_input[j]);
            if (min > list_input[j]) {
                //printf("if true\n");
                min = list_input[j];
                rang_min = j;
            }
        }

        //printf("min : %d | rang_min : %d\n", min, rang_min);
        list_output[i] = min;
        list_input[rang_min] = 1000000;
    }
    
    for (int y = 0; y < ARRAY_SIZE(list_input); y++) {
        printf("%d, ", list_output[y]);
    }

    printf("\n");
}


int main() {
    int list[5] = {1, 8, 5, 12, 3};

    sort(/*list*/);


    return 0;
}
