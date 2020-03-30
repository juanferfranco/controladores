Semana 11
===========

La semana pasada hablamos de los procesos como aquella abstracción que brinda el
sistema operativo para poder ejecutar programas. 

Un proceso puede tener solo un flujo de instrcciones; sin embargo, es usual que tenga
más de un flujo de instrucciones, es decir, que pueda realizar varias tareas a la vez y
por tanto ejecutar concurrentemente varios flujos de instrucciones o hilos.

En `este <https://docs.google.com/presentation/d/1x5Ff276oalMTOKGvMBanpTV2Iw73SIzTYDdUgk74PRA/edit?usp=sharing>`__
presentación vamos a introducir algunos conceptos básicos.

Ejercicio 1
------------
¿Cómo se puede crear un hilo en C#

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class ThreadTest
    {
      static void Main()
      {
        Thread t = new Thread (WriteY);
        t.Start();                     
        for (int i = 0; i < 1000; i++) Console.Write ("1");
      }

      static void WriteY()
      {
        for (int i = 0; i < 1000; i++) Console.Write ("2");
      }
    }

Otra manera:

.. code-block:: csharp
   :lineno-start: 1

   static void Main()
   {
    Thread t = new Thread ( () => Console.WriteLine ("Hello!") );
    t.Start();
   }

* En la forma anterior qué es:

.. code-block:: csharp
   :lineno-start: 1

   () => Console.WriteLine ("Hello!")


Ejercicio 2
------------
Cada hilo tiene su propio stack

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class ThreadTest
    {
        static void Main() 
        {
          new Thread (Go).Start();      // Call Go() on a new thread
          Go();                         // Call Go() on the main thread
        }
         
        static void Go()
        {
          // Declare and use a local variable - 'cycles'
          for (int cycles = 0; cycles < 5; cycles++) Console.WriteLine ("Hola");
        }
    }

* ¿Cuántas veces se imprime la palabra hola?

Ejercicio 3
------------
Los hilos pueden compartir información referenciando el mismo objeto:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class ThreadTest
    {
      bool done;
     
      static void Main()
      {
        ThreadTest tt = new ThreadTest();   // Create a common instance
        new Thread (tt.Go).Start();
        tt.Go();
      }
     
      // Note that Go is now an instance method
      void Go() 
      {
         if (!done) { done = true; Console.WriteLine ("Done"); }
      }
    }

O por medio de miembros estáticos de la clase:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class ThreadTest 
    {
      static bool done;    // Static fields are shared between all threads
     
      static void Main()
      {
        new Thread (Go).Start();
        Go();
      }
     
      static void Go()
      {
        if (!done) { done = true; Console.WriteLine ("Done"); }
      }
    }

* ¿Cuántas veces se imprime Done?

Ejercicio 4
------------

En el código anterior, qué puede pasar si estas dos líneas de código
se intercambian:

.. code-block:: csharp
   :lineno-start: 1

   { done = true; Console.WriteLine ("Done"); }

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class ThreadTest 
    {
      static bool done;    // Static fields are shared between all threads
     
      static void Main()
      {
        new Thread (Go).Start();
        Go();
      }
     
      static void Go()
      {
        if (!done) { 
            Console.WriteLine ("Done");
            done = true;
        }
      }
    }

* ¿Por qué la diferencia?

Ejercicio 5
------------

¿Cómo puedo garantizar que solo un hilo estará en estará
en la siguiente parte del código en un momento dado?

.. code-block:: csharp
   :lineno-start: 1

   if (!done) { 
        Console.WriteLine ("Done");
        done = true;
   }

Se debe colocar un candado al código, de modo que cada hilo
tenga que solicitar el candado. Si el candado está disponible
el hilo entra, si no está disponible el hilo debe esperar:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class ThreadSafe 
    {
      static bool done;
      static readonly object locker = new object();
     
      static void Main()
      {
        new Thread (Go).Start();
        Go();
      }
     
      static void Go()
      {
        lock (locker)
        {
          if (!done) { Console.WriteLine ("Done"); done = true; }
        }
      }
    }

* Note en el ejemplo el modificador `readonly <https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/readonly>`__.
  Si se aplica a un tipo referencia quiere decir que en locker no puedo guardar una referencia a un objeto diferente
  al inicial.

Ejercicio 6
------------
En C# los hilos pueden ejecutarse en `background o foreground <https://docs.microsoft.com/en-us/dotnet/api/system.threading.thread.isbackground?view=netframework-4.8>`__.

