/**
  ******************************************************************************
  * @file    stm32f10x_gpio.c
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    04/16/2010
  * @brief   This file provides all the GPIO firmware functions.
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
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
    
/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */ 
    
/** @defgroup GPIO 
  * @brief GPIO driver modules
  * @{
  */ 
    
/** @defgroup GPIO_Private_TypesDefinitions
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @defgroup GPIO_Private_Defines
  * @{
  */ 
    
    /* ------------ RCC registers bit address in the alias region ---------------- */ 
#define AFIO_OFFSET                 (AFIO_BASE - PERIPH_BASE)
    
    /* --- EVENTCR Register ----- */ 
    
    /* Alias word address of EVOE bit */ 
#define EVCR_OFFSET                 (AFIO_OFFSET + 0x00)
#define EVOE_BitNumber              ((uint8_t)0x07)
#define EVCR_EVOE_BB                (PERIPH_BB_BASE + (EVCR_OFFSET * 32) + (EVOE_BitNumber * 4))
    
    /* --- MAPR Register --- */ 
    /* Alias word address of MII_RMII_SEL bit */ 
#define MAPR_OFFSET                 (AFIO_OFFSET + 0x04) 
#define MII_RMII_SEL_BitNumber      ((u8)0x17) 
#define MAPR_MII_RMII_SEL_BB        (PERIPH_BB_BASE + (MAPR_OFFSET * 32) + (MII_RMII_SEL_BitNumber * 4))
    
#define EVCR_PORTPINCONFIG_MASK     ((uint16_t)0xFF80)
#define LSB_MASK                    ((uint16_t)0xFFFF)
#define DBGAFR_POSITION_MASK        ((uint32_t)0x000F0000)
#define DBGAFR_SWJCFG_MASK          ((uint32_t)0xF0FFFFFF)
#define DBGAFR_LOCATION_MASK        ((uint32_t)0x00200000)
#define DBGAFR_NUMBITS_MASK         ((uint32_t)0x00100000)
/**
  * @}
  */ 
    
/** @defgroup GPIO_Private_Macros
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @defgroup GPIO_Private_Variables
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @defgroup GPIO_Private_FunctionPrototypes
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @defgroup GPIO_Private_Functions
  * @{
  */ 
    
/**
  * @brief  Deinitializes the GPIOx peripheral registers to their default reset values.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */ 
