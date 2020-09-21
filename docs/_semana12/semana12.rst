Semana 12: Unidad 3
=====================

Esta semana vamos a terminar la unidad 3. 

Ya sabemos cuáles son los pasos necesarios para ir desde
un lenguaje como C y C++ a código de máquina; sin embargo, nos falta
una última estación en este recorrido. ¿Qué pasa con lenguajes como C#?

Para resolver esta pregunta vamos a tener que analizar un poco más
qué es un compilador y qué es un intérprete.

Actividades
-------------

Actividad 17
^^^^^^^^^^^^^^
* Fecha: septiembre 22 de 2020
* Descripción: unidad 3, análisis de los ejercicios
* Recursos: ingresa a Teams
* Duración de la actividad: 1:40 minutos
* Forma de trabajo: individual

Actividad 18
^^^^^^^^^^^^^^^^
* Fecha: septiembre 22 a septiembre 24 de 2020 
* Descripción: realizar los ejercicios propuestos
* Recursos: actividad de trabajo autónomo
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

Ejercicio 1
############
En este ejercicio vamos a investigar un poco más sobre algunos conceptos
de los lenguajes de programación. En particular analizaremos qué son
las implementaciones interpretadas y qué son las implementaciones compiladas.
Nota por favor que no te dije lenguajes interpretados o compilados. Al final
de los ejercicios que te propongo tu mismo podrás explicar la diferencia.

En ejercicios pasados discutimos las fases para transformar un
programa del código fuente a lenguaje de máquina.¿ Lo recuerdas?

* Iniciamos con el programa.
* Luego hacemos un análisis léxico, con el Tokenizer, para generar los tokens.
* Los tokens son unidades indivisibles compuestas por un tipo y un valor.
  Los tokens nos permiten identificar las palabras que componen nuestro programa.
* Ahora hacemos un análisis semántico, utilizando un Parser. Esto nos permiten
  reconocer si estamos combinando correctamente las palabras en el programa
  realizado.
* El Parser genera, si el programa es válido, una representación del programa
  conocida como AST.

Es precisamente este AST el que pasamos a un intérprete o a un compilador. El
intérprete ejecutará el código. El compilador convertirá el AST a otro lenguaje,
que posiblemente será transformado de nuevo o interpretado.

Por ejemplo, en el caso de C, luego de generar el AST, utilizamos un generador
de código y producimos lenguaje ensamblador. Luego este lenguaje ensamblador
lo convertimos en lenguaje de máquina. Finalmente, el lenguaje de máquina es
INTERPRETADO por la CPU.

Hay dos tipos de intérpretes que se diferencian en el formato del programa
que interpretan. En ese sentido el programa puede estar representado como un AST
o como Bytecodes. Los intérpretes que utilizan el primer formato se conocen
como intérpretes recursivos y los segundos como Máquinas Virtuales (VM). En el
caso de los segundos, la representación será muy parecida a un programa en lenguaje
ensamblador, como el de una CPU real, y por tanto el nombre de máquinas virtuales.

En el caso de los compiladores tenemos tres tipos: 

* Ahead-of-time (AOT): todo el código se traduce a un nuevo lenguaje antes de ser
  ejecutado. Como en el caso de C y C++. Sin embargo, es interesante anotar, 
  por ejemplo, que C++ se comparta como un interprete a la hora de optimizar el código.
* Just-in-time (JIT): el código se genera durante la ejecución del programa.
* AST-transformer o también conocidos como transpilers. Aquí la idea es realizar
  una transformación de un tipo de AST a otro, para generar, por ejemplo, de un
  lenguaje de programación a otro.


Ejercicio 2
############
Profundicemos un poco más en los intérpretes.

Los AST interpreters: ejecutan el programa directamente desde la representación AST,
es decir, producen el resultado modelado con el lenguaje de programación directamente,
en tiempo de ejecución.

Realiza el siguiente ejercicio utilizando la herramienta `AST-explorer <https://astexplorer.net/>`__:

* Selecciona javacript.
* Escribe el siguiente código
  
  .. code-block:: javascript
     :linenos:

     a = 5;
     b = a*2 + 10;

* Analiza el AST generado. Verás que la herramienta te identifica expresiones y cada expresión la
  organiza como un árbol identificando el lado izquierdo y el lado derecho.

¿Puedes pintar árboles para los dos expresiones anteriores?


Ejercicio 3
############
Profundicemos un poco más en los intérpretes.

Los bytecodes interpreters no parten de una representación AST en forma de árbol, sino
que parten de un arreglo de bytecodes. Por tanto, necesitarán un paso más en tiempo
de compilación:

* Iniciamos con el programa.
* Análisis léxico --> genera tokens
* Análisis semántico --> genera el AST.
* Bytecode emitter --> Generar bytecodes

Ahora si, en tiempo de ejecución se ejecutará el programa representado como un
arreglo de bytecodes.

¿Para qué hacemos este paso extra? Se hace para optimizar el almacenamiento del
programa en comparación con la representación AST. También será más fácil
de recorrer el programa y se tendrá un control más granular de la ejecución.

Recuerda que a este tipo de intérprete lo llamamos también virtual machine. Usualmente,
estas virtual machines son de dos tipos: stack-based y register-based.

¿Recuerdas el computador Hack? si consideramos la CPU implementada como un intérprete
de las instrucciones Hack, podríamos decir que la CPU es una virtual machine register-based.

¿Cómo serán las VM stack-based? Imagina el stack, como un pila de platos.
Estas VM apilan (stack) los operandos y luego aplican las operaciones. Por tanto, 
los resultados siempre quedan en el tope de la pila. Entonces, para realizar la operación
``5+6`` la VM colocará en la pila el 5, luego el 6, y finalmente realizará la operación suma.
Como resultado, los operandos 5 y 6 serán retirados de la pila y quedará el resultado 11
en la parte superior de esta.

Realiza el siguiente ejercicio:

* Crea un programa Test.java:

  .. code-block:: java
     :linenos:

        class Test{

            public static void main(String[] args){
                int x = 5;
                System.out.println(x+2-1);
            }
        }

* Compila el programa así: ``javac Test.java``. Verás que se genera en el directorio un
  archivo Test.class