Para entender la diferencia entre ambos analicemos el siguiente código:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class Example
    {
        static void Main()
        {
            BackgroundTest longTest = new BackgroundTest(50);
            Thread th = new Thread(new ThreadStart(longTest.RunLoop));
            th.Start();
        }
    }
    
    class BackgroundTest
    {
        int maxIterations;
    
        public BackgroundTest(int maxIterations)
        {
            this.maxIterations = maxIterations;
        }
    
        public void RunLoop()
        {
            for (int i = 0; i < maxIterations; i++) {
                Console.WriteLine("{0} count: {1}", 
                    Thread.CurrentThread.IsBackground ? 
                       "Background Thread" : "Foreground Thread", i);
                Thread.Sleep(250);
            }
            Console.WriteLine("{0} finished counting.", 
                              Thread.CurrentThread.IsBackground ? 
                              "Background Thread" : "Foreground Thread");
        }
    } 

Ahora vamos a comparar qué pasa con este código:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class Example
    {
        static void Main()
        {
            BackgroundTest longTest = new BackgroundTest(50);
            Thread th = new Thread(new ThreadStart(longTest.RunLoop));
            th.IsBackground = true;
            th.Start();
        }
    }
    
    class BackgroundTest
    {
        int maxIterations;
    
        public BackgroundTest(int maxIterations)
        {
            this.maxIterations = maxIterations;
        }
    
        public void RunLoop()
        {
            for (int i = 0; i < maxIterations; i++) {
                Console.WriteLine("{0} count: {1}", 
                    Thread.CurrentThread.IsBackground ? 
                       "Background Thread" : "Foreground Thread", i);
                Thread.Sleep(250);
            }
            Console.WriteLine("{0} finished counting.", 
                              Thread.CurrentThread.IsBackground ? 
                              "Background Thread" : "Foreground Thread");
        }
    } 

* ¿Qué podemos concluir?

Ejercicio 7: RETO
------------------

Explicar qué sucede con el siguiente código:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class Example
    {
        static void Main()
        {
            BackgroundTest shortTest = new BackgroundTest(10);
            Thread foregroundThread = 
                new Thread(new ThreadStart(shortTest.RunLoop));
    
            BackgroundTest longTest = new BackgroundTest(50);
            Thread backgroundThread = 
                new Thread(new ThreadStart(longTest.RunLoop));
            backgroundThread.IsBackground = true;
    
            foregroundThread.Start();
            backgroundThread.Start();
        }
    }
    
    class BackgroundTest
    {
        int maxIterations;
    
        public BackgroundTest(int maxIterations)
        {
            this.maxIterations = maxIterations;
        }
    
        public void RunLoop()
        {
            for (int i = 0; i < maxIterations; i++) {
                Console.WriteLine("{0} count: {1}", 
                    Thread.CurrentThread.IsBackground ? 
                       "Background Thread" : "Foreground Thread", i);
                Thread.Sleep(250);
            }
            Console.WriteLine("{0} finished counting.", 
                              Thread.CurrentThread.IsBackground ? 
                              "Background Thread" : "Foreground Thread");
        }
    }

Ejercicio 8
------------

Consideremos de nuevo el ejercicio 6:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class Example
    {
        static void Main()
        {
            BackgroundTest longTest = new BackgroundTest(50);
            Thread th = new Thread(new ThreadStart(longTest.RunLoop));
            th.IsBackground = true;
            th.Start();
        }
    }
    
    class BackgroundTest
    {
        int maxIterations;
    
        public BackgroundTest(int maxIterations)
        {
            this.maxIterations = maxIterations;
        }
    
        public void RunLoop()
        {
            for (int i = 0; i < maxIterations; i++) {
                Console.WriteLine("{0} count: {1}", 
                    Thread.CurrentThread.IsBackground ? 
                       "Background Thread" : "Foreground Thread", i);
                Thread.Sleep(250);
            }
            Console.WriteLine("{0} finished counting.", 
                              Thread.CurrentThread.IsBackground ? 
                              "Background Thread" : "Foreground Thread");
        }
    }

 * ¿Qué pasa si añadimos la siguiente línea?

 .. code-block:: csharp
   :lineno-start: 1
   
    th.Start();
    th.Join();

* ¿Qué conclusión podemos sacar?

Ejercicio 9
------------

Y si queremos pasarle argumentos a un hilo? datos iniciales?

Tenemos dos maneras:

