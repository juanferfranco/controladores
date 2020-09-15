Semana 11: Unidad 3
==========================

Esta semana terminaremos la introducción a C y veremos
en detalle cómo es el proceso de transformación a lenguaje de máquina.

Actividad 13
^^^^^^^^^^^^
* Fecha: septiembre 15 de 2020
* Descripción: sustentación
* Recursos: ingresa a Teams
* Duración de la actividad: 1:40 minutos
* Forma de trabajo: individual

Actividad 14
^^^^^^^^^^^^^^^^
* Fecha: septiembre 15 a septiembre 17 de 2020 
* Descripción: realizar los ejercicios propuestos
* Recursos: actividad de trabajo autónomo
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

Ejercicio 1
############
Con este ejercicio vamos a responder una pregunta
¿Qué son las directivas del preprocesador?

El preprocesamiento es una característica muy propia de
C que no es común a otros lenguajes de programación. Esta
característica permite MODIFICAR el programa ANTES de pasárselo
a compilador para que lo convierta en lenguaje ensamblador.

Lo que debes hacer para usar el preprocesador es introducir en
el código DIRECTIVAS, es decir, instrucciones que le das al
preprocesador. Una vez el preprocesador lee tu programa, su tarea
será remover las directivas y sustituirlas por código C que él
mismo generará usando las instrucciones que tu le has dado con
la directiva específica. Luego de este paso, tu programa estará
listo para ser leído por el compilador.

Ten en cuenta que las directivas comenzarán por el símbolo #.

Ejercicio 2
#############
Ahora te voy a mostrar algunos ejemplos de directiva que puedes
usar o que probablemente ya has utilizado en este punto del curso:

.. code-block:: c
    :linenos:

    #define M 5
    #define C 5

    int main(int argc, char* argv[]) {
        int x = 2;
        int y = x*M + C;
        return 0;
    }

¿Cuál será el resultado en la variable ``y`` luego de ejecutar este programa?

Para responder esta pregunta recuerda que antes de compilador
el programa, el archivo se pasa al preprocesador. El resultado del preprocesador
será algo similar a esto:

.. code-block:: c
    :linenos:

    int main(int argc, char* argv[]) {
        int x = 2;
        int y = x*5 + 5;
        return 0;
    }

Ahora si, este archivo, será pasado al compilador para que
lo convierta en código ensamblador. La respuesta a la pregunta
será 15.


Mira este otro ejemplo:


.. code-block:: c
   :linenos:

	#define M 5
	#define C 5
	#define MAP(val,m,c) x*m+c

    int main(int argc, char* argv[]) {
        int x = 2;
        int y = MAP(x,M,C);
        return 0;
    }

¿Qué crees que genere el preprocesador luego de procesar este
archivo? 

.. note::
    ¡Alerta de Spoiler!

    .. code-block:: c
        :linenos:

        int main(int argc, char* argv[]) {
            int x = 2;
            int y = x*5+5;
            return 0;
        }

Otra forma de saber, ANTES de compilar, la salida del preprocesador es así:

``gcc -E codigo.c``

Por último prueba el comando anterior con este programa:

.. code-block:: c
   :linenos:

	#include <stdio.h>
    
    #define M 5
	#define C 5
	#define MAP(val,m,c) x*m+c

    int main(int argc, char* argv[]) {
        int x = 2;
        int y = MAP(x,M,C);
        printf("y: %d", y);
        return 0;
    }

¿Qué puedes concluir de la directiva ``#include`` 

Ejercicio 3
#############
Otro uso interesante del preprocesador es para las DIRECTIVAS
de compilación condicional. 

Esta directivas te permiten incluir un código u otro, dependiendo
de una condición:

.. code-block:: c
   :linenos:

    #include <stdio.h>

    #define CONDITION
    
    int main(int argc, char* argv[]) {
    
        #ifdef CONDITION
        printf("CODIGO IF\n");
        #else
        printf("CODIGO ELSE\n");
        #endif
        return 0;
    }

¿Cómo crees que quede el programa luego de ser preprocesado?

.. note::
    ¡Alerta de Spoiler!


    Al definir ``CONDITION`` con la directiva ``#define CONDITION``
    y con el comando ``gcc -E codigo.c`` el resultado es:

    .. code-block:: c
        :linenos:

        int main(int argc, char* argv[]) {
           printf("CODIGO IF\n");
            return 0;
        }


Ejercicio 4
#############
¿Será posible definir una directiva para el preprocesador
desde la línea de comandos?

Volvamos al ejemplo anterior pero esta vez sin el ``#define CONDITION``

.. code-block:: c
   :linenos:

    #include <stdio.h>

    int main(int argc, char* argv[]) {
    
        #ifdef CONDITION
        printf("CODIGO IF\n");
        #else
        printf("CODIGO ELSE\n");
        #endif
        return 0;
    }

¿Cuál será el resultado de compilar y ejecutar este programa?

Compara el resultado obtenido con la salida del comando ``gcc -E codigo.c``.

Ahora prueba este comando:

``gcc -DCONDITION -E codigo.c``

¿Cuál es el resultado?

Y si compilas así:

``gcc -DCONDITION -Wall codigo.c -o codigo``

¿Qué conclusiones puedes sacar?

Ejercicio 5
#############
Ahora si vamos a responder la pregunta de la semana:
¿Cómo llegamos del código fuente al binario (el ejecutable)?

