/**
  ******************************************************************************
  * @file    Lib_DEBUG/main.c 
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
#include "lib_dbg.h"
#include "stm32_eval.h"
#include <stdio.h>
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup Lib_DEBUG
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    USART_InitTypeDef USART_InitStructure;

    /* Private function prototypes ----------------------------------------------- */ 
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
        
    
        /* USARTx configured as follow:
           disabled (RTS and CTS signals)
        USART_InitStructure.USART_BaudRate = 115200;
    
    
    
    
    
    
    
        /* Initialize all peripherals pointers */ 
        debug ();
    
    
    
        /* Simulate wrong parameter passed to library function --------------------- */ 
        /* To enable SPI1 clock, RCC_APB2PeriphClockCmd function must be used and
        RCC_APB1PeriphClockCmd (RCC_APB2Periph_SPI1, ENABLE);
    
        /* Some member of GPIOA_InitStructure structure are not initialized */ 
        GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_6;
    
    
        /* GPIOA_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; */ 
        GPIO_Init (GPIOA, &GPIOA_InitStructure);
    
        
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
    
        /* User can add his own implementation to report the file name and line number */ 
        
    
    
    
        /* Infinite loop */ 
        /* while (1)
} 
#endif /* 
    
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
    
    



/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 