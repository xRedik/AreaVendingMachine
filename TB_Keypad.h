const byte ROWS = 4;
const byte COLS = 4;

//change pins
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};
//

char MapKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const char CODE_FINISHING_CHARACTER = '#';
const char CODE_STARTING_CHARACTER = '1'; 


Keypad Tb_Keypad = Keypad(makeKeymap(MapKeys), rowPins, colPins, ROWS, COLS);


String All_String_Code = "";

void ReadCode(char pressed_key){
  All_String_Code += pressed_key;
  Serial.println(pressed_key); //For test purpose
  Serial.println(All_String_Code); //For test purpose
}
