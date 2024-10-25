#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strlen()

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define BUFFER 256

typedef enum {False, True} bool;

struct Morseletter {char letter; char * code_letter;};
// dictionary for translate letter to morse
struct Morseletter morse[27] = {{'a', "01"}, {'b', "1000"}, {'c', "1010"}, {'d', "100"}, {'e', "0"}, {'f', "0010"}, {'g', "110"},
                                {'h', "0000"}, {'i', "00"}, {'j', "0111"}, {'k', "101"}, {'l', "0100"}, {'m', "11"}, {'n', "10"},
                                {'o', "111"}, {'p', "0110"}, {'q', "1101"}, {'r', "010"}, {'s', "000"}, {'t', "1"}, {'u', "001"},
                                {'v', "001"}, {'w', "011"}, {'x', "1001"}, {'y', "1011"}, {'z', "1100"}, {'_', " "}};

int MESSAGE_MORSE_SIZE;


// take a message to translate from user
void takeMessage(char * message) {
    printf("enter a message :\n");
    scanf("%s", message);
    // fgets(message, BUFFER, stdin);  <- TODO  (seg fault)

}

// translate message
void translateToMorse(char * t_message, char ** t_message_morse, int t_size) {
    for (int i = 0; i < t_size; i++) {
        int j = 0;
        char * str_buffer;
        while (t_message[i] != morse[j].letter && j < ARRAY_SIZE(morse) + 1)
            j++;
        if (j != ARRAY_SIZE(morse) + 1)
            t_message_morse[i] = morse[j].code_letter;
        else
            printf("ERROR : char not in struct Morseletter");

        // display the coded message
        int code_letter_size = strlen(morse[j].code_letter);
        for (int h = 0; h < code_letter_size; h++) {
            if (morse[j].code_letter[h] == '0')
                // dot
                printf(". ");
            else if (morse[j].code_letter[h] == '1')
                // dash
                printf("- ");
            else if (morse[j].code_letter == " ")
                // spaces
                printf("       ");
            else 
                printf("ERROR (ln %d in translateToMorse)\n", __LINE__);
        }
        // space beetween letters 
        printf("   ");
    }
    printf("\n");
}


char ** code() {

    char * message = malloc(BUFFER * sizeof(char));
    takeMessage(message);

    // store the size of message into size
    int size = strlen(message);
    MESSAGE_MORSE_SIZE = strlen(message);

    // define coded message
    char ** message_morse = malloc(size * sizeof(char));

    translateToMorse(message, message_morse, size);

    // print the coded message
    for (int i = 0; i < size; i++)
        printf("%s ", message_morse[i]);
    printf("\n");

    free(message);
    return message_morse;
}


void decode(char ** message_morse) {
    char * message_decode = malloc(BUFFER * sizeof(char));

    // decode the message
    for (int i = 0; i < MESSAGE_MORSE_SIZE; i++) {
        int j = 0;
        while (message_morse[i] != morse[j].code_letter && j < ARRAY_SIZE(morse) + 1)
            j++;
        if (j != ARRAY_SIZE(morse) + 1) {
            if (morse[j].letter == '_') 
                message_decode[i] = ' ';
            else
                message_decode[i] = morse[j].letter;
        } else
            printf("ERROR : char not in struct Morseletter");
    }

    // print the decoded message
    for (int i = 0; i < MESSAGE_MORSE_SIZE; i++)
        printf("%c", message_decode[i]);
    printf("\n");

    free(message_morse);
    free(message_decode);
}


int main() {
    // code a message
    char ** message_code = code();

    // decode a message
    decode(message_code);

    return 0;
}
