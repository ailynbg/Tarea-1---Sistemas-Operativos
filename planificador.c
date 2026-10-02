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
    char Dependencias[200];
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
    //printf("%s\n",linea);
    struct Actividad a;
    char arr[4][200];
    char *token= strtok(linea, ":");
    int seg=0;
      for(int i =0; i<4;i++){
        if(i>0){
        token= strtok(NULL,":");
        }
        if(i==2 && token[0]==' '&&token[1]==' '){
        seg= rand() % 4901 +100;
        sprintf(arr[i],"%d",seg);
        continue;
        }
        strcpy(arr[i],token);
      }
      a.ID_Actividad=atoi(arr[0]);
      strcpy(a.Nombre_Actividad,arr[1]);
      a.Tiempo=atoi(arr[2]);
      strcpy(a.Dependencias,arr[3]);
      printf("ID: %d\n",a.ID_Actividad);
      printf("Actividad: %s\n",a.Nombre_Actividad);
      printf("Tiempo (m/s): %d\n",a.Tiempo);
      printf("Dependencias: %s\n",a.Dependencias);
    }
    
  }
  
  
  
  
  
}
