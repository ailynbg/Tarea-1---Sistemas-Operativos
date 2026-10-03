# Tarea-1-Sistemas-Operativos
Para este trabajo se realizaron algunas funciones que ayudaron a facilitar el uso del programa, a continuación se explicara cada una de ellas:

Seremi(): Funcion utilizada para llamar a una syscall de interrupción con las teclas Ctrl+C, el objetivo es que el programa aborte la ejecución de inmediato, esta fue aplicada hacia los procedimientos hijos, para que no se produzcan procesos huerfanos.

Procesos(): Esta función es para asociar los datos a procedimientos, mediante los procesos hijos, y poder determinar el estado en el que se encuentra, en este se ocuparon pipes para la comunicación entre procedimientos, poder avisar cuando uno se termina, y el dependiente pueda ejecutarse, usando write y read. Se realizo una prueba de falla con el nodo 5, actualmente esta oculto, pero funciona.

estado(): Para esta funcion se llamo la funcion actividadbuscar() que prontamente se hablara de ella, para esta se extrajo la posicion de la id de la que depende la actividad a buscar, en base a esto se reviso con .fase si estaba terminada, en falla o se ejecutaba.

revision(): Esta es una de las mas importantes ya que nos permite poder revisar si se puede avanzar con ese procedimiento o aun no, en esta funcion se realiza un conteo de los procedimientos que entran a ejecutar, para poder usarlo en otra funcion como restriccion.

waitprocess(): Aqui tenemos el sitio de espera de los procesos, se decide si pasan o aun no, ya que estos ven si los ya ejecutados se finalizan, tambien se ocupa el conteo pero al contrario, ya que se van disminuyendo a medida que salen.

int main(): Aqui es donde se realiza lo principal, ya que se realiza parseo en .txt, sacando linea por linea y luego separando y extrayendo cada informacion para cada variable. Tambien se inician las pipes y se llaman las funciones a seguir para luego de finalizadas las pipes se cierren.

Para poder ejecutarlo ya con un plan.txt y dentro de la carpeta con el código descargado se coloca: <br>
gcc -Wall -Wextra -std=c17 planificador.c -o planificador
./planificador plan.txt K (K cualquier numero que desee limitar al programa)

DISEÑO DEL PROGRAMA<br>

Para el trabajo se ocuparon diferentes comandos, variables y funciones, algunos son:
fork(): Para poder ejecutar cada actividad sea un proceso independiente
pipes(): poder tener comunicacion entre hijos y padre para avisar el termino de la ejecucion.
revision(): Esto decide la actividad a ejecutar sin pasarse del limite implementado.
Actividad: Para poder organizar de mejor manera el arreglo de actividades.
Fase(): Fue diseñado para tener un orden con los que terminaban, tenian fallas o estaban en ejecucion.
strlok(): Para poder separar a distintas variables a ocupar como dependencias.
