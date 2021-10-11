/** @file tmr.c
 *  @brief The implementation for the timer.
 */

#include "tmr_cfg.h"				/* For timer configuration definitions */
#include "constants.h"				/* For REGBIT definitions */
#include "mcu_cfg.h"				/* For GetSystemClock() definition */

/**
 * Divider value used in timer period register calculation
 */
#define TMR_PERIOD_DIV				1000000UL

/**
 *  Defines a table of pointers to the timer modulo registers on the microcontroller.
 */
static TYPE volatile * const modreg[NUM_TIMERS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the timer status and control registers on the microcontroller.
 */
static TYPE volatile * const tmrreg[NUM_TIMERS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the timer counter registers on the microcontroller.
 */
static TYPE volatile * const tmrcnt[NUM_TIMERS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a pointer to the System Options Register 2 on the microcontroller.
 */
static TYPE volatile * const tmrclk = (TYPE*)&REGISTER1;

/**
 *  Defines a pointer to the System Clock Gating Control Register 6 on the microcontroller.
 */
static TYPE volatile * const tmrgate = (TYPE*)&REGISTER2;

/**
 *  Defines a table of pins for the TPM clock gate controls on the microcontroller.
 */
static const TYPE tmrpins[NUM_TIMERS] =
{
  	REGBIT1, REGBIT2
};

/**
 * Defines the Interupt IRQ values for each timer channel
 */
static uint8_t TmrIrqValue[NUM_TIMERS] =
{
	INT_TPM0,			/**< TMR0 irq value */
	INT_TPM1,			/**< TMR1 irq value */
	INT_TPM2			/**< TMR2 irq value */
};

/**
 * The following function is inline in order to decrease the complexity of 
 * function within this module. If inline is not used it should be declared
 * as static.
 */
void Tmr_ClkDivSet(uint8_t Prescaler, uint8_t Channel);

/******************************************************************************
* Function : Tmr_Init()
*
* Description:
*
* This function is used to initialize the Tmr based on the configuration table
*  defined in tmr_cfg module.
*  
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
* PRE-CONDITION: MCU clocks initialized
* PRE-CONDITION: Timer clock enabled
*
* POST-CONDITION: The TMR peripheral is setup with the configuration settings.
*
* @param  		Config is a pointer to the configuration table that contains
*				the initialization for the peripheral.
*
* @return 		void
*
* Example:
* @code
* 	const TmrConfig_t *TmrConfig = Tmr_ConfigGet();
*
* 	Tmr_Init(TmrConfig);
* @endcode
*
*******************************************************************************/
void Tmr_Init(const TmrConfig_t *Config)
{

}

/******************************************************************************
* Function : Tmr_ClkDivSet()
* 
* Description:
*
* This function is used to set the clock divider for the timer module.
*  
* PRE-CONDITION: Tmer_Init must be called
* PRE-CONDITION: MCU clocks initialized
* PRE-CONDITION: Timer clock enabled
*
* POST-CONDITION: The TMR peripheral is setup with the clock settings.
*
* @param  		Prescaler - the prescaler to set the clock to
* @param		Channel - the timer channel to configure
*
* @return 		void
*
* Example:
* @code
* 	// Set the chosen timer clock input divider
*	Tmr_ClkDivSet(Config[i].ClkPrescaler , i);
*
* @endcode
*
*******************************************************************************/
inline void Tmr_ClkDivSet(uint8_t Prescaler, uint8_t Channel)
{

}

/******************************************************************************
* Function : Tmr_Enable()
* 
* Description:
*
* This function enables and starts the specified timer channel.
*  
* PRE-CONDITION: Tmer_Init must be called
* PRE-CONDITION: MCU clocks initialized
* PRE-CONDITION: Timer clock enabled
*
* POST-CONDITION: The timer channel is enabled in the specified mode
*
* @param     Channel - TmrRegister_t, The timer channel to set.
* @param     Mode - TmrRegister_t, The timer channel to set.
*
* @return 		void
*
* Example:
* @code
* 	const TmrConfig_t *TmrConfig = Tmr_ConfigGet();
*
* 	Tmr_Init(TmrConfig);
*   Tmr_Enable(TIMER_0, MODE_COUNT_UP);
*
* @endcode
*
*******************************************************************************/
void Tmr_Enable(TmrRegister_t Channel, TmrClockMode_t Mode)
{

}

/******************************************************************************
* Function : Tmr_Disable()
* 
* Description:
*
* This function disables the specified timer channel.
*  
* PRE-CONDITION: Tmer_Init must be called
* PRE-CONDITION: MCU clocks initialized
* PRE-CONDITION: Timer clock enabled
*
* POST-CONDITION: The timer channel is disabled.
*
* @param     Channel - TmrRegister_t, The timer channel to set.
*
* @return 		void
*
* Example:
* @code
* 	const TmrConfig_t *TmrConfig = Tmr_ConfigGet();
*
* 	Tmr_Init(TmrConfig);
*   Tmr_Enable(TIMER_0, MODE_COUNT_UP);
*   ...
*   Tmr_Disable(TIMER_0);
*
* @endcode
*
*******************************************************************************/
void Tmr_Disable(TmrRegister_t Channel)
{

}

/******************************************************************************
* Function : Tmr_RegisterWrite()
* 
* Description:
*
*  This function is used to directly address and modify a Tmr register.  The 
*  function should be used to access specialized functionality in the Tmr peripheral
*  that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the Tmr register address space
*
* POST-CONDITION: The register located at Address with be updated with Value
*
* @param  		Address is a register address within the Tmr peripheral map
* @param      Value is the value to set the Tmr register to
*
* @return 		void
*
* Example:
* @code
*    Tmr_RegisterWrite(0x1000, 0x15);
* @endcode
*
*******************************************************************************/
void Tmr_RegisterWrite(uint32_t Address, uint32_t Value)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   *RegisterPointer = Value;
}

/******************************************************************************
* Function : Tmr_RegisterRead()
* 
* Description:
*
* This function is used to directly address a Tmr register.  The function 
* should be used to access specialized functionality in the Tmr peripheral
* that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the Tmr register address space
*
* POST-CONDITION: The value stored in the register is returned to the caller
*
* @param  		Address is the address of the Tmr register to read
*
* @return 		The current value of the Tmr register.
*
* Example:
* @code
*    TmrValue = Tmr_RegisterRead(0x1000);
* @endcode
*
*******************************************************************************/
uint32_t Tmr_RegisterRead(uint32_t Address)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   return *RegisterPointer;
}

/******************************************************************************
* Function : Adc_CallbackRegister()
* 
* Description:
*
* This function is used to set the callback functions of the tmr driver. By 
* default, the callbacks are initialized to a NULL pointer. The driver may 
* contain more than one possible callback, so the function will take a parameter
* to configure the specified callback. 
*
* PRE-CONDITION: The TmrCallback_t has been populated
* PRE-CONDITION: The callback function exists within memory.
*
* POST-CONDITION: The specified callback function will be registered with the
* driver. 
*
* @param  		Function is the callback function that will be registered
* @param 		CallbackFunction is a function pointer to the desired function
*
* @return 		None.
*
* Example:
* @code
*    TmrCallback_t Tmr_Function = TMR_SAMPLE_COMPLETE; 
*    
*    Tmr_CallbackRegister(Tmr_Function, Tmr_SampleAverage);
* @endcode
*
*******************************************************************************/
void Tmr_CallbackRegister(TmrCallback_t Function, TYPE (*CallbackFunction)(type))
{

}

