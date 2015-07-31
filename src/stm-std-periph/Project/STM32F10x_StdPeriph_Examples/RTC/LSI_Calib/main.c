/**
  ******************************************************************************
  * @file RTC/LSI_Calib/main.c 
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
#include "main.h"
#include <stdio.h>
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup RTC_LSI_Calib
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
#define RTCClockOutput_Enable  /* RTC Clock/64 is output on tamper pin(PC.13) */
    
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    





    /* Private function prototypes ----------------------------------------------- */ 
void RTC_Configuration (void);




    /* Private functions --------------------------------------------------------- */ 
    
/**
  * @brief   Main program.
  * @param  None
  * @retval None
  */ 
int main (void) 
{
    
        /* !< At this stage the microcontroller clock setting is already configured, 
           from startup
           function, refer to
        
        /* Initialize LEDs and Key Button mounted on STM3210X-EVAL board */ 
        STM_EVAL_LEDInit (LED1);
    
    
    
        /* RTC Configuration */ 
        RTC_Configuration ();
    
        /* Wait until Key Push button is pressed */ 
        while (STM_EVAL_PBGetState (BUTTON_KEY) != 0)
        
    {
    
    
        /* Get the Frequency value */ 
        RCC_GetClocksFreq (&RCC_Clocks);
    
        /* Enable TIM5 APB1 clocks */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM5, ENABLE);
    
        /* Connect internally the TM5_CH4 Input Capture to the LSI clock output */ 
        GPIO_PinRemapConfig (GPIO_Remap_TIM5CH4_LSI, ENABLE);
    
        /* TIM5 Time base configuration */ 
        TIM_TimeBaseStructure.TIM_Prescaler = 0;
    
    
    
    
    
        /* TIM5 Channel4 Input capture Mode configuration */ 
        TIM_ICInitStructure.TIM_Channel = TIM_Channel_4;
    
    
    
    
    
    
        /* Reinitialize the index for the interrupt */ 
        OperationComplete = 0;
    
        /* Enable the TIM5 Input Capture counter */ 
        TIM_Cmd (TIM5, ENABLE);
    
        /* Reset all TIM5 flags */ 
        TIM5->SR = 0;
    
        /* Enable the TIM5 channel 4 */ 
        TIM_ITConfig (TIM5, TIM_IT_CC4, ENABLE);
    
        /* NVIC configuration */ 
        NVIC_Configuration ();
    
        /* Wait the TIM5 measuring operation to be completed */ 
        while (OperationComplete != 2)
        
    {
    }
    
        /* Compute the actual frequency of the LSI. (TIM5_CLK = 2 * PCLK1) */ 
        if (PeriodValue != 0)
        
    {
        
    
    
        /* Adjust the RTC prescaler value */ 
        RTC_SetPrescaler (LsiFreq - 1);
    
        /* Wait until last write operation on RTC registers has finished */ 
        RTC_WaitForLastTask ();
    
        /* Turn on LED2 */ 
        STM_EVAL_LEDOn (LED2);
    
        
    {
        
            /* Inifinite loop */ 
    }



/**
  * @brief  Configures the nested vectored interrupt controller.
  * @param  None
  * @retval None
  */ 
void NVIC_Configuration (void) 
{
    
    
        /* Configure one bit for preemption priority */ 
        NVIC_PriorityGroupConfig (NVIC_PriorityGroup_1);
    
        /* Enable the RTC Interrupt */ 
        NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;
    
    
    
    
    
        /* Enable the TIM5 Interrupt */ 
        NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
    
    
    


/**
  * @brief  Configures the RTC.
  * @param  None
  * @retval None
  */ 
void RTC_Configuration (void) 
{
    
        /* Enable PWR and BKP clocks */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
    
        /* Allow access to BKP Domain */ 
        PWR_BackupAccessCmd (ENABLE);
    
        /* Reset Backup Domain */ 
        BKP_DeInit ();
    
        /* Enable the LSI OSC */ 
        RCC_LSICmd (ENABLE);
    
        /* Wait till LSI is ready */ 
        while (RCC_GetFlagStatus (RCC_FLAG_LSIRDY) == RESET)
        
    {
    }
    
        /* Select the RTC Clock Source */ 
        RCC_RTCCLKConfig (RCC_RTCCLKSource_LSI);
    
        /* Enable RTC Clock */ 
        RCC_RTCCLKCmd (ENABLE);
    
        /* Wait for RTC registers synchronization */ 
        RTC_WaitForSynchro ();
    
        /* Wait until last write operation on RTC registers has finished */ 
        RTC_WaitForLastTask ();
    
        /* Enable the RTC Second */ 
        RTC_ITConfig (RTC_IT_SEC, ENABLE);
    
        /* Wait until last write operation on RTC registers has finished */ 
        RTC_WaitForLastTask ();
    
        /* Set RTC prescaler: set RTC period to 1sec */ 
        RTC_SetPrescaler (40000);
    
        /* Wait until last write operation on RTC registers has finished */ 
        RTC_WaitForLastTask ();
    
        /* To output second signal on Tamper pin, the tamper functionality
        BKP_TamperPinCmd (DISABLE);
    
        /* Enable the RTC Second Output on Tamper Pin */ 
        BKP_RTCOutputConfig (BKP_RTCOutputSource_Second);



/**
  * @brief  Increments OperationComplete variable and return its value 
  *   before increment operation.
  * @param  None
  * @retval OperationComplete value befor increment
  */ 
    uint32_t IncrementVar_OperationComplete (void) 
{
    
    



/**
  * @brief  Returns OperationComplete value.
  * @param  None
  * @retval OperationComplete value
  */ 
    uint32_t GetVar_OperationComplete (void) 
{
    



/**
  * @brief  Sets the PeriodValue variable with input parameter.
  * @param  lue: Value of PeriodValue to be set.
  * @retval None
  */ 
void SetVar_PeriodValue (uint32_t Value) 
{
    


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
        
        /* Infinite loop */ 
        while (1)
        
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