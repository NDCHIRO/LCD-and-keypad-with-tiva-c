#include "tm4c123gh6pm.h"
#include "init.h"
#include "best_function.h"


/*
Intialization function 
*/
void init();



 

int main(void)
{
  
  init() ;
   
  
  while(1){
  
  
  

  // Calling the intiallization function 
  
  /*
NOTE : 
        Launchpad key<switches are neagtive logic >
*/



  
 char x= keypad_getkey();
 switch (x)
 {
 	case '0':
 		GPIO_PORTB_DATA_R = ~ZERO;
 		break;
 	case '1':
 		GPIO_PORTB_DATA_R = ~ONE;
 		break;
 	case '2':
 		GPIO_PORTB_DATA_R = ~TWO;
 		break;
 	case '3':
 		GPIO_PORTB_DATA_R = ~THREE;
 		break;
 	case '4':
 		GPIO_PORTB_DATA_R = ~FOUR;
 		break;
 	case '5':
 		GPIO_PORTB_DATA_R = ~FIVE;
 		break;
 	case '6':
 		GPIO_PORTB_DATA_R = ~SIX;
 		break;
 	case '7':
 		GPIO_PORTB_DATA_R = ~SEVEN;
 		break;
 	case '8':
 		GPIO_PORTB_DATA_R = ~EIGHT;
 		break;
 	case '9':
 		GPIO_PORTB_DATA_R =~NINE;
 		break;
 	case 'A':
 		GPIO_PORTB_DATA_R = ~A;
 		break;
 	case 'B':
 		GPIO_PORTB_DATA_R = ~B;
 		break;
 	case 'C':
 		GPIO_PORTB_DATA_R = ~C;
 		break;
 	case 'D':
 		GPIO_PORTB_DATA_R = ~D;
 		break;
 	case 'E':
 		GPIO_PORTB_DATA_R = ~E;
 		break;
 	case 'F':
 		GPIO_PORTB_DATA_R = ~F;
 		break;

 }
  
 
 
/*
 
  if (Sw1 == 0x00 ) // zero means that switch is pressed
  {
  
  switch(state) {
    
			case S0: 
				GPIO_PORTB_DATA_R = ~ZERO; // Assign value in n0 to output pins 
				state = S1;		// Set next state
						//
				break;
			case S1: 
				GPIO_PORTB_DATA_R = ~ONE;
				state = S2;
			
			  break;
			case S2: 
				GPIO_PORTB_DATA_R = ~TWO;
				state = S3;
			
				break;
			case S3: 
				GPIO_PORTB_DATA_R = ~THREE;
				state = S4;
				
				break;
			case S4: 
				GPIO_PORTB_DATA_R = ~FOUR;
				state = S5;
				
				break;
			case S5: 
				GPIO_PORTB_DATA_R = ~FIVE;
				state = S6;
				
				break;
			case S6: 
				GPIO_PORTB_DATA_R = ~SIX;
				state = S7;
				
				break;
			case S7: 
				GPIO_PORTB_DATA_R = ~SEVEN;
				state = S8;
				
				break;
			case S8: 
				GPIO_PORTB_DATA_R = ~EIGHT;
				state = S9;
				
				break;
			case S9: 
				GPIO_PORTB_DATA_R = ~NINE;
				state = SA;
			
				break;
            
                        
                                	
			case SA: 
				GPIO_PORTB_DATA_R = ~A;
				state = SB;
				
				break;
			case SB: 
				GPIO_PORTB_DATA_R = ~B;
				state = SC;
				
				break;
			case SC: 
				GPIO_PORTB_DATA_R = ~C;
				state = SD;
				
				break;
                                
                        case SD: 
				GPIO_PORTB_DATA_R = ~D;
				state = SE;
				
				break;        
                                
                                
			case SE: 
				GPIO_PORTB_DATA_R = ~E;
				state = SF;
			
				break;
                      
                        case SF: 
				GPIO_PORTB_DATA_R = ~F;
				state = S0;
			
				break;        
                                
  
  
  
  } 
  
 
  
  }
  
  
   else if (Sw2 == 0x00)
  {
  
      switch(state) {
    
			case S0: 
				GPIO_PORTB_DATA_R = ~ZERO  ; // Assign value in Zero to output pins 
				state = SF;		// Set next state
						
				break;
			case S1: 
				GPIO_PORTB_DATA_R = ~ONE;   
				state = S0;
			
			  break;
			case S2: 
				GPIO_PORTB_DATA_R = ~TWO;
				state = S1;
			
				break;
			case S3: 
				GPIO_PORTB_DATA_R = ~THREE;
				state = S2;
				
				break;
			case S4: 
				GPIO_PORTB_DATA_R = ~FOUR;
				state = S3;
				
				break;
			case S5: 
				GPIO_PORTB_DATA_R = ~FIVE;
				state = S4;
				
				break;
			case S6: 
				GPIO_PORTB_DATA_R = ~SIX;
				state = S5;
				
				break;
			case S7: 
				GPIO_PORTB_DATA_R = ~SEVEN;
				state = S6;
				
				break;
			case S8: 
				GPIO_PORTB_DATA_R = ~EIGHT;
				state = S7;
				
				break;
			case S9: 
				GPIO_PORTB_DATA_R = ~NINE;
				state = S8;
			
				break;
	 
                        case SA: 
				GPIO_PORTB_DATA_R = ~A;
				state = S9;
				
				break;
			case SB: 
				GPIO_PORTB_DATA_R = ~B;
				state = SA;
				
				break;
			case SC: 
				GPIO_PORTB_DATA_R = ~C;
				state = SB;
                                break ;
			case SD: 
				GPIO_PORTB_DATA_R = ~D;
				state = SC;
				
				break; 
	
				
			case SE: 
				GPIO_PORTB_DATA_R = ~E;
				state = SD;
			
				break;
                      
                        case SF: 
				GPIO_PORTB_DATA_R = ~F;
				state = SE;
			
				break;        
      }
      
  }*/
 
 
  unsigned int cnt = 1000000;
  while(cnt--);
 /* else if(sw1 == 0x00 & sw2 == 0x00) // sw1 + sw2 pressed at the same time  
  {
    //state=S0;
    init(); 
  }*/
  
  
  
  
  
  
  } 
}


