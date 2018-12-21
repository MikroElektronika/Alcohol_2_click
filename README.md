![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Alcohol2 Click

- **CIC Prefix**  : ALCOHOL2
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : jul 2018.

---

### Software Support

We provide a library for the Alcohol2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2485/alcohol-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register.
The library includes function for read Alcohol data.


Key functions :

- ``` uint16_t alcohol2_readAlcohol() ``` - Function for read Alcohol data
- ``` void alcohol2_writeByte( uint8_t reg, uint8_t _data ) ``` - Function writes one byte to the register.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C bus and set AN pin as INPUT and RST pin as OUTPUT.
- Application Initialization - Initializes I2C driver and device configuration.
- Application Task - (code snippet) - Gets Alcohol (C2H5OH) data and logs data to USBUART every 500ms.


```.c
void applicationTask()
{
    Alcohol_Value = alcohol2_readAlcohol();
    FloatToStr( Alcohol_Value, demoText );
    mikrobus_logWrite( "Alcohol value : ", _LOG_TEXT );
    mikrobus_logWrite( demoText, _LOG_LINE );
    Delay_ms( 500 );
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2485/alcohol-2-click) page.

Other mikroE Libraries used in the example:

- I2C
- Conversions 

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
