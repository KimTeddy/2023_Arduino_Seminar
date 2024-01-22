
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
void setup() {
  tone(8, NOTE_C4); delay(500); 
  tone(8, NOTE_D4); delay(500); 
  tone(8, NOTE_E4); delay(500); 
  tone(8, NOTE_F4); delay(500); 
  tone(8, NOTE_G4); delay(500); 
  noTone(8);
}

void loop() {
}
