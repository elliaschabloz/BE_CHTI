

#include "DriverJeuLaser.h"

extern void CallbackSon(void);
extern int SortieSon;
extern int Index;

void StartSon(void){
	Index = 0;
	return ;
}
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
int cpt = 0;	
	
while	(1)
	{
		/*cpt++;
		if (cpt == 20000000){
			StartSon();
			cpt = 0;
		}*/
	}
}

