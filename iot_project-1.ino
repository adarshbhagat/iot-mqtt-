#include <ESP8266WiFi.h>
#include <PubSubClient.h>

char bulbstate[5];
 
const char* ssid = "adarsh";
const char* password =  "nodemcu@";
const char* mqttServer = "m16.cloudmqtt.com";
const int mqttPort =  13864;
const char* mqttUser = "ggyomyfu";
const char* mqttPassword = "VUdG8ryKPy0z";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
  
  pinMode(D7,OUTPUT);
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  client.publish("esp/test", "Hello from ESP8266");
  client.subscribe("Bhagat");
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) 
  {
    bulbstate[i]=(char)payload[i];
    Serial.print((char)payload[i]);
  }
 
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() 
{
  client.loop();
  if(bulbstate[0] == '1')
  {
    digitalWrite(D7,HIGH);
  }
  if(bulbstate[0] == '0')
  {
    digitalWrite(D7,LOW);
  }
   if(bulbstate[0] == '2')
  {
    digitalWrite(D7,HIGH);
    delay(1000);
    digitalWrite(D7,LOW);
    delay(1000);
  }
  if(bulbstate[0] == '3')
  {
    digitalWrite(D7,HIGH);
    delay(500);
    digitalWrite(D7,LOW);
    delay(500);
  }
  if(bulbstate[0] == '4')
  {
    digitalWrite(D7,HIGH);
    delay(70);
    digitalWrite(D7,LOW);
    delay(70);
    digitalWrite(D7,HIGH);
    delay(70);
    digitalWrite(D7,LOW);
    delay(70);
    delay(700);
  }
  if(bulbstate[0] == '5')
  {
    digitalWrite(D7,HIGH);
    delay(70);
    digitalWrite(D7,LOW);
    delay(70);
    digitalWrite(D7,HIGH);
    delay(70);
    digitalWrite(D7,LOW);
    delay(70);
    digitalWrite(D7,HIGH);
    delay(70);
    digitalWrite(D7,LOW);
    delay(70);
    digitalWrite(D7,HIGH);
    delay(70);
    digitalWrite(D7,LOW);
    delay(70);
    digitalWrite(D7,HIGH);
    delay(70);
    digitalWrite(D7,LOW);
    delay(70);
    delay(1000);
  }
}
