/** @file tmr.h
 *  @brief The interface definition for the timer.
 * 
 *  This is the header file for the definition of the interface for the 
 *  timer.
 */
#ifndef TMR_H_
#define TMR_H_

#include "tmr_cfg.h"		/* For timer configuration */

#ifdef __cplusplus
extern "C"{
#endif

void Tmr_Init(const TmrConfig_t * Config);
void Tmr_Enable(TmrRegister_t Channel, TmrClockMode_t Mode);
void Tmr_Disable(TmrRegister_t Channel);
void Tmr_RegisterWrite(uint32_t Address, uint32_t Value);
uint32_t Tmr_RegisterRead(uint32_t Address);
void Tmr_CallbackRegister(TmrCallback_t Function, TYPE (*CallbackFunction)(type));

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*TMR_H_*/
