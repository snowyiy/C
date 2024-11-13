#include <stdio.h>
#include <stdlib.h>

#define BUFFER 2048


int main(int argc, char * argv[]) {

    char * buffer = malloc(BUFFER);
    strcpy(buffer, argv[1]);
    //printf("%s\n", buffer);

    return 0;
}
