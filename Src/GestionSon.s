	PRESERVE8
	THUMB  	
	IMPORT Son
	include Driver\DriverJeuLaser.inc
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		
SortieSon dcd 0
Index dcd 0
; ===============================================================================================
	EXPORT CallbackSon
	EXPORT SortieSon

		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici	

CallbackSon proc
	LDR r1,=Index ;index du tableau
	LDR r2,[r1]
	
	LDR r3,=Son ;pointeur sur le tableau

	LDRSH r12,[r3,r2,LSL #1] ;valeur a l'indice r1 du tableau (echantillon)
	
	;mise à l'echelle entre 0 et 719 de l'echantillon
	ADD r12,#32768
	MOV r3,#92
	UDIV r12,r3
	
	LDR r3,=SortieSon ;adresse variable globale exportée
	STR r12,[r3]
	
	ADD r2,#1
	STR r2,[r1]
	
	push {LR}
	MOV r0, r12
	BL PWM_Set_Value_TIM3_Ch3
	pop {LR}
	
	BX LR
	ENDP
	END	
		
StartSon proc
	BL CallbackSon
