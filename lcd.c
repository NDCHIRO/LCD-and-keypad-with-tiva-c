#include "tm4c123gh6pm.h"
#include "lcd.h"
#include "systicDelay.h"
#include <stdlib.h>
#include <string.h>
#include "lcdTimer.h"
#include "mn ay 7aga l ay 7aga.c"
    //RS , RW , E  PA5, PA6, PA7
   // rows E1 , E2,E3,E4
  //COL   D2, D3 ,D6 , D7

void init(){
    //port f
     SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5; // Enabling the clock to enable port F
     GPIO_PORTF_LOCK_R = 0x4C4F434B;   //  unlock PortF PF0  
     GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4 and PF0  
     GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
     
     GPIO_PORTF_PUR_R |= (sw1|sw2) ;          // enable pullup resistors on PF4,PF0
     GPIO_PORTF_DEN_R = 0x7F;          //  enable digital pins PF4-PF0
      
     //port E
     SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4; // Enabling the clock to enable port E
     GPIO_PORTE_ODR_R |= (0x1C);          
     GPIO_PORTE_LOCK_R = 0x4C4F434B;   //  unlock PortB
      
     //port B
     SYSCTL_RCGCGPIO_R |= 0x02;
     GPIO_PORTB_DIR_R = 0xFF;
     GPIO_PORTB_DEN_R = 0xFF;
    
    //portA for commands
    SYSCTL_RCGCGPIO_R |= 0x01;
    GPIO_PORTA_DIR_R = 0xE0;
    GPIO_PORTA_DEN_R = 0xE0;
  SYSCTL_RCGCGPIO_R &=~( SYSCTL_RCGCGPIO_R2);  
  SYSCTL_RCGCGPIO_R &=~( SYSCTL_RCGCGPIO_R3);
    SYSCTL_RCGCGPIO_R &=~( SYSCTL_RCGCGPIO_R4);
}

/*void delayUs(int num)
{
  for(int i=0;i<num*16;i++)
  {
    
  }
}

void delayMs(int num)
{
   for(int i=0;i<num*16*1000;i++)
  {
    
  }
} */

void LCD_command(unsigned char command)
{
        GPIO_PORTA_DATA_R &=~( RS | RW);
	/* RS = 0, R/W = 0 */
	GPIO_PORTB_DATA_R = command;
	GPIO_PORTA_DATA_R |= EN;
	/* pulse E */
	delayUs(1);
	/* Enable pulse Width */
	GPIO_PORTA_DATA_R = 0;
	if (command < 4)
            delayMs(2);
            /* command 1 and 2 needs up to 1.64ms */
	else
              delayUs(40); /* all otheRS 40 us */

}

void LCD_data(unsigned char data)
{

	GPIO_PORTA_DATA_R |= RS; /* RS = 1, R/W = 0 */
	GPIO_PORTA_DATA_R &=~(RW);
        GPIO_PORTB_DATA_R = data;
	GPIO_PORTA_DATA_R = EN | RS; /* pulse E */
	delayUs(1);
	GPIO_PORTA_DATA_R = 0;
	delayUs(40);
}






void LCD_start()
{
	delayMs(30); /* initialization sequence */// Wait >15 ms after power is applied
	LCD_command(0x30);
	// command 0x30 = Wake up
	delayMs(50);
	// must wait 5ms, busy flag not available
	LCD_command(0x30);
	// command 0x30 = Wake up #2
	delayUs(1000);
	// must wait 100us, busy flag not available
	LCD_command(0x30);
	// command 0x30 = Wake up #3
	delayUs(1000);
	// must wait 100us, busy flag not available
	// Prepare LCD Operation and Function
	LCD_command(0x38); /* set 8-bit data, 2-line, 5x7 font */
	LCD_command(0x06); /* move cuRSor right */
	LCD_command(0X01); /* clear screen, move cuRSor to home */
	LCD_command(0x0F); /* turn on display, cuRSor blinking */
        LCD_command(1);
        LCD_command(0x80);
        delayMs(500);
       
}



int concat(char arr[])                 ////function for concatenation
{
  unsigned int count=atoi(arr);
  return count;
}



void startcount(int count,int size)
{
  unsigned int Sw2  = GPIO_PORTF_DATA_R&0x01;     // read PF0 into sw2
  unsigned int count1=count;
  for(int i=0;i<count;i++)
   {
     if (Sw2 == 0x00 ) //(abort and restart) zero means that switch is pressed
        {
          LCD_command(0x01); // clear display 
          
  
          lcd_timer(); // restart timer 

          
          
          
          
          
     
        }
     
     char buffer[16];
     itoa(count1,buffer);
     
     LCD_command(0x01);         //clear
     
       if(size==2)
       {
          LCD_data(buffer[0]);  
          LCD_command(0x06);
          LCD_data(buffer[1]);  
          LCD_command(0x06);
       }
       
       if(size==3)
       {
          LCD_data(buffer[0]);  
          LCD_command(0x06);
          LCD_data(buffer[1]);  
          LCD_command(0x06);
          LCD_data(buffer[2]);  
          LCD_command(0x06);
       }
       
       if(size==4)
       {
         
          LCD_data(buffer[0]);  
          LCD_command(0x06);
          LCD_data(buffer[1]);  
          LCD_command(0x06);
          LCD_data(buffer[2]);  
          LCD_command(0x06);
          LCD_data(buffer[3]);  
          LCD_command(0x06);
       }
       
      LCD_data('.');  
      LCD_command(0x06);
      LCD_data('0');  
      LCD_command(0x06);
      LCD_data('0');  
      LCD_command(0x06);
    
      delayMs(1000);

      count1--;
   }
   
  
}




