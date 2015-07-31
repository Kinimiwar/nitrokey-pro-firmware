/**
  ******************************************************************************
  * @file    stm32f10x_fsmc.h
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    04/16/2010
  * @brief   This file contains all the functions prototypes for the FSMC firmware 
  *          library.
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
    
    /* Define to prevent recursive inclusion ------------------------------------- */ 
#ifndef __STM32F10x_FSMC_H
#define __STM32F10x_FSMC_H
    
#ifdef __cplusplus
extern "C"
{
    
#endif                          /* 
    
        /* Includes ------------------------------------------------------------------ */ 
#include "stm32f10x.h"
    
/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */ 
    
/** @addtogroup FSMC
  * @{
  */ 
    
/** @defgroup FSMC_Exported_Types
  * @{
  */ 
    
/** 
  * @brief  Timing parameters For NOR/SRAM Banks  
  */ 
    
    {
        
                                               parameter can be a value between 0 and 0xF.
                                               memories. */
        
                                               parameter can be a value between 0 and 0xF. 
                                               memories. */
        
                                           can be a value between 0 and 0xFF.
                                           Flash memories. */
        
                                                   parameter can be a value between 0 and 0xF.
                                                   memories. */
        
                                           be a value between 1 and 0xF.
                                           accesses. */
        
                                           value of this parameter depends on the memory type as shown below:
                                           CRAM
                                           0xF in NOR Flash memories
        
    
    
/** 
  * @brief  FSMC NOR/SRAM Init structure definition
  */ 
     
    {
        
        
                                           can be a value of @ref FSMC_Data_Address_Bus_Multiplexing */
        
                                       value of @ref FSMC_Memory_Type */
        
        
                                               Flash memories.
        
                                               This parameter can be a value of @ref FSMC_Wait_Signal_Polarity */
        
                                       memories in burst mode.
        
                                               during the wait state,
                                               value of @ref FSMC_Wait_Timing */
        
                                           value of @ref FSMC_Write_Operation */
        
                                       
        
        
        
                                                                           used */
        
    
    
/** 
  * @brief  Timing parameters For FSMC NAND and PCCARD Banks
  */ 
     
    {
        
                                       write access
                                       configured).
        
                                           to
                                           parameter can be a number between 0x00 and 0xFF */
        
                                           deassertion
                                           the memory space timing
        
                                           NAND-Flash
                                           be configured).
    
    
/** 
  * @brief  FSMC NAND Init structure definition
  */ 
     
    {
        
        
                                           FSMC_Wait_feature */
        
                                               FSMC_Data_Width */
        
        
        
                                           can be a value between 0 and 0xFF. */
        
                                           can be a number between 0x0 and 0xFF */
        
        
    
    
/** 
  * @brief  FSMC PCCARD Init structure definition
  */ 
     
    {
        
                                       FSMC_Wait_feature */
        
                                           can be a value between 0 and 0xFF. */
        
                                           can be a number between 0x0 and 0xFF */
        
        
        
    
    
/**
  * @}
  */ 
     
/** @defgroup FSMC_Exported_Constants
  * @{
  */ 
     
/** @defgroup FSMC_NORSRAM_Bank 
  * @{
  */ 
#define FSMC_Bank1_NORSRAM1                             ((uint32_t)0x00000000)
#define FSMC_Bank1_NORSRAM2                             ((uint32_t)0x00000002)
#define FSMC_Bank1_NORSRAM3                             ((uint32_t)0x00000004)
#define FSMC_Bank1_NORSRAM4                             ((uint32_t)0x00000006)
/**
  * @}
  */ 
     
/** @defgroup FSMC_NAND_Bank 
  * @{
  */ 
#define FSMC_Bank2_NAND                                 ((uint32_t)0x00000010)
#define FSMC_Bank3_NAND                                 ((uint32_t)0x00000100)
/**
  * @}
  */ 
     
/** @defgroup FSMC_PCCARD_Bank 
  * @{
  */ 
#define FSMC_Bank4_PCCARD                               ((uint32_t)0x00001000)
/**
  * @}
  */ 
     
#define IS_FSMC_NORSRAM_BANK(BANK) (((BANK) == FSMC_Bank1_NORSRAM1) || \
      ((BANK) == FSMC_Bank1_NORSRAM2) || \
#define IS_FSMC_NAND_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
        ((BANK) == FSMC_Bank3_NAND)) 
#define IS_FSMC_GETFLAG_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
        ((BANK) == FSMC_Bank3_NAND) || \
#define IS_FSMC_IT_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
        ((BANK) == FSMC_Bank3_NAND) || \
/** @defgroup NOR_SRAM_Controller 
  * @{
  */ 
        
/** @defgroup FSMC_Data_Address_Bus_Multiplexing 
  * @{
  */ 
        
#define FSMC_DataAddressMux_Disable                       ((uint32_t)0x00000000)
#define FSMC_DataAddressMux_Enable                        ((uint32_t)0x00000002)
#define IS_FSMC_MUX(MUX) (((MUX) == FSMC_DataAddressMux_Disable) || \
        ((MUX) == FSMC_DataAddressMux_Enable)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_Memory_Type 
  * @{
  */ 
        
#define FSMC_MemoryType_SRAM                            ((uint32_t)0x00000000)
#define FSMC_MemoryType_PSRAM                           ((uint32_t)0x00000004)
#define FSMC_MemoryType_NOR                             ((uint32_t)0x00000008)
#define IS_FSMC_MEMORY(MEMORY) (((MEMORY) == FSMC_MemoryType_SRAM) || \
        ((MEMORY) == FSMC_MemoryType_PSRAM) || \
/**
  * @}
  */ 
        
/** @defgroup FSMC_Data_Width 
  * @{
  */ 
        
#define FSMC_MemoryDataWidth_8b                         ((uint32_t)0x00000000)
#define FSMC_MemoryDataWidth_16b                        ((uint32_t)0x00000010)
#define IS_FSMC_MEMORY_WIDTH(WIDTH) (((WIDTH) == FSMC_MemoryDataWidth_8b) || \
        ((WIDTH) == FSMC_MemoryDataWidth_16b)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_Burst_Access_Mode 
  * @{
  */ 
        
#define FSMC_BurstAccessMode_Disable                    ((uint32_t)0x00000000) 
#define FSMC_BurstAccessMode_Enable                     ((uint32_t)0x00000100)
#define IS_FSMC_BURSTMODE(STATE) (((STATE) == FSMC_BurstAccessMode_Disable) || \
        ((STATE) == FSMC_BurstAccessMode_Enable)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_Wait_Signal_Polarity 
  * @{
  */ 
        
#define FSMC_WaitSignalPolarity_Low                     ((uint32_t)0x00000000)
#define FSMC_WaitSignalPolarity_High                    ((uint32_t)0x00000200)
#define IS_FSMC_WAIT_POLARITY(POLARITY) (((POLARITY) == FSMC_WaitSignalPolarity_Low) || \
        ((POLARITY) == FSMC_WaitSignalPolarity_High)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_Wrap_Mode 
  * @{
  */ 
        
#define FSMC_WrapMode_Disable                           ((uint32_t)0x00000000)
#define FSMC_WrapMode_Enable                            ((uint32_t)0x00000400) 
#define IS_FSMC_WRAP_MODE(MODE) (((MODE) == FSMC_WrapMode_Disable) || \
        ((MODE) == FSMC_WrapMode_Enable)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_Wait_Timing 
  * @{
  */ 
        
#define FSMC_WaitSignalActive_BeforeWaitState           ((uint32_t)0x00000000)
#define FSMC_WaitSignalActive_DuringWaitState           ((uint32_t)0x00000800) 
#define IS_FSMC_WAIT_SIGNAL_ACTIVE(ACTIVE) (((ACTIVE) == FSMC_WaitSignalActive_BeforeWaitState) || \
        ((ACTIVE) == FSMC_WaitSignalActive_DuringWaitState)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_Write_Operation 
  * @{
  */ 
        
#define FSMC_WriteOperation_Disable                     ((uint32_t)0x00000000)
#define FSMC_WriteOperation_Enable                      ((uint32_t)0x00001000)
#define IS_FSMC_WRITE_OPERATION(OPERATION) (((OPERATION) == FSMC_WriteOperation_Disable) || \
        ((OPERATION) == FSMC_WriteOperation_Enable)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_Wait_Signal 
  * @{
  */ 
        
#define FSMC_WaitSignal_Disable                         ((uint32_t)0x00000000)
#define FSMC_WaitSignal_Enable                          ((uint32_t)0x00002000) 
#define IS_FSMC_WAITE_SIGNAL(SIGNAL) (((SIGNAL) == FSMC_WaitSignal_Disable) || \
        ((SIGNAL) == FSMC_WaitSignal_Enable)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_Extended_Mode 
  * @{
  */ 
        
#define FSMC_ExtendedMode_Disable                       ((uint32_t)0x00000000)
#define FSMC_ExtendedMode_Enable                        ((uint32_t)0x00004000)
        
#define IS_FSMC_EXTENDED_MODE(MODE) (((MODE) == FSMC_ExtendedMode_Disable) || \
        ((MODE) == FSMC_ExtendedMode_Enable)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_Write_Burst 
  * @{
  */ 
        
#define FSMC_WriteBurst_Disable                         ((uint32_t)0x00000000)
#define FSMC_WriteBurst_Enable                          ((uint32_t)0x00080000) 
#define IS_FSMC_WRITE_BURST(BURST) (((BURST) == FSMC_WriteBurst_Disable) || \
        ((BURST) == FSMC_WriteBurst_Enable)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_Address_Setup_Time 
  * @{
  */ 
        
#define IS_FSMC_ADDRESS_SETUP_TIME(TIME) ((TIME) <= 0xF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Address_Hold_Time 
  * @{
  */ 
        
#define IS_FSMC_ADDRESS_HOLD_TIME(TIME) ((TIME) <= 0xF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Data_Setup_Time 
  * @{
  */ 
        
#define IS_FSMC_DATASETUP_TIME(TIME) (((TIME) > 0) && ((TIME) <= 0xFF))
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Bus_Turn_around_Duration 
  * @{
  */ 
        
#define IS_FSMC_TURNAROUND_TIME(TIME) ((TIME) <= 0xF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_CLK_Division 
  * @{
  */ 
        
#define IS_FSMC_CLK_DIV(DIV) ((DIV) <= 0xF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Data_Latency 
  * @{
  */ 
        
#define IS_FSMC_DATA_LATENCY(LATENCY) ((LATENCY) <= 0xF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Access_Mode 
  * @{
  */ 
        
#define FSMC_AccessMode_A                               ((uint32_t)0x00000000)
#define FSMC_AccessMode_B                               ((uint32_t)0x10000000) 
#define FSMC_AccessMode_C                               ((uint32_t)0x20000000)
#define FSMC_AccessMode_D                               ((uint32_t)0x30000000)
#define IS_FSMC_ACCESS_MODE(MODE) (((MODE) == FSMC_AccessMode_A) || \
        ((MODE) == FSMC_AccessMode_B) || \
/**
  * @}
  */ 
        
/**
  * @}
  */ 
        
/** @defgroup NAND_PCCARD_Controller 
  * @{
  */ 
        
/** @defgroup FSMC_Wait_feature 
  * @{
  */ 
        
#define FSMC_Waitfeature_Disable                        ((uint32_t)0x00000000)
#define FSMC_Waitfeature_Enable                         ((uint32_t)0x00000002)
#define IS_FSMC_WAIT_FEATURE(FEATURE) (((FEATURE) == FSMC_Waitfeature_Disable) || \
        ((FEATURE) == FSMC_Waitfeature_Enable)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_ECC 
  * @{
  */ 
        
#define FSMC_ECC_Disable                                ((uint32_t)0x00000000)
#define FSMC_ECC_Enable                                 ((uint32_t)0x00000040)
#define IS_FSMC_ECC_STATE(STATE) (((STATE) == FSMC_ECC_Disable) || \
        ((STATE) == FSMC_ECC_Enable)) 
/**
  * @}
  */ 
        
/** @defgroup FSMC_ECC_Page_Size 
  * @{
  */ 
        
#define FSMC_ECCPageSize_256Bytes                       ((uint32_t)0x00000000)
#define FSMC_ECCPageSize_512Bytes                       ((uint32_t)0x00020000)
#define FSMC_ECCPageSize_1024Bytes                      ((uint32_t)0x00040000)
#define FSMC_ECCPageSize_2048Bytes                      ((uint32_t)0x00060000)
#define FSMC_ECCPageSize_4096Bytes                      ((uint32_t)0x00080000)
#define FSMC_ECCPageSize_8192Bytes                      ((uint32_t)0x000A0000)
#define IS_FSMC_ECCPAGE_SIZE(SIZE) (((SIZE) == FSMC_ECCPageSize_256Bytes) || \
        ((SIZE) == FSMC_ECCPageSize_512Bytes) || \
        ((SIZE) == FSMC_ECCPageSize_1024Bytes) || \
        ((SIZE) == FSMC_ECCPageSize_2048Bytes) || \
/**
  * @}
  */ 
        
/** @defgroup FSMC_TCLR_Setup_Time 
  * @{
  */ 
        
#define IS_FSMC_TCLR_TIME(TIME) ((TIME) <= 0xFF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_TAR_Setup_Time 
  * @{
  */ 
        
#define IS_FSMC_TAR_TIME(TIME) ((TIME) <= 0xFF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Setup_Time 
  * @{
  */ 
        
#define IS_FSMC_SETUP_TIME(TIME) ((TIME) <= 0xFF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Wait_Setup_Time 
  * @{
  */ 
        
#define IS_FSMC_WAIT_TIME(TIME) ((TIME) <= 0xFF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Hold_Setup_Time 
  * @{
  */ 
        
#define IS_FSMC_HOLD_TIME(TIME) ((TIME) <= 0xFF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_HiZ_Setup_Time 
  * @{
  */ 
        
#define IS_FSMC_HIZ_TIME(TIME) ((TIME) <= 0xFF)
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Interrupt_sources 
  * @{
  */ 
        
#define FSMC_IT_RisingEdge                              ((uint32_t)0x00000008)
#define FSMC_IT_Level                                   ((uint32_t)0x00000010)
#define FSMC_IT_FallingEdge                             ((uint32_t)0x00000020)
#define IS_FSMC_IT(IT) ((((IT) & (uint32_t)0xFFFFFFC7) == 0x00000000) && ((IT) != 0x00000000))
#define IS_FSMC_GET_IT(IT) (((IT) == FSMC_IT_RisingEdge) || \
        ((IT) == FSMC_IT_Level) || \
/**
  * @}
  */ 
        
/** @defgroup FSMC_Flags 
  * @{
  */ 
        
#define FSMC_FLAG_RisingEdge                            ((uint32_t)0x00000001)
#define FSMC_FLAG_Level                                 ((uint32_t)0x00000002)
#define FSMC_FLAG_FallingEdge                           ((uint32_t)0x00000004)
#define FSMC_FLAG_FEMPT                                 ((uint32_t)0x00000040)
#define IS_FSMC_GET_FLAG(FLAG) (((FLAG) == FSMC_FLAG_RisingEdge) || \
        ((FLAG) == FSMC_FLAG_Level) || \
#define IS_FSMC_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFFF8) == 0x00000000) && ((FLAG) != 0x00000000))
        
/**
  * @}
  */ 
        
/**
  * @}
  */ 
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Exported_Macros
  * @{
  */ 
        
/**
  * @}
  */ 
        
/** @defgroup FSMC_Exported_Functions
  * @{
  */ 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#ifdef __cplusplus
} 
#endif                          /* 
    
#endif  /*__STM32F10x_FSMC_H */
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