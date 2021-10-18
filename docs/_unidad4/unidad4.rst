Unidad 4. Sistema operativo
============================

Introducción
--------------

Hemos llegado a la última estación de este recorrido a través
de las diferentes capas que componen un sistema de cómputo.
Partimos del hardware, desde una compuerta nand, y estamos
por fin en la capa de sistema operativo.

Propósito de aprendizaje
**************************

Comprender algunos conceptos básicos de los servicios que ofrece
el sistema operativo a las aplicaciones de usuario y utilizar
algunos de esos servicios en la construcción de aplicaciones
simples.

Lecturas y ejercicios
------------------------
 
Sesión 1: concepto de proceso e hilos
***************************************

Ejercicio 1: concepto de sistema operativo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué es un sistema operativo?

En términos generales, un sistema operativo es un SOFTWARE que administra
RECURSOS de hardware y software del computador Y provee servicios mediante
los cuales los programas de usuario pueden hacer uso de esos recursos.

Los siguientes ejercicios explorarán algunos servicios que ofrece el sistema
operativo. La exploración la realizaremos de manera práctica para que luego,
puedas profundizar leyendo uno de los tantos excelentes libros de sistemas
operativos. En particular te recomiendo este:

`Operating Systems: Three Easy Pieces <http://pages.cs.wisc.edu/~remzi/OSTEP/>`__

De todos los posibles servicios que ofrece el sistema operativo, Linux en nuestro
caso, vamos a seleccionar solo algunos que te permitirán resolver posteriormente
la evaluación de esta Unidad.

Ejercicio 2: preguntas sobre los conceptos básicos de los procesos 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vamos a discutir juntos estas preguntas:

* ¿Cuál es la diferencia entre un programa y un proceso?
* ¿Puedo tener múltiples procesos corriendo el mismo programa?
* ¿Para qué sirve el stack de un proceso?
* ¿Para qué sirve el heap de un proceso?
* ¿Qué es la zona de texto de un proceso?
* ¿Dónde se almacenan las variables globales inicializadas?
* ¿Dónde se almacenan las variables globales no inicializadas?
* ¿Cuáles son los posibles estados de un proceso en general? Ten en cuenta
  que esto varía entre sistemas operativos.

Ejercicio 3: concepto de hilo 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Vamos al tablero para introducir el concepto general de hilo.

Ejercicio 4: creación de hilos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vamos a crear un hilo en Linux:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>

    void* imprime_x(void *param){
        while(1) printf("x");
        return NULL;
    }


    int main(int argc, char *argv[]){
        pthread_t threadID;
        pthread_create(&threadID,NULL,&imprime_x,NULL);
        while(1) printf("o");
        exit(EXIT_SUCCESS);
    }

Compila el código así:

.. code-block:: bash

    gcc -Wall main.c -o main -lpthread

Ejecuta el código como siempre, pero esta vez para terminar el programa debes enviar 
la señal ``CRTL+C`` a la terminal.

Ejecuta en la terminal: 

Ejercicio 5: análisis de código con hilos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora vas a escribir este código, compilarlo y ejecutarlo:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>

    struct threadParam_t
    {
        char character;
        int counter;
    };


    void* imprime(void *parg){
        struct threadParam_t *pargTmp = (struct threadParam_t *)parg;
        for(int i = 0; i < pargTmp->counter;i++){
            printf("%c",pargTmp->character);
        }
        return NULL;
    }


    int main(int argc, char *argv[]){
        pthread_t threadID1;
        pthread_t threadID2;

        struct threadParam_t threadParam1 = {'a',30000};
        struct threadParam_t threadParam2 = {'b',20000};

        pthread_create(&threadID1,NULL,&imprime, &threadParam1);
        pthread_create(&threadID2,NULL,&imprime, &threadParam2);

        exit(EXIT_SUCCESS);
    }

* ¿Qué pasó al ejecutarlo? 
* Notaste que el programa no hace nada, te animas a proponer un hipótesis 
  al respecto de lo que puede estar ocurriendo?

