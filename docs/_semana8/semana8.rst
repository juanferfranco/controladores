Semana 8: Unidad 3
==========================

En este punto del curso ya conocemos cómo funciona un computador,
también conocemos el concepto de programa almacenado y cómo hacer para
convertir un programa de lenguaje ensamblador a lenguaje de máquina. 

A partir de ahora vamos a emprender un viaje por varios de los componentes
de software relacionados con los sistema de cómputo. En esta unidad vamos a
analizar las herramientas necesarias para transformar un programa
en lenguajes como C, C++ y C# a lenguaje ensamblador.

Propósito de aprendizaje
--------------------------

Comprender cómo se transforma un programa escrito en lenguajes como C, C++ y C#
a lenguaje ensamblador.


Código de honor
----------------
Al realizar los ejercicios esta unidad se espera que hagas lo siguiente:

* Colabora con tus compañeros cuando así se indique.
* Trabaja de manera individual cuando la actividad así te lo proponga.
* NO DEBES utilizar sitios en Internet con soluciones o ideas para atacar el proyecto.
* NO DEBES hacer uso de foros para buscar soluciones al proyecto.
* ¿Entonces qué hacer si no me funciona algo? Te propongo que experimentes, crea hipótesis,
  experimenta de nuevo, observa y concluye.
* NO OLVIDES, este curso se trata de pensar y experimentar NO de BUSCAR soluciones
  en Internet.

Actividades
-------------

Actividad 1
^^^^^^^^^^^^
* Fecha: agosto 25 de 2020 - 8 a.m.
* Descripción: introducción a la Unidad 3
* Recursos: ingresa al grupo de Teams
* Duración de la actividad: 1 hora 40 minutos de discusión
* Forma de trabajo: colaborativo con solución de dudas en tiempo real.

Vamos a comenzar nuestro viaje explorando una herramienta conocida como
la línea de comandos, disponible en casi todos los sistemas operativos. Para
ello te propongo realizar la siguiente
`guía <https://drive.google.com/open?id=11tTtbCuVjYcBBYPrULbCeb0PABJLyhGEtzRGKMRG5u0>`__.

Actividad 2
^^^^^^^^^^^^
* Fecha: agosto 25 a agosto 27 de 2020 
* Descripción: introducción al lenguaje C
* Recursos: actividad de trabajo autónomo
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

Para realizar la siguiente guía vas a necesitar un entorno de
prueba. En la sección :ref:`ejercicios_sem1` te he dejado información para
que tengas ese entorno en tu computador local; sin embargo, para que
puedas comenzar de una vez te voy a recomendar dos sitios donde puedes
compilar y ejecutar programas online. Usa el que más te guste.

#. `Online GDB <https://www.onlinegdb.com/>`__
#. `repl.it <https://repl.it/>`__

En este `enlace <https://drive.google.com/file/d/1wiyBZL0kf1cQekHPfa7URcOxSpnfKE7-/view?usp=sharing>`__
encontrarás una guía básica del lenguaje C.

.. note::
    ¡Alerta de Spoiler!

    En este `enlace <https://drive.google.com/file/d/174GYcz_in94R_z6NklA02yzmsj3OuD5f/view?usp=sharing>`__
    , se encuentra la solución a algunos puntos de la guía introductoria a C (ojo, no todos). 
    Te recomiendo hacer los ejercicios sin recurrir a la solución.

.. _ejercicios_sem1:

Ejercicios
************

Ejercicio 1: entorno de trabajo
##################################
Para poder trabajar en los ejercicios que te propondré vas
a necesitar un ambiente de trabajo. Te propongo que instales en una USB o en una
partición de tu computador el sistema operativo Linux. Te 
preguntarás si puedes instalarlo en una máquina virtual.
Lo puedes hacer pero usualmente no lo recomiendo porque la
experiencia de uso no resulta agradable si tu sistema es muy lento.

Vas a necesitar dos memorias USB. Una grande (> 16GB), donde instalarás tu sistema operativo
y otra más pequeña (8GB) donde grabaras el instalador. Trata de utilizar la USB más rápida y
más grande para instalar tu sistema operativo.

Te voy a dejar unos videos de ayuda:

* Este `video <https://www.youtube.com/watch?v=zSGZe8NSEAc>`__ 
  te muestra como grabar en la USB pequeña el instalador. En este caso la distribución es PopOS,
  es la misma que yo uso; sin embargo, puedes grabar la que más te guste, por ejemplo Ubuntu.
  Ten presente que la versión del video no será la última. También, debes investigar
  cómo entrar al menú de configuración de tu BIOS para que ajustes el orden de boot. 
  Nota que debes darle prioridad a la USB para que al tenerle conectada arranques el 
  instalador del sistema operativo.

