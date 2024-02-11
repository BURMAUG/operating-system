#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length of command */
int
main(void){
    int should_run = 1;
    while(should_run){
        printf("osh> ");
        fflush(stdout);
        // Make a child process
        pid_t pid; 
        pid = fork();
        char user_input[MAX_LINE];
        scanf("%79[^\n]", user_input);
        if(pid == -1){
            perror("error");
            exit(-1);
        }
        else if(pid == 0){
            char* argv[4] = {"bash", "-c", user_input, NULL};
            // Child process
            execvp(argv[0], argv);
            exit(1);
        }else{
            wait(NULL);
            printf("Child has completed printing the processes from execvp.\n");
        }
//        should_run = 0;
    }
    return 1;

}
