#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>

void Seremi(int sig){
  printf("A llegado la autoridad, Se abortan todas las actividades... %d\n", sig);
  (void) signal(2, SIG_DFL);
}

struct Actividad {
    int ID_Actividad;
    char Nombre_Actividad[200];
    int Tiempo;
    int Dependencias[200];
};

int main (int argc, char *argv[]){

  if (argc != 3){
  fprintf(stderr, "Son Tres Parametros\n");
  exit(1);
  }

  int K = atoi(argv[2]);
  char *txt = argv[1];
  printf("El maximo de actividades simultaneamente es %d\n",K);

  (void) signal(2, Seremi);
  
  FILE* archivo = fopen(txt, "r");
  char linea[300];
  
  if (archivo!=NULL){
    while(fgets(linea, sizeof(linea), archivo)){
    
    struct Actividad a;
    char *token= strtok(linea, ":");
    printf("%s\n",token);
    a.ID_Actividad=atoi(token);
    
    }
    
  }
  
  
  
  
  
}
