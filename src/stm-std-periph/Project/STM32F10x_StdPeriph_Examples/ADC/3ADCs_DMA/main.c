/**
  ******************************************************************************
  * @file    ADC/3ADCs_DMA/main.c 
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
    
/** @addtogroup ADC_3ADCs_DMA
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
#define ADC1_DR_Address    ((uint32_t)0x4001244C)
#define ADC3_DR_Address    ((uint32_t)0x40013C4C)
    
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    ADC_InitTypeDef ADC_InitStructure;



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
        
        /* System clocks configuration --------------------------------------------- */ 
        RCC_Configuration ();
    
        /* NVIC configuration ------------------------------------------------------ */ 
        NVIC_Configuration ();
    
        /* GPIO configuration ------------------------------------------------------ */ 
        GPIO_Configuration ();
    
        /* DMA1 channel1 configuration ---------------------------------------------- */ 
        DMA_DeInit (DMA1_Channel1);
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* Enable DMA1 channel1 */ 
        DMA_Cmd (DMA1_Channel1, ENABLE);
    
        /* DMA2 channel5 configuration ---------------------------------------------- */ 
        DMA_DeInit (DMA2_Channel5);
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* Enable DMA2 channel5 */ 
        DMA_Cmd (DMA2_Channel5, ENABLE);
    
        /* ADC1 configuration ------------------------------------------------------ */ 
        ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    
    
    
    
    
    
    
        /* ADC1 regular channels configuration */ 
        ADC_RegularChannelConfig (ADC1, ADC_Channel_14, 1, ADC_SampleTime_28Cycles5);
    
        /* Enable ADC1 DMA */ 
        ADC_DMACmd (ADC1, ENABLE);
    
        /* ADC2 configuration ------------------------------------------------------ */ 
        ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    
    
    
    
    
    
    
        /* ADC2 regular channels configuration */ 
        ADC_RegularChannelConfig (ADC2, ADC_Channel_13, 1, ADC_SampleTime_28Cycles5);
    
        /* Enable ADC2 EOC interupt */ 
        ADC_ITConfig (ADC2, ADC_IT_EOC, ENABLE);
    
        /* ADC3 configuration ------------------------------------------------------ */ 
        ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    
    
    
    
    
    
    
        /* ADC3 regular channel14 configuration */ 
        ADC_RegularChannelConfig (ADC3, ADC_Channel_12, 1, ADC_SampleTime_28Cycles5);
    
        /* Enable ADC3 DMA */ 
        ADC_DMACmd (ADC3, ENABLE);
    
        /* Enable ADC1 */ 
        ADC_Cmd (ADC1, ENABLE);
    
        /* Enable ADC1 reset calibaration register */ 
        ADC_ResetCalibration (ADC1);
    
        /* Check the end of ADC1 reset calibration register */ 
        while (ADC_GetResetCalibrationStatus (ADC1));
    
        /* Start ADC1 calibaration */ 
        ADC_StartCalibration (ADC1);
    
        /* Check the end of ADC1 calibration */ 
        while (ADC_GetCalibrationStatus (ADC1));
    
        /* Enable ADC2 */ 
        ADC_Cmd (ADC2, ENABLE);
    
        /* Enable ADC2 reset calibaration register */ 
        ADC_ResetCalibration (ADC2);
    
        /* Check the end of ADC2 reset calibration register */ 
        while (ADC_GetResetCalibrationStatus (ADC2));
    
        /* Start ADC2 calibaration */ 
        ADC_StartCalibration (ADC2);
    
        /* Check the end of ADC2 calibration */ 
        while (ADC_GetCalibrationStatus (ADC2));
    
        /* Enable ADC3 */ 
        ADC_Cmd (ADC3, ENABLE);
    
        /* Enable ADC3 reset calibaration register */ 
        ADC_ResetCalibration (ADC3);
    
        /* Check the end of ADC3 reset calibration register */ 
        while (ADC_GetResetCalibrationStatus (ADC3));
    
        /* Start ADC3 calibaration */ 
        ADC_StartCalibration (ADC3);
    
        /* Check the end of ADC3 calibration */ 
        while (ADC_GetCalibrationStatus (ADC3));
    
        /* Start ADC1 Software Conversion */ 
        ADC_SoftwareStartConvCmd (ADC1, ENABLE);
    
        /* Start ADC2 Software Conversion */ 
        ADC_SoftwareStartConvCmd (ADC2, ENABLE);
    
        /* Start ADC3 Software Conversion */ 
        ADC_SoftwareStartConvCmd (ADC3, ENABLE);
    
        
    {
    



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* ADCCLK = PCLK2/4 */ 
        RCC_ADCCLKConfig (RCC_PCLK2_Div4);
    
        /* Enable peripheral clocks ------------------------------------------------ */ 
        /* Enable DMA1 and DMA2 clocks */ 
        RCC_AHBPeriphClockCmd (RCC_AHBPeriph_DMA1 | RCC_AHBPeriph_DMA2, ENABLE);
    
        /* Enable ADC1, ADC2, ADC3 and GPIOC clocks */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_ADC1 | RCC_APB2Periph_ADC2 | 


/**
  * @brief  Configures the different GPIO ports.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
        /* Configure PC.02, PC.03 and PC.04 (ADC Channel12, ADC Channel13 and 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
    
    


/**
  * @brief  Configures Vector Table base location.
  * @param  None
  * @retval None
  */ 
void NVIC_Configuration (void) 
{
    
    
        /* Configure and enable ADC interrupt */ 
        NVIC_InitStructure.NVIC_IRQChannel = ADC1_2_IRQn;
    
    
    
    


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
    



#endif /* 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 