En el caso del lenguaje C se siguen unos pasos conocidos como el
pipeline de compilación compuesto por 4 pasos: preprocesamiento,
compilación, ensamblado y enlazado.

IMPORTANTE: para poder conseguir un ejecutable desde el código fuente,
es necesario que nuestro código pase por todas las etapas del pipeline
de manera exitosa.

Para ilustrar el proceso vamos a crear un programa compuesto por 3 archivos:
dos archivos .c y un archivo .h. Todos los archivos estarán almacenados
en el mismo directorio.

min.h

.. code-block:: c
   :linenos:

    #ifndef MIN_H
    #define MIN_H
    int min(int, int);
    #endif

min.c

.. code-block:: c
   :linenos:

    #include "min.h"

    int min(int a, int b){
        if(a < b) return a;
        else return b;
    }



main.c

.. code-block:: c
   :linenos:

    #include "min.h"
    #include <stdio.h>

    int main(int argc, char* argv[]){
        printf("the min value is: %d\n",min(1,2));
        return 0;
    }

La idea será crear un ejecutable partiendo de estos tres archivos.
Ten presente que los archivos ``.h`` se usan para informarle al compilador
qué tipo de datos recibe la función min y qué tipo de dato devuelve. Los
archivos .h no se compilan, solo los archivos ``.c``.

Compilamos primero ``min.c``:

* Preprocesamiento:  ``gcc -E min.c``. Al ejecutar este comando nota como
   el preprocesador incluye la información de min.h a min.c
* Compilación: ejecuta el comando ``gcc -S min.c``. La opción ``-S`` le indica 
  al comando ``gcc`` que debe hacer el proceso anterior (preprocesador) y con la
  salida de este paso alimentar al compilador y detenerse en ese punto. El archivo
  de salida generado será ``min.s`` que contendrá el código ensamblador.

.. code-block:: c
   :linenos:


        .file	"min.c"
        .text
        .globl	min
        .type	min, @function
    min:
    .LFB0:
        .cfi_startproc
        endbr64
        pushq	%rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq	%rsp, %rbp
        .cfi_def_cfa_register 6
        movl	%edi, -4(%rbp)
        movl	%esi, -8(%rbp)
        movl	-4(%rbp), %eax
        cmpl	-8(%rbp), %eax
        jge	.L2
        movl	-4(%rbp), %eax
        jmp	.L3
    .L2:
        movl	-8(%rbp), %eax
    .L3:
        popq	%rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
    .LFE0:
        .size	min, .-min
        .ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
        .section	.note.GNU-stack,"",@progbits
        .section	.note.gnu.property,"a"
        .align 8
        .long	 1f - 0f
        .long	 4f - 1f
        .long	 5
    0:
        .string	 "GNU"
    1:
        .align 8
        .long	 0xc0000002
        .long	 3f - 2f
    2:
        .long	 0x3
    3:
        .align 8
    4:

* Ensamblado: en esta fase se gera el código máquina.
  ``as min.s -o min.o``. También es posible generar el código de
  máquina con el comando ``gcc -c min.c``

* Debemos repetir este proceso con todos los archivos ``.c`` de nuestro
  proyecto: ``gcc -c main.c``. Ten presente que el comando anterior
  ejecutará automáticamente todos los pasos previos, es decir, el preprocesado,
  la compilación y el proceso de ensamblado.

* Enlazado: una vez tengas todos los archivos ``.o`` lo último que debes hacer
  es enlazar todos los archivos para generar un archivo ejecutable. Este archivo
  contiene el código de máquina de todos los ``.o`` pero organizado en un formato
  específico. En el caso de Linux el formato típico es ``.ELF``. Ejecuta el siguiente
  comando para enlazar: ``ld min.o main.o``. Verás el siguiente resultado:

.. code-block:: c
   :linenos:

    ld: warning: cannot find entry symbol _start; defaulting to 0000000000401000
    ld: main.o: in function main:
    main.c:(.text+0x31): undefined reference to printf

Este resultado indica que no fue posible generar el ejecutable 
(`` main.c:(.text+0x31): undefined reference to printf``). Pero ¿Por qué?
la razón es que nos falta el archivo con el código de máquina de la función ``printf``.
Esta función está prototipada en el archivo de cabecera (``stdio.h``), pero el archivo
no contiene el código fuente de ``printf``. ¿Y dónde está el código entonces? este
código hace parte de la biblioteca `glibc <https://www.gnu.org/software/libc/>`__ 
que debes tener en tu sistema operativo y que contiene el código de máquina de varias
funciones, entre ellas, ``printf``.

Una forma fácil de generar el ejecutable es utilizar de nuevo ``gcc``. Este comando
se encargará de suministrarle a ``ld`` todo los archivos con código máquina necesarios para
generar nuestro ejecutable: ``gcc min.o main.o -o main``.

Actividad 15
^^^^^^^^^^^^^^^^
* Fecha: septiembre 17 de 2020
* Descripción: análisis de los ejercicios
* Recursos: ingresa a Teams
* Duración de la actividad: 1:40 minutos
* Forma de trabajo: individual y grupal con solución de dudas en tiempo real

Actividad 16
^^^^^^^^^^^^^^
* Fecha: septiembre 17 a septiembre 22 de 2020 
* Descripción: leer el material sugerido y realizar los ejercicios propuestos
* Recursos: actividad de trabajo autónomo
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

Ejercicio 6
##############

TODO...