//#include "consecutive.c"
//#include "increment-1.c"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>



// example: given spawn 1 "increment 10 foo.txt"
int main(int argc, char* argv[]){
int status;
int MAX_CHILDREN = atoi(argv[1]);
printf("%d\n", MAX_CHILDREN);
pid_t pid;
pid = fork();
    for(int i = 0; i < MAX_CHILDREN; i++){

      char* args[] = {argv[2], argv[3],argv[4],  NULL };

      execv(args[2], args);

      printf("child process is running %d times\n", i +1);

    }

    for(int j = 0; j < MAX_CHILDREN; ++j){
      wait(NULL);
    }


/*
else{
  status = system("./main test.txt");
  printf("parent process is running");
}

*/

  return 0;



}
