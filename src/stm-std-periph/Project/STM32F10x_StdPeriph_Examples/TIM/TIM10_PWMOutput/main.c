/**
  ******************************************************************************
  * @file    TIM/TIM10_PWMOutput/main.c 
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
    
/** @addtogroup TIM10_PWMOutput
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
        
        /* GPIO Configuration */ 
        GPIO_Configuration ();
    
        /* -----------------------------------------------------------------------
           frequency is set to SystemCoreClock (72 MHz), to get TIM10 counter
           (TIM10CLK / TIM10 counter clock) - 1
           36 KHz
           ----------------------------------------------------------------------- */ 
        /* Compute the prescaler value */ 
        PrescalerValue = (uint16_t) (SystemCoreClock / 24000000) - 1;
    
        /* Time base configuration */ 
        TIM_TimeBaseStructure.TIM_Period = 665;
    
    
    
    
    
        /* PWM1 Mode configuration: Channel1 */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    
    
    
    
    
    
    
        /* TIM10 enable counter */ 
        TIM_Cmd (TIM10, ENABLE);
    
        
    {
    }



/**
  * @brief  Configure TIM10 pin.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
        /* Enable TIM10 and GPIOF clock */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_TIM10 | RCC_APB2Periph_GPIOF | 
    
        /* Remap TIM10_CH1 on PF6 pin */ 
        GPIO_PinRemapConfig (GPIO_Remap_TIM10, ENABLE);
    
        /* GPIOF Configuration: TIM10 Channel1 as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    
    
    


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