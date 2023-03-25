/***************************************************************************/
/*	Project : Vaccum Cleaner																							 */
/*	Details :	...																													 */
/***************************************************************************/

#include "../Main/main.h"
#include "../Modules/SW.h"
#include "../Modules/Timer.h"
#include "../Modules/Display.h"
#include "../Modules/Led.h"
#include "../Modules/VC.h"
#include "../Modules/Motor.h"
#include "stdio.h"

/* Oscilloscope should monitor C6 and C7 channels */

int main(void)
{
    /* Initialization */
   
   printf("Vacuum Cleaner is starting ...\n");
   
    SW_Init();		/* Switch Init */
    DISP_Init();	/* Display Init */
    VC_Init();		/* Vaccum Cleaner Init */
    Motor_Init();	/* Motor Init */

    /* Initialize the timer and start it */
    TMR_Init();
    TMR_Start();

    while (1)
    {
      // Sleep
			__WFI();
    }

    return 0;
}

