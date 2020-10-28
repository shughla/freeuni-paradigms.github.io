R1 = M[SP + 12]
R3 = M[SP + 8]
R2 = M[SP + 4]
SP = SP - 8
M[SP + 4] = R3
M[SP] = R2
CALL R1 
SP = SP + 8
;RV cmp (a,b)

BNE RV 0 PC + 12
RV = .1 1
RET
RV = .1 0
RET



SP = SP - 12
R1 = M[SP]
R2 = M[SP + 4]
R3 =  <CompareStrings>
SP = SP - 12
M[SP + 8] = R3
M[SP + 4] = R1
M[SP] = R2
CALL <AreEqual>
SP = SP + 12
M[SP + 8] = RV
SP = SP + 12
RET

SP = SP - 4

R1 = M[SP + 16] ; bert.next
M[R1 + 4] = 0

R1 = SP + 20
R2 = SP + 8
M[SP + 20] = R2
M[SP] = R1

R1 = M[SP]
R2 = M[R1]
R3 = M[SP + 20]
M[R2 + 8] = R3

RV = .1 M[SP + 8]

SP = SP + 4
RET





