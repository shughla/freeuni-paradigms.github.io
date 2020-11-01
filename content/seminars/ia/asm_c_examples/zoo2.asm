; gooddeeds	8
; conformity	4
; saved pc	SP


R1 = M[SP + 8] ; confority
R2 = M[R1] ; *conformity
R3 = R2 * 2
R4 = R1 + R3
M[R4] = .2 0 

R1 = M[SP + 8] ; gooddeeds
R2 = M[R1 + 12] ; goodeeds->henrietta
R3 = R2 + 4 ; & goodeeds->henrietta[0].emmyjo
; R3 = R2 + 8*2 + 4 ; & goodeeds->henrietta[2].emmyjo
R4 = M[R3] ; -> doug
; R4 = M[R3 + 4] ; -> emmijo[0]
R5 = R4*16
R6 = R1 + R5
M[SP + 8] = R6


R1 = SP + 8
SP = SP -4
M[SP] = R1
CALL <AskingQuestions>
SP = SP + 4

; RV remains same
RET

