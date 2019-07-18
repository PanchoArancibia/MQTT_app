// hal_WiFi.h
#ifndef HAL_WIFI_H
#define HAL_WIFI_

// Archivo para configuración de WiFi

#include <Arduino.h>

/*
 *  Parámetros de red
 */
const char* config_SSID = "Casa292";
const char* config_PASS = "Huracan292!";

const char* mqtt_server = "192.168.0.22";   // Raspberry Pi
// const char* mqtt_server = "192.168.0.30";   // Nano Pi Neo


/*  
 *  Funciones privadas
 */


/*  
 *  Funciones públicas
 */
void setup_wifi(void);
void callback(char*, byte*, unsigned int);
void reconnect(void);

#endif  /* HAL_WIFI_H */
