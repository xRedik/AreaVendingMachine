void DeliverFirst(){
    moveUp(4900); // Move up 4900 steps (Note: the stepper motor is set in Quarter set resolution)
    delay(200);
    moveLeft(1700); // Move left 1700 steps
    delay(300);
    // Rotate the helical coil, discharge the selected item
    f_servo.writeMicroseconds(2000); // rotate
    delay(950);
    f_servo.writeMicroseconds(1500);  // stop
    delay(500);
    // Move the container back to starting position
    moveRight(1700);
    delay(200);
    moveDown(4900);
}

void DeliverSecond(){
      moveUp(4900);
      delay(200);
      // Rotate the helix, push the selected item
      s_servo.writeMicroseconds(2000); // rotate
      delay(950);
      s_servo.writeMicroseconds(1500);  // stop
      delay(500);
      moveDown(4900);
}

void DeliverThird(){
      moveUp(2200); 
      delay(200);
      moveLeft(1700);
      delay(300);
      // Rotate the helix, push the selected item
      th_servo.writeMicroseconds(2000); // rotate
      delay(950);
      th_servo.writeMicroseconds(1500);  // stop
      delay(500);
      // Move the container back to starting position
      moveRight(1700);
      delay(200);
      moveDown(2200);
}

void DeliverFourth(){
      moveUp(2200); // Move verticaly 4800 steps
      delay(200);
      // Rotate the helix, push the selected item
      ft_servo.writeMicroseconds(2000); // rotate
      delay(950);
      ft_servo.writeMicroseconds(1500);  // stop
      delay(500);
      moveDown(2200);
}
