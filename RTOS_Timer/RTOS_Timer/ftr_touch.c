/**
  ******************************************************************************
  * @file    ftr_touch.c 
  * @author  Dang Thanh Tri 
  * @version V1.0
  * @date    11-Nov-2019
  * @brief   ftr sensor module 
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "ftr_touch.h"

/* Private typedef -----------------------------------------------------------*/
#define FTR_TOUCH_TASK_TIME             50  // ms

#define TOUCH_TH_TIME                   400
#define PRESS_TH_TIME                   2000
#define RELEASE_TH_TIME                 1200

/* Private define ------------------------------------------------------------*/
static uint16_t release_time_offset = 0;
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
touch_t touch_table[3];

/* Private function prototypes -----------------------------------------------*/
static void _ftr_touch_task(void *pv_context);
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*                             				APIs                                    */
/******************************************************************************/

/**
  * @brief
  * @note   
  * @param  None
  * @retval None.
  */
void ftr_touch_setup(void)
{
  task_add(TASK_REPEATED, FTR_TOUCH_TASK_TIME, (void *)_ftr_touch_task);
}

void ftr_touch_clear(touch_id_t id)
{
  touch_t *touch_p = &touch_table[id];

  touch_p->evt.is_touched = false;
  touch_p->evt.is_pressed = false;
  touch_p->evt.is_released = false;
}

/**
  * @brief
  * @note   
  * @param  None
  * @retval None.
  */
bool ftr_touch_is_touched(touch_id_t id)
{
  bool result = false;
  touch_t *touch_p = &touch_table[id];

  if (touch_p->evt.is_touched)
  {
    result = true;
    touch_p->evt.is_touched = false;
  }
  
  return result;
}

bool ftr_touch_is_pressed(touch_id_t id)
{
  bool result = false;
  touch_t *touch_p = &touch_table[id];

  if (touch_p->evt.is_pressed)
  {
    result = true;
    touch_p->evt.is_pressed = false;
  }

  return result;
}

bool ftr_touch_is_released(touch_id_t id)
{
  bool result = false;
  touch_t *touch_p = &touch_table[id];

  if (touch_p->evt.is_released)
  {
    result = true;
    touch_p->evt.is_released = false;
  }

  return result;
}

/******************************************************************************/
/*                            Module Private APIs                             */
/******************************************************************************/

static void _process_touch(touch_id_t id)
{
  touch_t *touch_p = &touch_table[id];

  // update timer
  if (touch_p->timer.enabled)
  {
    touch_p->timer.cnt += FTR_TOUCH_TASK_TIME;
  }
  else
  {
    touch_p->timer.cnt = 0;
  }

  // update current status
  touch_p->state.now = key_read_status(id);

  // process touch event
  if (touch_p->state.prev == KEY_RELEASED && touch_p->state.now == KEY_PRESSED)   // touched event
  {
    touch_p->timer.enabled = 1; // enable timer
    touch_p->timer.cnt = 0;     // reset timer
		touch_p->evt.is_prev_touched = true;

  }
  else if (touch_p->state.prev == KEY_PRESSED && touch_p->state.now == KEY_RELEASED) // released event
  {
//    if (touch_p->timer.cnt > 0 && touch_p->timer.cnt < TOUCH_TH_TIME) // trigger user defined touch event
//    {
		touch_p->evt.is_touched = touch_p->evt.is_prev_touched;
//    }
    
    release_time_offset = touch_p->timer.cnt;
  }
  else if (touch_p->state.prev == KEY_PRESSED && touch_p->state.now == KEY_PRESSED)  // pressing
  {
    if (touch_p->timer.cnt == PRESS_TH_TIME)   // trigger user defined press event
                                  // the "==" sign can cause BUG!!!
    {
      touch_p->evt.is_pressed = true;
			touch_p->evt.is_prev_touched = false;
    }
  }
  else  // releasing
  {
    if (touch_p->timer.cnt >= RELEASE_TH_TIME + release_time_offset)
    {
      touch_p->evt.is_released = true;
      touch_p->timer.enabled = 0;
    }
  }

  // update prev status
  touch_p->state.prev = touch_p->state.now;
}

/**
  * @brief  
  * @note   
  * @param  None
  * @retval None.
  */
static void _ftr_touch_task(void *pv_context)
{
  _process_touch(TOUCH_1);
  _process_touch(TOUCH_2);
  _process_touch(TOUCH_3);
  
}



/******************************************************************************/
/*                             	Module routines                               */
/******************************************************************************/

/******************************************************************************/
/*                         	Module Interrupt Handle                           */
/******************************************************************************/

/******************************** END OF FILE *********************************/


