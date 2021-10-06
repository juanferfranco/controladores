Unidad 3. Programación orientada a objetos 
================================================

Introducción
--------------

En esta unidad vas a repasar y analizar cómo funcionan algunas 
de las abstracciones usadas en la programación orientada a objetos.

Propósito de aprendizaje
**************************

Comprender cómo funcionan algunas abstracciones de la programación 
orientada a objetos mediante la implementación de ellas en 
lenguaje C y la comparación en C#.

Temas
******

* Memoria, encapsulamiento, herencia, polimorfismo.

Trayecto de actividades
------------------------

Sesión 1: memoria 
*******************************

Antes de analizar la implementación de algunas abstracciones de la 
programación orientada a objetos, vas a aprender un poco más acerca 
del modelo de memoria de un programación en ejecución o proceso.

Ejercicio 1: memoria de un proceso
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En la unidad anterior hablamos del concepto de proceso ¿Recuerdas? Pues
un proceso no es más que una abstracción que emplea el sistema operativo para
ejecutar y administrar un programa en ejecución. Los programas están almacenados
en archivos conocidos como object files. Para ejecutar un programa el sistema
operativo crea un proceso que ejecuta el object file, es decir, la CPU (o un
``core``) consumirá (fetch) y ejecutará las instrucciones del object file que estarán
almacenadas en alguna región de la memoria principal. Tu sabes también que los
programas en ejecución necesitarán memoria para almacenar las variables. Entonces
surge la siguiente pregunta ``¿Cómo es la memoria de un proceso
y cuál es su estructura?``

Cuando el sistema operativo crea un proceso para ejecutar un programa, también
es necesario asignarle memoria y aplicarle una estructura particular. En casi todos
los sistemas operativos las estructura de memoria del proceso es más o menos la misma.
La memoria de un proceso está dividida en múltiples partes conocidas como segmentos:

* Block Started by Symbol (BSS) es el segmentos de datos no inicializados.
* Data.
* Text segment o segmento de código.
* Stack.
* Heaps.

Algunos de estos segmentos se crean con la información almacenada en el
object file mientras que otros segmentos aparecen al momento de ejecutar el programa.

Ejercicio 2: observar los segmentos del object file
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Cómo hacemos para ver el contenido de los segmentos de memoria provenientes del
object file?

Escribe el siguiente programa llamado main.c:

.. code-block:: c

    int main(int argc, char* argv[]) {

        return 0;
    }

Compila el programa con ``gcc -Wall main.c -o main``. Podrás observar el tamaño de 
algunos segmentos:

``size main`` 

.. code-block:: bash

    text	   data	    bss	    dec	    hex	filename
    1418	    544	      8	   1970	    7b2	main

Puedes observar tres segmentos: text, data y bss.

Ejercicio 3: ¿Qué se almacena en los segmentos?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Te estarás preguntado ¿Para qué sirve cada uno de los segmentos
que acabas de ver?

El segmento BSS denota la cantidad de memoria reservada para variables globales
que no se inicializaron o que se inicializan a 0.

Modifica el programa anterior así:

.. code-block:: c

    int var1;
    int var2;
    int var3 = 0;

    int main(int argc, char* argv[]) {

        return 0;
    }

De nuevo, compila y ejecuta ``size main``:

.. code-block:: bash

    text	   data	    bss	    dec	    hex	filename
    1418	    544	     16	   1978	    7ba	main

Compara esta salida con la anterior. ¿Notas un cambio en BSS?

Ejercicio 4: segmento data
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para analizar el segmento data te propongo modificar de nuevo nuestro programa:

.. code-block:: c

    int var1;
    int var2;
    int var3 = 0;
    int var4 = 69;
    int var5 = 666;

    int main(int argc, char* argv[]) {

        return 0;
    }

Compila y ejecuta ``size main``:

.. code-block:: bash

    text	   data	    bss	    dec	    hex	filename
    1418	    552	     16	   1986	    7c2	main

Compara, ¿El segmento data cambió? El segmento ``data`` entonces te sirve para almacenar
las variables inicializadas con valores diferentes de 0.

Ejercicio 5: variables estáticas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Modifica de nuevo el archivo:

.. code-block:: c

    int var1;
    int var2;
    int var3 = 0;
    int var4 = 69;
    int var5 = 666;

    void func(){
        static int i = 10;
        i++;
    }

    int main(int argc, char* argv[]) {
        func();
        return 0;
    }

Compila y ejecuta ``size main``:

.. code-block:: bash

    text	   data	    bss	    dec	    hex	filename
    1506	    556	     20	   2082	    822	main

Nota que los segmentos cambiaron de nuevo al incluir una nueva variable.


Ejercicio 7: ver el contenido del segmento .data
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Cómo hago para ver el contenido del segmento data?

Toma como referencia el programa anterior y escribe el comando ``objdump -s -j .data main``

.. code-block:: bash

    main:     file format elf64-x86-64

    Contents of section .data:
    4000 00000000 00000000 08400000 00000000  .........@......
    4010 45000000 9a020000                    E....... 

¿Puedes ver efectivamente el contenido? observa los valores iniciales de ``var4`` y ``var5`` en
el programa. Ten presente que ``4000`` y ``4010`` son direcciones. El resto de información
es datos, cada file muestra 16 bytes (máximo) y luego se ve la representación de cada byte en ASCII.

Ejercicio 8: ver el contenido del segmento de texto
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En el segmento de texto está contenido todo el código de máquina del programa producido por
el compilador.

¿Cómo puedes ver el contenido?

Ejecuta ``objdump -S main``

Podrás observar el código de máquina y la representación simbólica en lenguaje ensamblador.

Ejercicio 9: contenido del stack y del heap
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Cómo hacemos para ver el contenido de los segmentos stack y heap?

Solo podemos ver esta parte de la memoria cuando el programa esté en ejecución. Cuando
quieres ejecutar un object file, el sistema operativo crea un nuevo proceso e inicializa
su memoria. Los segmentos BSS, data y text son inicializados con la información que está en
el object file y, el stack y el heap se añaden y son modificados a medida que el código
del segmento text es leído por parte de la CPU.

Veamos un ejemplo:

.. code-block:: c

    #include <unistd.h> 
    int main(int argc, char* argv[]) {
        while (1) {
            sleep(1); 
        };

        return 0;
    }

Compila el código con ``gcc -Wall main.c -o main``

Y ahora ejecuta el programa así ``./main &`` para que quede en background y retomes
el control de la terminal para que puedas seguir escribiendo comandos. Ten en cuenta
que el número que te aparece en la terminal al ejecutar el programa es el ``pid`` o
identificador del proceso en el sistema operativo:

.. code-block:: bash

    juanfranco@pop-os:/tmp/linker$ ./main &
    [1] 295236

Más tarde cuando quieras matar el proceso escribe en la terminal 
``kill -9 295236``.

En Linux puedes consultar información del proceso en el directorio ``/proc`` allí tendrás
una entrada para el proceso identificada con el pid del mismo.

Ejecuta el comando ``ls -al /proc/295236``:

