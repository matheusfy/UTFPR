
char inverso ( char nome)
{
    int i,j=10;

    for (i=0; i<10; i++)

    {
        nome[j]= nome[i];
        j--;

    }
    printf(" %s", nome[j]);

}
