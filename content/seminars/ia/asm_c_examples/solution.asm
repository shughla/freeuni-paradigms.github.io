; superhero elastigirl

superboy[4]	24
...
superboy[0]	20
dash[1]		16
dash[0]		12
violet 4	8
frozone 4 	4
saved pc	SP 


; დაკასტვა სად არის საჭირო
- მეხსიერებიდან წაკითხვა
- მეხსიერებაში ჩაწერა

; scale by offset (გამრავლება) სად არის საჭირო
- მასივი
- პოინტერ არითმეტიკა

; frozone += elastigirl.superboy[*frozone]

R1 = M[SP + 4] ; frozone
R2 = .2 M[R1] ; *frozone
R3 = SP + 20 ; &superboy
R4 = R2 + R3 ; superboy + sizeof(char) * (*frozone)
R5 = .1 M[R4] ; elastigirl.superboy[*frozone]
R5 = R5*2
R6 = R1 + R5 ; frozone + elastigirl.superboy[*frozone]
M[SP + 4] = R6; frozone  

; elastigirl.dash[0]
; ჰენდაუთის ამოხსნაში აქ მგონი შეცდომაა
R1 = M[SP + 12] ; elastigirl.dash[0]
R2 = M[R1 + 4] ; -> dash
M[R2] = 400 ; (R2 + 0) -> violet


R1 = SP + 8
SP = SP - 4
M[SP] = R1
CALL <pixar>
SP = SP + 4

R1 = M[RV]
RV = R1 + 160
RET
