/**
  ******************************************************************************
  * @file    ADC/TIMTrigger_AutoInjection/system_stm32f10x.c
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    04/16/2010
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer System Source File.
  ******************************************************************************  
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  ******************************************************************************
  */  
    
/** @addtogroup CMSIS
  * @{
  */ 
    
/** @addtogroup stm32f10x_system
  * @{
  */ 
    
/** @addtogroup STM32F10x_System_Private_Includes
  * @{
  */ 
    
#include "stm32f10x.h"
    
/**
  * @}
  */ 
    
/** @addtogroup STM32F10x_System_Private_TypesDefinitions
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @addtogroup STM32F10x_System_Private_Defines
  * @{
  */ 
    
    /* !< Uncomment the line corresponding to the desired System clock (SYSCLK)
       IMPORTANT NOTE:
       System clock doesn't exceed your device's
       source.
       an external 8MHz crystal 
       drive the System clock.
       different crystal you have to adapt those functions accordingly.
    
#if defined (STM32F10X_LD_VL) || (defined STM32F10X_MD_VL) 
    /* #define SYSCLK_FREQ_HSE HSE_Value */ 
#define SYSCLK_FREQ_24MHz  24000000
#else /* 
    /* #define SYSCLK_FREQ_HSE HSE_Value */ 
    /* #define SYSCLK_FREQ_24MHz 24000000 */ 
    /* #define SYSCLK_FREQ_36MHz 36000000 */ 
    /* #define SYSCLK_FREQ_48MHz 48000000 */ 
#define SYSCLK_FREQ_56MHz  56000000
    /* #define SYSCLK_FREQ_72MHz 72000000 */ 
#endif /* 
    
    /* !< Uncomment the following line if you need to use external SRAM mounted
       as data memory */ 
#if defined (STM32F10X_HD) || (defined STM32F10X_XL)
    /* #define DATA_IN_ExtSRAM */ 
#endif /* 
    
/**
  * @}
  */ 
    
/** @addtogroup STM32F10x_System_Private_Macros
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @addtogroup STM32F10x_System_Private_Variables
  * @{
  */ 
    
/*******************************************************************************
*  Clock Definitions
*******************************************************************************/ 
#ifdef SYSCLK_FREQ_HSE
    uint32_t SystemCoreClock = SYSCLK_FREQ_HSE; /* !< System Clock Frequency (Core Clock) */

#elif defined SYSCLK_FREQ_24MHz
    uint32_t SystemCoreClock = SYSCLK_FREQ_24MHz;   /* !< System Clock Frequency (Core Clock) */

#elif defined SYSCLK_FREQ_36MHz
    uint32_t SystemCoreClock = SYSCLK_FREQ_36MHz;   /* !< System Clock Frequency (Core Clock) */

#elif defined SYSCLK_FREQ_48MHz
    uint32_t SystemCoreClock = SYSCLK_FREQ_48MHz;   /* !< System Clock Frequency (Core Clock) */

#elif defined SYSCLK_FREQ_56MHz
    uint32_t SystemCoreClock = SYSCLK_FREQ_56MHz;   /* !< System Clock Frequency (Core Clock) */

#elif defined SYSCLK_FREQ_72MHz
    uint32_t SystemCoreClock = SYSCLK_FREQ_72MHz;   /* !< System Clock Frequency (Core Clock) */

#else   /*!< HSI Selected as System Clock source */
    uint32_t SystemCoreClock = HSI_Value;   /* !< System Clock Frequency (Core Clock) */

#endif /* 
    
{
0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};


/**
  * @}
  */ 
    
/** @addtogroup STM32F10x_System_Private_FunctionPrototypes
  * @{
  */ 



#ifdef SYSCLK_FREQ_HSE
static void SetSysClockToHSE (void);


#elif defined SYSCLK_FREQ_24MHz
static void SetSysClockTo24 (void);


