#include <unistd.h>
#include <stdio.h>

int main() {

  int euid = geteuid();

  if(euid !=0){return -1;}

  printf("==========TESTING AS NON ROOT USER: \n");
  seteuid(1000);
  printf("\n");
  printf("get_tag() should = -1: %d\n ", get_tag(5));
  printf("get_tag() should = 0: %d\n ", get_tag(getpid()));
  printf("get_tag() should = -1: %d\n ", get_tag(10000));

  printf("set_tag(): should = -1 %d\n ", set_tag(5, 1)); // fails as not root
  printf("set_tag(): should = -1 %d\n ", set_tag(5, -1)); // fails as new_value is < 0
  printf("set_tag(): should - -1 %d\n ", set_tag(getpid(), 1)); // fails because not root
  printf("set_tag(): should = -1 %d\n ", set_tag(10000,1)); // fails because is big ass number

  printf("==========TESTING AS ROOT USER: \n");
  seteuid(0);
  printf("\n");
  printf("get_tag(): should = 0 %d\n ", get_tag(5));
  printf("get_tag(): should = 0 %d\n ", get_tag(getpid()));
  printf("get_tag(): should = -1 %d\n ", get_tag(10000));

  printf("set_tag(): should = 0 %d\n ", set_tag(5, 1)); // passes
  printf("set_tag(): should = -1 %d\n ", set_tag(5, -1)); // fails as new_value is < 0
  printf("set_tag(): should = 0 %d\n ", set_tag(getpid(), 1)); // passes
  printf("set_tag(): should = -1 %d\n ", set_tag(10000,1)); // fails because is big ass number

  return 0;
}
