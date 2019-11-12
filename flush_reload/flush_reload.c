
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <x86intrin.h> /* for rdtscp and clflush */
#include "flush_reload.h"



uint8_t array2[256 * STRIDE];
uint8_t temp=0;

void main(){
  

  for(int k=0; k< 16; k++) {  
  /* you can add your code here*/


  		/* change <DESKNUMBER> to your lab desk/pc number i.e tp-5b01-23 is desk number 23*/
  		victim(&temp,array2,k,<DESKNUMBER>);


  /* you can add your code here*/

  }

}
