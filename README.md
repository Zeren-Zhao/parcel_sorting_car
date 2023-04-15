# Parcel Sorting Car

Replacing the current manual sorting of couriers in warehouses with a 'Parcel Sorting Car'. The courier sorting trolley is a machine trolley that automatically scans QR codes and sorts couriers according to the information. The vehicle continuously scans the QR code with a camera and after analysing the code transports the courier to the designated location and returns back. (The use of other equipment for sorting purposes can also be achieved in some cases and the 'Parcel Sorting Car' can be considered a model for a courier sorting system.)

## Background

With the rapid development of e-commerce business, the courier industry has also become increasingly prosperous. In the development of the courier industry, parcels sorting cars play a vital role. First of all, parcels sorting cars can automatically sort couriers according to their destinations, reducing the time and labor costs of manual operations and improving work efficiency. parcels sorting cars can automatically detect and correct errors during the sorting process, reducing the rate of human-caused sorting errors and improving the accuracy of courier operations and customer satisfaction. With the development of the courier industry, the volume of orders is increasing and the sorting tasks are becoming more and more complex, so the traditional manual sorting method can no longer meet the business needs.

  In summary, the express sorting trolley is an inevitable product of the development of the express industry, with important significance and background. It not only improves work efficiency and accuracy, but also provides support for the modernization and transformation of the express industry and technological innovation.


## Project Description

Our project is to develop a parcel sorting car based on `Raspberry Pi 3B`, which aims to achieve the initial regional sorting of parcels. The project uses a `camera` for QR code recognition, and after it scans the parcel identification code it makes a determination of the area it is going to, and then navigates to the area where the parcel needs to be unloaded based on the coordinates of its current location.The location information will be obtained based on the statistics of the `timer function` build by using select(). After reaching the area, it performs the unloading operation. After the action is executed, it reverts back to the starting point to wait for the next parcel to be scanned.

## Features

- QR code scanning and information extraction： Obtain the infrmation in QR code
- Decision making: Determine destination location based on information
- Navigation of Sorting Car: Navigation based on destination coordinates and starting position coordinates
- Unloading function:Interrupt navigation when you reach your destination and drive servo to perform unloading operations

## Installation

1.Get the update and install the opencv and zbar libraries
```
sudo spt-get update
sudo apt-get install libopencv-dev libzbar-dev
```
2.Compile source files with Cmake
```
mkdir build
cd build
cp /path/to/CMakeLists.txt .

cmake ..

make

./final_try

```
## System Flow Chart
![Image text](https://raw.github.com/Zeren-Zhao/parcel_sorting_car/main/Images/Connection.png)
## Project Contributers



| Name | Student ID | Role |
| -------------- | ---------| -----------|
| [Shiguang Liu](https://github.com/Shiguang2737887?tab=overview&from=2023-01-01&to=2023-01-31)| 2737887L |Decision, Navigation & unloading function Designer | 
| [Zeren Zhao](https://github.com/ZerenZhao)     | 2759260Z |Structure & Control Designer                |
| [Zhuohang Zhang](https://github.com/ZhuohangZhang)| 2752741Z |QR Code Function Designer                |
| [Zeyu Zhang](https://github.com/zeu1)   | 2641089Z |Proposals and procurement management               |


## Social Media

[<img src="https://camo.githubusercontent.com/451c9e00b3f8c9b6c15d4708d9c6293766e9766345a206114a135e4a597847b6/68747470733a2f2f7265732e636c6f7564696e6172792e636f6d2f6478737479337374362f696d6167652f75706c6f61642f76313634393339353835392f626c696e642d6e61762d73797374656d2f69636f6e73382d696e7374616772616d2d34385f6b356b7577692e706e67">](https://www.instagram.com/parcel_sorting_car/)
[<img src="https://camo.githubusercontent.com/e1aebb8e5b3c1fcaf7c9372d909c10dc1fe81b63f88c786ae15e78b65bd961dd/68747470733a2f2f7265732e636c6f7564696e6172792e636f6d2f6478737479337374362f696d6167652f75706c6f61642f76313634393339353835392f626c696e642d6e61762d73797374656d2f69636f6e73382d796f75747562652d34385f6b70616c6c392e706e67">](https://www.youtube.com/channel/UC4p4kkTgzrwiDSgzqwEgowA)
[<img src="https://user-images.githubusercontent.com/56697327/229308058-92dbd6a5-40c9-4143-af38-86583202f425.png">](https://www.facebook.com/profile.php?id=100091941216976)

