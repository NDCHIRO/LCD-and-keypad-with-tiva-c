/*
Defining of Display digits from zero up to one on the 7-segment display 
*/

#define ZERO 0x3f //0100 0000  Display 0        
#define ONE 0x06 //0111 1001  Display 1
#define TWO 0x5b //0010 0100  Display 2 
#define THREE 0x4f //0011 0000  Display 3
#define FOUR 0x66 //0001 1001  Display 4
#define FIVE 0x6d //0001 0010  Display 5
#define SIX 0x7d //0000 0010  Display 6
#define SEVEN 0x07 //0111 1000  Display 7
#define EIGHT 0x7f //0000 0000  Display 8
#define NINE 0x67 //0001 0000  Display 9
/////////////////////////////////////////////////////////

#define A 0x77 //0000 1000  Display A
#define B 0x7c //0000 0011   Display B
#define C 0x39 //0100 0110  Display C
#define D 0x5e //0010 0001  Display D
#define E 0x79 //0000 0110  Display E
#define F 0x71 //0000 1110  Display F



/*
#define RS 0x20
#define RW 0x40
#define EN 0x80
*/


#define RS 0x20 /* PORTA BIT5 mask */
#define RW 0x40 /* PORTA BIT6 mask */
#define EN 0x80 /* PORTA BIT7 mask */






/*
Defining the switches .. 
*/


 
#define sw1 (1U<<4)
#define sw2  (1U<<0)


void init(void);
/*void delayUs(int num);
void delayMs(int num);*/
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_start();
int concat(char arr[]);
void startcount(int count,int size);