.. code-block:: csharp
   :lineno-start: 1

    static void Main()
    {
        Thread t = new Thread ( () => Print ("Hello from t!") );
        t.Start();
    }
    
    static void Print (string message) 
    {
        Console.WriteLine (message);
    }

Y esta es la otra:

.. code-block:: csharp
   :lineno-start: 1

    static void Main()
    {
        Thread t = new Thread (Print);
        t.Start ("Hello from t!");
    }
    
    static void Print (object messageObj)
    {
        string message = (string) messageObj;   // We need to cast here
        Console.WriteLine (message);
    }

Noten que en esta última, los argumentos se pasan en Start(), pero es necesario
realizar un cast.

Ejericio 10
------------
Ejecute el siguiente código varias veces:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class Example
    {
        static void Main()
        {

            for (int i = 0; i < 10; i++)
                new Thread (() => Console.Write (i)).Start();
        }
    }

* ¿Qué está pasando?
* ¿Están todos los posibles
  valores de i?

Ahora compare con este otro código:

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class Example
    {
        static void Main()
        {

            for (int i = 0; i < 10; i++)
            {
                int temp = i;
                new Thread (() => Console.Write (temp)).Start();
            }
        }
    }   

* ¿Nota alguna diferencia?
* Tenga en cuenta que el órden de ejecución de los hilos puede variar con cada
  ejecución. Este comportamiento es de esperar; sin embargo, ¿Están todos los posibles
  valores de i?

Ejercicio 11: RETO
--------------------

* ¿Qué puede estar ocurriendo aquí?
* ¿Por qué?

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.Threading;
    
    class Example
    {
        static void Main()
        {

            string text = "t1";
            Thread t1 = new Thread ( () => Console.WriteLine (text) );
             
            text = "t2";
            Thread t2 = new Thread ( () => Console.WriteLine (text) );
             
            t1.Start();
            t2.Start();
        }
    }

¿Cómo podría corregir este programa?


Ejercicio 12: RETO
--------------------

Se requiere realizar una aplicación que permita contar el número de líneas que poseen varios archivos de texto. 
El nombre de los archivos se pasará como argumentos a la aplicación (apliación por consola). Además de mostrar en pantalla 
el número de líneas de cada archivo, la aplicación debe presentar el número de líneas totales (suma de todas las líneas de los archivos pasados). 
Por ejemplo: 

.. code-block:: csharp
   :lineno-start: 1

    cuentalineas.exe archv1 archv2 archv3 
    
Deberá generar una salida como la siguiente (donde se asume que archv1 tiene 122 líneas, archv2 212 y archv3 100):

.. code-block:: csharp
   :lineno-start: 1

    archv1: 122 lineas
    archv2: 212 lineas
    archv1: 100 lineas
    total: 434 lineas
 
La aplicación debe crear un hilo por cada archivo para permitir concurrencia en el conteo de las líneas de todos los archivos.
Es importante que se presenten los resultados en el mismo orden en el que fueron especificados (como en el ejemplo).

Ejercicio 13: RETO
--------------------
Se tiene un archivo de entrada que posee por línea las siguientes cadenas de caracteres separadas por espacios:

.. code-block:: csharp
   :lineno-start: 1

    nombre ocupación edad


Nombre y ocupación son cadenas de caracteres que representan texto mientras que edad representa valores numéricos.
Se tendrán máximo 100 líneas y 20 caracteres máximo por cadena.

Cree un programa llamado prog que lea el archivo de entrada, organice la información en una estructura
de datos (usted decide cuál y cómo), IMPRIMA en pantalla el contenido de la estructura de datos. 

Luego cree 2 hilos para procesar de diferente manera la información
y finalmente imprima el contenido de los archivos de salida.

El Hilo 1 escribe en el archivo de salida 1 los registros del archivo de entrada, pero en orden inverso, es decir,
primero el último y de último el primero.

El Hilo 2 escribe en el archivo de salida 2 los registros ordenados por ocupación en orden alfabético.

Hilo 1 e Hilo 2 deben lanzarse a la vez. Es decir, queremos ejecución concurrente.
Una vez hilo 1 e hilo 2 finalicen, el hilo principal debe mostrar en pantalla el resultado de los archivos de salida.

Para ejecutar el programa:

.. code-block:: csharp
   :lineno-start: 1

    prog In Out1 Out2

* prog es el nombre del ejecutable
* In especifica el nombre del archivo de entrada
* Out1 y Out2 especifican el nombre de los los archivos de salida 1 y 2 respectivamente