.. code-block:: c 

    total 0
    dr-xr-xr-x   9 juanfranco juanfranco 0 Sep 21 14:17 .
    dr-xr-xr-x 714 root       root       0 Sep 18 07:13 ..
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 arch_status
    dr-xr-xr-x   2 juanfranco juanfranco 0 Sep 21 15:12 attr
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 autogroup
    -r--------   1 juanfranco juanfranco 0 Sep 21 15:12 auxv
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 cgroup
    --w-------   1 juanfranco juanfranco 0 Sep 21 15:12 clear_refs
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 14:17 cmdline
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 comm
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 coredump_filter
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 cpuset
    lrwxrwxrwx   1 juanfranco juanfranco 0 Sep 21 15:12 cwd -> /tmp/linker
    -r--------   1 juanfranco juanfranco 0 Sep 21 15:12 environ
    lrwxrwxrwx   1 juanfranco juanfranco 0 Sep 21 14:17 exe -> /tmp/linker/main
    dr-x------   2 juanfranco juanfranco 0 Sep 21 15:12 fd
    dr-x------   2 juanfranco juanfranco 0 Sep 21 15:12 fdinfo
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 gid_map
    -r--------   1 juanfranco juanfranco 0 Sep 21 15:12 io
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 limits
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 loginuid
    dr-x------   2 juanfranco juanfranco 0 Sep 21 15:12 map_files
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 maps
    -rw-------   1 juanfranco juanfranco 0 Sep 21 15:12 mem
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 mountinfo
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 mounts
    -r--------   1 juanfranco juanfranco 0 Sep 21 15:12 mountstats
    dr-xr-xr-x   5 juanfranco juanfranco 0 Sep 21 15:12 net
    dr-x--x--x   2 juanfranco juanfranco 0 Sep 21 15:12 ns
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 numa_maps
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 oom_adj
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 oom_score
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 oom_score_adj
    -r--------   1 juanfranco juanfranco 0 Sep 21 15:12 pagemap
    -r--------   1 juanfranco juanfranco 0 Sep 21 15:12 patch_state
    -r--------   1 juanfranco juanfranco 0 Sep 21 15:12 personality
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 projid_map
    lrwxrwxrwx   1 juanfranco juanfranco 0 Sep 21 15:12 root -> /
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 sched
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 schedstat
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 sessionid
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 setgroups
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 smaps
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 smaps_rollup
    -r--------   1 juanfranco juanfranco 0 Sep 21 15:12 stack
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 14:17 stat
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 statm
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:11 status
    -r--------   1 juanfranco juanfranco 0 Sep 21 15:12 syscall
    dr-xr-xr-x   3 juanfranco juanfranco 0 Sep 21 15:12 task
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 timers
    -rw-rw-rw-   1 juanfranco juanfranco 0 Sep 21 15:12 timerslack_ns
    -rw-r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 uid_map
    -r--r--r--   1 juanfranco juanfranco 0 Sep 21 15:12 wchan

Cada una de estas entradas corresponde a una característica del proceso.

Para preguntar por el mapa de memoria del proceso ejecuta: ``cat /proc/295236/maps``:

.. code-block:: c

    563fa1aeb000-563fa1aec000 r--p 00000000 08:03 8393449                    /tmp/linker/main
    563fa1aec000-563fa1aed000 r-xp 00001000 08:03 8393449                    /tmp/linker/main
    563fa1aed000-563fa1aee000 r--p 00002000 08:03 8393449                    /tmp/linker/main
    563fa1aee000-563fa1aef000 r--p 00002000 08:03 8393449                    /tmp/linker/main
    563fa1aef000-563fa1af0000 rw-p 00003000 08:03 8393449                    /tmp/linker/main
    7f28fb8f9000-7f28fb91e000 r--p 00000000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f28fb91e000-7f28fba96000 r-xp 00025000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f28fba96000-7f28fbae0000 r--p 0019d000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f28fbae0000-7f28fbae1000 ---p 001e7000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f28fbae1000-7f28fbae4000 r--p 001e7000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f28fbae4000-7f28fbae7000 rw-p 001ea000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f28fbae7000-7f28fbaed000 rw-p 00000000 00:00 0 
    7f28fbb0b000-7f28fbb0c000 r--p 00000000 08:03 1049197                    /usr/lib/x86_64-linux-gnu/ld-2.31.so
    7f28fbb0c000-7f28fbb2f000 r-xp 00001000 08:03 1049197                    /usr/lib/x86_64-linux-gnu/ld-2.31.so
    7f28fbb2f000-7f28fbb37000 r--p 00024000 08:03 1049197                    /usr/lib/x86_64-linux-gnu/ld-2.31.so
    7f28fbb38000-7f28fbb39000 r--p 0002c000 08:03 1049197                    /usr/lib/x86_64-linux-gnu/ld-2.31.so
    7f28fbb39000-7f28fbb3a000 rw-p 0002d000 08:03 1049197                    /usr/lib/x86_64-linux-gnu/ld-2.31.so
    7f28fbb3a000-7f28fbb3b000 rw-p 00000000 00:00 0 
    7ffdd8feb000-7ffdd900c000 rw-p 00000000 00:00 0                          [stack]
    7ffdd9183000-7ffdd9186000 r--p 00000000 00:00 0                          [vvar]
    7ffdd9186000-7ffdd9187000 r-xp 00000000 00:00 0                          [vdso]
    ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]

Observa cada línea. Tomemos por ejemplo la primera:

``563fa1aeb000-563fa1aec000 r--p 00000000 08:03 8393449                    /tmp/linker/main``

Primero tienes un rango de direcciones: ``563fa1aeb000-563fa1aec000`` en ese 
rango tienes mapeada información del object file ``/tmp/linker/main``. Después del 
rango de direcciones encuentras los permisos: r se puede leer, w modificar, x ejecutar, p para
indicar si la región de memoria es privada o compartida con otro procesos (s). Si la región
está mapeada a un archivo, lo que sigue es el offset en el archivo. Si la región está mapeada
a un archivo verás el identificador del dispositivo (08:03) donde está el archivo. Luego aparece
el inode (lo vemos luego). Y finalmente el path del archivo que está mapeado a esta región. También
puedes ver un espacio en blanco o el propósito de la región, por ejemplo [stack] para indicar
que es una región utilizada para implementar el segmento de stack.

Ejercicio 10: stack
^^^^^^^^^^^^^^^^^^^^^^^^

Profundicemos un poco más en el stack.

¿Recuerdas qué se almacena en el stack?

* Variables locales que no sean estáticas.
* El ``stack frame`` cuando llamas una función. Allí se encuentra 
  la dirección a la que debe retornar el programa luego de llamar la función.
* Parámetros de entrada y salida de una función.

MUY MUY IMPORTANTE: 

* Al llamar un función, las variables que declares en el stack se van
  apilando, como si fueran una columna de platos. El puntero de pila se va ajustando siempre
  el TOP del stack; sin embargo, cuando retornes de la función el puntero de pila se ajustará
  nuevamente a la base de la columna de platos (las variables). Los datos de las variables 
  locales siguen allí pero en cualquier momento pueden ser destruidos al llamar otra función 
  o al producirse una interrupción. Las interrupciones interrumpen el flujo de instrucciones,
  para ejecutar un nuevo flujo conocido como servicio de atención a la interrupción, y hacen
  uso del stack para almacenar temporalmente parte del contexto de la CPU. EN CONCLUSIÓN: una
  vez retornes de una función NO PUEDES contar con las variables locales (¡Murieron!).

* Como el stack no es tan grande comparado con el HEAP debes evitar llamados recursivos
  infinitos para evitar desbordar su capacidad.

¿Cómo puedes ver el contenido del stack? Necesitas un depurador (un debugger).

Ejercicio 11: el heap
^^^^^^^^^^^^^^^^^^^^^^^

Profundicemos un poco más en el heap.

Considera el siguiente código:

.. code-block:: c

    #include <unistd.h>
    #include <stdlib.h> 
    #include <stdio.h> 
    
    int main(int argc, char* argv[]) {
        void* ptr = malloc(1024); 
        printf("Address: %p\n", ptr);
    
        while (1) {
            sleep(1); 
        };
        
        return 0;
    }

Compila y ejecuta:

.. code-block:: c

    ./main &
    [2] 321982
    Address: 0x55f05576b2a0

Ahora ejecuta de nuevo ``cat /proc/321982/maps`` (nota que estamos usando el pid del nuevo
proceso):

