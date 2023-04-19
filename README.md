# Parcel Sorting Car
![Image text](https://raw.github.com/Zeren-Zhao/parcel_sorting_car/main/Images/Logo.png)

Replacing the current manual sorting of couriers in warehouses with a 'Parcel Sorting Car'. The courier sorting trolley is a machine trolley that automatically scans QR codes and sorts couriers according to the information. The vehicle continuously scans the QR code with a camera and after analysing the code transports the courier to the designated location and returns back. (The use of other equipment for sorting purposes can also be achieved in some cases and the 'Parcel Sorting Car' can be considered a model for a courier sorting system.)

## Motivation

With the rapid development of e-commerce business, the courier industry has also become increasingly prosperous. In the development of the courier industry, parcels sorting cars play a vital role. First of all, parcels sorting cars can automatically sort couriers according to their destinations, reducing the time and labor costs of manual operations and improving work efficiency. parcels sorting cars can automatically detect and correct errors during the sorting process, reducing the rate of human-caused sorting errors and improving the accuracy of courier operations and customer satisfaction. With the development of the courier industry, the volume of orders is increasing and the sorting tasks are becoming more and more complex, so the traditional manual sorting method can no longer meet the business needs.

  In summary, the express sorting trolley is an inevitable product of the development of the express industry, with important significance and background. It not only improves work efficiency and accuracy, but also provides support for the modernization and transformation of the express industry and technological innovation.


## Project Description

Our project is to develop a parcel sorting car based on `Raspberry Pi 3B`, which aims to achieve the initial regional sorting of parcels. The project uses a `camera` for QR code recognition, and after it scans the parcel identification code it makes a determination of the area it is going to, and then navigates to the area where the parcel needs to be unloaded based on the coordinates of its current location.The location information will be obtained based on the statistics of the `timer function` build by using select(). After reaching the area, it performs the unloading operation. After the action is executed, it reverts back to the starting point to wait for the next parcel to be scanned.

## Features

- QR code scanning and information extraction： Obtain the infrmation in QR code
- Decision making: Determine destination location based on information
- Navigation of Sorting Car: Navigation based on destination coordinates and starting position coordinates
- Unloading function:Interrupt navigation when you reach your destination and drive servo to perform unloading operations

## Required packages:
- Raspberry Pi OS 32bit (previously called Raspbian): https://www.raspberrypi.com/software/
- Cmake: https://cmake.org/download/
- OpenCV for C++: https://opencv.org/
- zbar: https://github.com/ZBar/ZBar
- wiringPi: http://wiringpi.com/wiringpi-updated-for-the-pi-v3plus/
### Installing Raspberry Pi OS:
1. Download package.
2. Install Raspberry Pi OS on your PC.
3. Insert SD card into your PC.
4. Open Raspberry Pi Imager.
5. In Operating system select: Raspberry Pi OS (32-bit)
6. In Storage select your SD card.
7. Select setting and add your WIFI name (SSID) and password.
8. Finally, click on Write.
### Installing CMake:
1. Open terminal
2. Installation
```
sudo apt-get install cmake
```
### Installing Opencv
1. Open terminal
2. Download OpenCV from Official website
3. Extract all
4. Open terminal and use ``cd`` go to the opencv directory
5. Create a new build folder for building
```
mkdir build
cd build
```
6. Compilation
```
cmake ..
sudo make
sudo make install
```
``sudo make`` is very time consuming, about five to six hours depending on the internet speed.
### Installing zbar
1. Open terminal
2. Installation
```
sudo apt-get install libzbar-dev
```
### Installing wiringPi
1. Open terminal
2. Installation
```
cd /tmp
wget https://unicorn.drogon.net/wiringpi-2.46-1.deb
sudo dpkg -i wiringpi-2.46-1.deb
```
3. To test if you have already installed wiringPi, you can open terminal
```
gpio readall
```
if there is the map of gpio, you have installed the wiringPi successfully

## Build
### Components
|Name              |Cost |Amount|Total|Link |
|------------------|-----|------|-----|-----|
|Raspberry Pi 3B   |     |  1   |     |                                                                               |
|Raspberry Pi Camera Module| 8.59|1|8.59|https://www.amazon.co.uk/Raspberry-Camera-KEYESTUDIO-Vision-Module/dp/B073RCXGQS/ref=sxin_16_pa_sp_search_thematic_sspa?content-id=amzn1.sym.8a568856-906e-49e2-9994-a7e0ba8118ab%3Aamzn1.sym.8a568856-906e-49e2-9994-a7e0ba8118ab&crid=2FIEZIGDXZZRM&cv_ct_cx=pi%2Bcamera&keywords=pi%2Bcamera&pd_rd_i=B073RCXGQS&pd_rd_r=e7c70e0b-5c0e-4bf9-8370-cf5d8c94d9a1&pd_rd_w=adFcw&pd_rd_wg=63SlJ&pf_rd_p=8a568856-906e-49e2-9994-a7e0ba8118ab&pf_rd_r=3EEEV73AX77CC48F976T&qid=1681570005&sbo=RZvfv%2F%2FHxDF%2BO5021pAnSA%3D%3D&sprefix=pi%2Bca%2Caps%2C85&sr=1-1-1c12e6fc-61d1-41ee-8e02-a6ca5f2da604-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9zZWFyY2hfdGhlbWF0aWM&th=1|
|L298N motor driver|5.39 |  1   |5.39 |https://www.amazon.co.uk/dp/B07GF2MK4Z?psc=1&ref=ppx_yo2ov_dt_b_product_details|
|TT motor with Plastic Tire Wheels|2.15|2|4.30|https://www.amazon.co.uk/AEDIKO-Motor-Gearbox-Shaft-200RPM/dp/B09V7QH1S8/ref=sr_1_7?keywords=tt%2Bmotor&qid=1681569618&sr=8-7&th=1|
|SG90 servo motor| 3.00|1|3.00|https://www.amazon.co.uk/Servomotor-Geared-include-Flugzeug-Modellbau/dp/B0BN82DX5D/ref=sr_1_1_sspa?crid=1WC6ZE2KE9YM6&keywords=sg90%2Bservo&qid=1681569796&sprefix=sg90%2Caps%2C83&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1|
|Power bank| |1|||
|DuPont thread||severval|||
|Acrylic sheet||1|||
|Universal Wheel||several|||
|6-12v Power supply||1|||
### Tools
1. Insulation tape
2. Tweezers
3. Glue for plastic parts
4. Phillips screwdrivers
5. Scissors
### Connection Diagram
![Image text](https://raw.github.com/Zeren-Zhao/parcel_sorting_car/main/Images/wiring.png)

## Software Structure

### System Flowchart
![Image text](https://raw.github.com/Zeren-Zhao/parcel_sorting_car/main/Images/Flowchart.png)
### State Machine
![Image text](https://raw.github.com/Zeren-Zhao/parcel_sorting_car/main/Images/Sm.png)
## User Case
![Image text](https://raw.github.com/Zeren-Zhao/parcel_sorting_car/main/Images/User_case.png)

## Unit test
Find detaile here: https://github.com/Zeren-Zhao/parcel_sorting_car/wiki/3.-Unit-test
## How to use
1. Download the code
2. Extract all
3. Open terminal
4. Use ``cd`` in the terminal to enter the project directory
5. Execute the ``cmake .`` command to generate the Makefile
6. Execute the ``make`` command to compile and generate the executable file 
7. Execute the program by entering the path and name of the executable file in the terminal
```
cd the/path/of/the/project
cmake .
make
./name of the executable file
```
## Project Contributers

| Name | Student ID | Role |
| -------------- | ---------| -----------|
| [Shiguang Liu](https://github.com/Shiguang2737887?tab=overview&from=2023-01-01&to=2023-01-31)| 2737887L |Decision, Navigation & unloading function Designer | 
| [Zeren Zhao](https://github.com/ZerenZhao)     | 2759260Z |Structure & Control Designer                |
| [Zhuohang Zhang](https://github.com/ZhuohangZhang)| 2752741Z |QR Code Function Designer                |
| [Zeyu Zhang](https://github.com/zeu1)   | 2816269Z |Proposals and Servo management               |


## Social Media

[<img src="https://camo.githubusercontent.com/451c9e00b3f8c9b6c15d4708d9c6293766e9766345a206114a135e4a597847b6/68747470733a2f2f7265732e636c6f7564696e6172792e636f6d2f6478737479337374362f696d6167652f75706c6f61642f76313634393339353835392f626c696e642d6e61762d73797374656d2f69636f6e73382d696e7374616772616d2d34385f6b356b7577692e706e67">](https://www.instagram.com/parcel_sorting_car/)
[<img src="https://camo.githubusercontent.com/e1aebb8e5b3c1fcaf7c9372d909c10dc1fe81b63f88c786ae15e78b65bd961dd/68747470733a2f2f7265732e636c6f7564696e6172792e636f6d2f6478737479337374362f696d6167652f75706c6f61642f76313634393339353835392f626c696e642d6e61762d73797374656d2f69636f6e73382d796f75747562652d34385f6b70616c6c392e706e67">](https://www.youtube.com/channel/UC4p4kkTgzrwiDSgzqwEgowA)
[<img src="https://user-images.githubusercontent.com/56697327/229308058-92dbd6a5-40c9-4143-af38-86583202f425.png">](https://www.facebook.com/profile.php?id=100091941216976)

