#include <Keypad.h>
#include <Servo.h>

#include "TB_Keypad.h"
#include "TB_Stepper.h"
#include "TB_Servo.h"
#include "TB_Vender.h"

boolean checkKit = false;
String KitReceived = "";

void setup(){
  
  Serial.begin(9600);

  pinMode(DIR_PIN_Vertical, OUTPUT);
  pinMode(STEP_PIN_Vertical, OUTPUT);
  pinMode(DIR_PIN_Horizontal, OUTPUT);
  pinMode(STEP_PIN_Horizontal, OUTPUT);

  f_servo.attach(PIN_FIRST_SERVO);
  s_servo.attach(PIN_SECOND_SERVO);
  th_servo.attach(PIN_THIRD_SERVO);
  ft_servo.attach(PIN_FOURTH_SERVO);

}
  
void loop(){
  if (Serial.available() > 0) {
    KitReceived = Serial.readStringUntil('\n');
    Serial.println(KitReceived);
    checkKit = true;
  }

  if (checkKit){
    if(KitReceived == "First kit") DeliverFirst();
    else if(KitReceived == "Second kit") DeliverSecond(); 
    else if(KitReceived == "Third kit") DeliverThird();
    else if(KitReceived == "Fourth kit") DeliverFourth();
    checkKit = false;
    KitReceived = "";
  }
  delay(2000);
}
