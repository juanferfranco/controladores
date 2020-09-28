Semana 13: Unidad 4
==========================

Ya sabes cómo se genera el código de máquina desde varios
lenguajes de programación de alto nivel. También aprendiste sobre el lenguaje de
programación C y C++ y cómo funciona la implementación de C#. Ahora vamos a
explorar cómo funciona un modelo de programación conocido como la programación orientada a objetos.

Antes de comenzar en si el propósito de esta unidad, tenemos que comprender mejor cómo
es la memoria de un proceso.

Propósito de aprendizaje
--------------------------

Reconocer e implementar los conceptos de la programación orientada a objetos.

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
* Fecha: septiembre 29 de 2020 - 8 a.m.
* Descripción: ejercicios de la unidad 4
* Recursos: ingresa al grupo de Teams
* Duración de la actividad: 1 hora 40 minutos de discusión
* Forma de trabajo: colaborativo con solución de dudas en tiempo real.

Ejercicio 1
#############
En la semanas anteriores hablamos del concepto de proceso ¿Recuerdas? Pues
un proceso no es más que una abstracción que emplea el sistema operativo para
ejecutar y administrar un programa en ejecución. Los programas están almacenados
en archivos conocidos como object files. Para ejecutar un programa el sistema
operativo crea un proceso que ejecuta el object file, es decir, la CPU (o un
core) consumirá (fetch) y ejecutará las instrucciones del object file que estarán
almacenadas en alguna región de la memoria principal. Tu sabes también que los
programas en ejecución necesitarán memoria para almacenar las variables. Entonces
surge la siguiente pregunta ¿Cómo es la memoria de un proceso
y cuál es su estructura?

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

Ejercicio 2
#############
¿Cómo hacemos para ver el contenido de los segmentos de memoria provenientes del
object file?

Escribe el siguiente programa llamado main.c:

.. code-block:: c
   :linenos:

    int main(int argc, char* argv[]) {

        return 0;
    }

Compila el programa con ``gcc -Wall main.c -o main``. Podrás observar el tamaño de 
algunos segmentos:

``size main`` 

.. code-block:: c

   text	   data	    bss	    dec	    hex	filename
   1418	    544	      8	   1970	    7b2	main

Puedes observar tres segmentos: text, data y bss.

Ejercicio 3
#############
Te estarás preguntado ¿Para qué sirve cada uno de los segmentos
que acabas de ver?

El segmento BSS denota la cantidad de memoria reservada para variables globales
que no se inicializaron o que se inicializan a 0.

Modifica el programa anterior así:

.. code-block:: c
   :linenos:

    int var1;
    int var2;
    int var3 = 0;

    int main(int argc, char* argv[]) {

        return 0;
    }

De nuevo, compila y ejecuta ``size main``:

.. code-block:: c

   text	   data	    bss	    dec	    hex	filename
   1418	    544	     16	   1978	    7ba	main

Compara esta salida con la anterior. ¿Notas un cambio en BSS?

Ejercicio 4
#############
Tal vez alguna vez has escuchado decir que declarar variables globales
no es buena práctica. ¿Por qué?

* Si defines muchas variables globales incrementas el tamaño
  del binario (como puedes ver con size)
* Puede introducir problemas de seguridad
* Pueden introducir problemas de concurrencia como las condiciones
  de carrera.
* Polucionan el espacio de nombres del programa.

Estas respuestas seguro te generan más preguntas. Algunas de estas
preguntas seguro las responderemos en las próximas semanas, otras
de ellas quedan para tu curiosidad o en una nueva temporada de esta seria :)

Ejercicio 5
#############
Para analizar el segmento data te propongo modificar de nuevo nuestro programa:

.. code-block:: c
   :linenos:

    int var1;
    int var2;
    int var3 = 0;
    int var4 = 69;
    int var5 = 666;

    int main(int argc, char* argv[]) {

        return 0;
    }

Compila y ejecuta ``size main``:

.. code-block:: c
   
   text	   data	    bss	    dec	    hex	filename
   1418	    552	     16	   1986	    7c2	main

Compara, ¿El segmento data cambió? El segmento ``data`` entonces te sirve para almacenar
las variables inicializadas con valores diferentes de 0.

Ejercicio 6
#############
Modifica de nuevo el archivo:

.. code-block:: c
   :linenos:

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

.. code-block:: c

   text	   data	    bss	    dec	    hex	filename
   1506	    556	     20	   2082	    822	main

Observa entonces que los segmentos data y bss se incrementan.

Ejercicio 7
#############
¿Cómo hago para ver el contenido del segmento data?

Toma como referencia el programa anterior y escribe el comando ``objdump -s -j .data main``

.. code-block:: c

    main:     file format elf64-x86-64

    Contents of section .data:
    4000 00000000 00000000 08400000 00000000  .........@......
    4010 45000000 9a020000                    E....... 

¿Puedes ver efectivamente el contenido? observa los valores iniciales de ``var4`` y ``var5`` en
el programa. Ten presente que ``4000`` y ``4010`` son direcciones. El resto de información
es datos, cada file muestra 16 bytes (máximo) y luego se ve la representación de cada byte en ASCII.