Ejercicio 6: esperar un hilo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El problema con el código anterior es que el proceso está terminando antes 
que los hilos puedan comenzar incluso a funcionar. Por tanto, será necesario 
que el hilo principal espere a que los dos hilos creados terminen antes de 
que el pueda terminar. 

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>

    struct threadParam_t
    {
        char character;
        int counter;
    };


    void* imprime(void *parg){
        struct threadParam_t *pargTmp = (struct threadParam_t *)parg;
        for(int i = 0; i < pargTmp->counter;i++){
            printf("%c",pargTmp->character);
        }
        return NULL;
    }


    int main(int argc, char *argv[]){
        pthread_t threadID1;
        pthread_t threadID2;

        struct threadParam_t threadParam1 = {'a',30000};
        struct threadParam_t threadParam2 = {'b',20000};

        pthread_create(&threadID1,NULL,&imprime, &threadParam1);
        pthread_create(&threadID2,NULL,&imprime, &threadParam2);

        pthread_join(threadID1,NULL);
        pthread_join(threadID2,NULL);

        exit(EXIT_SUCCESS);
    }

* ¿Qué debes hacer para esperara a que un hilo en particular termine?
* Considera los siguientes fragmentos de código y piensa cuál puede ser la 
  diferencia entre ambos:

.. code-block:: c

    pthread_create(&threadID1,NULL,&imprime, &threadParam1);
    pthread_join(threadID1,NULL);
    pthread_create(&threadID2,NULL,&imprime, &threadParam2);
    pthread_join(threadID2,NULL);


.. code-block:: c

    pthread_create(&threadID1,NULL,&imprime, &threadParam1);
    pthread_create(&threadID2,NULL,&imprime, &threadParam2);
    pthread_join(threadID1,NULL);
    pthread_join(threadID2,NULL);


Trabajo autónomo 1: RETO con hilos
***************************************
(Tiempo estimado: 10 horas 20 minutos)

Vas a revisar de nuevo todo el material de la sesión 1 y luego 
trabaja en el siguiente reto.

Se tiene un archivo de entrada que posee por línea 3 cadenas de caracteres
separadas por espacios así:  nombre ocupación edad. 
Nombre y ocupación son cadenas de caracteres que representan texto mientras 
que edad representa valores numéricos. Se tendrán máximo 100 líneas y 
20 caracteres máximo por cadena.

* Crea un programa llamado prog.c que lea el archivo de entrada, luego debe organizar la información
  en una estructura de datos, luego debe IMPRIMIR en pantalla el contenido de la estructura de datos.
  OJO no del archivo, sino de la información cargada en la estructura de datos proveniente del archivo.
  
* Crea 2 hilos para procesar de diferente manera la información. Los hilos deben lanzarse para que se ejecuten
  en paralelo, OJO, NO DE MANERA SECUENCIAL, SI EN PARALELO.

* El Hilo 1 escribe en el archivo de salida1 los registros del archivo de entrada, pero en orden
  inverso, es decir, primero el último y de último el primero.

* El Hilo 2 escribe en el archivo de salida 2 los registros ordenados por ocupación en orden alfabético.

* NO OLVIDES Hilo 1 e Hilo 2 deben lanzarse a la vez. Una vez Hilo 1 e Hilo 2 finalicen, el hilo 
  principal debe abrir los archivos de salida e imprimir el resultado, primero del Hilo 1 y luego del 
  Hilo 2

* El programa se ejecutará así: ./prog In Out1 Out2

* prog es el nombre del ejecutable, In especifica el nombre del archivo de entrada
  Out1 y Out2 especifican el nombre de los los archivos de salida 1 y 2 respectivamente. RECUERDA que
  In, Out1 y Out2 son parámetros.

Sesión 2: relación de conceptos
***********************************

Ejercicio 7: veamos cómo es en C#
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora vamos a familiarizarnos con el concepto de hilo en C#. Ingresa 
a `este <http://www.albahari.com/threading/>`__ sitio y lee detalladamente
su contenido hasta la sección Creating and Starting Threads (sin incluirla,
claro, a menos que quieras).

* ¿Qué es un hilo?
* ¿Cuál es la diferencia entre un método y un hilo?
* ¿La ejecución de los hilos es determinística?
* ¿Cuál es la diferencia entre un método estático y un
  método no estático?
* ¿Cuál es la diferencia entre un hilo y un método estático?

Ejercicio 8: comunicación de procesos mediante colas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Existe varios mecanismos de comunicación entre procesos. En este ejercicio
te voy a proponer que analices uno llamado System V message queues (Colas 
de mensajes System V).

