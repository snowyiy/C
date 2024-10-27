#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "powi.h"



// convert binary into decimal
int decimal(int binary) {
    int decimal;

    for (int i = 0; i < 8; i++) {
        // take the last digit
        int digit = binary - floor(binary / 10) * 10;
        binary = floor(binary / 10);

        // add the digit * 2exp i to decimal
        decimal += digit * powi(2, i);
    }

    return decimal;
}


int main() {
    int binary_to_convert = 11111111;

    int result_decimal = decimal(binary_to_convert);
    printf("%d\n", result_decimal);

    return 0;
}
