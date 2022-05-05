
#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

int out1_pin = 14;
int out2_pin = 15;
int out3_pin = 16;
int out4_pin = 17;

void OnNoteOn(byte channel) {
  Serial.print("OnNoteOn  ch:");
  Serial.println(channel);
  
  if (channel == 1)
    digitalWrite(out1_pin, HIGH);

  else if (channel == 2)
    digitalWrite(out2_pin, HIGH);

  else if (channel == 3)
    digitalWrite(out3_pin, HIGH);

  else if (channel == 4)
    digitalWrite(out4_pin, HIGH);
}

void OnNoteOff(byte channel) {
  Serial.print("OnNoteOff  ch:");
  Serial.println(channel);
  
  if (channel == 1)
    digitalWrite(out1_pin, LOW);

  else if (channel == 2)
    digitalWrite(out2_pin, LOW);

  else if (channel == 3)
    digitalWrite(out3_pin, LOW);

  else if (channel == 4)
    digitalWrite(out4_pin, LOW);
}

// -----------------------------------------------------------------------------

void setup()
{
    MIDI.begin(MIDI_CHANNEL_OMNI);
    Serial.begin(57600);
    Serial.println("MIDI Input Test");
  
    pinMode(out1_pin, OUTPUT);
    pinMode(out2_pin, OUTPUT);
    pinMode(out3_pin, OUTPUT);
    pinMode(out4_pin, OUTPUT);
   
}

unsigned long t=0;

void loop() {
  int type, note, velocity, channel, d1, d2;
  if (MIDI.read()) {                    // Is there a MIDI message incoming ?
    byte type = MIDI.getType();
    switch (type) {
      case midi::NoteOn:
        note = MIDI.getData1();
        velocity = MIDI.getData2();
        channel = MIDI.getChannel();
        if (velocity > 0) {
          Serial.println(String("Note On:  ch=") + channel + ", note=" + note + ", velocity=" + velocity);
          OnNoteOn(channel);
        } else {
          Serial.println(String("Note Off: ch=") + channel + ", note=" + note);
          OnNoteOff(channel);
        }
        break;
      case midi::NoteOff:
        note = MIDI.getData1();
        velocity = MIDI.getData2();
        channel = MIDI.getChannel();
        Serial.println(String("Note Off: ch=") + channel + ", note=" + note + ", velocity=" + velocity);
        OnNoteOff(channel);
        break;
      default:
        d1 = MIDI.getData1();
        d2 = MIDI.getData2();
        Serial.println(String("Message, type=") + type + ", data = " + d1 + " " + d2);
    }
    t = millis();
  }
  if (millis() - t > 10000) {
    t += 10000;
    Serial.println("(inactivity)");
  }
}
