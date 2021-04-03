/**
  ******************************************************************************
  * @file    per_key.c 
  * @author  Dang Thanh Tri 
  * @version V1.0
  * @date    11-June-2019
  * @brief   per_key module
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "per_key.h"

/* Private typedef -----------------------------------------------------------*/
#define PER_KEY_TASK_TIME               10    // ms

#define PER_KEY_BTN_PRESSED_LEVEL       0
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
touch_key_t touch_keys[3];

key_status_t key_status;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static void _per_key_task(void *pv_context);

/******************************************************************************/
/*                             				APIs                                    */
/******************************************************************************/

void per_key_setup(void)
{
  task_add(TASK_REPEATED, PER_KEY_TASK_TIME, (void *)_per_key_task);
}

key_status_t key_read_status(key_id_t id)
{
  return touch_keys[id].status;
}

/******************************************************************************/
/*                            Module Private APIs                             */
/******************************************************************************/

/******************************************************************************/
/*                             	Module routines                               */
/******************************************************************************/

/**
  * @brief  Task per_key
  * @note   Filter per_key state, extract event and handle it
  * @param  None
  * @retval None.
  */
static void _filter_key(key_id_t id)
{
  touch_key_t *my_touch_key = &touch_keys[id];
  my_touch_key->raw_status = (PER_KEY_BTN_PRESSED_LEVEL == bsp_gpio_read_pin(id)) ? KEY_PRESSED : KEY_RELEASED;

  if ( my_touch_key->prev_status !=  my_touch_key->raw_status)
  {
     my_touch_key->filter_cnt += 1;
  }
  else
  {
     my_touch_key->filter_cnt = 0;
  }

  if ( my_touch_key->filter_cnt >= 3)
  {
    my_touch_key->prev_status =  my_touch_key->raw_status;
    my_touch_key->filter_cnt = 0;
    
    my_touch_key->status = my_touch_key->raw_status;
  }
}

static void _per_key_task(void *pv_context)
{ 
  _filter_key(0);
  _filter_key(1);
  _filter_key(2);
}



/******************************************************************************/
/*                         	Module Interrupt Handle                           */
/******************************************************************************/

/******************************** END OF FILE *********************************/

