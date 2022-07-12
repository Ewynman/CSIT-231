#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

int main (int argc, char **argv){
    //Parent PID
    int popeyePID;
    //NEwpews PID and Number
    int peepeyePID, pupeyePID, pipeyePID, poopeyePID;
    int peepeyeNum, pupeyeNum, pipeyeNum, poopeyeNum;
    char *peepeye[4], *pupeye[4], *pipeye[4], *poopeye[4];
    //Newpew PPID
    int peepeyePPID, pupeyePPID, pipeyePPID, poopeyePPID;

    //Random Num
    int rannum = 0;
    time_t t1;
    srand((unsigned)time(&t1));

    //int to string variables
    char num1[12];
    char num2[12];
    char num3[12];
    char num4[12];

    int status, wstatus, ret;
    //random Number 4 - 10
    peepeyeNum = rand() % 10;
    while (peepeyeNum < 4)
    {
        peepeyeNum = rand() %10;
    }
    pupeyeNum = rand() % 10;
    while(pupeyeNum < 4)
    {
	pupeyeNum = rand() % 10;
    }
    pipeyeNum = rand() % 10;
    while (pipeyeNum < 4)
    {
        pipeyeNum = rand() %10;
    }
    poopeyeNum = rand() % 10;
    while (poopeyeNum < 4)
    {
        poopeyeNum = rand() %10;
    }

    sprintf(num1, "%i", peepeyeNum);
    sprintf(num2, "%i", pupeyeNum);
    sprintf(num3, "%i", pipeyeNum);
    sprintf(num4, "%i", poopeyeNum);

    peepeye[0] = "./nephew";
    peepeye[1] = "Peepeye";
    peepeye[2] = num1;
    peepeye[3] = NULL;

    pupeye[0] = "./nephew";
    pupeye[1] = "Pupeye";
    pupeye[2] = num2;
    pupeye[3] = NULL;

    pipeye[0] = "./nephew";
    pipeye[1] = "Pipeye";
    pipeye[2] = num3;
    pipeye[3] = NULL;

    poopeye[0] = "./nephew";
    poopeye[1] = "Poopeye";
    poopeye[2] = num4;
    poopeye[3] = NULL;
    //Clear the screen and prints the start message
    system("clear");
    printf("\nRacers to the starting line\n");
    sleep(3);
    printf("On your marks....Get Set....GO!\n");
    sleep(3);
    system("clear");
    //Forking
    popeyePID = fork();
    if (popeyePID == 0){
        peepeyePID = getpid();
        peepeyePPID = getppid();

        execvp("./nephew", peepeye);
        while(wait(&status) != popeyePID);
    }
    if (popeyePID > 0){
        peepeyePID = getpid();
        peepeyePPID = getppid();
    }
    if (popeyePID < 0){
        perror("My PID is less than zero in the fork()");
    }
    //forking 2
    popeyePID = fork();
    if (popeyePID == 0){
        pupeyePID = getpid();
        pupeyePPID = getppid();

        execvp("./nephew", pupeye);
        while(wait(&status) != popeyePID);
    }
    if (popeyePID > 0){
        peepeyePID = getpid();
        peepeyePPID = getppid();
    }
    if (popeyePID < 0){
        perror("My PID is less than zero in the fork()");
    }
    //fork 3
    popeyePID = fork();
    if (popeyePID == 0){
        peepeyePID = getpid();
        peepeyePPID = getppid();

        execvp("./nephew", pipeye);
        while(wait(&status) != popeyePID);
    }
    if (popeyePID > 0){
        peepeyePID = getpid();
        peepeyePPID = getppid();
    }
    if (popeyePID < 0){
        perror("My PID is less than zero in the fork()");
    }
    //fork 
    popeyePID = fork();
    if (popeyePID == 0){
        peepeyePID = getpid();
        peepeyePPID = getppid();

        execvp("./nephew", poopeye);
        while(wait(&status) != popeyePID);
    }
    if (popeyePID > 0){
        peepeyePID = getpid();
        peepeyePPID = getppid();
    }
    if (popeyePID < 0){
        perror("My PID is less than zero in the fork()");
    }
}
