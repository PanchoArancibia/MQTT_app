/*  Librería de Framework Arduino */
#include <Arduino.h>

/*  Librerías locales */
// #include "hal_WiFi.h"
#include "hal_GSM.h"
#include "hal_mosquitto.h"

/*  Librerías globales */
#include <TinyGsmClient.h>

#ifdef DUMP_AT_COMMANDS
  #include <StreamDebugger.h>
  StreamDebugger debugger(SerialAT, SerialMon);
  TinyGsm modem(debugger);
#else
  TinyGsm modem(SerialAT);
#endif

/*  Constantes locales */
const int Pin_Reset   = D1;   // GPIO5
const int Pin_Enable  = D2;   // GPIO4
// const int Pin_Led     = D;  

/*  Objetos */
TinyGsmClient client(modem);
PubSubClient  mqtt(client);

/*  Variables locales */
long lastReconnectAttempt = 0;

/*  Funciones Locales */
void mqttCallback(char* topic, byte* payload, unsigned int len);
boolean mqttConnect(void);

void setup() {
  // Establecer baudrate de terminal para debug
  SerialMon.begin(115200);
  delay(10);

  // Pin de Reset
  pinMode(Pin_Reset, OUTPUT);
  digitalWrite(Pin_Reset, HIGH);

  // Pin de Enable
  pinMode(Pin_Enable, OUTPUT);
  digitalWrite(Pin_Enable, HIGH);

  DBG("Espere...");

  // Establecer baudrate de módulo GSM
  // TinyGsmAutoBaud(SerialAT,GSM_AUTOBAUD_MIN,GSM_AUTOBAUD_MAX);   // Autobaud!
  SerialAT.begin(115200);
  delay(3000);

  /*  Inicialización y conexión a red */
  SerialMon.println("Inicializar Modem...");
  modem.restart();  // Restart takes quite some time
  // modem.init();     // To skip it, call init() instead of restart()

  String modemInfo = modem.getModemInfo();
  SerialMon.print("Modem: ");
  SerialMon.println(modemInfo);

  SerialMon.print("Esperando por red...");
  if (!modem.waitForNetwork(240000L)) {
    SerialMon.println(" error");
    delay(10000);
    return;
  }
  SerialMon.println(" OK");

  if (modem.isNetworkConnected()) {
    SerialMon.println("Red conectada");
  }

  /*  Inicialización MQTT */
  // Configuración MQTT Broker
  mqtt.setServer(broker, 1883);
  mqtt.setCallback(mqttCallback);

}

void loop() {

}

void mqttCallback(char* topic, byte* payload, unsigned int len) {
  SerialMon.print("Message arrived [");
  SerialMon.print(topic);
  SerialMon.print("]: ");
  SerialMon.write(payload, len);
  SerialMon.println();

  // // Only proceed if incoming message's topic matches
  // if (String(topic) == topicLed) {
  //   ledStatus = !ledStatus;
  //   digitalWrite(LED_PIN, ledStatus);
  //   mqtt.publish(topicLedStatus, ledStatus ? "1" : "0");
  // }
}

boolean mqttConnect() {
  SerialMon.print("Connecting to ");
  SerialMon.print(broker);

  // Connect to MQTT Broker
  boolean status = mqtt.connect("GsmClientTest");

  // Or, if you want to authenticate MQTT:
  //boolean status = mqtt.connect("GsmClientName", "mqtt_user", "mqtt_pass");

  if (status == false) {
    SerialMon.println(" fail");
    return false;
  }
  SerialMon.println(" OK");
  // mqtt.publish(topicInit, "GsmClientTest started");
  // mqtt.subscribe(topicLed);
  return mqtt.connected();
}
