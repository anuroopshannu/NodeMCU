/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

SoftwareSerial nserial(D2,D3);

const char* ssid = "Violet";
const char* password = "violet@edwin";

//int m1=0;
//int m2=1;
//int val;
//int x=0;
//int y=0;
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
  Serial.begin(115200);
  nserial.begin(4800);

  // prepare GPIO2
  //pinMode(2, OUTPUT);
  //digitalWrite(2, 0);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP addresss
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  nserial.print(req);
  nserial.print('\n');
  client.flush();
  //val=req.toInt();
  //val=(499-val)/4;
  //x=128+val;
  //y=128-val;
  //analogWrite(m1,x);
  //analogWrite(m2,y);
  
  // Set GPIO2 according to the request
  //digitalWrite(2, val);
  
 

  // Prepare the response
  //String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
 // s += (val)?"high":"low";
 // s += "</html>\n";
 
  // Send the response to the client
 // client.print(s);
 // delay(1);
//  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}

