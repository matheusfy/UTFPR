/*2) Implemente uma função que imprime uma string (array de caracteres) em ordem inversa. Exemplo: "pablo" -> "olbap".*/

#include<stdio.h>


int inverte(char vet[], int i)
{

    if (i<0)
    {
        return 0;
    }
    printf("%c",vet[i]);
    i--;
    inverte(vet,i);

}



int main(void)
{

    char vet[6]={"pablo"};
    int i=4;

    inverte(vet,i);

}

