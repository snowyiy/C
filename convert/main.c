#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int powi(int a, int b) {
    int r = 1;
    for (int i = 0; i < b; i++) {
        r *= a;
    }
    return r;
}


int BinaryToDecimal(int binary) {
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

    //convert binary_to_convert
    int result_decimal = BinaryToDecimal(binary_to_convert);
    printf("%d\n", result_decimal);

    return 0;
}