* Las colas de mensajes son de tamaño fijo → Las comunicaciones ocurren por 
  paquetes o unidades de mensaje.

* Cada mensaje incluye un tipo entero. Esto permite seleccionar el mensajes a leer. Esto 
  quiere decir que puedes enviar a una cola varios tipos de mensajes y seleccionar
  cuál tipo quieres leer. Podrías entonces tener un proceso enviando mensajes de varios 
  tipos y otros procesos lectores consumiendo solo el mensaje de su interés. 
  UNA BELLEZA!!!

* Las colas de mensajes existen a nivel de sistema, no son de un proceso en particular. 

Ejercicio 9: creación de colas
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para crear una cola de mensajes utilizas el siguiente llamado al sistema:

.. code-block:: c

    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/msg.h>

    int msgget(key_t key, int msgflg);

Nota que debes definir el valor de key y msgflg. Estos dos parámetros te permitirán 
crear un identificador para la cola, solicitar la creación y adicionar mensajes.

Infortunadamente no tenemos el tiempo para profundizar en cada detalle de la función. 
Por tanto, vamos a utilizar los siguientes pasos para crear la cola en un proceso y luego 
conectarse a ella en otro proceso:

.. code-block:: c

    system("touch msgreq.txt");
    
    key_t key;
    
    if ((key = ftok("msgreq.txt", 'B')) == -1) {
        perror("ftok");
        exit(1);
    }
    
    int reqMsgId;

    if ((reqMsgId = msgget(key, PERMS | IPC_CREAT)) == -1) {
        perror("msgreq msgget fails");
        exit(1);
    }

Ejercicio 10: destrucción de colas
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Una vez termines de utilizar la cola puedes destruirla del sistema operativo 
con la función ``msgctl``. Ten presente que esta destrucción la debería realizar 
el último proceso que haga uso de ella.

.. code-block:: c

    system("rm msgreq.txt");

    if (msgctl(reqMsgId, IPC_RMID, NULL) == -1) {
        perror("msgreq msgctl fails");
        exit(1);
    }

Ejercicio 11: enviar mensajes
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora que ya sabes crear la cola, obtener el identificador de ella y destruirla, 
vas a aprender a enviar usando el llamado al sistema ``msgsnd`` 

.. code-block:: c

    typedef struct _msgbuf {
        long mtype;
        char mtext[64];
    }MsgBuf;

    MsgBuf resBuf;

    len = strlen("Hola") + 1; // por qué + 1?
    strncpy(resBuf.mtext,"Hola",len);
    resBuf.mtype = 1111; //
    if (msgsnd(resMsgId, &resBuf, len, 0) == -1){
        perror("msgsnd fails: ");  
    }

Ejercicio 12: recibir mensajes
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para recibir mensajes usas ``msgrcv``.

.. code-block:: c

    typedef struct _msgbuf {
        long mtype;
        char mtext[64];
    }MsgBuf;

    MsgBuf reqBuf;

    if (msgrcv(reqMsgId, &reqBuf, sizeof(reqBuf.mtext), 0, 0) == -1) {
        perror("msgrcv fails");
    }

Trabajo autónomo 2: repaso y ejemplo
*****************************************
(Tiempo estimado: 2 horas 20 minutos)

Ejercicio 13: ejemplo
^^^^^^^^^^^^^^^^^^^^^^^

Analiza la documentación y el ejemplo de 
`este <https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_message_queues.htm>`__ 
sitio.

Evaluación de la Unidad 4
----------------------------
(Tiempo de la semana 15: 8 horas)
(Tiempo de la semana 16: 12 horas)


Enunciado
*************
Te voy a proponer un RETO interesante para esta evaluación que podrás 
resolver en equipo máximo de 3 de personas.

Problema 
^^^^^^^^^^^

Vas a construir dos aplicaciones que llamaremos servidor y cliente. Solo 
tendrás una instancia del servidor, pero una hasta 3 clientes.
El servidor podrá publicar hasta 6 EVENTOS. Los clientes le manifestarán de manera explícita 
al servidor su interés en algunos eventos específicos; sin embargo, en un momento dado,
también podrán indicarle que ya no están interesados en algunos en particular. 
Por cada evento, el servidor mantendrá una lista de interesados que irá cambiando 
a medida que entran y salen interesados. Al generarse un evento en el servidor, 
este publicará a todos los interesados. 

