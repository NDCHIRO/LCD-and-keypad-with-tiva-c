#include "init.h"
void mohem(int i,int size){
char x= keypad_getkey();
  
void  
 
 switch (x)
 {
 	case '0':
              LCD_data('0');  
              LCD_command(0x06);
              break;
                
 	case '1':
              LCD_data('1');  
              LCD_command(0x06);
  		break;
                
 	case '2':
              LCD_data('2');  
              LCD_command(0x06);
 		break;
                
 	case '3':
              LCD_data('3');  
              LCD_command(0x06);
 		break;
                
 	case '4':
              LCD_data('4');  
              LCD_command(0x06);
 		break;
                
 	case '5':
              LCD_data('5');  
              LCD_command(0x06);
 		break;
                
 	case '6':
              LCD_data('6');  
              LCD_command(0x06);
 		break;
                
 	case '7':
              LCD_data('7');  
              LCD_command(0x06);
 		break;
                
 	case '8':
              LCD_data('8');  
              LCD_command(0x06);
 		break;
                
 	case '9':
              LCD_data('9');  
              LCD_command(0x06);
 		break;
       /*         
 	case 'A':
              LCD_data('10');  
              LCD_command(0x06);
 		break;
                
 	case 'B':
              LCD_data('11');  
              LCD_command(0x06);
 		break;
                
 	case 'C':
              LCD_data('12');  
              LCD_command(0x06);
 		break;
                
 	case 'D':
              LCD_data('13');  
              LCD_command(0x06);
 		break;
                
 	case 'E':
              LCD_data('14');  
              LCD_command(0x06);
 		break;
                
 	case 'F':
              LCD_data('15');  
              LCD_command(0x06);
 		break;*/

 }
 
  if(i>4)
  {
    LCD_commnad(0x01);
    LCD_data('s');  
    LCD_command(0x06);
    LCD_data('t');    
    LCD_command(0x06);
    LCD_data('a');  
    LCD_command(0x06);
    LCD_data('r');  
    LCD_command(0x06);
    LCD_data('t');  
    LCD_command(0x06);
    delayMs(1000);
    LCD_command(0x01);
  /*  
    int gg=concat(arr);  //fe el lcd.c
    
    LCD_data(':');  
    LCD_command(0x06);
    LCD_data('0');  
    LCD_command(0x06);
    LCD_data('0');  
    LCD_command(0x06);
    startcount(gg,size);      //fe el lcd.c*/
} 
 arr[i]=x;
  i++;
  size++;
  
  if (Sw1 == 0x00 ) //(start) zero means that switch is pressed
  {
    int gg=concat(arr);  //fe el lcd.c
    startcount(gg,size);
    
    LCD_command(0x01);        //clear and print end
    LCD_data('E');  
    LCD_command(0x06);
    LCD_data('N');  
    LCD_command(0x06);
    LCD_data('D');  
    LCD_command(0x06);
      for(int i=0;i<5*16*1000;i++)
      {
         GPIO_PORTF_DATA_R |=(0x02);        //blink    
      }
  }
  
  
}