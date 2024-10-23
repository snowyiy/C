#include <stdio.h>

#define MAX_BUFFER_SIZE 1000


int main() {
    FILE * fp;

    fp = fopen("fichier.txt", "r");
    if (fp == NULL) {
        printf("ERROR fopen");
        return 1;
    }


/*     char c = fgetc(fp);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    } */

/*    char c;
   while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
   } */

    char str[MAX_BUFFER_SIZE];
    while (fgets(str, MAX_BUFFER_SIZE, fp) != NULL) {
        printf("%s", str);
    }

    printf("\n");

    fclose(fp);


    return 0;
}