#include <stdio.h>
#include <string.h>

void imprima(char v1[6]);

int main(void){
    char v1[6]={"pablo"};

    imprima(v1);
return 0;
}

void imprima(char v1[6]){

    char v2[6];
    int i;

    for(i=1; i<6; i++){
        v2[i]=v1[5-i];
        printf("%c", v2[i]);
    }

 }
