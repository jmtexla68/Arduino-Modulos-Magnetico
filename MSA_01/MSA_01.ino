/*
***********************************************
Tutorial Arduino Sensor Magnetico efecto Hall
https://conbotassucias.wordpress.com/
***********************************************

Este ejemplo utiliza un sensor 49E, 
montado en un módulo con un  amplificador 
operacional LM393

Al detectar un campo magnetico, enciende un led.
*/
 //declaramos las variables
int Led=13;       //pin del led
int pin_digital = 7//pin de señal de sensor
;int  val;//variable para almacenar un valor
void  setup()
{
pinMode(Led,OUTPUT);//define LED como salida
pinMode(pin_digital = 7,INPUT);//define señal sensor como entrada
}
void  loop()

{ val=digitalRead(pin_digital = 7);//lee el valor de la entrada digital
if(val==HIGH)//Cuando el sensor detecta campo, el LED se encienda.
{
digitalWrite(Led,HIGH);
}
else        //si no detecta el LED se apaga
{
digitalWrite(Led,LOW);
}
}
