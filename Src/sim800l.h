#ifndef SIM800L_H_
#define SIM800L_H_




#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_uart.h"
#include "ObitString.h"

///////////////////////////////////////////////////////////////////////////////////////////////////

#define SIM800_UART_BUFFER_MAX_SIZE      512
#define SIM800_UART                      huart2

extern UART_HandleTypeDef SIM800_UART;

///////////////////////////////////////////////////////////////////////////////////////////////
void Sim800_UartCallBack();
void Sim800_SendRaw(uint8_t *data, uint16_t length);
void Sim800_SendString(char *str);
void Sim800_SendAtNotWaitResponse(char *str);
uint8_t Sim800_SendAtCommand(uint8_t* AtCommand, uint8_t AtLength, uint32_t Time_out, uint8_t* answer, uint8_t AnsLength, uint8_t clear_buffer);
uint8_t WaitForStringInTimeOut( uint8_t *str, uint16_t str_len, uint16_t time_out);
void WaitForString( uint8_t *str, uint16_t str_len);

void Sim800L_Init();
uint16_t Sim800_CheckNewSMS();
void Sim800_ReadSMS(uint16_t index, uint8_t *SMS_content, uint16_t size_content, uint8_t *SMS_header, uint16_t size_header);
void Sim800L_SendSMS(uint8_t *SMS, uint8_t SMS_len, uint8_t *PhoneNumber, uint8_t PhoneNumLen);

uint8_t Sim800l_GPRS_HttpGet(char *URL, char *Response, uint16_t Response_Length);



#endif