#include <Keypad.h>
#include <Servo.h>

#include "TB_Keypad.h"
#include "TB_Stepper.h"
#include "TB_Servo.h"
#include "TB_Vender.h"

boolean FlagStart = true;
boolean StepUI = true;
boolean StepGive = false;

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
    
  Serial.println("Voice: Greetings");
}
  
void loop(){

  if(StepUI){
    
    char pressed_key = Tb_Keypad.getKey();
    
    if (pressed_key && FlagStart){
      Serial.println(pressed_key);
      if(pressed_key == CODE_STARTING_CHARACTER){
        Serial.println("Voice: Enter the Code");
        FlagStart = false;
      }
    }
    
    else if(pressed_key){
       ReadCode(pressed_key);
       if(pressed_key == CODE_FINISHING_CHARACTER){
          Serial.println("Code: " + All_String_Code);
          All_String_Code = "";
          StepUI = false;
          StepGive = true;
          Serial.println("Voice: Code searched");
       }
    }  
  }
  else if(StepGive){
     //Write code for reading the data from rasbbery pi
      String KitReceived = "";
     
     ///
     if(KitReceived == "First kit") DeliverFirst(); 
     else if(KitReceived == "Second kit") DeliverSecond(); 
     else if(KitReceived == "Third kit") DeliverThird();
     else if(KitReceived == "Fourth kit") DeliverFourth();
     else Serial.println("Voice: Error wrong code");
     StepGive = false;
     StepUI = true;
  }
  
  delay(2000);
}
