#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//TODO ability to encode txt file

#define BUFFER 256

struct LeetCode {
    char letter;
    char leet;
};
struct LeetCode LeetCode[4] = {{'a', '4'}, {'e', '3'}, {'i', '1'}, {'o', '0'}};


void encodeLeet(char * text) {
    char * lowercase_text = malloc(BUFFER);
    for (int i = 0; i < strlen(text); i++)
        lowercase_text[i] = tolower(text[i]);

    for (int i = 0; i < strlen(text); i++) {
        for (int j = 0; j < 4; j++) {
            if (lowercase_text[i] == LeetCode[j].letter)
                text[i] = LeetCode[j].leet;
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
