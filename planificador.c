#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>
#define MAX_ACTIVIDADES 10000
#define MAX_DEPENDENCIAS 100

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
  
  if (archivo!=NULL){
  struct Actividad a[MAX_ACTIVIDADES];
  int cont=0;
  char arr[4][200];
  
    while(fgets(linea, sizeof(linea), archivo)){
    int cont1=0;
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
      
        char *token1= strtok(arr[3], ",");
        while(token1!=NULL){
        a[cont].Dependencias[cont1]=atoi(token1);
        token1= strtok(NULL,",");
        cont1++;
        }
        
      printf("ID: %d\n",a[cont].ID_Actividad);
      printf("Actividad:%s\n",a[cont].Nombre_Actividad);
      printf("Tiempo (m/s): %d\n", a[cont].Tiempo);
      printf("Dependencias:");
      for(int i=0; i<cont1;i++){
      printf("%d\n ",a[cont].Dependencias[i]);
      }
      cont++;
  }
    printf("cuantas son:%d\n",cont);
    
  }
  
}
