
#include "DriverJeuLaser.h"

extern int DFT(short int * Signal64ech, char k, short int * tab);
extern short int LeSignal;
extern short int TabCos;
extern short int TabSin;

int tab[64];

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

void Systick_Period_ff( unsigned int Periode_ticks );
void Systick_Prio_IT( char Prio, void (*Systick_function)(void) );
SysTick_On;
SysTick_Enable_IT;
	
	

//============================================================================	
	
//test();

while	(1)
	{
		
	}
}

