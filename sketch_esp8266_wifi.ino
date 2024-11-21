#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Longboard 22";
const char* password = "surf1213";

const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* mqtt_user = "";
const char* mqtt_pass = "";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);  // Inicializa a comunicação serial
  Serial.begin("Inicializando...");
  setup_wifi();  // Conecta-se à rede Wi-Fi
  client.setServer(mqtt_server, mqtt_port);  // Define o servidor MQTT
}

void loop() {
  if (!client.connected()) {
    reconnect();  // Verifica e reconecta ao MQTT se necessário
  }

  client.loop();  // Mantém a conexão MQTT aberta

  if (Serial.available() > 0) {
    String temperature = Serial.readStringUntil('\n');  // Lê a temperatura enviada pelo Arduino
    Serial.println("Temperatura recebida: " + temperature);
    
    // Publica a temperatura no tópico MQTT
    client.publish("home/temperature", temperature.c_str());
  }
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando ao WiFi... ");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Tentando conectar...");
  }

  Serial.println("Conectado ao WiFi!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");

    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str(), mqtt_user, mqtt_pass)) {
      Serial.println("Conectado ao MQTT!");
    } else {
      Serial.print("Falha ao conectar, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}
