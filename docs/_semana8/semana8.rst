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
