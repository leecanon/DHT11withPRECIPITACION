#include <DHT.h>

const int sensorDHT=2;
int sensorPin=2;
int sensorPin2=10;
int sensorValue=0;

int temp = 0, humedad, lluvia;
int t = 1023;

DHT dht (sensorDHT,DHT11);

void setup() {

  Serial.begin(9600); //Comunicacion con la PC a 9600 batios
  dht.begin();//iniciamos nuestro sensor
  pinMode (2,INPUT); 
  pinMode(10, INPUT);
}

void loop() {

      int lluvia= map(analogRead(A1), 0.00, 1023, 30,0);//map() 
      sensorValue = analogRead(sensorPin);
      humedad= dht.readHumidity(); //Permite leer la humedad incluyendo la libreria 
      temp= dht.readTemperature(); //Permite leer la temperatura "" "" 
      //Serial.println(""); 
      Serial.print("Temperatura: ");
      Serial.print(temp);
      Serial.print("°C"); //temperatura: 21°C
      Serial.print("Humedd:");
      Serial.print(humedad);
      Serial.print("%");
      Serial.println(""); 
      Serial.print("LLuvia: ");
      Serial.print(lluvia);
      Serial.print("mm");
  delay(500);
}
