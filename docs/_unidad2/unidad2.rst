Unidad 2. De lenguaje de alto nivel a código ejecutable 
============================================================

Introducción
--------------

En este punto del curso ya tienes una buena idea de cómo funciona un 
computador. También escribiste algunos programas en lenguaje ensamblador 
y estudiaste la relación entre este y el lenguaje de máquina.

A partir de ahora vas a emprender un viaje por varios de los componentes
de software relacionados con los sistemas de cómputo. En esta unidad vas a
aprender por medio de un nuevo lenguaje de programación conceptos que 
te permitirán comprender cómo se puede conseguir el código de máquina 
a partir de un lenguaje de alto nivel.

Propósito de aprendizaje
^^^^^^^^^^^^^^^^^^^^^^^^^^

Comprender cómo se transforma un programa escrito en un lenguaje de alto nivel 
hasta el ejecutable.

Temas
^^^^^^

* Introducción al lenguaje C

Trayecto de actividades
------------------------

Ejercicio 1: entorno de trabajo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para poder trabajar en los ejercicios vas a necesitar un ambiente de trabajo basado en Linux.

Te voy a pedir que le des una mirada a  `este video <https://youtu.be/ZPpo-uViT_o>`__ para 
que te hagas una idea de qué es Linux.

Hay varias opciones para tener Linux funcionando en tu computador: lo puedes instalar en una 
memoria, en una partición de tu computador, en una máquina virtual o incluso en 
`WSL2 <https://docs.microsoft.com/en-us/windows/wsl/install-win10>`__.

Te voy a recomendar que lo instales en una máquina virtual tal como lo explican en 
`este <https://youtu.be/tNUgLsXD7xg>`__ video

Ejercicio 2: instala las herramientas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Una vez tengas Linux funcionando debes instalar una cuentas herramientas en tu 
sistema Linux.

Abren la terminal y ejecuta los comandos:

.. code-block:: bash

    $ sudo apt update
    $ sudo apt install build-essential
    $ sudo apt install gdb

Ejercicio 3: instala un editor de texto 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para el curso te recomiendo que instales 
`Visual Studio Code <https://code.visualstudio.com>`__

Ejercicio 4: línea de comandos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te propongo que te familiarices un poco más con la terminal o línea de comandos 
de tu sistema operativo.

Para ello te propongo realizar la siguiente
`guía <https://drive.google.com/open?id=11tTtbCuVjYcBBYPrULbCeb0PABJLyhGEtzRGKMRG5u0>`__.

Ten presente que en los comentarios de la guía podrás consultar la solución a las preguntas; 
sin embargo, trata de pensar primero y luego compara con la respuesta.

Ejercicio 5: lenguaje de programación C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Este será uno de los ejercicios más largos de la unidad porque vamos a introducir 
el lenguaje de programación con el cual estudiaremos los conceptos que nos queda del curso: ``lenguaje C``.

.. toctree::
    :maxdepth: 3

    Introducción a C <./introC>

..
    Ejercicio 6: herramientas
    ^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. note:: EN CONSTRUCCIÓN

        En los próximos días te estaré publicando este contenido

..
  En este ejercicio comprenderás en detalle los pasos necesarios para transformar un programa en C a 
  lenguaje de máquina.

  .. toctree::
    :maxdepth: 3

    Herramientas <./tools>

..
    Ejercicio 7: máquinas virtuales
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. note:: EN CONSTRUCCIÓN

        En los próximos días te estaré publicando este contenido


..
  En este ejercicio aprenderás acerca de las máquinas virtuales.  

  .. toctree::
    :maxdepth: 3

    Máquinas virtuales <./VM>

Evaluación
-----------------
(Tiempo total estimado 12 horas)

Enunciado
^^^^^^^^^^^

Te voy a proponer una serie de problemas para que evidencies 
en su solución lo que aprendiste en esta unidad.

Para darle variedad a las formas de evaluar te voy a proponer que 
``armes un equipo de trabajo de 2 o 3 persona incluyéndote``. La idea es 
que entre todos construyan la solución a cada uno de los problemas.

Problema 1: analisis y relación 
**************************************
Lo que has aprendido en este curso está relacionado con otras áreas 
del conocimiento de tu carrera. En este problema te voy pedir que analices 
y luego relaciones. 

