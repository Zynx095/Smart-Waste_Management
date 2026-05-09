#define TRIG_PIN 5
#define ECHO_PIN 18

long duration;
float distance;

void setup() {
    Serial.begin(115200);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    Serial.println("Smart Waste Management System Started");
}

void loop() {

    // Clear trigger
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Send pulse
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read echo
    duration = pulseIn(ECHO_PIN, HIGH);

    // Calculate distance
    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Waste Level Logic
    if(distance < 10) {
        Serial.println("Bin Status: FULL");
    }
    else if(distance < 20) {
        Serial.println("Bin Status: MEDIUM");
    }
    else {
        Serial.println("Bin Status: EMPTY");
    }

    Serial.println("----------------------");

    delay(2000);
}
