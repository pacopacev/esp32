#define BLYNK_TEMPLATE_ID "TMPL4Qrfa5DFS"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "y4CSS2wOhOA9BqfqBMy33xXh9vdbvTd6"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "ELOPARWFNT";
char pass[] = "24680135790!!**";

#define LED_PIN 19

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Start Blynk and Wi-Fi
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Connection successful
  Serial.println("\n✅ WiFi connected!");
  Serial.print("📶 ESP32 IP Address: ");
  Serial.println(WiFi.localIP());
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(LED_PIN, value);
}

void loop() {
  Blynk.run();
}
