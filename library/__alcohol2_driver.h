/*
    __alcohol2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __alcohol2_driver.h
@brief    Alcohol2 Driver
@mainpage Alcohol2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   ALCOHOL2
@brief      Alcohol2 Click Driver
@{

| Global Library Prefix | **ALCOHOL2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **jul 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _ALCOHOL2_H_
#define _ALCOHOL2_H_

/** 
 * @macro T_ALCOHOL2_P
 * @brief Driver Abstract type 
 */
#define T_ALCOHOL2_P    const uint8_t*

/** @defgroup ALCOHOL2_COMPILE Compilation Config */              /** @{ */

//  #define   __ALCOHOL2_DRV_SPI__                            /**<     @macro __ALCOHOL2_DRV_SPI__  @brief SPI driver selector */
   #define   __ALCOHOL2_DRV_I2C__                            /**<     @macro __ALCOHOL2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __ALCOHOL2_DRV_UART__                           /**<     @macro __ALCOHOL2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup ALCOHOL2_VAR Variables */                           /** @{ */

extern const uint8_t _ALCOHOL2_STATUS_REG ;
extern const uint8_t _ALCOHOL2_LOCK_REG   ;
extern const uint8_t _ALCOHOL2_TIACN_REG  ;
extern const uint8_t _ALCOHOL2_REFCN_REG  ;
extern const uint8_t _ALCOHOL2_MODECN_REG ;
                  
extern const uint8_t _ALCOHOL2_WRITE_MODE    ;
extern const uint8_t _ALCOHOL2_READ_ONLY_MODE;
                
extern const uint8_t _ALCOHOL2_EXT_TIA_RES      ;
extern const uint8_t _ALCOHOL2_2750_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_3500_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_7K_OHM_TIA_RES   ;
extern const uint8_t _ALCOHOL2_14K_OHM_TIA_RES  ;
extern const uint8_t _ALCOHOL2_35K_OHM_TIA_RES  ;
extern const uint8_t _ALCOHOL2_120K_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_350K_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_10_OHM_LOAD_RES  ;
extern const uint8_t _ALCOHOL2_33_OHM_LOAD_RES  ;
extern const uint8_t _ALCOHOL2_50_OHM_LOAD_RES  ;
extern const uint8_t _ALCOHOL2_100_OHM_LOAD_RES ;
                 
extern const uint8_t _ALCOHOL2_VREF_INT             ;
extern const uint8_t _ALCOHOL2_VREF_EXT             ;
extern const uint8_t _ALCOHOL2_20_PERCENTS_INT_ZERO ;
extern const uint8_t _ALCOHOL2_50_PERCENTS_INT_ZERO ;
extern const uint8_t _ALCOHOL2_67_PERCENTS_INT_ZERO ;
extern const uint8_t _ALCOHOL2_INT_ZERO_BYPASSED    ;
extern const uint8_t _ALCOHOL2_BIAS_POL_NEGATIVE    ;
extern const uint8_t _ALCOHOL2_BIAS_POL_POSITIVE    ;
extern const uint8_t _ALCOHOL2_0_PERCENTS_BIAS      ;
extern const uint8_t _ALCOHOL2_1_PERCENT_BIAS       ;
extern const uint8_t _ALCOHOL2_2_PERCENTS_BIAS      ;
extern const uint8_t _ALCOHOL2_4_PERCENTS_BIAS      ;
extern const uint8_t _ALCOHOL2_6_PERCENTS_BIAS      ;
extern const uint8_t _ALCOHOL2_8_PERCENTS_BIAS      ;
extern const uint8_t _ALCOHOL2_10_PERCENTS_BIAS     ;
extern const uint8_t _ALCOHOL2_12_PERCENTS_BIAS     ;
extern const uint8_t _ALCOHOL2_14_PERCENTS_BIAS     ;
extern const uint8_t _ALCOHOL2_16_PERCENTS_BIAS     ;
extern const uint8_t _ALCOHOL2_18_PERCENTS_BIAS     ;
extern const uint8_t _ALCOHOL2_20_PERCENTS_BIAS     ;
extern const uint8_t _ALCOHOL2_22_PERCENTS_BIAS     ;
extern const uint8_t _ALCOHOL2_24_PERCENTS_BIAS     ;
                
