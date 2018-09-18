Semana 10
===========
El reto de esta semana será construir una herramienta que permita generar código de máquina a partir de un 
archivo con código ensamblador para la CPU hack.  

Objetivos
----------
1. Repasar (en casa) un lenguaje de programación mediante la elaboración de un proyecto relacionado con el curso.
2. Realizar una herramienta que genere código de máquina a partir de código en lenguaje ensamblador.
3. Desarrollar habilidades en la detección y corrección de errores.

Material
---------
El material para esta semana corresponde al proyecto 6: Ensamblador.
    
    * `Presentación <https://docs.wixstatic.com/ugd/44046b_399d71e72e3b4cc39fc1e336196077b7.pdf>`__
    * `Proyecto <https://www.nand2tetris.org/project06>`__
    * `Capítulo del libro <https://docs.wixstatic.com/ugd/44046b_89a8e226476741a3b7c5204575b8a0b2.pdf>`__

Adicional a este material, para quien desee realizar la aplicación en python, 
`hay una guía <https://drive.google.com/open?id=1MGmSod2WP0FzB2xOowGVeGhiaMjNPnmYatrmWfMC_X4>`__ que ilustra cómo instalar 
las herramientas, cómo depurar aplicaciones y algunas facilidades del lenguaje para realizar el proyecto.

También se sugiere utilizar processing (java) para realizar la herramienta.

Consideraciones
-----------------
Algunos asuntos a tener en cuenta a la hora de realizar el proyecto:

    * El objetivo del proyecto se resume en la siguiente figura:

    .. image:: ../_static/proyecto6.jpeg
       :scale: 60 %

    * En el proyecto tenemos dos tipos de programas .asm para verificar la herramienta construida. Un tipo contiene símbolos y 
      el otro tipo no. El archivo sin símbolos puede ensamblarse en una sola pasada. El archivo con 
      símbolos requiere dos pasadas para construir la tabla de símbolos y así poder generar el código.
    * Los siguientes símbolos están predefinidos y por tanto, la tabla de símbolos deberá iniciarse con estos valores:

        ======== =======
        Símbolo  valor
        ======== =======
        R0       0
        R1       1
        R2       2
        ...
        R15      15
        SP       0
        LCL      1
        ARG      2
        THIS     3
        THAT     4
        SCREEN   16384
        KBD      24576
        ======== =======
    * Los lables están asociados a direcciones de la memoria ROM.
    * Las variables están asociadas a direcciones en la memoria RAM. Dichas direcciones serán asignadas por la herramienta 
      desde la posicion 16.
    * Un programa en lenguaje ensamblador puede tener: espacios en blanco, líneas vacías, líneas identadas, líneas con
      comentarios, comentarios, instrucciones tipo A y tipo C, símbolos que pueden ser variables o labels a posiciones en ROM.
    * Para la traducción de las instrucciones tipo A:

    .. image:: ../_static/tipoA.jpeg
       :scale: 60 %

    * Para las instrucciones tipo C, por ejemplo esta:

    .. image:: ../_static/tipoC.jpeg
       :scale: 60 %
    
    * Escribir los 3 primeros unos:

    .. image:: ../_static/tipoC1.jpeg
       :scale: 60 %
    
    * Generar el código ginario correspondiente a la operación

    .. image:: ../_static/tipoC2.jpeg
       :scale: 60 %
    
    * Generar el código binario correspondiente al destino
    
    .. image:: ../_static/tipoC3.jpeg
       :scale: 60 %
    
    * Generar el código binario correspondiente al salto:
    
    .. image:: ../_static/tipoC4.jpeg  
       :scale: 60 %  
         
    * En general, para cada instrucción se propone: 
        * leer la instrucción y dividirla en los campos que la componen.
        * Si la instrucción es tipo A convertir el valor decimal a binario.
        * Si la instrucción es tipo C, para cada campo en la instrucción, generar el código binario correspondiente.
        * Ajustar el código binario correspondiete a una instrucción de 16 bits.
        * Escribir la instrucción de 16 bits en el archivo de salida correspondiente.
    
    * Cuando el código tiene símbolos, el primer paso es iniciar la tabla de símbolos.

    .. image:: ../_static/simbols.jpeg  
       :scale: 70 %  

    * En la primer pasada se ingresan a la tabla de símbolos los labels. Note que las etiquetas corresponden a la dirección 
      de memoria ROM donde quederá almacenada la instrucción. Observe que los comentarios no se cuentan porque no son 
      instrucciones y por tanto no ocupan posiciones de memoria ROM.

    .. image:: ../_static/simbolsLabels.jpeg
       :scale: 70%
    
    * En la segunda pasada se ingresan a la tabla de símbolos las variables.En la segunda pasada, lo que no es label es variable.
      Por tanto, al encontrar un símbolo primero se busca en la tabla de símbolos. En caso de no encontrarlo, se crea el símbolo 
      y se le asigna una dirección única en RAM (por que es una variable) desde la dirección 16. 
    
    .. image:: ../_static/simbolsVars.jpeg
       :scale: 70%

El algoritmo para el generado de código será:

    * Inicialización:
        
        * Construir la tabla de símbolos
        * Adicionar los símbolos predefinidos
    
    * Primera pasada:
        
        * Leer el programa línea por línea.
        * Para cada línea de la forma (XXX) adicionar a la tabla de símbolos la pareja XXX, address. Donde address es la dirección 
          de la instrucción que se encuentra luego de (XXX).
    
    * Segunda pasada:
        
        * Inicializar n = 16
        * Leer el programa línea por línea.
        * Si la instrucción es del tipo @simbolo, leer la tabla de símbolos.
            
            * Si el símbolo está, traducir la instrucción.
            * Si el símbolo no está, adicionar a la tabla de símbolos la pareja símolo, n
            * Traducir
            * Hacer n++.
    
        * Si la instrucción es tipo C, realizar la traducción
        * Escribir la instrucción traducida al archivo de salida.
