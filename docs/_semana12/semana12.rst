Semana 12
===========

Evaluación 4
-------------
La evaluación consiste en entregar los RETOS 12 y 13 de la semana 11.
SOLO EN VERSIÓN CONSOLA ojo!

Tenga presente las siguientes consideraciones

* Plazo de entrega, viernes 17 de abril a las 12 del MEDIO DÍA.
* Cree una carpeta. Incluya en esa carpeta otras CARPETAS, una para cada reto
  y un archivo .pdf con:

    * EL ENLACE, solo el ENLACE a un video que tenga las siguientes secciones:
    
        * Sección 1: mostrar cómo se compila el proyecto.
        * Sección 2: mostrar el proyecto corriendo. Mostrar claramente cómo se
          lanza el ejecutable y cómo está pasando los archivos
        * Sección 3: mostrar cómo probó cada programa,
          mostrar claramente el contenido de los archivos de entrada y salida.
        * Sección 4: explicación detallada de cómo funciona el código. OJO NO QUE PARTES
          TIENE, se trata de explicar cómo funciona el código y mostrar que efectivamente
          domina el código escrito.

* Comprima la carpeta anterior con SOLO usando .ZIP, no RAR, no 7Z, SOLO .ZIP. NO
  CUMPLIR CON ESTO REBAJARÁ EN UNA UNIDAD AUTOMÁTICAMENTE LA NOTA FINAL.
* El video debe tener buena calidad de audio para poder escuchar claramente su
  sustentación.
* Suba la sustentación `aquí <https://www.dropbox.com/request/Z1wEOWlfUjjEOeLx4CbY>`__

Criterios de evaluación
^^^^^^^^^^^^^^^^^^^^^^^^

Nota_Final = Funcionamiento*sustentación

Donde funcionamiento será una nota de 0 a 5 y sustentación un factor de 0 a 1. ESTO
quiere decir que el funcionamiento puede ser 5, pero si la sustentación es 0, la nota
final final 0.

Para la sustentación:

* 1: incluye todas las sesiones del video.
* 0.6: Las sesiones 3 o 4 presentan algunos errores conceptuales leves.
* 0.4: Las sesiones 3 o 4 presentan errores conceptuales o las explicaciones son muy pobres.
* 0: las sesiones 3 o 4 presentan errores conceptuales graves o no hay explicación.


Sesión 1
---------
En esta sesión vamos a introducir los conceptos de sincronización y comunicación entre hilos.

Ejercicio 1
^^^^^^^^^^^^
Considere el siguiente código:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class HelloWorld {
    
      static int counter = 0;
      const int ITERATIONS = 100;
    
      static void Main() {
          
          Thread t = new Thread(Code);
          t.Start();
          
          Code();
          t.Join();
          
          Console.WriteLine("Counter: {0}",counter);
          
          
      }
      
      static void Code(){
          
          int temporal = 0;
          
          for(int i= 0; i < ITERATIONS; i++){
            temporal = counter;
            temporal++;
            counter = temporal;
          }
      }
    }


* Explique el funcionamiento detallado.
* Corra el programa varias veces. ¿El resultado es el esperado?
* Aumente gradualmente el valor de ITERATIONS en pasos de un órden
  de magnitud. Corra varias veces el programa. El resultado es el esperado?
* Explique qué puede estar pasando.

Ejercicio 2
^^^^^^^^^^^^
¿Cómo podemos solucionar el problema que se nos presenta en el ejercicio 1?

Podemos recurrir al ejercicio 5 de la semana 11. A esto se le conoce como
un semáforo de exclusión mutua (?)

Considere el siguiente código:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class HelloWorld {
    
      static int counter = 0;
      const int ITERATIONS = 1000000;
      static readonly object locker = new object();
    
      static void Main() {
          
          Thread t = new Thread(Code);
          t.Start();
          
          Code();
          t.Join();
          
          Console.WriteLine("Counter: {0}",counter);
          
          
      }
      
      static void Code(){
          
          int temporal = 0;
          
          for(int i= 0; i < ITERATIONS; i++){
           
            lock(locker){
                temporal = counter;
                temporal++;
                counter = temporal;
            }
          }
      }
    }

* ¿Cómo funciona el código anterior?
* ¿Qué pasa si el semáforo se coloca aquí?

.. code-block:: csharp
   :lineno-start: 1

      static void Code(){
          
          int temporal = 0;
          lock(locker){   
            for(int i= 0; i < ITERATIONS; i++){
              temporal = counter;
              temporal++;
              counter = temporal;
            }
          }
      }

* ¿El código funciona?
* Explique cómo funciona

Ejercicio 3
^^^^^^^^^^^^
En la literatura técnica de las bibliotecas de diferentes
lenguajes de programación se observa este término: Thread Safety.
El término indica si la biblioteca o el procedimiento en cuestión
es o no Thread Safe. Pero, ¿Qué quiere decir?


Se dice que un programa o un método es Thead-safe si al ejecutarse
no se presentan comportamientos indeterminados (ejercicio 1) en
un escenario con múltiples hilos. En otras palabras, si nos dicen
que un método es Thread-Safe quiere decir que lo podemos usar sin
problema en varios hilos.

* El método Code() del ejercicio 1 es Thread-safe?
* el método Code() del ejercicio 2 es Thread-safe?

Ejercicio 4:
^^^^^^^^^^^^^
Uno de los programas que más usamos en IDED es Unity. En Unity podemos
construir programas con varios hilos, además del hilo principal (?);
sin embargo, es usual que en el proceso encontremos errores. Al
buscar la causa de esos errores veremos que en la documentación oficial
de Unity encontraremos cosas como estas:

* El API de Unity no es tread-safe
* El API de Unity, en su mayoría solo puede ser usada en el hilos principal.

¿Entonces qué hacemos si queremos usar hilos?

PERO ANTES:

* ¿Para qué podríamos necesitar hilos en Unity?

Ejercicio 5: RETO
^^^^^^^^^^^^^^^^^^
Este ejercicio es muy importante: por favor repita los ejercicios 1 al 4.
Verifique sus notas, analice el código, experimente.
