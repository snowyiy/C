#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 64


int main(int argc, char * argv[]) {

    if (argc == 2) {
        // asign argv[1] to buffer
        char buffer[BUFFER];
        strcpy(buffer, argv[1]);
        printf("%s\n", buffer);

        // count the index of '.'
        int i;
        for (i = 0; buffer[i] != '.'; i++);
        char * file = malloc(i+5);
        strcpy(file, buffer);

        // get the file name
        char * file_name = malloc(i);
        memcpy(file_name, buffer, i);
        file_name[i] = '\0';
        //printf("%s\n", file_name);

        // get the file extention
        char file_extention[5];
        strcpy(file_extention, &buffer[i]);
        //printf("%s\n", file_extention);


        // TODO : check the file extention
        //if (file_extention == ".btxt") {
            FILE * p_file;
            p_file = fopen(file, "r+");

            if (NULL == p_file) {
                fprintf(stderr, "ERROR : file can't be opened\n");
                return EXIT_FAILURE;
            }

            char letter;
            int bold = 0;
            while ((letter = fgetc(p_file)) != EOF) {
                if (letter == '/' && bold == 0) {
                    bold = 1;
                    continue;
                } else if (letter == '*' && bold == 1) {
                    bold = 2;
                    continue;
                } else if (letter == '*' && bold == 2) {
                    bold = 1;
                    continue;
                } else if (letter == '/' && bold == 1) {
                    bold = 0;
                    continue;
                }

                if (bold == 2)
                    printf("\e[1m%c\e[m", letter);
                else 
                    printf("%c", letter);

            } printf("\n");

            fclose(p_file);

        //} else {
            //fprintf(stderr, "ERROR : wrong file extention\n");
            //return 1;
        //}


        free(file_name);
        
    } else if (argc != 1) {
        fprintf(stderr, "ERROR : too many arguments !\n");
        return 1;
    }

    return 0;
}
