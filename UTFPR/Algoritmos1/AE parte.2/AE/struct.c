#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (void)
{
    int i=20,j=0;
    char nome[20];

    printf("insira seu nome\n");
    scanf(" %s", &nome[20]);

    for (i=20; i<="\0"; i--)
    {
        nome[j]=nome[i];
        j++;

    }
    printf(" %s", nome[j]);
}

