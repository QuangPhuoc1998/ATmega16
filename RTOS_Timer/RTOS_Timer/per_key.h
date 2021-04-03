/**
  ******************************************************************************
  * @file    per_key.h 
  * @author  Dang Thanh Tri 
  * @version V1.0
  * @date    11-Nov-2019
  * @brief   per_key module
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PER_KEY
#define __PER_KEY

/* Includes ------------------------------------------------------------------*/
#include "sys_task.h"
#include "bsp_gpio.h"
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  KEY_PRESSED = 1,
  KEY_RELEASED = 0,
} key_status_t;

typedef enum
{
  KEY_ID_1,
  KEY_ID_2,
} key_id_t;

typedef struct
{
  key_status_t status;
  key_status_t prev_status;
  key_status_t raw_status;
  uint8_t filter_cnt;
} touch_key_t;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void per_key_setup(void);
key_status_t key_read_status(key_id_t id);

#endif /* __PER_KEY */
