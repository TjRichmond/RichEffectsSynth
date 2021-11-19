/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define C_Pin GPIO_PIN_10
#define C_GPIO_Port GPIOB
#define C_EXTI_IRQn EXTI15_10_IRQn
#define F_Pin GPIO_PIN_7
#define F_GPIO_Port GPIOC
#define F_EXTI_IRQn EXTI9_5_IRQn
#define D_Pin GPIO_PIN_8
#define D_GPIO_Port GPIOA
#define D_EXTI_IRQn EXTI9_5_IRQn
#define E_Pin GPIO_PIN_9
#define E_GPIO_Port GPIOA
#define E_EXTI_IRQn EXTI9_5_IRQn
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define B_Pin GPIO_PIN_4
#define B_GPIO_Port GPIOB
#define B_EXTI_IRQn EXTI4_IRQn
#define A_Pin GPIO_PIN_5
#define A_GPIO_Port GPIOB
#define A_EXTI_IRQn EXTI9_5_IRQn
#define G_Pin GPIO_PIN_6
#define G_GPIO_Port GPIOB
#define G_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */
#define NS 512
#define FULLBUFFERSIZE 1024

extern volatile uint32_t* outBufPtr;
extern volatile uint32_t* inBufPtr;

extern uint32_t dac_val[FULLBUFFERSIZE];
extern uint32_t Sine_LUT[NS];
//extern uint32_t Saw_LUT[NS];
//extern uint32_t Tri_LUT[NS];
//extern uint32_t Sqr_LUT[NS];

extern bool keyPressFlag;
extern uint8_t oscType;

extern float waveAmp;
extern uint16_t volume;

extern bool keyState[7];
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
