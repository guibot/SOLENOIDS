#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

int out1_pin = 6;
int out2_pin = 7;
int out3_pin = 8;
int out4_pin = 9;

// -----------------------------------------------------------------------------

// This function will be automatically called when a NoteOn is received.
// It must be a void-returning function with the correct parameters,
// see documentation here:
// https://github.com/FortySevenEffects/arduino_midi_library/wiki/Using-Callbacks

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
    // Do whatever you want when a note is pressed.

    // Try to keep your callbacks short (no delays ect)
    // otherwise it would slow down the loop() and have a bad impact
    // on real-time performance.

  if (channel == 1)
    digitalWrite(out1_pin, HIGH);

  else if (channel == 2)
    digitalWrite(out2_pin, HIGH);

  else if (channel == 3)
    digitalWrite(out3_pin, HIGH);

  else if (channel == 4)
    digitalWrite(out4_pin, HIGH);
  
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
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
    pinMode(out1_pin, OUTPUT);
    pinMode(out2_pin, OUTPUT);
    pinMode(out3_pin, OUTPUT);
    pinMode(out4_pin, OUTPUT);
    //MIDI.turnThruOff();
    // Connect the handleNoteOn function to the library,
    // so it is called upon reception of a NoteOn.
    MIDI.setHandleNoteOn(handleNoteOn);  // Put only the name of the function

    // Do the same for NoteOffs
    MIDI.setHandleNoteOff(handleNoteOff);

    // Initiate MIDI communications, listen to all channels
    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
    // Call MIDI.read the fastest you can for real-time performance.
    MIDI.read();

    // There is no need to check if there are messages incoming
    // if they are bound to a Callback function.
    // The attached method will be called automatically
    // when the corresponding message has been received.
}
