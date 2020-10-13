Semana 15 Unidad 5: sistemas operativo
========================================

Hemos llegado a la última estación de este recorrido a través
de la diferentes capas que componen un sistema de cómputo.
Partimos del hardware, desde una compuerta nand, y estamos
por fin en la capa de sistema operativo.

Propósito de aprendizaje
--------------------------

Comprender algunos conceptos básicos de los servicios que ofrece
el sistema operativo a las aplicaciones de usuario y utilizar
algunos de esos servicios en la construcción de aplicaciones
simples.

Código de honor
----------------
Al realizar los ejercicios y el RETO de esta unidad se espera que hagas lo siguiente:

* Colabora con tus compañeros cuando así se indique.
* Trabaja de manera individual cuando la actividad así te lo proponga.
* NO DEBES utilizar sitios en Internet con soluciones o ideas para atacar los RETOS.
* NO DEBES hacer uso de foros para buscar soluciones a los RETOS.
* ¿Entonces qué hacer si no me funciona algo? Te propongo que experimentes, crea hipótesis,
  experimenta de nuevo, observa y concluye.
* NO OLVIDES, este curso se trata de pensar y experimentar NO de BUSCAR soluciones
  en Internet.

Actividades
-------------

Actividad 1
^^^^^^^^^^^^
* Fecha: octubre 13 de 2020 - 8 a.m.
* Descripción: ejercicios de la unidad 5
* Recursos: ingresa al grupo de Teams
* Duración de la actividad: 1 hora 40 minutos de discusión
* Forma de trabajo: colaborativo con solución de dudas en tiempo real.

Ejercicio 1
##############
¿Qué es un sistema operativo?

En términos generales, un sistema operativo es un SOFTWARE que administra
RECURSOS de hardware y software del computador Y provee servicios mediante
los cuales los programas de usuario pueden hacer uso de esos recursos.

Los siguientes ejercicios explorarán algunos servicios que ofrece el sistema
operativo. La exploración la realizaremos de manera práctica para que luego,
puedas profundizar leyendo uno de los tantos excelentes libros de sistemas
operativos. En particular te recomiendo un par:


`Operating System Concepts <https://codex.cs.yale.edu/avi/os-book/OS10/index.html>`__:

.. image:: ./_static/osbook.jpeg
    :scale: 100 %


`Operating Systems: Three Easy Pieces <http://pages.cs.wisc.edu/~remzi/OSTEP/>`__

De todos los posibles servicios que ofrece el sistema operativo, Linux en nuestro
caso, vamos a seleccionar solo algunos que te permitirán resolver posteriormente
el RETO final de esta Unidad.

Ejercicio 2
#############

¿Cómo hacemos para poder realizar varias tareas de manera concurrente
en un programa?

Lo haremos utilizando hilos. En `este <https://drive.google.com/open?id=1I5G4rRNEzmAuOgpEtgDra8TPUTpIPHTXCTwzHF93wHE>`__
enlace encontrarás 4 ejercicios que te mostrarán cómo crear hilos en C, cómo compilar
un programa que tiene hilos, esperar a qué los hilos terminen, cómo lanzar varios hilos
a la vez y esperar a que terminen.

Ejercicio 3
############
Ahora considera que tenemos un sistema compuesto por varios hilos y/o procesos
que interactúan entre ellos para poder lograr un fin. ¿Cómo hacemos para sincronizar
el acceso a los recursos compartidos? ¿Cómo hacemos para sincronizar el funcionamiento
conjunto de las partes?

Para responder estas preguntas a analizar el material en
`este enlace <https://docs.google.com/presentation/d/1EfixM_Svf4z5tO_WYw1K7T2CH7ofUykifvB7b2LTqQk/edit?usp=sharing>`__.

Actividad 2
^^^^^^^^^^^^
* Fecha: octubre 13 a octubre 15.
* Descripción: realiza el reto presentado al final del material
  del ejercicio 3. 
* Recursos: material de esta semana
* Duración de la actividad: 4 horas
* Forma de trabajo: individual

Actividad 3
^^^^^^^^^^^^
* Fecha: octubre 15 de 2020 - 10 a.m.
* Descripción: ejercicios de la unidad 5
* Recursos: ingresa al grupo de Teams
* Duración de la actividad: 1 hora 40 minutos de discusión
* Forma de trabajo: colaborativo con solución de dudas en tiempo real.

Ejercicio 4
############
En este momento ya sabemos cómo hacer varias tareas a la vez,
ya sabemos sincronizar flujos de instrucciones concurrentes. ¿Cómo
podemos hacer para comunicarlos?

En el reto pudiste observar que mediante el uso de archivos pudimos
comunicar dos procesos. Ahora veremos cómo mediante memoria compartida
podemos lograr también comunicar dos procesos.

Primero vamos a analizar con detenimiento 
`este <https://docs.google.com/presentation/d/1kHSjuQ6GBcHGMa1AZAhdzFPdKiCBva3hSNPVwI7cUyA/edit?usp=sharing>`__
material.

Ejercicio 5
##############

El siguiente ejemplo muestra como dos procesos
pueden comunicarse utilizando memoria compartida.

El primer proceso crea la memoria compartida y
escribe información. El segundo proceso la lee
y luego, cuando no se requiere más, la destruye.

