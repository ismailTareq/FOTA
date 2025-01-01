/*
 * BL.h
 *
 *  Created on: Dec 22, 2024
 *      Author: ismail
 */

#ifndef INC_BL_H_
#define INC_BL_H_


#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "usart.h"
#include "crc.h"

#define BL_HOST_COMMUNICATION_UART       &huart2
#define CRC_ENGINE_OBJ                   &hcrc

#define CBL_GET_VER_CMD              0x10
#define CBL_GET_CID_CMD              0x11
#define CBL_GO_TO_ADDR_CMD           0x12
#define CBL_FLASH_ERASE_CMD          0x13
#define CBL_MEM_WRITE_CMD            0x14



#define CRC_VERIFING_FAILED  0X00
#define CRC_VERIFING_PASS  0X01

#define SEND_NACK        0xAB
#define SEND_ACK         0xCD


#define HOSTM_MAX_SIZE    200

#define CBL_VENDOR_ID                100
#define CBL_SW_MAJOR_VERSION         1
#define CBL_SW_MINOR_VERSION         1
#define CBL_SW_PATCH_VERSION         0


#define CBL_FLASH_MAX_PAGE_NUMBER    16
#define CBL_FLASH_MASS_ERASE         0xFF


#define INVALID_PAGE_NUMBER          0x00
#define VALID_PAGE_NUMBER            0x01
#define UNSUCCESSFUL_ERASE           0x02
#define SUCCESSFUL_ERASE             0x03

#define HAL_SUCCESSFUL_ERASE         0xFFFFFFFFU

#define ADDRESS_IS_INVALID           0x00
#define ADDRESS_IS_VALID             0x01

#define STM32F103_SRAM_SIZE         (20 * 1024)
#define STM32F103_FLASH_SIZE         (64 * 1024)
#define STM32F103_SRAM_END          (SRAM_BASE + STM32F103_SRAM_SIZE)
#define STM32F103_FLASH_END          (FLASH_BASE + STM32F103_FLASH_SIZE)

//for Discovery board
/*
#define STM32F407_SRAM1_SIZE         (112 * 1024)
#define STM32F407_SRAM2_SIZE         (16 * 1024)
#define STM32F407_SRAM3_SIZE         (64 * 1024)
#define STM32F407_FLASH_SIZE         (1024 * 1024)
#define STM32F407_SRAM1_END          (SRAM1_BASE + STM32F407_SRAM1_SIZE)
#define STM32F407_SRAM2_END          (SRAM2_BASE + STM32F407_SRAM2_SIZE)
#define STM32F407_SRAM3_END          (CCMDATARAM_BASE + STM32F407_SRAM3_SIZE)
#define STM32F407_FLASH_END          (FLASH_BASE + STM32F407_FLASH_SIZE)
*/

#define FLASH_PAYLOAD_WRITE_FAILED  0x00
#define FLASH_PAYLOAD_WRITE_PASSED  0x01
typedef enum{
	BL_NACK=0,
	BL_ACK
}BL_status;

typedef void (*pMainApp)(void);
typedef void (*Jump_Ptr)(void);

BL_status BL_FeatchHostCommand();
void BL_SendMessage(char *format,...);

#endif /* INC_BL_H_ */
