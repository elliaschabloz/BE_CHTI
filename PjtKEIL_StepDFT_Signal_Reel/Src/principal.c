
#include "DriverJeuLaser.h"

extern int DFT(short int * Signal64ech, char k, short int * tab);
extern short int LeSignal;
extern short int TabCos;
extern short int TabSin;

short int tab[64];

/* Faire la fct en ASM avec une boucle while
La fct C appele la fct ASM
Le 2pi/M va disparaitre
*/
void test( ){
	for(int i=0; i<64; i++){
		tab[i] = DFT(&LeSignal, i, &TabSin) + DFT(&LeSignal, i, &TabCos);
	}

}

int DFT_ModuleAuCarre( short int * Signal64ech, char k){
	return DFT(&LeSignal, k, &TabCos) + DFT(&LeSignal, k, &TabSin);
}
	
int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();

/// Timer Systick ///

Systick_Period_ff( 360000 );
Systick_Prio_IT( 2, &Systick_Period_ff );
SysTick_On;
SysTick_Enable_IT;
	
Init_TimingADC_ActiveADC_ff( ADC1, 72 );
Single_Channel_ADC( ADC1, 2 );	
Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
Init_ADC1_DMA1( 0, tab );

//============================================================================	
	
//test();

while	(1)
	{
		
	}
}

