[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/Conveyor-with-PWM-Speed-and-Item-Counting?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-Arduino-light.svg?style=flat&logo=arduino&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-Personal%20Experiment-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# Arduino Pro Mini-based Conveyor Motor Speed Control System using PWM Method
Conveyor is a mechanical system used to move goods or materials from one place to another that is carried out continuously. The purpose of this project is to provide education to the wider community on how to make a simple mini conveyor. This project has been implemented and takes approximately 1 week. To adjust how fast the conveyor machine can move, you can use a potentiometer. To change the direction of movement of the conveyor machine as well as stop it, you can use a push button. The benefit of making this project is none other than to add insight. The results show that this system can function properly.

<br><br>

## Project Requirements
| Part | Description |
| --- | --- |
| Development Board | Arduino Pro Mini |
| Code Editor | Arduino IDE 1.8.19 (Stable Legacy Version) |
| Programmer Tools | PL2303 USB |
| Driver | PL2303 USB Driver |
| Programming Language | C/C++ |
| Actuators | Gear Motor / Motor DC (x1) |
| Other Components | • Jumper cable (1 set)<br>• Adaptor DC 12V 2A (x1)<br>• Motor driver L298N (x1)<br>• Breadboard (x1)<br>• Potentiometer (x1)<br>• Push button 12 x 12 mm (x2)<br>• PVC Sheets 3 mm 10 x 50 cm (x5)<br>• Stainless Steel Concrete 30 cm (x1)<br>• Bearing Pillow Block 6 mm (x3)<br>• 1/2 Inch Pipe 25 cm (x2)<br>• Oscar fabric 50 x 137 cm (x1)<br>• Wood stickers (1 set)<br>• Bolts plus (1 set)<br>• Nuts (1 set)<br>• L Bracket (1 set)<br>• PVC Electrical insulation (1 set)<br>• Sandpaper G-180 1 m (x1)<br>• Smart Car Rims (x1) |

<br><br>

## Download & Install
1. Arduino IDE 

   <table><tr><td width="810">

   ```
   https://bit.ly/ArduinoIDE_Installer
   ```

   </td></tr></table><br>

2. PL2303 USB Driver

   <table><tr><td width="810">
   
   ```
   https://bit.ly/PL2303P_USBdriver
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
<td><img src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Arduino IDE Setup
1. Open the ``` Arduino IDE ``` first, then open this project by clicking ``` File ``` -> ``` Open ``` : 

   <table><tr><td width="810">
   
      ``` pwm_conveyor.ino ```

   </td></tr></table><br>
   
2. ``` Board Setup ``` in Arduino IDE

   <table>
      <tr><th width="810">

      How to setup the ``` Arduino Pro Mini ``` board
            
      </th></tr>
      <tr><td width="810">
      
      Select a board by clicking: ``` Tools ``` -> ``` Board ``` -> ``` Arduino AVR Boards ``` -> ``` Arduino Pro or Pro Mini ```

      </td></tr>
   </table><br>

3. ``` Change Processor ``` in Arduino IDE

   <table><tr><td width="810">
      
      Click ``` Tools ``` -> ``` Processor ``` -> ``` ATmega328P (5V, 16 MHz) ```

   </td></tr></table><br>

4. ``` Port Setup ``` in Arduino IDE

   <table><tr><td width="810">
      
      Click ``` Port ``` -> Choose according to your device port ``` (you can see in device manager) ```

   </td></tr></table><br>

5. Before uploading the program please click: ``` Verify ```.<br><br>

6. If there is no error in the program code, then please click: ``` Upload ```.<br><br>

7. Some things you need to do when using the ``` Arduino Pro Mini board ``` with ``` PL2303 USB ``` :

   <table><tr><td width="810">

      • ``` Arduino IDE ``` information: ``` Uploading... ``` -> immediately press the ``` RESET ``` button and release it.
      
      • Wait until the message appears: ```Done Uploading ``` -> ```The program is directly operated ```.

   </td></tr></table><br>

8. If there is still a problem when uploading the program, then try checking the ``` driver ``` / ``` port ``` / ``` others ``` section.

<br><br>

## PL2303 USB Setup
<img width="840" src="Assets/Documentation/Experiment/PL2303 Configuration.jpg" alt="pl2303-configuration"><br><br>

<h3><img src="https://github.com/user-attachments/assets/932b96eb-cbc7-42f1-8938-43cb431889a5" width="16" height="16"> Notes :</h3>
<blockquote>
   <ul>
   <li>
   
   This ``` Arduino Pro Mini ``` is not equipped with a ``` USB port ```, so you need an additional device in the form of a ``` USB to TTL Serial ``` to connect to a laptop or PC. ``` USB to TTL Serial ``` like the ``` PL2303 USB ``` is commonly used as an intermediate medium for uploading programs.
   
   </li>
   <li>
   
   You can see the wiring between the ``` PL2303 USB ``` and the ``` Arduino Pro Mini ``` board in the picture above.
   
   </li>
   <li>
   
   To upload a program, in addition to using the ``` PL2303 USB ```, you can also use other programming tools such as: ``` CP2102 USB ```, ``` CH340 USB ```, or with ``` FTDI USB ```. Based on experience, I admit that using ``` FTDI USB ``` or ``` CP2102 USB ``` is much better than ``` PL2303 USB ``` or ``` CH340 USB ``` because they are known to be more stable in performance.
   
   </li>
   </ul>
</blockquote>

<br><br>

## Get Started
1. Download and extract this repository.<br><br>
   
2. Make sure you have the necessary electronic components.<br><br>
   
3. Make sure your components are designed according to the diagram.<br><br>
   
4. Configure your device according to the settings above.<br><br>

5. Please enjoy [Done].

<br><br>

## Appreciation
If this work is useful to you, then support this work as a form of appreciation to the author by clicking the ``` ⭐Star ``` button at the top of the repository.

<br><br>

## LICENSE
MIT License - Copyright © 2026 - Devan C. M. Wijaya, S.Kom

Permission is hereby granted without charge to any person obtaining a copy of this software and the software-related documentation files to deal in them without restriction, including without limitation the right to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons receiving the Software to be furnished therewith on the following terms:

The above copyright notice and this permission notice must accompany all copies or substantial portions of the Software.

IN ANY EVENT, THE AUTHOR OR COPYRIGHT HOLDER HEREIN RETAINS FULL OWNERSHIP RIGHTS. THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, THEREFORE IF ANY DAMAGE, LOSS, OR OTHERWISE ARISES FROM THE USE OR OTHER DEALINGS IN THE SOFTWARE, THE AUTHOR OR COPYRIGHT HOLDER SHALL NOT BE LIABLE, AS THE USE OF THE SOFTWARE IS NOT COMPELLED AT ALL, SO THE RISK IS YOUR OWN.