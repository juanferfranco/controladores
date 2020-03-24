Semana 10
===========

Evaluación sumativa 3
-----------------------
Para la evaluación sumativa 3 tendremos en cuenta las siguientes consideraciones:

* Plazo de entrega, viernes *27 de marzo a las 12 del MEDIO DÍA.*
* Cree una carpeta. Incluya en esa carpeta otra con el proyecto y un archivo .pdf con:

    * Una explicación de qué herramientas utilizó para hacer su proyecto, por ejemplo,
      visual studio windows forms o consola.
    * EL ENLACE, solo el ENLACE a un video que tenga las siguientes secciones:
        
        * Sección 1: mostrar cómo se compila el proyecto.
        * Sección 2: mostrar el proyecto corriendo.
        * Sección 3: mostrar cómo lo probó, los archivos de entrada en asm, los archivos
          de salida en .hack y MUY MUY IMPORTANTE cómo está verificando que cada el .hack
          generado está correcto.
        * Sección 4: explicación detallada de cómo funciona el código, indicando cómo
          se inicializa, qué hace en la primera pasada, qué hace en la segunda pasada.
          MUY MUY IMPORTANTE esta explicación la debe mostrar utilizando el debugger. 
* Comprima la carpeta anterior con SOLO usando .ZIP, no RAR, no 7Z, SOLO .ZIP. NO
  CUMPLIR CON ESTO REBAJARÁ EN UNA UNIDAD AUTOMÁTICAMENTE LA NOTA FINAL.
* El video debe tener buena calidad de audio para poder escuchar claramente su
  sustentación.
* Suba la sustentación aquí: https://www.dropbox.com/request/pfvWeDieylHCP1D528uB


Criterios de evaluación
^^^^^^^^^^^^^^^^^^^^^^^^

Nota_Final = Funcionamiento*sustentación

Donde funcionamiento será una nota de 0 a 5 y sustentación un factor de 0 a 1. ESTO
quiere decir que el funcionamiento puede ser 5, pero si la sustentación es 0, la nota
final final 0.

Para la sustentación:

* 1: incluye todas las sesiones del video.
* 0.6: incluye las sesiones 3 y 4 con explicaciones correctas, precisas y detalladas.
* 0.4: Las sesiones 3 o 4 presentan algunos errores conceptuales leves.
* 0: las sesiones 3 o 4 presentan errores conceptuales graves.


Trabajo para esta semana
-------------------------

La semana pasada introducimos dos conceptos importantes: compiladores y máquinas virtuales.

Los compiladores permiten transformar código en alto nivel a lenguaje ensamblador que luego
será transformado a lenguaje de máquina. Dichas instrucciones en lenguaje de máquina serán
ejecutadas directamente por la CPU. En contraste las máquinas virtuales emularán el comportamiento
de una CPU e interpretarán nuestro código que será ensamblado a un lenguaje ensamblador intermedio
que podrá ejecutar cualquier CPU que tenga portada la máquina virtual.

Esta semana vamos a discutir algunos conceptos importantes relacionados con los sistemas
operativos. Los sistemas operativos ofrecerán servicios a los programas que permitirán:

* Darle acceso a los recursos de procesamiento: CPU, mediante procesos.
* Realizar varias tareas a la vez: hilos.
* Acceder a la memoria RAM para crear variables: Memoria virtual.
* Acceder información almacenada de manera permanente: sistemas de archivos.
* Acceder a dispositivos para obtener y producir información del mundo
  exterior: interfaces de entrada/salida 

Esta semana vamos a discutir dos conceptos: Procesos y Memoria Virtual.