Considera el siguiente programa:

.. code-block:: c 

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct IntArray{
        int *parr;
        int length;
    }IntArray;


    IntArray *createIntArray(int size);
    void initIntArray(IntArray *);
    void destroyIntArray(IntArray *);
    void printArray(IntArray *);

    int main(){
        IntArray * pIntArray = createIntArray(100);
        initIntArray(pIntArray);
        printArray(pIntArray);
        destroyIntArray(pIntArray);
    }

    IntArray *createIntArray(int size){
            IntArray *pIntArray = malloc(sizeof(IntArray));
            pIntArray->parr =   malloc( sizeof(int) * size);      
            pIntArray->length = size;
            return pIntArray;
    }

    void initIntArray(IntArray *this){
        for(int i = 0; i < 100; i++){
            this->parr[i] = i;
        }
    }

    void printArray(IntArray *this){
        for(int i = 0; i < this->length; i++){
            printf("parr[%d]: %d\n", i, this->parr[i]);
        }
    }

    void destroyIntArray(IntArray *this){
        free(this->parr);
        free(this);
    }

* Explica cómo funciona el programa.
* Explica en que parte del MAPA DE MEMORIA del proceso se 
  almacena CADA variable usada.
* Construye una programa similar a este usando C#. 
* Explica en qué parte de la memoria se almacena cada 
  variable de tu programa.
* Compara ambos programas e indica qué conceptos del programa 
  propuesto se ven reflejados en tu programa.

Problema 2: del código fuente al código de máquina 
******************************************************

Explica cómo se transforma el programa anterior (el que está en C) 
desde el código fuente hasta el código de máquina, es decir, qué pasos son 
necesarios para lograr lo anterior. En el proceso responde en el 
contexto del PROGRAMA:

* ¿Qué hace el preprocesador?
* ¿Qué hace el compilador?
* ¿Qué hace el ensamblador?
* ¿Quién o que parte del proceso de transformación se encarga de mezclar 
  tu código con el código de ``printf`` 

Problema 3: programación en lenguaje C 
****************************************

Vas a crear un programa en C que haga lo siguiente:

* Crea un archivo de texto con la información de un arreglo de caracteres
* Tu programa debe leer ese archivo y almacenar la información en un arreglo 
  de enteros en memoria dinámica.
* Realiza tres funciones que permitan encontrar el máximo, el mínimo y el promedio.
* A cada función le debes pasar la dirección de memoria del primer elemento del 
  arreglo y el tamaño de este.
* Vas a crear un archivo de salida donde almacenarás el máximo, mínimo y el promedio 
  encontrados.

¿Qué debes entregar?
^^^^^^^^^^^^^^^^^^^^^^^^^^

* Subir a `este <https://www.dropbox.com/request/IlFVvm1HltrxnTlb4gjb>`__ 
  enlace un ``.pdf`` con:

  #. Los nombres y IDs.
  #. Enlace al repositorio GitHub con la solución a los problemas 
  #. La URL del video en youtube.
  #. Reportar si algún compañero del equipo no trabajó. 

* El video DEBE TENER una duración ``MÁXIMA`` de 15 minutos.
* El video debe tener los siguientes capítulos en este mismo orden:

  * Integrantes y las tareas que realizó cada uno.
  * Problema 1: explicación.
  * Problema 2: explicación.
  * Problema 3: demostración de la solución.
  * Problema 3: explicación de la solución.
  * Problema 3: explicación de la implementación en código de la solución.

* En `este video <https://youtu.be/6-0cERIVsFg>`__ puedes aprender a adicionar 
  capítulos a tu video.

Criterios de evaluación
^^^^^^^^^^^^^^^^^^^^^^^^^

Cada problema se evalua completo, es decir, no se reciben problemas 
con solución incompleta. Un problema se soluciona completamente si tiene TODO lo 
solicitado incluyendo el video con la demostración y la explicación de su solución.

* Calidad y duración máxima del video y repositorio en Github: 0.5
* Problema 1: 1.5 unidad.
* Problema 2: 1 unidades
* Problema 3: 2 unidades.

.. note:: Sobre las personas reportadas en el pdf

    Las personas que aparezcan reportadas en el pdf obtendrán automáticamente 
    una calificación de 0.


