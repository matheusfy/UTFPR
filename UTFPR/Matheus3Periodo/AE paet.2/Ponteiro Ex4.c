 /*a)	Uma função que recebe a quilometragem total, a distância entre cada pedágio e o consumo do veículo,
  e calcule o número de pedágios daquela estrada e a quantidade de litros de combustível gasta;
b)	Um vetor de “structs” que armazene os valores computados em (a);
c)	Uma função que calcule o custo da viagem para cada estrada, recebendo como parâmetros: uma struct (conforme criada em (b)),
o preço de cada pedágio e o preço do combustível. Ex.: se cada pedágio custa 10 duckdollars e o combustível é vendido por 3 duckdollars,
o custo da viagem em cada estrada seria:
A	115,00
B	122,35
C	109,39
D	101,06
Teste também com outros preços. A estrada D será sempre a mais vantajosa, mesmo baixando/aumentando o preço do pedágio ou do combustível?
*/




 #include <stdio.h>

 struct informacao{

    float qt , dp, cv;


 }
 void calcula(int qm, int dp, int cv, float *n, float *p)
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
