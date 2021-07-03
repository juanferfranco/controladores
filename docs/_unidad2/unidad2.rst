Unidad 3. Del código fuente al código ejecutable 
==================================================

Introducción
--------------

En este punto del curso ya conocemos cómo funciona un computador. Ya 
escribiste algunos programas en lenguaje ensamblador y estudiantes la 
relación entre este y el lenguaje de máquina.

A partir de ahora vamos a emprender un viaje por varios de los componentes
de software relacionados con los sistema de cómputo. En esta unidad vamos a
analizar las herramientas necesarias para transformar un programa
en lenguajes como C, C++ y C# a lenguaje de maquina.


Propósito de aprendizaje
^^^^^^^^^^^^^^^^^^^^^^^^^^

Comprender cómo se transforma un programa escrito en lenguajes como C, C++ y C#
a lenguaje de máquina.

Temas
^^^^^^

* Introducción al lenguaje C
* Herramientas
* Máquinas virtuales

Trayecto de actividades
------------------------

Ejercicio 1: entorno de trabajo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para poder trabajar en los ejercicios vas a necesitar un ambiente de trabajo basado en Linux.
Hay varias opciones para tener Linux funcionando en tu computador: lo puedes instalar en una 
memoria, en una partición de tu computador, en una máquina virtual o incluso en 
`WSL2 <https://docs.microsoft.com/en-us/windows/wsl/install-win10>`__.

La opción que te voy a recomendar es instalar el sistema operativo en una memoria USB externa.

Vas a necesitar dos memorias USB. Una grande (> 16GB), donde instalarás tu sistema operativo
y otra más pequeña (8GB) donde grabaras el instalador. Trata de utilizar la USB más rápida y
más grande para instalar tu sistema operativo.

Te voy a dejar unos videos de ayuda:

* Este `video <https://www.youtube.com/watch?v=zSGZe8NSEAc>`__ 
  te muestra como grabar en la USB pequeña el instalador. En este caso la distribución es PopOS,
  es la misma que yo uso; sin embargo, puedes grabar la que más te guste, por ejemplo Ubuntu.
  Ten presente que la versión del video no será la última. También, debes investigar
  cómo entrar al menú de configuración de tu BIOS para que ajustes el orden de boot. 
  Nota que debes darle prioridad a la USB para que al tenerla conectada arranques el 
  instalador del sistema operativo.

* Ahora, este video `video <https://www.youtube.com/watch?v=RR9Vgytjj24>`__ te mostrará
  cómo instalar, usando la USB pequeña con el instalador, tu sistema operativo en la USB grande.
  Te recomiendo iniciar a ver el video en el minuto 6:29, donde comienza en si el proceso
  de instalación. Una vez termines de instalar Linux en la USB grande, NO OLVIDES desconectar la USB
  pequeña para que tu computador inicie con la versión instalada de Linux en la USB grande.

* Si tu computador no arranca en Linux debes reiniciarlo y entrar el menu de boot (debes indagar 
  cómo hacerlo en tu computador) y seleccionar Linux.

Si lo anterior no te funciona, prueba con una máquina virtual o con WSL2.

Ejercicio 2: instala las herramientas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Una vez tengas Linux instalado instala unas cuentas herramientas:

Abren la terminal y ejecuta los comandos:

.. code-block:: bash

    $ sudo apt update
    $ sudo apt install build-essential
    $ sudo apt install gdb

Ejercicio 3: instala un par de entornos de desarrollo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para el curso te recomiendo que instales dos entornos de desarrollo:

#. `Eclipse <https://www.eclipse.org/downloads/packages/>`__
#. `Visual Studio Code <https://code.visualstudio.com/>`__

Eclipse te permitirá tener un depurador visual de código, pero la verdad
es un poco lento. Visual Studio, no tiene un depurador visual tan rico, pero es
muy liviano. Yo uso ambos. Normalmente trabajo con Visual Studio Code y cuando
algo no me funciona lo pruebo con Eclipse.

Ejercicio 4: línea de comandos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te propongo que te familiarices un poco más con la terminal o línea de comandos 
de tu sistema operativo.

Para ello te propongo realizar la siguiente
`guía <https://drive.google.com/open?id=11tTtbCuVjYcBBYPrULbCeb0PABJLyhGEtzRGKMRG5u0>`__.

Ejercicio 5: lenguaje de programación C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En esta unidad vamos a aprender un nuevo lenguaje de programación. 
Es simple pero muy poderoso. En este 
`enlace <https://drive.google.com/file/d/1wiyBZL0kf1cQekHPfa7URcOxSpnfKE7-/view?usp=sharing>`__
encontrarás una guía básica del lenguaje C.

.. note::
    ¡Alerta de Spoiler!

    En este `enlace <https://drive.google.com/file/d/174GYcz_in94R_z6NklA02yzmsj3OuD5f/view?usp=sharing>`__
    , se encuentra la solución a algunos puntos de la guía introductoria a C (ojo, no todos). 
    Te recomiendo hacer los ejercicios sin recurrir a la solución.

Ejercicio 6: continuemos estudiando C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Primero te voy a proponer que hagas dos guía para que trabajes los conceptos
básicos y luego una serie de ejercicios que te permitirán practicar varias
de las cosas que has hecho hasta ahora.

Realiza `esta <https://drive.google.com/file/d/19NmKVXEYB5Ud0SqbBwAe4HVYMD6LDHKD/view>`__ 
guía sobre punteros, arreglos y memoria dinámica.

.. note::
        ¡Alerta de Spoiler!
    
    En este `enlace <https://docs.google.com/presentation/d/1eCo1pCzYd0YB1dYhTLJNV8w9lVAQVX6u4LQEq1oHtH0/edit#slide=id.p9>`__
    se encuentra la solución a la guía de punteros, arreglos y memoria dinámica.

Realiza `esta <https://drive.google.com/open?id=1hBPkoUsGUmatr3tRm5ztr-s3hyc3OLhl>`__ 
guía sobre estructuras de datos y archivos.

.. note::
        ¡Alerta de Spoiler!

    La solución a algunos puntos la puedes consultar `aquí <https://drive.google.com/file/d/1FWuPqJNWvEvHp89-ADvKu7XqdAZR6fx2/view?usp=sharing>`__ 

Ejercicio 7: entrada/salida
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

Ejercicio 8: entrada/salida
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

Ejercicio 9: scanf return
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

Ejercicio 10: cadenas
^^^^^^^^^^^^^^^^^^^^^^

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

Ejercicio 11
^^^^^^^^^^^^^^^^

Repite el ejercicio anterior pero esta vez compilando
sin ``-fno-stack-protector``.

Ejercicio 12
^^^^^^^^^^^^^^

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

Ejercicio 13
^^^^^^^^^^^^^^^^

Usando el código anterior ingresa:  juan fernado franco.
¿Cuál es el resultado?

Ejercicio 14
^^^^^^^^^^^^^^^^

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

Ejercicio 15
^^^^^^^^^^^^^

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

Ejercicio 16
^^^^^^^^^^^^^^

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

Ejercicio 17: análisis de una expresión más compleja
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

Ejercicio 18
^^^^^^^^^^^^^

Te propongo que realices un programa que:

* Solicite el tamaño de un arreglo.
* Solicite uno por uno sus elementos.
* Realiza una función para imprimir el contenido del arreglo. A esta
  función deberás pasar la dirección del arreglo y el tamaño.
* Solicite insertar un nuevo elemento en el
  arreglo mediante la selección de la posición deseada. La posición
  será un número de 1 hasta en el tamaño del arreglo.

Trata de PENSARLE UNOS MINUTOS. Más abajo está la solución.

.. note::
    ¡Alerta de Spoiler!

El siguiente código muestra una posible solución:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #define MAX 100

    void printArray(int *pdata,int n){

        printf("\n The array is: \n");

        for(int i = 0; i< n ;i++) {
            printf("data[%d]: %d\n",i,  *(pdata+i) );
        }
    }

    int main(){
        int n;
        int data[MAX];
        int position;

        printf("Enter the length of the array: ");
        scanf("%d", &n);
        printf("Enter %d elements of the array \n",n);

        for(int i = 0; i < n; i++){
            scanf("%d", &data[i]);
        }
        printArray(data, n);

        printf("\n Enter a position where you want to insert: ");
        scanf("%d", &position);
        position--;
        for(int i = n-1;i >= position; i--){
            data[i+1] = data[i];
        }
        printf("\nEnter the value: ");
        scanf("%d", &data[position]);

        printArray(data,n+1);
        return 0;
    }

Ejercicio 19
^^^^^^^^^^^^^^^^

Repasa el manejo de archivos y la gestión de errores. 
Lee esta información:

* `Manejo básico <https://www.geeksforgeeks.org/basics-file-handling-c/>`__
* `¿Fin de un archivo o un error? <https://www.geeksforgeeks.org/eof-and-feof-in-c/>`__
* `¿Cómo vamos a gestionar los errores en C? <https://www.geeksforgeeks.org/error-handling-c-programs/>`__

Ejercicio 20
^^^^^^^^^^^^^^^

Analiza con detenimiento el siguiente ejemplo:

* Utiliza el *debugger* de eclipse.
* Mira cómo se guardan las cadenas en memoria.

.. code-block:: c
   :linenos:

    #include <stdio.h>

    char nombres[3][20] = {"fulano","mengano","perano"};

    int main (void){

        char *a;
        char (*b)[20];
        char *c;
        char (*d)[3][20];

        a = &nombres[0][0];
        printf("el nombre es %s \n", a);
        b = nombres;
        c = &nombres[0][0];
        d = &nombres;

        for(int i = 0; i < 3; i++ ){
            printf("char (*)[] el nombre[%d] es %s \n", i , (char * ) (b+i));
            printf("char *: el nombre[%d] es %s \n", i , (char * ) ( c + (i*2) ));
            printf("char (*)[][]: el nombre[%d] es %s \n", i , (char * ) (d+i));
        }
        return 0;
    }

Ejercicio 21
^^^^^^^^^^^^^^

Escribe una función que te permita encontrar los elementos comunes de
dos arreglos de enteros. El encabezado de la función es:

.. code-block:: c
   :linenos:


    uint8_t arrayCommon(int32_t* arr1, int32_t arr1Size,int32_t* arr2, int32_t arr2Size, int32_t* arrRes, int32_t arrResSize)

* La función debe recibir las direcciones de memoria de los dos arreglos
  a comparar y del arreglo resultado. También debe recibir el tamaño de
  cada arreglo.
* Debe devolver la cantidad de elementos comunes encontrados o 0 si no
  encuentra.
* Incluye el archivo de cabeceras ``#include <stdint.h>`` para que el
  compilador encuentra la definición de ``uint8_t``.
* Crea un programa que solicite el tamaño de los arreglos y sus
  elementos.
* El programa debe mostrar el resultado de la función.
* Antes de insertar un elemento en el arreglo resultado debe verificar
  que este no exista en el arreglo, es decir, el arreglo resultado
  no debe tener elementos repetidos.

El flujo del programa será:

* Solicite el tamaño del primer arreglo.
* Ingrese los elementos del primer arreglo.
* Solicite el tamaño del segundo arreglo.
* Ingrese los elementos del segundo arreglo.
* Indicar cuántos elementos comunes se encontraron y el arreglo
  con dichos elementos.