.. code-block:: c

    55f054ece000-55f054ecf000 r--p 00000000 08:03 8394826                    /tmp/linker/main
    55f054ecf000-55f054ed0000 r-xp 00001000 08:03 8394826                    /tmp/linker/main
    55f054ed0000-55f054ed1000 r--p 00002000 08:03 8394826                    /tmp/linker/main
    55f054ed1000-55f054ed2000 r--p 00002000 08:03 8394826                    /tmp/linker/main
    55f054ed2000-55f054ed3000 rw-p 00003000 08:03 8394826                    /tmp/linker/main
    55f05576b000-55f05578c000 rw-p 00000000 00:00 0                          [heap]
    7f4b21bb2000-7f4b21bd7000 r--p 00000000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f4b21bd7000-7f4b21d4f000 r-xp 00025000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f4b21d4f000-7f4b21d99000 r--p 0019d000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f4b21d99000-7f4b21d9a000 ---p 001e7000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f4b21d9a000-7f4b21d9d000 r--p 001e7000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f4b21d9d000-7f4b21da0000 rw-p 001ea000 08:03 1049202                    /usr/lib/x86_64-linux-gnu/libc-2.31.so
    7f4b21da0000-7f4b21da6000 rw-p 00000000 00:00 0 
    7f4b21dc4000-7f4b21dc5000 r--p 00000000 08:03 1049197                    /usr/lib/x86_64-linux-gnu/ld-2.31.so
    7f4b21dc5000-7f4b21de8000 r-xp 00001000 08:03 1049197                    /usr/lib/x86_64-linux-gnu/ld-2.31.so
    7f4b21de8000-7f4b21df0000 r--p 00024000 08:03 1049197                    /usr/lib/x86_64-linux-gnu/ld-2.31.so
    7f4b21df1000-7f4b21df2000 r--p 0002c000 08:03 1049197                    /usr/lib/x86_64-linux-gnu/ld-2.31.so
    7f4b21df2000-7f4b21df3000 rw-p 0002d000 08:03 1049197                    /usr/lib/x86_64-linux-gnu/ld-2.31.so
    7f4b21df3000-7f4b21df4000 rw-p 00000000 00:00 0 
    7fffc1d25000-7fffc1d46000 rw-p 00000000 00:00 0                          [stack]
    7fffc1dec000-7fffc1def000 r--p 00000000 00:00 0                          [vvar]
    7fffc1def000-7fffc1df0000 r-xp 00000000 00:00 0                          [vdso]
    ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]

Mira el rango de direcciones del heap: ``55f05576b000-55f05578c000``, ahora observa la dirección
de ``ptr``: ``0x55f05576b2a0`` Ah! está en el rango, está en el heap.

Volvamos al programa. Considera esta línea: ``void* ptr = malloc(1024)`` ¿La variable ptr
en qué segmento está?

¿Qué pasa con la dirección de la región que reservamos una vez salgamos del ámbito en el cual
se declaró prt?

Y si perdemos la dirección ¿Qué pasa con esa memoria que reservamos? ¿Y qué pasa si esto
nos comienza a ocurrir mucho en nuestro programa?

¿Recuerdas cómo evitamos este desperdicio de memoria? (¿Cuál es la función que libera la reserva?)

No olvides que reservar y devolver la reserva de la memoria es tu responsabilidad cuando
trabajas en con lenguajes como C y C++. Otros implementaciones de lenguajes cuentan con un componente que 
se ejecuta concurrente a tu código y se denomina el garbage collector (por ejemplo C#). 
El garbage collector se encarga de liberar o devolver la reserva de memoria por nosotros.

Y ¿Cómo puedes hacer para detectar errores en la gestión de memoria? Puedes utilizar una herramienta
llamada valgrind.

Considera este programa:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char* argv[]) {
        char *ptr = malloc(20*sizeof(char));
        return 0;
    }

Compila el programa así: ``gcc -g -Wall main.c -o main``. Instala valgrind
con ``sudo apt install valgrind``. Corre el programa así: ``valgrind ./main``:

.. code-block:: none

    ==331725== Memcheck, a memory error detector
    ==331725== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==331725== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
    ==331725== Command: ./main
    ==331725== 
    ==331725== 
    ==331725== HEAP SUMMARY:
    ==331725==     in use at exit: 20 bytes in 1 blocks
    ==331725==   total heap usage: 1 allocs, 0 frees, 20 bytes allocated
    ==331725== 
    ==331725== LEAK SUMMARY:
    ==331725==    definitely lost: 20 bytes in 1 blocks
    ==331725==    indirectly lost: 0 bytes in 0 blocks
    ==331725==      possibly lost: 0 bytes in 0 blocks
    ==331725==    still reachable: 0 bytes in 0 blocks
    ==331725==         suppressed: 0 bytes in 0 blocks
    ==331725== Rerun with --leak-check=full to see details of leaked memory
    ==331725== 
    ==331725== For lists of detected and suppressed errors, rerun with: -s
    ==331725== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Podrás observar en la sección LEAK SUMMARY que valgrind detectó un leak de 20 bytes.

¿Pero en dónde está el error?

Ejecuta ``valgrind --leak-check=full  ./main``

.. code-block:: none

    ==331978== Memcheck, a memory error detector
    ==331978== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==331978== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
    ==331978== Command: ./main
    ==331978== 
    ==331978== 
    ==331978== HEAP SUMMARY:
    ==331978==     in use at exit: 20 bytes in 1 blocks
    ==331978==   total heap usage: 1 allocs, 0 frees, 20 bytes allocated
    ==331978== 
    ==331978== 20 bytes in 1 blocks are definitely lost in loss record 1 of 1
    ==331978==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==331978==    by 0x109165: main (main.c:5)
    ==331978== 
    ==331978== LEAK SUMMARY:
    ==331978==    definitely lost: 20 bytes in 1 blocks
    ==331978==    indirectly lost: 0 bytes in 0 blocks
    ==331978==      possibly lost: 0 bytes in 0 blocks
    ==331978==    still reachable: 0 bytes in 0 blocks
    ==331978==         suppressed: 0 bytes in 0 blocks
    ==331978== 
    ==331978== For lists of detected and suppressed errors, rerun with: -s
    ==331978== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

Puedes ver que el error ocurrió en la línea 5 del programa ``main.c``. ¡Genial!

Ejercicio 12: corrección del memory leak
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Te animas a corregir el error del ejercicio anterior y verificar con valgrind que
todo esté bien?

Ejercicio 13: el debugger
^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Recuerdas que para poder ver el contenido del stack necesitas un debugger? Pues
vamos a probar uno. En este caso usaremos GDB. Escribe gdb en la terminal. Si el comando
no es reconocido, lo puedes instalar con ``sudo apt-get install build-essentials``.

Considera este programa:

.. code-block:: c

    #include <stdio.h>

    int main(int argc, char* argv[]) {
        char arr[14];
        
        arr[0] = 'C';
        arr[1] = 'o';
        arr[2] = 'n';
        arr[3] = 't';
        arr[4] = 'r';
        arr[5] = 'o';
        arr[6] = 'l';
        arr[7] = 'a';
        arr[8] = 'd';
        arr[9] = 'o';
        arr[10] = 'r';
        arr[11] = 'e';
        arr[12] = 's';
        arr[13] = 0;

        printf("arr: %s", arr);

        return 0;
    }

Compila el programa con ``gcc -g -Wall main.c -o main``. La opción ``-g`` le
dice al compilador que genere el ejecutable incluyendo información de depuración
en la tabla de símbolos. Esta información será usada posteriormente por GDB

Ejecuta el programa con GDB: ``gdb main``:

.. code-block:: bash

    GNU gdb (Ubuntu 9.1-0ubuntu1) 9.1
    Copyright (C) 2020 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.
    Type "show copying" and "show warranty" for details.
    This GDB was configured as "x86_64-linux-gnu".
    Type "show configuration" for configuration details.
    For bug reporting instructions, please see:
    <http://www.gnu.org/software/gdb/bugs/>.
    Find the GDB manual and other documentation resources online at:
        <http://www.gnu.org/software/gdb/documentation/>.

    For help, type "help".
    Type "apropos word" to search for commands related to "word"...
    Registered pretty printers for UE4 classes
    Reading symbols from main...
    (gdb) 

Observa que te aparecerá un nuevo prompt: ``(gdb)`` donde escribirás comandos
para GBD.

* Para comenzar la ejecución del programa escribe ``run``
* Coloca un breakpoint al iniciar la función main: ``break main``. El breakpoint le indica
  al depurador que debe tener la ejecución del proceso en ese punto.
