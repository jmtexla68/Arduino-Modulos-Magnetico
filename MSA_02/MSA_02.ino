/*
***********************************************
Tutorial Arduino Sensor Magnetico efecto Hall
https://conbotassucias.wordpress.com/
***********************************************

Este ejemplo utiliza un sensor 49E, 
montado en un módulo con un  amplificador 
operacional LM393
Al detectar un campo magnetico, imprimirá el 
valor sobre el monitor serie.
Al detectar un campo magnetico, apaga un led.
Si no detecta se enciende el led.
Utilizamos la señal Analógica y digital del sensor y
trabajan independientemente
*/
 //declaramos las variables
int pin_analogico = A0; // definimos los pines por los que
int pin_digital = 7;   // conectamos las salidas del módulo
int Led=13;       //pin del led
int  sensorValue =  1000;

void setup() {
Serial.begin(9600); //iniciamos la comunicación serial
pinMode(pin_digital,INPUT_PULLUP); //definimos como entrada
pinMode(Led,OUTPUT);//define LED como salida
}

void loop() {

Serial.print("lectura analoga = ");
Serial.println(analogRead(A0));
delay(sensorValue);
// si la salida digital está en cero, es porque se ha superado el valor de referencia
// entonces se desplegará el mensaje: "salida digital activa"
if (digitalRead(pin_digital) == LOW)
{
  Serial.println("salida digital activa");
  digitalWrite(Led,HIGH);
}
else
{
  Serial.println("salida digital inactiva"); // de otra forma de deplegará "salida digital inactiva"
digitalWrite(Led,LOW);
}

}