* Ahora, este video `video <https://www.youtube.com/watch?v=RR9Vgytjj24>`__ te mostrará
  cómo instalar, usando la USB pequeña con el instalador, tu sistema operativo en la USB grande.
  Te recomiendo iniciar a ver el video en el minuto 6:29, donde comienza en si el proceso
  de instalación. Una vez termines de instalar Linux en la USB grande, NO OLVIDES desconectar la USB
  pequeña para que tu computador inicie con la versión instalada de Linux en la USB grande.

Ejercicio 2: instala las herramientas 
#######################################
Abren la terminal y ejecuta los comandos:

.. code-block:: c
   :linenos:

    $ sudo apt update
    $ sudo apt upgrade
    $ sudo apt install build-essential
    $ sudo apt install gdb

Ejercicio 3: instala un par de entornos de desarrollo
#########################################################

Para el curso te recomiendo que instales dos entornos de desarrollo:

#. Eclipse
#. Visual Studio Code

Eclipse te permitirá tener un depurador visual de código, pero la verdad
es un poco lento. Visual Studio, no tiene un depurador visual tan rico, pero es
muy liviano. Yo uso ambos. Normalmente trabajo con Visual Studio Code y cuando
algo no me funciona lo pruebo con Eclipse.

Actividad 3
^^^^^^^^^^^^
* Fecha: agosto 27 de 2020 - 10 a.m. 
* Descripción: introducción al lenguaje C
* Recursos: actividad de trabajo autónomo
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

Actividad 4
^^^^^^^^^^^^
* Fecha: agosto 25 a septiembre 1 de 2020
* Descripción: introducción al lenguaje C
* Recursos: actividad de trabajo autónomo
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

Para las actividades 3 y 4 te propongo que continues estudiando
un poco más el lenguaje de programación C.

Primero te voy a proponer que hagas dos guía para que trabajes los conceptos
básicos y luego una serie de ejercicios que te permitirán practicar varias
de las cosas que has hecho hasta ahora.

Realiza `esta <https://drive.google.com/file/d/19NmKVXEYB5Ud0SqbBwAe4HVYMD6LDHKD/view>`__ guía sobre punteros,
arreglos y memoria dinámica.

.. note::
        ¡Alerta de Spoiler!
    
    En este `enlace <https://docs.google.com/presentation/d/1eCo1pCzYd0YB1dYhTLJNV8w9lVAQVX6u4LQEq1oHtH0/edit#slide=id.p9>`__
    se encuentra la solución a la guía de punteros, arreglos y memoria dinámica.

Realiza `esta <https://drive.google.com/open?id=1hBPkoUsGUmatr3tRm5ztr-s3hyc3OLhl>`__ guía sobre
estructuras de datos y archivos.

.. note::
        ¡Alerta de Spoiler!

    La solución a algunos puntos la puedes consultar `aquí <https://drive.google.com/file/d/1FWuPqJNWvEvHp89-ADvKu7XqdAZR6fx2/view?usp=sharing>`__

Ejercicios
*************


Ejercicio 1: entrada/salida
###############################
En la guía introductoria del lenguaje C se discutió la
función **scanf** para realizar operaciones de entrada en
C. Al realizar el ejercicios final, la calculadora,
¿Notaste algún comportamiento extraño del
programa al leer caracteres? Específicamente ``scanf("%c",&var)``.

Ten presente que al introducir texto en la terminal,
además de los caracteres visibles, se introduce un ENTER.
Así, por ejemplo, al introducir el número 325 y luego presionar
ENTER, se están ingresando 4 bytes: 0x33 0x32 0x35 0x0A. los
tres primeros bytes corresponden a los códigos ASCII de cada dígito
del número 325 y el 0x0A corresponde al código ASCII del ENTER
o nueva línea (NEW LINE).

Considere el siguiente código:

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main()
    {
        int num;
        char key;
        printf("Prueba a scanf. Ingrese el numero 325 y presione ENTER:\n");
        scanf("%d",&num);
        printf("Ingrese cualquier tecla para terminar y presione ENTER:\n");
        scanf("%c",&key);
        
        return 0;
    }  

Ejecuta el código anterior. ¿Cuál es el resultado? ¿Por qué?

El primer scanf (``scanf("%d",&num);``) buscará en el flujo de entrada una
secuencia de bytes que comience con un carácter numérico y parará de leer
una vez detecte un carácter no numérico, el cual, dejará intacto en el flujo
de entrada. En este caso, ``scanf("%d",&num);`` sacará del flujo
los bytes 0x33 0x32 0x35, correspondientes a ``'3'`` ``'2'`` ``'5'``,
y dejará en el flujo el byte 0x0A (correspondiente al ENTER). Luego
convertirá la cadena de 3 bytes en ASCII al número que representan, es decir,
al 325 que en base 16 sería 0x0145 (comprueba esto con la calculadora del
sistema operativo)

