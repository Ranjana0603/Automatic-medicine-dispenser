#include <ESP8266WiFi.h>
#include <Servo.h>

const char* ssid = "SKYNET";  // Enter SSID here

const char* password = "$mil!n@007";  //Enter Password here

// Variable to store the HTTP request

Servo myservo1;
Servo myservo2;
Servo myservo3;

String header;

String Item_1_State = "off";
String Item_2_State = "off";
String Item_3_State = "off";

WiFiServer server(80);
/*
  digitalWrite(5,HIGH);
  delay(350);
  digitalWrite(5,LOW);*/
void setup() {

  Serial.begin(115200);
  pinMode(5, OUTPUT);
  myservo1.attach(16);
  myservo2.attach(0);
  myservo3.attach(2);
  myservo1.write(180);
  myservo2.write(180);
  myservo3.write(180);


  Serial.print("Connecting to ");

  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  // Print local IP address and start web server

  Serial.println("");

  Serial.println("WiFi connected-->");

  Serial.println("Copy this IP address: ");

  Serial.println(WiFi.localIP());

  server.begin();

}


void loop() {

  WiFiClient client = server.available();

  if (client) {                             // If a new client connects,

    Serial.println("new client connected");

    String currentLine = "";                // make a String to hold incoming data from the client

    while (client.connected())

      if (client.available()) {             // if there's bytes to read from the client,

        char c = client.read();

        Serial.write(c);

        header += c;

        if (c == '\n') {                    // if the byte is a newline character

          if (currentLine.length() == 0) {

            client.println("HTTP/1.1 200 OK");

            client.println("Content-type:text/html");

            client.println("Connection: close");

            client.println();


            if (header.indexOf("GET /MOTOR1/on") >= 0) {

              Serial.println("MOTOR1 on");

              Item_1_State = "on";

              digitalWrite(5, HIGH);
              delay(350);
              digitalWrite(5, LOW);

              myservo1.write(0);
              delay(350);
              myservo1.write(180);

            } else if (header.indexOf("GET /MOTOR1/off") >= 0) {

              Serial.println("MOTOR1 off");

              Item_1_State = "off";

              digitalWrite(5, HIGH);
              delay(350);
              digitalWrite(5, LOW);

              myservo1.write(0);
              delay(350);
              myservo1.write(180);

            }


            if (header.indexOf("GET /MOTOR2/on") >= 0) {

              Serial.println("MOTOR2 on");

              Item_2_State = "on";

              digitalWrite(5, HIGH);
              delay(350);
              digitalWrite(5, LOW);

              myservo2.write(0);
              delay(350);
              myservo2.write(180);

            } else if (header.indexOf("GET /MOTOR2/off") >= 0) {

              Serial.println("MOTOR2 off");

              Item_2_State = "off";

              digitalWrite(5, HIGH);
              delay(350);
              digitalWrite(5, LOW);

              myservo2.write(0);
              delay(350);
              myservo2.write(180);

            }




            if (header.indexOf("GET /MOTOR3/on") >= 0) {

              Serial.println("MOTOR3 on");

              Item_3_State = "on";

              digitalWrite(5, HIGH);
              delay(350);
              digitalWrite(5, LOW);

              myservo3.write(0);
              delay(350);
              myservo3.write(180);

            } else if (header.indexOf("GET /MOTOR3/off") >= 0) {

              Serial.println("MOTOR3 off");

              Item_3_State = "off";

              digitalWrite(5, HIGH);
              delay(350);
              digitalWrite(5, LOW);

              myservo3.write(0);
              delay(350);
              myservo3.write(180);

            }

            else if (header.indexOf("GET /prescreption1/off") >= 0) {

              Serial.println("MOTOR3 off");

              Item_3_State = "off";

              digitalWrite(5, HIGH);
              delay(350);
              digitalWrite(5, LOW);

              myservo3.write(0);
              delay(350);
              myservo3.write(180);

              delay(500);
              myservo1.write(0);
              delay(350);
              myservo1.write(180);

            }

            else if (header.indexOf("GET /prescreption2/off") >= 0) {

              Serial.println("MOTOR3 off");

              Item_3_State = "off";

              digitalWrite(5, HIGH);
              delay(350);
              digitalWrite(5, LOW);

              myservo2.write(0);
              delay(350);
              myservo2.write(180);

              delay(500);
              myservo2.write(0);
              delay(350);
              myservo2.write(180);

            }
            else if (header.indexOf("GET /prescreption3/off") >= 0) {

              Serial.println("MOTOR3 off");

              Item_3_State = "off";

              digitalWrite(5, HIGH);
              delay(350);
              digitalWrite(5, LOW);

              myservo3.write(0);
              delay(350);
              myservo3.write(180);

              delay(500);
              myservo1.write(0);
              delay(350);
              myservo1.write(180);

              delay(500);
              myservo2.write(0);
              delay(350);
              myservo2.write(180);

            }
            // Display the HTML web page

            client.println("<!DOCTYPE html><html>");

            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");

            client.println("<link rel=\"icon\" href=\"data:,\">");

            client.println("<style>html { font-family: Cairo; display: inline; margin: 0px auto; text-align: center; background-color: #ccffb3;}");

            client.println(".button { background-color: #800000; border: none; color: white; padding: 16px 40px;");

            client.println("text-decoration: none; font-size: 35px; margin: 2px; cursor: pointer;}");

            client.println(".button2 {background-color: #800000;}</style></head>");



            client.println("<svg width=\"350\" height=\"80\"><text fill=\"#00bfbf\" font-family=\"serif\" font-size=\"24\" id=\"svg_1\" stroke=\"#000000\" text-anchor=\"middle\" transform=\"matrix(1.35388 0 0 1.42308 -6.66283 -8.67308)\" x=\"106.5\" xml:space=\"preserve\" y=\"41.5\">$$Vending Machine$$</text></svg>");



            // Web Page Heading

            client.println("<body><h1>Select your product</h1>");
            //button 1

            //client.println("<p>Device state: " + Item_1_State + "</p>");

            // If the LED1State is off, it displays the ON button

            if (Item_1_State == "off") {

              client.println("<p><a href=\"/MOTOR1/on\"><button class=\"button\">Amlodipine</button></a></p>");

              //client.println("<svg width=\"500\" height=\"300\"><ellipse cx=\"258.5\" cy=\"125.5\" fill=\"#ffffff\" rx=\"47\" ry=\"52\" stroke=\"#ffffaa\" stroke-width=\"5\"/><rect fill=\"#cccccc\" height=\"40\" stroke=\"#ffffaa\" stroke-width=\"5\" transform=\"rotate(-0.485546 261 187.5)\" width=\"39\" x=\"241.5\" y=\"167.5\"/></svg>");


            } else {

              client.println("<p><a href=\"/MOTOR1/off\"><button class=\"button button2\">Amlodipine</button></a></p>");

              //client.println("<svg width=\"500\" height=\"300\"><ellipse cx=\"258.5\" cy=\"125.5\" fill=\"#ff7f00\" rx=\"47\" ry=\"52\" stroke=\"#ffffaa\" stroke-width=\"5\"/><rect fill=\"#cccccc\" height=\"40\" stroke=\"#ffffaa\" stroke-width=\"5\" transform=\"rotate(-0.485546 261 187.5)\" width=\"39\" x=\"241.5\" y=\"167.5\"/></svg>");


            }

            client.println("</body></html>");

            //button 2



            //client.println("<p>Device state: " + Item_2_State + "</p>");

            // If the LED1State is off, it displays the ON button

            if (Item_2_State == "off") {

              client.println("<p><a href=\"/MOTOR2/on\"><button class=\"button\">Metformin</button></a></p>");

              //client.println("<svg width=\"500\" height=\"300\"><ellipse cx=\"258.5\" cy=\"125.5\" fill=\"#ffffff\" rx=\"47\" ry=\"52\" stroke=\"#ffffaa\" stroke-width=\"5\"/><rect fill=\"#cccccc\" height=\"40\" stroke=\"#ffffaa\" stroke-width=\"5\" transform=\"rotate(-0.485546 261 187.5)\" width=\"39\" x=\"241.5\" y=\"167.5\"/></svg>");


            } else {

              client.println("<p><a href=\"/MOTOR2/off\"><button class=\"button button2\">Metformin</button></a></p>");

              //client.println("<svg width=\"500\" height=\"300\"><ellipse cx=\"258.5\" cy=\"125.5\" fill=\"#ff7f00\" rx=\"47\" ry=\"52\" stroke=\"#ffffaa\" stroke-width=\"5\"/><rect fill=\"#cccccc\" height=\"40\" stroke=\"#ffffaa\" stroke-width=\"5\" transform=\"rotate(-0.485546 261 187.5)\" width=\"39\" x=\"241.5\" y=\"167.5\"/></svg>");


            }

            client.println("</body></html>");

            //button 3



            //client.println("<p>Device state: " + Item_3_State + "</p>");

            // If the LED1State is off, it displays the ON button

            if (Item_3_State == "off") {

              client.println("<p><a href=\"/MOTOR3/on\"><button class=\"button\">Lisinopril</button></a></p>");

              //client.println("<svg width=\"500\" height=\"300\"><ellipse cx=\"258.5\" cy=\"125.5\" fill=\"#ffffff\" rx=\"47\" ry=\"52\" stroke=\"#ffffaa\" stroke-width=\"5\"/><rect fill=\"#cccccc\" height=\"40\" stroke=\"#ffffaa\" stroke-width=\"5\" transform=\"rotate(-0.485546 261 187.5)\" width=\"39\" x=\"241.5\" y=\"167.5\"/></svg>");


            } else {

              client.println("<p><a href=\"/MOTOR3/off\"><button class=\"button button2\">Lisinopril</button></a></p>");

              //client.println("<svg width=\"500\" height=\"300\"><ellipse cx=\"258.5\" cy=\"125.5\" fill=\"#ff7f00\" rx=\"47\" ry=\"52\" stroke=\"#ffffaa\" stroke-width=\"5\"/><rect fill=\"#cccccc\" height=\"40\" stroke=\"#ffffaa\" stroke-width=\"5\" transform=\"rotate(-0.485546 261 187.5)\" width=\"39\" x=\"241.5\" y=\"167.5\"/></svg>");


            }

            client.println("</body></html>");

            client.println();

            break;

          } else {

            currentLine = "";

          }

        } else if (c != '\r') {

          currentLine += c;

        }

      }

  }

  header = "";

  client.stop();

  //Serial.println("Client disconnected");

  //Serial.println("");

}
