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
Según va aumentando el valor del campo magnetico 
el led parpadea más rápido.
*/
 //declaramos las variables
int  sensorPin  =  A0;     // pin de entrada del sensor 
int  ledPin  =  13;   // pin de salida para el LED
int  sensorValue =  0;  // variable para almacenar el valor procedente del sensor

void setup()
{                 //la variable analogica no se declara
pinMode(ledPin,OUTPUT); //definimos el pin 13 como salida
Serial.begin(9600);
}
void loop()
{
sensorValue =  analogRead(sensorPin);
if (sensorValue < 450 || sensorValue > 600)  // valores bajos o altos implican campo detectado
  {Serial.print("Campo detectado: ");  // imprime leyenda si detecta campo

/* Enciende y apaga led con un retardo conforme
  al valor entregado por el sensor*/
  
digitalWrite(ledPin,  HIGH);  
delay(sensorValue); 
digitalWrite(ledPin,  LOW);
delay(sensorValue);}
if (sensorValue < 540 || sensorValue > 560) //esta comparación es para que no esté escibiendo con valores nulos
{ Serial.println(sensorValue,  DEC);
  
}
}
