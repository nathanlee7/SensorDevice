# SensorDevice
I created an Arduino-based project that uses an ultrasonic sensor to measure the distance of nearby objects. The system provides real-time visual and auditory feedback to indicate proximity, making it applicable to a wide range of real-world scenarios where distance detection and object awareness are important, such as robotics, automation, and safety systems.

The program is implemented in C++ and integrates an ultrasonic sensor, three LEDs (red, yellow, and green), and a piezo speaker. Based on the detected distance:

    6 cm: The red LED turns on, and the speaker emits rapid beeps to indicate that an object is in very close proximity.

    2 cm: The yellow LED turns on, and the speaker beeps at a moderate rate to warn that an object is approaching and caution is advised.

    12 cm: The green LED turns on, and the speaker emits slow beeps to indicate that the area is clear of nearby objects.

This project demonstrates how simple electronic components can be combined with Arduino programming to create a functional proximity alert system.
