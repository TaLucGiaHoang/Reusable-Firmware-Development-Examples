/** @file tmr_cfg.h
 *  @brief This module contains the configuration interface for timer
 */
#ifndef TMR_CFG_H_
#define TMR_CFG_H_
#include <stdint.h>				// For standard type definitions

/**
 *  Defines the timer clock input dividers
 */
typedef enum 
{
	TMR_DIV_1 = 1,			/**< Timer prescalar of 1:1 */
	TMR_DIV_2 = 2,			/**< Timer prescalar of 1:2 */
	TMR_DIV_4 = 4,			/**< Timer prescalar of 1:4 */
	TMR_DIV_8 = 8,			/**< Timer prescalar of 1:8 */
	TMR_DIV_16 = 16,		/**< Timer prescalar of 1:16 */
	TMR_DIV_32 = 32,		/**< Timer prescalar of 1:32 */
	TMR_DIV_64 = 64,		/**< Timer prescalar of 1:64 */
	TMR_DIV_128 = 128		/**< Timer prescalar of 1:128 */
}TmrPrescale_t;

/**
 *  Defines the counter modes for the timer.
 */
typedef enum 
{
	UP_COUNT,			/**< LPTPM counter operates in up counting mode. */
	UP_DOWN				/**< LPTPM counter operates in up-down counting mode. */
}TmrCounter_t;

/**
 *  Defines the clock sources for the timer.
 */
typedef enum 
{
	FLL_PLL = 1,		/**< Use the FLL or PLL clock */
	OSCERCLK,			/**< Oscillator clock frequency */
	INT_CLK				/**< Internal clock */
}TmrClkSrc_t;


/**
 * Defines the timer configuration table elements that are used
 * by Tmr_Init to configure the timer registers.
 */
typedef struct
{
	uint16_t TimerChannel;		    /**< Name of Timer */
	uint16_t TimerEnable;			/**< ENABLED or DISABLED Timer channel*/
	uint16_t TimerMode;		  	    /**< Timer Counter Mode Setting */
	uint16_t ClockSource;			/**< Timer Clock Source Setting */
	uint16_t ClkMode;				/**< Timer Clock Mode Select */
	uint16_t ClkPrescaler;  		/**< Clock input divider */
    uint16_t IntEnabled;			/**< Timer Interrupt Enable - ENABLED or DISABLED */
	uint16_t IntPriority;			/**< Timer Interrupt Priority */
	uint16_t Interval;				/**< Timer interval in microseconds */
}TmrConfig_t;

/**
 *  This enumeration is a list of the timer channels
 */
typedef enum
{
	TMR0 = 0U,	       	/**< Timer 0 */
	TMR1 = 1U,         	/**< Timer 1 */
	TMR2 = 2U,         	/**< Timer 2 */
	NUM_TIMERS = 3U		/**< Number of timers on the microcontroller */
}TmrRegister_t;

/**
 *  Defines the available clock modes for the timer
 */
typedef enum
{
	STOP,				/**< LPTPM counter is disabled */
	MODULE_CLK,			/**< LPTPM counter increments on every LPTPM counter clock */
	EXTERNAL_CLK		/**< LPTPM counter increments on rising edge of LPTPM_EXTCLK synchronized to the LPTPM counter
							 clock */
}TmrClockMode_t;

#ifdef __cplusplus
extern "C"{
#endif

const TmrConfig_t * Tmr_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*TMR_CFG_H_*/