* Ahora ejecuta ``hexdump -C Test.class``. El resultado será el bytecode
  
  .. code-block:: java  

        00000000  ca fe ba be 00 00 00 34  00 1b 0a 00 05 00 0e 09  |.......4........|
        00000010  00 0f 00 10 0a 00 11 00  12 07 00 13 07 00 14 01  |................|
        00000020  00 06 3c 69 6e 69 74 3e  01 00 03 28 29 56 01 00  |..<init>...()V..|
        00000030  04 43 6f 64 65 01 00 0f  4c 69 6e 65 4e 75 6d 62  |.Code...LineNumb|
        00000040  65 72 54 61 62 6c 65 01  00 04 6d 61 69 6e 01 00  |erTable...main..|
        00000050  16 28 5b 4c 6a 61 76 61  2f 6c 61 6e 67 2f 53 74  |.([Ljava/lang/St|
        00000060  72 69 6e 67 3b 29 56 01  00 0a 53 6f 75 72 63 65  |ring;)V...Source|
        00000070  46 69 6c 65 01 00 09 54  65 73 74 2e 6a 61 76 61  |File...Test.java|
        00000080  0c 00 06 00 07 07 00 15  0c 00 16 00 17 07 00 18  |................|
        00000090  0c 00 19 00 1a 01 00 04  54 65 73 74 01 00 10 6a  |........Test...j|
        000000a0  61 76 61 2f 6c 61 6e 67  2f 4f 62 6a 65 63 74 01  |ava/lang/Object.|
        000000b0  00 10 6a 61 76 61 2f 6c  61 6e 67 2f 53 79 73 74  |..java/lang/Syst|
        000000c0  65 6d 01 00 03 6f 75 74  01 00 15 4c 6a 61 76 61  |em...out...Ljava|
        000000d0  2f 69 6f 2f 50 72 69 6e  74 53 74 72 65 61 6d 3b  |/io/PrintStream;|
        000000e0  01 00 13 6a 61 76 61 2f  69 6f 2f 50 72 69 6e 74  |...java/io/Print|
        000000f0  53 74 72 65 61 6d 01 00  07 70 72 69 6e 74 6c 6e  |Stream...println|
        00000100  01 00 04 28 49 29 56 00  20 00 04 00 05 00 00 00  |...(I)V. .......|
        00000110  00 00 02 00 00 00 06 00  07 00 01 00 08 00 00 00  |................|
        00000120  1d 00 01 00 01 00 00 00  05 2a b7 00 01 b1 00 00  |.........*......|
        00000130  00 01 00 09 00 00 00 06  00 01 00 00 00 01 00 09  |................|
        00000140  00 0a 00 0b 00 01 00 08  00 00 00 2e 00 03 00 02  |................|
        00000150  00 00 00 0e 08 3c b2 00  02 1b 05 60 04 64 b6 00  |.....<.....`.d..|
        00000160  03 b1 00 00 00 01 00 09  00 00 00 0e 00 03 00 00  |................|
        00000170  00 04 00 02 00 05 00 0d  00 06 00 01 00 0c 00 00  |................|
        00000180  00 02 00 0d                                       |....|
        00000184

* Para ver una representación simbólica de este bytecode escribe ``javap -c Test.class``:

  .. code-block:: java 

        Compiled from "Test.java"
        class Test {
        Test();
            Code:
            0: aload_0
            1: invokespecial #1                  // Method java/lang/Object."<init>":()V
            4: return

        public static void main(java.lang.String[]);
            Code:
            0: iconst_5
            1: istore_1
            2: getstatic     #2                  // Field java/lang/System.out:Ljava/io/PrintStream;
            5: iload_1
            6: iconst_2
            7: iadd
            8: iconst_1
            9: isub
            10: invokevirtual #3                  // Method java/io/PrintStream.println:(I)V
            13: return
        }

* Observa el código en el método main: ``iconst_5`` coloca un 5 en el stack, ``istore_1`` almacena el valor
  en x. Esto corresponde a la operación ``x = 5``. Ahora mira cómo se resulte ``x+2-1``. Primero
  se coloca en el stack el valor de x con ``iload_1``, luego se coloca el 2 ``iconst_2``, se hace
  la suma ``iadd`` dejando el resultado en el stack. Luego se coloca en el stack el 1 con ``iconst_1``
  y finalmente se realiza la resta ``isub``.

Ejercicio 4
############
Continuado con el tema del ejercicio anterior.

* Abre la aplicación `compiler explorer <https://godbolt.org/>`__.
* Selecciona python
* Ingresa el programa:

  .. code-block:: python
     :linenos:

     def main():
        x = 5;
        print(x+2-1)

* Observa la salida al lado derecho:

    .. code-block:: python
       :linenos:

            1           0 LOAD_CONST               0 (<code object main at 0x5653b7cb2980, file "example.py", line 1>)
                        2 LOAD_CONST               1 ('main')
                        4 MAKE_FUNCTION            0
                        6 STORE_NAME               0 (main)
                        8 LOAD_CONST               2 (None)
                        10 RETURN_VALUE

            Disassembly of <code object main at 0x5653b7cb2980, file "example.py", line 1>:
            2           0 LOAD_CONST               1 (5)
                        2 STORE_FAST               0 (x)

            3           4 LOAD_GLOBAL              0 (print)
                        6 LOAD_FAST                0 (x)
                        8 LOAD_CONST               2 (2)
                        10 BINARY_ADD
                        12 LOAD_CONST               3 (1)
                        14 BINARY_SUBTRACT
                        16 CALL_FUNCTION            1
                        18 POP_TOP
                        20 LOAD_CONST               0 (None)
                        22 RETURN_VALUE

* ¿Qué tipo de VM será el intérprete de python?


Ejercicio 5
############
Ahora profundicemos un poco más en los compiladores.

Los AOT (Ahead-of-time) compilers. Ahead-of-time quiere decir, antes de la
ejecución, es decir, estos compiladores traducen completamente el código
fuente antes de ser ejecutados. Recuerda, por ejemplo, C o C++. Una vez el código
de máquina es generado, este es interpretado por la CPU. 

Los siguientes pasos permiten generar, en tiempo de compilación,
código de máquina:

* Iniciamos con el programa.
* Análisis léxico --> genera tokens
* Análisis semántico --> genera el AST.
* Code generator --> produce representaciones intermedias que luego
  se traducen a código de máquina especifico para cada CPU.

Los pasos desde el programa hasta la generación del AST se conocen como FRONTEND. 
Los pasos desde el generador de código, pasando por las representaciones
intermedias y el código de máquina se conocen como BACKEND.

Actualmente, motores de videojuegos como Unity trabajan intensamente para lograr
optimizar todos los pasos anteriores. Para ello usan las ideas desarrolladas
en el proyecto LLVM (low level virtual machine). Si quieres profundizar más
en el asunto te recomiendo  `esta conferencia <https://youtu.be/LKpyaVrby04>`__. 
Te dejo también la presentación de la misma `aquí <https://drive.google.com/file/d/1w6A02OlnDS1ILXB56l4DlZ_ntFUrlirX/view?usp=sharing>`__.
Te he hablado un par de veces del nuevo stack de Unity llamado DOTs. Pues bien,
una de las tecnologías en DOTs es el burst compiler. La idea de del burst
compiler es permitir que un subconjunto de C# pueda producir ejecutables,
con un desempeño incluso superior al que se podría lograr con C++. ¿Te suena
interesante no? A mi también :)

