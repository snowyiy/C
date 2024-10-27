#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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


int hexadecimalToBinary(char * hexadecimal, int size) {
    int binary = 0;

    for (int i = 0; i < size; i++) {
        switch (hexadecimal[i]) {
            case '0':
                binary += 000 * powi(10000, i);
                break;
            case '1':
                binary += 0001 * powi(10000, i);
                break;
            case '2':
                binary += 0010 * powi(10000, i);
                break;
            case '3':
                binary += 0011 * powi(10000, i);
                break;
            case '4':
                binary += 0100 * powi(10000, i);
                break;
            case '5':
                binary += 0101 * powi(10000, i);
                break;
            case '6':
                binary += 0110 * powi(10000, i);
                break;
            case '7':
                binary += 0111 * powi(10000, i);
                break;
            case '8':
                binary += 1000 * powi(10000, i);
                break;
            case '9':
                binary += 1001 * powi(10000, i);
                break;
            case 'a':
                binary += 1010 * powi(10000, i);
                break;
            case 'b':
                binary += 1011 * powi(10000, i);
                break;
            case 'c':
                binary += 1100 * powi(10000, i);
                break;
            case 'd':
                binary += 1101 * powi(10000, i);
                break;
            case 'e':
                binary += 1110 * powi(10000, i);
                break;
            case 'f':
                binary += 1111 * powi(10000, i);
                break;
            default :
                printf("ERROR !!!!!!!!!!!!!!!!!!!!!!!!!\n");
                return -1;
        }
    }

    return binary;
}


int main() {
    int binary_to_decimal = 11111111;
    int decimal_to_binary = 255;
    char hexadecimal_to_binary[2] = "f";

    // convert from binary to decimal
    int result_binary_to_decimal = binaryToDecimal(binary_to_decimal);
    printf("%d\n", result_binary_to_decimal);

    // convert from decimal to binary
    int result_decimal_to_binary = decimalToBinary(decimal_to_binary);
    printf("%d\n", result_decimal_to_binary);

    // convert hexadecimal to binary
    int str_size = strlen(hexadecimal_to_binary);  // get the number of char in hexadecimal_to_binary
    int result_hexadecimal_to_binary = hexadecimalToBinary(hexadecimal_to_binary, str_size);
    printf("%d\n", result_hexadecimal_to_binary);

    return 0;
}
