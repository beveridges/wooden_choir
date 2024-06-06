#include <MIDI.h>
#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h>

struct Serial2MIDISettings : public midi::DefaultSettings
{
  static const long BaudRate = 9600;
  static const int8_t RxPin  = 20;
  static const int8_t TxPin  = 21;
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial0, DIN_MIDI, Serial2MIDISettings);
BLEMIDI_CREATE_DEFAULT_INSTANCE()

unsigned long t0 = millis();
bool isConnected = false;


void setup() {

  Serial.begin(115200);
  DIN_MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.begin();
  
  pinMode(LED_BUILTIN, OUTPUT);     // set LED pin as output
  digitalWrite(LED_BUILTIN, LOW);  //onboard LED, LOW);    // switch off LED pin

  BLEMIDI.setHandleConnected([]() {
    isConnected = true;
    Serial.println("---------CONNECTED---------");
    digitalWrite(LED_BUILTIN, HIGH);
  });

  BLEMIDI.setHandleDisconnected([]() {
    isConnected = false;
    Serial.println("-----NOT CONNECTED---------");
    digitalWrite(LED_BUILTIN, LOW);
  });
  
  MIDI.setHandleNoteOn([](byte channel, byte note, byte velocity) {
    Serial.print("NoteON: CH: ");
    digitalWrite(LED_BUILTIN, LOW);
  });

  MIDI.setHandleNoteOff([](byte channel, byte note, byte velocity) {
    digitalWrite(LED_BUILTIN, HIGH);
  });


}
void loop() {

   MIDI.read();
  // Serial0.print('1');
  // delay(1000);
  // Serial0.print('0');
  // delay(700);
  // DIN_MIDI.sendNoteOn(60, 127, 1);
  // delay(3000);
  // DIN_MIDI.sendNoteOff(60, 127, 1);
  // delay(300);

}