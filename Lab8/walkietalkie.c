#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

//the variable "user" is an option on the command line
//the variable "myfifo" will be the name of the fifo in the file system that is created
//the variable "myrecording" will store the name of the file that stores the  conversation
//the array "theargs" passes the previous variables to other processes
char  *user;
char  myfifo[50];
char  myrecording[50];
char  *theargs[5];
FILE  *conversation;

int main (int argc, char *argv[])
{

// clear the screen
  system("clear");

// test to see if an option has been put on the command line
  if (argc<3)
  {
    printf("USAGE: \"walkietalkie user-name fifo-name recording-name\"\n");
    exit(1);
  }

// set "user" from the first the command line option
// set "myrecording" to a file stored in your "HOME" directory with a suffix ".recording"
// set "myfifo" to a file stored in the /tmp/ directory with a suffix ".fifo"
  user=argv[1];
  strcat(myrecording,getenv("HOME"));
  strcat(myrecording, "/");
  strcat(myrecording, argv[3]);
  strcat(myrecording, ".recording");
  strcat(myfifo, "/tmp/");
  strcat(myfifo, argv[2]);
  strcat(myfifo, ".fifo");
  printf("%s, %s, %s\n", user, myfifo, myrecording);

//then populate the array "theargs" with values to be passed
  theargs[0]="./listen";
  theargs[1]=user;
  theargs[2]=myfifo;
  theargs[3]=myrecording;
  theargs[4]=NULL;

//if the ".recording" file specified exists, these commands will replace it with an empty file
  conversation=fopen(myrecording,"w");
  fclose(conversation);

// Greet the user and issue a warning regarding the recording 
  printf("Hello %s\n", user);
  printf("your fifo is %s\n", myfifo);
  printf("WARNING: This Conversation WILL be recorded to %s\n\n\n", myrecording);

// replace, in memory using execvp, this program "walkietalkie" with the program "listen"
// WITHOUT using a fork and pass all variables
// the default state of the "walkie-talkie" is listening!!!
  execvp(theargs[0], theargs);
}
