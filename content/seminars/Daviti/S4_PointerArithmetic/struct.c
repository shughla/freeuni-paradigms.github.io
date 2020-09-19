#include <stdio.h> 

typedef struct{
    char *name;
    int meore;
    char suid[7];
    int numUnits;
} student;



int main(){
    student st;

    // sizes of different types of variables
    printf("%ld\n", sizeof(char *));
    printf("%ld\n", sizeof(int));
    printf("%ld\n", sizeof(student));

    // how much space do the elements occupy
    student st;
    printf("%ld\n", &st.name);
    printf("%ld\n", &st.meore);
    printf("%ld\n", &st.suid[0]);
    printf("%ld\n", &st.numUnits);
}