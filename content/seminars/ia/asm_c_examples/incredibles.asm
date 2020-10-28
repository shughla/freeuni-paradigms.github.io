
typedef struct {
	int violet; 	// 4	0
	char *dash[2]; 	//  8	4
	char superboy[4]; // 4	12
} superhero;
// 16

; 
; elastigirl.superboy[3]	1  23
; ..				2  
; elastigirl.superboy[0]	1  20
; elastigirl.dash[1]		4  16
; elastigirl.dash[0]		4  12
; elastigirl.violet 		4  8	
; frozone			4  4
; saved PC			4  0
// ignore this funciton's body, just so it can compile
static superhero **pixar(superhero *syndrome) {
}
static superhero *theincredibles(short *frozone, superhero elastigirl){ 
;	frozone += elastigirl.superboy[*frozone];
R1 = M[SP + 4]; frozone
R2 = .2 M[R1] ; *frozone
R3 = SP + 20 ; &elastigirl.superboy
R4 = R3 + R2 ; (R2 * 1) &elastigir.superboy[*frozone]
R5 = .1 M[R4] ;  elastigir.superboy[*frozone]
R6 = R5 * 2 ; pointer arithmetic
R7 = R1 + R6 ; frozone + elasti....
M[SP + 4] = R7; frozone = ...

;	((superhero *)((superhero *) elastigirl.dash[0])->dash)->violet = 400;
R1 = M[SP + 12]
R2 = M[R1 + 4]
M[R2] = 400


;	return *pixar(&elastigirl) +10;
R1 = SP + 8
SP = SP - 4
M[SP] = R1
CALL <pixar>
SP = SP + 4

R1 = M[RV]
RV = R1 + 160

RET

}


