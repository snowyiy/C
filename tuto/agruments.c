/*=====================================*/
            /*NE MARCHE PAS*/
/*=====================================*/

#include <stdio.h>

#define VERSION "1.0.0"

int main(int argc, char * argv[]) {

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (argv[i] == "-v" || argv[i] == "-version") {
                printf("version %s\n", VERSION);
            } else {
                printf("Invalid Argument : %s\n", argv[i]);
                return 1;
            }
        }
    }

    return 0;
}