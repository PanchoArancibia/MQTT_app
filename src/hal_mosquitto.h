// hal_mosquitto.h
#ifndef HAL_MOSQUITTO_H
#define HAL_MOSQUITTO_

#include <PubSubClient.h>

/*
 *  EXAMPLE!
 *  Subscribe for messages:
 *   mosquitto_sub -h test.mosquitto.org -t GsmClientTest/init -t GsmClientTest/ledStatus -q 1
 *  Toggle led:
 *   mosquitto_pub -h test.mosquitto.org -t GsmClientTest/led -q 1 -m "toggle"
 */

/*  Parámetros para Mosquitto */

/*  MQTT
 *  Parámetros y configuraciones!
 */
// Broker MQTT
const char* broker = "test.mosquitto.org";  

// Tópicos a suscribir
const char* sTopic_Relay = "Departament_01/Relay";
const char* sTopic_IR    = "Departament_01/IR";

// Tópicos a publicar
const char* pTopic_IP    = "Departament_01/IP";
const char* pTopic_State = "Departament_01/State";


#endif  /* HAL_MOSQUITTO_H */