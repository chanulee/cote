# cote
**_What is the value of telepresence if actual presence is neglected?_**  

During the pandemic, people became accustomed to virtual interactions. Driven by this shift, emerging technologies like Virtual Reality are focusing on translating real-world experiences entirely into the digital realm. Meanwhile, face-to-face interactions in the real world are dwindling. As an example, we often observe families in cafes who are each just looking at their smartphone without any conversation. What is the value of telepresence if actual presence is neglected? Tim Cook once said, if you're staring at smartphones more than into people's eyes, you're doing it wrong. We aim to gently promote humane and analog interaction through calm physical interfaces rather than attention-grabbing displays.  
  
In the Korean language, Hangeul, there's a phrase, "대화를 꽃피우다," which translates to 'blooming the conversation.' It's a beautiful term that likens a conversation to a flower.
  
With this ‘côte’ in the room, it can subtly make the space more vibrant and delightful.
## 1. File Directory
- demonov01: For final demo of Cyber Physical Systems module happened in 01 Nov 2023. oF, ino, wek files + recreation guide
- testcode: QC tools made for the project: osc communication, serial communication and motor control
- trials: Tried to develop it part-by-part, some succeeded and some didn't. For future works.
- resources: Images and circuit diagram
- appendix: About visionOSC's face datapoints
## 2. Specimen
### 2-1. Hardware
Check out fritzing file for more information.
- Arduino Nano Every (Arduino Mega 2560)
- Micro Servo MG90S (Black small one) * 6 (5V)
- Logitech C270 (HD 720p, proven to work as a video grabbing webcam) [Amazon](https://www.amazon.co.uk/dp/B01BGBJ8Y0?psc=1&ref=ppx_yo2ov_dt_b_product_details)
- PCA9685 Motor Driver (for power delivery, should be connected to power and arduino)
### 2-2. Software Requirements
- oF ofxOsc
- oF ofxGui (for Motor Testing)
- wekinator
- visionOSC [go to repo](https://github.com/LingDong-/VisionOSC)
- touchDesigner (not yet)
### 2-3. Features
- OSC Communication (visionOSC - wekinator - oF)
- Multiple OSC inputs
- OSC input parsing
- Combine multiple OSC messages and send (trying)
- Serial Communication (oF - Arduino)
- Motor Control
- Higher resolution (room to improve)
- Breathing motion
## 3. visionOSC data structure
Through several experiments with processing and wekinator OSC input monitor, I mapped out datapoints of [LingDong's visionOSC](https://github.com/LingDong-/VisionOSC).  
Check out [visionOscDatapoints folder](https://github.com/chanulee/cote-bloom/tree/main/appendix/visionOscDatapoints)
## 4. Future Works
- visionOSC & TouchDesigner --multiOSC--> oF --modifiedOSC--> wekinator --class--> oF --serial--> Arduino
- If openframeworks gets data directly from OSC not wekinator, we can make some decision before getting to the wekinator part - for example, maybe we can use certain model in certain condition - and we can exclude non-related data from the original OSC so machine learning part would be much more accurate with faster training/learning
- motor angle data 0-254 is mapped to 0-270 and finally about 1000-2000, but I'm still using 0-254 part so the resolution is quite low.
- nothing happens if there's nobody or one person in the cam view, everything stops. maybe we can add breathing motion when nothing is detected
- getting input from multiple addresses works in oF
- Selecting certain relevant OSC messages and then make them into a new message, sending it to wekinator - receiving and making new message kind of works, but the sending timing makes the message's size vary.
- Simple keypressedSerial is working on both Arduino nano and Mega - but servoAngleSerial doesn't work on Mega.
## 5. References
1. ofxOsc OSC Message documentaiton [openframeworks.cc](https://openframeworks.cc/documentation/ofxOsc/ofxOscMessage/)
2. ofxOsc bundling and parsing [forum.openframeworks.cc](https://forum.openframeworks.cc/t/osc-bundle-help/15404)
3. Based on research by H. Segerman [Paper](https://archive.bridgesmathart.org/2022/bridges2022-313.pdf)
## 6. Credits (Teammates)
- Hardware design engineering mainly by Jinhak Lee (IDE 23/25)
- Virtual prototyping, visual design and circuit diagram mainly by Poh Asdathorn (GIDv / Keio Media Design)
---
## Cote for Raspberry Pi
### Hardware
- Raspberry Pi 4 (8GB RAM)
- Arduino Nano Every
- Logitech C270 (HD 720p, proven to work as a video grabbing webcam) [Amazon](https://www.amazon.co.uk/dp/B01BGBJ8Y0?psc=1&ref=ppx_yo2ov_dt_b_product_details)
- 15W USB-C Power Supply
### Software
- 
---
**Cyber Physical Systems, October-November 2023**    
Advisor Dr. Rebecca Stewart, Charlotte Slingsby, Dr Shayan Sharifi   
MSc Innovation Design Engineering   
Dyson School of Design Engineering, Imperial College London  
  
This module was funded by [Design Education Trust](https://www.designeducationtrust.org.uk/)
