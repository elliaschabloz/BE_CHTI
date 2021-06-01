	PRESERVE8
	THUMB   
	include DriverJeuLaser.inc

; ====================== zone de r�servation de donn�es,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite	
FlagCligno dcd 0
	
; ===============================================================================================
	
	EXPORT timer_callback ; la fonction timer_callback est rendue publique donc utilisable par d'autres modules.
		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; �crire le code ici		
	
	
timer_callback proc
	push	{lr}
	ldr r3,=FlagCligno	
	ldr r2,[r3]
	ldr r0,=1
	CBNZ r2, L1 ; si r1 n'est pas nul, on saute � L1
	
	LDR r2, =1 ; sinon on met � 1
	bl GPIOB_Clear ; mettre PB1 � 0
	b Continue
	
L1  	
	LDR r2, =0 ; mettre FlagCligno � 0
	bl GPIOB_Set;	mettre PB1 � 1

Continue
	STR r2,[r3]
	pop {lr}
	bx lr
	endp
		
		
	END	