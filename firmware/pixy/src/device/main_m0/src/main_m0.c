//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//

#include <debug.h>
#include <chirp.h>
#include <cycletimer.h>
#include <pixyvals.h>
#include "exec_m0.h"
#include "frame_m0.h"
#include "rls_m0.h"

//int g_foo3 = 0x12345678;
//int *g_foo4 = (int *)0xdeadbeef;

int main(void)
{
	/*
	//CTIMER_DECLARE();
#if 0
	uint32_t memory = SRAM1_LOC;
	uint32_t lut = SRAM1_LOC;

	//while(1);
	memset((void *)QQ_LOC, 0x01, 0x3000);
	g_qqueue->writeIndex = 0;
	g_qqueue->produced = 0;
	g_qqueue->consumed = 0;

 	while(1)
 		getRLSFrame(&memory, &lut); 
#endif
#if 0
	int i = 0x12345678;
	foo(&i);
	printf("%d\n", i);
	while(1);
#endif
#if 0
	int i;
	uint32_t lut = SRAM1_LOC;
 	uint32_t memory = SRAM1_LOC+0x1000;
	uint8_t *plut = (uint8_t *)lut;
	for (i=0; i<0x4000; i++)
		plut[i] = i%5==0 ? 1 : 0;
	
 	while(1)
 		getRLSFrame(&memory, &lut); 

#endif
*/





#if 1
	_DBG("M0 start\n");

	chirpOpen();
	exec_init();
	frame_init();
	rls_init();
	exec_loop();
#endif







/*#if 0
	while(1)
	{
		if (g_foo)
			loop0();
	}
#endif

#if 0
	vsync();
#endif
#if 0
	//while(g_loop);
	int i;
	uint8_t type = CAM_GRAB_M1R2;
	uint32_t memory = SRAM1_LOC;
	uint16_t offset = 0;
	uint16_t width = 300;
	uint16_t height = 200;
	_DBG("M0 start\n");
	while(1)
	{
		 getFrame(&type, &memory, &offset, &offset, &width, &height);
		 i++;

		 if (i%50==0)
		 {
			 _DBD32(i), _CR();
		 }
	}
#endif
#if 0
	while(1)
	{
		CTIMER_START();
		syncM1((uint32_t *)&LPC_GPIO_PORT->PIN[1], 0x2000);
		CTIMER_STOP();
		
		printf("%d\n", CTIMER_GET());
	}	
#endif
 
#if 0
{
	uint32_t i;
	uint8_t *lut = (uint8_t *)SRAM1_LOC + 0x10000;
	uint32_t memory = SRAM1_LOC;
	uint32_t size = SRAM1_SIZE/2;
	for (i=0; i<0x10000; i++)
		lut[i] = 0;
	lut[0xb400] = 0;
	lut[0xb401] = 1;
	lut[0xb402] = 1;
	lut[0xb403] = 1;
	lut[0xb404] = 0;
	lut[0xb405] = 1;
	lut[0xb406] = 1;
	lut[0xb407] = 0;
	lut[0xb408] = 0;
	lut[0xb409] = 0;

	while(1)
 		getRLSFrame(&memory, &size); //, (uint32_t *)&lut);
}
#endif
*/
return 0;
}
