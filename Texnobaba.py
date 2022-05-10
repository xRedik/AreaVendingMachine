# This program allows a user to enter a
# Code. If the C-Button is pressed on the
# keypad, the input is reset. If the user
# hits the A-Button, the input is checked.

import RPi.GPIO as GPIO
from playsound import playsound
import time
from playsound import playsound
import time
import serial
import mysql.connector
from mysql.connector import Error
import Texnobaba

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1) #change port
ser.reset_input_buffer()


#change pins
L1 = 5
L2 = 6
L3 = 13
L4 = 19

C1 = 12
C2 = 16
C3 = 20
C4 = 21

keypadPressed = -1
jobFinished = False
boolCheck = False
secretCode = "4789135"
input = ""

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(L1, GPIO.OUT)
GPIO.setup(L2, GPIO.OUT)
GPIO.setup(L3, GPIO.OUT)
GPIO.setup(L4, GPIO.OUT)

GPIO.setup(C1, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(C2, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(C3, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(C4, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

def keypadCallback(channel):
    global keypadPressed
    if keypadPressed == -1:
        keypadPressed = channel

GPIO.add_event_detect(C1, GPIO.RISING, callback=keypadCallback)
GPIO.add_event_detect(C2, GPIO.RISING, callback=keypadCallback)
GPIO.add_event_detect(C3, GPIO.RISING, callback=keypadCallback)
GPIO.add_event_detect(C4, GPIO.RISING, callback=keypadCallback)

def setAllLines(state):
    GPIO.output(L1, state)
    GPIO.output(L2, state)
    GPIO.output(L3, state)
    GPIO.output(L4, state)

def checkCode(enteredCode):
    if enteredCode == secretCode:
        return True, "FirstKit"
    return False, None

def checkSpecialKeys():
    global input
    global jobFinished

    pressed = False
    GPIO.output(L3, GPIO.HIGH)

    if (GPIO.input(C4) == 1):
        print("Code is Cleared")
        playsound("Voices/3Second.wav",True) #temizlendi
        input = ""

        pressed = True

    GPIO.output(L3, GPIO.LOW)
    GPIO.output(L1, GPIO.HIGH)

    if (not pressed and GPIO.input(C4) == 1):
        boolCheck, KitName = checkCode(input)
        if boolCheck:
            print(input)
            print(KitName)
            ser.write((KitName+"\n").encode())
            print("Code correct!")
            playsound("Voices/3Second.wav",True) #First Kit Delivered

        else:
            playsound("Voices/3Second.wav",True) #Incorred Code
            print("Incorrect code!")

        pressed = True
        jobFinished = True
        input = ""

    GPIO.output(L1, GPIO.LOW)
    GPIO.output(L2, GPIO.HIGH)

    if (GPIO.input(C4) == 1):
        print("Instructions")
        playsound("Voices/3Second.wav",True) #it will play background if false
        pressed = True
   
    GPIO.output(L2, GPIO.LOW)

    return pressed

def readLine(line, characters):
    global input
    GPIO.output(line, GPIO.HIGH)
    if(GPIO.input(C1) == 1):
        input += characters[0]
    if(GPIO.input(C2) == 1):
        input += characters[1]
    if(GPIO.input(C3) == 1):
        input += characters[2]
    if(GPIO.input(C4) == 1):
        input += characters[3]
    GPIO.output(line, GPIO.LOW)

def Tb_Keypad():
    global jobFinished
    while True:
        if keypadPressed != -1:
            setAllLines(GPIO.HIGH)
            if GPIO.input(keypadPressed) == 0:
                keypadPressed = -1
            else:
                time.sleep(0.1)
        else:
            if not checkSpecialKeys():
                readLine(L1, ["1","2","3","A"])
                readLine(L2, ["4","5","6","B"])
                readLine(L3, ["7","8","9","C"])
                readLine(L4, ["*","0","#","D"])
                time.sleep(0.1)
            else:
                time.sleep(0.1)

if __name__ == '__main__':
    playsound("Voices/3Second.wav", True) #it will play background if false #Greetings
    print("First")
    time.sleep(1)
    playsound("Voices/testValorant.wav", False) #Please enter the code #A is accept, C is Clear
    print("Second")

    while True:
        Tb_Keypad()
