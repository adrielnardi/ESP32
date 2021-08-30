#include <PubSubClient.h> // biblioteca mqtt
#include <WiFi.h>         // biblioteca wifi

char *ssid = "XXXXX";
char *password = "XXXXX";

uint16_t period = 60000; // periodo de requisição a cada 60 segundos

WiFiClient wifiClient;               // client wifi
PubSubClient mqttClient(wifiClient); // cliente mqtt

char *mqttServer = "broker.hivemq.com";  // endereço do servidor HIVEMQ
int mqttPort = 1883;                    // porta do servidor HIVEMQ

void setup() {
  Serial.begin(115200);
  //CONECTANDO WIFI
  delay(10);
  Serial.println();
  Serial.print("Tentando se conectar a : ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());

  //Conectando ao servidor MQTT
  mqttClient.setServer(mqttServer, mqttPort); 
   while (!mqttClient.connected()) {
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (mqttClient.connect(clientId.c_str())) { // tenta conectar
      // Serial.print("MQTT Connected on ");
      // Serial.println(mqttServer);
    } else {
      Serial.print("falhou, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" tentando em 5 segundos...");
      delay(5000);
    }
  }
}


void loop() {
  // se não tiver conectado na wifi -> conecta no wifi
  if (!wifiIsConnected()) {
  //CONECTANDO WIFI
  delay(10);
  Serial.println();
  Serial.print("Tentando se conectar a : ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
  }
  
  // se não tiver conectado no servidor -> conecta ao mqtt
  if (!mqttClient.connected()) {
     while (!mqttClient.connected()) {
    String clientId = "clientId-YegxBsCCCi";
    clientId += String(random(0xffff), HEX);
    if (mqttClient.connect(clientId.c_str())) { // tenta conectar
      Serial.print("MQTT Connected on ");
      Serial.println(mqttServer);
    } else {
      Serial.print("falhou, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" tentando em 5 segundos...");
      delay(5000);
    }
  }
  }

  float humidity = getHumidity(); // obtém os dados da humidade
  String data = String(humidity);    // converte float para string
  mqttClient.publish("/adriel/room/humidity", data.c_str()); // envia o dado
  Serial.print("Enviado ");
  Serial.print(data);
  Serial.println(" para /adriel/room/humidity");  

  mqttClient.loop(); // loop do mqtt client
  delay(period);     // aguarda o periodo estabelecido na variável
}

// verificar se o wifi está conectado
bool wifiIsConnected() { return (WiFi.status() == WL_CONNECTED); }

// retorna a humidade entre 55.0 até 100.0 %
float getHumidity() { return random(55, 100); }