Ejercicio 22
^^^^^^^^^^^^^^

En este ejercicio te propongo encriptar y desencriptar un archivo

Se busca realizar dos programas que permitan encriptar
y desencriptar un archivo.

El programa que encripta:

* Debe solicitar al usuario la función para encriptar
  la información y el nombre del archivo de entrada y
  el de salida. El archivo de entrada tendrá la
  información y el de salida la información encriptada.
* La función debe modificar cada uno de los bytes que
  componen el archivo. Tenga presente que también se
  encriptará el byte de nueva línea.

El programa que desencripta:

* Debe solicitar al usuario la función para encriptar
  la información y el nombre del archivo de entrada y
  el de salida. En este caso el archivo de entrada
  tendrá la información encriptada y el archivo de salida
  la información desencriptada.
* Tenga presente que el usuario ingresa la función
  con la cual se encripta y usted debe encontrar la
  función inversa para desencriptar.

.. note::
    ¡Alerta de Spoiler!

Te dejo una posible solución al ejercicio. Ten en cuenta, que voy
a obviar todas las verificaciones de error para mantener
el código compacto y te puedas concentrar justo en la
funcionalidad solicitada.

.. warning:: Este código asumen que la información ingresada está
             bien formateada y libre de errores. Por tanto, se omiten
             algunas verificaciones.

.. note:: Para probar los siguientes programas (es el mismo para encriptar
          y desencriptar) es necesario que crees el archivo de texto que
          será encriptado.

.. code-block:: c
    :linenos:

    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    uint8_t encXorFunction(uint8_t data) { return data ^ 0xFF; }

    int main(int argc, char *argv[]) {
    char input[50];
    char inFile[20];
    char outFile[20];
    char function[10];
    uint8_t (*encFuntion)(uint8_t) = NULL;

    printf("Enter in_file out_file function\n");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s %s %s", inFile, outFile, function);

    FILE *fin = fopen(inFile, "r");
    if (fin == NULL) {
        perror("Error: ");
        return EXIT_FAILURE;
    }

    if (strncmp("xor", function, 3) == 0) {
        encFuntion = &encXorFunction;
    }

    FILE *fout = fopen(outFile, "w");
    if (fout == NULL) {
        perror("Error: ");
        return EXIT_FAILURE;
    }

    while ( fgets(input, sizeof(input), fin) != NULL) {

        int n = strlen(input);

        for (int i = 0; i < n; i++) {
        input[i] = (*encFuntion)(input[i]);
        }
        fputs(input, fout);
    }

    fclose(fin);
    fclose(fout);
    return EXIT_SUCCESS;
    }

Ejercicio 23
^^^^^^^^^^^^^^

Modifica el código anterior para que reciba
la información como argumentos de la función main,
al ejecutar el programa. NO DEBES SOLICITAR información
al usuario, todas la información será pasada cuando
se invoque el ejecutable en línea de comandos.

Ejercicio 24
^^^^^^^^^^^^^^

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

Ejercicio 25
^^^^^^^^^^^^^^

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
	#define MAP(val,m,c) val*m+c

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

Ejercicio 26
^^^^^^^^^^^^^^

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


Ejercicio 27
^^^^^^^^^^^^^^

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

Ejercicio 28
^^^^^^^^^^^^^^

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

.. code-block:: bash

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

Ejercicio 29
^^^^^^^^^^^^^^

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

Ejercicio 30
^^^^^^^^^^^^^

En cuanto a la fase de ensamblado, ya te comenté que el archivo de salida contiene lenguaje de máquina
de la CPU específica. Cada sistema operativo maneja su propio formato de archivo de salida del ensamblador
o código objeto relocalizable (relocatable object file), es por ello que aunque el computador sea el mismo,
si instalas diferentes sistemas operativos, cada uno tendrá su propio ensamblador y su propio formato
de object file. Por tanto, un archivo de salida del ensamblador no solo contiene instrucciones específicas
de la CPU, sino que también estará organizado según la conveniencia de cada sistema operativo.
Y es por esto, entre otras cosas, que Windows no podrá ejecutar tal cual los programas compilados
para Linux, así estés corriendo los sistemas operativos en el mismo computador.

Ejercicio 31
^^^^^^^^^^^^^^

No te lo dije, pero cuando compilas un programa en C la única salida del programa no tiene que ser
un ejecutable. Te cuento que tienes más posibilidades:

* Puedes generar un ejecutable, usualmente con extensión ``.out`` equivalente al ``.exe`` de Windows.
* Puedes generar una biblioteca estática con extensión ``.a`` equivalente a los archivos ``.lib``
  de Windows.
* Puedes generar una biblioteca dinámica con extensión ``.so`` equivalente a los ``.dll`` en Windows.

Los object file de los que hablamos en el ejercicio anterior son el producto de la fase de ensamblado.
Recuerda que se denominan relocatable object files. Para poder tener un ejecutable, recuerda que necesitas
una fase más: el enlazado. La fase de enlazado te permite combinar varios relocatable object files y
bibliotecas para generar ejecutables o bibliotecas.

Ejercicio 32
^^^^^^^^^^^^^^

¿Qué necesitas para correr el archivo ejecutable en un sistema operativo? pues necesitas que el sistema
operativo cree una abstracción denominada PROCESO. Por medio de esta abstracción el sistema operativo
administrará cuándo se ejecutarán, por parte de alguno de los CORE disponibles, el flujo de instrucciones
definido en el archivo ejecutable. Como te has podido dar cuenta, la ejecución de un programa en C comienza
llamando la función ``main``; sin embargo, el punto de entrada de un archivo ejecutable no es la función
``main``, sino otro punto que tendrá definidas las instrucciones necesarias para preparar el llamado a main.

Cuando enlazas un programa puedes usar bibliotecas estáticas o dinámicas. El código de la biblioteca
estática hará parte del archivo ejecutable. En contraste, el código de la biblioteca dinámica no será
parte del ejecutable; sin embargo, el archivo ejecutable si tendrá que indicar qué dependencias a
bibliotecas dinámicas tiene. De esta manera cuando quieras ejecutar el archivo, el sistema operativo tendrá
que cargar EN TIEMPO DE EJECUCIÓN el código de la biblioteca necesaria.

Ejercicio 33
^^^^^^^^^^^^^^

¿Qué es un biblioteca estática? es un archivo contenedor de múltiples relocatable object files. Este
archivo no es producido por el enlazador. En sistemas como Linux será el programa ``ar`` quien
lo generará. Como las bibliotecas estáticas son colecciones de relocatable object files, estas
pueden ser enlazadas con otros object files para producir ejecutables. De esta manera, la biblioteca
estática HARÁ PARTE DEL EJECUTABLE.

Ejercicio 34
^^^^^^^^^^^^^^

¿Y qué es una biblioteca dinámica? es un archivo creado directamente por el enlazador. Es 
similar en estructura a los archivos ejecutables, pero NO LO PUEDES EJECUTAR directamente. Una
biblioteca dinámica no tiene punto de entrada como un ejecutable. Más bien tiene pedazos de código
que pueden ser llamados por el programa. Lo más interesante de todo, es que puedes tener muchos
programas que dependan de la misma biblioteca. Aquí es donde brilla el sistema operativo. Este
te permitirá que varios procesos puedan compartir la misma biblioteca. Por tanto, a diferencia
de una biblioteca estática, las bibliotecas dinámicas no hacen parte del archivo ejecutable
de un programa, sino que son cargadas en la memoria del computador en tiempo de ejecución y
son compartidas por múltiples procesos. ¡QUE BELLEZA!

Ejercicio 35
^^^^^^^^^^^^^^

¿Y cómo funciona un enlazador? ya sabes que un enlazador toma varios relocatable object files
y los combina para generar un ejecutable. pero ¿Cómo los combina? para responder esta pregunta
debemos indagar al interior de un relocatable object file. Ya sabes que estos archivos tienen
instrucciones de máquina, pero organizadas en secciones denominadas SÍMBOLOS. Para entender mejor
hagamos un ejemplo. Escribo los siguientes códigos:


functions.c:

.. code-block:: c
   :linenos:

    int suma(int a, int b) {
        return (a + b);
    }

    int sumatoria(int* numeros, int cantidad) {
        int acumulado = 0;
        for (int i = 0; i < cantidad; i++) {
            acumulado += numeros[i];
        }
        return acumulado;
    }

Compila el archivo anterior para producir un relocatable object file:

``gcc -Wall -c functions.c -o functions.o``

Ahora observa los símbolos definidos en functions.o utilizando el siguiente comando:

``nm functions.o``

El resultado será:

.. code-block:: c

    0000000000000000 T suma
    0000000000000018 T sumatoria

Nota que los dos símbolos encontrados son precisamente los nombres de las funciones
definidas en ``functions.c``. Ahora ejecuta el siguiente comando que te dará más detalles
acerca de los símbolos en ``functions.o``:

``readelf -s functions.o``

Obtendrás esto:

.. code-block:: bash

    Symbol table '.symtab' contains 11 entries:
    Num:    Value          Size Type    Bind   Vis      Ndx Name
      0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
      1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS functions.c
      2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 
      3: 0000000000000000     0 SECTION LOCAL  DEFAULT    2 
      4: 0000000000000000     0 SECTION LOCAL  DEFAULT    3 
      5: 0000000000000000     0 SECTION LOCAL  DEFAULT    5 
      6: 0000000000000000     0 SECTION LOCAL  DEFAULT    6 
      7: 0000000000000000     0 SECTION LOCAL  DEFAULT    7 
      8: 0000000000000000     0 SECTION LOCAL  DEFAULT    4 
      9: 0000000000000000    24 FUNC    GLOBAL DEFAULT    1 suma
     10: 0000000000000018    73 FUNC    GLOBAL DEFAULT    1 sumatoria

Nota varias cosas interesantes:

* La dirección asociada a los símbolos suma y sumatoria es relativa a 0. Esto ocurrirá
  con cada relocatable object file. Por tanto será responsabilidad del enlazador ubicar
  los símbolos en una dirección apropiada una vez se mezclen los archivos para formar
  el ejecutable.
* Hay algunos símbolos marcados como LOCAL y otros GLOBAL. Nota que suma y sumatoria
  son GLOBAL, por tanto estarán visibles al momento de combinarlos con otros relocatable
  object files.

Ya hemos dicho en varias oportunidades que los relocatable object files incluyen
el código de máquina del programa. Lo puedes observar con el siguientes comando:

``objdump -d functions.o``

