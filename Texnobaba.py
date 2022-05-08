from playsound import playsound
import time
import serial
import mysql.connector
from mysql.connector import Error
import Texnobaba_Keypad

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1) #change port
ser.reset_input_buffer()

playsound("Voices/testValorant.wav", True) #it will play background if false #Greetings
time.sleep(1)

BeginningBool = True

while True:
    if BeginningBool:
        playsound("Voices/testValorant.wav", True) #Please enter the code #A is accept, C is Clear
        BeginningBool = False
    Texnobaba_Keypad.Tb_Keypad()


