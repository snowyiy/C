#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 2048

int main() {
    char * file_path = malloc(BUFFER);
    printf("enter the path of the file to crypt :\n");
    scanf("%s", file_path);

    // get the name of the chosen file
    int h = strlen(file_path) - 1;
    while (file_path[h] != '/' && h >= 0) {
        h--;
    } h++;

    char * file_name = malloc(strlen(file_path - h));
    for (int i = h; i < strlen(file_path); i++) {
        file_name[i - h] = file_path[i];
    }

    // set the name of the crypted file
    char * crypt_file = "crypt-";   //!
    printf("crypted : %s\n", crypt_file);

    FILE *file;
    file = fopen(file_path, "r+");

    // print an error if the file does not exist
    if(file == NULL) { printf("ERROR ! the given file does not exist\n"); return 1; }

    
    char * file_content = malloc(BUFFER);

    while (fgets(file_content, BUFFER, file)) {
        printf("%d\n", strlen(file_content));



    }



    //int asciiValue = (int)ch;

    fclose(file);

    free(file_path);
    free(file_name);
    free(file_content);

    return 0;
}