.. code-block:: bash

    functions.o:     file format elf64-x86-64


    Disassembly of section .text:

    0000000000000000 <suma>:
        0:	f3 0f 1e fa          	endbr64 
        4:	55                   	push   %rbp
        5:	48 89 e5             	mov    %rsp,%rbp
        8:	89 7d fc             	mov    %edi,-0x4(%rbp)
        b:	89 75 f8             	mov    %esi,-0x8(%rbp)
        e:	8b 55 fc             	mov    -0x4(%rbp),%edx
        11:	8b 45 f8             	mov    -0x8(%rbp),%eax
        14:	01 d0                	add    %edx,%eax
        16:	5d                   	pop    %rbp
        17:	c3                   	retq   

    0000000000000018 <sumatoria>:
        18:	f3 0f 1e fa          	endbr64 
        1c:	55                   	push   %rbp
        1d:	48 89 e5             	mov    %rsp,%rbp
        20:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
        24:	89 75 e4             	mov    %esi,-0x1c(%rbp)
        27:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
        2e:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
        35:	eb 1d                	jmp    54 <sumatoria+0x3c>
        37:	8b 45 fc             	mov    -0x4(%rbp),%eax
        3a:	48 98                	cltq   
        3c:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
        43:	00 
        44:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
        48:	48 01 d0             	add    %rdx,%rax
        4b:	8b 00                	mov    (%rax),%eax
        4d:	01 45 f8             	add    %eax,-0x8(%rbp)
        50:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
        54:	8b 45 fc             	mov    -0x4(%rbp),%eax
        57:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
        5a:	7c db                	jl     37 <sumatoria+0x1f>
        5c:	8b 45 f8             	mov    -0x8(%rbp),%eax
        5f:	5d                   	pop    %rbp
        60:	c3                   	retq 

Recuerdas cuando programaste en ensamblador el computador Hack? pues bueno
aquí tienes código ensamblador y su equivalente código de máquina para
el procesador de tu computador.

Ahora vamos a realizar otro ejemplo donde verás cómo se combinan varios
relocatable object files para producir un ejecutable:

file1.h:

.. code-block:: c
   :linenos:

    #ifndef _FILE1_H
    #define _FILE1_H

    int suma(int, int);
    int multiplicacion(int, int);

    #endif

file2.c:

.. code-block:: c
   :linenos:

    int suma(int a, int b){
        return (a+b);
    }

file3.c:

.. code-block:: c
   :linenos:

    int multiplicacion(int a, int b){
        return a*b;
    }

main.c:

.. code-block:: c
   :linenos:

    #include "file1.h"

    int main(int argc, char* argv[]) {
        int a = suma(4, 5);
        int b = multiplicacion(9, a);
        return b;
    }

Nota que ``main.c`` debe incluir ``file.h`` donde están las declaraciones de
las funciones suma y multiplicacion. Esto es necesario en C para poder
utilizar las funciones. 

Vamos a compilar los programas:

``gcc -Wall -c file2.c -o file2.o``

``gcc -Wall -c file3.c -o file3.o``

``gcc -Wall -c main.c -o main.o``

Ahora observamos de nuevo las tablas de símbolos de cada relocatable object file:

.. code-block:: bash

    $ readelf -s file2.o

    Symbol table '.symtab' contains 10 entries:
          Num:    Value          Size Type    Bind   Vis      Ndx Name
            0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
            1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS file2.c
            2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 
            3: 0000000000000000     0 SECTION LOCAL  DEFAULT    2 
            4: 0000000000000000     0 SECTION LOCAL  DEFAULT    3 
            5: 0000000000000000     0 SECTION LOCAL  DEFAULT    5 
            6: 0000000000000000     0 SECTION LOCAL  DEFAULT    6 
            7: 0000000000000000     0 SECTION LOCAL  DEFAULT    7 
            8: 0000000000000000     0 SECTION LOCAL  DEFAULT    4 
            9: 0000000000000000    24 FUNC    GLOBAL DEFAULT    1 suma

    $ readelf -s file3.o

    Symbol table '.symtab' contains 10 entries:
          Num:    Value          Size Type    Bind   Vis      Ndx Name
            0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
            1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS file3.c
            2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 
            3: 0000000000000000     0 SECTION LOCAL  DEFAULT    2 
            4: 0000000000000000     0 SECTION LOCAL  DEFAULT    3 
            5: 0000000000000000     0 SECTION LOCAL  DEFAULT    5 
            6: 0000000000000000     0 SECTION LOCAL  DEFAULT    6 
            7: 0000000000000000     0 SECTION LOCAL  DEFAULT    7 
            8: 0000000000000000     0 SECTION LOCAL  DEFAULT    4 
            9: 0000000000000000    23 FUNC    GLOBAL DEFAULT    1 multiplicacion

    $ readelf -s main.o

    Symbol table '.symtab' contains 13 entries:
          Num:    Value          Size Type    Bind   Vis      Ndx Name
            0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
            1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS main.c
            2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 
            3: 0000000000000000     0 SECTION LOCAL  DEFAULT    3 
            4: 0000000000000000     0 SECTION LOCAL  DEFAULT    4 
            5: 0000000000000000     0 SECTION LOCAL  DEFAULT    6 
            6: 0000000000000000     0 SECTION LOCAL  DEFAULT    7 
            7: 0000000000000000     0 SECTION LOCAL  DEFAULT    8 
            8: 0000000000000000     0 SECTION LOCAL  DEFAULT    5 
            9: 0000000000000000    60 FUNC    GLOBAL DEFAULT    1 main
            10: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND _GLOBAL_OFFSET_TABLE_
            11: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND suma
            12: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND multiplicacion

Puedes ver que en la tabla de símbolos de main.o, suma y multiplicacion
se marcan como GLOBAL y muestra que no están definidos (UND), es decir, no
sabemos dónde está el código de ambas funciones.

Ahora necesitamos pasar estos tres archivo ``.o`` al enlazador para
unirlos y generar el ejecutable:

``gcc -Wall file2.o file3.o main.o -o exe``

El ejecutable se generó correctamente. Incluso puedes ejecutarlo. Puedes
ver el valor retornado por la función main con el comando echo $?

Recuerdas que en un ejercicio anterior te comenté que el punto de entrada
de un archivo ejecutable no es la función ``main``, sino otro punto que 
tendrá definidas las instrucciones necesarias para preparar el llamado a main.
¿Dónde está el código que hace lo anterior? si ejecutas el comando 
``readelf -d exe | grep '(NEEDED)'``

.. code-block:: c

     0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]

Observarás que nuestro ejecutable exe dependerá de una biblioteca dinámica
llamada ``libc``. El enlazado con esta biblioteca lo hace por nosotros gcc
y como ya te habrás dado cuenta esta biblioteca incluye el código de entrada
que prepará el entorno del programa para poder llamar a la función main.

Modifica el archivo main.c:

.. code-block:: c
   :linenos:

    #include "file1.h"
    #include <stdio.h>
    
    int main(int argc, char* argv[]) {
        int a = suma(4, 5);
        int b = multiplicacion(9, a);
        printf("b value is: %d",b);
        return 0;
    }

Compila de nuevo el archivo main.c. ``gcc -Wall -c main.c -o main.o``. Observa
la tabla de símbolos:

.. code-block:: bash

    readelf -s main.o

    Symbol table '.symtab' contains 15 entries:
          Num:    Value          Size Type    Bind   Vis      Ndx Name
            0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
            1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS main.c
            2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 
            3: 0000000000000000     0 SECTION LOCAL  DEFAULT    3 
            4: 0000000000000000     0 SECTION LOCAL  DEFAULT    4 
            5: 0000000000000000     0 SECTION LOCAL  DEFAULT    5 
            6: 0000000000000000     0 SECTION LOCAL  DEFAULT    7 
            7: 0000000000000000     0 SECTION LOCAL  DEFAULT    8 
            8: 0000000000000000     0 SECTION LOCAL  DEFAULT    9 
            9: 0000000000000000     0 SECTION LOCAL  DEFAULT    6 
            10: 0000000000000000    84 FUNC    GLOBAL DEFAULT    1 main
            11: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND _GLOBAL_OFFSET_TABLE_
            12: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND suma
            13: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND multiplicacion
            14: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND printf

Nota que ahora aparece como un símbolo global la función printf. Además
dice que no está definido el símbolo

Genera el ejecutable: ``gcc -Wall file2.o file3.o main.o -o exe``. Observa que no
salió error. Quiere decir que el enlazador encontró la definición del símbolo
printf. ¿Pero dónde? ejecuta de nuevo: ``readelf -d exe | grep '(NEEDED)'``

.. code-block:: c
    
    0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]

Ah!!! la definición de printf también está en la biblioteca libc. Solo
por curiosidad, ¿En dónde está la biblioteca? ejecuta ``whereis libc.so.6``

.. code-block:: c

    libc.so: /usr/lib/x86_64-linux-gnu/libc.so.6 /usr/lib/x86_64-linux-gnu/libc.so

Ejercicio 36
^^^^^^^^^^^^^^

El ejercicio anterior va muy largo, pero podemos seguir experimentando:

Prueba ahora haciendo esto ``gcc -Wall file2.o main.o``

Obtendrás esto:

.. code-block:: c

    /usr/bin/ld: main.o: in function main:
    main.c:(.text+0x30): undefined reference to multiplicacion
    collect2: error: ld returned 1 exit status

¿Qué pasó? en este caso el enlazador no encontró el símbolo multiplicacion
definido en ninguna parte y por tanto no es posible generar el ejecutable.

Los símbolos suma y multiplicacion los tenemos definidos. Entonces que tal
si hacemos esto: ``gcc -Wall file2.o file3.o`` ¿Obtenemos un ejecutable?

.. code-block:: c

    /usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/Scrt1.o: in function _start:
    (.text+0x24): undefined reference to main
    collect2: error: ld returned 1 exit status

¿Qué pasó? Muy interesante, nota que para generar el ejecutable el enlazador
está mezclando nuestro código con otro relocatable object file: ``Scrt1.o``. En
este archivo hay una función llamada ``_start``. Lo que acabamos de descubrir
es que esa función está llamando a la función main. ¿Pero dónde está la función main? pues
nota que al generar el ejecutable no le entregamos al enlazador ningún archivo con
la definición de main. Por tanto, el enlazador no puede generar el ejecutable.

Ejercicio 37
^^^^^^^^^^^^^^

En el ejercicio anterior vimos que nuestro programa está llamando a la función _start quien
luego llama a la función main. Vimos que la función _start el enlazador la toma del
archivo Scrt1.o. ¿Podemos ver el código ensamblador final del programa?

Ejecuta estos comandos:

``objdump -f ex`` 

Este comando te permitirá ver la dirección en la cuál iniciará la ejecución de nuestro programa:

.. code-block:: c

    exe:     file format elf64-x86-64
    architecture: i386:x86-64, flags 0x00000150:
    HAS_SYMS, DYNAMIC, D_PAGED
    start address 0x0000000000001060

El programa arranca en la dirección ``0x0000000000001060``. Ejecuta: ``objdump --disassemble exe``
y podrás ver que en esa dirección efectivamente está la función ``_start``

