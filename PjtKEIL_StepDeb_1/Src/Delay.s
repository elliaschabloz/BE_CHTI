	PRESERVE8
	THUMB   
		

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		
VarTime	dcd 0 ;valeur à l'adresse mémoire de VarTime à 0

	
; ===============================================================================================
	
;constantes (équivalent du #define en C)
TimeValue	equ 900000 


	EXPORT Delay_100ms ; la fonction Delay_100ms est rendue publique donc utilisable par d'autres modules.
	EXPORT VarTime	   ; on rend VarTime globale
		
;Section ROM code (read only) :		
	area    moncode,code,readonly
		


; REMARQUE IMPORTANTE 
; Cette manière de créer une temporisation n'est clairement pas la bonne manière de procéder :
; - elle est peu précise
; - la fonction prend tout le temps CPU pour... ne rien faire...
;
; Pour autant, la fonction montre :
; - les boucles en ASM
; - l'accés écr/lec de variable en RAM
; - le mécanisme d'appel / retour sous programme
;
; et donc possède un intérêt pour débuter en ASM pur

Delay_100ms proc
	
	    ldr r0,=VarTime  	; r0=&VarTime  
						  
		ldr r1,=TimeValue	; r1 = 900000
		str r1,[r0]			; VarTime = 900000
		
BoucleTempo	
		ldr r1,[r0]     	; r1=VarTime		
						
		subs r1,#1			; r1--
		str  r1,[r0]		; VarTime = r1
		bne	 BoucleTempo	; reboucle tant VarTime != 0
			
		bx lr				; sort et va à l'adresse de la prochaine instruction
		endp
		
		
	END	