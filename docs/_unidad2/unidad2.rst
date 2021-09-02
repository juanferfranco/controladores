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
^^^^^^^^^^^^^

.. note:: Se publicará en la semana de evaluación.


