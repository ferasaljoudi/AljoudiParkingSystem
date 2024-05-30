<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/SVGsHeader/aljoudiParkingSystem.svg" alt="Aljoudi Parking System" style="width: 100%"></a>
</div>
<br>

This project was developed individually as part of ENEL351, a course within my engineering degree program. The Aljoudi Parking System reflects the application of skills and knowledge acquired through my studies, showcasing a comprehensive approach to solving real-world problems in smart parking management.

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/overview.svg" alt="Overview" style="width: 100%"></a>
</div>
<br>

Aljoudi Parking System represents a significant step towards automating vehicle management and parking solutions. The system uses the microcontroller (STM32F103RB) technology to simplify parking processes, enhance vehicle safety, and improve user experience in parking environments. The system is built on a practical, user-friendly platform that can accommodate up to four vehicles simultaneously. Incorporating different sensors and electronic components, the system aims to provide efficient, reliable, and secure parking services, focusing on areas with limited parking space.

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/technologiesUsed.svg" alt="Technologies Used" style="width: 100%"></a>
</div>
<br>

<div align = "center">

  [![C](https://img.shields.io/badge/-C-00599C?style=for-the-badge&logo=c&logoColor=00FF00)](https://www.w3schools.com/c/)
  <a href="https://www.st.com/en/microcontrollers-microprocessors/stm32f1-series.html"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/Badges/stm.svg" alt="STM32"></a>
  [![Keil uVision](https://img.shields.io/badge/-Keil_uVision-0090D0?style=for-the-badge&logoColor=white)](https://www.keil.com/)

</div>

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/features.svg" alt="Features" style="width: 100%"></a>
</div>
<br>

- <b>Real-time Parking Availability:</b> Utilizes an LCD display to inform users of the current number of available parking spots, updating dynamically as vehicles enter and leave the facility.
- <b>Vehicle Weight Measurement:</b> At the entrance, the system includes a pressure sensor to weigh vehicles. This weight is used to categorize vehicles and determine parking rates.
- <b>Dynamic Rate Calculation:</b> Based on the vehicle’s weight, the system calculates the appropriate parking rate per hour and displays this information on the LCD screen.
- <b>Automated Door Mechanism:</b> Equipped with servo motors, the system automates the opening and closing of the entrance and exit doors.
- <b>Vehicle Presence Detection:</b> Incorporates an IR sensor at the exit to detect the presence of a vehicle, ensuring the exit door opens timely for leaving vehicles.
- <b>Fire Detection and Alerting:</b> Features a gas sensor to detect smoke or fire within the parking lot. In case of detection, the system activates a digital buzzer to alert users and staff.
- <b>Full Capacity Management:</b> The system is programmed to deny entry (by not opening the entrance door) when the parking lot reaches full capacity.

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/softwareRequirements.svg" alt="Software Requirements" style="width: 100%"></a>
</div>
<br>


The software environment and programming language used for the system are as follows:

- <b>Keil µVision IDE:</b> The project is developed and compiled using the Keil µVision IDE.
- <b>C Programming Language:</b> The firmware for the STM32F103RB microcontroller is written in C.

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/hardwareRequirements.svg" alt="Hardware Requirements" style="width: 100%"></a>
</div>
<br>

- <b>STM32F103RB Microcontroller:</b> Acts as the central unit controlling the entire parking system.
- <b>LCD Display:</b> For displaying available parking spots, rates, and alerts.
- <b>Potentiometer (10K):</b> Used to adjust the contrast of the LCD display.
- <b>Analog Pressure Sensor:</b> To weigh vehicles and determine parking rates.
- <b>Analog Gas Sensor:</b> For detecting smoke or fire within the parking facility.
- <b>Digital Buzzer:</b> To alert users in case of fire detection.
- <b>Digital IR Sensor:</b> For detecting vehicle presence at the exit door.
- <b>Two Servo Motors:</b> To control the opening and closing of entrance and exit doors.
- <b>Power Supply:</b> 4xAA battery holder and powerbank.

<br>
<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/ferasaljoudi/AssetsRepository/main/BrownSVGs/resources.svg" alt="Resources" style="width: 100%"></a>
</div>
<br>

- For an in-depth understanding and comprehensive details of the Aljoudi Parking System, please refer to the _<a href="https://github.com/ferasaljoudi/AljoudiParkingSystem/blob/main/Documentation/ProjectReport.pdf" title="Aljoudi Parking System Report">Project Report</a>_.
- To see system in action and understand its real-world functionality, watch the _<a href="https://www.youtube.com/watch?v=ReGvdZkHqbI" title="Aljoudi Parking System">Youtube Video</a>_.
