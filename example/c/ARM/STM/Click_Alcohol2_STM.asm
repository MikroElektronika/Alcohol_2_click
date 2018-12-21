_systemInit:
;Click_Alcohol2_STM.c,34 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Alcohol2_STM.c,36 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #0
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Alcohol2_STM.c,37 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Alcohol2_STM.c,38 :: 		mikrobus_i2cInit( _MIKROBUS1, &_ALCOHOL2_I2C_CFG[0] );
MOVW	R0, #lo_addr(__ALCOHOL2_I2C_CFG+0)
MOVT	R0, #hi_addr(__ALCOHOL2_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Alcohol2_STM.c,39 :: 		mikrobus_logInit( _LOG_USBUART_A, 115200 );
MOV	R1, #115200
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Alcohol2_STM.c,40 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Alcohol2_STM.c,41 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Alcohol2_STM.c,43 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Alcohol2_STM.c,45 :: 		alcohol2_i2cDriverInit( (T_ALCOHOL2_P)&_MIKROBUS1_GPIO, (T_ALCOHOL2_P)&_MIKROBUS1_I2C, 0x48 );
MOVS	R2, #72
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_alcohol2_i2cDriverInit+0
;Click_Alcohol2_STM.c,47 :: 		alcohol2_writeByte( _ALCOHOL2_MODECN_REG, _ALCOHOL2_DEEP_SLEEP_MODE );
MOVS	R1, __ALCOHOL2_DEEP_SLEEP_MODE
MOVS	R0, __ALCOHOL2_MODECN_REG
BL	_alcohol2_writeByte+0
;Click_Alcohol2_STM.c,48 :: 		alcohol2_writeByte( _ALCOHOL2_LOCK_REG,   _ALCOHOL2_WRITE_MODE );
MOVS	R1, __ALCOHOL2_WRITE_MODE
MOVS	R0, __ALCOHOL2_LOCK_REG
BL	_alcohol2_writeByte+0
;Click_Alcohol2_STM.c,49 :: 		alcohol2_writeByte( _ALCOHOL2_TIACN_REG, _ALCOHOL2_EXT_TIA_RES | _ALCOHOL2_100_OHM_LOAD_RES );
MOVS	R0, __ALCOHOL2_EXT_TIA_RES
ORR	R0, R0, __ALCOHOL2_100_OHM_LOAD_RES
UXTB	R1, R0
MOVS	R0, __ALCOHOL2_TIACN_REG
BL	_alcohol2_writeByte+0
;Click_Alcohol2_STM.c,50 :: 		alcohol2_writeByte( _ALCOHOL2_REFCN_REG, _ALCOHOL2_VREF_INT | _ALCOHOL2_50_PERCENTS_INT_ZERO | _ALCOHOL2_BIAS_POL_NEGATIVE | _ALCOHOL2_0_PERCENTS_BIAS );
MOVS	R0, __ALCOHOL2_VREF_INT
ORR	R0, R0, __ALCOHOL2_50_PERCENTS_INT_ZERO
UXTB	R0, R0
ORR	R0, R0, __ALCOHOL2_BIAS_POL_NEGATIVE
UXTB	R0, R0
ORR	R0, R0, __ALCOHOL2_0_PERCENTS_BIAS
UXTB	R1, R0
MOVS	R0, __ALCOHOL2_REFCN_REG
BL	_alcohol2_writeByte+0
;Click_Alcohol2_STM.c,51 :: 		mikrobus_logWrite( "Alcohol 2 is initialized", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr1_Click_Alcohol2_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_Alcohol2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Alcohol2_STM.c,52 :: 		Delay_ms( 300 );
MOVW	R7, #61055
MOVT	R7, #54
NOP
NOP
L_applicationInit2:
SUBS	R7, R7, #1
BNE	L_applicationInit2
NOP
NOP
NOP
;Click_Alcohol2_STM.c,53 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Alcohol2_STM.c,55 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Alcohol2_STM.c,57 :: 		Alcohol_Value = alcohol2_readAlcohol();
BL	_alcohol2_readAlcohol+0
BL	__UnsignedIntegralToFloat+0
MOVW	R1, #lo_addr(_Alcohol_Value+0)
MOVT	R1, #hi_addr(_Alcohol_Value+0)
STR	R0, [R1, #0]
;Click_Alcohol2_STM.c,58 :: 		FloatToStr( Alcohol_Value, demoText );
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_Alcohol2_STM.c,59 :: 		mikrobus_logWrite( "Alcohol value : ", _LOG_TEXT );
MOVW	R0, #lo_addr(?lstr2_Click_Alcohol2_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_Alcohol2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Alcohol2_STM.c,60 :: 		mikrobus_logWrite( demoText, _LOG_LINE );
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Alcohol2_STM.c,61 :: 		Delay_ms( 500 );
MOVW	R7, #36223
MOVT	R7, #91
NOP
NOP
L_applicationTask4:
SUBS	R7, R7, #1
BNE	L_applicationTask4
NOP
NOP
NOP
;Click_Alcohol2_STM.c,62 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Alcohol2_STM.c,64 :: 		void main()
;Click_Alcohol2_STM.c,66 :: 		systemInit();
BL	_systemInit+0
;Click_Alcohol2_STM.c,67 :: 		applicationInit();
BL	_applicationInit+0
;Click_Alcohol2_STM.c,69 :: 		while (1)
L_main6:
;Click_Alcohol2_STM.c,71 :: 		applicationTask();
BL	_applicationTask+0
;Click_Alcohol2_STM.c,72 :: 		}
IT	AL
BAL	L_main6
;Click_Alcohol2_STM.c,73 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
