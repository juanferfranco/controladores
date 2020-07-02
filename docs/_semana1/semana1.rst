Semana 1: Unidad 1/Reto 1
==========================

Esta semana comenzaremos estudiando y construyendo los bloques de
constitutivos básicos de una computador: las compuertas

Objetivos
----------
1. Introducir el curso.
2. Construir los circuitos digitales más básicos: las compuertas.

RoadMap
--------
¿Para dónde vamos en la primera parte del curso? Vamos a implementar
un computador.

¿Cómo se construye un computador? Se parte de un diseño que se
describe mediante algún lenguaje de descripción de hardware:

.. image:: ../_static/gateHDL.png

Luego el diseño se debe traducir a transistores y conexiones entre
estos:

.. image:: ../_static/transistor.png

Finalmente, los transistores y sus conexiones se deben transferir
a un medio físico. Esto se hace mediante un proceso conocido como
fotolitografía:

.. raw:: html

    <div style="position: relative; padding-bottom: 5%; height: 0; overflow: hidden; max-width: 100%; height: auto;">
        <iframe width="560" height="315" src="https://www.youtube.com/embed/vK-geBYygXo" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
    </div>

Y ¿Cómo funciona un transistor?

.. raw:: html

    <div style="position: relative; padding-bottom: 5%; height: 0; overflow: hidden; max-width: 100%; height: auto;">
        <iframe width="560" height="315" src="https://www.youtube.com/embed/tz62t-q_KEc" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
    </div>

En este curso vamos a implementar un computador usando un lenguaje
de descripción de hardware. Nuestro bloque de construcción básico será la
compuerta NAND y a partir de esta construiremos otros circuitos, que
a su vez utilizaremos para construir otros circuitos más complejos.
El proceso se irá repitiendo hasta llegar a un computador completo.


Código de honor
----------------
Al realizar el proyecto de esta semana se espera que hagas lo siguiente:

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
* Fecha: julio 7 de 2020 - 8 a.m.
* Descripción: asiste al encuentro sincrónico donde se introducirá el curso y se
  explicará el reto de la semana, su importancia, su relación con los
  criterios de competencia y cómo será evaluada.
* Recursos: ingresar al grupo de `Teams <https://teams.microsoft.com/l/team/19%3a2120a8ab2394491a8b8a9bfe4d209156%40thread.tacv2/conversations?groupId=790121bd-4b34-49b3-b4f2-a29c7a9eee9d&tenantId=618bab0f-20a4-4de3-a10c-e20cee96bb35>`__
* Duración de la actividad: 1:40 minutos sincrónicos.
* Forma de trabajo: grupal

Actividad 2
^^^^^^^^^^^^
* Fecha: julio 7 a julio 9 de 2020.
* Descripción: trabajo autónomo
* Recursos: 

    #. Lee el `capítulo 1 del libro guía <https://docs.wixstatic.com/ugd/44046b_f2c9e41f0b204a34ab78be0ae4953128.pdf>`__.
    #. También tienes disponible esta `presentación <https://drive.google.com/open?id=1MY1buFHo_Wx5DPrKhCNSA2cm5ltwFJzM>`__
       para que complementes.
    #. Instala las herramientas a utilizar y explóralas.
    #. Lee la definición del proyecto y la información que encuentras `aquí <https://www.nand2tetris.org/project01>`__
    #. Comienza a trabajar en el proyecto. Avanza todo lo que puedas.

* Duración de la actividad: 4 horas de trabajo autónomo
* Forma de trabajo: individual

Actividad 3
^^^^^^^^^^^^
* Fecha: julio 9 de 2020 - 10 a.m.
* Descripción: asiste al encuentro sincrónico para resolver dudas en tiempo real con el docente.
* Recursos: 

    #. Ingresar al grupo de `Teams <https://teams.microsoft.com/l/team/19%3a2120a8ab2394491a8b8a9bfe4d209156%40thread.tacv2/conversations?groupId=790121bd-4b34-49b3-b4f2-a29c7a9eee9d&tenantId=618bab0f-20a4-4de3-a10c-e20cee96bb35>`__
    #. Continua trabajando en el `proyecto <https://www.nand2tetris.org/project01>`__

* Duración de la actividad: 1:40 minutos sincrónicos.
* Forma de trabajo: grupal

Actividad 4
^^^^^^^^^^^^
* Fecha: julio 9 a julio 14 de 2020.
* Descripción: terminación del proyecto y sustentación
* Recursos: 

    #. Termina el proyecto.
    #. Realiza el video de sustentación para lo cual te recomiendo los siguientes recursos:

        #. Software para capturar `OBS Studio <https://obsproject.com/>`__
        #. Observa `este <https://www.youtube.com/watch?time_continue=3&v=1tuJjI7dhw0>`__
           tutorial para el manejo de OBS Studio.
* Duración de la actividad: 4 horas.
* Forma de trabajo: individual.

¿Qué debes entregar?
^^^^^^^^^^^^^^^^^^^^^
* Crea una carpeta que llamarás reto1.
* Guarda todos los archivos del project1 en esa carpeta.
* Realiza la representación circuital para cada circuito. Marca claramente en el circuito: el nombre de cada
  chip, el nombre de los puertos y el nombre de los cables. Todos estos nombres deben coincidir con los nombres
  en el archivo de implementación de cada circuito.
* Guarda en la carpeta una copia de la `rúbrica <https://docs.google.com/spreadsheets/d/1LEA9HUjbpCGkc3JuRploYtPCqSJ9cDmuG60F74LkeXo/edit?usp=sharing>`__
  con tu autoevaluación diligenciada
* En la carpeta guarda un archivo .pdf con el enlace al video de sustentación y una tabla de contenidos que 
  indique el instante de tiempo en el cual se pueden encontrar cada una de las secciones solicitadas en el video.
* Comprime la carpeta principal en formato .ZIP, ojo, solo .ZIP no uses otros
  formatos por favor.
* Entrega el archivo .ZIP `aquí <https://upbeduco-my.sharepoint.com/:f:/g/personal/juanf_franco_upb_edu_co/ElXoot2FtPxLtw2DSvCL1awBv7RgesnQ3X5qSPg1HjrBQw>`__.
* La fecha límite para entregar el trabajo es antes de la sesión de julio 14 de 2020.

¿Qué deberá tener el video de sustentación?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Máximo 20 minutos: debes planear el video muy bien tal como aprendiste en segundo semestre.
* Cuida la calidad del audio y del video.
* Sección 1: introducción. Di tu nombre y si realizaste el RETO
  completo. Si no terminaste indica claramente qué te faltó y por qué. NO OLVIDES
  diligenciar la `rúbrica <https://docs.google.com/spreadsheets/d/1LEA9HUjbpCGkc3JuRploYtPCqSJ9cDmuG60F74LkeXo/edit?usp=sharing>`__
  con tu autoevaluación.
* Sección 2: modelado. Explica detalladamente cómo resolviste el problema, qué utilizaste,
  que alternativas de solución viste, justifica las razones para usar
  una alternativa sobre otras. Usa una aplicación de whiteboard para explicar el funcionamiento del modelo circuital.
* Sección 3: implementación. Muestra que tu programa carga bien y sin errores
  o advertencias problemáticas. Explica el código fuente tu programa.
* Sección 4: pruebas. Muestra claramente que tu programa pasa todos los vectores de prueba
  definidos.
* Tus explicaciones deben ser claras, precisas y completas. No olvides planear 
  bien tu video de sustentación.