Para desplegar las aplicaciones, lanzarás el servidor y cada cliente en una terminal 
para cada uno. No olvides hacer pruebas con los 3 clientes.

Estas son las características a implementar en el servidor:

El servidor :

* Debe recibir commandos desde la línea de comandos y al mismo tiempo debe 
  ser capaz de escuchar las peticiones de los clientes.
* Cada petición de un cliente será visualizada con un mensaje 
  en la terminal.
* Los comandos que recibirá el servidor son: 

  * exit: termina el servidor y deberá publicar este evento a TODOS los clientes.
  * add event_name: adiciona el evento event_name.
  * remove event_name: elimina el evento event_name.
  * trigger event_name: publica el evento event_name.
  * list event_name: lista todos los clientes suscritos a event_name.
  * all: muestra todos los eventos y todos los clientes.

Estas son las características a implementar en el cliente:

* El cliente debe visualizar en la terminal cada que sea notificado de un evento.
* El cliente debe soportar los siguientes comandos:

  * sub event_name: se suscribe al evento event_name
  * unsub event_name: se desuscribe del evento event_name
  * list: lista todos los eventos a los cuales está suscrito.
  * ask: le pregunta al servidor cuáles eventos hay disponibles.

¿Qué debes entregar?
***************************

Diligencia y entrega en este `enlace <https://forms.office.com/r/ks9RbJ4RQJ>`__.

En el formulario anterior te voy a solicitar evidenciar el código con la solución 
y un video con la sustentación.

Con respecto al código:
  
#. Debe estar bajo control de versión en GitHub
#. SOLO debes tener tres archivos: server.c, client.c, readme.txt.
#. El archivo readme.txt debe indicar cómo compilar cada archivo y
   cómo se debe lanzar cada programa.

Con respecto al video:

#. El video DEBE TENER una duración ``MÁXIMA`` de 15 minutos.
#. En `este video <https://youtu.be/6-0cERIVsFg>`__ puedes aprender a adicionar 
   capítulos a tu video.
#. El video debe tener los siguientes capítulos en este mismo orden:

   * Imagen con los integrantes y qué aportes realizó cada uno.
   * Demostración de la solución.
   * Explicación conceptual de la solución.
   * Explicación del código con la implementación.

Con respecto a la demostración:

#. Demostrar add event_name: 0.25
#. Demostrar exit: 0.25
#. Demostrar remove event_name: 0.25
#. Demostrar trigger event_name: 0.25
#. Demostrar list event_name: 0.25
#. Demostrar all: 0.25
#. Demostrar sub event_name: 0.25
#. Demostrar unsub event_name: 0.25
#. Demostrar list: 0.25
#. Demostrar ask: 0.25


Con respecto a la explicación conceptual responde 
estas preguntas:

#. Explica en general la estructura del código con tu solución: 0.2
#. ¿Cómo es la arquitectura de cada aplicación? : 0.2
#. ¿Cómo resolviste el problema de escuchar comandos y a la vez estar 
   pendiente de las comunicaciones en cada proceso? : 0.2
#. ¿Cómo le comunicas a cada cliente interesado acerca de un evento?  : 0.2
#. ¿Cómo solucionaste el problema de tener hasta 3 clientes : 0.2
   que se suscriben y desuscriben a un evento? : 0.2
#. ¿Cómo implementaste la lista de interesados? : 0.2
#. ¿Cómo añades y remueves interesados de la lista? : 0.2
#. Si en el servidor remueve un evento y el cliente ejecuta el comando list 
   ¿Cómo solucionaste una posible inconsistencia? : 0.2
#. Cuando el cliente ejecuta el comando ask ¿Cómo haces para preguntarle 
   al server? : 0.2
#. Cuando el server ejecuta el comando exit cómo resolviste el problema 
   de poder también terminar a los clientes? : 0.2


Criterios de evaluación
****************************

* Calidad y duración máxima del video, repositorio en Github: 0.5
* Solución del problema: 2.5
* Sustentación: 2.  

.. note:: Sobre las personas reportadas

    Las personas que aparezcan reportadas indicando que no trabajaron obtendrán automáticamente 
    una calificación de 0.
