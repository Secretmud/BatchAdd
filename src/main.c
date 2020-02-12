#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void user_parse(char tmp[1024]);

int main(int argc, char * argv[]) {
    FILE * file;
    char buffer[1024];
    int i = 0;
    if (argc == 2) {
        file = fopen(argv[1], "r");
        while(fgets(buffer, sizeof buffer, file) != NULL) {
            fputs(buffer, stdin);
            user_parse(buffer);
	    i++;
        }
	printf("%d users added\n", i);
        fclose(file);
    } else {
        printf("You need to pass a user file as a program argument\n");
    }
    return 0;
}

void user_parse(char tmp[1024]) {
    char buffer[10][1024];
    const char * pass = "PASSWORD";
    char * cmd = (char * )malloc(sizeof buffer);
    char * token = strtok(tmp, ":");
    int x = 0;
    while (token != NULL) {
        strcpy(buffer[x], token);
        token = strtok(NULL, ":");
        x++;
    }
    /*
     * buffer[0] = USERNAME
     * buffer[1] = UUID
     * buffer[2] = GROUP
     * buffer[3] = USER COMMENT
     * buffer[4] = HOME DIR
     * buffer[5] = SHELL
     * buffer[6] = PASSWORD
     **/
    sprintf(cmd, "echo %s %s -u %s -p $(openssl dgst -sha512 <<< %s) -G %s -c \"%s\" -d %s -s %s",
                        buffer[2], buffer[0], buffer[1], 
						buffer[6], buffer[2], buffer[3],  
                        buffer[4], buffer[5]);
    system(cmd);
    free(cmd);
}