El segundo scanf ``scanf("%c",&key);`` leerá un carácter del flujo de entrada.
En este caso dicho carácter está disponible y corresponde al ENTER dejado
por el scanf anterior.

¿Cómo solucionar este problema? Una posible solución será (aunque hay otras
más):

.. code-block:: c
    :linenos:

    #include <stdio.h>

        int main()
        {
            int num;
            char key;
            printf("Prueba a scanf. Ingrese el numero 325 y presione ENTER:\n");
            scanf("%d",&num);
            scanf("%c",&key); // Saco del flujo el ENTER
            printf("Ingrese cualquier tecla para terminar y presione ENTER:\n");
            scanf("%c",&key);
            return 0;
        }  

Ejercicio 2: entrada/salida
###############################
Para complementar el ejercicio anterior, se propone analizar otros ejemplos
(Tomados de este `enlace <http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html>`__).


.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        int a = 10;
        printf("enter a number: ");
        scanf("%d", &a);
        printf("You entered %d.\n", a);
    }  

Ingresa un número y ENTER. ¿Qué ocurre? Ahora ingresa una palabra y ENTER.
¿Qué ocurre? ¿Por qué?

Ejercicio 3: scanf return
###############################
scanf devuelve la cantidad de conversiones realizadas. Analiza
este ejemplo (ingresa CRTL+C si algo sale mal):

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        int a;
        printf("enter a number: ");
        while (scanf("%d", &a) != 1)
        {
            // input was not a number, ask again:
            printf("enter a number: ");
        }
        printf("You entered %d.\n", a);
    }

¿Por qué funciona así el programa? Recuerda el ejercicio 1.

Ejercicio 4: cadenas
###############################
Compila el código que se muestra a continuación así:
``gcc -Wall -fno-stack-protector tmp.c -o tmp``

Ejecuta el programa con estos vectores de prueba cuando se pregunte
por el nombre:

* juan
* juan-fernan
* juan-fernando-franco

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        char name[12];
        printf("What's your name? ");
        scanf("%s", name);
        printf("Hello %s!\n", name);
    }

Explique cómo funciona el programa en cada caso.

Ejercicio 5
###############################

Repite el ejercicio anterior pero esta vez compilando
sin ``-fno-stack-protector``.

Ejercicio 6
###############################

Finalmente repita el ejercicio anterior, pero esta vez
usando el siguiente código y compilando sin ``-fno-stack-protector``

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        char name[40];
        printf("What's your name? ");
        scanf("%39s", name);
        printf("Hello %s!\n", name);
    }

Explica por qué en scanf especificamos un 39 sabiendo que name puede almacenar 
40 caracteres. Recuerda, de la primera guía, que todas las cadenas en C deben terminar
con un 0.

Ejercicio 7
###############################
Usando el código anterior ingresa:  juan fernado franco.
¿Cuál es el resultado?

Ejercicio 8
###############################
Escribe el siguiente código:

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        char name[40];
        printf("What's your name? ");
        scanf("%39[^\n]", name);
        printf("Hello %s!\n", name);
    }

Nota la línea:``scanf("%39[^\n]", name);``. En este caso le estamos diciendo a
scanf que lea hasta 39 caracteres y hasta que encuentre un ENTER (``\n``). También
es posible indicarle a scanf que lea mientras que los caracteres estén en una
lista, por ejemplo: ``scanf("%39[a-z]", name);``.

Ejercicio 9
###############################
¿Entonces qué usamos para leer la entrada?

Ahora que conocemos mejor los punteros y los arreglos podemos explorar la
función fgets: ``char *fgets(char *str, int n, FILE *stream)``. A esta
función le debemos pasar la dirección del buffer donde queremos colocar
los caracteres, la cantidad de caracteres y el flujo. fgets termina de leer
el flujo cuando encuentre un ENTER. Dicho ENTER se saca del flujo

Analiza el funcionamiento de fgets:

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        char name[40];
        printf("What's your name? ");
        if (fgets(name, 40, stdin))
        {
            printf("Hello %s!\n", name);
        }
    }

NOTA que en **name** quedará también el ENTER. Entonces para eliminarlo
simplemente hacemos: 

.. code-block:: c
    :linenos:

    #include <stdio.h>
    #include <string.h>

    int main(void)
    {
        char name[40];
        printf("What's your name? ");
        if (fgets(name, 40, stdin))
        {
            name[strcspn(name, "\n")] = 0;
            printf("Hello %s!\n", name);
        }
    }

**strcspn** buscará en la cadena **name** el primer *match* con
``\n`` y devolverá la posición en **name** en la cual fue encontrado
el *match*. 

