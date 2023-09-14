# Car Diagnostics and infotainment system

## Introduction

A personal project for my car which enhances the personal user and passenger experience of driving a car. The built system is a hybrid system which partially relies on the in-vehicle sensors, custom-built electronics and the HMI system that uses an embedded microcontroller. The system provides a real time overview of vehicle's running condition such as the tire pressure, engine temperature, lights and temperature controls and a full infotainment system. The system was intended for lower end car models here in India which misses out these features from economical cars. adding this system will provide the user peace of mind, enhances the safety and a sense of luxury at a fraction of cost of the other systems.

## Project Objective

Build an in-vehicle digital infotainment system that provide car telematics, diagnosis, full blown android-based media center for car along with some additional features.

*Full list of features and capabilities are listed in a separate section below.*

## Hardware used (not exhaustive)

-   Custom built PCB for internal circuitry and controlling additional hardware.
-   3.5-inch Touch display as secondary digital instrument cluster. (Used in ver. 2.0 of the project). *ver. 1.0 was based on a simple 1620A LCD display with very limited capabilities.*
-   Nexus 7 as main touch display.
-   Arduino uno
-   Ambient lights
-   SDR radio receiver
-   powered USB hub, USB DAC (Fiio), Splitter
-   Power drivers, MOSFETs, Buck-Boost converters
-   Relay board to control in-vehicle circuitry.
-   TPMS sensors
-   USB Dashcam
-   Reverse parking sensors, camera

## Software used

-   Arduino IDE (C/C++ Programming)
-   Nextion Editor for HMI programming
-   adobe photoshop, Corel for UI designing.
-   Custom android kernel

## Features offered

-   On-screen car diagnostics and telematics data.
-   Enhanced safety and security due to addition of
    -   Dashcam
    -   Reverse Parking camera/drive view monitoring
    -   Reverse parking sensors with distance and visuals on secondary display.
    -   TPMS sensors with active alerts in case something goes wrong with tires.
    -   Ignition lock and touch to start system. (Make sure the car is in neutral gear before using it…)
-   Software Defined Radio (SDR), capable of detecting wide band of radio signals including normal FM broadcasts, Flight tracker, (ADS-B), some free to air open channels can also be detected.
-   For the infotainment part, you get everything that your car didn’t offer you in times this device was built.
    -   Full Internet access, calls.
    -   YouTube, Spotify, anything and everything android OS can handle will function. (thanks to the custom kernel and the custom os…)
    -   Sat nav online and offline.
-   In version 2.0 a few more features were added such as,
    -   touch based vehicle start-stop
    -   interactive parking sensors display
    -   indoor ambient lighting with lighting controls
    -   Foglamps control.
    -   Inside ambient temperature.
    -   potential to integrate any of the car’s functionalities.

#### 

## Device pics (for more, please refer to wiki)

*please excuse me for bad quality pics and messy workbench… In those times I was not very good at presenting kind of person.*

<br/>

### Testing individual components

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/9d388ebacfb8417c4566902f714d3e09.jpeg">
</p>

<!--- <p align="Center"> <i>"note: logo copyright belongs to Micro-Star INT'L CO., LTD" </i></p> --->

<br/>
<br/>

### Assembling ver. 1 system.

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/f7eedbf5f4ca087268f1d76b12a5db2a.jpeg">
</p>

<br/>

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/171357ff35640d9dc3c4047a2f29333c.jpeg">
</p>

<br/>
<br/>


### Version 1.0 completed

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/02dcefdb7e5eea76cb40dc7a3868d732.jpeg">
</p>

<br/>

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/e37f7464d839af581979ec15eb30d827.jpeg">
</p>

<br/>
<br/>

### Upgrading to ver. 2.0

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/af5d03618712d2e5069a821a6ada92b9.jpeg">
</p>

<br/>

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/4266169d7aa75448afd3d20935274a08.jpeg">
</p>

<br/>
<br/>

### ver. 2.0 installed


<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/5271e4fcdbb2cffbff6aa26edf78f724.jpeg">
</p>

<br/>

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/d6f7f290c4efc46ee3d61d01c9a8625c.jpeg">
</p>

<br/>
<br/>

### HMI Interface
<br/>

**Home Screen**

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/eaf3e9bba1395512a6107e3924d26f5d.png">
</p>

<br/>
<br/>

**Ignition switch**

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/a88818149587a8f79bd5a79bc5407ab1.png">
</p>

<br/>
<br/>

**Ambient lights control**

<p float="left">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/f5322579174f9958e9a22e8f3bbb16b5.png">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/03946da73d038f187458a8008e1b53a4.png">
</p>

**Reverse sensor display**

<p align="Center">
  <img src="https://raw.githubusercontent.com/wiki/CuriousLad1000/Car_infotainment_system/images/52b4b8d50843daac27cac4ed1621e7ac.png">
</p>

<br/>
<br/>

> For more detailed pics please see wiki..
