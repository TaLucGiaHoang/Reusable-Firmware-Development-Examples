/** @file tmr_cfg.c
 *  @brief This module contains the configuration for the tmr module
 */
#include "tmr_cfg.h"				// For this module's definitions
#include "constants.h"				// For DISABLED, ENABLED, etc

/**
* This configuration table is used to configure the behavior and function of
* the timers.  The channels are defined in tmr_cfg.h.  The configuration
* consists of
*
*  o Timer Name - Specify the name of the timer. This label must be defined in
*      the Tmr_RegisterType enumeration.
*  o Timer Enable - Enable or disable the specified timer channel.
*  o Timer Mode - Specify the mode of the timer.  Timer modes are defined in the
*      Tmr_CounterEnum enumeration.
*  o Clock Source - Specify the source of the timer clock.  All channels
*      must use the same clock source, so only TMR0 clock source is used.
*  o Clock Mode Selection - Specify the clock mode.  Clock modes are defined in
*	   the Tmr_ClkModeType enumeration.
*  o Clock Prescaler - Specify the clock input divider.
*  o Interrupt Enable - This sets whether the interrupt for this timer is enabled.
*     DISABLED  - Sets the interrupt enable bit low
*     ENABLED - Sets the interrupt enable bit high
*  o Timer Interval - Specify the period of the timer in microseconds.
*******************************************************************************/
const TmrConfig_t TmrConfig[] =
{
// Timer  Timer     Timer     Clock           Clock Mode  Clock      Interrupt  Interrupt  Timer
// Name   Enable    Mode      Source          Selection   Prescaler  Enable     Priority   Interval (us)
//                            
 {TMR0,   ENABLED,  UP_COUNT, FLL_PLL,        MODULE_CLK, TMR_DIV_1, DISABLED,  3,         100},
 {TMR1,   DISABLED, UP_COUNT, NOT_APPLICABLE, STOP,       TMR_DIV_1, DISABLED,  0,         0  },
 {TMR2,   ENABLED,  UP_COUNT, FLL_PLL,        MODULE_CLK, TMR_DIV_1, DISABLED,  3,         100},
};

/******************************************************************************
* Function : Tmr_ConfigGet()
* 
* Description:
*
* This function return a pointer to the Tmr configuration structure. 
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
*
* POST-CONDITION: A constant pointer to the first member of the configuration
* table will be returned.
*
* @return   A pointer to the configuration table.
*
* Example Example:
* @code
*  const TmrConfig_t * TmrConfig = Tmr_ConfigGet();
*
*  Tmr_Init(TmrConfig);
* @endcode
*
*
*******************************************************************************/
const TmrConfig_t * Tmr_ConfigGet(void)
{
 return TmrConfig;
}

/*** End of File **************************************************************/

