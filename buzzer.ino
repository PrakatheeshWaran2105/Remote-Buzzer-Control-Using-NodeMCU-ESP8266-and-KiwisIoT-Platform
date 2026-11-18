#include <KiwisIoT.h>

// ===== WIFI =====
const char* ssid  = "prakatheesh";
const char* pass  = "123456789";
const char* topic = "dash_1791381337342";

KiwisIoT kiwisiot(ssid, pass, topic);

// ===== RGB LED =====
#define RED_PIN D1

// ===== KIWISIOT CONTROL =====
void onControl(String ch, String val) {

  // Channel 0 மட்டும்
  if (ch != "0") return;

  Serial.print("Channel: ");
  Serial.println(ch);

  Serial.print("Value: ");
  Serial.println(val);

  // Channel 0 + Value 1 = LED ON
  if (val == "1") {
    digitalWrite(RED_PIN, HIGH);
    Serial.println("LED ON");
  }

  // Channel 0 + Value 0 = LED OFF
  else if (val == "0") {
    digitalWrite(RED_PIN, LOW);
    Serial.println("LED OFF");
  }
}

void setup() {

  Serial.begin(115200);
  delay(1000);

  pinMode(RED_PIN, OUTPUT);

  // Initially OFF
  digitalWrite(RED_PIN, LOW);

  kiwisiot.begin();

  Serial.println("RGB LED Ready");
  Serial.println("Channel 0");
  Serial.println("Value 1 = ON");
  Serial.println("Value 0 = OFF");
}

void loop() {
  kiwisiot.run();
}
