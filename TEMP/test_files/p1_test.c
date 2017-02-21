#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    pid_t own_pid = getpid();

    int x = set_tag(own_pid, 0x2);

    int y = get_tag(own_pid);

    printf("set_tag: %d\n", x);
    printf("get_tag: %d\n", y);

    return 0;
}