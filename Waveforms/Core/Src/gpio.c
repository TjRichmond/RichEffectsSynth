/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */
#include <stdbool.h>
#include "tim.h"
#include "dac.h"

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */


/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
     PA2   ------> USART2_TX
     PA3   ------> USART2_RX
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = C_Pin|B_Pin|A_Pin|G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = F_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(F_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = D_Pin|E_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin){
		case B1_Pin:
//				if(oscType>=3){
//					oscType = 0;
//				}
//				else
//					oscType++;
			break;

		case A_Pin:
			if(HAL_GPIO_ReadPin(GPIOB, A_Pin)) {
				htim2.Instance->CR1 |= TIM_CR1_CEN;
				htim2.Instance->ARR = 799;
				//keyState[0] = false;
				keyPressFlag = true;
			}
			else {
				htim2.Instance->CR1 &= ~TIM_CR1_CEN;
				//keyState[0] = false;
				keyPressFlag = false;
			}
			break;

		case B_Pin:
			if(HAL_GPIO_ReadPin(GPIOB, B_Pin)) {
				htim2.Instance->CR1 |= TIM_CR1_CEN;
				htim2.Instance->ARR = 712;
				keyPressFlag = true;
			}
			else {
				htim2.Instance->CR1 &= ~TIM_CR1_CEN;
				keyPressFlag = false;
			}
			break;

		case C_Pin:
			if(HAL_GPIO_ReadPin(GPIOB, C_Pin)) {
				htim2.Instance->CR1 |= TIM_CR1_CEN;
				htim2.Instance->ARR = 672;
				keyPressFlag = true;
			}
			else {
				htim2.Instance->CR1 &= ~TIM_CR1_CEN;
				keyPressFlag = false;
			}
			break;

		case D_Pin:
			if(HAL_GPIO_ReadPin(GPIOA, D_Pin)) {
				htim2.Instance->CR1 |= TIM_CR1_CEN;
				htim2.Instance->ARR = 599;
				keyPressFlag = true;
			}
			else {
				htim2.Instance->CR1 &= ~TIM_CR1_CEN;
				keyPressFlag = false;
			}
			break;

		case E_Pin:
			if(HAL_GPIO_ReadPin(GPIOA, E_Pin)) {
				htim2.Instance->CR1 |= TIM_CR1_CEN;
				htim2.Instance->ARR = 533;
				keyPressFlag = true;
			}
			else {
				htim2.Instance->CR1 &= ~TIM_CR1_CEN;
				keyPressFlag = false;
			}

			break;

		case F_Pin:
			if(HAL_GPIO_ReadPin(F_GPIO_Port, F_Pin)) {
				htim2.Instance->CR1 |= TIM_CR1_CEN;
				htim2.Instance->ARR = 503;
				keyPressFlag = true;
			}
			else {
				htim2.Instance->CR1 &= ~TIM_CR1_CEN;
				keyPressFlag = false;
			}
			break;

		case G_Pin:
			if(HAL_GPIO_ReadPin(GPIOB, G_Pin)) {
				htim2.Instance->CR1 |= TIM_CR1_CEN;
				htim2.Instance->ARR = 448;
				keyPressFlag = true;
			}
			else {
				htim2.Instance->CR1 &= ~TIM_CR1_CEN;
				keyPressFlag = false;
			}
			break;
	}
}


/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
