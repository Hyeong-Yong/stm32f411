/*
 * usb.c
 *
 *  Created on: 2022. 1. 2.
 *      Author: HYJH
 */

#include "usb.h"
//#include "usb_device.h"

#ifdef _USE_HW_USB


bool usbInit(void)
{
  bool ret = true;

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
  delay(100);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


  MX_USB_DEVICE_Init();

  return ret;
}


#endif
