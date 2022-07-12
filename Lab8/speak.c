

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>


char *theargs[5];
char *myfifo;
char *myrecording;
char *user;
FILE *recorded;
struct sigaction mysignal;
int fdr;



void ctrlc()
{
	printf("\nControl c disabled while speaking\n");
	printf("enter ur message. (hit [Enter] to continue):\n");		

}


void ctrlz()
{
	printf("\nControl z disabled while speaking\n");
	printf("enter ur message. (hit [Enter] to continue):\n");	

}


void listen()
{
	execvp(theargs[0], theargs);
}

 int main(int argc, char *argv[])
{

	signal(SIGINT, ctrlc);
	signal(SIGTSTP, ctrlz);
	char message[80];

	user = argv[1];
	myfifo = argv[2];
	myrecording = argv[3];

	theargs[0] = "./listen";
	theargs[1] = user;
	theargs[2] = myfifo;
	theargs[3] = myrecording;
	theargs[4] = NULL;

	mysignal.sa_handler=listen;
	mysignal.sa_flags = SA_NODEFER |SA_RESETHAND ;
 	sigaction(SIGQUIT, &mysignal, NULL);


	while (1)
	{
		printf ("\nenter ur message. (hit [Enter] to send message):\n");

		fdr = open(myfifo,O_WRONLY);
		fgets(message, 80, stdin);
		write(fdr, message, strlen(message)+1);
		close(fdr);

		recorded = fopen(myrecording, "a");
		fprintf(recorded, "%s\n", message);
         	fclose(recorded);
		printf("sending %s -> %s", user, message);
		listen();

	}
}

