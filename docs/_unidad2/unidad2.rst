Unidad 2. Del código fuente al código ejecutable 
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

Te voy a pedir que le des una mirada a  `este video <https://youtu.be/ZPpo-uViT_o>`__ para 
que te hagas una idea de qué es Linux.

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

Si lo anterior no te funciona, prueba con una `máquina virtual <https://youtu.be/tNUgLsXD7xg>`__ o con WSL2.
Ten presente que las versiones de los videos pueden no coincidir con las versiones actuales.

Ejercicio 2: instala las herramientas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Una vez tengas Linux funcionando debes instalar una cuentas herramientas:

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

Ten presente que en los comentarios de la guía podrás consultar la solución a las preguntas; 
sin embargo, trata de pensar primero en la respuesta y luego compara con la explicación.

Ejercicio 5: lenguaje de programación C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Este será uno de los ejercicios más largos de la unidad porque vamos a introducir 
el lenguaje de programación con el cual estudiaremos todos los conceptos del curso: ``C``.

.. toctree::
    :maxdepth: 3

    Introducción a C <./introC>

Ejercicio 6: herramientas
^^^^^^^^^^^^^^^^^^^^^^^^^^

En este ejercicio comprenderás en detalle los pasos necesarios para transformar un programa en C a 
lenguaje de máquina.

.. toctree::
  :maxdepth: 3

  Herramientas <./tools>

Ejercicio 7: máquinas virtuales
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En este ejercicio aprenderás acerca de las máquinas virtuales.  

.. toctree::
  :maxdepth: 3

  Máquinas virtuales <./VM>


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
