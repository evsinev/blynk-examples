/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  You can send/receive any data using WidgetTerminal object.

  App project setup:
    Terminal widget attached to Virtual Pin V1
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "token";

char ssid[] = "ssid_name";
char pass[] = "ssid_password";
 
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);

  ledcWrite(0, pinValue);
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  Serial.print("V3 Slider value is: ");
  Serial.println(pinValue);

  ledcWrite(1, pinValue);
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();
  Serial.print("V3 Slider value is: ");
  Serial.println(pinValue);

  ledcWrite(2, pinValue);
}

void setup()
{

  ledcSetup(0, 3000, 8);
  ledcAttachPin(16, 0);

  ledcSetup(1, 3000, 8);
  ledcAttachPin(15, 1);

  
  ledcSetup(2, 3000, 8);
  ledcAttachPin(18, 2);

  
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
