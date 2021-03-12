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
// incuimos la libreria:
#include <LiquidCrystal.h>
// inicializamos la libreria con los pines de
// la interfaz
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 //declaramos las variables
float pin_analogico = A0; // definimos los pines por los que
int pin_digital = 7;   // conectamos las salidas del módulo
int Led=13;       //pin del led
int  sensorValue =  1000;

void setup() {{
Serial.begin(9600); //iniciamos la comunicación serial
pinMode(pin_digital,INPUT_PULLUP); //definimos como entrada
pinMode(Led,OUTPUT);//define LED como salida
}
{
 // configuramos el numero de columnas y filas:
 lcd.begin(16, 2);
}}

void loop() {

Serial.print("lectura analoga = ");
Serial.println(analogRead(A0));
delay(sensorValue);

lcd.setCursor(1,0);
lcd.write("Campo: ");
lcd.print(analogRead(A0));

// si la salida digital está en cero, es porque se ha superado el valor de referencia
// entonces se desplegará el mensaje: "salida digital activa"
if (digitalRead(pin_digital) == LOW)
{
  Serial.print("No Detectado");
  digitalWrite(Led,HIGH);
  lcd.setCursor(1,1);
  lcd.print("No Detectado");
}
else
{
  Serial.println("No Detectado"); // de otra forma de deplegará "salida digital inactiva"
digitalWrite(Led,LOW);
lcd.setCursor(1,1);
  lcd.print("Detectado   ");
}

}
