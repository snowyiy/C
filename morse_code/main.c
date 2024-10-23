#include <stdio.h>
#include <stdlib.h>


int main() {
    // dictionary for translate letter to morse
    char morse_letter[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                            'x', 'y', 'z'};
    char morse_letter_code[][26] = {"12", "2111", "2121", "211", "1", "1121", "221", "1111", "11", "1222", "212", "1211", "22", "21", "222",
                                    "1221", "2212", "121", "111", "2", "112", "1112", "122", "2112", "2122", "2211"};


    // take a message to translate from user
    int buffer = 1024;
    char message[1024];
    printf("enter a message (1024 char max):\n");
    scanf("%s", message);  // \0

    // for (int i = 0; i < size; i++) {
    //     printf("%c", message[i]);
    // }

    // count spaces at the end
    int spaces = 0;
    int i = buffer;
    while (message[i] != EOF) {
        spaces++;
        i--;
    }

    // set size to the size of message without the spaces at the end
    int size = buffer - spaces;
    // printf("size : %d\n", size);
    // printf("spaces : %d\n", spaces);

    // set the size of the translated message
    char *message_morse = malloc(size * sizeof(char*));

    // !-DOESN'T WORK -> pointer
    // code the message
    for (int i = 0; i < size; i++) {
        for (int j = 0; i < 27; i++) {
            if (message[i] == morse_letter[j]) {     //!
                message_morse[i] = morse_letter_code[j];  //!
            }
        }
    }

    // print the coded message
    for (int i = 0; i < size; i++) {
        printf("%c", message_morse[i]);
    }
    printf("\n");

    free(message_morse);

    return 0;
}
