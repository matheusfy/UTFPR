#include <stdio.h>

void num_natural (int y)
{

    if (y==0){
    printf("");
    }
    else

        num_natural(y-1);
        printf(" %i", y);



      }

int main(void)
{
    int y;
        printf("insira um numero: ");
        scanf("%i", &y);
        num_natural(y);

}
