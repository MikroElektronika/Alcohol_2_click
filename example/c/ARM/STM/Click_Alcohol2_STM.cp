#line 1 "C:/Users/katarina.perendic/Desktop/alcohol 2/example/c/ARM/STM/Click_Alcohol2_STM.c"
#line 1 "c:/users/katarina.perendic/desktop/alcohol 2/example/c/arm/stm/click_alcohol2_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "c:/users/katarina.perendic/desktop/alcohol 2/example/c/arm/stm/click_alcohol2_config.h"
#line 1 "c:/users/katarina.perendic/desktop/alcohol 2/example/c/arm/stm/click_alcohol2_types.h"
#line 19 "c:/users/katarina.perendic/desktop/alcohol 2/example/c/arm/stm/click_alcohol2_config.h"
const uint32_t _ALCOHOL2_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "c:/users/katarina.perendic/desktop/alcohol 2/library/__alcohol2_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 57 "c:/users/katarina.perendic/desktop/alcohol 2/library/__alcohol2_driver.h"
extern const uint8_t _ALCOHOL2_STATUS_REG ;
extern const uint8_t _ALCOHOL2_LOCK_REG ;
extern const uint8_t _ALCOHOL2_TIACN_REG ;
extern const uint8_t _ALCOHOL2_REFCN_REG ;
extern const uint8_t _ALCOHOL2_MODECN_REG ;

extern const uint8_t _ALCOHOL2_WRITE_MODE ;
extern const uint8_t _ALCOHOL2_READ_ONLY_MODE;

extern const uint8_t _ALCOHOL2_EXT_TIA_RES ;
extern const uint8_t _ALCOHOL2_2750_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_3500_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_7K_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_14K_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_35K_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_120K_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_350K_OHM_TIA_RES ;
extern const uint8_t _ALCOHOL2_10_OHM_LOAD_RES ;
extern const uint8_t _ALCOHOL2_33_OHM_LOAD_RES ;
extern const uint8_t _ALCOHOL2_50_OHM_LOAD_RES ;
extern const uint8_t _ALCOHOL2_100_OHM_LOAD_RES ;

extern const uint8_t _ALCOHOL2_VREF_INT ;
extern const uint8_t _ALCOHOL2_VREF_EXT ;
extern const uint8_t _ALCOHOL2_20_PERCENTS_INT_ZERO ;
extern const uint8_t _ALCOHOL2_50_PERCENTS_INT_ZERO ;
extern const uint8_t _ALCOHOL2_67_PERCENTS_INT_ZERO ;
extern const uint8_t _ALCOHOL2_INT_ZERO_BYPASSED ;
extern const uint8_t _ALCOHOL2_BIAS_POL_NEGATIVE ;
extern const uint8_t _ALCOHOL2_BIAS_POL_POSITIVE ;
extern const uint8_t _ALCOHOL2_0_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_1_PERCENT_BIAS ;
extern const uint8_t _ALCOHOL2_2_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_4_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_6_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_8_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_10_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_12_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_14_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_16_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_18_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_20_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_22_PERCENTS_BIAS ;
extern const uint8_t _ALCOHOL2_24_PERCENTS_BIAS ;

extern const uint8_t _ALCOHOL2_FET_DIS ;
extern const uint8_t _ALCOHOL2_FET_EN ;
extern const uint8_t _ALCOHOL2_DEEP_SLEEP_MODE ;
extern const uint8_t _ALCOHOL2_2_LEAD_MODE ;
extern const uint8_t _ALCOHOL2_STANDBY_MODE ;
extern const uint8_t _ALCOHOL2_3_LEAD_MODE ;
extern const uint8_t _ALCOHOL2_TEMP_MODE_TIA_OFF ;
extern const uint8_t _ALCOHOL2_TEMP_MODE_TIA_ON ;

extern const uint8_t _ALCOHOL2_DEVICE_EN ;
extern const uint8_t _ALCOHOL2_DEVICE_DIS ;

extern const uint8_t ADC_DEVICE_ADDR ;
#line 128 "c:/users/katarina.perendic/desktop/alcohol 2/library/__alcohol2_driver.h"
void alcohol2_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 135 "c:/users/katarina.perendic/desktop/alcohol 2/library/__alcohol2_driver.h"
void alcohol2_gpioDriverInit( const uint8_t*  gpioObj);
#line 146 "c:/users/katarina.perendic/desktop/alcohol 2/library/__alcohol2_driver.h"
void alcohol2_writeByte( uint8_t reg, uint8_t _data );
#line 155 "c:/users/katarina.perendic/desktop/alcohol 2/library/__alcohol2_driver.h"
uint8_t alcohol2_readByte( uint8_t reg );
#line 160 "c:/users/katarina.perendic/desktop/alcohol 2/library/__alcohol2_driver.h"
void alcohol2_waitReady( void );
#line 165 "c:/users/katarina.perendic/desktop/alcohol 2/library/__alcohol2_driver.h"
void alcohol2_enable( uint8_t state );
#line 172 "c:/users/katarina.perendic/desktop/alcohol 2/library/__alcohol2_driver.h"
uint16_t alcohol2_readAlcohol();
#line 31 "C:/Users/katarina.perendic/Desktop/alcohol 2/example/c/ARM/STM/Click_Alcohol2_STM.c"
float Alcohol_Value;
char demoText[ 50 ];

void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_i2cInit( _MIKROBUS1, &_ALCOHOL2_I2C_CFG[0] );
 mikrobus_logInit( _LOG_USBUART_A, 115200 );
 Delay_ms( 100 );
}

void applicationInit()
{
 alcohol2_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x48 );

 alcohol2_writeByte( _ALCOHOL2_MODECN_REG, _ALCOHOL2_DEEP_SLEEP_MODE );
 alcohol2_writeByte( _ALCOHOL2_LOCK_REG, _ALCOHOL2_WRITE_MODE );
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
