#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>
#define MAX_ACTIVIDADES 10000
#define MAX_DEPENDENCIAS 10000

void Seremi(int sig){
  printf("A llegado la autoridad, Se abortan todas las actividades... %d\n", sig);
  (void) signal(2, SIG_DFL);
}

struct Actividad {
    int ID_Actividad;
    char Nombre_Actividad[200];
    int Tiempo;
    int Dependencias[MAX_DEPENDENCIAS];
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
  char linea1[300];
  
  if (archivo!=NULL){
  struct Actividad a[MAX_ACTIVIDADES];
  int cont=0;
    while(fgets(linea, sizeof(linea), archivo)){
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
      a[cont].ID_Actividad=atoi(arr[0]);
      strcpy(a[cont].Nombre_Actividad,arr[1]);
      a[cont].Tiempo=atoi(arr[2]);
        if(arr[3]!=NULL){
            int cont1=0;
              char *token1= strtok(arr[3], ",");
            while(token!=NULL){
              if(cont>0){
              token1= strtok(NULL,",");
              }
              a[cont].Dependencias[cont1]=atoi(token1);
              cont1++;
            }
        }else{
          a[cont].Dependencias[0]=NULL;
        }
      }
      strcpy(a[cont].Dependencias,arr[3]);
      printf("ID: %d\n",a[cont].ID_Actividad);
      printf("Actividad:%s\n",a[cont].Nombre_Actividad);
      printf("Tiempo (m/s): %d\n", a[cont].Tiempo);
      printf("Dependencias:%s\n",a[cont].Dependencias);
      cont++;
    }
    printf("cuantas son:%d\n",cont);
    
  }
  
  
  
  
  
}
