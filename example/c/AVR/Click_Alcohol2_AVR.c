/*
Example for Alcohol2 Click

    Date          : jul 2018.
    Author        : Katarina Perendic

Test configuration AVR :
    
    MCU              : ATMEGA32
    Dev. Board       : EasyAVR v7 
    AVR Compiler ver : v7.0.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C bus and set AN pin as INPUT and RST pin as OUTPUT.
- Application Initialization - Initializes I2C driver and device configuration.
- Application Task - (code snippet) - Gets Alcohol (C2H5OH) data and logs data to USBUART every 500ms.

*/

#include "Click_Alcohol2_types.h"
#include "Click_Alcohol2_config.h"


float Alcohol_Value;
char demoText[ 50 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_ALCOHOL2_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 115200 );
    Delay_ms( 100 );
}

void applicationInit()
{
    alcohol2_i2cDriverInit( (T_ALCOHOL2_P)&_MIKROBUS1_GPIO, (T_ALCOHOL2_P)&_MIKROBUS1_I2C, 0x48 );
    
    alcohol2_writeByte( _ALCOHOL2_MODECN_REG, _ALCOHOL2_DEEP_SLEEP_MODE );
    alcohol2_writeByte( _ALCOHOL2_LOCK_REG,   _ALCOHOL2_WRITE_MODE );
    alcohol2_writeByte( _ALCOHOL2_TIACN_REG, _ALCOHOL2_EXT_TIA_RES | _ALCOHOL2_100_OHM_LOAD_RES );
    alcohol2_writeByte( _ALCOHOL2_REFCN_REG, _ALCOHOL2_VREF_INT | _ALCOHOL2_50_PERCENTS_INT_ZERO | _ALCOHOL2_BIAS_POL_NEGATIVE | _ALCOHOL2_0_PERCENTS_BIAS );
    mikrobus_logWrite( "Alcohol 2 is initialized", _LOG_LINE );
    Delay_ms( 300 );
}

void applicationTask()
{
    Alcohol_Value = alcohol2_readAlcohol();
    FloatToStr( Alcohol_Value, demoText );
    mikrobus_logWrite( "Alcohol value : ", _LOG_TEXT );
    mikrobus_logWrite( demoText, _LOG_LINE );
    Delay_ms( 500 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}