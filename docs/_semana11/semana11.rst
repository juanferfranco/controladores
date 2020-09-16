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

Ahora que ya sabemos cómo se transforma un programa del código fuente al lenguaje de máquina,
podemos indagar un poco más en las fases. ¿Cómo funciona un compilador?

Un compilador también funciona por fases. Así:

* La primera fase es el TOKENIZER o el análisis léxico. Su propósito es obtener una representación
  intermedia del programa conocida como stream of tokens. Por ejemplo, supongamos la siguiente
  expresión en un lenguaje de programación arbitrario: ``print hola``. Un token es una unidad
  indivisible que consiste de un tipo y un valor. En la expresión anterior el primer token es de
  tipo Identificador y el valor es print. El segundo token es de tipo CADENA y el valor es hola.

* La segunda fase es el PARSER. Su propósito es validar si la sintaxis de el programa es válida o no.
  Por tanto, a esta fase se le conoce como análisis sintáctico. El PARSER toma la gramática formal
  del lenguaje y trata de hacer un match con el texto del programa. En términos simples, la gramática
  formal del lenguaje es el conjunto de reglas que se deben seguir para usar correctamente las
  'palabras' definidas por el lenguaje. El PARSER valida si el programa que escribiste cumple las
  reglas definidas en la gramática y si todo está bien produce una representación intermedia 
  del programa conocida como AST o Abstract Syntax Tree.

  No olvides que un programa en lenguaje C se puede compilar a múltiples lenguajes ensambladores
  o set de instrucciones. Cada set de instrucciones es específico para cada CPU;
  sin embargo, sin importar el set de instrucciones final, la representación AST será la misma. 
  A esta parte del compilador se le conoce como frontend y luego, a la parte del compilador que
  toma el AST y lo convierte a un set de instrucciones específico, se le conoce como backend.

* La tercera fase es el generador de código ensamblador. Es precisamente el backend del que te hablé
  hace un momento. El generador toma el AST, lo optimiza y genera instrucciones en lenguaje ensamblador
  para la CPU específica que estemos compilando.

Observa el siguiente código:

.. code-block:: c
   :linenos:

    int main(){
        int a = 1;
        int b = 2;
        int c = a + b;
        return 0;
    }

Vamos a utilizar otro compilador, clang. Compila así:

``clang -Xclang -ast-dump -fsyntax-only main.c``

observa el resultado. Esa será el AST generado. ¿Por qué te hablo de clang en este ejercicio? porque
cuando estés estudiando el nuevo framework de Unity conocido como ``DOTs`` te darás cuanta que ellos
están utilizando clang como frontend. Estudiar en detalle estos asuntos desborda las posibilidades
de este curso; sin embargo, al menos tendrás los conceptos básicos para no estar perdido.

Ejercicio 7
##############
En cuanto a la fase de ensamblado, ya te comenté que el archivo de salida contiene lenguaje de máquina
de la CPU específica. Cada sistema operativo maneja su propio formato de archivo de salida del ensamblador
o código objeto (object file), es por ello que aunque el computador sea el mismo, si instalas diferentes
sistemas operativos, cada uno tendrá su propio ensamblador y su propio formato de object file. Por tanto,
un archivo de salida del ensamblador no solo contiene instrucciones específicas de la CPU, sino que también
estará organizado según la conveniencia de cada sistema operativo. Y es por esto que Windows no podrá
ejecutar tal cual los programas compilados para Linux, así estés corriendo los sistemas operativos en
el mismo computador.

Ejercicio 8
#############
No te lo dije, pero cuando compilas un programa en C la única salida del programa no tiene que ser
un ejecutable. Te cuento que tienes más posibilidades:

* Puedes generar un ejecutable, usualmente con extensión ``.out`` equivalente al ``.exe`` de Windows.
* Puedes generar una biblioteca estática con extensión ``.a`` equivalente a los archivos ``.lib``
  de Windows.
* Puedes generar una biblioteca dinámica con extensión ``.so`` equivalente a los ``.dll`` en Windows.

Los object file de los que hablamos en el ejercicio anterior son el producto de la fase de ensamblado.
Para poder tener un ejecutable, recuerda que necesitas una fase más: el enlazado. La fase de enlazado
te permite combinar varios object files y bibliotecas para generar ejecutables o bibliotecas.

TODO...

