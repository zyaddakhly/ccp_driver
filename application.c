/* 
 * File:   application.c
 * Author: zyadi
 *
 * Created on August 18, 2023, 8:01 AM
 */

/*---------------------------Section Include-----------------------------------------------*/
#include "application.h"

/*---------------------------Function Declaration -----------------------------------------------*/
void application_init(void);
void call_timer(void);
void call_ccp(void);


/*--------------------------- Global Variable -----------------------------------------------*/
Std_ReturnType ret;

volatile unsigned long timer_flag = 0;
volatile uint16 cap_value = 0;
volatile unsigned long cc1_second_flag = 0;
volatile unsigned long total_period_micro_second = 0;
volatile unsigned long freq= 0;
volatile uint8 str[6];
volatile uint16 freq2= 0;



ccp1_t _ccp1 = 
{
    .CCP1_INterruptHandler = call_ccp,
    .ccp1_mode = CCP1_CAPTURE_MODE_SELECT,
    .ccp1_mode_variant = CCP1_CAPUTURE_MOCDE_1_FALLING_EDGE,
    .pin.port = PORTC_INDEX,
    .pin.pin  = GPIO_PIN2,
    .pin.direction = GPIO_OUTPUT,
    .pin.logic = GPIO_INPUT,
    .ccp1_capture_timer = CCP1_CCP2_TIMER3,
};
timer3_t timer3 = 
{
    .TIMER3_INterruptHandler = call_timer,
    .timer3_mode = TIMER3_TIMER_MODE,
    .prescaler_vlaue = TIMER3_PRESCALER_DIV_BY_1,
    .timer3_register_rw_mode = TIMER3_8BIT_RW_REG_MODE,
    .timer3_preload_value = 0
            
    
};



int main() {
    
    application_init();
    ret = Timer3_Init(&timer3);
    ret = CCP1_Init(&_ccp1);
    ret = lcd_4bit_send_string_pos(&lcd_1, 1, 5, "**********");
    ret = lcd_4bit_send_string_pos(&lcd_1, 2, 1, "Freq = ");
            

    while(1)
    {
        if(cc1_second_flag == 2)
        {
            total_period_micro_second = (timer_flag *65536)+ cap_value;
            freq = (1/(total_period_micro_second/1000000.0));
            freq2 = freq;
            ret = convert_short_to_str(freq2,str);
            ret = lcd_4bit_send_string_pos(&lcd_1, 2, 9, str);
            cc1_second_flag = 0;
        }
    }
  


    return 0;
}



void application_init(void)
{
    Std_ReturnType ret = E_OK;
    ecu_initialize();


}
void call_ccp(void)
{
    static uint32 cc1_flag = 0;

    cc1_flag++;
    cc1_second_flag++;
    if(cc1_flag == 1)
    {
     ret =  Timer3_Write_Value(&timer3,0);
    }
    else if ( cc1_flag == 2)
    {
        cc1_flag = 0;
        timer_flag = 0;
        ret = CCP1_Capture_Mode_Read_Value(&cap_value);
    }
}
void call_timer(void)
{
    timer_flag++;
}