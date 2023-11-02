# visionOSC data structure
![](https://github.com/chanulee/cote-bloom/blob/main/appendix/visionOscDatapoints/hero.jpg)
This is datapoint map/guide for faceOSC in LingDong's visionOSC [go to repo](https://github.com/LingDong-/VisionOSC).
- 232 inputs for one face, 461 inputs for two faces.
- Check out the .csv file for the specific datapoint chart.
- The score data: their numbers are 3, 6, 9...
- Buffer 0 data: 0, 1, 2
```
for (int i = 4; i <= 231; i++) {
    if (i % 3 != 0) { // Skip scores: 3, 6, 9, 12, 15, 18...
        int faceData = m.getArgAsInt(i);
        ofLog() << "facedata: " << faceData;
        wekMessage.addIntArg(faceData);
    }
}
```
## 1. Background
- There's datapoint description for poseOSC and handOSC but no enough documentation of faceOSC
- **No information about which data is related to certain part of the face**
- So this map might be helpful for various usecases such as refining relevant data for machine learning or media art
## 2. File structure
- **Modified processing file** that maps out the number of each datapoints on the face [original code at LingDong's repo](https://github.com/LingDong-/VisionOSC/tree/main/demos/VisionOSCProcessingReceiver)
- **csv file** with all the data points
- **screenshot** of wekinator input monitor
---
Chanwoo Lee  
MSc Innovation Design Engineering,  
Imperial College London  
Oct 2023