¿Quieres dar un vistazo rápido de las posibilidades que vienen con DOTS?
Te recomiendo que hagas `este tutorial <https://youtu.be/C56bbgtPr_w>`__ 
corto para que lo ves con tus propios ojos.

¿Qué es el proyecto LLVM? Es una infraestructura de compilación compuesta
por un conjunto de compiladores y herramientas que permiten desarrollar
un fronted para cualquier lenguaje de programación y un backend para cualquier
set de instrucciones.

Los pasos que se siguen al usar LLVM, todos en tiempo de compilación, son:

* Iniciamos con el programa.
* Análisis léxico --> genera tokens
* Análisis semántico --> genera el AST.
* LLVM IR generator --> genera LLVM bytecode o LLVM IR
* El LLVM IR lo recibe el generador de código LLVM encargado
  de generar código de máquina para múltiples plataformas.

 Considera el siguiente ejemplo llamado main.cpp:

 .. code-block:: c 
    :linenos:

    int main(void){
        int x = 10;
        return x+5-2;
    }

Compila usando ``clang++ main.cpp`` el resultado será el archivo 
``a.out``. Ejecuta el archivo con ``./a.out`` y lee el resultado generado
por el programa con ``echo $?``

Ahora ejecuta ``clang++ main.cpp -S`` para producir el archivo ``main.s``
que tendrá el código ensamblador:

.. code-block:: c 
    :linenos:

    int main(void){
        int x = 10;
        return x+5-2;
    }

.. code-block:: c 
    :linenos:

		.text
		.file	"main.cpp"
		.globl	main                    # -- Begin function main
		.p2align	4, 0x90
		.type	main,@function
	main:                                   # @main
		.cfi_startproc
	# %bb.0:
		pushq	%rbp
		.cfi_def_cfa_offset 16
		.cfi_offset %rbp, -16
		movq	%rsp, %rbp
		.cfi_def_cfa_register %rbp
		movl	$0, -4(%rbp)
		movl	$10, -8(%rbp)
		movl	-8(%rbp), %eax
		addl	$5, %eax
		subl	$2, %eax
		popq	%rbp
		.cfi_def_cfa %rsp, 8
		retq
	.Lfunc_end0:
		.size	main, .Lfunc_end0-main
		.cfi_endproc
											# -- End function
		.ident	"clang version 10.0.0-4ubuntu1 "
		.section	".note.GNU-stack","",@progbits
		.addrsig

Observa las línas 17 y 18 donde hace el cálculo correspondiente
a la expresión ``return x+5-2``. 

Compila de nuevo el código, pero esta vez con 

Ahora ejecuta ``clang++ main.cpp -S -O3`` y lee de nuevo main.s:


.. code-block:: c 
    :linenos:

		.text
		.file	"main.cpp"
		.globl	main                    # -- Begin function main
		.p2align	4, 0x90
		.type	main,@function
	main:                                   # @main
		.cfi_startproc
	# %bb.0:
		movl	$13, %eax
		retq
	.Lfunc_end0:
		.size	main, .Lfunc_end0-main
		.cfi_endproc
											# -- End function
		.ident	"clang version 10.0.0-4ubuntu1 "
		.section	".note.GNU-stack","",@progbits
		.addrsig


Observa la línea 9. ¿Qué notas? ¿Recuerdas el resultado obtenido al ejecutar
el programa? Mira de nuevo la línea 9. 

Estrictamente hablando, se supone que estamos compilando el código, pero
podrás notar que clang++ con la opción -O3 está interpretando, en tiempo,
de compilación, el código, para optimizarlo. Interesante, ¿Cierto? :)

Ahora ejecuta el comando ``clang++ main.cpp -S -emit-llvm`` observa
el archivo main.ll:

.. code-block:: c
   :linenos:

    ; ModuleID = 'main.cpp'
    source_filename = "main.cpp"
    target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
    target triple = "x86_64-pc-linux-gnu"

    ; Function Attrs: noinline norecurse nounwind optnone uwtable
    define dso_local i32 @main() #0 {
      %1 = alloca i32, align 4
      %2 = alloca i32, align 4
      store i32 0, i32* %1, align 4
      store i32 10, i32* %2, align 4
      %3 = load i32, i32* %2, align 4
      %4 = add nsw i32 %3, 5
      %5 = sub nsw i32 %4, 2
      ret i32 %5
    }

    attributes #0 = { noinline norecurse nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

    !llvm.module.flags = !{!0}
    !llvm.ident = !{!1}

    !0 = !{i32 1, !"wchar_size", i32 4}
    !1 = !{!"clang version 10.0.0-4ubuntu1 "}

