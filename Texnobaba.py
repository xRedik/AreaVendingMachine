from playsound import playsound
import time
import serial
import mysql.connector
from mysql.connector import Error
import Texnobaba_Keypad

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1) #change port
ser.reset_input_buffer()

playsound("Voices/3Second.wav", True) #it will play background if false #Greetings
print("First")
time.sleep(1)
playsound("Voices/testValorant.wav", True) #Please enter the code #A is accept, C is Clear
print("Second")

while True:
    Texnobaba_Keypad.Tb_Keypad()


