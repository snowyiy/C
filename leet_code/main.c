#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 256

void encodeLeet(char * text) {
    char * lowercase_text = malloc(BUFFER);
    for (int i = 0; i < strlen(text); i++)
        lowercase_text[i] = tolower(text[i]);

    for (int i = 0; i < strlen(text); i++) {
        switch (lowercase_text[i]) {
            case 'a':
                text[i] = '4';
                break;
            case 'e':
                text[i] = '3';
                break;
            case 'o':
                text[i] = '0';
                break;
            case 'i':
                text[i] = '1';
                break;
            defalut:
                break;
        }
    }

}


int main(int argc, char ** argv) {
    char * text = malloc(BUFFER);
    printf("Type a text here :\n");
    fgets(text, BUFFER, stdin);

    encodeLeet(text);

    printf("%s", text);

    return 1;
}