* Escribe ``run``. Verás que la ejecución del programa se detiene en en la función
  main.
* Utiliza el comando ``n`` para ejecutar la siguiente línea de código.
* Imprime el contenido de la variable arr con ``print arr``.

La variable arr está en el stack. Puedes ver el contenido del stack con ``x/16x arr``. 
El comando es ``x`` pero además puedas indicar la cantidad de bytes (16) y el formato
(x para hexadecimal):

.. code-block:: bash

    (gdb) x/16x arr
    0x7fffffffdb8a:	0x43	0x6f	0x6e	0x74	0x72	0x6f	0x6c	0x61
    0x7fffffffdb92:	0x64	0x6f	0x72	0x65	0x73	0x00	0x00	0xcd
    (gdb)

Puedes ver el interpretados en ASCII de los valores:

.. code-block:: bash

    (gdb) x/16c arr
    0x7fffffffdb8a:	67 'C'	111 'o'	110 'n'	116 't'	114 'r'	111 'o'	108 'l'	97 'a'
    0x7fffffffdb92:	100 'd'	111 'o'	114 'r'	101 'e'	115 's'	0 '\000'	0 '\000'	-51 '\315'
    (gdb) 

Cambia el contenido del stack:

.. code-block:: bash

    (gdb) set arr[11] = 'a'
    (gdb) print arr
    $2 = "Controladoras"
    (gdb) x/16x arr
    0x7fffffffdb8a:	0x43	0x6f	0x6e	0x74	0x72	0x6f	0x6c	0x61
    0x7fffffffdb92:	0x64	0x6f	0x72	0x61	0x73	0x00	0x00	0xcd
    (gdb) x/16c arr
    0x7fffffffdb8a:	67 'C'	111 'o'	110 'n'	116 't'	114 'r'	111 'o'	108 'l'	97 'a'
    0x7fffffffdb92:	100 'd'	111 'o'	114 'r'	97 'a'	115 's'	0 '\000'	0 '\000'	-51 '\315'
    (gdb)

Trabajo autónomo 1: memoria
********************************
(Tiempo estimado: 1 hora 20 minutos)

Construye un programa que te permite visualizar cada uno de los segmentos 
de memoria de un proceso. Experimenta, adiciona más variables. NO OLVIDES 
usar GDB y valgrind.

Sesión 2: encapsulamiento
****************************

Ejercicio 14: el concepto de clase en C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El siguiente ejemplo te mostrará una técnica para el manejo de la memoria dinámica
que le entrega la responsabilidad de reservar y liberar la memoria dinámica al
código definido en el archivo queue.c. Si analizas detenidamente podrás ver
que el código en queue.h y queue.c trata de implementar el concepto de ``CLASE`` que
ya conoces de otros lenguajes de programación.

queue.h:

.. code-block:: c 

    #ifndef _QUEUE_H
    #define _QUEUE_H

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

    queue_t* create(int size);
    void destroy(queue_t* this);
    int size(queue_t* this);
    void enqueue(queue_t* this, double item);
    double dequeue(queue_t* q);

    #endif

queue.c:

.. code-block:: c 

    #include "queue.h"
    #include <stdlib.h> 

    static void init(queue_t* this, int size) {
        this->front = 0;
        this->rear = 0;
        this->arr = (double*)malloc(size * sizeof(double));
    }

    queue_t* create(int size){
        queue_t* q = malloc(sizeof(queue_t));
        init(q,size);
        return(q);
    }

    void destroy(queue_t* this){
        free(this->arr);
        free(this);
    }

    int size(queue_t* this){
        return this->rear - this->front;
    }

    void enqueue(queue_t* this, double item) {
        this->arr[this->rear] = item;
        this->rear++;
    }
    
    double dequeue(queue_t* this) {
        double item = this->arr[this->front];
        this->front++;
        return item;
    }

main.c:

.. code-block:: c 

    #include <stdio.h> 
    #include "queue.h"

    int main(int argc, char** argv) {

        queue_t* q = create(10);
        enqueue(q, 6.5);
        enqueue(q, 1.3);
        enqueue(q, 2.4);
        printf("%f\n", dequeue(q));
        printf("%f\n", dequeue(q));
        printf("%f\n", dequeue(q));
        destroy(q);
        return 0;
    }

Para compilar este ejemplo sigue los siguientes pasos:

gcc -c -g -Wall queue.c -o queue.o

gcc -c -g -Wall main.c -o main.o

gcc -g -Wall queue.o main.o -o exe

Ejecuta el código y verifica con valgrind el manejo de la memoria

./exe

valgrind ./exe

¿Qué resultado obtienes?
¿En qué parte de la memoria está almacenada la variable q?
¿Explica cuánta memoria y dónde se está creando con la función create(10)?

Ejercicio 15: el concepto de objeto
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora que conocemos más detalles de la memoria de un proceso y luego
del ejercicio anterior, ya tenemos buenas herramientas para hablar del
modelo de programación orientado a objetos.

Como te has dado cuenta hasta ahora, C no es un lenguaje de programación
orientado a objetos; sin embargo, te preguntarás ¿Es posible escribir 
programas orientados a objetos con C? La respuesta es si. El punto es que
en su sintaxis C no soporta los conceptos de clases, herencia y polimorfismo.
Aún así, es posible implementar estos conceptos de manera indirecta.

¿Y en últimas qué son los objetos?

Mira, no le demos vueltas conceptuales al asunto. Un objeto no es más que
un conjunto de datos en la memoria de un proceso. OJO: SON DATOS y están en la
MEMORIA DE UN PROCESO. Esto último es clave. Los objetos solo viven en tiempo
de ejecución.

Entonces cuando estoy escribiendo el programa hay objetos? NO, ese es el punto
precisamente que intento aclararte de entrada. Cuando escribes un programa orientado
a objetos, NO TIENES OBJETOS aún. Lo que defines es cómo serán esos objetos,
cómo se crearán, cuándo se crearán, cómo y cuándo se usarán y cómo y cuándo
se destruirán (en algunos lenguajes de programación). Es decir, tu programa
describe lo que pasará con los OBJETOS cuando lo ejecutes.

Te lo repito de nuevo: cuando programas orientado a objetos NO estás creando objetos.
Estás más bien indicando qué se debe hacer para crearlos cuando el programa se EJECUTE.

¿Claro lo anterior? Pregunta si no es claro.

Por lo anterior, es que existe el término DISEÑO ORIENTADO A OBJECTOS. Porque
cuando DISEÑAS un programa orientado a objetos te tienes qué imaginar cómo serán esos
OBJETOS, cuándo se crearán y cuáles serán las relaciones entre ellos cuando 
ejecutes el programa.

Ejercicio 16: concepto de mutabilidad e inmutabilidad
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Profe, si yo pudiera ir a ver un objeto en memoria ¿Cómo se vería?

No lo olvides, en últimas, un objeto es una colección de bytes en la memoria. A esas 
posiciones de memoria que componen el objeto las denominamos ATRIBUTOS y al contenido
de esos atributos los llamamos EL ESTADO DEL OBJETO. 

Cuando puedes modificar los valor de los atributos de un objeto mientras el programa
corre se dice que el objeto es MUTABLE. Pero también el objeto puede ser INMUTABLE,
es decir, que una vez creado el objeto e inicializados sus atributos, no podrás cambiar
sus valores o su estado.

Ejercicio 17: concepto de relación entre objetos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ya te comenté que los objetos (colecciones de bytes) pueden estar relacionados entre
ellos. ¿Qué significa eso?

En términos muy generales, si dos objetos están relacionados, es posible que al modificar
el estado de uno de ellos se afecte el estado del otro. Ya en términos más concretos podemos
decir que un objeto está relacionado con otro cuando uno de sus atributos contiene la dirección
de memoria del otro objeto.

Ejercicio 18: el concepto de método
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

No lo olvides, un objeto son bytes en memoria. Pero entonces, ¿Qué pasa con el código?

