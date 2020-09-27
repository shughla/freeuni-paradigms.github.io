#include <stdio.h>

size_t strlen(const char *s){
    char * curr = (char *)s;
    int size = 0;
    while(*curr != '\0'){
        curr++;
        size++;
    }
    return size;
}

char *strcpy(char *dest, const char *src){
    char * dest_new = dest;
    while(*src != '\0'){
        *dest_new = *src;
        src++;
        dest_new++;
    }
    *dest_new = '\0';
    return dest;
}

char *strcat(char *dest, const char *src){

}

char *strdup(const char *s){
    size_t size = strlen(s);
    char * str = malloc(size + 1);
    strcpy(str, s);
    return str;
}


int main(){
    char *str = "wubba lubba";
    printf("%ld", strlen(str));
    printf("%s", str);
}