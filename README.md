# Parcel Sorting Car

Replacing the current manual sorting of couriers in warehouses with a 'Parcel Sorting Car'. The courier sorting trolley is a machine trolley that automatically scans QR codes and sorts couriers according to the information. The vehicle continuously scans the QR code with a camera and after analysing the code transports the courier to the designated location and returns back. (The use of other equipment for sorting purposes can also be achieved in some cases and the 'Parcel Sorting Car' can be considered a model for a courier sorting system.)

## Background

With the rapid development of e-commerce business, the courier industry has also become increasingly prosperous. In the development of the courier industry, parcels sorting cars play a vital role. First of all, parcels sorting cars can automatically sort couriers according to their destinations, reducing the time and labor costs of manual operations and improving work efficiency. parcels sorting cars can automatically detect and correct errors during the sorting process, reducing the rate of human-caused sorting errors and improving the accuracy of courier operations and customer satisfaction. With the development of the courier industry, the volume of orders is increasing and the sorting tasks are becoming more and more complex, so the traditional manual sorting method can no longer meet the business needs.

  In summary, the express sorting trolley is an inevitable product of the development of the express industry, with important significance and background. It not only improves work efficiency and accuracy, but also provides support for the modernization and transformation of the express industry and technological innovation.


## Project Description

Our project is to develop a parcel sorting car based on `Raspberry Pi 3B`, which aims to achieve the initial regional sorting of parcels. The project uses a `camera` for QR code recognition, and after it scans the parcel identification code it makes a determination of the area it is going to, and then navigates to the area where the parcel needs to be unloaded based on the coordinates of its current location.The location information will be obtained based on the statistics of the `timer threads`. After reaching the area, it performs the unloading operation. After the action is executed, it reverts back to the starting point to wait for the next parcel to be scanned.

## Features

- QR code scanning and information extraction： Obtain the infrmation in QR code
- Decision making: Determine destination location based on information
- Navigation of Sorting Car: Navigation based on destination coordinates and starting position coordinates
- Unloading function:Interrupt navigation when you reach your destination and drive servo to perform unloading operations

## Installation

```
graph TD
    A[Scan] -->B(Go Shopping)

```

### Enviromental Check
```
sudo spt-get update
sudo apt-get install libopencv-dev libzbar-dev
```
## System Flow Chart

## Project Contributers
<div align="center">

| Name | Student ID | Role |
| -------------- | ---------| -----------|
| [Click here](https://github.com/Shiguang2737887?tab=overview&from=2023-01-01&to=2023-01-31"){:title="Shiguang Liu" target="_blank"}
   | 2737887L |Decision, Navigation & unloading function Designer | 
| Zeren Zhao     | 2759260Z |Structure & Control Designer                       |
| Zhuohang Zhang | 2752741Z |QR Code Function Designer                          |
| Zeyu Zhang     | 2641089Z |Proposals and procurement management               |

</div>