Ejercicio 10
###############################
(Este ejercicio es tomado de `aquí <https://www.geeksforgeeks.org/pointer-array-array-pointer/>`__)

Relación arreglos y punteros

.. code-block:: c
    :linenos:

    #include<stdio.h> 

    int main() 
    { 
        int *p;  
        int (*ptr)[5];  
        int arr[5]; 
        
        p = arr; 
        ptr = &arr;  
        printf("p = %p, ptr = %p\n", p, ptr); 
        p++;  
        ptr++; 
        printf("p = %p, ptr = %p\n", p, ptr); 
        return 0; 
    }

Ejecuta el programa anterior. El resultados es:

.. code-block:: c
    :linenos:
    
    p = 0x7fff4f32fd50, ptr = 0x7fff4f32fd50
    p = 0x7fff4f32fd54, ptr = 0x7fff4f32fd64


En la expresión ``int * p;`` p es una variable de tipo
``int *``. En este tipo de variables se almacenan las
``direcciones`` de variables de tipo ``int``. Por tanto, ``*p``
(sin colocar int antes del ``*``) es de tipo ``int`` porque 
p es de tipo ``int *``.

En la expresión ``int (*ptr)[5];`` ptr es una variable de tipo
``int (*)[5]``. En este tipo de variables se almacenan direcciones
de variables de tipo ``int [5]``, es decir, variables de tipo
arreglo de cinco posiciones. Por tanto, ``*ptr`` es de tipo 
``int [5]`` porque ptr es de tipo ``int (*)[5]``.

En la expresión ``p = arr;`` arr es el nombre del arreglo y un puntero
al primer elemento del arreglo.
En este caso `arr` es de tipo ``int *`` porque el primer elemento
del arreglo es de tipo ``int``. Por tanto, ``*arr`` 
será tipo ``int``.

En la expresión ``ptr = &arr;`` ``&arr`` es la dirección del arreglo.
``&arr`` es tipo ``int (*)[5]``.

La expresión ``printf("p = %p, ptr = %p\n", p, ptr);`` imprime el
contenido de p y ptr. Según el resultado
``(p = 0x7fff4f32fd50, ptr = 0x7fff4f32fd50`)``, la dirección del
arreglo y del primer elemento del arreglo es la misma; sin embargo,
como p es tipo ``int *``, la expresión ``p++`` hará que p apunte
(almacene la dirección) al siguiente entero. En cambio, en la
expresión ``ptr++;`` ptr apuntará al siguiente arreglo de 5
enteros (5 enteros ocupan 20 bytes en memoria considerando
que cada entero ocupa 4 bytes), ya que ptr es de tipo
``int (*)[5]``.

Ejercicio 11: análisis de una expresión más compleja
##############################################################

El siguiente ejercicio es más complejo que el anterior, sin embargo,
se analiza de igual manera. Considera el siguiente código:

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int arr[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

    int main(void) {
        int (*p)[3][4] = &arr;
        printf("%d\n", ( (*p)[2] )[3] );
        printf("%d\n", *( *(*p + 2) + 3 ) );
        return 0;
    }


``arr`` es un arreglo de arreglos, es decir, es una arreglo de 3 arreglos
de 4 enteros cada uno.

``arr`` es el nombre del arreglo de arreglos y un puntero al primer elemento
del arreglo. Por tanto, ``arr`` es de tipo ``int (*)[4]`` ya que el primer elemento
de arr es un arreglo de tipo ``int [4]``.

``p`` es un puntero que almacena la dirección de un arreglo de arreglos.
Por tanto, p es de tipo ``int (*)[3][4]``.

Si ``p`` es de tipo ``int (*)[3][4]`` entonces ``*p`` será de tipo ``int [3][4]`` o
``int (*)[4]`` (un puntero al primer elemento del arreglo de arreglos).

El operador ``[]`` en la expresión ``(*p)[2]`` es equivalente a ``*( *p + 2)``.
Como el tipo de ``(*p + 2)`` es ``int (*)[4]`` el tipo de ``*( *p + 2)``
será ``int [4]``. la expresión ``(*p)[2]`` accede al tercer elemento de arr, es
decir, a ``{9,10,11,12}`` que es de tipo ``int [4]``.

Por último, como ``(*p)[2]`` es tipo ``int [4]``, entonces ``( (*p)[2] )[3] )`` es
tipo int y corresponderá al cuarto elemento del tercer arreglo de arr.

Nota que ``( (*p)[2] )[3] )`` es equivalente a ``*( (*p)[2] + 3)`` que a su
vez es equivalente a  ``*( * ( *p + 2)+ 3)``

El programa imprimirá el número ``12``.

La expresión ``printf("%d\n", *( * ( *p + 2)+ 3));`` al ser equivalente a
``printf("%d\n", ( (*p)[2] )[3] );`` también mostrará un ``12``.