void GPIO_DeInit (GPIO_TypeDef * GPIOx) 
{
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    
        
    {
        
        
    
    
    else if (GPIOx == GPIOB)
        
    {
        
        
    
    
    else if (GPIOx == GPIOC)
        
    {
        
        
    
    
    else if (GPIOx == GPIOD)
        
    {
        
        
    
    
    else if (GPIOx == GPIOE)
        
    {
        
        
    
    
    else if (GPIOx == GPIOF)
        
    {
        
        
    
    
    else
        
    {
        
            
        {
            
            
        
    



/**
  * @brief  Deinitializes the Alternate Functions (remap, event control
  *   and EXTI configuration) registers to their default reset values.
  * @param  None
  * @retval None
  */ 
void GPIO_AFIODeInit (void) 
{
    
    


/**
  * @brief  Initializes the GPIOx peripheral according to the specified
  *   parameters in the GPIO_InitStruct.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that
  *   contains the configuration information for the specified GPIO peripheral.
  * @retval None
  */ 
void GPIO_Init (GPIO_TypeDef * GPIOx, GPIO_InitTypeDef * GPIO_InitStruct) 
{
    
    
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    
    
    
/*---------------------------- GPIO Mode Configuration -----------------------*/ 
        currentmode = ((uint32_t) GPIO_InitStruct->GPIO_Mode) & ((uint32_t) 0x0F);
    
        
    {
        
            /* Check the parameters */ 
            assert_param (IS_GPIO_SPEED (GPIO_InitStruct->GPIO_Speed));
        
            /* Output mode */ 
            currentmode |= (uint32_t) GPIO_InitStruct->GPIO_Speed;
    
    
/*---------------------------- GPIO CRL Configuration ------------------------*/ 
        /* Configure the eight low port pins */ 
        if (((uint32_t) GPIO_InitStruct->GPIO_Pin & ((uint32_t) 0x00FF)) != 0x00)
        
    {
        
        
            
        {
            
            
                /* Get the port pins position */ 
                currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;
            
                
            {
                
                
                    /* Clear the corresponding low control register bits */ 
                    pinmask = ((uint32_t) 0x0F) << pos;
                
                
                    /* Write the mode configuration in the corresponding bits */ 
                    tmpreg |= (currentmode << pos);
                
                    /* Reset the corresponding ODR bit */ 
                    if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD)
                    
                {
                    
                
                
                else
                    
                {
                    
                        /* Set the corresponding ODR bit */ 
                        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU)
                        
                    {
                        
                    
                
            
        
        
    
    
/*---------------------------- GPIO CRH Configuration ------------------------*/ 
        /* Configure the eight high port pins */ 
        if (GPIO_InitStruct->GPIO_Pin > 0x00FF)
        
    {
        
        
            
        {
            
            
                /* Get the port pins position */ 
                currentpin = ((GPIO_InitStruct->GPIO_Pin) & pos);
            
                
            {
                
                
                    /* Clear the corresponding high control register bits */ 
                    pinmask = ((uint32_t) 0x0F) << pos;
                
                
                    /* Write the mode configuration in the corresponding bits */ 
                    tmpreg |= (currentmode << pos);
                
                    /* Reset the corresponding ODR bit */ 
                    if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD)
                    
                {
                    
                
                
                    /* Set the corresponding ODR bit */ 
                    if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU)
                    
                {
                    
                
            
        
        
    



/**
  * @brief  Fills each GPIO_InitStruct member with its default value.
  * @param  GPIO_InitStruct : pointer to a GPIO_InitTypeDef structure which will
  *   be initialized.
  * @retval None
  */ 
void GPIO_StructInit (GPIO_InitTypeDef * GPIO_InitStruct) 
{
    
        /* Reset GPIO init structure parameters values */ 
        GPIO_InitStruct->GPIO_Pin = GPIO_Pin_All;
    
    


/**
  * @brief  Reads the specified input port pin.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The input port pin value.
  */ 
    uint8_t GPIO_ReadInputDataBit (GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin) 
{
    
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    
    
        
    {
        
    
    
    else
        
    {
        
    
    



/**
  * @brief  Reads the specified GPIO input data port.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @retval GPIO input data port value.
  */ 
    uint16_t GPIO_ReadInputData (GPIO_TypeDef * GPIOx) 
{
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    



/**
  * @brief  Reads the specified output data port bit.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The output port pin value.
  */ 
    uint8_t GPIO_ReadOutputDataBit (GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin) 
{
    
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    
    
        
    {
        
    
    
    else
        
    {
        
    
    



/**
  * @brief  Reads the specified GPIO output data port.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @retval GPIO output data port value.
  */ 
    uint16_t GPIO_ReadOutputData (GPIO_TypeDef * GPIOx) 
{
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    



/**
  * @brief  Sets the selected data port bits.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */ 
void GPIO_SetBits (GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin) 
{
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    
    


/**
  * @brief  Clears the selected data port bits.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */ 
void GPIO_ResetBits (GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin) 
{
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    
    


/**
  * @brief  Sets or clears the selected data port bit.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @param  BitVal: specifies the value to be written to the selected bit.
  *   This parameter can be one of the BitAction enum values:
  *     @arg Bit_RESET: to clear the port pin
  *     @arg Bit_SET: to set the port pin
  * @retval None
  */ 
void GPIO_WriteBit (GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, BitAction BitVal) 
{
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    
    
    
        
    {
        
    
    
    else
        
    {
        
    



/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */ 
void GPIO_Write (GPIO_TypeDef * GPIOx, uint16_t PortVal) 
{
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    


/**
  * @brief  Locks GPIO Pins configuration registers.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */ 
void GPIO_PinLockConfig (GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin) 
{
    
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_ALL_PERIPH (GPIOx));
    
    
    
        /* Set LCKK bit */ 
        GPIOx->LCKR = tmp;
    
        /* Reset LCKK bit */ 
        GPIOx->LCKR = GPIO_Pin;
    
        /* Set LCKK bit */ 
        GPIOx->LCKR = tmp;
    
        /* Read LCKK bit */ 
        tmp = GPIOx->LCKR;
    
        /* Read LCKK bit */ 
        tmp = GPIOx->LCKR;


/**
  * @brief  Selects the GPIO pin used as Event output.
  * @param  GPIO_PortSource: selects the GPIO port to be used as source
  *   for Event output.
  *   This parameter can be GPIO_PortSourceGPIOx where x can be (A..E).
  * @param  GPIO_PinSource: specifies the pin for the Event output.
  *   This parameter can be GPIO_PinSourcex where x can be (0..15).
  * @retval None
  */ 
void GPIO_EventOutputConfig (uint8_t GPIO_PortSource, uint8_t GPIO_PinSource) 
{
    
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_EVENTOUT_PORT_SOURCE (GPIO_PortSource));
    
    
    
        /* Clear the PORT[6:4] and PIN[3:0] bits */ 
        tmpreg &= EVCR_PORTPINCONFIG_MASK;
    
    
    


/**
  * @brief  Enables or disables the Event Output.
  * @param  NewState: new state of the Event output.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */ 
void GPIO_EventOutputCmd (FunctionalState NewState) 
{
    
        /* Check the parameters */ 
        assert_param (IS_FUNCTIONAL_STATE (NewState));
    


/**
  * @brief  Changes the mapping of the specified pin.
  * @param  GPIO_Remap: selects the pin to remap.
  *   This parameter can be one of the following values:
  *     @arg GPIO_Remap_SPI1
  *     @arg GPIO_Remap_I2C1
  *     @arg GPIO_Remap_USART1
  *     @arg GPIO_Remap_USART2
  *     @arg GPIO_PartialRemap_USART3
  *     @arg GPIO_FullRemap_USART3
  *     @arg GPIO_PartialRemap_TIM1
  *     @arg GPIO_FullRemap_TIM1
  *     @arg GPIO_PartialRemap1_TIM2
  *     @arg GPIO_PartialRemap2_TIM2
  *     @arg GPIO_FullRemap_TIM2
  *     @arg GPIO_PartialRemap_TIM3
  *     @arg GPIO_FullRemap_TIM3
  *     @arg GPIO_Remap_TIM4
  *     @arg GPIO_Remap1_CAN1
  *     @arg GPIO_Remap2_CAN1
  *     @arg GPIO_Remap_PD01
  *     @arg GPIO_Remap_TIM5CH4_LSI
  *     @arg GPIO_Remap_ADC1_ETRGINJ
  *     @arg GPIO_Remap_ADC1_ETRGREG
  *     @arg GPIO_Remap_ADC2_ETRGINJ
  *     @arg GPIO_Remap_ADC2_ETRGREG
  *     @arg GPIO_Remap_ETH
  *     @arg GPIO_Remap_CAN2  
  *     @arg GPIO_Remap_SWJ_NoJTRST
  *     @arg GPIO_Remap_SWJ_JTAGDisable
  *     @arg GPIO_Remap_SWJ_Disable
  *     @arg GPIO_Remap_SPI3
  *     @arg GPIO_Remap_TIM2ITR1_PTP_SOF
  *     @arg GPIO_Remap_PTP_PPS
  *     @arg GPIO_Remap_TIM15
  *     @arg GPIO_Remap_TIM16
  *     @arg GPIO_Remap_TIM17
  *     @arg GPIO_Remap_CEC
  *     @arg GPIO_Remap_TIM1_DMA 
  *     @arg GPIO_Remap_TIM9
  *     @arg GPIO_Remap_TIM10
  *     @arg GPIO_Remap_TIM11
  *     @arg GPIO_Remap_TIM13
  *     @arg GPIO_Remap_TIM14
  *     @arg GPIO_Remap_FSMC_NADV               
  * @note  If the GPIO_Remap_TIM2ITR1_PTP_SOF is enabled the TIM2 ITR1 is connected 
  *        to Ethernet PTP output. When Reset TIM2 ITR1 is connected to USB OTG SOF output.       
  * @param  NewState: new state of the port pin remapping.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */ 
void GPIO_PinRemapConfig (uint32_t GPIO_Remap, FunctionalState NewState) 
{
    
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_REMAP (GPIO_Remap));
    
    
        
    {
        
    
    
    else
        
    {
        
    
    
    
    
        
    {
        
        
    
    
    else if ((GPIO_Remap & DBGAFR_NUMBITS_MASK) == DBGAFR_NUMBITS_MASK)
        
    {
        
        
        
    
    
    else
        
    {
        
        
    
    
        
    {
        
    
    
        
    {
        
    
    
    else
        
    {
        
    



/**
  * @brief  Selects the GPIO pin used as EXTI Line.
  * @param  GPIO_PortSource: selects the GPIO port to be used as source for EXTI lines.
  *   This parameter can be GPIO_PortSourceGPIOx where x can be (A..G).
  * @param  GPIO_PinSource: specifies the EXTI line to be configured.
  *   This parameter can be GPIO_PinSourcex where x can be (0..15).
  * @retval None
  */ 
void GPIO_EXTILineConfig (uint8_t GPIO_PortSource, uint8_t GPIO_PinSource) 
{
    
    
        /* Check the parameters */ 
        assert_param (IS_GPIO_EXTI_PORT_SOURCE (GPIO_PortSource));
    
    
    
    


/**
  * @brief  Selects the Ethernet media interface.
  * @note   This function applies only to STM32 Connectivity line devices.  
  * @param  GPIO_ETH_MediaInterface: specifies the Media Interface mode.
  *   This parameter can be one of the following values:
  *     @arg GPIO_ETH_MediaInterface_MII: MII mode
  *     @arg GPIO_ETH_MediaInterface_RMII: RMII mode    
  * @retval None
  */ 
void GPIO_ETH_MediaInterfaceConfig (uint32_t GPIO_ETH_MediaInterface) 
{
    
    
        /* Configure MII_RMII selection bit */ 
        *(__IO uint32_t *) MAPR_MII_RMII_SEL_BB = GPIO_ETH_MediaInterface;


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