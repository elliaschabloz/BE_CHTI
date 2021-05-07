

#include "DriverJeuLaser.h"

extern void CallbackSon(void);
extern int SortieSon;

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();

// configuration du Timer 4 en débordement 91µs
Timer_1234_Init_ff(TIM4, 6552);
	
Active_IT_Debordement_Timer( TIM4, 2, CallbackSon);

// config du PWM, avec Timer3, channel 3	
PWM_Init_ff( TIM3, 3, 720 );
	
GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);
//============================================================================	
	
	
while	(1)
	{
	}
}