Parte de tus tareas al diseñar o PLANEAR un programa orientado a objetos es decir qué
OPERACIONES vas a realizar para crear los objetos (asignarles memoria), iniciar su estado
(¿Qué es eso?) (construirlos), destruirlos, leer y modificar su ESTADO. PERO, POR FAVOR,
no lo olvides, cuando estás escribiendo el programa estás MODELANDO tu solución,
tu programa es un PLAN que DESCRIBE lo que ocurrirá cuando sea ejecutado.

Ejercicio 19: relación estado-comportamiento
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Cómo puedes definir la construcción de un objeto?

Lo puedes hacer de dos formas:

* Construyes un objeto vacío o con un conjuntos mínimo de atributos. A medida que el programa
  se ejecuta, se van añadiendo más atributos. A esta
  técnica se le conoce como prototype-based OOP, por ejemplo en python y javascript.
* El objeto ya tiene unos atributos predeterminados. A esta
  técnica se le conoce como class-based OOP, por ejemplo en C++, C#, java y python.

Para utilizar la segunda forma, debes crear una plantilla predeterminada o CLASE que indique
los atributos que tendrá un objeto al ejecutar el programa.

Te preguntarás, pero en un clase también hay código, entonces ¿Los objetos tienen código? 
Nop. Por lo que hemos venido discutiendo ya sabes que los objetos son solo datos. 
También ya sabes que cuando escribes una clase estás PLANEANDO qué atributos tendrá cada
objeto en memoria. Entonces cuando escribes código en una clase está indicando que ese código
y los atributos están relacionados, es decir, estás indicando de manera explícita 
las posibles OPERACIONES que puedes realizar sobre los DATOS. De esta manera ENCAPSULAS
en el conceptos de CLASE los DATOS y el CÓDIGO. Ten en cuenta que al código también
se le conoce cómo el COMPORTAMIENTO de los objetos, es decir, las acciones que se realizarán
sobre los datos.  

Ejercicio 20: implementación del concepto de clase
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Cómo hacemos para implementar las ideas anteriores en C? Ya sabes que C no soporta 
de manera explícita el concepto de clase, pero podemos implementar dicho concepto de manera
implícita:

* Usa un estructura para encapsular los atributos del objeto.
* Utiliza funciones para definir el comportamiento de los objetos. Las funciones
  que definen el comportamiento del objeto recibirán como argumento la dirección
  en memoria de la estructura que encapsula los atributos del objeto.

Analiza de nuevo este código:

queue.h:

.. code-block:: c 

    #ifndef _QUEUE_H
    #define _QUEUE_H

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

    queue_t* create(int size);
    void destroy(queue_t* this);
    int size(queue_t* this);
    void enqueue(queue_t* this, double item);
    double dequeue(queue_t* q);

    #endif

queue.c:

.. code-block:: c 

    #include "queue.h"
    #include <stdlib.h> 

    static void init(queue_t* this, int size) {
        this->front = 0;
        this->rear = 0;
        this->arr = (double*)malloc(size * sizeof(double));
    }

    queue_t* create(int size){
        queue_t* q = malloc(sizeof(queue_t));
        init(q,size);
        return(q);
    }

    void destroy(queue_t* this){
        free(this->arr);
        free(this);
    }

    int size(queue_t* this){
        return this->rear - this->front;
    }

    void enqueue(queue_t* this, double item) {
        this->arr[this->rear] = item;
        this->rear++;
    }
    
    double dequeue(queue_t* this) {
        double item = this->arr[this->front];
        this->front++;
        return item;
    }

Nota que en queue.h declaras qué atributos tendrá el objeto:

.. code-block:: c 

    #ifndef _QUEUE_H
    #define _QUEUE_H

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

Y qué funciones podrás invocar para leer o escribir dichos atributos, es decir, el comportamiento
del objeto:

.. code-block:: c 

    queue_t* create(int size);
    void destroy(queue_t* this);
    int size(queue_t* this);
    void enqueue(queue_t* this, double item);
    double dequeue(queue_t* q);

Estas cuatro funciones te permiten crear una cola, destruirla, conocer su tamaño,
almacenar en la cola y leer información de ella. Nota que casi todas las funciones
definen un parámetro llamado this. Este parámetro contendrá la dirección del objeto
sobre el cual actuará el código definido en la función.

Por último, observa de nuevo la función main.c:

.. code-block:: c 

    #include <stdio.h> 
    #include "queue.h"

    int main(int argc, char** argv) {

        queue_t* q = create(10);
        enqueue(q, 6.5);
        enqueue(q, 1.3);
        enqueue(q, 2.4);
        printf("%f\n", dequeue(q));
        printf("%f\n", dequeue(q));
        printf("%f\n", dequeue(q));
        destroy(q);
        return 0;
    }

Nota que debemos incluir queue.h para poder utilizar las funciones y el nuevo
tipo de dato ``queue_t``. Observa que la función ``create(10)`` nos permite
crear un cola (un objeto) de 10 enteros en el heap. La dirección de la cola la almacenamos
en la variable ``q`` que estará en el stack.

Si analizas un poco más el archivo ``queue.c`` varás que ``create`` reserva el espacio
en heap para el objeto y adicionalmente inicializa sus atributos:

.. code-block:: c 

    static void init(queue_t* this, int size) {
        this->front = 0;
        this->rear = 0;
        this->arr = (double*)malloc(size * sizeof(double));
    }

    queue_t* create(int size){
        queue_t* q = malloc(sizeof(queue_t));
        init(q,size);
        return(q);
    }

Ejercicio 21: comparación con C#
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora compara el programa anterior con una implementación en C#:

.. code-block:: csharp

    using System;

    public class Queue{
        
        private int front;
        private int rear;
        private double[] arr;
        
        public Queue(int size){
            
            front = 0;
            rear = 0;
            arr = new double[size];
        }    
        
        public int size(){
            return (rear - front);
        }
        
        public void enqueue(double item) {
            arr[rear] = item;
            rear++;
        }
        
        public double dequeue() {
            double item = arr[front];
            front++;
            return item;
        }
    }

    class Program {
        static void Main() {
            Queue q = new Queue(10);
            q.enqueue(6.5);
            q.enqueue(1.3);
            q.enqueue(2.4);
            Console.WriteLine(q.dequeue());
            Console.WriteLine(q.dequeue());
            Console.WriteLine(q.dequeue());
        }
    }

Mira los atributos:

En C:

.. code-block:: c 

    #ifndef _QUEUE_H
    #define _QUEUE_H

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

En C#:

