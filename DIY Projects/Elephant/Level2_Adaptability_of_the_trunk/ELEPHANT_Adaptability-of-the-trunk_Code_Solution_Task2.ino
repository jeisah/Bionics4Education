//Adaptability OF THE TRUNK

//TASK 2

//LIBRARY
#include <ESP32Servo.h>
Servo servo;

//GLOBALES VARIABLES
//PWM properties Servo
int Frequence0=50;
int LED_Channel0=0;
int Resolution0=16; 

//PWM properties LED
int Frequence12=5000;
int LED_Channel12=12;
int Resolution12=8;

//GPIO
int PIN_Built_in=13;
int PIN_BUZZER=17;

//FUNCTION
//Command_servo: function that give the order of the angle to the servomotor
void Command_servo(float angle)
{   
    //convert 0-180 degrees to 0-65536
    uint32_t conv = (((angle/180.0)*2000)/20000.0*65536.0)+1634;
    ledcWrite(Channel_Servo,conv);
}

//movement_trunk: function that creates a movement of the trunk to convert a moment of activity of the elephant
void movement_trunk()
{
  /*...*/
}

//SETUP: function that initialize the components and display a start message to the serial monitor
void setup()
{
  //INITIALIZATION
  //ESP32 sends information to the LED
  pinMode(PIN_Built_in, OUTPUT);
  
  //ESP32 sends information to the buzzer
  pinMode(PIN_BUZZER,OUTPUT);
  ledcAttachPin(PIN_Built_in,LED_Channel12);
  ledcSetup(LED_Channel12, Frequence12, Resolution12);
  ledcAttachPin(PIN_SERVOS,LED_Channel0);
  ledcSetup(LED_Channel0,Frequence0,Resolution0);
  
  //SERIAL COMMUNICATION
  Serial.begin(9600); 
  delay(5000);
  Serial.println("Adapatability of the trunk: task 2!"); 
}

//LOOP: function that flash the red LED and create a snoring. Then, the buzzer is controlled to create a noise. - code executed repeatedly
void loop()
{ 
   //Flash LED 
   ledcWrite(LED_Channel12,256);
   delay(500);
   ledcWrite(LED_Channel12,0);
   delay(500);
   
   //Snoring
   for (int i=0;i<=256;i=i+10) 
   { 
   ledcWrite(LED_Channel12,i); 
   delay(50);
   }
   
   for (int y=256;y>=0;y=y-10) 
   {  
   ledcWrite(LED_Channel12,y);
   delay(50); 
   }

   //Create a noise
   for (int i=0;i<20;i++) 
   {
    digitalWrite (PIN_BUZZER,HIGH);
    delay (2);
    digitalWrite (PIN_BUZZER,LOW);
    delay (2);
   }
}