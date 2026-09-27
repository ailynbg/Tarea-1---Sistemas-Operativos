#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>

void Seremi(int sig)
{
  printf("A llegado la autoridad, Se abortan todas las actividades... %d\n", sig);
  (void) signal(2, SIG_DFL);
}

int main (int argc, char *argv[]){

if (argc != 3){
fprintf(stderr, "Son Tres Parametros\n");
exit(1);
}

int K = atoi(argv[2]);
char *txt = argv[1];
printf("%d\n",K);


(void) signal(2, Seremi);

}
