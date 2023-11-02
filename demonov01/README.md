# Full Demo Set for cote - 01 Nov
## 1. Working Features
- visionOSC --OSC--> Wekinator --OSC--> oF --Serial--> Arduino
- Motor Control
- Higher resolution
- Mapping
- Breathing motion
- Blooming motion
## 2. Specimen
### 2-1. Hardware
Check out fritzing file for more information.
- Arduino Nano Every (Arduino Mega 2560)
- Micro Servo MG90S (Black small one) * 6 (5V)
- Logitech C270 (HD 720p, proven to work as a video grabbing webcam) [Amazon](https://www.amazon.co.uk/dp/B01BGBJ8Y0?psc=1&ref=ppx_yo2ov_dt_b_product_details)
- PCA9685 Motor Driver (for power delivery, should be connected to power and arduino)
### 2-2. Files Description
- cote2people: wekinator model (Neural Network) that determines if two people are standing still(1) or in  face-to-face(2)
- wek2ardu: oF app that gets OSC data from wekinator(1 or 2) and send it to arduino as serial message
- coteClass: Arduino file for getting the wekinator class
## 3. Recreate the Demo
1. Open **visionOSC**, connect Logitech C270, set CAM 1 and press 'Apply' and see if video grabbing is working (default output PORT 9527, address /faces/arr, 461 inputs for 2 faces)
2. Open **wekinator** app, open(CMD+O) a machine learning model cote2people, press 'Start Listening' and see if the data input is working, and 'Run' 
3. Open **Arduino** app, open coteClass.ino and upload it to arduino nano
4. Open **wek2ardu.xcodepro**, check if the arduino serial monitor is closed, and then build it
## 4. Future Works
- visionOSC & TouchDesigner --multiOSC--> oF --modifiedOSC--> wekinator --class--> oF --serial--> Arduino
- If openframeworks gets data directly from OSC not wekinator, we can make some decision before getting to the wekinator part - for example, maybe we can use certain model in certain condition - and we can exclude non-related data from the original OSC so machine learning part would be much more accurate with faster training/learning
- motor angle data 0-254 is mapped to 0-270 and finally about 1000-2000, but I'm still using 0-254 part so the resolution is quite low.
- nothing happens if there's nobody or one person in the cam view, everything stops. maybe we can add breathing motion when nothing is detected 
---
**Cyber Physical Systems, October-November 2023**    
Advisor Dr. Rebecca Stewart, Charlotte Slingsby, Dr Shayan Sharifi   
MSc Innovation Design Engineering   
Dyson School of Design Engineering, Imperial College London  
  
This module was funded by [Design Education Trust](https://www.designeducationtrust.org.uk/)
