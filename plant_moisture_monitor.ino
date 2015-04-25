
typedef struct pottype_ {
    int yellow;
    int red;
} pot_t;

// configuration
int MINIMUM_MOISTURE_LEVEL = 20;
int SLEEP_SECONDS = 30;
pot_t POTS[] = {{10, 11}, {12, 13}};

int potcount = sizeof(POTS) / sizeof(POTS[0]);

void setup() {
  for (int i = 0; i < potcount; i++) {
    pinMode(POTS[i].yellow, OUTPUT);
    digitalWrite(POTS[i].yellow, LOW);

    pinMode(POTS[i].red, OUTPUT);
    digitalWrite(POTS[i].red, LOW);
  }
}

void loop() {
  for (int i = 0; i < potcount; i++) {
    digitalWrite(POTS[i].yellow, HIGH);
    delay(1000); // remove after adding real measurement code
    int measurement = 20;
    if (measurement < MINIMUM_MOISTURE_LEVEL) {
      digitalWrite(POTS[i].red, HIGH);
    } else {
      digitalWrite(POTS[i].red, LOW);
    }
    digitalWrite(POTS[i].yellow, LOW);
  }
  delay(SLEEP_SECONDS * 1000);
}
