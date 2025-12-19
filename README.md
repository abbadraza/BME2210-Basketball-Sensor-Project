# BME2210-Basketball-Sensor-Project
My sensor system utilizes an ultrasonic sensor to detect if a basketball goes through a hoop.
It will detect if it comes in or under 5 cm. From there, it will not only light up a red LED but also add a point to the score which will reflect on the LCD “scoreboard”. It’s meant to add points to the scoreboard automatically if a player makes a basket. In medical applications, this could be used to 

Materials and Methods:
Complete parts list
For the basketball sensor, I used:
•	HC-SR04 Ultrasonic sensor
o	This sensor measures the duration it takes for an ultrasonic wave to be pushed out of the sensor and bounce back. It uses the speed of sound to calculate the distance between the sensor and the object.
•	16*2 LCD display
•	Arduino UNO R3
•	Breadboard
•	Red LED
•	220 Ohm Resistor
•	Potentiometer (variable resistor)
o	A potentiometer is essentially a variable resistor, meaning that when you twist the knob, it either increases or decreases the resistance. This was used specifically for the LCD screen’s text, as the text contrast increases/decreases with the potentiometer.
The ultrasonic sensor will send the duration it took for the ultrasonic signal to bounce back to the sensor. From there, the code will convert that duration to distance, and from there check to see if the distance becomes 5 cm or less, to which it will add a point to the points variable, update the scoreboard, and light up the LED. It will run this loop every 500 ms, so that it can ensure that if a basketball went through a hoop, that it wouldn’t register more than one point.
