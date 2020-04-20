Semana 13
===========
Esta semana realizaremos dos actividades:

1. La evaluación sumativa número 5.
2. Vamos a discutir cómo hacen un computador para almacenar permanentemente
   información, cómo la organiza y cómo la usa.

Evaluación 5: RETO
-------------------
Para la evaluación sumativa número 5 considere:

Consideraciones
^^^^^^^^^^^^^^^^^^^^

* Vamos a destinar todas las horas de trabajo autónomo de esta semana: 8 horas.
* Tenemos un reto adicional con las horas de trabajo autónomo y es que debemos
  repartirlas entre el lunes y el viernes.

La evaluación se trata de un video que debe
tener estas 10 secciones. En la edición del haga un encabezado que marque
cada sesión.

* Explicar qué son los circuitos lógicos combinacionales y mostrar ejemplos
  de estos circuitos en la implementación del computador Hack.
* Explicar qué son los circuitos lógicos secuenciales y mostrar ejemplos de
  estos circuitos en la implementación del computador Hack.
* Explicar el concepto de entrada/salida mapeada a memoria y mostrar este
  concepto cómo se implementó en el computador Hack.
* Inventar un programa simple para el computador Hack que tenga variables,
  estructuras de control if y ciclos y operaciones de entrada salida. Explicar
  el programa y mostrarlo funcionando en el simulador.
* Mostrar cómo se convierte este programa a código de máquina y explique en
  detalle con una instrucción tipo A y con una tipo C.
* Tome una parte de las instrucciones de máquina del programa anterior, pero 
  que tenga instrucciones tipo A e instrucciones tipo C aritméticas y de salto. 
  Haga un diagrama del computador y muestre cómo se ejecutan las instrucciones anteriores.
* Queremos implementar un máquina virtual en nuestro computador Hack. Cómo sería
  esa máquina, cómo podría funcionar, qué caracterísiticas tendría.
* Explicar en qué consisten estos tres conceptos: procesos, memoria virtual e hilos.
* Explicar qué son las condiciones de carrera y cómo se podrían evitar.
* Explicar el concepto de jerarquía de memoria y por qué razón es deseable hacer
  programas que optimicen su uso.

Entrega
^^^^^^^^^^
Para la entraga de la evaluación suba un archivo .pdf a
`este <https://www.dropbox.com/request/YrV7kp35WzSsvLTBp5du>`__ enlace.
El archivo debe tener:

* Su nombre.
* Un índice que muestre cada sesión pedida en qué minuto y qué segundo del video
  se encuentra.
* Un enlace al video.

El PLAZO MÁXIMO es el VIERNES 24 de abril a las 6 P.M.

Sesión 1: Persistencia
------------------------
En esta sesión vamos a analizar cómo es posible que un computador almacene información
de manera permanente, cómo la organiza y recupera después y cómo accedemos a esta
información desde un lenguaje de programación.

Comenzaremos analizando `este <https://docs.google.com/presentation/d/1L_0NXN6R4mJpqFBmNrnzQcLw5wYQYznMz6TRb-F66B4/edit?usp=sharing>`__
material.

Ejercicio 1 
^^^^^^^^^^^^
¿Qué es un path realativo y un path absoluto en un sistema de archivos?

Este reto busca responder esta pregunta. Se trata entonces de crear un programa
tipo consola que reciba como parámetro el path del archivo. El programa
deberá abrir el archivo e imprimir en la pantalla su contenido.

Considere los siguiente:

* Pase el archivo con un path relativo.
* Pase el archivo con un path absoluto.

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.IO;

    namespace PathReadFile
    {
        class Program
        {
            static void Main(string[] args)
            {
                if(args.Length == 1)
                {
                    try
                    {
                        var lines = File.ReadAllLines(args[0]);
                        foreach (var line in lines)
                        {
                            Console.WriteLine(line);
                        }
                    }
                    catch (Exception e) {
                        Console.WriteLine(e.Message);
                    }
                }
            }
        }
    }

Ejercicio 2
^^^^^^^^^^^^
El siguiente programa muestra cómo leer y escribir archivos.
Para realizar la prueba cree el archivo file.txt, con alguna líneas
de texto, y guárdelo en el mismo directorio donde se encuentra el
ejecutable del programa.

Ejecute el programa y observe el contenido de outFile.txt

.. code-block:: csharp
   :lineno-start: 1

    using System;
    using System.IO;

    namespace PathReadFile
    {
        class Program
        {
            static void Main(string[] args)
            {
                int counter = 0;
                string line;

                // Read the file and display it line by line.  
                StreamReader file = new StreamReader(@".\file.txt");
                StreamWriter Outfile =  new StreamWriter(@".\outFile.txt");

                while ((line = file.ReadLine()) != null)
                {
                    Console.WriteLine(line);
                    Outfile.WriteLine(line);
                    counter++;
                }
                file.Close();
                //Outfile.Close();
                Console.WriteLine("There were {0} lines.", counter);

            }
        }
    }

Ahora repita el ejercicio pero esta vez descomente la línea:

.. code-block:: csharp
   :lineno-start: 1

  //Outfile.Close();

* ¿Cómo se explica este comportamiento?

Ejercicio 3
^^^^^^^^^^^^
Analicemos el siguiente código

.. code-block:: csharp
   :lineno-start: 1

    using System.IO;

    namespace fileTests
    {
        class WriteTextFile
        {
            static void Main()
            {

                // Example #1: Write an array of strings to a file.
                string[] lines = { "First line", "Second line", "Third line" };
                File.WriteAllLines(@".\WriteLines.txt", lines);

                // Example #2: Write one string to a text file.
                string text = "A class is the most powerful data type in C#. Like a structure, " +
                               "a class defines the data and behavior of the data type. ";
                File.WriteAllText(@".\WriteText.txt", text);

                using (StreamWriter file =  new StreamWriter(@".\WriteLines2.txt"))
                {
                    foreach (string line in lines)
                    {
                        // If the line doesn't contain the word 'Second', write the line to the file.
                        if (!line.Contains("Second"))
                        {
                            file.WriteLine(line);
                        }
                    }
                }
                // Example #4: Append new text to an existing file.
                // The using statement automatically flushes AND CLOSES the stream and calls 
                // IDisposable.Dispose on the stream object.
                using (StreamWriter file = new StreamWriter(@".\WriteLines2.txt", true))
                {
                    file.WriteLine("Fourth line");
                }
            }
        }
    }

* ¿Nota algo especial en el programa?

Ejercicio 4:RETO
^^^^^^^^^^^^^^^^^^^
Usando la palabra reservada using, escriba de nuevo el código del ejercicio 3


Sesión 2
---------
Vamos a realizar algunos ejercicios relacionados con la persistencia.
