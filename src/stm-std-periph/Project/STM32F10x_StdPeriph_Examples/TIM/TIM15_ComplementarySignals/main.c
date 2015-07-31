/**
  ******************************************************************************
  * @file    TIM/TIM15_ComplementarySignals/main.c 
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    04/16/2010
  * @brief   Main program body
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */  
    
    /* Includes ------------------------------------------------------------------ */ 
#include "stm32f10x.h"
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup TIM15_ComplementarySignals
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;




    /* Private function prototypes ----------------------------------------------- */ 
void RCC_Configuration (void);




    /* Private functions --------------------------------------------------------- */ 
    
/**
  * @brief   Main program
  * @param  None
  * @retval None
  */ 
int main (void) 
{
    
        /* !< At this stage the microcontroller clock setting is already configured, 
           from startup
           function, refer to
        
        /* System Clocks Configuration */ 
        RCC_Configuration ();
    
        /* GPIO Configuration */ 
        GPIO_Configuration ();
    
        /* -----------------------------------------------------------------------
           signals with 50% duty cycles:
           1) = 366 Hz
           (TIM15_Period + 1) = 50%
           automatic 
           ----------------------------------------------------------------------- */ 
        
        /* Time Base configuration */ 
        TIM_TimeBaseStructure.TIM_Prescaler = 0;
    
    
    
    
    
    
        /* Channel 1 Configuration in PWM mode */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    
    
    
    
    
    
    
    
    
        /* Automatic Output enable, Break, dead time and lock configuration */ 
        TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
    
    
    
    
    
    
    
    
        /* TIM15 counter enable */ 
        TIM_Cmd (TIM15, ENABLE);
    
        /* Main Output Enable */ 
        TIM_CtrlPWMOutputs (TIM15, ENABLE);
    
        
    {
    



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* TIM15, GPIOA, GPIOB and AFIO clocks enable */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_TIM15 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB 


/**
  * @brief  Configure the TIM1 Pins.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
        /* GPIOA Configuration: Channel 1 as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    
    
    
    
        /* GPIOB Configuration: Channel 1N as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    
    
        /* GPIOA Configuration: BKIN pin */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    
    


#ifdef  USE_FULL_ASSERT
    
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */ 
void assert_failed (uint8_t * file, uint32_t line) 
{
    
        /* User can add his own implementation to report the file name and line number,
           file, line) */ 
        
        
    {
    }



#endif /* 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 