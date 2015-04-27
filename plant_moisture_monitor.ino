
typedef struct pot_type_ {
    int yellow;
    int red;
} pot_t;

typedef struct hygrometer_type_ {
    int digital_output;
    int analog_input;
} hygrometer_t;

// configuration
int MINIMUM_MOISTURE_LEVEL = 400;
pot_t POTS[] = {{13, 12}, {11, 10}};
hygrometer_t HYGROMETERS[] = {{7, A1}, {6, A0}};
int CHECK_INTERVAL_MINUTES = 30;

int pot_count = sizeof(POTS) / sizeof(POTS[0]);
int hygrometer_count = sizeof(HYGROMETERS) / sizeof(HYGROMETERS[0]);

void setup() {
  Serial.begin(9600);
  Serial.println("starting");

  for (int i = 0; i < hygrometer_count; i++) {
    pinMode(HYGROMETERS[i].digital_output, OUTPUT);
    digitalWrite(POTS[i].yellow, LOW);
  }

  for (int i = 0; i < pot_count; i++) {
    pinMode(POTS[i].yellow, OUTPUT);
    digitalWrite(POTS[i].yellow, LOW);

    pinMode(POTS[i].red, OUTPUT);
    digitalWrite(POTS[i].red, LOW);
  }
}

void loop() {
  for (int i = 0; i < pot_count; i++) {
    digitalWrite(POTS[i].yellow, HIGH);

    digitalWrite(HYGROMETERS[i].digital_output, HIGH);

    delay(1000);

    int measurement = analogRead(HYGROMETERS[i].analog_input);

    Serial.print("measurement of hygrometer ");
    Serial.print(i);
    Serial.print(" is ");
    Serial.println(measurement);

    if (measurement > MINIMUM_MOISTURE_LEVEL) {
      digitalWrite(POTS[i].red, HIGH);
    } else {
      digitalWrite(POTS[i].red, LOW);
    }

    digitalWrite(HYGROMETERS[i].digital_output, LOW);

    digitalWrite(POTS[i].yellow, LOW);
  }

  Serial.println("sleeping");
  for (int i = 0; i < CHECK_INTERVAL_MINUTES; i++) {
    delay(60 * 1000);
  }
  Serial.println("sleep done");
}