extern const uint8_t _ALCOHOL2_FET_DIS           ;
extern const uint8_t _ALCOHOL2_FET_EN            ;
extern const uint8_t _ALCOHOL2_DEEP_SLEEP_MODE   ;
extern const uint8_t _ALCOHOL2_2_LEAD_MODE       ;
extern const uint8_t _ALCOHOL2_STANDBY_MODE      ;
extern const uint8_t _ALCOHOL2_3_LEAD_MODE       ;
extern const uint8_t _ALCOHOL2_TEMP_MODE_TIA_OFF ;
extern const uint8_t _ALCOHOL2_TEMP_MODE_TIA_ON  ;
                  
extern const uint8_t _ALCOHOL2_DEVICE_EN         ;
extern const uint8_t _ALCOHOL2_DEVICE_DIS        ;

extern const uint8_t ADC_DEVICE_ADDR        ;

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup ALCOHOL2_INIT Driver Initialization */              /** @{ */

#ifdef   __ALCOHOL2_DRV_SPI__
void alcohol2_spiDriverInit(T_ALCOHOL2_P gpioObj, T_ALCOHOL2_P spiObj);
#endif
#ifdef   __ALCOHOL2_DRV_I2C__
void alcohol2_i2cDriverInit(T_ALCOHOL2_P gpioObj, T_ALCOHOL2_P i2cObj, uint8_t slave);
#endif
#ifdef   __ALCOHOL2_DRV_UART__
void alcohol2_uartDriverInit(T_ALCOHOL2_P gpioObj, T_ALCOHOL2_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void alcohol2_gpioDriverInit(T_ALCOHOL2_P gpioObj);
                                                                       /** @} */
/** @defgroup ALCOHOL2_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Function writes one byte to the register.
 *
 * @param[in] reg       Address where data be written
 * @param[in] _data     Data to be written
 */
void alcohol2_writeByte( uint8_t reg, uint8_t _data );

/**
 * @brief Function reads one byte from the register.
 *
 * @param[in] reg              Address which from data be read
 *
 * @retval data that is read from the registry
 */
uint8_t alcohol2_readByte( uint8_t reg );

/**
 * @brief Function waits until I2C is ready for the next command.
 */
void alcohol2_waitReady( void );

/**
 * @brief Device Enable function
 */
void alcohol2_enable( uint8_t state );

/**
 * @brief Function for read Alcohol data
 *
 * @retval Alcohol data - 12bit ADC value
 */
uint16_t alcohol2_readAlcohol();





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Alcohol2_STM.c
    @example Click_Alcohol2_TIVA.c
    @example Click_Alcohol2_CEC.c
    @example Click_Alcohol2_KINETIS.c
    @example Click_Alcohol2_MSP.c
    @example Click_Alcohol2_PIC.c
    @example Click_Alcohol2_PIC32.c
    @example Click_Alcohol2_DSPIC.c
    @example Click_Alcohol2_AVR.c
    @example Click_Alcohol2_FT90x.c
    @example Click_Alcohol2_STM.mbas
    @example Click_Alcohol2_TIVA.mbas
    @example Click_Alcohol2_CEC.mbas
    @example Click_Alcohol2_KINETIS.mbas
    @example Click_Alcohol2_MSP.mbas
    @example Click_Alcohol2_PIC.mbas
    @example Click_Alcohol2_PIC32.mbas
    @example Click_Alcohol2_DSPIC.mbas
    @example Click_Alcohol2_AVR.mbas
    @example Click_Alcohol2_FT90x.mbas
    @example Click_Alcohol2_STM.mpas
    @example Click_Alcohol2_TIVA.mpas
    @example Click_Alcohol2_CEC.mpas
    @example Click_Alcohol2_KINETIS.mpas
    @example Click_Alcohol2_MSP.mpas
    @example Click_Alcohol2_PIC.mpas
    @example Click_Alcohol2_PIC32.mpas
    @example Click_Alcohol2_DSPIC.mpas
    @example Click_Alcohol2_AVR.mpas
    @example Click_Alcohol2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __alcohol2_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */