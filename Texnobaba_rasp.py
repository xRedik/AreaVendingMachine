from playsound import playsound
import time
import serial
import mysql.connector
from mysql.connector import Error


ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1) #change port
ser.reset_input_buffer()

playsound("Voices/testValorant.wav",True) #it will play background if false

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
    if line[:5]=="Voice":
        CommandStr = line[7:]
        if CommandStr == "Greetings":
            print("Command is Greetings")
            playsound("Voices/testValorant.wav",True) #it will play background if false
        elif CommandStr == "Enter the Code":
            print("Command is Enter the Code")
            playsound("Voices/testValorant.wav",True) #it will play background if false
        elif CommandStr == "Code is searched":
            playsound("Voices/testValorant.wav",True)
    elif line[:4]=="Code":
        Code = line[6:]
        ser.write(SearchFromDatabase(Code))
        print("Code is ", Code)
    else:
        print("Command is ", line, " and it is undefined")