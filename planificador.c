#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>
#include <sys/wait.h>
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
    int contar;
    pid_t pid;
    int pipefd[2];
    int fase;
    //terminado 0
    //fallo -1
    //ejecucion 1
    //wait 2
};

void procesos(struct Actividad a[],int cant, int i){
pid_t t=fork();
  if(t>0){
  a[i].pid=t;
  a[i].fase=1;
  }else if(t==0){
  
  if(a[i].contar > 0){
    char string[100];
    for(int j = 0; j < a[i].contar; j++){
    read(a[i].pipefd[0],string,sizeof(string));
    printf("Actividad %d recibió: %s\n",a[i].ID_Actividad,string);
    }
  }
  sleep(a[i].Tiempo/1000);
  char string[100];
  for(int i=0; i<cant; i++){// actividades
    for(int j=0; j<a[i].contar; j++){//dependencias
      if(a[i].Dependecias[j]==a[i].ID_Actividad){
        write(a[i].pipefd[1],string,strlen(string);
      };
      break;
    }
  }
  exit(0);
  }
}
  

int actividadbuscar( struct Actividad a[], int cant, int id){
  for(int i=0;i<cant; i++){
      if(a[i].ID_Actividad==id){
        return i;
      }
    }return -1;
} //manda la posicion


int estado(struct Actividad a[], int cant, int n){
 for(int i =0; i<a[n].contar;i++){
  int m= actividadbuscar(a,cant,a[n].Dependencias[i]); //LA posicion de la dependencia
  if(a[m].fase!=0){//fase de la dependencia 

    return 0;//la funcion no se ejecuta
  }
    
 }return 1;//se ejecuta 
}

void revision(struct Actividad a[], int cant, int k, int *conteo){
  for(int i=0; i<cant;i++){
  if(k<*conteo){
  return;}
  if(a[i].fase==2&& estado(a,cant, i)==1){//revisa en las actividades, cual estan en wait y si se puede ejecutar o no)
    procesos(a,cant,i);
    *conteo++;
  }
  }
}


int main (int argc, char *argv[]){

  if (argc != 3){
  fprintf(stderr, "Son Tres Parametros\n");
  exit(1);
  }

  int K = atoi(argv[2]);
  int conteo=0;
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
    char *token= strtok(linea, ":");
    int seg=0;
    int cont1=0;
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
        a[cont].contar=cont1;
        }
        a[cont].fase=2;
        
      printf("ID: %d\n",a[cont].ID_Actividad);
      printf("Actividad:%s\n",a[cont].Nombre_Actividad);
      printf("Tiempo (m/s): %d\n", a[cont].Tiempo);
      printf("Dependencias:");
      for(int i=0; i<cont1;i++){
      printf("%d\n",a[cont].Dependencias[i]);
      }
      cont++;
  }
    for(int i=0; i<cont; i++){
    pipe(a[i].pipefd);}
    //sale del while
    revision(a, cont, K,&conteo);
    
  }
  
}
