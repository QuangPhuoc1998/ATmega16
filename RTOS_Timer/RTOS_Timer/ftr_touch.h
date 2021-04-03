/**
  ******************************************************************************
  * @file    ftr_touch.h 
  * @author  Dang Thanh Tri 
  * @version V1.0
  * @date    11-Nov-2019
  * @brief   
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FTR_TOUCH_H
#define __FTR_TOUCH_H

/* Includes ------------------------------------------------------------------*/
#include "per_key.h"

#include "sys_task.h"
#include "stdbool.h"
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  TOUCH_EVT = 0,
  PRESS_EVT,
  RELEASE_EVT,
} touch_evt_t;

/* Exported constants --------------------------------------------------------*/
typedef struct
{
  struct
  {
    bool is_touched;
		bool is_prev_touched;
    bool is_pressed;
    bool is_released;
  } evt;
  
  struct
  {
    uint32_t cnt;
    bool enabled;
  } timer;

  struct
  {
    key_status_t now;
    key_status_t prev;  
  } state;
} touch_t; 

typedef enum
{
  TOUCH_1 = 0,
  TOUCH_2 = 1,
  TOUCH_3 
} touch_id_t;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void ftr_touch_setup(void);
void ftr_touch_clear(touch_id_t id);
bool ftr_touch_is_touched(touch_id_t id); 
bool ftr_touch_is_pressed(touch_id_t id); 
bool ftr_touch_is_released(touch_id_t id); 

#endif /* __FTR_TOUCH_H */

/******************************** END OF FILE *********************************/