Ejercicio 8
#############
En el segmento de texto está contenido todo el código de máquina del programa producido por
el compilador.

¿Cómo puedes ver el contenido?

Ejecuta ``objdump -S main``

Podrás observar el código de máquina y la representación simbólica en lenguaje ensamblador.

Ejercicio 9
#############

¿Cómo hacemos para ver el contenido de los segmentos stack y heap?

Solo podemos ver esta parte de la memoria cuando el programa esté en ejecución. Cuando
quieres ejecutar un object file, el sistema operativo crea un nuevo proceso e inicializa
su memoria. Los segmentos BSS, data y text son inicializados con la información que está en
el object file y, el stack y el heap se añaden y son modificados a medida que el código
del segmento text es leído por parte de la CPU.

Veamos un ejemplo:

.. code-clock:: c
   :linenos:

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

.. code-block:: c 

    juanfranco@pop-os:/tmp/linker$ ./main &
    [1] 295236

NO LO HAGAS AHORA, pero si después quieres matar el proceso escribe en la terminal 
``kill -9 295236``.

En Linux puedes consultar información del proceso en el directorio ``/proc`` allí tendrás
una entrada para el proceso identificada con el pid del mismo.

Ejecuta el comando ``ls -al /proc/295236``:

.. code-block:: c 
   :linenos:

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
   :linenos:

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

¿Puedes identificar el tamaño del stack? Mira que no es muy grande, es por ello que no DEBES
usar el stack para guardar variables grandes. Si necesitas arreglos o estructuras de datos grandes
debes usar el HEAP.

Ejercicio 10
#############
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

Ejercicio 11
#############
Profundicemos un poco más en el heap.

Considera el siguiente código:

.. code-block:: c
   :linenos:

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

¿Ves el segmento heap? ¿Qué tamaño tiene? Nota que en el programa reservamos 1 KiB pero realmente se
reservar 4 KiB.

Mira el rango de direcciones del heap: ``55f05576b000-55f05578c000``, ahora observa la dirección
de ``ptr``: ``0x55f05576b2a0`` Ah! está en el rango, está en el heap.

IMPORTANTE: el tamaño del heap puede crecer hasta varias gigas, solo que en este caso se reservaron
de entrada 4 KiB.

Volvamos al programa. Considera esta línea: ``void* ptr = malloc(1024)`` ¿La variable ptr
en qué segmento está?

¿Qué pasa con la dirección de la región que reservamos una vez salgamos del ámbito en el cual
se declaró prt?

Y si perdemos la dirección ¿Qué pasa con esa memoria que reservamos? ¿Y qué pasa si esto
nos comienza a ocurrir mucho en nuestro programa?

¿Recuerdas cómo evitamos este desperdicio de memoria? (¿Cuál es la función que libera la reserva?)

No olvides que reservar y devolver la reserva de la memoria es tu responsabilidad cuando
trabajas en con lenguajes como C y C++. Otros implementaciones de lenguajes cuentan con un componente que se ejecuta
concurrente a tu código y se denomina el garbage collector (por ejemplo C#). El garbage collector se encarga
de liberar o devolver la reserva de memoria por nosotros.

Y ¿Cómo puedes hacer para detectar errores en la gestión de memoria? Puedes utilizar una herramienta
llamada valgrind.

Considera este programa:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char* argv[]) {
        char *ptr = malloc(20*sizeof(char));
        return 0;
    }

Compila el programa así: ``gcc -g -Wall main.c -o main``. Instala valgrind
con ``sudo apt install valgrind``. Corre el programa así: ``valgrind ./main``:

.. code-block:: c

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

.. code-block:: c

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

Actividad 2
^^^^^^^^^^^^
* Fecha: septiembre 29 a octubre 1 de 2020 
* Descripción: trabajo autónomo en los ejercicios
* Recursos: ejercicios de la unidad 4
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

Ejercicio 12
#############
¿Te animas a corregir el error del ejercicio anterior y verificar con valgrind que
todo esté bien?

Ejercicio 13
#############
¿Recuerdas que para poder ver el contenido del stack necesitas un debugger? Pues
vamos a probar uno. En este caso usaremos GDB. Escribe gdb en la terminal. Si el comando
no es reconocido, lo puedes instalar con ``sudo apt-get install build-essentials``.

Considera este programa:

.. code-block:: c
   :linenos:

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

.. code-block:: c

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

.. code-block:: c

    (gdb) x/16x arr
    0x7fffffffdb8a:	0x43	0x6f	0x6e	0x74	0x72	0x6f	0x6c	0x61
    0x7fffffffdb92:	0x64	0x6f	0x72	0x65	0x73	0x00	0x00	0xcd
    (gdb)

Puedes ver el interpretados en ASCII de los valores:

.. code-block:: c

