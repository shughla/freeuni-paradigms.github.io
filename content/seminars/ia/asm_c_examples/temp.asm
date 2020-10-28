R1 = M[SP + 4]
R2 = M[SP + 8]
R3 = M[SP + 12]
SP = SP - 8
M[SP + 4] = R2 ; b
M[SP] = R1 ;a
CALL R3
SP = SP + 8

BNE RV 0 PC + 12
RV = .1 1
RET

RV = .1 0
RET


SP = SP - 12

R1 = <CompareStrings>
R2 = M[SP]
R3 = M[SP + 4]

SP = SP - 12
M[SP + 8] = R1 ; comaprestring
M[SP + 4] = R2 ; t
M[SP] = R3 ; s
CALL <AreEqual>

SP = SP + 12

M[SP + 8] = RV


SP = SP + 12
RET



SP = SP - 4

R1 = M[SP + 16]
M[R1 + 4] = 0

R1 = SP + 8
M[SP + 20] = R1
R2 = SP + 20
M[SP] = R2

R1 = M[SP]
R2 = M[R1]
R3 = M[SP + 20]
M[R2 + 8] = R3


SP = SP + 4
RET

