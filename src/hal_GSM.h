// hal_GSM.h
#ifndef HAL_GSM_H
#define HAL_GSM_

// #include <Arduino.h>

/*  MODEM */
#define TINY_GSM_MODEM_SIM800
// #define TINY_GSM_MODEM_ESP8266

// Define the serial console for debug prints, if needed
#define TINY_GSM_DEBUG SerialMon

// Range to attempt to autobaud
#define GSM_AUTOBAUD_MIN 9600
#define GSM_AUTOBAUD_MAX 38400

// Set serial for debug console (to the Serial Monitor, default speed 115200)
#define SerialMon Serial

// Set serial for AT commands (to the module)
// Use Hardware Serial on Mega, Leonardo, Micro
#define SerialAT Serial1

// Uncomment this if you want to use SSL
//#define USE_SSL

// Credenciales para GSM
const char *GSMcredentials_apn  = "imovil.entelpcs.cl";
const char *GSMcredentials_user = "";
const char *GSMcredentials_pass = "";

/*
 *  Constantes
 */


/*
 *  Comandos AT
 *  --------------------------------------------------
 *  AT+CGATT    ->  Attach or detach from GPRS service
 *  AT+CGDCONT  ->  Define PDP context
 *  AT+CGACT    ->  PDP context activate or deactivate
 *  AT+CGPADDR  ->  Show PDP address
 *  --------------------------------------------------
 */
/* 
//  AT+CGATT=<state>
const char *AT_CMD_CGATT_ATTACHED       = "AT+CGATT=1\r\n";
const char *AT_CMD_CGATT_DETACHED       = "AT+CGATT=0\r\n";

//  AT+CGDCONT=
const char *AT_CMD_CGDCONT_ENTEL        = "AT+CGDCONT=1,\"IP\",\"imovil.entelpcs.cl\"";

//  AT+CGACT
const char *AT_CMD_CGACT_ACTIVATED      = "AT+CGACT=1\r\n";
const char *AT_CMD_CGACT_DESACTIVATED   = "AT+CGACT=0\r\n";

//  AT+CGPADDR
const char *AT_CMD_CGPADDR              = "AT+CGPADDR=1";

*/

#endif  /* HAL_GSM_H */
