#include "tm4c123gh6pm.h"
#include "systicDelay.h"

void delayMs(int num)
{
  NVIC_ST_CURRENT_R =0;
  NVIC_ST_RELOAD_R=15999;  //num*((16*pow(10,6))-1);
  NVIC_ST_CTRL_R=5;
  for (int i=0; i<num; i++)
  {
    while((NVIC_ST_CTRL_R & 0x10000)==0);
  }
} 


void delayUs(int num)
{
  NVIC_ST_CURRENT_R =0;
  NVIC_ST_RELOAD_R=15;  //num*((16*pow(10,3))-1);             //check el eq de 
  NVIC_ST_CTRL_R=5;
  for (int i=0; i<num; i++)
  {
    while((NVIC_ST_CTRL_R & 0x10000)==0);
  }
} 