¿Sabes qué es eso? Es código LLVM IR. Observa las líneas 13 y 14. De nuevo corresponde al
cálculo de la expresión ``return x+5-2``. Desde esta representación se puede generar
código para múltiples set de instrucciones como te comenté antes.


Ejercicio 6
############
Ahora hablemos un poco más de los Just-In-Time (JIT) compilers. Los AOT traducen
el programa a código de máquina en tiempo de compilación. Los JIT lo hacen en
tiempo de ejecución.

Los pasos que sigue un JIT compiler en tiempo de compilación son:

* Iniciamos con el programa.
* Análisis léxico --> genera tokens.
* Análisis semántico --> genera el AST.
* Bytecode emitter --> Generar bytecode.

En tiempo de ejecución un intérprete (lo que llamamos virtual machine) interpreta
el bytecode, pero algunos bytecode son compilados a código de máquina. La primera
vez que se compilan dichos bytecodes y se ejecuta el código de máquina producido
toma un tiempo; sin embargo, la interpretación posterior de estos bytecodes compilados
será muy rápido puesto que la ejecución no será efectuada por el intérprete sino
directamente por la CPU.

Ejercicio 7
############
Finalmente, analicemos un poco más los transpilers o AST transformers.

Los pasos que sigue el transpiler, en tiempo de compilación, son:

* Iniciamos con el programa.
* Análisis léxico --> genera tokens
* Análisis semántico --> genera el AST.
* El transpiler o AST transformer --> genera otro AST para el mismo lenguaje
  o para otro lenguaje de programación. Por ejemplo, traducir una versión vieja
  de javascript a una versión nueva o de python a javascript.
* El nuevo AST se pasa a un generador de código --> genera el programa en otro lenguaje
  de programación (claramente conservando la semántica del programa inicial).

La salida de todo este proceso puede pasarse ahora a un AOT o un JIT compiler.

Ejercicio 8
############

¿Los lenguajes javascript, python, C, C#, c++ son lenguajes interpretados o compilados?

:)

La verdad es que esta pregunta es incorrecta. Lo que es interpretado o compilado
es la implementación específica. ¿Cómo así? Creo que con lo que aprendiste tu mismo
puedes explicar que significa esto. ¿Te animas?

Actividad 19
^^^^^^^^^^^^^^^^
* Fecha: septiembre 24 de 2020
* Descripción: análisis de los ejercicios
* Recursos: ingresa a Teams
* Duración de la actividad: 1:40 minutos
* Forma de trabajo: individual y grupal con solución de dudas en tiempo real

Actividad 20
^^^^^^^^^^^^^^
* Fecha: septiembre 24 a septiembre 29 de 2020 
* Descripción: realizar los ejercicios propuestos
* Recursos: actividad de trabajo autónomo
* Duración de la actividad: 4 horas
* Forma de trabajo: individual, trabajo autónomo.

Pongamos todo el `armamento` de conocimiento que tienes hasta ahora
a prueba con esta pregunta:


¿Cómo es la implementación de C#?

Ejercicio 9
#############
Te voy a dejar `aquí <https://codeasy.net/lesson/c_sharp_compilation_process>`__
un enlace para que leas.

Ahora si, escribe ¿Cómo es la implementación de C#?

Te dejo algunas preguntas adicionales:

* ¿Es posible generar código de máquina partiendo de C# en tiempo de compilación?
* ¿Qué ventaja tiene entonces generar código Just-In-Time en tiempo de ejecución?
* ¿Pudiste identificar en la lectura cómo se llama la máquina virtual utilizada
  para interpretar código IL?
* ¿Qué es el .NET framework?

Ejercicio 10
#############
¿En qué consiste el proyecto MONO?

Ejercicio 11
#############
Busca en la documentación de Unity ¿Qué es IL2CPP? Con lo que aprendiste esta semana
explica ¿Cuáles serían los pasos, en la implementación de Unity, para pasar de
C# a lenguaje de máquina utilizado IL2CPP?

Ejercicio 12
#############
¿Cómo funciona IL2CPP en Unity?

Te dejo `este <hhttps://docs.unity3d.com/Manual/IL2CPP-HowItWorks.html>`__
enlace para que leas al respecto.

Ejercicio 13
#############

* Crea un proyecto en Unity.
* Abre los project settings .
* En el menú Player busca Configuration.
* ¿Qué es el `Scripting Backend <https://docs.unity3d.com/Manual/scripting-backends.html>`__?
* ¿A qué se refiere el `API Compatibility level <https://docs.unity3d.com/Manual/dotnetProfileSupport.html>`__?












