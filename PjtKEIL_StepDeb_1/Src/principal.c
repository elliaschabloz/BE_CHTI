#include "DriverJeuLaser.h"

extern void Delay_100ms(void);

int x;
int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();

// configuration de PortB.1 (PB1) en sortie push-pull
GPIO_Configure(GPIOB, 1, OUTPUT, OUTPUT_PPULL);

	
	

//============================================================================	
	
	
while	(1)
	{
		Delay_100ms();
		x = 0;
		GPIOB_Set(1);
		Delay_100ms();
		x = 1;
		GPIOB_Clear(1);
	}
}
