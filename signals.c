#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int sig) {
    if (sig == SIGINT) {
        int fd = open("sigfile.txt", O_CREAT|O_WRONLY|O_APPEND, 0644);
        char *str = "Exit due to SIGINT\n";
        write(fd, str, sizeof(str));
        close(fd);
        exit(0);
    }
    if (sig == SIGUSR1) {
        printf("PID of the Parent: %d\n", getppid());
    }
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while(1) {
        printf("Current PID: %d\n", getpid());
        sleep(1);
    }

    return 0;
}
