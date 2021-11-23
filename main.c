#include "tm4c123gh6pm.h"
#include "lcd.h"
#include "init.h"
#include "systicDelay.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lcdTimer.h"
//#include "best_function.c"
//int time = 0 ; 








/*
void systickDelay(int time)

{
   NVIC_ST_CURRENT_R =0;                        //el current register ely hya5od el value
   NVIC_ST_RELOAD_R=(time *16*pow(10,6))-1 ;    //RELOAD VALUE goes here
   NVIC_ST_CTRL_R = 5;         
   while ((NVIC_ST_CTRL_R & 0x10000) == 0);
	 NVIC_ST_CTRL_R = 0; 



}*/






/*
Intialization function 
*/
int main(void)
{
      init();


    LCD_start();
//    LCD_data('p');  
  //  LCD_command(0x06);
    //LCD_data('a');  
    //LCD_command(0x06);
/*
    while (1)
    {
    int SW1 = GPIO_PORTF_DATA_R&0x10; 	// read PF4 into SW1
    int SW2 = GPIO_PORTF_DATA_R&0x01; 	// read PF0 into SW2
    if(SW1 == 0x00){              	// zero means SW1 is pressed
      GPIO_PORTF_DATA_R = 0x02;   	// LED is green
     } 
    else if(SW2 == 0x00){               // 0x10 means SW1 is not pressed
      GPIO_PORTF_DATA_R = 0x02;  	// LED is red
     }
    
   */
initKeypad();

lcd_timer();

}
    
    