Proceso 1:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/mman.h>
    #include <sys/stat.h>        /* For mode constants */
    #include <fcntl.h>           /* For O_* constants */
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>


    #define SH_SIZE 16

    int main(int argc, char * argv[]){

        int shm_fd = shm_open("shm0", O_CREAT | O_RDWR, 0600);
        if (shm_fd < 0) {
            perror("shm memory error: ");
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, "Shared memory is created with fd: %d\n", shm_fd);
        
        if (ftruncate(shm_fd, SH_SIZE * sizeof(char)) < 0) {
            perror("Truncation failed: ");
            exit(EXIT_FAILURE);
        }

        fprintf(stdout, "The memory region is truncated.\n");

        void* map = mmap(NULL, SH_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

        if (map == MAP_FAILED) {
            perror("Mapping failed: ");
            exit(EXIT_FAILURE);
        }

        char* ptr = (char*)map;
        ptr[0] = 'A';
        ptr[1] = 'B';
        ptr[2] = 'C';
        ptr[3] = '\n';
        ptr[4] = '\0';

        fprintf(stdout, "Data is written to the shared memory.\n");

        if (munmap(ptr, SH_SIZE) < 0) {
            perror("Unmapping failed: ");
            exit(EXIT_FAILURE);
        }

        
        if (close(shm_fd) < 0) {
            perror("Closing shm failed: ");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }

Proceso 2:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/mman.h>
    #include <sys/stat.h>        /* For mode constants */
    #include <fcntl.h>           /* For O_* constants */
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>

    #define SH_SIZE 16

    int main(int argc, char * argv[]){

        int shm_fd = shm_open("shm0", O_RDONLY, 0600);
        if (shm_fd < 0) {
            perror("shm memory error: ");
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, "Shared memory is created with fd: %d\n", shm_fd);    

        void* map = mmap(NULL, SH_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

        if (map == MAP_FAILED) {
            perror("Mapping failed: ");
            exit(EXIT_FAILURE);
        }    

        char* ptr = (char*)map;
        fprintf(stdout, "The contents of shared memory object: %s\n", ptr);

    
        if (munmap(ptr, SH_SIZE) < 0) {
            perror("Unmapping failed: ");
            exit(EXIT_FAILURE);
        }

        
        if (close(shm_fd) < 0) {
            perror("Closing shm failed: ");
            exit(EXIT_FAILURE);
        }  
    
        if (shm_unlink("shm0") < 0) {
            perror("Unlink failed: ");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }

Para ejecutar los programas sigue estos pasos:

.. code-block:: c
   :linenos:

    gcc -Wall p1.c -o p1 -lrt
    ./p1

El proceso 1 terminará pero abra dejado la zona
de memoria compartida lista y con datos. Para
verificarlo:

.. code-block:: c
   :linenos:

    ls /dev/shm
    cat /dev/shm/shm0

Ahora compile y ejecute el proceso 2.

.. code-block:: c
   :linenos:

    gcc -Wall p2.c -o p2 -lrt
    ./p2

Actividad 4
^^^^^^^^^^^^
* Fecha: octubre 15 a octubre 20 de 2020.
* Descripción: soluciona el RETO
* Recursos: material de la semana.
* Duración de la actividad: 4 horas
* Forma de trabajo: individual.

RETO
######

Crear un chat entre dos procesos utilizando memoria compartida, hilos y semáforos. 
Cada proceso deberá esperar por la entrada de su usuario y al mismo tiempo ser
capaz de mostrar los mensajes enviados por el otro usuario (es por ello que se 
requieren dos hilos por proceso).

El intercambio de mensajes se debe realizar utilizando memoria compartida y
semáforos para la sincronización. Se debe señalizar dos momentos: hay un mensaje y
ya se puede escribir un nuevo mensaje.

Rúbrica de evaluación
#######################
En `este <https://docs.google.com/spreadsheets/d/1qrzERyqYGGdlXWvq39w2pskB3wbaQ72XGHkGMB9u-U0/edit?usp=sharing>`__
enlace encontrarás la rúbrica de evaluación del RETO de la unidad.

No olvides diligenciar la AUTOEVALUACIÓN y sustentar, en la columna de observaciones,
cada NOTA que te asignes.

RECUERDA el código de HONOR.

¿Qué debes entregar?
#####################

Comprime una carpeta en formato .ZIP con lo siguiente:

#. Un pdf con la explicación de la arquitectura de tu solución: qué partes tiene, 
   por qué son necesarias (¿Qué pasa si no las usaras?, cómo están relacionadas 
   esas partes, qué función cumplen en la solución. RECUERDA, no se trata de explicar el código, se trata 
   de explicar cómo solucionaste, conceptualmente hablando,  el problema.
#. Archivos .c y .h con los programas.
#. Un pdf con el paso a paso de los comandos utilizados para compilar y ejecutar los 
   programas.

¿Cuándo y dónde entregar?
###########################
#. Debes realizar la entrega de tu trabajo el 22 de octubre antes de la clase.
#. Sube tu carpeta comprimida en formato .ZIP `aquí <https://auladigital.upb.edu.co/mod/assign/view.php?id=655821>`__.
