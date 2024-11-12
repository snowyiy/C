#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 2048

// TODO - séparer le code en fonction et en ajouter une pour décoder un fichier

int main(int argc, char * argv[]) {

    char * file_path = malloc(BUFFER);
    strcpy(file_path, argv[1]);
    //printf("%s\n", file_path);

    // get the name of the chosen file
    int h = strlen(file_path) - 1;
    while (file_path[h] != '/' && h >= 0) {
        h--;
    } h++;

    int file_name_size = strlen(file_path - h);
    char * file_name = malloc(file_name_size);
    for (int i = h; i < strlen(file_path); i++) {
        file_name[i - h] = file_path[i];
    }

    // set the name of the crypted file
    char * crypt_file_name = malloc(file_name_size + 6);
    strcpy(crypt_file_name, "crypt-");
    strcpy(&crypt_file_name[6], file_name);
    //printf("crypted : %s\n", crypt_file_name);

    FILE *file;
    file = fopen(file_path, "r+");

    // print an error if the file does not exist
    if (file == NULL) { printf("ERROR ! the given file does not exist\n"); return 1; }

    
    char * current_line = malloc(BUFFER);
    int * crypt_current_line = malloc(BUFFER);
    int crypt_file_content[BUFFER];

    FILE *crypt_file;
    crypt_file = fopen(crypt_file_name, "w");

    fclose(crypt_file);


    crypt_file = fopen(crypt_file_name, "ab");

    int j = 0;
    while (fgets(current_line, BUFFER, file)) {
        // //printf("%d\n", strlen(current_line));
        // for (int i = 0; i < strlen(current_line); i++) {
        //     if (current_line[i] == '\n') { crypt_current_line[i] = current_line[i]; }  
        //     else { crypt_current_line[i] = current_line[i]; }
        //     //printf("%d\n", current_line[i]);
        // }

<<<<<<< HEAD
        // crypt_file_content[j] = *crypt_current_line;
=======
        //for (int h = 0; h < BUFFER; h++)
            *(crypt_file_content + j) = crypt_current_line;
            //crypt_file_content[j] = crypt_current_line[h];
>>>>>>> refs/remotes/origin/dev

        // j++;
        fprintf(crypt_file, "%d", current_line);
    }

    fclose(file);


    // // write content to the crypt file
    // FILE *crypt_file;
    // crypt_file = fopen(crypt_file_name, "wb");

    //fprintf(crypt_file, "%d", file_content);

    fclose(crypt_file);


    free(file_path);
    free(file_name);
    free(crypt_file_name);
    free(current_line);
    free(crypt_current_line);

    return 0;
}
