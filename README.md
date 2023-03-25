# **Industrial Vacuum Cleaner**
##### Industrial Vacuum Cleaner project based on ARM-CortexM4 processor developed in C-Language. Debugged and simulated using Keil-IDE (v5) ... the project is part of Swift Act Training (Embedded Software Design).
---
## **Details**
The Project presents the software development of an industrial vacuum cleaner that has 3 necessary speed states:
**Low Speed - Medium Speed - Max Speed**
And the vacuum's motor speed is to be changed using a switch _(speed can be changed multiple times using the switch till it reaches the maximum or minimum speed)_. Additionally, the current speed will be displayed.
>__Note__ that the speed will be in degrees ... and the speed states angles will correspond to the AC sine wave targeted angle (obtained by **TRIAC**) but it's simulated using SysTick for simulation purpose.
##### Generally, the vacuum will have 3 fundamental states:
**1. Firing State:** which will be the triggering pulse that the changes firing angle corresponding to each complete sine wave _(cycle)_
**2. Soft Switching State:** used when changing from one speed to another
**3. Harmonic Reduction State:** used when the desired speed is obtained ... by using **Kurz Technique** the motor will continuously operate at the same speed suppressing the effect of the harmonics.
>__Note__ that the firing angle is the angle that gets continuously updated based on the __target__ vacuum cleaner state angle (Soft Switching State or Harmonic Reduction State).

## **Attachments**
Simulation video illustrating the vacuum cleaner operation ... the toolbox menu simulates the switches where,
* **Plus:** increases speed by 50 degrees
* **Minus:** Decreases speed by 50 degrees
* **Dust:** Resets speed to remove dust and restores operation when pressed again.

>__Note__ that the _Dust_ is to be a dust sensor that will indicate the bag is full and should automatically restore operation once the dust bag is cleaned.

https://user-images.githubusercontent.com/97047710/227726665-cde2c5eb-ff88-4536-9b24-ec439b338d0d.mp4

The following image clarifies the Vacuum Cleaner’s (VC) states upon increasing and decreasing speed knowing that the maximum speed --> 10 degrees ... minimum speed --> 140 degrees.
![Vaccum Cleaner Operation](https://user-images.githubusercontent.com/97047710/227731740-776c656f-5126-4068-ad10-ca0602d20b65.png)
