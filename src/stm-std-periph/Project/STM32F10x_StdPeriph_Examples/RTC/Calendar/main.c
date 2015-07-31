/**
  ******************************************************************************
  * @file    RTC/Calendar/main.c 
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
#include "stm32_eval.h"
#include <stdio.h>
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup RTC_Calendar
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
#define RTCClockOutput_Enable  /* RTC Clock/64 is output on tamper pin(PC.13) */
    
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    __IO uint32_t TimeDisplay = 0;


    /* Private function prototypes ----------------------------------------------- */ 
void RTC_Configuration (void);













#ifdef __GNUC__
    /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else /* 
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif  /* __GNUC__ */
    
    /* Private functions --------------------------------------------------------- */ 
    
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */ 
int main (void) 
{
    
        /* !< At this stage the microcontroller clock setting is already configured, 
           from startup
           function, refer to
        
        /* Initialize LED1 mounted on STM3210X-EVAL board */ 
        STM_EVAL_LEDInit (LED1);
    
        /* USARTx configured as follow:
           disabled (RTS and CTS signals)
        USART_InitStructure.USART_BaudRate = 115200;
    
    
    
    
    
    
    
        /* NVIC configuration */ 
        NVIC_Configuration ();
    
        
    {
        
            /* Backup data register value is not correct or not yet programmed (when
            
        
            /* RTC Configuration */ 
            RTC_Configuration ();
        
        
            /* Adjust time by values entred by the user on the hyperterminal */ 
            Time_Adjust ();
        
    
    
    else
        
    {
        
            /* Check if the Power On Reset flag is set */ 
            if (RCC_GetFlagStatus (RCC_FLAG_PORRST) != RESET)
            
        {
            
        
        
            /* Check if the Pin Reset flag is set */ 
            else if (RCC_GetFlagStatus (RCC_FLAG_PINRST) != RESET)
            
        {
            
        
        
        
            /* Wait for RTC registers synchronization */ 
            RTC_WaitForSynchro ();
        
            /* Enable the RTC Second */ 
            RTC_ITConfig (RTC_IT_SEC, ENABLE);
        
            /* Wait until last write operation on RTC registers has finished */ 
            RTC_WaitForLastTask ();
    
    
#ifdef RTCClockOutput_Enable
        /* Enable PWR and BKP clocks */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
    
        /* Allow access to BKP Domain */ 
        PWR_BackupAccessCmd (ENABLE);
    
        /* Disable the Tamper Pin */ 
        BKP_TamperPinCmd (DISABLE); /* To output RTCCLK/64 on Tamper pin, the tamper
    
        /* Enable RTC Clock Output on Tamper Pin */ 
        BKP_RTCOutputConfig (BKP_RTCOutputSource_CalibClock);
    
#endif /* 
        
        /* Clear reset flags */ 
        RCC_ClearFlag ();
    
        /* Display time in infinite loop */ 
        Time_Show ();



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
    
        /* Enable LSE */ 
        RCC_LSEConfig (RCC_LSE_ON);
    
        /* Wait till LSE is ready */ 
        while (RCC_GetFlagStatus (RCC_FLAG_LSERDY) == RESET)
        
    {
    }
    
        /* Select LSE as RTC Clock Source */ 
        RCC_RTCCLKConfig (RCC_RTCCLKSource_LSE);
    
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
        RTC_SetPrescaler (32767);   /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */
    
        /* Wait until last write operation on RTC registers has finished */ 
        RTC_WaitForLastTask ();



/**
  * @brief  Returns the time entered by user, using Hyperterminal.
  * @param  None
  * @retval Current time RTC counter value
  */ 
    uint32_t Time_Regulate (void) 
{
    
    
    
    
        
    {
        
    
    
    
    
        
    {
        
    
    
    
    
        
    {
        
    
    
    
        /* Return the value to store in RTC counter register */ 
        return ((Tmp_HH * 3600 + Tmp_MM * 60 + Tmp_SS));



/**
  * @brief  Adjusts time.
  * @param  None
  * @retval None
  */ 
void Time_Adjust (void) 
{
    
        /* Wait until last write operation on RTC registers has finished */ 
        RTC_WaitForLastTask ();
    
        /* Change the current time */ 
        RTC_SetCounter (Time_Regulate ());
    
        /* Wait until last write operation on RTC registers has finished */ 
        RTC_WaitForLastTask ();


/**
  * @brief  Displays the current time.
  * @param  TimeVar: RTC counter value.
  * @retval None
  */ 
void Time_Display (uint32_t TimeVar) 
{
    
    
        /* Compute hours */ 
        THH = TimeVar / 3600;
    
        /* Compute minutes */ 
        TMM = (TimeVar % 3600) / 60;
    
        /* Compute seconds */ 
        TSS = (TimeVar % 3600) % 60;
    


/**
  * @brief  Shows the current time (HH:MM:SS) on the Hyperterminal.
  * @param  None
  * @retval None
  */ 
void Time_Show (void) 
{
    
    
        /* Infinite loop */ 
        while (1)
        
    {
        
            /* If 1s has paased */ 
            if (TimeDisplay == 1)
            
        {
            
                /* Display current time */ 
                Time_Display (RTC_GetCounter ());
            
        
    



/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */ 
    PUTCHAR_PROTOTYPE 
{
    
        /* Place your implementation of fputc here */ 
        /* e.g. write a character to the USART */ 
        USART_SendData (EVAL_COM1, (uint8_t) ch);
    
        /* Loop until the end of transmission */ 
        while (USART_GetFlagStatus (EVAL_COM1, USART_FLAG_TC) == RESET)
        
    {
    }
    



/**
  * @brief  Gets numeric values from the hyperterminal.
  * @param  None
  * @retval None
  */ 
    uint8_t USART_Scanf (uint32_t value) 
{
    
    
    {
    0, 0};
    
        
    {
        
            /* Loop until RXNE = 1 */ 
            while (USART_GetFlagStatus (EVAL_COM1, USART_FLAG_RXNE) == RESET)
            
        {
        }
        
        
            
        {
            
            
        
    
    
        /* Calculate the Corresponding value */ 
        index = (tmp[1] - 0x30) + ((tmp[0] - 0x30) * 10);
    
        /* Checks */ 
        if (index > value)
        
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