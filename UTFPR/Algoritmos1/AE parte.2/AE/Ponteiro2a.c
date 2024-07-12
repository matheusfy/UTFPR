/*a)	Uma função que recebe a quilometragem total, a distância entre cada pedágio e o consumo do veículo,
 e calcule o número de pedágios daquela estrada e a quantidade de litros de combustível gasta*/
#include <stdio.h>
#include <stdlib.h>
 int calcula(int qm, int dp, int cv, float *n, float *p)
 {
     *n = qm/dp;
     *p = qm/cv;
 }

int main (void)
{
    int qm,dp,cv;
    float n=0,p=0;
            fflush(stdin);
            printf("Insira a quilometragem total(km): \n");
            scanf("%d", &qm);
            fflush(stdin);
            printf("Insira a distancia entre cada pedagio (km): \n");
            scanf("&d", &dp);
            fflush(stdin);
            printf("Insira o consumo do veiculo (km/h): \n");
            scanf("%d", &cv);
            fflush(stdin);

            calcula(qm,dp,cv,&n,&p);

            printf("Quantidade de pedagios : %.1f \n", n);
            printf("Quantidade de combustivel gasto %.1f(L)\n",p);
            return 0;

}
