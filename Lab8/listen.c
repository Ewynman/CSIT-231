#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>


// myfifo contains the identifying part of the file name for my fifo
// myrecording contains the identifying part of the file name for recording the conversation
// recorded will contain the entire name of the file that records the conversation
// user is who is speaking or listening
// homedir contains your "HOME" directory and is retrieved by the "getenv()" call
// the array "theargs" passes the previous variables to other processes
// message is what the user has typed
// fdr is the file descriptor of the reading side of the fifo
// mysignal is a struct containing defining properties of a sigaction
char *myfifo;
char *myrecording;
FILE *recorded;
char *user;
char *homedir;
char *theargs[5];
char  message[80];
int   fdr;
struct sigaction mysignal;


// tospeak is the function that switches from reading to speaking
void tospeak ()
{
  execvp(theargs[0], theargs);
}  


int main (int argc, char *argv[])
{
// initialize meaningful variable names from passed arguments
// then populate the parameter array "theargs"
  user=argv[1];
  myfifo=argv[2];
  myrecording=argv[3];

  theargs[0]="./speak";
  theargs[1]=user;
  theargs[2]=myfifo;
  theargs[3]=myrecording;
  theargs[4]=NULL;


// then use sigaction to change CTRL-\'s nature
  mysignal.sa_handler=tospeak;
  mysignal.sa_flags = SA_NODEFER |SA_RESETHAND ;
  sigaction(SIGQUIT, &mysignal, NULL);

// create or open the fifo in RDONLY mode, since this is the "listening" program
// it is its default state and continually loops
// fdr is set to the reading side of the fifo and the message is read from it
// the message is echoed back and then the file descriptor "fdr" is closed
  while (1) 
  { 
    printf("\nReading Messages Sent to me:\n");
    printf("\nPress CTRL-\\ to send a message\n");
    mkfifo(myfifo, 0660);
    fdr = open(myfifo,O_RDONLY); 
    read(fdr, message, 80); 
    printf("%s", message); 
    close(fdr);

//The following lines write the "message" to your ".recording" file
    recorded=fopen(myrecording,"a");
    fprintf(recorded, "%s\n", message);
    fclose(recorded);
  }
}
