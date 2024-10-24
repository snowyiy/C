#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strlen()

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

struct Morseletter {char letter; char * code_letter;};

// dictionary for translate letter to morse
struct Morseletter morse[26] = {{'a', "01"}, {'b', "1000"}, {'c', "1010"}, {'d', "100"}, {'e', "0"}, {'f', "0010"}, {'g', "110"},
                                {'h', "0000"}, {'i', "00"}, {'j', "0111"}, {'k', "101"}, {'l', "0100"}, {'m', "11"}, {'n', "10"},
                                {'o', "111"}, {'p', "0110"}, {'q', "1101"}, {'r', "010"}, {'s', "000"}, {'t', "1"}, {'u', "001"},
                                {'v', "001"}, {'w', "011"}, {'x', "1001"}, {'y', "1011"}, {'z', "1100"}};


// take a message to translate from user
void take_message(char * message) {
    printf("enter a message :\n");
    scanf("%s", message);

}

// translate message
void translate(char * t_message, char ** t_message_morse, int t_size) {//, struct Morseletter * t_morse, int t_array_size) {
    for (int i = 0; i < t_size; i++) {
        int j = 0;
        while (t_message[i] != morse[j].letter && j < ARRAY_SIZE(morse) + 1)
            j++;
        t_message_morse[i] = morse[j].code_letter;
    	
        // display the coded message
        int code_letter_size = strlen(morse[j].code_letter);
        for (int h = 0; h < code_letter_size; h++) {
            if (morse[j].code_letter[h] == '1')
                // dot
                printf("- ");
            else
                // dash
                printf("--- ");
        }
        // space beetween letters 
        printf("   ");
    }
    printf("\n");
}


void code() {

    int buffer = 256;
    char * message = malloc(buffer * sizeof(char));
    take_message(message);

    // store the size of message into size
    int size = strlen(message);

    // define coded message
    char ** message_morse = malloc(size * sizeof(char));

    translate(message, message_morse, size);

    // print the coded message
    for (int i = 0; i < size; i++)
        printf("%s ", message_morse[i]);
    printf("\n");

    free(message);
    free(message_morse);

}


void decode() {

}


int main() {
    // code a message
    code();

    // decode a message
    //decode()

    return 0;
}
