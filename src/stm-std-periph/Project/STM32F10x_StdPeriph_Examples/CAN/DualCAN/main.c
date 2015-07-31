/**
  ******************************************************************************
  * @file    CAN/DualCAN/main.c 
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
#include "stm32_eval.h"
#include "stm3210c_eval_lcd.h"
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup CAN_DualCAN
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
    /* Private define ------------------------------------------------------------ */ 
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    CAN_InitTypeDef CAN_InitStructure;



    /* Private function prototypes ----------------------------------------------- */ 
void RCC_Configuration (void);














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
        
        /* System clocks configuration --------------------------------------------- */ 
        RCC_Configuration ();
    
        /* GPIO configuration ------------------------------------------------------ */ 
        GPIO_Configuration ();
    
        /* LCD Initilalization */ 
        STM3210C_LCD_Init ();
    
    
        /* Set the LCD Back Color */ 
        LCD_SetBackColor (LCD_COLOR_RED);
    
        /* Set the LCD Text Color */ 
        LCD_SetTextColor (LCD_COLOR_GREEN);
    
    
    
    
    
        /* Set the LCD Back Color */ 
        LCD_SetBackColor (LCD_COLOR_BLUE);
    
        /* Set the LCD Text Color */ 
        LCD_SetTextColor (LCD_COLOR_WHITE);
    
        /* NVIC configuration ------------------------------------------------------ */ 
        NVIC_Configuration ();
    
        /* Configures LED 1..4 */ 
        STM_EVAL_LEDInit (LED1);
    
    
    
    
        /* Configure BUTTON_KEY */ 
        STM_EVAL_PBInit (BUTTON_KEY, BUTTON_MODE_GPIO);
    
        /* Configure BUTTON_TAMPER */ 
        STM_EVAL_PBInit (BUTTON_TAMPER, BUTTON_MODE_GPIO);
    
        /* CANs configuration */ 
        CAN_Config ();
    
        /* IT Configuration for CAN1 */ 
        CAN_ITConfig (CAN1, CAN_IT_FMP0, ENABLE);
    
        /* IT Configuration for CAN2 */ 
        CAN_ITConfig (CAN2, CAN_IT_FMP0, ENABLE);
    
        /* turn off all leds */ 
        STM_EVAL_LEDOff (LED1);
    
    
    
    
        /* Infinite loop */ 
        while (1)
        
    {
        
            
        {
            
            
            
            
            
                
            {
            
        
        
            
        {
            
            
            
            
            
                
            {
            
        
    



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* GPIOB, GPIOD and AFIO clocks enable */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOB, ENABLE);
    
        /* CAN1 and CAN2 Periph clocks enable */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_CAN1 | RCC_APB1Periph_CAN2, ENABLE);


/**
  * @brief  Configures the GPIOs.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
        /* Configure CAN1 RX pin */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    
    
    
        /* Configure CAN2 RX pin */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    
    
        /* Configure CAN1 TX pin */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    
    
    
    
        /* Configure CAN2 TX pin */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    
    
        /* Remap CAN1 and CAN2 GPIOs */ 
        GPIO_PinRemapConfig (GPIO_Remap2_CAN1, ENABLE);
    


/**
  * @brief  Configures the NVIC for CAN.
  * @param  None
  * @retval None
  */ 
void NVIC_Configuration (void) 
{
    
    
    
    
    
    
    
    
    
    


/**
  * @brief  Turn ON/OFF the dedicate led
  * @param  Ledstatus: Led number from 0 to 3 
  * @retval None
  */ 
void LED_Display (uint8_t Ledstatus) 
{
    
        
    {
        
            /* Turn off all leds */ 
            STM_EVAL_LEDOff (LED1);
        
    
    
    else
        
    {
        
        
    
    
        
    {
        
            
            
            
            
        
            
            
            
            
        
            
            
            
        
            
            
            
        
            
            
            
        
            
    



/**
  * @brief  Configures the CAN.
  * @param  None
  * @retval None
  */ 
void CAN_Config (void) 
{
    
        /* CAN register init */ 
        CAN_DeInit (CAN1);
    
    
    
        /* CAN1 cell init */ 
        CAN_InitStructure.CAN_TTCM = DISABLE;
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* CAN1 filter init */ 
        CAN_FilterInitStructure.CAN_FilterNumber = 0;
    
    
    
    
    
    
    
    
    
    
        /* CAN2 filter init */ 
        CAN_FilterInitStructure.CAN_FilterNumber = 14;
    
    
        /* Transmit */ 
        TxMessage.StdId = 0x321;
    
    
    
    


/**
  * @brief  Delay
  * @param  None
  * @retval None
  */ 
void Delay (void) 
{
    
    
        
    {
    



/**
  * @brief  Initializes a Rx Message.
  * @param  CanRxMsg *RxMessage
  * @retval None
  */ 
void Init_RxMes (CanRxMsg * RxMessage) 
{
    
    
    
    
    
    
    
        
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
    



#endif /* 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 