#include <Arduino.h>

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
