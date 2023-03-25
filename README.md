# **Industrial Vaccum Cleaner**
##### Industrial Vaccum Cleaner project based on ARM-CortexM4 microcontroller developed in C-Language and debugged and simulated using Keil-IDE
---
## **Details**
Project presents the software development of an industrial vaccum cleaner that have 3 necessary speed states:
**Low Speed - Medium Speed - Max Speed**
And the vaccum motor speed is to be changed using a switch _(speed can be changed multiple times using the switch till it reaches the maximum or minimum speed)_. Additionally, current speed will be displayed.
##### Generally, the vaccum will have 3 fundamental states:
**1. Firing State:** which will be the triggering pulse that will
**2. Soft Switching State:** used when changing from one speed to another.
**3. Harmonic Reduction State:** used when the desired speed is obtained ... which by using **Kurz Technique** the motor will continuously operate at the same speed reducing the harmonics effect.

## **Attachments**
Simulation video illustrating the vaccum cleaner operation ... the toolbox menu simulates the switches where,
* **Plus:** increases speed 50 degrees.
* **Minus:** Decreases speed 50 degrees.
* **Dust:** Resets speed to be able to remove dust and when pressed again restores operation.

https://user-images.githubusercontent.com/97047710/227726665-cde2c5eb-ff88-4536-9b24-ec439b338d0d.mp4
