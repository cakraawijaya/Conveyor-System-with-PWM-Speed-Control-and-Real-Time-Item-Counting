[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/IoT-Based-Smart-Conveyor-System-with-PWM-Speed-Control-and-Real-Time-Item-Counting?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-STM8-light.svg?style=flat&logo=STMicroelectronics&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-Personal%20Experiment-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# Automatic Items Counter on STM8-based Conveyor
Automatic items counter is a fast and precise tool for humans to get the sum of items. The purpose of this project is to provide education to the wider community on how to make a simple automatic item counter. This project has been implemented and took approximately 2 weeks. This system is made to be used as a complement to the conveyor. In addition, this system has also provided display and reset features for the needs of its users. The way this system works is that if the items transported by the conveyor are right in front of the laser beam, the light intensity received by the LDR sensor is low, so it is considered that there are items and starts counting. The calculation results will be displayed on the LCD screen. This project will be useful for business people, because it can increase efficiency in production. The results show that this system can function properly.

<br><br>

## Project Requirements
| Part | Description |
| --- | --- |
| Development Board | STM8S103F3P6 |
| Code Editor | Arduino IDE 1.8.19 (Stable Legacy Version) |
| Programmer Tools | ST-Link/V2 |
| Serial Communication Tools | FTDI USB |
| Driver | • ST-Link USB Driver<br>• CDM FTDI USB Driver |
| Communications Protocol | Inter Integrated Circuit (I2C) |
| Programming Language | C/C++ |
| Arduino Library | LiquidCrystal_I2C (default) |
| Sensor | • LDR Sensor Module (x1)<br>• KY-008: Laser Transmitter Module 5V (x1) |
| Display | LCD I2C (x1) |
| Other Components | • Micro USB cable - USB type A (x1)<br>• Mini USB cable - USB type A (x1)<br>• Jumper cable (1 set)<br>• Adaptor DC 5V (x1)<br>• Breadboard (x1)<br>• Push button 12 x 12 mm (x1) |

<br><br>

## Download & Install
1. Arduino IDE

   <table><tr><td width="810">
   
   ```
   https://bit.ly/ArduinoIDE_Installer
   ```

   </td></tr></table><br>

2. ST-Link USB Driver

   <table><tr><td width="810">
   
   ```
   https://bit.ly/STLink_USBdriver
   ```

   </td></tr></table><br>
   
3. CDM FTDI USB Driver

   <table><tr><td width="810">
   
   ```
   https://bit.ly/CDM_FTDI_USBdriver
   ```

   </td></tr></table>
   
<br><br>

## Project Designs
<table>
<tr>
<th width="420">Block Diagram</th>
<th width="420">Pictorial Diagram</th>
</tr>
<tr>
<td><img src="Assets/Documentation/Diagram/Block Diagram.jpg" alt="block-diagram"></td>
<td><img src="Assets/Documentation/Diagram/Pictorial Diagram.jpg" alt="pictorial-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Wiring</th>
</tr>
<tr>
<td><img width="840" src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Scanning the I2C Address on the LCD
<table><tr><td width="840">

```ino
/*
  =====================================================
  I2C Scanner for STM8S103F3P6
  by: Devan Cakra Mudra Wijaya, S.Kom.
  =====================================================

  Functions:
  - Detects all connected I2C devices
  - Displays device addresses in HEX format
  - Displays the total number of detected devices


  =====================================================
  SDA and SCL Pins for STM8S103F3P6
  =====================================================
  SDA -> PB5
  SCL -> PB4
*/

// Include the I2C library for I2C communication
#include "I2C.h"

// Constant that defines the delay between scans (5000 ms = 5 seconds)
const uint16_t SCAN_INTERVAL = 5000;


// The setup() function runs once when the board is powered on or reset
// It is used to initialize hardware, serial communication, sensors, modules, and the program's initial configuration
void setup() {

  // Start Serial communication at 9600 baud rate
  Serial_begin(9600);

  // Wait for 5 seconds before starting the program
  delay(5000);

  // Display program header
  Serial_println_s("====================================");
  Serial_println_s("         I2C DEVICE SCANNER         ");
  Serial_println_s("by: Devan Cakra Mudra Wijaya, S.Kom.");
  Serial_println_s("====================================");

  // Print an empty line
  Serial_println_s("");

  // Initialize I2C communication
  I2C_begin();
}


// The loop() function runs continuously after setup() has finished
// The main program logic is typically placed inside this function
void loop() {

  // Variable to store the error code returned from I2C communication
  uint8_t error;

  // Variable to store the I2C address currently being checked
  uint8_t address;

  // Counter variable for the number of detected devices
  uint8_t deviceCount = 0;

  // Display information indicating that the scan process has started
  Serial_println_s("------------------------------------");
  Serial_println_s("Scanning I2C bus...");
  Serial_println_s("------------------------------------");

  // Loop through addresses from 1 to 126
  // Valid I2C addresses range from 0x01 to 0x7E
  for (address = 1; address < 127; address++) {

    // Perform I2C write transaction (STM8 I2C driver)
    // Used to test ACK response from device
    // Error code depends on I2C driver implementation
    error = I2C_write(address, 0x00);

    // If no error occurs:
    if (error == 0) {

      // Display information that a device was found
      Serial_print_s("[FOUND] Device at address 0x");

      // If the address is less than 16:
      // Add a leading zero to keep HEX formatting aligned
      if (address < 16) {
        Serial_print_s("0");
      }

      // Display the address in HEX format
      Serial_print_ub(address, HEX);
      Serial_println_s("");

      // Increment the detected device count
      deviceCount++;
    }

    // If an unknown error occurs:
    else if (error == 4) {

      // Display an error message
      Serial_print_s("[ERROR] Unknown error at address 0x");

      // If the address is less than 16:
      // Add a leading zero to keep HEX formatting aligned
      if (address < 16) {
        Serial_print_s("0");
      }

      // Display the problematic address in HEX format
      Serial_print_ub(address, HEX);
      Serial_println_s("");
    }

    // If the error is neither 0 nor 4:
    // Ignore it, as this usually means no device exists at that address
  }

  // Print an empty line
  Serial_println_s("");

  // If no devices were found:
  if (deviceCount == 0) {

    // Display a message indicating that no devices were found
    Serial_println_s("No I2C devices found.");
  }
  else { // If at least one device was found:

    // Display the total number of detected devices
    Serial_print_s("Total devices found: ");

    // Display the value of deviceCount
    Serial_print_ub(deviceCount, DEC);
    Serial_println_s("");
  }

  // Display information about the next scan
  Serial_print_s("Next scan in ");

  // Convert milliseconds to seconds
  Serial_print_ub(SCAN_INTERVAL / 1000, DEC);

  // Display the unit in seconds
  Serial_println_s(" seconds.");

  // Empty line
  Serial_println_s("\n");

  // Wait 5 seconds before performing the next scan
  delay(SCAN_INTERVAL);
}
```

</td></tr></table><br><br>

## Arduino IDE Setup
1. Open the ``` Arduino IDE ``` first, then open this project by clicking ``` File ``` -> ``` Open ``` :

   <table><tr><td width="810">
   
      ``` auto_counter.ino ```

   </td></tr></table><br>
   
2. Fill in the ``` Additional Board Manager URLs ``` in Arduino IDE

   <table><tr><td width="810">
      
      Click ``` File ``` -> ``` Preferences ``` -> enter the ``` Boards Manager Url ``` by copying the following link :
   
      ```
      https://raw.githubusercontent.com/tenbaht/sduino/master/package_sduino_stm8_index.json
      ```

   </td></tr></table><br>
   
3. ``` Board Setup ``` in Arduino IDE

   <table>
      <tr><th width="810">

      How to setup the ``` STM8S103F3P6 ``` board
            
      </th></tr>
      <tr><td width="810">

      • Click ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Install ``` Sduino STM8 plain C core (non-C++) ```.

      • Then selecting a board by clicking: ``` Tools ``` -> ``` Board ``` -> ``` STM8S Boards ``` -> ``` STM8S103F3 Breakout Board ```.
            
      </td></tr>
   </table><br>
   
4. ``` Change Programmer ``` in Arduino IDE

   <table><tr><td width="810">
      
   Click ``` Tools ``` -> ``` Programmer ``` -> ``` ST-Link/V2 ```

   </td></tr></table><br>
   
5. Before uploading the program please click: ``` Verify ```.<br><br>

6. If there is no error in the program code, the next step is to use the ``` STM8 ``` programming tool according to the procedure. Then click: ``` Upload ```.<br><br>

7. If there is still a problem when uploading the program, then try checking the ``` driver ``` / ``` port ``` / ``` programmer tool ``` / ``` others ``` section.

<br><br>

## ST-Link/V2 Setup
<img width="840" src="Assets/Documentation/Experiment/ST-Link Configuration.jpg" alt="stlink-configuration"><br><br>

<h3><img src="https://github.com/user-attachments/assets/932b96eb-cbc7-42f1-8938-43cb431889a5" width="16" height="16"> Notes :</h3>
<blockquote>
   <ul>
   <li>
   
   The single wire interface module or ``` SWIM ``` is basically used to communicate with the ``` STM8 ``` board.

   </li>
   <li>
   
   You can see the wiring between the ``` ST-Link/V2 ``` and the ``` STM8 ``` board in detail in the picture above.
   
   </li>
   <li>
   
   Based on personal experience, the ``` STM8 ``` can only be programmed with ``` ST-Link ```.
   
   </li>
   </ul>
</blockquote>

<br><br>

## FTDI USB Setup
<img width="840" src="Assets/Documentation/Experiment/FTDI Configuration.jpg" alt="ftdi-configuration"><br><br>

<h3><img src="https://github.com/user-attachments/assets/932b96eb-cbc7-42f1-8938-43cb431889a5" width="16" height="16"> Notes :</h3>
<blockquote>
   <ul>
   <li>
   
   Serial communication on this ``` STM8 ``` board is very possible, especially for ``` Serial Monitor ``` and ``` Serial Plotter ``` purposes. Tools that can be used for serial communication include: ``` CP2102 USB ```, ``` CH340 USB ```, ``` FTDI USB ```, or with ``` PL2303 USB ```.

   </li>
   <li>
   
   You can see the wiring between the ``` FTDI USB ``` and the ``` STM8 ``` board in detail in the picture above.
   
   </li>
   <li>
   
   Based on experience, I admit that using ``` FTDI USB ``` or ``` CP2102 USB ``` is much better than ``` PL2303 USB ``` or ``` CH340 USB ``` because they are known to be more stable in performance.
   
   </li>
   </ul>
</blockquote>

<br><br>

## Removing write protection on STM8
The write protection on the ``` STM8 ``` can be removed through several steps, among others :<br><br>
1. Connect the ``` STM8 ``` to the ``` ST-Link/V2 ```, then connect the ``` ST-Link/V2 ``` to a PC or laptop.<br><br>

2. Open ``` CMD (Command Prompt) ```.<br><br>

3. Enter into the directory :

   <table><tr><td width="810">
      
      ``` C:\Users\[Computer Name]\AppData\Local\Arduino15\packages\sduino\tools\STM8Tools\2019.02.05\win ```

   </td></tr></table><br>

4. Input the command:

   <table><tr><td width="810">
      
      ```
      stm8flash -cstlinkv2 -pstm8s103?3 -u
      ```

   </td></tr></table><br>
   
5. Press ``` Enter ```, then you can see the result as the picture below.
   
   <img width="810" height="250" src="Assets/Documentation/Experiment/Remove Protection STM8.jpg" alt="rmv-protection">

<br><br>

## Get Started
1. Download and extract this repository.<br><br>
   
2. Make sure you have the necessary electronic components.<br><br>
   
3. Make sure your components are designed according to the diagram.<br><br>
   
4. Configure your device according to the settings above.<br><br>

5. Please enjoy [Done].

<br><br>

## Highlights
<img width="840" src="Assets/Documentation/Experiment/Device.jpg" alt="auto-items-counter">

<br><br>

## Appreciation
If this work is useful to you, then support this work as a form of appreciation to the author by clicking the ``` ⭐Star ``` button at the top of the repository.

<br><br>

## Disclaimer
This application is my own work and is not the result of plagiarism from other people's research or work, except those related to third party services which include: libraries, frameworks, and so on.

<br><br>

## LICENSE
MIT License - Copyright © 2026 - Devan C. M. Wijaya, S.Kom

Permission is hereby granted without charge to any person obtaining a copy of this software and the software-related documentation files to deal in them without restriction, including without limitation the right to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons receiving the Software to be furnished therewith on the following terms:

The above copyright notice and this permission notice must accompany all copies or substantial portions of the Software.

IN ANY EVENT, THE AUTHOR OR COPYRIGHT HOLDER HEREIN RETAINS FULL OWNERSHIP RIGHTS. THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, THEREFORE IF ANY DAMAGE, LOSS, OR OTHERWISE ARISES FROM THE USE OR OTHER DEALINGS IN THE SOFTWARE, THE AUTHOR OR COPYRIGHT HOLDER SHALL NOT BE LIABLE, AS THE USE OF THE SOFTWARE IS NOT COMPELLED AT ALL, SO THE RISK IS YOUR OWN.