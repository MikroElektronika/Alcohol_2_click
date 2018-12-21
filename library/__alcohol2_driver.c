/*
    __alcohol2_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__alcohol2_driver.h"
#include "__alcohol2_hal.c"

/* ------------------------------------------------------------------- MACROS */

const uint8_t _ALCOHOL2_STATUS_REG    = 0x00;
const uint8_t _ALCOHOL2_LOCK_REG      = 0x01;
const uint8_t _ALCOHOL2_TIACN_REG     = 0x10;
const uint8_t _ALCOHOL2_REFCN_REG     = 0x11;
const uint8_t _ALCOHOL2_MODECN_REG    = 0x12;
     
const uint8_t _ALCOHOL2_WRITE_MODE     = 0x00;
const uint8_t _ALCOHOL2_READ_ONLY_MODE = 0x01;
         
const uint8_t _ALCOHOL2_EXT_TIA_RES      = 0x00;
const uint8_t _ALCOHOL2_2750_OHM_TIA_RES = 0x04;
const uint8_t _ALCOHOL2_3500_OHM_TIA_RES = 0x08;
const uint8_t _ALCOHOL2_7K_OHM_TIA_RES   = 0x0C;
const uint8_t _ALCOHOL2_14K_OHM_TIA_RES  = 0x10;
const uint8_t _ALCOHOL2_35K_OHM_TIA_RES  = 0x14;
const uint8_t _ALCOHOL2_120K_OHM_TIA_RES = 0x18;
const uint8_t _ALCOHOL2_350K_OHM_TIA_RES = 0x1C;
const uint8_t _ALCOHOL2_10_OHM_LOAD_RES  = 0x00;
const uint8_t _ALCOHOL2_33_OHM_LOAD_RES  = 0x01;
const uint8_t _ALCOHOL2_50_OHM_LOAD_RES  = 0x02;
const uint8_t _ALCOHOL2_100_OHM_LOAD_RES = 0x03;
         
const uint8_t _ALCOHOL2_VREF_INT             = 0x00;
const uint8_t _ALCOHOL2_VREF_EXT             = 0x80;
const uint8_t _ALCOHOL2_20_PERCENTS_INT_ZERO = 0x00;
const uint8_t _ALCOHOL2_50_PERCENTS_INT_ZERO = 0x20;
const uint8_t _ALCOHOL2_67_PERCENTS_INT_ZERO = 0x40;
const uint8_t _ALCOHOL2_INT_ZERO_BYPASSED    = 0x60;
const uint8_t _ALCOHOL2_BIAS_POL_NEGATIVE    = 0x00;
const uint8_t _ALCOHOL2_BIAS_POL_POSITIVE    = 0x10;
const uint8_t _ALCOHOL2_0_PERCENTS_BIAS      = 0x00;
const uint8_t _ALCOHOL2_1_PERCENT_BIAS       = 0x01;
const uint8_t _ALCOHOL2_2_PERCENTS_BIAS      = 0x02;
const uint8_t _ALCOHOL2_4_PERCENTS_BIAS      = 0x03;
const uint8_t _ALCOHOL2_6_PERCENTS_BIAS      = 0x04;
const uint8_t _ALCOHOL2_8_PERCENTS_BIAS      = 0x05;
const uint8_t _ALCOHOL2_10_PERCENTS_BIAS     = 0x06;
const uint8_t _ALCOHOL2_12_PERCENTS_BIAS     = 0x07;
const uint8_t _ALCOHOL2_14_PERCENTS_BIAS     = 0x08;
const uint8_t _ALCOHOL2_16_PERCENTS_BIAS     = 0x09;
const uint8_t _ALCOHOL2_18_PERCENTS_BIAS     = 0x0A;
const uint8_t _ALCOHOL2_20_PERCENTS_BIAS     = 0x0B;
const uint8_t _ALCOHOL2_22_PERCENTS_BIAS     = 0x0C;
const uint8_t _ALCOHOL2_24_PERCENTS_BIAS     = 0x0D;
         
const uint8_t _ALCOHOL2_FET_DIS             = 0x00;
const uint8_t _ALCOHOL2_FET_EN              = 0x80;
const uint8_t _ALCOHOL2_DEEP_SLEEP_MODE     = 0x00;
const uint8_t _ALCOHOL2_2_LEAD_MODE         = 0x01;
const uint8_t _ALCOHOL2_STANDBY_MODE        = 0x02;
const uint8_t _ALCOHOL2_3_LEAD_MODE         = 0x03;
const uint8_t _ALCOHOL2_TEMP_MODE_TIA_OFF   = 0x06;
const uint8_t _ALCOHOL2_TEMP_MODE_TIA_ON    = 0x07;
               
const uint8_t _ALCOHOL2_DEVICE_EN           = 0x00;
const uint8_t _ALCOHOL2_DEVICE_DIS          = 0x01;

const uint8_t ADC_DEVICE_ADDR          = 0x4D;


/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __ALCOHOL2_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */


/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __ALCOHOL2_DRV_SPI__

void alcohol2_spiDriverInit(T_ALCOHOL2_P gpioObj, T_ALCOHOL2_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __ALCOHOL2_DRV_I2C__

void alcohol2_i2cDriverInit(T_ALCOHOL2_P gpioObj, T_ALCOHOL2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
 
    hal_gpio_rstSet( 1 );
}

#endif
#ifdef   __ALCOHOL2_DRV_UART__

void alcohol2_uartDriverInit(T_ALCOHOL2_P gpioObj, T_ALCOHOL2_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

}

#endif


/* ----------------------------------------------------------- IMPLEMENTATION */

void alcohol2_writeByte( uint8_t reg, uint8_t _data )
{
    uint8_t writeReg[ 2 ];
    
    writeReg[ 0 ] = reg;
    writeReg[ 1 ] = _data;
    
    alcohol2_enable( _ALCOHOL2_DEVICE_EN );
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 2, END_MODE_STOP );
    alcohol2_enable( _ALCOHOL2_DEVICE_DIS );
}

uint8_t alcohol2_readByte( uint8_t reg )
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 1 ];
    
    writeReg[ 0 ] = reg;
    
    alcohol2_enable( _ALCOHOL2_DEVICE_EN );
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, readReg, 1, END_MODE_STOP );
    alcohol2_enable( _ALCOHOL2_DEVICE_DIS );
    
    return readReg[ 0 ];
}

void alcohol2_enable( uint8_t state )
{
    Delay_10us();
    hal_gpio_rstSet( state );
}

uint16_t alcohol2_readAlcohol()
{
    uint8_t readData[ 2 ];
    uint16_t ADC_data;
    
    hal_i2cStart();
    hal_i2cRead( ADC_DEVICE_ADDR, readData, 2, END_MODE_STOP );
    
    ADC_data = readData[ 0 ];
    ADC_data <<= 8;
    ADC_data |= readData[ 1 ];
        
    return ADC_data;
}

void alcohol2_waitReady()
{
    uint8_t i2cBusy;

    i2cBusy = alcohol2_readByte( _ALCOHOL2_STATUS_REG );
    while (!(i2cBusy & 0x01))
    {
        i2cBusy = alcohol2_readByte( _ALCOHOL2_STATUS_REG );
    }
}


/* -------------------------------------------------------------------------- */
/*
  __alcohol2_driver.c

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