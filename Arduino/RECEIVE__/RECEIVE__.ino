#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // set LED pin as output
  digitalWrite(LED_BUILTIN, LOW);    // switch off LED pin
  MIDI.begin(MIDI_CHANNEL_OMNI);             // initialize UART with baud rate of 9600
  MIDI.setHandleNoteOn(MyHandleNoteOn);
  MIDI.setHandleNoteOff(MyHandleNoteOff);
}

void MyHandleNoteOn(byte channel, byte pitch, byte velocity) { 
  // Serial.println("hello");
  // Serial.println(MIDI.getChannel());
  digitalWrite(LED_BUILTIN,HIGH);
  Serial.println(pitch);
  Serial.println(velocity);
}


void MyHandleNoteOff(byte channel, byte pitch, byte velocity) { 
  
  // Serial.println(MIDI.getChannel());
  digitalWrite(LED_BUILTIN,LOW);

}

void loop() {

  MIDI.read();
 
}
