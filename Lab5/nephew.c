#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char **argv){
    int raceWait;

    raceWait = atoi(argv[2]);
    sleep(raceWait);
    printf("----------------------------------------------");
    printf("\n%s ", argv[1]);
    printf("Finished in %i seconds\n", raceWait);
    printf("My PID is: %i\n", getpid());
    printf("My Uncle Popeye's id is: %i\n", getpid());
    printf("-----------------------------------------------");
    exit (0);
}
