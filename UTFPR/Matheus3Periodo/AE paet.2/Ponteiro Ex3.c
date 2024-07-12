#include <stdio.h>
#include <string.h>

void letra(char v[], int *a, int *b ){
    int i;

    for(i=0; i<10; i++){
        if(v[i]=='a'||v[i]=='e'||v[i]=='i' ||v[i]=='o' ||v[i]=='u'){
        (*a)++;

        }else{
         (*b)++;
        }

    }


}



int main(void){

    char v[10]={"abcdefghi"};
    int vogais=0 , consoantes=0;

    letra (v,&vogais,&consoantes);

    printf("%i vogais\n", vogais);
    printf("%i consoantes", consoantes);
}