.. code-block:: bash

    Disassembly of section .init:

    0000000000001000 <_init>:
        1000:	f3 0f 1e fa          	endbr64 
        1004:	48 83 ec 08          	sub    $0x8,%rsp
        1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
        100f:	48 85 c0             	test   %rax,%rax
        1012:	74 02                	je     1016 <_init+0x16>
        1014:	ff d0                	callq  *%rax
        1016:	48 83 c4 08          	add    $0x8,%rsp
        101a:	c3                   	retq   

    Disassembly of section .plt:

    0000000000001020 <.plt>:
        1020:	ff 35 9a 2f 00 00    	pushq  0x2f9a(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x8>
        1026:	f2 ff 25 9b 2f 00 00 	bnd jmpq *0x2f9b(%rip)        # 3fc8 <_GLOBAL_OFFSET_TABLE_+0x10>
        102d:	0f 1f 00             	nopl   (%rax)
        1030:	f3 0f 1e fa          	endbr64 
        1034:	68 00 00 00 00       	pushq  $0x0
        1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
        103f:	90                   	nop

    Disassembly of section .plt.got:

    0000000000001040 <__cxa_finalize@plt>:
        1040:	f3 0f 1e fa          	endbr64 
        1044:	f2 ff 25 ad 2f 00 00 	bnd jmpq *0x2fad(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
        104b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

    Disassembly of section .plt.sec:

    0000000000001050 <printf@plt>:
        1050:	f3 0f 1e fa          	endbr64 
        1054:	f2 ff 25 75 2f 00 00 	bnd jmpq *0x2f75(%rip)        # 3fd0 <printf@GLIBC_2.2.5>
        105b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

    Disassembly of section .text:

    0000000000001060 <_start>:
        1060:	f3 0f 1e fa          	endbr64 
        1064:	31 ed                	xor    %ebp,%ebp
        1066:	49 89 d1             	mov    %rdx,%r9
        1069:	5e                   	pop    %rsi
        106a:	48 89 e2             	mov    %rsp,%rdx
        106d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
        1071:	50                   	push   %rax
        1072:	54                   	push   %rsp
        1073:	4c 8d 05 c6 01 00 00 	lea    0x1c6(%rip),%r8        # 1240 <__libc_csu_fini>
        107a:	48 8d 0d 4f 01 00 00 	lea    0x14f(%rip),%rcx        # 11d0 <__libc_csu_init>
        1081:	48 8d 3d f0 00 00 00 	lea    0xf0(%rip),%rdi        # 1178 <main>
        1088:	ff 15 52 2f 00 00    	callq  *0x2f52(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
        108e:	f4                   	hlt    
        108f:	90                   	nop

    0000000000001090 <deregister_tm_clones>:
        1090:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4010 <__TMC_END__>
        1097:	48 8d 05 72 2f 00 00 	lea    0x2f72(%rip),%rax        # 4010 <__TMC_END__>
        109e:	48 39 f8             	cmp    %rdi,%rax
        10a1:	74 15                	je     10b8 <deregister_tm_clones+0x28>
        10a3:	48 8b 05 2e 2f 00 00 	mov    0x2f2e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
        10aa:	48 85 c0             	test   %rax,%rax
        10ad:	74 09                	je     10b8 <deregister_tm_clones+0x28>
        10af:	ff e0                	jmpq   *%rax
        10b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
        10b8:	c3                   	retq   
        10b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

    00000000000010c0 <register_tm_clones>:
        10c0:	48 8d 3d 49 2f 00 00 	lea    0x2f49(%rip),%rdi        # 4010 <__TMC_END__>
        10c7:	48 8d 35 42 2f 00 00 	lea    0x2f42(%rip),%rsi        # 4010 <__TMC_END__>
        10ce:	48 29 fe             	sub    %rdi,%rsi
        10d1:	48 89 f0             	mov    %rsi,%rax
        10d4:	48 c1 ee 3f          	shr    $0x3f,%rsi
        10d8:	48 c1 f8 03          	sar    $0x3,%rax
        10dc:	48 01 c6             	add    %rax,%rsi
        10df:	48 d1 fe             	sar    %rsi
        10e2:	74 14                	je     10f8 <register_tm_clones+0x38>
        10e4:	48 8b 05 05 2f 00 00 	mov    0x2f05(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
        10eb:	48 85 c0             	test   %rax,%rax
        10ee:	74 08                	je     10f8 <register_tm_clones+0x38>
        10f0:	ff e0                	jmpq   *%rax
        10f2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
        10f8:	c3                   	retq   
        10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

    0000000000001100 <__do_global_dtors_aux>:
        1100:	f3 0f 1e fa          	endbr64 
        1104:	80 3d 05 2f 00 00 00 	cmpb   $0x0,0x2f05(%rip)        # 4010 <__TMC_END__>
        110b:	75 2b                	jne    1138 <__do_global_dtors_aux+0x38>
        110d:	55                   	push   %rbp
        110e:	48 83 3d e2 2e 00 00 	cmpq   $0x0,0x2ee2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
        1115:	00 
        1116:	48 89 e5             	mov    %rsp,%rbp
        1119:	74 0c                	je     1127 <__do_global_dtors_aux+0x27>
        111b:	48 8b 3d e6 2e 00 00 	mov    0x2ee6(%rip),%rdi        # 4008 <__dso_handle>
        1122:	e8 19 ff ff ff       	callq  1040 <__cxa_finalize@plt>
        1127:	e8 64 ff ff ff       	callq  1090 <deregister_tm_clones>
        112c:	c6 05 dd 2e 00 00 01 	movb   $0x1,0x2edd(%rip)        # 4010 <__TMC_END__>
        1133:	5d                   	pop    %rbp
        1134:	c3                   	retq   
        1135:	0f 1f 00             	nopl   (%rax)
        1138:	c3                   	retq   
        1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

    0000000000001140 <frame_dummy>:
        1140:	f3 0f 1e fa          	endbr64 
        1144:	e9 77 ff ff ff       	jmpq   10c0 <register_tm_clones>

    0000000000001149 <suma>:
        1149:	f3 0f 1e fa          	endbr64 
        114d:	55                   	push   %rbp
        114e:	48 89 e5             	mov    %rsp,%rbp
        1151:	89 7d fc             	mov    %edi,-0x4(%rbp)
        1154:	89 75 f8             	mov    %esi,-0x8(%rbp)
        1157:	8b 55 fc             	mov    -0x4(%rbp),%edx
        115a:	8b 45 f8             	mov    -0x8(%rbp),%eax
        115d:	01 d0                	add    %edx,%eax
        115f:	5d                   	pop    %rbp
        1160:	c3                   	retq   

    0000000000001161 <multiplicacion>:
        1161:	f3 0f 1e fa          	endbr64 
        1165:	55                   	push   %rbp
        1166:	48 89 e5             	mov    %rsp,%rbp
        1169:	89 7d fc             	mov    %edi,-0x4(%rbp)
        116c:	89 75 f8             	mov    %esi,-0x8(%rbp)
        116f:	8b 45 fc             	mov    -0x4(%rbp),%eax
        1172:	0f af 45 f8          	imul   -0x8(%rbp),%eax
        1176:	5d                   	pop    %rbp
        1177:	c3                   	retq   

    0000000000001178 <main>:
        1178:	f3 0f 1e fa          	endbr64 
        117c:	55                   	push   %rbp
        117d:	48 89 e5             	mov    %rsp,%rbp
        1180:	48 83 ec 20          	sub    $0x20,%rsp
        1184:	89 7d ec             	mov    %edi,-0x14(%rbp)
        1187:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
        118b:	be 05 00 00 00       	mov    $0x5,%esi
        1190:	bf 04 00 00 00       	mov    $0x4,%edi
        1195:	e8 af ff ff ff       	callq  1149 <suma>
        119a:	89 45 f8             	mov    %eax,-0x8(%rbp)
        119d:	8b 45 f8             	mov    -0x8(%rbp),%eax
        11a0:	89 c6                	mov    %eax,%esi
        11a2:	bf 09 00 00 00       	mov    $0x9,%edi
        11a7:	e8 b5 ff ff ff       	callq  1161 <multiplicacion>
        11ac:	89 45 fc             	mov    %eax,-0x4(%rbp)
        11af:	8b 45 fc             	mov    -0x4(%rbp),%eax
        11b2:	89 c6                	mov    %eax,%esi
        11b4:	48 8d 3d 49 0e 00 00 	lea    0xe49(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
        11bb:	b8 00 00 00 00       	mov    $0x0,%eax
        11c0:	e8 8b fe ff ff       	callq  1050 <printf@plt>
        11c5:	b8 00 00 00 00       	mov    $0x0,%eax
        11ca:	c9                   	leaveq 
        11cb:	c3                   	retq   
        11cc:	0f 1f 40 00          	nopl   0x0(%rax)

    00000000000011d0 <__libc_csu_init>:
        11d0:	f3 0f 1e fa          	endbr64 
        11d4:	41 57                	push   %r15
        11d6:	4c 8d 3d db 2b 00 00 	lea    0x2bdb(%rip),%r15        # 3db8 <__frame_dummy_init_array_entry>
        11dd:	41 56                	push   %r14
        11df:	49 89 d6             	mov    %rdx,%r14
        11e2:	41 55                	push   %r13
        11e4:	49 89 f5             	mov    %rsi,%r13
        11e7:	41 54                	push   %r12
        11e9:	41 89 fc             	mov    %edi,%r12d
        11ec:	55                   	push   %rbp
        11ed:	48 8d 2d cc 2b 00 00 	lea    0x2bcc(%rip),%rbp        # 3dc0 <__do_global_dtors_aux_fini_array_entry>
        11f4:	53                   	push   %rbx
        11f5:	4c 29 fd             	sub    %r15,%rbp
        11f8:	48 83 ec 08          	sub    $0x8,%rsp
        11fc:	e8 ff fd ff ff       	callq  1000 <_init>
        1201:	48 c1 fd 03          	sar    $0x3,%rbp
        1205:	74 1f                	je     1226 <__libc_csu_init+0x56>
        1207:	31 db                	xor    %ebx,%ebx
        1209:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
        1210:	4c 89 f2             	mov    %r14,%rdx
        1213:	4c 89 ee             	mov    %r13,%rsi
        1216:	44 89 e7             	mov    %r12d,%edi
        1219:	41 ff 14 df          	callq  *(%r15,%rbx,8)
        121d:	48 83 c3 01          	add    $0x1,%rbx
        1221:	48 39 dd             	cmp    %rbx,%rbp
        1224:	75 ea                	jne    1210 <__libc_csu_init+0x40>
        1226:	48 83 c4 08          	add    $0x8,%rsp
        122a:	5b                   	pop    %rbx
        122b:	5d                   	pop    %rbp
        122c:	41 5c                	pop    %r12
        122e:	41 5d                	pop    %r13
        1230:	41 5e                	pop    %r14
        1232:	41 5f                	pop    %r15
        1234:	c3                   	retq   
        1235:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
        123c:	00 00 00 00 

    0000000000001240 <__libc_csu_fini>:
        1240:	f3 0f 1e fa          	endbr64 
        1244:	c3                   	retq   

    Disassembly of section .fini:

    0000000000001248 <_fini>:
        1248:	f3 0f 1e fa          	endbr64 
        124c:	48 83 ec 08          	sub    $0x8,%rsp
        1250:	48 83 c4 08          	add    $0x8,%rsp
        1254:	c3                   	retq 


Ejercicio 38
^^^^^^^^^^^^^^

Ya viste que en C es posible incluir en el proceso de enlazado bibliotecas estáticas
y dinámicas. Ahora la idea es ver cómo las puedes incluir. Antes de ver esto, debemos
revisar algunos conceptos. Sabes qué es el Application binary interface (ABI)?

Antes de responder la pregunta, te haré otra que tal vez sea más familiar para ti.
¿Has oido hablar del API de una bilioteca? API quiere decir Application Programming
Interface. El API de una biblioteca es la interfaz pública que provee esta para
poder usar su funcionalidad. En términos prácticos, puedes pensar el API como las
CONVENCIONES que debes seguir para llamar una de las funciones de la biblioteca.

El ABI es similar al API, pero son aquellas convenciones que necesitas seguir para
que un programa pueda llamar a otro programa a nivel de LENGUAJE DE MÁQUINA. Entonces
cuando tu programa quiere utilizar una biblioteca dinámica, solo podrá usarla si
utiliza la misma ABI. Entre las conveciones que define la ABI de un sistema están:

* El set de instrucciones de la CPU, la estructura de memoria a utilizar, el ENDIAN,
  entre otros.
* Los tipos de datos, el tamaño y como se ubicarán en la memoria.
* Cómo se deben llamar las funciones (calling convection), en dónde se pasan los
  parámetros y en dónde se devuelven resultados.
* MUY IMPORTANTE: cómo se deben hacer los llamados al sistema operativo (luego hablamos
  sobre eso).
* Cómo será el formato de los relocatable object files, de las bibliotecas dinámicas, 
  de los ejecutables.
* Entre otras cosas...

En el caso de Linux, el ABI utilizada se llama 
`System V ABI <https://drive.google.com/file/d/1hF_FvOsMJsG5NxymjykvFP-L111j75TN/view?usp=sharing>`__ 
y el formato de los ejecutable `ELF <https://www.packtpub.com/product/learning-linux-binary-analysis/9781782167105>`__.
En Windows el formato de los ejecutables es `PE <https://docs.microsoft.com/en-us/windows/win32/debug/pe-format>`__


Ejercicio 40
^^^^^^^^^^^^^^

En este ejercicio vamos a analizar un poco más los relocatable object files. Recuerda que
este es el tipo de archivo que obtendrás como salida del proceso de ensamblado.
¿Qué hay en un relocatable object file? Vas a encontrar al menos estas cosas: el código del máquina,
el valor inicial de las variables globales y la tabla de símbolos.

Te has preguntado ¿Por qué tienen la palabra relocatable estos object files? Recuerda que parte
del contenido del archivo es código de máquina. Recuerda también que la idea es que estos archivos
los toma el enlazador y los combina para generar un ejecutable. Por tanto, las instrucciones contenidas
en el relocatable object file no pueden manipular direcciones de memoria absolutas. Esto permite
que el enlazador asigne esas direcciones solo después de enlazar y generar el ejecutable.

Considera este código:

funcs.c:

.. code-block:: c
   :linenos:

    int suma(int a, int b) {
        return (a + b);
    }

    int sumatoria(int* numeros, int cantidad) {
        int acumulado = 0;
        for (int i = 0; i < cantidad; i++) {
            acumulado += numeros[i];
        }
        return acumulado;
    }

Compila el programa: ``gcc -Wall -c functions.c -o functions.o``. Ahora observa el archivo
de salida: ``readelf -hSl functions.o``

.. code-block:: none

    ELF Header:
    Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
    Class:                             ELF64
    Data:                              2's complement, little endian
    Version:                           1 (current)
    OS/ABI:                            UNIX - System V
    ABI Version:                       0
    Type:                              REL (Relocatable file)
    Machine:                           Advanced Micro Devices X86-64
    Version:                           0x1
    Entry point address:               0x0
    Start of program headers:          0 (bytes into file)
    Start of section headers:          768 (bytes into file)
    Flags:                             0x0
    Size of this header:               64 (bytes)
    Size of program headers:           0 (bytes)
    Number of program headers:         0
    Size of section headers:           64 (bytes)
    Number of section headers:         12
    Section header string table index: 11

    Section Headers:
    [Nr] Name              Type             Address           Offset
        Size              EntSize          Flags  Link  Info  Align
    [ 0]                   NULL             0000000000000000  00000000
        0000000000000000  0000000000000000           0     0     0
    [ 1] .text             PROGBITS         0000000000000000  00000040
        0000000000000061  0000000000000000  AX       0     0     1
    [ 2] .data             PROGBITS         0000000000000000  000000a1
        0000000000000000  0000000000000000  WA       0     0     1
    [ 3] .bss              NOBITS           0000000000000000  000000a1
        0000000000000000  0000000000000000  WA       0     0     1
    [ 4] .comment          PROGBITS         0000000000000000  000000a1
        0000000000000025  0000000000000001  MS       0     0     1
    [ 5] .note.GNU-stack   PROGBITS         0000000000000000  000000c6
        0000000000000000  0000000000000000           0     0     1
    [ 6] .note.gnu.propert NOTE             0000000000000000  000000c8
        0000000000000020  0000000000000000   A       0     0     8
    [ 7] .eh_frame         PROGBITS         0000000000000000  000000e8
        0000000000000058  0000000000000000   A       0     0     8
    [ 8] .rela.eh_frame    RELA             0000000000000000  00000268
        0000000000000030  0000000000000018   I       9     7     8
    [ 9] .symtab           SYMTAB           0000000000000000  00000140
        0000000000000108  0000000000000018          10     9     8
    [10] .strtab           STRTAB           0000000000000000  00000248
        000000000000001c  0000000000000000           0     0     1
    [11] .shstrtab         STRTAB           0000000000000000  00000298
        0000000000000067  0000000000000000           0     0     1

Observa las secciones. La .text continen el código de máquina, la .data
tendrán los valores iniciales de las variables globales y .symtab será la tabla
de símbolos.

Ahora mira la tabla de símbolos:

``readelf -s functions.o``

.. code-block:: bash

    Symbol table '.symtab' contains 11 entries:
          Num:    Value          Size Type    Bind   Vis      Ndx Name
            0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
            1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS functions.c
            2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 
            3: 0000000000000000     0 SECTION LOCAL  DEFAULT    2 
            4: 0000000000000000     0 SECTION LOCAL  DEFAULT    3 
            5: 0000000000000000     0 SECTION LOCAL  DEFAULT    5 
            6: 0000000000000000     0 SECTION LOCAL  DEFAULT    6 
            7: 0000000000000000     0 SECTION LOCAL  DEFAULT    7 
            8: 0000000000000000     0 SECTION LOCAL  DEFAULT    4 
            9: 0000000000000000    24 FUNC    GLOBAL DEFAULT    1 suma
           10: 0000000000000018    73 FUNC    GLOBAL DEFAULT    1 sumatoria

Nota las direcciones de las funciones: 0 y 0x18. Estas direcciones no son
absolutas, son relativas. En todos los relocatable object files verás este mismo
comportamiento.

Ahora crea un nuevo archivo donde utilices las funciones de functions.c y
compila: ``gcc -Wall -c main.c -o main.o``

main.c:

.. code-block:: c
   :linenos:

    #include <stdio.h>

    int suma(int, int);
    int sumatoria(int*, int );

    int main(int argc, char* argv[]) {
        int a = suma(4, 5);
        int array[] = {1,2,3,4,5};
        int b = sumatoria(array,(sizeof(array))/(sizeof(int)));
        printf("suma(4,5): %d\n",a);
        printf("sumatoria(1..5): %d\n",b);
        return 0;
    }


Genera el ejecutable con ``gcc -Wall main.o functions.o -o exe`` y la tabla de símbolos
con ``readelf -s exe``

.. code-block:: bash

    Symbol table '.dynsym' contains 8 entries:
    Num:    Value          Size Type    Bind   Vis      Ndx Name
        0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
        1: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterTMCloneTab
        2: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __stack_chk_fail@GLIBC_2.4 (2)
        3: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND printf@GLIBC_2.2.5 (3)
        4: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __libc_start_main@GLIBC_2.2.5 (3)
        5: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
        6: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMCloneTable
        7: 0000000000000000     0 FUNC    WEAK   DEFAULT  UND __cxa_finalize@GLIBC_2.2.5 (3)

    Symbol table '.symtab' contains 69 entries:
    Num:    Value          Size Type    Bind   Vis      Ndx Name
        0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
        1: 0000000000000318     0 SECTION LOCAL  DEFAULT    1 
        2: 0000000000000338     0 SECTION LOCAL  DEFAULT    2 
        3: 0000000000000358     0 SECTION LOCAL  DEFAULT    3 
        4: 000000000000037c     0 SECTION LOCAL  DEFAULT    4 
        5: 00000000000003a0     0 SECTION LOCAL  DEFAULT    5 
        6: 00000000000003c8     0 SECTION LOCAL  DEFAULT    6 
        7: 0000000000000488     0 SECTION LOCAL  DEFAULT    7 
        8: 0000000000000528     0 SECTION LOCAL  DEFAULT    8 
        9: 0000000000000538     0 SECTION LOCAL  DEFAULT    9 
        10: 0000000000000568     0 SECTION LOCAL  DEFAULT   10 
        11: 0000000000000628     0 SECTION LOCAL  DEFAULT   11 
        12: 0000000000001000     0 SECTION LOCAL  DEFAULT   12 
        13: 0000000000001020     0 SECTION LOCAL  DEFAULT   13 
        14: 0000000000001050     0 SECTION LOCAL  DEFAULT   14 
        15: 0000000000001060     0 SECTION LOCAL  DEFAULT   15 
        16: 0000000000001080     0 SECTION LOCAL  DEFAULT   16 
        17: 00000000000012f8     0 SECTION LOCAL  DEFAULT   17 
        18: 0000000000002000     0 SECTION LOCAL  DEFAULT   18 
        19: 0000000000002028     0 SECTION LOCAL  DEFAULT   19 
        20: 0000000000002080     0 SECTION LOCAL  DEFAULT   20 
        21: 0000000000003db0     0 SECTION LOCAL  DEFAULT   21 
        22: 0000000000003db8     0 SECTION LOCAL  DEFAULT   22 
        23: 0000000000003dc0     0 SECTION LOCAL  DEFAULT   23 
        24: 0000000000003fb0     0 SECTION LOCAL  DEFAULT   24 
        25: 0000000000004000     0 SECTION LOCAL  DEFAULT   25 
        26: 0000000000004010     0 SECTION LOCAL  DEFAULT   26 
        27: 0000000000000000     0 SECTION LOCAL  DEFAULT   27 
        28: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
        29: 00000000000010b0     0 FUNC    LOCAL  DEFAULT   16 deregister_tm_clones
        30: 00000000000010e0     0 FUNC    LOCAL  DEFAULT   16 register_tm_clones
        31: 0000000000001120     0 FUNC    LOCAL  DEFAULT   16 __do_global_dtors_aux
        32: 0000000000004010     1 OBJECT  LOCAL  DEFAULT   26 completed.8059
        33: 0000000000003db8     0 OBJECT  LOCAL  DEFAULT   22 __do_global_dtors_aux_fin
        34: 0000000000001160     0 FUNC    LOCAL  DEFAULT   16 frame_dummy
        35: 0000000000003db0     0 OBJECT  LOCAL  DEFAULT   21 __frame_dummy_init_array_
        36: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS main.c
        37: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS functions.c
        38: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
        39: 00000000000021c4     0 OBJECT  LOCAL  DEFAULT   20 __FRAME_END__
        40: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS 
        41: 0000000000003db8     0 NOTYPE  LOCAL  DEFAULT   21 __init_array_end
        42: 0000000000003dc0     0 OBJECT  LOCAL  DEFAULT   23 _DYNAMIC
        43: 0000000000003db0     0 NOTYPE  LOCAL  DEFAULT   21 __init_array_start
        44: 0000000000002028     0 NOTYPE  LOCAL  DEFAULT   19 __GNU_EH_FRAME_HDR
        45: 0000000000003fb0     0 OBJECT  LOCAL  DEFAULT   24 _GLOBAL_OFFSET_TABLE_
        46: 0000000000001000     0 FUNC    LOCAL  DEFAULT   12 _init
        47: 00000000000012f0     5 FUNC    GLOBAL DEFAULT   16 __libc_csu_fini
        48: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterTMCloneTab
        49: 0000000000004000     0 NOTYPE  WEAK   DEFAULT   25 data_start
        50: 0000000000004010     0 NOTYPE  GLOBAL DEFAULT   25 _edata
        51: 00000000000012f8     0 FUNC    GLOBAL HIDDEN    17 _fini
        52: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __stack_chk_fail@@GLIBC_2
        53: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND printf@@GLIBC_2.2.5
        54: 000000000000121b    24 FUNC    GLOBAL DEFAULT   16 suma
        55: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __libc_start_main@@GLIBC_
        56: 0000000000004000     0 NOTYPE  GLOBAL DEFAULT   25 __data_start
        57: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
        58: 0000000000004008     0 OBJECT  GLOBAL HIDDEN    25 __dso_handle
        59: 0000000000002000     4 OBJECT  GLOBAL DEFAULT   18 _IO_stdin_used
        60: 0000000000001280   101 FUNC    GLOBAL DEFAULT   16 __libc_csu_init
        61: 0000000000004018     0 NOTYPE  GLOBAL DEFAULT   26 _end
        62: 0000000000001080    47 FUNC    GLOBAL DEFAULT   16 _start
        63: 0000000000004010     0 NOTYPE  GLOBAL DEFAULT   26 __bss_start
        64: 0000000000001169   178 FUNC    GLOBAL DEFAULT   16 main
        65: 0000000000001233    73 FUNC    GLOBAL DEFAULT   16 sumatoria
        66: 0000000000004010     0 OBJECT  GLOBAL HIDDEN    25 __TMC_END__
        67: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMCloneTable
        68: 0000000000000000     0 FUNC    WEAK   DEFAULT  UND __cxa_finalize@@GLIBC_2.2


Nota que te aparecen dos tablas de símbolos. .dynsym contiene los símbolos que
se deben definir en tiempo de ejecución. .symtab contiene los símbolos, es decir,
los que ya están resueltos y los que vienen de las bibliotecas dinámicas. 
¿Cuáles bibliotecas? ``readelf -d exe | grep '(NEEDED)'``


.. code-block:: c

    0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]

Ejercicio 41
^^^^^^^^^^^^^^

Ahora si vamos a probar como enlazar un programa con una bilioteca estática

Crea los siguientes archivos:

uno.c:

.. code-block:: c
   :linenos:

    int uno(){
        return 1;
    }

dos.c:

.. code-block:: c
   :linenos:

    int dos(){
        return 2;
    }

tres.c:

.. code-block:: c
   :linenos:

    int tres(){
        return 3;
    }

Compila:

``gcc -Wall -c uno.c -o uno.o``

``gcc -Wall -c dos.c -o dos.o``

``gcc -Wall -c tres.c -o tres.o``

Para generar la bilioteca estática debes seguir la convención de iniciar el nombre
con lib y colocar la extensión ``.a``:

``ar crc libstatic.a uno.o dos.o tres.o``

Puedes listar el contenido de la biblioteca con ``ar t libstatic.a``

Ahora necesitamos crear el API de la biblioteca

api.h:

.. code-block:: c
   :linenos:

    int uno();
    int dos();
    int tres();

Ahora usamos la biblioteca así

main.c:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include "api.h"

    int main(int argc, char* argv[]){

        printf("uno: %d\n",uno());
        printf("dos: %d\n",dos());
        printf("tres: %d\n",tres());

        return 0;
    }

Finalmente genera el ejecutable con ``gcc main.o -L./ -lstatic -o exe`` y
ejecuta el programa. En este caso:

* Con la opción ``-L./`` estás indicando una posible donde donde tendrás
  almacenadas bibliotecas estáticas y/o dinámicas.
* Con la opción ``-lstatic`` estás indicando que se debe utilizar la bilioteca
  libstatic.a o libstatic.so. Nota que en este caso se tiene en cuenta la
  convención, es decir, si tu pasas ``-lstatic`` el enlazador buscará
  el archivo libstatic.a o libstatic.so.
* Luego de ser enlazado el programa, ya no tendrás dependencias con la biblioteca
  estática porque está hará parte del ejecutable. Recuerda que en el caso de las
  bibliotecas dinámicas es diferente.

Ejercicio 42
^^^^^^^^^^^^^^^^^

Finalmente, vamos a probar como enlazar un programa con una bilioteca dinámica.
Recuerda que la biblioteca dinámica no hace parte del ejecutable, por tanto
para poder ejecutar el programa es necesario que le des a conocer al sistema
operativo el ejecutable mismo y las dependencias a bibliotecas dinámicas.

Cuando enlazas un programa con una biblioteca dinámica, en el ejecutable te
quedarán símbolos sin definir. Estos símbolos tendrán que definirse al momento
de ejecutar el programa. En este caso, cuando se ejecute el programa, será necesario
que el sistema operativo cargue de manera dinámica (dynamic linker) los símbolos
pendientes que estarán en la biblioteca dinámica. El dynamic linker se encargará
entonces de cargar a memoria la biblitoca y mapear esta a una región de memoria
del proceso (recuerda, un proceso es la abstracción que usa el sistema operativo
para poder correr y controlar la ejecución de un programa).

Es importante señalar que las biblotecas dinámicas tienen un formato ELF similar
al de los ejecutables; sin embargo, la direcciones de los símbolos no son absolutas,
sino relativas a un punto (position independent code). Eso permite entonces que
dos instrucciones separadas por 100 bytes, por ejemplo, puedan ser ubicadas en un
proceso en las direcciones 100 y 200 y en otro en la 512 y 612. Adicionalmente, las
bibliotecas dinámicas no puede ejecutarse.

Ahora considera los mismo programas del ejercicio anterior. Construye la biblioteca
dinámica así:

``gcc -c uno.c -fPIC -o uno.o``

``gcc -c dos.c -fPIC -o dos.o``

``gcc -c tres.c -fPIC -o tres.o``

La opción ``-fPIC`` quiere decir position independent code. FInalmente mezclamos
los código:

``gcc -shared uno.o dos.o tres.o -o libstatic.so``

Antes de generar el ejecutable borra la bilioteca estática con ``rm -fv ./libstatic.a``.
Ejecuta el comando ``gcc main.o -L./ -lstatic -o exe`` y luego ejecuta el programa. El
resultado debería ser algo similar a esto:

.. code-block:: c

    ./exe: error while loading shared libraries: libstatic.so: 
    cannot open shared object file: No such file or directory

¿Por qué ocurre esto? como te dije antes, debes decirle al sistema operativo en dónde está
la bilioteca dinámica. Esto se hace actualizando la variable de ambiente (environment variable)
``LD_LIBRARY_PATH`` con ``export LD_LIBRARY_PATH=./``. Ejecuta de nuevo el programa.
¿Funcionó?

¿Será posible que el propio programa ejecutable le indique al sistema operativo cuándo cargar
la biblioteca y dónde está ubicada? SI!!! Y esto es genial porque te permite cargar en ejecución
diferentes versiones de biblioteca, es decir, tienes más flexibilidad.

Considera el siguiente programa:

.. code-block:: c
    :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <dlfcn.h>
    #include "api.h"
    
    int main(int argc, char* argv[]) {

        int (*func_ptr)() = NULL;

        // Cargo la biblioteca dinámica
        void* handle = dlopen ("./libstatic.so", RTLD_LAZY);

        if (!handle) {
            fprintf(stderr, "%s\n", dlerror());
            exit(1);
        }
        
        // Busco el símbolo que necesito
        func_ptr = dlsym(handle, "uno");
        if (!func_ptr) {
            fprintf(stderr, "%s\n", dlerror());
            exit(1);
        }
        printf("uno(): %d\n", func_ptr());

        func_ptr = dlsym(handle, "dos");
        if (!func_ptr) {
            fprintf(stderr, "%s\n", dlerror());
            exit(1);
        }
        printf("dos(): %d\n", func_ptr());


        func_ptr = dlsym(handle, "tres");
        if (!func_ptr) {
            fprintf(stderr, "%s\n", dlerror());
            exit(1);
        }
        printf("tres(): %d\n", func_ptr());


        return 0;
    }


Compila con ``gcc -Wall -c main.c -o main.o``

En el ejemplo anterior al generar el ejecutable hicimos esto ``gcc main.o -L./ -lstatic -o exe``.
Si nuestro programa dependiera de más biliotecas haríamos ``gcc main.o -L./ -lstatic -lXXX -lXXX -o exe``
Recuerda que la bilioteca se generó con el comando ``gcc -shared uno.o dos.o tres.o -o libstatic.so``;
sin embargo, para este ejemplo como vamos a cargar de manera `manual` la biblioteca, es necesario
generar nuestra biblioteca dinámica indicando todas las dependencias que esta tendrá a otras
bibliotecas, así: ``gcc -shared uno.o dos.o tres.o -lXXX -lXXX -o libstatic.so``. En este
caso no tenemos más dependencias, por tanto podemos conservar la biblioteca del ejemplo anterior.

Para generar el ejecutable escribe ``gcc -Wall main.o -ldl -o exe``. Ejecuta el programa. ¿Funciona?

Ten presente los siguientes puntos:

* ``int (*func_ptr)() = NULL;`` en esta expresión ``func_ptr`` es una variable que almacena
  direcciones de funciones que no reciben nada y devuelven un entero.
* ``void* handle = dlopen ("./libstatic.so", RTLD_LAZY);`` carga la biblioteca dinámica.
* ``func_ptr = dlsym(handle, "uno");`` carga nu símbolo en particular.
* En ``gcc -Wall main.o -ldl -o exe`` pasamos la opción ``-ldl``. Esta opción indica que
  vamos a realizar una carga perezosa (lazy loading) de la biblioteca dinámica.

Ejercicio 43
^^^^^^^^^^^^^^^^^

Ya sabemos cuáles son los pasos necesarios para ir desde
un lenguaje como C y C++ a código de máquina; sin embargo, nos falta
una última estación en este recorrido. ¿Qué pasa con lenguajes como C#?

Para resolver esta pregunta vamos a tener que analizar un poco más
qué es un compilador y qué es un intérprete.


En este ejercicio vamos a investigar un poco más sobre algunos conceptos
de los lenguajes de programación. En particular analizaremos qué son
las implementaciones interpretadas y qué son las implementaciones compiladas.
Nota por favor que no te dije lenguajes interpretados o compilados. Al final
de los ejercicios que te propongo tu mismo podrás explicar la diferencia.

En ejercicios pasados discutimos las fases para transformar un
programa del código fuente a lenguaje de máquina.¿ Lo recuerdas?

* Iniciamos con el programa.
* Luego hacemos un análisis léxico, con el Tokenizer, para generar los tokens.
* Los tokens son unidades indivisibles compuestas por un tipo y un valor.
  Los tokens nos permiten identificar las palabras que componen nuestro programa.
* Ahora hacemos un análisis semántico, utilizando un Parser. Esto nos permiten
  reconocer si estamos combinando correctamente las palabras en el programa
  realizado.
* El Parser genera, si el programa es válido, una representación del programa
  conocida como AST.

Es precisamente este AST el que pasamos a un intérprete o a un compilador. El
intérprete ejecutará el código. El compilador convertirá el AST a otro lenguaje,
que posiblemente será transformado de nuevo o interpretado.

Por ejemplo, en el caso de C, luego de generar el AST, utilizamos un generador
de código y producimos lenguaje ensamblador. Luego este lenguaje ensamblador
lo convertimos en lenguaje de máquina. Finalmente, el lenguaje de máquina es
INTERPRETADO por la CPU.

Hay dos tipos de intérpretes que se diferencian en el formato del programa
que interpretan. En ese sentido el programa puede estar representado como un AST
o como Bytecodes. Los intérpretes que utilizan el primer formato se conocen
como intérpretes recursivos y los segundos como Máquinas Virtuales (VM). En el
caso de los segundos, la representación será muy parecida a un programa en lenguaje
ensamblador, como el de una CPU real, y por tanto el nombre de máquinas virtuales.

En el caso de los compiladores tenemos tres tipos: 

* Ahead-of-time (AOT): todo el código se traduce a un nuevo lenguaje antes de ser
  ejecutado. Como en el caso de C y C++. Sin embargo, es interesante anotar, 
  por ejemplo, que C++ se comparta como un interprete a la hora de optimizar el código.
* Just-in-time (JIT): el código se genera durante la ejecución del programa.
* AST-transformer o también conocidos como transpilers. Aquí la idea es realizar
  una transformación de un tipo de AST a otro, para generar, por ejemplo, de un
  lenguaje de programación a otro.

Ejercicio 44
^^^^^^^^^^^^^^

Profundicemos un poco más en los intérpretes.

Los AST interpreters: ejecutan el programa directamente desde la representación AST,
es decir, producen el resultado modelado con el lenguaje de programación directamente,
en tiempo de ejecución.

Realiza el siguiente ejercicio utilizando la herramienta `AST-explorer <https://astexplorer.net/>`__:

* Selecciona javacript.
* Escribe el siguiente código
  
  .. code-block:: javascript
     :linenos:

     a = 5;
     b = a*2 + 10;

* Analiza el AST generado. Verás que la herramienta te identifica expresiones y cada expresión la
  organiza como un árbol identificando el lado izquierdo y el lado derecho.

¿Puedes pintar árboles para los dos expresiones anteriores?


Ejercicio 45
^^^^^^^^^^^^^^

Profundicemos un poco más en los intérpretes.

Los bytecodes interpreters no parten de una representación AST en forma de árbol, sino
que parten de un arreglo de bytecodes. Por tanto, necesitarán un paso más en tiempo
de compilación:

* Iniciamos con el programa.
* Análisis léxico --> genera tokens
* Análisis semántico --> genera el AST.
* Bytecode emitter --> Generar bytecodes

Ahora si, en tiempo de ejecución se ejecutará el programa representado como un
arreglo de bytecodes.

¿Para qué hacemos este paso extra? Se hace para optimizar el almacenamiento del
programa en comparación con la representación AST. También será más fácil
de recorrer el programa y se tendrá un control más granular de la ejecución.

Recuerda que a este tipo de intérprete lo llamamos también virtual machine. Usualmente,
estas virtual machines son de dos tipos: stack-based y register-based.

¿Recuerdas el computador Hack? si consideramos la CPU implementada como un intérprete
de las instrucciones Hack, podríamos decir que la CPU es una virtual machine register-based.

¿Cómo serán las VM stack-based? Imagina el stack, como un pila de platos.
Estas VM apilan (stack) los operandos y luego aplican las operaciones. Por tanto, 
los resultados siempre quedan en el tope de la pila. Entonces, para realizar la operación
``5+6`` la VM colocará en la pila el 5, luego el 6, y finalmente realizará la operación suma.
Como resultado, los operandos 5 y 6 serán retirados de la pila y quedará el resultado 11
en la parte superior de esta.

Realiza el siguiente ejercicio:

* Crea un programa Test.java:

  .. code-block:: java
     :linenos:

        class Test{

            public static void main(String[] args){
                int x = 5;
                System.out.println(x+2-1);
            }
        }

* Compila el programa así: ``javac Test.java``. Verás que se genera en el directorio un
  archivo Test.class

* Ahora ejecuta ``hexdump -C Test.class``. El resultado será el bytecode
  
.. code-block:: bash  

        00000000  ca fe ba be 00 00 00 34  00 1b 0a 00 05 00 0e 09  |.......4........|
        00000010  00 0f 00 10 0a 00 11 00  12 07 00 13 07 00 14 01  |................|
        00000020  00 06 3c 69 6e 69 74 3e  01 00 03 28 29 56 01 00  |..<init>...()V..|
        00000030  04 43 6f 64 65 01 00 0f  4c 69 6e 65 4e 75 6d 62  |.Code...LineNumb|
        00000040  65 72 54 61 62 6c 65 01  00 04 6d 61 69 6e 01 00  |erTable...main..|
        00000050  16 28 5b 4c 6a 61 76 61  2f 6c 61 6e 67 2f 53 74  |.([Ljava/lang/St|
        00000060  72 69 6e 67 3b 29 56 01  00 0a 53 6f 75 72 63 65  |ring;)V...Source|
        00000070  46 69 6c 65 01 00 09 54  65 73 74 2e 6a 61 76 61  |File...Test.java|
        00000080  0c 00 06 00 07 07 00 15  0c 00 16 00 17 07 00 18  |................|
        00000090  0c 00 19 00 1a 01 00 04  54 65 73 74 01 00 10 6a  |........Test...j|
        000000a0  61 76 61 2f 6c 61 6e 67  2f 4f 62 6a 65 63 74 01  |ava/lang/Object.|
        000000b0  00 10 6a 61 76 61 2f 6c  61 6e 67 2f 53 79 73 74  |..java/lang/Syst|
        000000c0  65 6d 01 00 03 6f 75 74  01 00 15 4c 6a 61 76 61  |em...out...Ljava|
        000000d0  2f 69 6f 2f 50 72 69 6e  74 53 74 72 65 61 6d 3b  |/io/PrintStream;|
        000000e0  01 00 13 6a 61 76 61 2f  69 6f 2f 50 72 69 6e 74  |...java/io/Print|
        000000f0  53 74 72 65 61 6d 01 00  07 70 72 69 6e 74 6c 6e  |Stream...println|
        00000100  01 00 04 28 49 29 56 00  20 00 04 00 05 00 00 00  |...(I)V. .......|
        00000110  00 00 02 00 00 00 06 00  07 00 01 00 08 00 00 00  |................|
        00000120  1d 00 01 00 01 00 00 00  05 2a b7 00 01 b1 00 00  |.........*......|
        00000130  00 01 00 09 00 00 00 06  00 01 00 00 00 01 00 09  |................|
        00000140  00 0a 00 0b 00 01 00 08  00 00 00 2e 00 03 00 02  |................|
        00000150  00 00 00 0e 08 3c b2 00  02 1b 05 60 04 64 b6 00  |.....<.....`.d..|
        00000160  03 b1 00 00 00 01 00 09  00 00 00 0e 00 03 00 00  |................|
        00000170  00 04 00 02 00 05 00 0d  00 06 00 01 00 0c 00 00  |................|
        00000180  00 02 00 0d                                       |....|
        00000184

* Para ver una representación simbólica de este bytecode escribe ``javap -c Test.class``:

.. code-block:: bash 

        Compiled from "Test.java"
        class Test {
        Test();
            Code:
            0: aload_0
            1: invokespecial #1                  // Method java/lang/Object."<init>":()V
            4: return

        public static void main(java.lang.String[]);
            Code:
            0: iconst_5
            1: istore_1
            2: getstatic     #2                  // Field java/lang/System.out:Ljava/io/PrintStream;
            5: iload_1
            6: iconst_2
            7: iadd
            8: iconst_1
            9: isub
            10: invokevirtual #3                  // Method java/io/PrintStream.println:(I)V
            13: return
        }

* Observa el código en el método main: ``iconst_5`` coloca un 5 en el stack, ``istore_1`` almacena el valor
  en x. Esto corresponde a la operación ``x = 5``. Ahora mira cómo se resulte ``x+2-1``. Primero
  se coloca en el stack el valor de x con ``iload_1``, luego se coloca el 2 ``iconst_2``, se hace
  la suma ``iadd`` dejando el resultado en el stack. Luego se coloca en el stack el 1 con ``iconst_1``
  y finalmente se realiza la resta ``isub``.

Ejercicio 46
^^^^^^^^^^^^^^

Continuado con el tema del ejercicio anterior.

* Abre la aplicación `compiler explorer <https://godbolt.org/>`__.
* Selecciona python
* Ingresa el programa:

  .. code-block:: python
     :linenos:

     def main():
        x = 5;
        print(x+2-1)

* Observa la salida al lado derecho:

    .. code-block:: python
       :linenos:

            1           0 LOAD_CONST               0 (<code object main at 0x5653b7cb2980, file "example.py", line 1>)
                        2 LOAD_CONST               1 ('main')
                        4 MAKE_FUNCTION            0
                        6 STORE_NAME               0 (main)
                        8 LOAD_CONST               2 (None)
                        10 RETURN_VALUE

            Disassembly of <code object main at 0x5653b7cb2980, file "example.py", line 1>:
            2           0 LOAD_CONST               1 (5)
                        2 STORE_FAST               0 (x)

            3           4 LOAD_GLOBAL              0 (print)
                        6 LOAD_FAST                0 (x)
                        8 LOAD_CONST               2 (2)
                        10 BINARY_ADD
                        12 LOAD_CONST               3 (1)
                        14 BINARY_SUBTRACT
                        16 CALL_FUNCTION            1
                        18 POP_TOP
                        20 LOAD_CONST               0 (None)
                        22 RETURN_VALUE

* ¿Qué tipo de VM será el intérprete de python?


Ejercicio 47
^^^^^^^^^^^^^^

Ahora profundicemos un poco más en los compiladores.

Los AOT (Ahead-of-time) compilers. Ahead-of-time quiere decir, antes de la
ejecución, es decir, estos compiladores traducen completamente el código
fuente antes de ser ejecutados. Recuerda, por ejemplo, C o C++. Una vez el código
de máquina es generado, este es interpretado por la CPU. 

Los siguientes pasos permiten generar, en tiempo de compilación,
código de máquina:

* Iniciamos con el programa.
* Análisis léxico --> genera tokens
* Análisis semántico --> genera el AST.
* Code generator --> produce representaciones intermedias que luego
  se traducen a código de máquina especifico para cada CPU.

Los pasos desde el programa hasta la generación del AST se conocen como FRONTEND. 
Los pasos desde el generador de código, pasando por las representaciones
intermedias y el código de máquina se conocen como BACKEND.

Actualmente, motores de videojuegos como Unity trabajan intensamente para lograr
optimizar todos los pasos anteriores. Para ello usan las ideas desarrolladas
en el proyecto LLVM (low level virtual machine). Si quieres profundizar más
en el asunto te recomiendo  `esta conferencia <https://youtu.be/LKpyaVrby04>`__. 
Te dejo también la presentación de la misma `aquí <https://drive.google.com/file/d/1w6A02OlnDS1ILXB56l4DlZ_ntFUrlirX/view?usp=sharing>`__.
Te he hablado un par de veces del nuevo stack de Unity llamado DOTs. Pues bien,
una de las tecnologías en DOTs es el burst compiler. La idea de del burst
compiler es permitir que un subconjunto de C# pueda producir ejecutables,
con un desempeño incluso superior al que se podría lograr con C++. ¿Te suena
interesante no? A mi también :)

¿Quieres dar un vistazo rápido de las posibilidades que vienen con DOTS?
Te recomiendo que hagas `este tutorial <https://youtu.be/C56bbgtPr_w>`__ 
corto para que lo ves con tus propios ojos.

¿Qué es el proyecto LLVM? Es una infraestructura de compilación compuesta
por un conjunto de compiladores y herramientas que permiten desarrollar
un fronted para cualquier lenguaje de programación y un backend para cualquier
set de instrucciones.

Los pasos que se siguen al usar LLVM, todos en tiempo de compilación, son:

* Iniciamos con el programa.
* Análisis léxico --> genera tokens
* Análisis semántico --> genera el AST.
* LLVM IR generator --> genera LLVM bytecode o LLVM IR
* El LLVM IR lo recibe el generador de código LLVM encargado
  de generar código de máquina para múltiples plataformas.

 Considera el siguiente ejemplo llamado main.cpp:

 .. code-block:: c 
    :linenos:

    int main(void){
        int x = 10;
        return x+5-2;
    }

Compila usando ``clang++ main.cpp`` el resultado será el archivo 
``a.out``. Ejecuta el archivo con ``./a.out`` y lee el resultado generado
por el programa con ``echo $?``

Ahora ejecuta ``clang++ main.cpp -S`` para producir el archivo ``main.s``
que tendrá el código ensamblador:

.. code-block:: c
    :linenos:

    int main(void){
        int x = 10;
        return x+5-2;
    }

.. code-block:: bash 
    
		.text
		.file	"main.cpp"
		.globl	main                    # -- Begin function main
		.p2align	4, 0x90
		.type	main,@function
	main:                                   # @main
		.cfi_startproc
	# %bb.0:
		pushq	%rbp
		.cfi_def_cfa_offset 16
		.cfi_offset %rbp, -16
		movq	%rsp, %rbp
		.cfi_def_cfa_register %rbp
		movl	$0, -4(%rbp)
		movl	$10, -8(%rbp)
		movl	-8(%rbp), %eax
		addl	$5, %eax
		subl	$2, %eax
		popq	%rbp
		.cfi_def_cfa %rsp, 8
		retq
	.Lfunc_end0:
		.size	main, .Lfunc_end0-main
		.cfi_endproc
											# -- End function
		.ident	"clang version 10.0.0-4ubuntu1 "
		.section	".note.GNU-stack","",@progbits
		.addrsig

Observa las línas 17 y 18 donde hace el cálculo correspondiente
a la expresión ``return x+5-2``. 

Compila de nuevo el código, pero esta vez con 

Ahora ejecuta ``clang++ main.cpp -S -O3`` y lee de nuevo main.s:


.. code-block:: bash
    :linenos:

		.text
		.file	"main.cpp"
		.globl	main                    # -- Begin function main
		.p2align	4, 0x90
		.type	main,@function
	main:                                   # @main
		.cfi_startproc
	# %bb.0:
		movl	$13, %eax
		retq
	.Lfunc_end0:
		.size	main, .Lfunc_end0-main
		.cfi_endproc
											# -- End function
		.ident	"clang version 10.0.0-4ubuntu1 "
		.section	".note.GNU-stack","",@progbits
		.addrsig


Observa la línea 9. ¿Qué notas? ¿Recuerdas el resultado obtenido al ejecutar
el programa? Mira de nuevo la línea 9. 

Estrictamente hablando, se supone que estamos compilando el código, pero
podrás notar que clang++ con la opción -O3 está interpretando, en tiempo,
de compilación, el código, para optimizarlo. Interesante, ¿Cierto? :)

Ahora ejecuta el comando ``clang++ main.cpp -S -emit-llvm`` observa
el archivo main.ll:

.. code-block:: bash

    ; ModuleID = 'main.cpp'
    source_filename = "main.cpp"
    target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
    target triple = "x86_64-pc-linux-gnu"

    ; Function Attrs: noinline norecurse nounwind optnone uwtable
    define dso_local i32 @main() #0 {
      %1 = alloca i32, align 4
      %2 = alloca i32, align 4
      store i32 0, i32* %1, align 4
      store i32 10, i32* %2, align 4
      %3 = load i32, i32* %2, align 4
      %4 = add nsw i32 %3, 5
      %5 = sub nsw i32 %4, 2
      ret i32 %5
    }

    attributes #0 = { noinline norecurse nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

    !llvm.module.flags = !{!0}
    !llvm.ident = !{!1}

    !0 = !{i32 1, !"wchar_size", i32 4}
    !1 = !{!"clang version 10.0.0-4ubuntu1 "}

¿Sabes qué es eso? Es código LLVM IR. Observa las líneas 13 y 14. De nuevo corresponde al
cálculo de la expresión ``return x+5-2``. Desde esta representación se puede generar
código para múltiples set de instrucciones como te comenté antes.


Ejercicio 48
^^^^^^^^^^^^^^

Ahora hablemos un poco más de los Just-In-Time (JIT) compilers. Los AOT traducen
el programa a código de máquina en tiempo de compilación. Los JIT lo hacen en
tiempo de ejecución.

Los pasos que sigue un JIT compiler en tiempo de compilación son:

* Iniciamos con el programa.
* Análisis léxico --> genera tokens.
* Análisis semántico --> genera el AST.
* Bytecode emitter --> Generar bytecode.

En tiempo de ejecución un intérprete (lo que llamamos virtual machine) interpreta
el bytecode, pero algunos bytecode son compilados a código de máquina. La primera
vez que se compilan dichos bytecodes y se ejecuta el código de máquina producido
toma un tiempo; sin embargo, la interpretación posterior de estos bytecodes compilados
será muy rápido puesto que la ejecución no será efectuada por el intérprete sino
directamente por la CPU.

Ejercicio 49
^^^^^^^^^^^^^^

Finalmente, analicemos un poco más los transpilers o AST transformers.

Los pasos que sigue el transpiler, en tiempo de compilación, son:

* Iniciamos con el programa.
* Análisis léxico --> genera tokens
* Análisis semántico --> genera el AST.
* El transpiler o AST transformer --> genera otro AST para el mismo lenguaje
  o para otro lenguaje de programación. Por ejemplo, traducir una versión vieja
  de javascript a una versión nueva o de python a javascript.
* El nuevo AST se pasa a un generador de código --> genera el programa en otro lenguaje
  de programación (claramente conservando la semántica del programa inicial).

La salida de todo este proceso puede pasarse ahora a un AOT o un JIT compiler.

Ejercicio 50
^^^^^^^^^^^^^^^

¿Los lenguajes javascript, python, C, C#, c++ son lenguajes interpretados o compilados?

:)

La verdad es que esta pregunta es incorrecta. Lo que es interpretado o compilado
es la implementación específica. ¿Cómo así? Creo que con lo que aprendiste tu mismo
puedes explicar que significa esto. ¿Te animas?

Ejercicio 51
^^^^^^^^^^^^^^^

¿Cómo es la implementación de C#?

Te voy a dejar `aquí <https://codeasy.net/lesson/c_sharp_compilation_process>`__
un enlace para que leas.

Ahora si, escribe ¿Cómo es la implementación de C#?

Te dejo algunas preguntas adicionales:

* ¿Es posible generar código de máquina partiendo de C# en tiempo de compilación?
* ¿Qué ventaja tiene entonces generar código Just-In-Time en tiempo de ejecución?
* ¿Pudiste identificar en la lectura cómo se llama la máquina virtual utilizada
  para interpretar código IL?
* ¿Qué es el .NET framework?

Ejercicio 52
^^^^^^^^^^^^^^^

¿En qué consiste el proyecto MONO? ¿Qué relación tiene con el ejercicio anterior?

Ejercicio 53
^^^^^^^^^^^^^

Busca en la documentación de Unity ¿Qué es IL2CPP? Con lo que aprendiste 
explica ¿Cuáles serían los pasos, en la implementación de Unity, para pasar de
C# a lenguaje de máquina utilizado IL2CPP?

Ejercicio 54
^^^^^^^^^^^^^^^

¿Cómo funciona IL2CPP en Unity?

Te dejo `este <https://docs.unity3d.com/Manual/IL2CPP-HowItWorks.html>`__
enlace para que leas al respecto.

Ejercicio 55
^^^^^^^^^^^^^^^

* Crea un proyecto en Unity.
* Abre los project settings .
* En el menú Player busca Configuration.
* ¿Qué es el `Scripting Backend <https://docs.unity3d.com/Manual/scripting-backends.html>`__?
* ¿A qué se refiere el `API Compatibility level <https://docs.unity3d.com/Manual/dotnetProfileSupport.html>`__?


PROYECTO 
^^^^^^^^^^

Realiza un programa que permita crear un base de datos de estudiantes.
Cada registro de la base de datos estará dado por:
número de cédula, nombre y semestre. Cada registro corresponde a un 
estudiante.

Implemente los siguientes comandos:

**mkdb nombre tamaño** : crea una base de datos especificando el nombre
y la cantidad de registros.

**loaddb nombre** : carga la base de datos en memoria desde el archivo
especificado. El comando debe indicar si la base de datos se cargó
correctamente o no existe. La base de datos debe cargarse en memoria
dinámica antes de poder aplicar los siguientes comandos.

**savedb nombre** : este comando salva la base de datos en el archivo
especificado.

**readall** : lee todos los registros de la base de datos.

**readsize** : lee la cantidad de registros de la base datos.

**mkreg cedula nombre semestre** : crea un nuevo registro en la base
de datos.

**readreg cédula** : busca en la base de datos por número de cédula.
En caso de encontrar la cédula imprime el registro completo.

**exit** : salir del programa. Antes de terminar debe preguntar si se desea
salvar la base de datos en el archivo especificado con el comando loaddb.

Cada comando deberá implementarse como una función.

Cada registro es así:

.. code-block:: c
   :linenos:

    struct estudiante
    {
        int cedula;
        char nombre[30];
        int semestre;
    };
