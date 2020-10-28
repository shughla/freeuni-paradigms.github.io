//#include <stdio.h>
#include "nenexistent.h"
#include "myheader.h"
typedef struct {
	int doug;
	short emmyjo[2];
} human;

typedef struct { 
	int doug;
	short emmyjo1;
	short emmyjo2;
} human2;
int main() {
	human human1;
	human1.emmyjo[1] = 3;
	human2 human22;
	human22.emmyjo2 = 3;
//	printf("%d\n", human1.emmyjo[1]);
//	printf("%d\n", (&human22.emmyjo1)[1]);
//	printf("%d\n", &(((human2*)&human1)->emmyjo1)[1]);
	human * ptr = &human1;
//	printf("%d\n", (&(((human2 *)&human1)->emmyjo1))[1]);
}
