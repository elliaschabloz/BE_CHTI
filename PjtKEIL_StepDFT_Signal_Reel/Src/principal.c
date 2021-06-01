
#include "DriverJeuLaser.h"

extern int DFT(short int * Signal64ech, char k, short int * tab);
extern short int LeSignal;
extern short int TabCos;
extern short int TabSin;

short int tab[64];
short int tab_ech[64];
short int tab_score[4];

int f1 = 85000;
int f2 = 90000;
int f3 = 95000;
int f4 = 100000;
int f5 = 115000;
int f6 = 120000;


int DFT_ModuleAuCarre( short int * Signal64ech, char k){
	return DFT(Signal64ech, k, &TabCos) + DFT(Signal64ech, k, &TabSin);
}

void callbackSystick(void){
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
	for(int i=0; i<64; i++){
		tab[i] = DFT_ModuleAuCarre( tab_ech, i);
	}
}


void test( ){
	for(int i=0; i<64; i++){
		tab[i] = DFT(&LeSignal, i, &TabSin) + DFT(&LeSignal, i, &TabCos);
	}

}
	
int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();

/// Timer Systick ///

	//
Systick_Period_ff( 360000 );
Systick_Prio_IT( 2, &callbackSystick );
SysTick_On;
SysTick_Enable_IT;
	
Init_TimingADC_ActiveADC_ff( ADC1, 72 );
Single_Channel_ADC( ADC1, 2 );	
Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
Init_ADC1_DMA1( 0, tab_ech );

//============================================================================	
	
//test();

while	(1)
	{
		if(tab[f1/5000] >= 100){
			tab_score[0] += 1;
		} else if(tab[f2/5000] >= 100){
			tab_score[1] += 1;
		} else if(tab[f3/5000] >= 100){
			tab_score[2] += 1;
		} else if(tab[f4/5000] >= 100){
			tab_score[3] += 1;
		}
	}
}

