#include <PubSubClient.h>
#include <WiFi.h>

const char* mqtt_server = "test.mosquitto.org";
const char* SSID = "3aiz eh ya3ni";
const char* password = "a7a 5555";

WiFiClient espClient;
PubSubClient client(espClient);

bool messageReceived = false; // Flag to indicate if a message was received

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(MQTT_Callback);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(SSID);
  WiFi.begin(SSID, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void MQTT_Callback(char* topic, byte* payload, unsigned int length) {
  String message;
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);

  if (String(topic) == "Fota/test") {
    messageReceived = true; // Set the flag when a message is received
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESPClient")) {
      Serial.println("Connected");
      client.subscribe("Fota/test");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (messageReceived) {
    messageReceived = false; // Reset the flag after processing
    String msg = "ismail is here";
    Serial.print("Publishing message: ");
    Serial.println(msg);
    client.publish("Fota/test", msg.c_str());
  }

  // Add a small delay to avoid flooding the MQTT broker
  delay(100);
}
