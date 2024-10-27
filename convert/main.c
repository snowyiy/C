#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "powi.h"


// convert binary into decimal
int binaryToDecimal(int binary) {
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


// convert decimal into binary
int decimalToBinary(int decimal) {
    int binary = 0;
    // int power = 1;

    for (int i = 0; i < 8; i++) {
        binary += (decimal % 2) * powi(10, i);   // * power;
        decimal = floor(decimal / 2);
        // power *= 10;
    }

    return binary;
}


int main() {
    int binary_to_convert = 11111111;
    int decimal_to_convert = 255;


    int result_decimal = binaryToDecimal(binary_to_convert);
    printf("%d\n", result_decimal);

    int result_binary = decimalToBinary(decimal_to_convert);
    printf("%d\n", result_binary);

    return 0;
}
