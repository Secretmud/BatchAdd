#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void user_parse(char tmp[1024]);

int main(int argc, char * argv[]) {
    FILE * file;
    char buffer[1024];
    int i = 0;
    if (argc == 2) {
        file = fopen(argv[1], "r");
        clock_t start;
        start = clock();
        while(fgets(buffer, sizeof buffer, file) != NULL) {
            fputs(buffer, stdin);
            user_parse(buffer);
	    i++;
        }
        start = clock() - start;
        printf("%d users added in %.4fs\n", i, ((float)start)/ CLOCKS_PER_SEC);
        fclose(file);
    } else {
        printf("You need to pass a user file as a program argument\n");
    }
    return 0;
}

void user_parse(char tmp[1024]) {
    char buffer[10][1024];
    const char * delimeter = ":";
    char * cmd = (char * )malloc(sizeof buffer);
    char * token = strtok(tmp, delimeter);
    int x = 0;
    while (token != NULL) {
        strcpy(buffer[x], token);
        token = strtok(NULL, delimeter);
        x++;
    }
    /*
     * buffer[0] = USERNAME
     * -u buffer[1] = UUID
     * -G buffer[2] = GROUP
     * -c buffer[3] = USER COMMENT
     * -d buffer[4] = HOME DIR
     * -s buffer[5] = SHELL
     * -p buffer[6] = PASSWORD
     *
     * Need to find a better way of hashing(Looking into openssl/sha.h) below is the two current versions I've tested	
     * 		mkpasswd -m sha-512 %s
     * 		
     **/
    sprintf(cmd, "sudo groupadd %s && sudo useradd %s -u %s -p $(mkpasswd -m sha-512 %s) -G %s -c \"%s\" -d %s -s %s",
                        buffer[2], buffer[0], buffer[1], 
                        buffer[6], buffer[2], buffer[3],
                        buffer[4], buffer[5]);
    system(cmd);
    free(cmd);
}
