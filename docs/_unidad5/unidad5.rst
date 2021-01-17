Unidad 5. Sistema operativo
============================

Introducción
--------------

Hemos llegado a la última estación de este recorrido a través
de la diferentes capas que componen un sistema de cómputo.
Partimos del hardware, desde una compuerta nand, y estamos
por fin en la capa de sistema operativo.

Propósito de aprendizaje
^^^^^^^^^^^^^^^^^^^^^^^^^^

Comprender algunos conceptos básicos de los servicios que ofrece
el sistema operativo a las aplicaciones de usuario y utilizar
algunos de esos servicios en la construcción de aplicaciones
simples.

Temas
^^^^^^

Trayecto de actividades
------------------------

Ejercicio 1
^^^^^^^^^^^^^

¿Qué es un sistema operativo?

En términos generales, un sistema operativo es un SOFTWARE que administra
RECURSOS de hardware y software del computador Y provee servicios mediante
los cuales los programas de usuario pueden hacer uso de esos recursos.

Los siguientes ejercicios explorarán algunos servicios que ofrece el sistema
operativo. La exploración la realizaremos de manera práctica para que luego,
puedas profundizar leyendo uno de los tantos excelentes libros de sistemas
operativos. En particular te recomiendo un par:

`Operating System Concepts <https://codex.cs.yale.edu/avi/os-book/OS10/index.html>`__:

`Operating Systems: Three Easy Pieces <http://pages.cs.wisc.edu/~remzi/OSTEP/>`__

De todos los posibles servicios que ofrece el sistema operativo, Linux en nuestro
caso, vamos a seleccionar solo algunos que te permitirán resolver posteriormente
el proyecto de esta Unidad.

Ejercicio 2
^^^^^^^^^^^^^

¿Cómo hacemos para poder realizar varias tareas de manera concurrente
en un programa?

Lo haremos utilizando hilos. En `este <https://drive.google.com/open?id=1I5G4rRNEzmAuOgpEtgDra8TPUTpIPHTXCTwzHF93wHE>`__
enlace encontrarás 4 ejercicios que te mostrarán cómo crear hilos en C, cómo compilar
un programa que tiene hilos, esperar a qué los hilos terminen, cómo lanzar varios hilos
a la vez y esperar a que terminen.

Ejercicio 3
^^^^^^^^^^^^^

Ahora considera que tenemos un sistema compuesto por varios hilos y/o procesos
que interactúan entre ellos para poder lograr un fin. ¿Cómo hacemos para sincronizar
el acceso a los recursos compartidos? ¿Cómo hacemos para sincronizar el funcionamiento
conjunto de las partes?

Para responder estas preguntas te invito a analizar el material en
`este enlace <https://docs.google.com/presentation/d/1EfixM_Svf4z5tO_WYw1K7T2CH7ofUykifvB7b2LTqQk/edit?usp=sharing>`__.

Ejercicio 4
^^^^^^^^^^^^^

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
^^^^^^^^^^^^^

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


PROYECTO
^^^^^^^^

Crea un chat entre dos procesos utilizando memoria compartida, hilos y semáforos. 
Cada proceso deberá esperar por la entrada de su usuario y al mismo tiempo ser
capaz de mostrar los mensajes enviados por el otro usuario (es por ello que se 
requieren dos hilos por proceso).

El intercambio de mensajes se debe realizar utilizando memoria compartida y
semáforos para la sincronización. Se debe señalizar dos momentos: hay un mensaje y
ya se puede escribir un nuevo mensaje.
