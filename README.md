# cote-bloom
**_What is the value of telepresence if actual presence is neglected?_**  

During the pandemic, people became accustomed to virtual interactions. Driven by this shift, emerging technologies like Virtual Reality are focusing on translating real-world experiences entirely into the digital realm. Meanwhile, face-to-face interactions in the real world are dwindling. As an example, we often observe families in cafes who are each just looking at their smartphone without any conversation. What is the value of telepresence if actual presence is neglected? Tim Cook once said, if you're staring at smartphones more than into people's eyes, you're doing it wrong. We aim to gently promote humane and analog interaction through calm physical interfaces rather than attention-grabbing displays.  
  
In the Korean language, Hangeul, there's a phrase, "대화를 꽃피우다," which translates to 'blooming the conversation.' It's a beautiful term that likens a conversation to a flower.
  
With this ‘côte’ in the room, it can subtly make the space more vibrant and delightful.
## 1. Features
- OSC Communication (visionOSC - oF - wekinator - oF)
- Multiple OSC inputs
- OSC input parsing
- Serial Communication (oF - Arduino)
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
### 2-2. Software Requirements
- oF ofxOsc
- oF ofxGui (for Motor Testing)
- wekinator
- visionOSC [go to repo](https://github.com/LingDong-/VisionOSC)
- touchDesigner
## 3. visionOSC data structure
Through several experiments with processing and wekinator OSC input monitor, I mapped out datapoints of [LingDong's visionOSC](https://github.com/LingDong-/VisionOSC).  
Check out [visionOscDatapoints folder]()
## 4. References
1. ofxOsc OSC Message documentaiton [openframeworks.cc](https://openframeworks.cc/documentation/ofxOsc/ofxOscMessage/)
2. ofxOsc bundling and parsing [forum.openframeworks.cc](https://forum.openframeworks.cc/t/osc-bundle-help/15404)
3. Based on mechanical Design by H. Segerman [Paper](https://archive.bridgesmathart.org/2022/bridges2022-313.pdf)
## 5. Memo / Trial & Error
- Do not build oF app when arduino Serial Monitor is on! Upload arduino -> Run oF -> Open arduino Serial Monitor
## 6. Credits (Teammates)
- Hardware design engineering mainly by Jinhak Lee (IDE 23/25)
- Virtual prototyping and visual design mainly by Poh Asdathorn (GIDv / Keio Media Design)
---
**Cyber Physical Systems, October-November 2023**    
Advisor Dr. Rebecca Stewart, Charlotte Slingsby, Dr Shayan Sharifi   
MSc Innovation Design Engineering   
Dyson School of Design Engineering, Imperial College London  
  
This module was funded by [Design Education Trust](https://www.designeducationtrust.org.uk/)
