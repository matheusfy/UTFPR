#include <stdio.h>

int num_natural (int y)
{

        if (y==0)
        printf(" %i", y);

        else{
        printf(" %i", y);
        num_natural(y-1);
        }
      }

int main(void)
{
    int y;

        printf("insira um numero: ");
        scanf("%i", &y);
        num_natural(y);

}