#elif defined SYSCLK_FREQ_36MHz
static void SetSysClockTo36 (void);


#elif defined SYSCLK_FREQ_48MHz
static void SetSysClockTo48 (void);


#elif defined SYSCLK_FREQ_56MHz
static void SetSysClockTo56 (void);


#elif defined SYSCLK_FREQ_72MHz
static void SetSysClockTo72 (void);


#endif /* 
    
#ifdef DATA_IN_ExtSRAM
static void SystemInit_ExtMemCtl (void);


#endif  /* DATA_IN_ExtSRAM */
    
/**
  * @}
  */ 
    
/** @addtogroup STM32F10x_System_Private_Functions
  * @{
  */ 
    
/**
  * @brief  Setup the microcontroller system
  *         Initialize the Embedded Flash Interface, the PLL and update the 
  *         SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */ 
void SystemInit (void) 
{
    
        /* Reset the RCC clock configuration to the default reset state(for debug purpose) */ 
        /* Set HSION bit */ 
        RCC->CR |= (uint32_t) 0x00000001;
    
        /* Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits */ 
#ifndef STM32F10X_CL
        RCC->CFGR &= (uint32_t) 0xF8FF0000;
    
#else /* 
        RCC->CFGR &= (uint32_t) 0xF0FF0000;
    
#endif  /* STM32F10X_CL */   
        
        /* Reset HSEON, CSSON and PLLON bits */ 
        RCC->CR &= (uint32_t) 0xFEF6FFFF;
    
        /* Reset HSEBYP bit */ 
        RCC->CR &= (uint32_t) 0xFFFBFFFF;
    
        /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */ 
        RCC->CFGR &= (uint32_t) 0xFF80FFFF;
    
#ifdef STM32F10X_CL
        /* Reset PLL2ON and PLL3ON bits */ 
        RCC->CR &= (uint32_t) 0xEBFFFFFF;
    
        /* Disable all interrupts and clear pending bits */ 
        RCC->CIR = 0x00FF0000;
    
        /* Reset CFGR2 register */ 
        RCC->CFGR2 = 0x00000000;
    
#elif defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) 
        /* Disable all interrupts and clear pending bits */ 
        RCC->CIR = 0x009F0000;
    
        /* Reset CFGR2 register */ 
        RCC->CFGR2 = 0x00000000;
    
#else /* 
        /* Disable all interrupts and clear pending bits */ 
        RCC->CIR = 0x009F0000;
    
#endif  /* STM32F10X_CL */
        
#if defined (STM32F10X_HD) || (defined STM32F10X_XL)
#ifdef DATA_IN_ExtSRAM
        SystemInit_ExtMemCtl ();
    
#endif  /* DATA_IN_ExtSRAM */
#endif /* 
        
        /* Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers */ 
        /* Configure the Flash Latency cycles and enable prefetch buffer */ 
        SetSysClock ();


/**
  * @brief  Update SystemCoreClock according to Clock Register Values
  * @note   None
  * @param  None
  * @retval None
  */ 
void SystemCoreClockUpdate (void) 
{
    
    
#ifdef  STM32F10X_CL
        uint32_t prediv1source = 0, prediv1factor = 0, prediv2factor = 0, pll2mull = 0;
    
#endif  /* STM32F10X_CL */
        
#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL)
        uint32_t prediv1factor = 0;
    
#endif  /* STM32F10X_LD_VL or STM32F10X_MD_VL */
        
        /* Get SYSCLK source ------------------------------------------------------- */ 
        tmp = RCC->CFGR & RCC_CFGR_SWS;
    
        
    {
        
            
            
        
            
            
        
            
                /* Get PLL clock source and multiplication factor ---------------------- */ 
                pllmull = RCC->CFGR & RCC_CFGR_PLLMULL;
            
            
#ifndef STM32F10X_CL      
                pllmull = (pllmull >> 18) + 2;
            
                
            {
                
                    /* HSI oscillator clock divided by 2 selected as PLL clock entry */ 
                    SystemCoreClock = (HSI_Value >> 1) * pllmull;
            
            
            else
                
            {
                
#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL)
                    prediv1factor = (RCC->CFGR2 & RCC_CFGR2_PREDIV1) + 1;
                
                    /* HSE oscillator clock selected as PREDIV1 clock entry */ 
                    SystemCoreClock = (HSE_Value / prediv1factor) * pllmull;
                
#else /* 
                    /* HSE selected as PLL clock entry */ 
                    if ((RCC->CFGR & RCC_CFGR_PLLXTPRE) != (uint32_t) RESET)
                    
                {   /* HSE oscillator clock divided by 2 */
                    
                
                
                else
                    
                {
                    
                
                
#endif /* 
            }
            
#else /* 
                pllmull = pllmull >> 18;
            
                
            {
                
            
            
            else
                
            {   /* PLL multiplication factor = PLL input clock * 6.5 */
                
            
            
                
            {
                
                    /* HSI oscillator clock divided by 2 selected as PLL clock entry */ 
                    SystemCoreClock = (HSI_Value >> 1) * pllmull;
            
            
            else
                
            {   /* PREDIV1 selected as PLL clock entry */
                
                    /* Get PREDIV1 clock source and division factor */ 
                    prediv1source = RCC->CFGR2 & RCC_CFGR2_PREDIV1SRC;
                
                
                    
                {
                    
                        /* HSE oscillator clock selected as PREDIV1 clock entry */ 
                        SystemCoreClock = (HSE_Value / prediv1factor) * pllmull;
                
                
                else
                    
                {   /* PLL2 clock selected as PREDIV1 clock entry */
                    
                        /* Get PREDIV2 division factor and PLL2 multiplication factor */ 
                        prediv2factor = ((RCC->CFGR2 & RCC_CFGR2_PREDIV2) >> 4) + 1;
                    
                    
                
            
            
#endif  /* STM32F10X_CL */ 
                break;
        
            
            
    
    
        /* Compute HCLK clock frequency ---------------- */ 
        /* Get HCLK prescaler */ 
        tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
    
        /* HCLK clock frequency */ 
        SystemCoreClock >>= tmp;



/**
  * @brief  Configures the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers.
  * @param  None
  * @retval None
  */ 
static void SetSysClock (void) 
{
    
#ifdef SYSCLK_FREQ_HSE
        SetSysClockToHSE ();
    
#elif defined SYSCLK_FREQ_24MHz
        SetSysClockTo24 ();
    
#elif defined SYSCLK_FREQ_36MHz
        SetSysClockTo36 ();
    
#elif defined SYSCLK_FREQ_48MHz
        SetSysClockTo48 ();
    
#elif defined SYSCLK_FREQ_56MHz
        SetSysClockTo56 ();
    
#elif defined SYSCLK_FREQ_72MHz
        SetSysClockTo72 ();
    
#endif /* 
        
        /* If none of the define above is enabled, the HSI is used as System clock
} 

/**
  * @brief  Setup the external memory controller. Called in startup_stm32f10x.s 
  *          before jump to __main
  * @param  None
  * @retval None
  */ 
#ifdef DATA_IN_ExtSRAM
/**
  * @brief  Setup the external memory controller. 
  *         Called in startup_stm32f10x_xx.s/.c before jump to main.
  * 	      This function configures the external SRAM mounted on STM3210E-EVAL
  *         board (STM32 High density devices). This SRAM will be used as program
  *         data memory (including heap and stack).
  * @param  None
  * @retval None
  */ 
void SystemInit_ExtMemCtl (void) 
{
    
        /* !< FSMC Bank1 NOR/SRAM3 is used for the STM3210E-EVAL, if another Bank is 
        
        /* Enable FSMC clock */ 
        RCC->AHBENR = 0x00000114;
    
        /* Enable GPIOD, GPIOE, GPIOF and GPIOG clocks */ 
        RCC->APB2ENR = 0x000001E0;
    
        /* --------------- SRAM Data lines, NOE and NWE configuration --------------- */ 
/*----------------  SRAM Address lines configuration -------------------------*/ 
/*----------------  NOE and NWE configuration --------------------------------*/ 
/*----------------  NE3 configuration ----------------------------------------*/ 
/*----------------  NBL0, NBL1 configuration ---------------------------------*/ 
        
    
    
    
    
    
    
    
    
/*----------------  FSMC Configuration ---------------------------------------*/ 
/*----------------  Enable FSMC Bank1_SRAM Bank ------------------------------*/ 
        
    

#endif  /* DATA_IN_ExtSRAM */
    
#ifdef SYSCLK_FREQ_HSE
/**
  * @brief  Selects HSE as System clock source and configure HCLK, PCLK2
  *          and PCLK1 prescalers.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */ 
static void SetSysClockToHSE (void) 
{
    
    
        /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration --------------------------- */ 
        /* Enable HSE */ 
        RCC->CR |= ((uint32_t) RCC_CR_HSEON);
    
        /* Wait till HSE is ready and if Time out is reached exit */ 
        do
        
    {
        
        
    
    
        
    {
        
    
    
    else
        
    {
        
    
    
        
    {
        
#if !defined STM32F10X_LD_VL && !defined STM32F10X_MD_VL 
            /* Enable Prefetch Buffer */ 
            FLASH->ACR |= FLASH_ACR_PRFTBE;
        
            /* Flash 0 wait state */ 
            FLASH->ACR &= (uint32_t) ((uint32_t) ~ FLASH_ACR_LATENCY);
        
#ifndef STM32F10X_CL
            FLASH->ACR |= (uint32_t) FLASH_ACR_LATENCY_0;
        
#else /* 
            if (HSE_Value <= 24000000)
            
        {
            
        
        
        else
            
        {
            
        
        
#endif  /* STM32F10X_CL */
#endif /* 
            
            /* HCLK = SYSCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_HPRE_DIV1;
        
            /* PCLK2 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE2_DIV1;
        
            /* PCLK1 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE1_DIV1;
        
            /* Select HSE as system clock source */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_SW));
        
        
            /* Wait till HSE is used as system clock source */ 
            while ((RCC->CFGR & (uint32_t) RCC_CFGR_SWS) != (uint32_t) 0x04)
            
        {
        
    
    
    else
        
    {   /* If HSE fails to start-up, the application will have wrong clock 
    



#elif defined SYSCLK_FREQ_24MHz
/**
  * @brief  Sets System clock frequency to 24MHz and configure HCLK, PCLK2 
  *          and PCLK1 prescalers.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */ 
static void SetSysClockTo24 (void) 
{
    
    
        /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration --------------------------- */ 
        /* Enable HSE */ 
        RCC->CR |= ((uint32_t) RCC_CR_HSEON);
    
        /* Wait till HSE is ready and if Time out is reached exit */ 
        do
        
    {
        
        
    
    
        
    {
        
    
    
    else
        
    {
        
    
    
        
    {
        
#if !defined STM32F10X_LD_VL && !defined STM32F10X_MD_VL 
            /* Enable Prefetch Buffer */ 
            FLASH->ACR |= FLASH_ACR_PRFTBE;
        
            /* Flash 0 wait state */ 
            FLASH->ACR &= (uint32_t) ((uint32_t) ~ FLASH_ACR_LATENCY);
        
        
#endif /* 
            
            /* HCLK = SYSCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_HPRE_DIV1;
        
            /* PCLK2 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE2_DIV1;
        
            /* PCLK1 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE1_DIV1;
        
#ifdef STM32F10X_CL
            /* Configure PLLs ------------------------------------------------------ */ 
            /* PLL configuration: PLLCLK = PREDIV1 * 6 = 24 MHz */ 
            RCC->CFGR &= (uint32_t) ~ (RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
        
        
            /* PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */ 
            /* PREDIV1 configuration: PREDIV1CLK = PLL2 / 10 = 4 MHz */ 
            RCC->CFGR2 &= (uint32_t) ~ (RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL | 
        
        
            /* Enable PLL2 */ 
            RCC->CR |= RCC_CR_PLL2ON;
        
            /* Wait till PLL2 is ready */ 
            while ((RCC->CR & RCC_CR_PLL2RDY) == 0)
            
        {
        
        
#elif defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL)
            /* PLL configuration: = (HSE / 2) * 6 = 24 MHz */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
        
        
#else /* 
            /* PLL configuration: = (HSE / 2) * 6 = 24 MHz */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
        
        
#endif  /* STM32F10X_CL */
            
            /* Enable PLL */ 
            RCC->CR |= RCC_CR_PLLON;
        
            /* Wait till PLL is ready */ 
            while ((RCC->CR & RCC_CR_PLLRDY) == 0)
            
        {
        
        
            /* Select PLL as system clock source */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_SW));
        
        
            /* Wait till PLL is used as system clock source */ 
            while ((RCC->CFGR & (uint32_t) RCC_CFGR_SWS) != (uint32_t) 0x08)
            
        {
        
    
    
    else
        
    {   /* If HSE fails to start-up, the application will have wrong clock 
    



#elif defined SYSCLK_FREQ_36MHz
/**
  * @brief  Sets System clock frequency to 36MHz and configure HCLK, PCLK2 
  *          and PCLK1 prescalers. 
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */ 
static void SetSysClockTo36 (void) 
{
    
    
        /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration --------------------------- */ 
        /* Enable HSE */ 
        RCC->CR |= ((uint32_t) RCC_CR_HSEON);
    
        /* Wait till HSE is ready and if Time out is reached exit */ 
        do
        
    {
        
        
    
    
        
    {
        
    
    
    else
        
    {
        
    
    
        
    {
        
            /* Enable Prefetch Buffer */ 
            FLASH->ACR |= FLASH_ACR_PRFTBE;
        
            /* Flash 1 wait state */ 
            FLASH->ACR &= (uint32_t) ((uint32_t) ~ FLASH_ACR_LATENCY);
        
        
            /* HCLK = SYSCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_HPRE_DIV1;
        
            /* PCLK2 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE2_DIV1;
        
            /* PCLK1 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE1_DIV1;
        
#ifdef STM32F10X_CL
            /* Configure PLLs ------------------------------------------------------ */ 
            
            /* PLL configuration: PLLCLK = PREDIV1 * 9 = 36 MHz */ 
            RCC->CFGR &= (uint32_t) ~ (RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
        
        
            /* !< PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */ 
            /* PREDIV1 configuration: PREDIV1CLK = PLL2 / 10 = 4 MHz */ 
            
        
        
            /* Enable PLL2 */ 
            RCC->CR |= RCC_CR_PLL2ON;
        
            /* Wait till PLL2 is ready */ 
            while ((RCC->CR & RCC_CR_PLL2RDY) == 0)
            
        {
        
        
#else /* 
            /* PLL configuration: PLLCLK = (HSE / 2) * 9 = 36 MHz */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
        
        
#endif  /* STM32F10X_CL */
            
            /* Enable PLL */ 
            RCC->CR |= RCC_CR_PLLON;
        
            /* Wait till PLL is ready */ 
            while ((RCC->CR & RCC_CR_PLLRDY) == 0)
            
        {
        
        
            /* Select PLL as system clock source */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_SW));
        
        
            /* Wait till PLL is used as system clock source */ 
            while ((RCC->CFGR & (uint32_t) RCC_CFGR_SWS) != (uint32_t) 0x08)
            
        {
        
    
    
    else
        
    {   /* If HSE fails to start-up, the application will have wrong clock 
    



#elif defined SYSCLK_FREQ_48MHz
/**
  * @brief  Sets System clock frequency to 48MHz and configure HCLK, PCLK2 
  *          and PCLK1 prescalers. 
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */ 
static void SetSysClockTo48 (void) 
{
    
    
        /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration --------------------------- */ 
        /* Enable HSE */ 
        RCC->CR |= ((uint32_t) RCC_CR_HSEON);
    
        /* Wait till HSE is ready and if Time out is reached exit */ 
        do
        
    {
        
        
    
    
        
    {
        
    
    
    else
        
    {
        
    
    
        
    {
        
            /* Enable Prefetch Buffer */ 
            FLASH->ACR |= FLASH_ACR_PRFTBE;
        
            /* Flash 1 wait state */ 
            FLASH->ACR &= (uint32_t) ((uint32_t) ~ FLASH_ACR_LATENCY);
        
        
            /* HCLK = SYSCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_HPRE_DIV1;
        
            /* PCLK2 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE2_DIV1;
        
            /* PCLK1 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE1_DIV2;
        
#ifdef STM32F10X_CL
            /* Configure PLLs ------------------------------------------------------ */ 
            /* PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */ 
            /* PREDIV1 configuration: PREDIV1CLK = PLL2 / 5 = 8 MHz */ 
            
        
        
            /* Enable PLL2 */ 
            RCC->CR |= RCC_CR_PLL2ON;
        
            /* Wait till PLL2 is ready */ 
            while ((RCC->CR & RCC_CR_PLL2RDY) == 0)
            
        {
        
        
            /* PLL configuration: PLLCLK = PREDIV1 * 6 = 48 MHz */ 
            RCC->CFGR &= (uint32_t) ~ (RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
        
        
#else /* 
            /* PLL configuration: PLLCLK = HSE * 6 = 48 MHz */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
        
        
#endif  /* STM32F10X_CL */
            
            /* Enable PLL */ 
            RCC->CR |= RCC_CR_PLLON;
        
            /* Wait till PLL is ready */ 
            while ((RCC->CR & RCC_CR_PLLRDY) == 0)
            
        {
        
        
            /* Select PLL as system clock source */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_SW));
        
        
            /* Wait till PLL is used as system clock source */ 
            while ((RCC->CFGR & (uint32_t) RCC_CFGR_SWS) != (uint32_t) 0x08)
            
        {
        
    
    
    else
        
    {   /* If HSE fails to start-up, the application will have wrong clock 
    



#elif defined SYSCLK_FREQ_56MHz
/**
  * @brief  Sets System clock frequency to 56MHz and configure HCLK, PCLK2 
  *          and PCLK1 prescalers. 
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */ 
static void SetSysClockTo56 (void) 
{
    
    
        /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration --------------------------- */ 
        /* Enable HSE */ 
        RCC->CR |= ((uint32_t) RCC_CR_HSEON);
    
        /* Wait till HSE is ready and if Time out is reached exit */ 
        do
        
    {
        
        
    
    
        
    {
        
    
    
    else
        
    {
        
    
    
        
    {
        
            /* Enable Prefetch Buffer */ 
            FLASH->ACR |= FLASH_ACR_PRFTBE;
        
            /* Flash 2 wait state */ 
            FLASH->ACR &= (uint32_t) ((uint32_t) ~ FLASH_ACR_LATENCY);
        
        
            /* HCLK = SYSCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_HPRE_DIV1;
        
            /* PCLK2 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE2_DIV1;
        
            /* PCLK1 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE1_DIV2;
        
#ifdef STM32F10X_CL
            /* Configure PLLs ------------------------------------------------------ */ 
            /* PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */ 
            /* PREDIV1 configuration: PREDIV1CLK = PLL2 / 5 = 8 MHz */ 
            
        
        
            /* Enable PLL2 */ 
            RCC->CR |= RCC_CR_PLL2ON;
        
            /* Wait till PLL2 is ready */ 
            while ((RCC->CR & RCC_CR_PLL2RDY) == 0)
            
        {
        
        
            /* PLL configuration: PLLCLK = PREDIV1 * 7 = 56 MHz */ 
            RCC->CFGR &= (uint32_t) ~ (RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
        
        
#else /* 
            /* PLL configuration: PLLCLK = HSE * 7 = 56 MHz */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
        
        
#endif  /* STM32F10X_CL */
            
            /* Enable PLL */ 
            RCC->CR |= RCC_CR_PLLON;
        
            /* Wait till PLL is ready */ 
            while ((RCC->CR & RCC_CR_PLLRDY) == 0)
            
        {
        
        
            /* Select PLL as system clock source */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_SW));
        
        
            /* Wait till PLL is used as system clock source */ 
            while ((RCC->CFGR & (uint32_t) RCC_CFGR_SWS) != (uint32_t) 0x08)
            
        {
        
    
    
    else
        
    {   /* If HSE fails to start-up, the application will have wrong clock 
    



#elif defined SYSCLK_FREQ_72MHz
/**
  * @brief  Sets System clock frequency to 72MHz and configure HCLK, PCLK2 
  *          and PCLK1 prescalers. 
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */ 
static void SetSysClockTo72 (void) 
{
    
    
        /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration --------------------------- */ 
        /* Enable HSE */ 
        RCC->CR |= ((uint32_t) RCC_CR_HSEON);
    
        /* Wait till HSE is ready and if Time out is reached exit */ 
        do
        
    {
        
        
    
    
        
    {
        
    
    
    else
        
    {
        
    
    
        
    {
        
            /* Enable Prefetch Buffer */ 
            FLASH->ACR |= FLASH_ACR_PRFTBE;
        
            /* Flash 2 wait state */ 
            FLASH->ACR &= (uint32_t) ((uint32_t) ~ FLASH_ACR_LATENCY);
        
        
            /* HCLK = SYSCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_HPRE_DIV1;
        
            /* PCLK2 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE2_DIV1;
        
            /* PCLK1 = HCLK */ 
            RCC->CFGR |= (uint32_t) RCC_CFGR_PPRE1_DIV2;
        
#ifdef STM32F10X_CL
            /* Configure PLLs ------------------------------------------------------ */ 
            /* PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */ 
            /* PREDIV1 configuration: PREDIV1CLK = PLL2 / 5 = 8 MHz */ 
            
        
        
            /* Enable PLL2 */ 
            RCC->CR |= RCC_CR_PLL2ON;
        
            /* Wait till PLL2 is ready */ 
            while ((RCC->CR & RCC_CR_PLL2RDY) == 0)
            
        {
        
        
            /* PLL configuration: PLLCLK = PREDIV1 * 9 = 72 MHz */ 
            RCC->CFGR &= (uint32_t) ~ (RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
        
        
#else /* 
            /* PLL configuration: PLLCLK = HSE * 9 = 72 MHz */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | 
        
        
#endif  /* STM32F10X_CL */
            
            /* Enable PLL */ 
            RCC->CR |= RCC_CR_PLLON;
        
            /* Wait till PLL is ready */ 
            while ((RCC->CR & RCC_CR_PLLRDY) == 0)
            
        {
        
        
            /* Select PLL as system clock source */ 
            RCC->CFGR &= (uint32_t) ((uint32_t) ~ (RCC_CFGR_SW));
        
        
            /* Wait till PLL is used as system clock source */ 
            while ((RCC->CFGR & (uint32_t) RCC_CFGR_SWS) != (uint32_t) 0x08)
            
        {
        
    
    
    else
        
    {   /* If HSE fails to start-up, the application will have wrong clock 
    



#endif /* 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 