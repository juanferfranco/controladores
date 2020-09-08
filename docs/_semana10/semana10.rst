Semana 10: Unidad 3
==========================

Esta semana continuaremos ejercitando el uso del lenguaje de programación
C.

Actividad 9
^^^^^^^^^^^^
* Fecha: septiembre 8 de 2020
* Descripción: ejercicios de lenguaje C
* Recursos: ingresa a Teams
* Duración de la actividad: 1:40 minutos
* Forma de trabajo: individual y grupal con solución de dudas en tiempo real


Ejercicios 
*************

Ejercicio 1
##############
Se propone realizar un programa que:

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

Ejercicio 2
##############
Repasa el manejo de archivos y la gestión de errores. 
Lee esta información:

* `Manejo básico <https://www.geeksforgeeks.org/basics-file-handling-c/>`__
* `¿Fin de un archivo o un error? <https://www.geeksforgeeks.org/eof-and-feof-in-c/>`__
* `¿Cómo vamos a gestionar los errores en C? <https://www.geeksforgeeks.org/error-handling-c-programs/>`__

Ejercicio 3
##############

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

Ejercicio 4
##############

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

Ejercicio 5
##############

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

Ejercicio 6
##############
Modifica el código anterior para que reciba
la información como argumentos de la función main,
al ejecutar el programa. NO DEBES SOLICITAR información
al usuario, todas la información será pasada cuando
se invoque el ejecutable en línea de comandos.


Actividad 10
^^^^^^^^^^^^^^^^
* Fecha: septiembre 8 a septiembre 10 de 2020 
* Descripción: terminar los ejercicios y comenzar el reto
* Recursos: actividad de trabajo autónomo
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

PROYECTO (RETO)
*****************
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

¿Qué debes entregar?
***********************

* Crea una carpeta que llamarás unidad3.
* Guarda SOLO el archivo .c y los archivos de texto con las pruebas. NO GUARDES ejecutables.
* En la primer línea cada archivo coloca tu ID así: // tu_id
* Guarda una copia de la rúbrica CON TU autoevaluación diligenciada. NO OLVIDES justificar cada nota
  Aquí está la `rúbrica <https://docs.google.com/spreadsheets/d/1DjP2vVNm4rzfQ1ae4LV8yyB270P67l9-cihEk9tPyc4/edit?usp=sharing>`__
* Comprime la carpeta unidad3 en formato .ZIP, ojo, solo .ZIP no uses otros
  formatos por favor.
* Entrega el archivo .ZIP `aquí <https://auladigital.upb.edu.co/mod/assign/view.php?id=636788>`__.


Actividad 11
^^^^^^^^^^^^^^^^
* Fecha: septiembre 10 de 2020
* Descripción: solución de dudas en tiempo real.
* Recursos: ingresa a Teams
* Duración de la actividad: 1:40 minutos
* Forma de trabajo: individual y grupal con solución de dudas en tiempo real


Actividad 12
^^^^^^^^^^^^^^
* Fecha: septiembre 10 a septiembre 15 de 2020 
* Descripción: terminar el reto y preparar la sustentación.
* Recursos: actividad de trabajo autónomo
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.
