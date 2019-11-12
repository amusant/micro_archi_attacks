
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <x86intrin.h> /* for rdtscp and clflush */
#define STRIDE 64
uint8_t array2[256 * STRIDE];

uint8_t temp = 0; /* Used so compiler won’t optimize out victim_function() */



void main(){
  int tries, i, j, k, mix_i, junk = 0;
  register uint64_t time1, time2;
  volatile uint8_t * addr;
  static int results[256];

  for (i = 0; i < 256; i++)
    results[i] = 0;
  for (tries = 9; tries > 0; tries--) {

    	/* Flush  */
    	for (i = 0; i < 256; i++)
    	  _mm_clflush( & array2[i * STRIDE]); /* intrinsic for clflush instruction */

		/* access */
    	for (i = 0; i < 64; i++) 
         temp &= array2[i*STRIDE];

    	/* RELOAD */
    	for (i = 0; i < 256; i++) {
    	  mix_i = ((i * 167) + 13) & 255;
    	  addr = & array2[mix_i * STRIDE];
    	  time1 = __rdtscp( & junk); /* READ TIMER */
    	  junk = * addr; /* MEMORY ACCESS TO TIME */
    	  time2 = __rdtscp( & junk) - time1; /* READ TIMER & COMPUTE ELAPSED TIME */
    	  results[mix_i]+=time2;
    	}
	}
  /* print access time*/	
  for (i = 0; i < 256; i++) 
  	printf("%d = %d \n",i,results[i]);
}
