int out1_pin = 14;
int out2_pin = 15;
int out3_pin = 16;
int out4_pin = 17;

void OnNoteOn(byte channel, byte note, byte velocity) {
  Serial.print("OnNoteOn  ");
  Serial.print(channel);
  Serial.print(" ");
  Serial.print(note);
  Serial.print(" ");
  Serial.println(velocity);
  
  if (channel == 1)
    digitalWrite(out1_pin, HIGH);

  else if (channel == 2)
    digitalWrite(out2_pin, HIGH);

  else if (channel == 3)
    digitalWrite(out3_pin, HIGH);

  else if (channel == 4)
    digitalWrite(out4_pin, HIGH);
}

void OnNoteOff(byte channel, byte note, byte velocity) {
  Serial.print("OnNoteOff  ");
  Serial.print(channel);
  Serial.print(" ");
  Serial.print(note);
  Serial.print(" ");
  Serial.println(velocity);
  
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
    Serial.begin(9600);
    pinMode(out1_pin, OUTPUT);
    pinMode(out2_pin, OUTPUT);
    pinMode(out3_pin, OUTPUT);
    pinMode(out4_pin, OUTPUT);
   
    usbMIDI.setHandleNoteOn(OnNoteOn); 
    usbMIDI.setHandleNoteOff(OnNoteOff);
}

void loop()
{
    usbMIDI.read();
}
