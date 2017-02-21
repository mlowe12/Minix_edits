#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int get_size(FILE* file){

  int val;
  int length = 0;


  while(fscanf(file, "%d", &val) != EOF){
    //printf("inside while!!!\n");
    ++length;
  }

  return length;
}


int* grab(FILE* file, int length){

  int val;
  int* data = calloc(length, sizeof *data);
  int i = 0;

  //printf("break1\n");
  fseek(file, 0, SEEK_SET);

  while(fscanf(file, "%d", &val) != EOF){

    //printf("inside while2!  \n");
    *(data + i) = val;
    //printf("data[i]: %d\n",*(data + i));
    //printf("val: %d\n", val);
    //printf("====\n");
    ++i;
  }

  //printf("outside while\n");

  return data;
}

void compare(int* data, int length){
  // data[0] = line 1 of txt file...
  for(int i = 0; i < length - 1; ++i){

    if( i == 0){continue;}

    int previous =  *(data + i);
    int current = *(data + i + 1);
    //printf("enter loop iteration %d\n", i);
    if(current - previous != 1){
      // print in form: line number: contents
      printf("%d: %d\n", (i+1), previous); //current
      printf("%d: %d\n",(i+2), current);
    }
  }

  return;
}


int main(int argc, const char* argv[]){

  int current;
  int previous;
  int line_number;

  /*First pass through file*/

  FILE* file = fopen(argv[1], "r");
  //printf("%d\n", length);
  int length = get_size(file);

  int* data = calloc(length, sizeof *data);
  data = grab(file, length);


  /*for(int i = 0; i < length; ++i){
    if(i == 0){ printf("====TESTING COPY====\n");}
    printf("data[%d] = %d\n", i, *(data + i));
  }

  */

  compare(data,length);

  return 0;








}