.. code-block:: csharp

    using System;

    public class Queue{
        
        private int front;
        private int rear;
        private double[] arr;

Mira cómo se crea el objeto y se llaman los métodos:

En C:

.. code-block:: c

    queue_t* q = create(10);
    enqueue(q, 6.5);

.. code-block:: csharp

Queue q = new Queue(10);
q.enqueue(6.5);

En la comparación anterior, notas que la implementación en C# no tiene
código para ``destroy``. ¿Recuerdas por qué es esto?

El programa en C# también podríamos escribirlo así:

.. code-block:: csharp

    using System;

    public class Queue{
        
        private int front;
        private int rear;
        private double[] arr;
        
        public Queue(int size){
            
            this.front = 0;
            this.rear = 0;
            this.arr = new double[size];
        }    
        
        public int size(){
            return (this.rear - this.front);
        }
        
        public void enqueue(double item) {
            this.arr[rear] = item;
            this.rear++;
        }
        
        public double dequeue() {
            double item = this.arr[front];
            this.front++;
            return item;
        }
    }
    
    
    class Program {
        
        static void Main() {
            Queue q = new Queue(10);
            q.enqueue(6.5);
            q.enqueue(1.3);
            q.enqueue(2.4);
            Console.WriteLine(q.dequeue());
            Console.WriteLine(q.dequeue());
            Console.WriteLine(q.dequeue());
        }
    }

Nota qué cambió con respecto a la primera implementación que te mostré.
¿Lo notaste? En esta segunda implementación estoy utilizando la palabra
reservada ``this``. Esta variable contiene la dirección en memoria del
objecto a través del cual llamamos el método. Observa de nuevo el código
en C. Notas ¿Cómo están relacionados los conceptos?

Trabajo autónomo 2: encapsulamiento
***************************************
(Tiempo estimado: 1 hora 20 minutos)

Vuelve a leer el material de esta sección y asegúrate de analizar con 
detenimiento los ejercicios 20 y 21.

Sesión 3: relaciones entre objetos
**************************************

Ejercicio 22: relación de composición entre objetos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cuando DISEÑAS un programa orientado a objetos
también debes considerar las relaciones entre esos objetos. Pues bien, en general
hay dos tipos:

* Relaciones TO-HAVE o HAS-TO (TIENE UN)

* Relaciones TO-BE o IS-A (ES UN) (¿recuerdas la herencia?)

Vamos a concentrarnos primero en las TO-HAVE: la composición y la agregación.

¿Qué es una relación de composición? 

Dos objetos tienen una relación de composición cuando uno de ellos contiene a
otro objeto. Debes tener en cuenta que en una relación de composición la VIDA del objeto
contenido depende de la vida del objeto contenedor, es decir, 
si el objeto contenedor muere, el objeto contenido también. Cuando el objeto
contenedor se va destruir, primero tendrá que hacerse con el objeto contenido.

Mira de nuevo este código:

.. code-block:: c 

    #include "queue.h"
    #include <stdlib.h> 

    static void init(queue_t* this, int size) {
        this->front = 0;
        this->rear = 0;
        this->arr = (double*)malloc(size * sizeof(double));
    }

    queue_t* create(int size){
        queue_t* q = malloc(sizeof(queue_t));
        init(q,size);
        return(q);
    }


Observa la función ``create``. Dicha función crear una ``queue``.
¿Qué datos componen la cola?

.. code-block:: c 

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

    #endif

A su vez se en ``init`` estamos creando un nuevo objeto que no es más
que un arreglo de ``size`` ``doubles``. La relación entre estos dos objetos
es de composición.  

Ahora nota que al momento de destruir el objeto contenedor, primero se
destruye el objeto contenido:

.. code-block:: c 

    void destroy(queue_t* this){
        free(this->arr);
        free(this);
    }

Ejercicio 23: relación de agregación
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué es la agregación?

En esta relación tenemos también un objeto contenedor y un objeto contenido, la
gran diferencia con la composición es que la vida del objeto contenido no depende
de la vida del objeto contenedor. El objeto contenido puede ser construido incluso
antes de que el objeto contenedor sea construido.

Ejercicio 24: MINI-RETO
^^^^^^^^^^^^^^^^^^^^^^^^^

Con todo lo anterior en mente y esta nueva definición, te tengo un mini RETO:

Implementa un programa en C modelado con objetos que implemente una relación de
agregación para esta situación: " ...el jugador recoge un arma, la usa varias veces 
y luego la tira..."

.. note::
    ¡Alerta de Spoiler!

    Una posible implementación a este mini-reto la puedes ver en el siguiente código
    tomado de `este <https://www.packtpub.com/free-ebook/extreme-c/9781789343625>`__ 
    . Le hice unas pequeñas modificaciones al código para que puedas ver el resultado
    en la terminal.

gun.h:

.. code-block:: c 

    #ifndef GUN_H_
    #define GUN_H_

    typedef struct
    {
        int bullets;
    } gun_t;

    gun_t *gun_new();
    void gun_ctor(gun_t *, int);
    void gun_dtor(gun_t *);

    int gun_has_bullets(gun_t *);
    void gun_trigger(gun_t *);
    void gun_refill(gun_t *);

    #endif /* GUN_H_ */


gun.c:

.. code-block:: c 

    #include <stdlib.h>
    #include <stdio.h>
    #include "gun.h"

    gun_t *gun_new()
    {
        return (gun_t *)malloc(sizeof(gun_t));
    }

    void gun_ctor(gun_t *this, int initial_bullets)
    {
        this->bullets = 0;
        if (initial_bullets > 0)
        {
            this->bullets = initial_bullets;
        }
    }

    void gun_dtor(gun_t *this)
    {

    }

    int gun_has_bullets(gun_t *this)
    {
        return (this->bullets > 0);
    }

    void gun_trigger(gun_t *this)
    {
        this->bullets--;
        printf("gun triggered\n");
    }

    void gun_refill(gun_t *this)
    {
        this->bullets = 7;
    }

    
player.h:

.. code-block:: c 

    #ifndef PLAYER_H_
    #define PLAYER_H_

    #include "gun.h"

    typedef struct
    {
        char *name;
        gun_t *gun;
    } player_t;

    player_t *player_new();
    void player_ctor(player_t *, const char *);
    void player_dtor(player_t *);

    void player_pickup_gun(player_t *, gun_t *);
    void player_shoot(player_t *);
    void player_drop_gun(player_t *);

    #endif /* PLAYER_H_ */


player.c:

.. code-block:: c 

    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include "gun.h"
    #include "player.h"

    player_t *player_new()
    {
        return (player_t *)malloc(sizeof(player_t));
    }

    void player_ctor(player_t *this, const char *name)
    {
        this->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(this->name, name);
        this->gun = NULL;
    }

    void player_dtor(player_t *this)
    {
        free(this->name);
    }

    void player_pickup_gun(player_t *this, gun_t *gun)
    {
        this->gun = gun;
    }

    void player_shoot(player_t *this)
    {
        if (this->gun)
        {
            gun_trigger(this->gun);
        }
        else
        {
            printf("Player wants to shoot but he doesn't have a gun!\n");
            exit(1);
        }
    }

    void player_drop_gun(player_t *this)
    {
        this->gun = NULL;
    }


main.c:

.. code-block:: c 

    #include <stdio.h>
    #include <stdlib.h>
    #include "gun.h"
    #include "player.h"

    int main(int argc, char *argv[])
    {
        gun_t *gun = gun_new();
        gun_ctor(gun, 3);

        player_t *player = player_new();
        player_ctor(player, "Billy");

        player_pickup_gun(player, gun);

        while (gun_has_bullets(gun))
        {
            player_shoot(player);
        }

        gun_refill(gun);

        while (gun_has_bullets(gun))
        {
            player_shoot(player);
        }

        player_drop_gun(player);

        player_dtor(player);
        free(player);
    gcc -Wall -c person.c -o person.o                             
    gcc -Wall -c student.c -o student.o                           
    gcc -Wall -c main.c -o main.o      
    gcc -Wall main.o person.o student.o -o app

    gcc -Wall -c  player.c -o player.o    
    gcc -Wall -c  gun.c -o gun.o          
    gcc -Wall -c  main.c -o main.o        
    gcc -Wall main.o player.o gun.o -o app

Ejercicio 25: representación UML de las relaciones
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Recuerdas que en tu curso de programación y diseño orientado a objetos
vistes las relaciones anteriores?

En ese curso a los dos relaciones anteriores: agregación y composición
se les denomina en general asociaciones, es decir, dos objetos pueden estar
asociados mediante una relación de agregación o composición.

Estas relaciones pueden mostrarse de manera gráfica utilizando un
lenguaje de modelado conocido como `UML <http://uml.org/>`__. Te dejo aquí
una imagen:

.. image:: ../_static/UMLasoc.png
    :alt: relaciones en UML

Ejercicio 26: ejericio de modelado UML
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Te animas a realizar un modelo UML para nuestros dos ejemplos de composición
y agregación?

Ejercicio 27: relación de herencia
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El otro tipo de relación que podemos tener entre dos objetos es la relación TO-BE, 
mejor conocida como herencia. 

¿Cómo funciona la herencia?

En términos simples, la herencia permite añadirle a un objeto atributos de otro
objeto. 

.. code-block:: c

    typedef struct {
        char first_name[32];
        char last_name[32];
        unsigned int birth_year;
    } person_t;

    typedef struct {
        char first_name[32];
        char last_name[32];
        unsigned int birth_year;
        char student_number[16]; // Extra attribute
        unsigned int passed_credits; // Extra attribute
    } student_t;

En el ejemplo anterior (tomado del de `aquí <https://www.packtpub.com/free-ebook/extreme-c/9781789343625>`__
nota los atributos de la estructura person_t y student_t. ¿Ves alguna relación entre ellos?

student_t ``extiende`` los atributos de person_t. Por tanto, podemos decir que student_t también
ES UNA (IS-A) person_t.

Observa entonces que podemos escribir de nuevo el código anterior así:

.. code-block:: c

    typedef struct {
        char first_name[32];
        char last_name[32];
        unsigned int birth_year;
    } person_t;
    
    typedef struct {
        person_t person;
        char student_number[16]; // Extra attribute
        unsigned int passed_credits; // Extra attribute
    }student_t;personPrivate

¿Ves lo que pasó? estamos anidando una estructura en otra estructura. Por tanto student_t hereda
de person_t. Observa que un puntero a student_t estará apuntando al primer atributo que es
un person_t. ¿Lo ves? Por eso decimos que un student_t también ES UN person_t. Míralo en acción
aquí:

.. code-block:: c

    #include <stdio.h>

    typedef struct {
        char first_name[32];
        char last_name[32];
        unsigned int birth_year;
    }person_t;

    typedef struct {
        person_t person;
        char student_number[16]; // Extra attribute
        unsigned int passed_credits; // Extra attribute
    } student_t;

    int main(int argc, char* argv[]) {
        student_t s;
        student_t* s_ptr = &s;
        person_t* p_ptr = (person_t*)&s;
        printf("Student pointer points to %p\n", (void*)s_ptr);
        printf("Person pointer points to %p\n", (void*)p_ptr);
        return 0;
    }

Ejercicio 28: para reflexionar
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En este punto te pido que te pongas cómodo. Lo que viene será alucinante...

Del ejercicio anterior concluimos que student_t está heredando de person_t.
Por tanto, a las funciones que definas para manipular un objeto de tipo
person_t también le puedes pasar un puntero a un student_t (para manipular
sus atributos correspondiente a person_t). SEÑORES y SEÑORAS, estamos
reutilizando código.

Ejercicio 29: implementación de herencia simple
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te voy a mostrar una técnica para implementar herencia simple en C.
Analiza con detenimiento este código por favor 
(`tomado de aquí <https://www.packtpub.com/free-ebook/extreme-c/9781789343625>`__):

person.h:

.. code-block:: c

    #ifndef PERSON_H_
    #define PERSON_H_

    typedef struct {
        char first_name[32];
        char last_name[32];
        unsigned int birth_year;
    } person_t;

    person_t *person_new();
    void person_ctor( person_t *, const char *, const char *, unsigned int);
    void person_dtor(person_t *);

    void person_get_first_name(person_t *, char *);
    void person_get_last_name(person_t *, char *);
    unsigned int person_get_birth_year(person_t *);

    #endif /* PERSON_H_ */

Código para person.c:

.. code-block:: c

    #include <stdlib.h>
    #include <string.h>
    #include <stdlib.h>
    #include "person.h"

    person_t *person_new() {
        return malloc(sizeof(person_t));
    }

    void person_ctor(person_t *this,
            const char *first_name,
            const char *last_name,
            unsigned int birth_year) {

                strcpy(this->first_name, first_name);
                strcpy(this->last_name, last_name);
                this->birth_year = birth_year;
    }

    void person_dtor(person_t *this) {

    }

    void person_get_first_name(person_t *this, char *buffer) {
        strcpy(buffer, this->first_name);
    }

    void person_get_last_name(person_t *this, char *buffer) {
        strcpy(buffer, this->last_name);
    }

    unsigned int person_get_birth_year(person_t *this) {
        return this->birth_year;
    }

    void person_get_last_name(person_t *this, char *buffer) {
        strcpy(buffer, this->last_name);
    }

    unsigned int person_get_birth_year(person_t *this) {
        return this->birth_year;
    }

student.h:

.. code-block:: c

    #ifndef STUDENT_H_
    #define STUDENT_H_

    #include "person.h"

    typedef struct {
        person_t person;
        char *student_number;
        unsigned int passed_credits;
    } student_t;

    student_t *student_new();
    void student_ctor(student_t *,
                    const char * /* first name */,
                    const char * /* last name */,
                    unsigned int /* birth year */,
                    const char * /* student number */,
                    unsigned int /* passed credits */);
    void student_dtor(student_t *);

    void student_get_student_number(student_t *, char *);
    unsigned int student_get_passed_credits(student_t *);

    #endif /* STUDENT_H_ */


student.c:

.. code-block:: c

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "person.h"
    #include "student.h"

    student_t *student_new() {
        return (student_t *)malloc(sizeof(student_t));
    }

    void student_ctor(student_t *this,
                    const char * first_name,
                    const char * last_name,
                    unsigned int birth_year,
                    const char * student_number,
                    unsigned int passed_credits) {

        person_ctor((person_t *)this,
        first_name, last_name, birth_year);
        this->student_number = (char *)malloc(16 * sizeof(char));
        strcpy(this->st´ent_number);
        person_dtor((person_t *)this);
    }

    void student_get_student_number(student_t *this,
            char *buffer) {
            strcpy(buffer, this->student_number);
    }

    unsigned int student_get_passed_credits(student_t *this) {
        return this->passed_credits;
    }

main.c:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include "person.h"
    #include "student.h"

    int main(int argc, char* argv[]) {
        char buffer[32];

        student_t *student = student_new();
        student_ctor(student, "John", "Doe", 1987, "TA5667", 134);
        
        person_t *person_ptr = (person_t *)student;
        person_get_first_name(person_ptr, buffer);
        printf("First name: %s\n", buffer);
        person_get_last_name(person_ptr, buffer);
        printf("Last name: %s\n", buffer);
        printf("Birth year: %d\n", person_get_birth_year(person_ptr));

        student_get_student_number(student, buffer);
        printf("Student number: %s\n", buffer);
        printf("Passed credits: %d\n",
        student_get_passed_credits(student));

        student_dtor(student);
        free(student);
        return 0;
    }

Para compilar y generar la aplicación:

.. code-block:: bash

    gcc -Wall -c person.c -o person.o                             
    gcc -Wall -c student.c -o student.o                           
    gcc -Wall -c main.c -o main.o      
    gcc -Wall main.o person.o student.o -o app

Sesión 4: polimorfismo
**************************

Ejercicio 30: POLIMORFISMO en tiempo de ejecución
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te voy a mostrar una técnica para implementar polimorfismo en tiempo de 
ejecución en C (`tomado de aquí <https://www.packtpub.com/free-ebook/extreme-c/9781789343625>`__).

Pero antes ¿Qué es el polimorfismo en tiempo de ejecución? Antes mira qué te permite hacer
el polimorfismo. Considera que tienes estos tres objetos:

.. code-block:: c

    struct animal_t* animal = animal_new();
    animal_ctor(animal);

    struct cat_t* cat = cat_new();
    cat_ctor(cat);

    struct duck_t* duck = duck_new();
    duck_ctor(duck);

cat y duck heredan de animal. Por tanto, como cat y duck son animal también,
entonces al hacer esto:

.. code-block:: c

    // This is a polymorphism
    animal_sound(animal);
    animal_sound((struct animal_t*)cat);
    animal_sound((struct animal_t*)duck);

Consigues esta salida:

.. code-block:: c

    Animal: Beeeep
    Cat: Meow
    Duck: Quack

Entonces puedes ver que la función animal_sound exhibe un comportamiento polimórfico
dependiendo del tipo de referencia que le pasemos.

¿Para qué sirve esto? Supón que tienes un código base al cual quieres adicionarle
funcionalidades nuevas. El polimorfismo te permite mantener el código base lo más intacto
posible a medida que añades más comportamientos por medio de la herencia.

Ahora, si. Mira cómo se puede implementar:

animal.h:

.. code-block:: c

    #ifndef ANIMAL_H_
    #define ANIMAL_H_
    
    // Forward declaration
    struct animal_t;
    
    // Memory allocator
    struct animal_t* animal_new();
    
    // Constructor
    void animal_ctor(struct animal_t*);
    
    // Destructor
    void animal_dtor(struct animal_t*);
    
    // Behavior functions
    void animal_get_name(struct animal_t*, char*);
    void animal_sound(struct animal_t*);
    
    
    #endif /* ANIMAL_H_ */

animal.c:

.. code-block:: c

    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    
    #include "animalPrivate.h"
    
    // Default definition of the animal_sound at the parent level
    void __animal_sound(void* this_ptr) {
        animal_t* animal = (animal_t*)this_ptr;
        printf("%s: Beeeep\n", animal->name);
    }
    
    // Memory allocator
    animal_t* animal_new() {
        return (animal_t*)malloc(sizeof(animal_t));
    }
    
    // Constructor
    void animal_ctor(animal_t* animal) {
        animal->name = (char*)malloc(10 * sizeof(char));
        strcpy(animal->name, "Animal");
        // Set the function pointer to point to the default definition
        animal->sound_func = __animal_sound;
    }
    
    // Destructor
    void animal_dtor(animal_t* animal) {
        free(animal->name);
    }
    // Behavior functions
    void animal_get_name(animal_t* animal, char* buffer) {
        strcpy(buffer, animal->name);
    }
    
    void animal_sound(animal_t* animal) {
        // Call the function which is pointed by the function pointer.
        animal->sound_func(animal);
    }


animalPrivate.h:

.. code-block:: c

    #ifndef ANIMALPRIVATE_H_
    #define ANIMALPRIVATE_H_
    
    // The function pointer type needed to point to
    // different morphs of animal_sound
    typedef void (*sound_func_t)(void*);
    
    // Forward declaration
    typedef struct {
        char* name;
        // This member is a pointer to the function which
        // performs the actual sound behavior
        sound_func_t sound_func;
    } animal_t;
    
    #endif /* ANIMALPRIVATE_H_ */


cat.h:

.. code-block:: c

    #ifndef CAT_H_
    #define CAT_H_
    
    // Forward declaration
    struct cat_t;
    
    // Memory allocator
    struct cat_t* cat_new();
    
    // Constructor
    void cat_ctor(struct cat_t*);
    
    // Destructor
    void cat_dtor(struct cat_t*);
    // All behavior functions are inherited from the animal class.
    
    #endif /* CAT_H_ */

cat.c:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #include "animal.h"
    #include "animalPrivate.h"
    
    typedef struct {
        animal_t animal;
    } cat_t;
    
    // Define a new behavior for the cat's sound
    void __cat_sound(void* ptr) {
        animal_t* animal = (animal_t*)ptr;
        printf("%s: Meow\n", animal->name);
    }
    
    // Memory allocator
    cat_t* cat_new() {
        return (cat_t*)malloc(sizeof(cat_t));
    }
    // Constructor
    void cat_ctor(cat_t* cat) {
        animal_ctor((struct animal_t*)cat);
        strcpy(cat->animal.name, "Cat");
        // Point to the new behavior function. Overriding
        // is actually happening here.
        cat->animal.sound_func = __cat_sound;
    }
    
    // Destructor
    void cat_dtor(cat_t* cat) {
        animal_dtor((struct animal_t*)cat);
    }

duck.h:

.. code-block:: c
    
    #ifndef DUCK_H_
    #define DUCK_H_
    
    // Forward declaration
    struct duck_t;
    
    // Memory allocator
    struct duck_t* duck_new();
    
    // Constructor
    void duck_ctor(struct duck_t*);
    
    // Destructor
    void duck_dtor(struct duck_t*);
    
    // All behavior functions are inherited from the animal class.
    
    
    #endif /* DUCK_H_ */

duck.c:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #include "animal.h"
    #include "animalPrivate.h"
    
    typedef struct {
        animal_t animal;
    } duck_t;
    
    // Define a new behavior for the duck's sound
    void __duck_sound(void* ptr) {
        animal_t* animal = (animal_t*)ptr;
        printf("%s: Quacks\n", animal->name);
    }
    
    // Memory allocator
    duck_t* duck_new() {
        return (duck_t*)malloc(sizeof(duck_t));
    }
    
    // Constructor
    void duck_ctor(duck_t* duck) {
        animal_ctor((struct animal_t*)duck);
        strcpy(duck->animal.name, "Duck");
        // Point to the new behavior function. Overriding
        // is actually happening here.
        duck->animal.sound_func = __duck_sound;
    }
    
    // Destructor
    void duck_dtor(duck_t* duck) {
        animal_dtor((struct animal_t*)duck);
    }


main.c:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    // Only public interfaces
    #include "animal.h"
    #include "cat.h"
    #include "duck.h"
    
    
    int main(int argc, char** argv) {
        struct animal_t* animal = animal_new();
        struct cat_t* cat = cat_new();
        struct duck_t* duck = duck_new();
    
        animal_ctor(animal);
        cat_ctor(cat);
        duck_ctor(duck);
    
        animal_sound(animal);
        animal_sound((struct animal_t*)cat);
        animal_sound((struct animal_t*)duck);
    
        animal_dtor(animal);
        cat_dtor(cat);
        duck_dtor(duck);
    
        free(duck);
        free(cat);
        free(animal);
        return 0;
    }

Ejercicio 31: clases abstractas
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué son las clases abstractas? Son un tipo de clases de las cuales no puedes
crear OBJETOS porque les falta o tienen incompleta una parte. 
Entonces ¿Para qué sirven? Sirven para crear programas
orientados a objetos que puedan extenderse al máximo y con la menor cantidad
de dependencias entre sus componentes. ¿Te suena que vale la pena?

Mira este problema: tienes que construir una biblioteca que te permita comunicar,
por un puerto serial, a Unity con un sensor. Las responsabilidades del código
son: gestionar el puerto serial, gestionar la comunicación con el hilo
principal o hilo del motor y enviar-recibir datos siguiendo un protocolo específico.
En este escenario podrías escribir una biblioteca que resuelva este problema solo
para el sensor particular o escribirla de tal manera que puedas reutilizar
casi todo el código y solo cambiar el protocolo de comunicación si a futuro
cambias de sensor.

¿Cuál de las dos opciones de suena más?

Si te suena más la segunda, entonces todas las partes comunes del código irán
en la clase abstracta y las partes que varían, en este caso el protocolo de comunicación,
irán en otra clase que herede de la clase abstracta. Aquí entra en juego el otro concepto
que estudiamos, el POLIMORFISMO, ¿Cómo? En el código de la clase
abstracta se llamará el código que varía o métodos VIRTUALES, pero este código no estará 
implementado. Por tanto, los métodos virtuales tendrás que implementarlo en la clase que
hereda, de la cual, si PUEDES crear OBJETOS. Hermoso, ¿No?.

En lenguajes de programación como C# se hace
`así <https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/abstract>`__.
En C++ sería `así <https://www.geeksforgeeks.org/virtual-function-cpp/>`__.

Ten presente que en la medida que llevas al extremo este concepto de abstracción podrás
llegar a clases que no tengan atributos sino SOLO métodos virtuales. En este punto habrás
llegado a las INTERFACES, de las cuales tampoco podrás crear objetos.

Ejercicio 32: caso de estudio sobre interfaces
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

`Estudia <https://chris-wood.github.io/2016/02/12/Polymorphism-in-C.html>`__ con detenimiento 
esta implementación de interfaces.

Trabajo autónomo 3,4: relaciones entre objetos y polimorfismo
***************************************************************
(Tiempo estimado: 10 horas 20 minutos)

Revisa de nuevo la sección 3 y en especial los ejercicios 24 y 29.

Analiza de nuevo el ejercicio 30 y el ejercicio 32. Trata de 
realizar diagramas donde visualices la relación entre las diferentes variables.

Evaluación Unidad 3
---------------------
Regresa aquí en la semana de evaluación y presiona F5 para 
cargar el enunciado.

