
typedef struct pottype_ {
    int yellow;
    int red;
} pot_t;

// configuration
int MINIMUM_MOISTURE_LEVEL = 20;
int SLEEP_SECONDS = 30;
pot_t POTS[] = {{10, 11}, {12, 13}};

void setup() {
  // Use 2 moisture sensors (1 per pot)
  // Use 2 red LEDS: one for each pot
  // Use 2 yellow LED to indicate a measurement is in progress for each pot
  // Initially, turn all LEDs off
  int potcount = sizeof(POTS) / sizeof(POTS[0]);
  for (int i = 0; i < potcount; i++) {
    pinMode(POTS[i].yellow, OUTPUT);
    pinMode(POTS[i].red, OUTPUT);
  }
  
  digitalWrite(pot1yellow, LOW);
  */
//  digitalWrite(pot1, LOW);
}

void loop() {
  
//   for each moisture sensor in the pot
//     display measurement indicator (yellow)
//     read the input for 1 second from digital pin
//     if input < MINIMUM_MOISTURE_LEVEL
//       display red LED for the pot
//     else
//       turn off red LED for the pot
//     turn off the measurement indicator (yellow)
  delay(SLEEP_SECONDS * 1000);
}