(gdb) x/16c arr
0x7fffffffdb8a:	67 'C'	111 'o'	110 'n'	116 't'	114 'r'	111 'o'	108 'l'	97 'a'
0x7fffffffdb92:	100 'd'	111 'o'	114 'r'	101 'e'	115 's'	0 '\000'	0 '\000'	-51 '\315'
(gdb) 

Cambia el contenido del stack:

.. code-block:: c

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

Ejercicio 14
#############

El siguiente ejemplo te mostrará una técnica para el manejo de la memoria dinámica
que le entrega la responsabilidad de reservar y liberar la memoria dinámica al
código definido en el archivo queue.c. Si analizas detenidamente podrás ver
que el código en queue.h y queue.c trata de implementar el concepto de clase que
ya conoces de otros lenguajes de programación.

queue.h:

.. code-block:: c 
   :linenos:

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
   :linenos:

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
   :linenos:

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

Actividad 3
^^^^^^^^^^^^
* Fecha: octubre 1 de 2020 - 10 a.m. 
* Descripción: ejercicios de la unidad 4
* Recursos: ingresa al grupo en Teams
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

Actividad 4
^^^^^^^^^^^^
* Fecha: octubre 1 a octubre 6 de 2020
* Descripción: trabajo autónomo en los ejercicios y reto
* Recursos: actividad de trabajo autónomo
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

Ahora que conocemos más detalles de la memoria de un proceso y luego
del ejercicio anterior, ya tenemos buenas herramientas para hablar del
modelo de programación orientado a objetos.

Como te has dado cuenta hasta ahora, C no es un lenguaje de programación
orientado a objetos; sin embargo, te preguntarás ¿Es posible escribir 
programas orientados a objetos con C? La respuesta es si. El punto es que
en su sintaxis C no soporta los conceptos de clases, herencia, y funciones
virtuales. Aún así, es posible implementar estos conceptos de manera indirecta.

Ejercicio 15
#############
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

Ejercicio 16
#############
Profe, si yo pudiera ir a ver un objeto en memoria ¿Cómo se vería?

No lo olvides, en últimas, un objeto es una colección de bytes en la memoria. A esas 
posiciones de memoria que componen el objeto las denominamos ATRIBUTOS y al contenido
de esos atributos los llamamos EL ESTADO DEL OBJETO. 

Cuando puedes modificar los valor de los atributos de un objeto mientras el programa
corre se dice que el objeto es MUTABLE. Pero también el objeto puede ser INMUTABLE,
es decir, que una vez creado el objeto e inicializados sus atributos, no podrás cambiar
sus valores o su estado.

Ejercicio 17
#############
Ya te comenté que los objetos (colecciones de bytes) pueden estar relacionados entre
ellos. ¿Qué significa eso?

En términos muy generales, si dos objetos están relacionados, es posible que al modificar
el estado de uno de ellos se afecte el estado del otro. Ya en términos más concretos podemos
decir que un objeto está relacionado con otro cuando uno de sus atributos contiene la dirección
de memoria del otro objeto.

Ejercicio 18
#############
No lo olvides, un objeto son bytes en memoria. Pero entonces, ¿Qué pasa con el código?

Parte de tus tareas al diseñar o PLANEAR un programa orientado a objetos es decir qué
OPERACIONES vas a realizar para crear los objetos (asignarles memoria), iniciar su estado
(¿Qué es eso?) (construirlos), destruirlos, leer y modificar su ESTADO. PERO, POR FAVOR,
no lo olvides, cuando estás escribiendo el programa estás MODELANDO tu solución,
tu programa es un PLAN que DESCRIBE lo que ocurrirá cuando sea ejecutado.

Ejercicio 19
#############
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

Ejercicio 20
################
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
   :linenos:

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
   :linenos:

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
   :linenos:

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
   :linenos:

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
   :linenos:

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

Si analizas un poco más el archivo ``queue.c`` varás que create reserva el espacio
en heap para el objeto y adicionalmente inicializa sus atributos:

.. code-block:: c 
   :linenos:

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

Ejercicio 21
################
Ahora compara el programa anterior con una implementación en C#:

.. code-block:: csharp
   :linenos:

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
   :linenos:

    #ifndef _QUEUE_H
    #define _QUEUE_H

    typedef struct {
        int front;
        int rear;
        double* arr;
    } queue_t;

En C#:

.. code-block:: csharp
   :linenos:

    using System;

    public class Queue{
        
        private int front;
        private int rear;
        private double[] arr;

Mira cómo se crea el objeto y se llaman los métodos:

En C:using System;


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
        this.rear++;using System;


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
    enqueue(q, 6.5);

.. code-block:: csharp
   :linenos:

   Queue q = new Queue(10);
   q.enqueue(6.5);

En la comparación anterior, notas que la implementación en C# no tiene
código para ``destroy``. ¿Recuerdas por qué es esto?

El programa en C# también podríamos escribirlo así:


.. code-block:: csharp
   :linenos:

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

Ejercicio 22
################
En el tiempo de trabajo autónomo que te queda esta semana te pide que
analices de nuevo todo lo que hicimos esta semana, es decir, dale
una segunda lectura.