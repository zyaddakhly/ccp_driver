#ifndef _MCAL_INTERNAL_INTERRUPT_H_
#define _MCAL_INTERNAL_INTERRUPT_H_

/*Section : Include*/
#include "mcal_interrupt_config.h"

/*Section : Macro Defination*/


/*ADC*/
#if ADC_INTERRUPT_FEATURE == FEATURE_ENALE

/*Disable the ADC interrupt */
#define ADC_InterruptDisable()     (PIE1bits.ADIE = 0)
/*Enable the ADC intrrupt */
#define ADC_InterruptEnable()      ( PIE1bits.ADIE= 1)
/*Clear flag bit for ADC */
#define ADC_InterruptFlagClear()   (PIR1bits.ADIF = 0)

#if INTERUPT_PRIORITY_LEVELS_ENABLE == FEATURE_ENALE
/*Make ADC HIGH Priority*/
#define ADC_HighPrioritySet()       (IPR1bits.ADIP = 1)
/*Make ADC Low Priority*/
#define ADC_LowPrioritySet()        (IPR1bits.ADIP  = 0)

#endif
#endif



/*TIMER0*/
/*Section : Macro Defination*/
#if TIMER0_INTERRUPT_FEATURE == FEATURE_ENALE

/*Disable the ADC interrupt */
#define TIMER0_InterruptDisable()     (INTCONbits.T0IE = 0)
/*Enable the ADC intrrupt */
#define TIMER0_InterruptEnable()      ( INTCONbits.T0IE = 1)
/*Clear flag bit for ADC */
#define TIMER0_InterruptFlagClear()   (INTCONbits.TMR0IF = 0)

#if INTERUPT_PRIORITY_LEVELS_ENABLE == FEATURE_ENALE
/*Make ADC HIGH Priority*/
#define TIMER0_HighPrioritySet()       (INTCON2bits.TMR0IP = 1)
/*Make ADC Low Priority*/
#define TIMER0_LowPrioritySet()        (INTCON2bits.TMR0IP  = 0)


#endif
#endif


/*TIMER1*/
/*Section : Macro Defination*/
#if TIMER1_INTERRUPT_FEATURE == FEATURE_ENALE

/*Disable the ADC interrupt */
#define TIMER1_InterruptDisable()     (PIE1bits.TMR1IE = 0)
/*Enable the ADC intrrupt */
#define TIMER1_InterruptEnable()      ( PIE1bits.TMR1IE = 1)
/*Clear flag bit for ADC */
#define TIMER1_InterruptFlagClear()   (PIR1bits.TMR1IF = 0)

#if INTERUPT_PRIORITY_LEVELS_ENABLE == FEATURE_ENALE
/*Make ADC HIGH Priority*/
#define TIMER1_HighPrioritySet()       (IPR1bits.TMR1IP= 1)
/*Make ADC Low Priority*/
#define TIMER1_LowPrioritySet()        (IPR1bits.TMR1IP = 0)


#endif
#endif

/*TIMER2*/
/*Section : Macro Defination*/
#if TIMER2_INTERRUPT_FEATURE == FEATURE_ENALE

/*Disable the ADC interrupt */
#define TIMER2_InterruptDisable()     (PIE1bits.TMR2IE= 0)
/*Enable the ADC intrrupt */
#define TIMER2_InterruptEnable()      ( PIE1bits.TMR2IE = 1)
/*Clear flag bit for ADC */
#define TIMER2_InterruptFlagClear()   (PIR1bits.TMR2IF = 0)

#if INTERUPT_PRIORITY_LEVELS_ENABLE == FEATURE_ENALE
/*Make ADC HIGH Priority*/
#define TIMER2_HighPrioritySet()       (IPR1bits.TMR2IP= 1)
/*Make ADC Low Priority*/
#define TIMER2_LowPrioritySet()        (IPR1bits.TMR2IP = 0)


#endif
#endif


#if TIMER3_INTERRUPT_FEATURE == FEATURE_ENALE

/*Disable the ADC interrupt */
#define TIMER3_InterruptDisable()     (PIE2bits.TMR3IE= 0)
/*Enable the ADC intrrupt */
#define TIMER3_InterruptEnable()      ( PIE2bits.TMR3IE = 1)
/*Clear flag bit for ADC */
#define TIMER3_InterruptFlagClear()   (PIR2bits.TMR3IF = 0)

#if INTERUPT_PRIORITY_LEVELS_ENABLE == FEATURE_ENALE
/*Make ADC HIGH Priority*/
#define TIMER3_HighPrioritySet()       (IPR2bits.TMR3IP= 1)
/*Make ADC Low Priority*/
#define TIMER3_LowPrioritySet()        (IPR2bits.TMR3IP = 0)


#endif
#endif
/*CCP1*/
#if CCP1_INTERRUPT_FEATURE == FEATURE_ENALE

/*Disable the CCP1 interrupt */
#define CCP1_InterruptDisable()     (PIE1bits.CCP1IE= 0)
/*Enable the CCP1 intrrupt */
#define CCP1_InterruptEnable()      ( PIE1bits.CCP1IE = 1)
/*Clear flag bit for CCP1 */
#define CCP1_InterruptFlagClear()   (PIR1bits.CCP1IF = 0)

#if INTERUPT_PRIORITY_LEVELS_ENABLE == FEATURE_ENALE
/*Make CCP1 HIGH Priority*/
#define CCP1_HighPrioritySet()       (IPR1bits.CCP1IP= 1)
/*Make CCP1 Low Priority*/
#define CCP1_LowPrioritySet()        (IPR1bits.CCP1IP = 0)


#endif
#endif


/*CCP2*/
#if CCP2_INTERRUPT_FEATURE == FEATURE_ENALE

/*Disable the CCP1 interrupt */
#define CCP2_InterruptDisable()     (PIE2bits.CCP2IE= 0)
/*Enable the CCP1 intrrupt */
#define CCP2_InterruptEnable()      ( PIE2bits.CCP2IE = 1)
/*Clear flag bit for CCP1 */
#define CCP2_InterruptFlagClear()   (PIR2bits.CCP2IF = 0)

#if INTERUPT_PRIORITY_LEVELS_ENABLE == FEATURE_ENALE
/*Make CCP1 HIGH Priority*/
#define CCP2_HighPrioritySet()       (IPR2bits.CCP2IP= 1)
/*Make CCP1 Low Priority*/
#define CCP2_LowPrioritySet()        (IPR2bits.CCP2IP = 0)


#endif
#endif


#endif