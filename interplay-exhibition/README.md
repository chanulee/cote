# System Guide for Cote
This system guide is for 
1. Software Setup
2. Hardware Installation
3. Maintenance
## 1. Software Setup for exhibition scenario 
### Essential Softwares
As Cote uses Apple's CoreML for face tracking, it is recommended to use Apple computers for the recreation. (If it's not possible, use faceOSC instead)  
1. Update your macbook and download Xcode. For this exhibition, I'm using macOS Sonoma and Xcode 15.
2. Download wekinator [here](http://www.wekinator.org/downloads/)
3. Download openFrameworks [here](https://openframeworks.cc/download/) and move it to main HD directory
4. Download visionOSC [here](https://github.com/LingDong-/VisionOSC)
### Essential Configurations
1. Download wek2ardu **oF** project from [here](https://github.com/chanulee/cote/tree/d52dcc5865f60ab2a6a312d79a86d98ab8011d35/demonov01), move the entire project to /myApps
2. Download coteClass.ino and upload it to **arduino**
3. Open **visionOSC**, turn off every detection except face detection, check port no 9527 (visionOSC to Wekinator) and save.
4. Connect the **webcam**, change the cammera number to get camera feed - do this every time you set up the system. (Due to refreshing and the fact that the camera number might vary on different system.
5. Open **wekinator**  

| Command | Input | Output |
| --- | --- | --- |
| `port` | 9527 | 12000 (default) |
| `add` | /faces/arr | /wek/outputs (default) |
| `#` | 232 | 1 |
|`description` | visionOSC -> Wek | Wek -> oF, Classifier with 2 classes |
## 2. Hardware Installation
- Macbook Pro 15 + USB-C Charger
- Control Box (arduino and PCA9685 motor driver) + Motor driver power
- Cote Modules * 3
- Webcam (Logitech C270) + USB-A to C Converter
## 3. Maintenance
### Setting up the artwork
Every hardware should be wired
1. Turn on the macbook, hold 'option' until it gets into bootcamp. Select macOS.
2. Open **visionOSC**, **wek2arduDebug**, **wekinator** and **macs fan control**
3. Setting up the webcam: On **visionOSC**, Press "Apply OSC/CAM Settings" button. Webcam's light turns on when successful.
4. In **wekinator**, press CMD+O or File/Open Project... and select interplay1p.wekproj. See if there's 232 inputs and the input light becomes green.
5. On the status bar, open **macs fan control**, set the fan speed to 4500 for both fans
6. Don't close the macbook all the way, it will prevent the heat to vent. Turn down the brightness and gently leave it open about 40 degree.
### End of the day...
1. Close **visionOSC**, **wek2arduDebug** and **wekinator**
2. Turn off the macbook and close it
### In case of...
- Hardware stuck: gently push the stuck part to the position it should be
- Software issue: please contact the creators
---
**InterPlay Exhibition Information**
- Venue: The Royal Society of Sculptors, Dora House 108 Old Brompton Rd, London SW7 3RA
- The Design Education Trust, Royal Society of Sculptors
  
Do you ever stop to reflect how much the design of motion in everyday objects affects your daily routine? Have you ever thought that behind everyday actions there was a creative mind designing the motion?  
Firstly you will encounter a selection of experimental kinetic objects from ‘Cyber Physical Systems’; a workshop of the joint programmes at Imperial College and the Royal College of Art of Innovation Design Engineering and Global Innovation Design. The devices use Arduino computers and Ai software to propose speculative kinetic designs that translate human behaviour into robotic motion.  
The Design Education Trust invites you to delve into a playful experience aiming to lift your spirits in these dour times. Join us between the 5th and 9th December to see our free INTERPLAY EXHIBITION at the ROYAL SOCIETY of SCULPTORS.

---
**Cyber Physical Systems, October-November 2023**    
Advisor Dr. Rebecca Stewart, Charlotte Slingsby, Dr Shayan Sharifi   
MSc Innovation Design Engineering   
Dyson School of Design Engineering, Imperial College London  
  
This module was funded by [Design Education Trust](https://www.designeducationtrust.org.uk/)
