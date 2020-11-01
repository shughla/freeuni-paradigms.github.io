; gooddeeds 8
; conformity 4
; saved pc SP

; human 8
; goodeeds 16

R1 = M[SP + 4] ; conformity
R2 = M[R1]
R3 = R2 * 2
R4 = R1 + R3
M[R4] = .2 0

R1 = M[SP + 8] ; gooddeeds
R2 = M[R1 + 12] ; henrietta
; R3 = 
R3 = R2 + 4 ; &emmyjo
R4 = M[R3] ; ->doug (რადგან 0 offsetზეა)
R5 = R4*16 
R6 = R1 + R5
M[SP + 8] = R6

R1 = SP + 8
SP = SP - 4
M[SP] = R1
CALL <AskingQuestions> 
SP = SP + 4

; RV რჩება იგივე
RET
