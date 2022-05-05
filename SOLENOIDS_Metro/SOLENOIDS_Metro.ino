#include <Metro.h> // Include Metro library
//
Metro metro1 = Metro(250); 
Metro metro2 = Metro(250); 
Metro metro3 = Metro(250); 
Metro metro4 = Metro(250); 
//
int solenoid_delay = 25;
//
int analog1, analogMap1;
int analog2, analogMap2;
int analog3, analogMap3;
int analog4, analogMap4;
//
int out1_pin = 6;
int out2_pin = 7;
int out3_pin = 8;
int out4_pin = 9;
//
int toogle1_pin = 5;
int toogle2_pin = 4;
int toogle3_pin = 3;
int toogle4_pin = 2;
//
void setup() {
  Serial.begin(9600);
  //
  pinMode(out1_pin, OUTPUT);
  pinMode(out2_pin, OUTPUT);
  pinMode(out3_pin, OUTPUT);
  pinMode(out4_pin, OUTPUT);
  //
  pinMode(toogle1_pin, INPUT);
  pinMode(toogle2_pin, INPUT);
  pinMode(toogle3_pin, INPUT);
  pinMode(toogle4_pin, INPUT);
}
//
void loop() {
  analog1 = analogRead(0);
  analogMap1 = map(analog1, 0, 1024, 10, 3000);
  analog2 = analogRead(1);
  analogMap2 = map(analog2, 0, 1024, 10, 3000);
  analog3 = analogRead(2);
  analogMap3 = map(analog3, 0, 1024, 10, 3000);
  analog4 = analogRead(3);
  analogMap4 = map(analog4, 0, 1024, 10, 3000);

  /*
  Serial.print(digitalRead(toogle1_pin));
  Serial.print("  ");
  Serial.print(digitalRead(toogle2_pin));
  Serial.print("  ");
  Serial.print(digitalRead(toogle3_pin));
  Serial.print("  ");
  Serial.print(digitalRead(toogle4_pin));
  Serial.print(" // ");
  Serial.print(" // ");
  Serial.print(analog1);
  Serial.print("  ");
  Serial.print(analog2);
  Serial.print("  ");
  Serial.print(analog3);
  Serial.print("  ");
  Serial.print(analog4);
  Serial.print(" // ");
  Serial.print(analogMap1);
  Serial.print("  ");
  Serial.print(analogMap2);
  Serial.print("  ");
  Serial.print(analogMap3);
  Serial.print("  ");
  Serial.print(analogMap4);
  Serial.println();
  */
  
  
  
  if (metro1.check() == 1) { 
    solenoid1();
    metro1.interval(analogMap1);
    metro1.reset();
  }
  if (metro2.check() == 1) { 
    solenoid2();
    metro2.interval(analogMap2);
    metro2.reset();
  }
  if (metro3.check() == 1) { 
    solenoid3();
    metro3.interval(analogMap3);
    metro3.reset();
  }
  if (metro4.check() == 1) { 
    solenoid4();
    metro4.interval(analogMap4);
    metro4.reset();
  }
}
//
void solenoid1()
{
  digitalWrite(out1_pin, HIGH);
  delay(solenoid_delay);
  digitalWrite(out1_pin, LOW);
}

void solenoid2()
{
  digitalWrite(out2_pin, HIGH);
  delay(solenoid_delay);
  digitalWrite(out2_pin, LOW);
}

void solenoid3()
{
  digitalWrite(out3_pin, HIGH);
  delay(solenoid_delay);
  digitalWrite(out3_pin, LOW);
}
void solenoid4()
{
  digitalWrite(out4_pin, HIGH);
  delay(solenoid_delay);
  digitalWrite(out4_pin, LOW);
}

/**/
