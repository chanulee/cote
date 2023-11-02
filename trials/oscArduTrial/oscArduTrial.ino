#include <WiFiUdp.h>
WiFiUDP myUdp;
unsigned int myReceivePort = 12000;
IPAddress mySendIp(127, 0, 0, 1);
unsigned int mySendPort = 7777;

#include <MicroOscUdp.h>
// The number 1024 between the < > below  is the maximum number of bytes reserved for incomming messages.
// Outgoing messages are written directly to the output and do not need more reserved bytes.
MicroOscUdp<1024> myOsc(&myUdp, mySendIp, mySendPort);

void setup() {
  // put your setup code here, to run once:
 myUdp.begin(myReceivePort);
     Serial.begin(9600);
     Serial.println("Serial on");
}

void loop() {
  // put your main code here, to run repeatedly:
  myOsc.onOscMessageReceived( myOscMessageParser );
}

// FUNCTION THAT WILL BE CALLED WHEN AN OSC MESSAGE IS RECEIVED:
void myOscMessageParser( MicroOscMessage& oscMessage) {
   // DO MESSAGE ADDRESS CHECKING AND ARGUMENT GETTING HERE
    Serial.println("parser called");
  // CHECK THE ADDRESS OF THE OSC MESSAGE
  if (oscMessage.checkOscAddress("/wek/outputs")) {
    Serial.println("getting input");
    int red = oscMessage.nextAsInt();
    Serial.println(red);
  
  } else if (oscMessage.checkOscAddress("/address")) {

    // USE THE FOLLOWING METHODS TO PARSE INDIVIDUAL ARGUMENTS :
    /*
      // PARSE AN INT
      int32_t intArgument = receivedOscMessage.nextAsInt();
      // PARSE AN FLOAT
      float floatArgument = receivedOscMessage.nextAsFloat();
      // PARSE AN STRING
      const char * s = receivedOscMessage.nextAsString();
      // PARSE A BLOB
      const uint8_t* blob;
      uint32_t length = receivedOscMessage.nextAsBlob(&blob);
      // PARSE MIDI
      const uint8_t* midi;
      receivedOscMessage.nextAsMidi(&midi);
    */

  }
}


