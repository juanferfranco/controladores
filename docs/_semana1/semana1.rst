SEMANA 1
===========

cap11
^^^^^^


.. code:: cpp

    #include <ESP8266WiFi.h>

    void setup()
    {
    Serial.begin(115200);
    Serial.println();

    WiFi.begin("network-name", "pass-to-network");

    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    }

    void loop() {}

Test

cap12
^^^^^^

.. code:: cpp

    #include <ESP8266WiFi.h>

    void setup()
    {
    Serial.begin(115200);
    Serial.println();

    WiFi.begin("network-name", "pass-to-network");

    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    }

    void loop() {}

More Code

cap13
^^^^^^
