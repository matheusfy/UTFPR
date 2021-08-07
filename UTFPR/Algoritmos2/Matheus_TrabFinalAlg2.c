#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafo.h"
#include "Buscas.h"
#define clear() printf("\033[H\033[J")

#define Branco 0
#define Cinza  1
#define Preto 2



void GrafoTeste(Grafo *G)
{
  inserirVertice(G,1);
  inserirVertice(G,2);
  inserirVertice(G,3);
  inserirVertice(G,4);
  inserirVertice(G,5);
  inserirVertice(G,6);
  inserirVertice(G,7);
  inserirVertice(G,8);
  inserirVertice(G,9);
  inserirVertice(G,10);
    inserirAresta(G,1,2,7);
    inserirAresta(G,2,1,7);
    inserirAresta(G,2,3,4);
    inserirAresta(G,3,2,4);
    inserirAresta(G,3,4,1);
    inserirAresta(G,4,3,1);
    inserirAresta(G,5,4,3);
    inserirAresta(G,4,5,3);
    inserirAresta(G,5,6,18);
    inserirAresta(G,6,5,18);
    inserirAresta(G,7,8,3);
    inserirAresta(G,8,7,3);
    inserirAresta(G,8,9,4);
    inserirAresta(G,9,8,4);
    inserirAresta(G,10,9,2);
    inserirAresta(G,9,10,2);

    inserirAresta(G,4,2,5);
    inserirAresta(G,2,4,5);
    inserirAresta(G,5,3,4);
    inserirAresta(G,3,5,4);

    inserirAresta(G,1,6,8);
    inserirAresta(G,6,1,8);
    inserirAresta(G,6,7,9);
    inserirAresta(G,7,6,9);
    inserirAresta(G,5,1,10);
    inserirAresta(G,1,5,10);
    inserirAresta(G,4,1,9);
    inserirAresta(G,1,4,9);
    inserirAresta(G,2,9,9);
    inserirAresta(G,9,2,9);
    inserirAresta(G,2,10,9);
    inserirAresta(G,10,2,9);
    inserirAresta(G,1,10,8);
    inserirAresta(G,10,1,8);
    inserirAresta(G,1,8,9);
    inserirAresta(G,8,1,9);
    inserirAresta(G,6,8,9);
    inserirAresta(G,8,6,9);
    inserirAresta(G,7,9,6);
    inserirAresta(G,9,7,6);
    inserirAresta(G,8,10,2);
    inserirAresta(G,10,8,2);

}


void testeMatriz(Grafo *G)
{
  inserirVertice(G,1);
  inserirVertice(G,2);
  inserirVertice(G,3);
  inserirVertice(G,4);
  inserirVertice(G,5);
  inserirAresta(G,1,2,4);
  inserirAresta(G,2,1,4);
  inserirAresta(G,1,3,4);
  inserirAresta(G,3,1,4);
  inserirAresta(G,3,2,4);
  inserirAresta(G,2,3,4);
  inserirAresta(G,4,2,4);
  inserirAresta(G,2,4,4);
  inserirAresta(G,4,3,4);
  inserirAresta(G,3,4,4);
  inserirAresta(G,3,5,4);
  inserirAresta(G,5,3,4);
  inserirAresta(G,4,5,4);
  inserirAresta(G,5,4,4);
}

void matrizadj(Grafo *G) // mostra na tela a matriz de adj
{
  no *v;
  no *a;
  no *aux;

  v = G->inicioG;
  printf("  "); // espaco para a estetica da matriz
  while(v!= NULL) // while para a coluna
  {
    printf("%d\t",v->id );
    v = v->down;
  }
  printf("\n");
  v = G->inicioG;

  while(v != NULL) // enquanto ponteiro v != null
  {
    printf("%d ",v->id ); // print para mostrar o valor da linha
    aux = G->inicioG;

    while(aux != NULL) // aux percorre a lista de vertice
    {
      a = v->prox;  // a recebe a primeira aresta do vertice que esta sendo analizado
      while(a != NULL && a->id != aux->id ) // enquanto 'a' difere de null e aux->id
      {
        a = a->prox;
      }
      if(a == NULL) // se 'a' igual a null, posicao é zero
        printf("0\t");
      else
        printf("1\t"); // se tem alguma aresta ligado com o vertice que aux ta percorrendo '1'
      aux = aux->down;
    }
    printf("\n");
    v = v->down; // avança vertice a ser analizado
  }
}

int main(int argc, char *argv[])
{
  Grafo G;
  Define(&G);
  Grafo Q;
  Define(&Q);
  int opc, vertice=0;
  int vertice1 = 0, vertice2 =0;
  int y=0, z=0;
  int peso = 0;
  no *aux;
  int cont;


  do{
  /*  ------------   MENU --------------*/
       printf("\n1-----INSERIR VERTICE.\n");
       printf("2-----INSERIR ARESTA.\n");
       printf("3-----VISUALIZAR GRAFO.\n");
       printf("4-----REMOVER VERTICE.\n");
       printf("5-----REMOVER ARESTA.\n");
       printf("6-----SAIR.\n");
       printf("7-----LIMPAR TELA.\n");
       printf("8-----Informar o grau do vertice.\n");
       printf("9-----Informar se o grafo é conexo.\n");
       printf("10-----Converter grafo para Matriz de Adjacencia\n");
       printf("11-----Caminhamento em Amplitude (Busca em Largura).\n");
       printf("12-----Caminhamento em Profundidade.\n");
       printf("13-----Caminho M ́ınimo (Algoritmo de Dijkstra).\n");
       printf("14-----Arvore Geradora M ́ınima (Algoritmo de Prim).\n");
       printf("15-----Apagar Grafo existente\n");
       printf("16-----Insere Grafo Teste\n");

       scanf("%d",&opc);

       switch (opc)
       {

        case 1:
            printf("Digite um numero para o vertice: \n");
            scanf("%d", &vertice);
            inserirVertice(&G,vertice); // funcao que insere o vertice no grafo
        break;

        case 2:
          // passa apenas uma dos pares ordenados (v1,v2) no caso (1,2) 1->2
            printf("Inserir aresta de : ");
            scanf("%d", &vertice1);
            printf("para : ");
            scanf("%d", &vertice2);
          printf("Insira um peso para a aresta\n");
          scanf("%d",&peso);
            if(inserirAresta(&G,vertice1,vertice2,peso)==0 && inserirAresta(&G,vertice2,vertice1,peso)==0)    printf("inserido a aresta com sucesso.\n");
            else        printf("Falha na insercao da aresta, verifique se a aresta já existe ou o vertice existe\n");
            break;

        case 3:
            visualizarGrafo(&G); // mostra o grafo na tela
        break;

        case 4:
          printf("Qual vertice deve ser removido?: ");
          scanf("%d",&vertice);
          if(verificaV(&G,vertice) == 1) // verifica se o vertice inserido para remover pertence ao grafo -> se sim remove
          {
            removerVertice(&G,vertice); //funcao para remocao do vertice
            printf("Removido com Sucesso\n\n");
          }
          else
          {
            printf("O vertice inserido para remover nao pertence ao grafo\n"); // caso o vertice nao existe no grafo
          }
          visualizarGrafo(&G); // mostra o grafo na tela
        break;

        case 5:

              printf("Entre quais vertices a aresta a ser removida esta?\n");
              printf("Vertice 1: ");
              scanf("%d", &vertice1);
              printf("Vertice2: ");
              scanf("%d", &vertice2);
              removerAresta(&G,vertice1,vertice2); // remove aresta entre v1 e v2
              visualizarGrafo(&G);

        break;

        case 6:
                esvaziaGrafo(&G); // desaloca memoria utilizada para o grafo
                visualizarGrafo(&G);
              printf("SAINDO.\n");
        break;

        case 7:
            clear(); // funcao para limpar a tela (linux)
        break;

        case 8:
        printf("Digite o valor do vertice: \n");
        scanf("%d", &vertice);
        if(verificaV(&G,vertice)==1)
        {
          grauVertice(&G,buscaV(&G,vertice));
        }
        break;

        case 9:
          // conexo ou nao

            bel(&G,buscaV(&G,G.inicioG->id),&Q); // realiza a busca em largura
            BUEL(&G); // mostra o resultado

            if(conexo(&G)== 0) // vai para funcao que verifica se é conexo ou nao
              printf("Grafo conexo\n");
            else
              printf("Grafo não é conexo\n");

        break;

        case 10:
          // grafo para matriz de adjacencia
            // testeMatriz(&G);
            matrizadj(&G);
              // esvaziaGrafo(&G);
        break;

        case 11:
          //Caminhamento em amplitude(Busca em Largura)
          printf("por qual vertice comecar? : \n");
          scanf("%d",&vertice );
          if(verificaV(&G,vertice)==1) // verifica se o vertice raiz pertence ao grafo
          {
            bel(&G,buscaV(&G,vertice),&Q); // realiza a busca em largura
            aux = G.inicioG;
            while(aux != NULL) // imprimi o resultado
            {
              printf("v: %d - pai: %d - d: %d\n",aux->id , aux->pai, aux->d);
              aux = aux->down;
            }
          }
          else
          {
            printf("tente outro vertice\n");
          }

        break;
        case 12:
          // Caminhamento em profundidade
              cont=1;
              printf("por qual vertice comecar? : \n");
              scanf("%d",&vertice );
              if(verificaV(&G,vertice)==1) // verifica se o vertice raiz pertence ao grafo
              {
                cont = DFS(&G,buscaV(&G,vertice), &Q,cont); // começa a busca e retorna o valor do contador em que parou
                aux = G.inicioG; // recebe inicio da lista
                /*while para caso exista algum vertice em branco ainda*/
                while(aux != NULL) // percorre ate o final da lista
                {
                  if(aux->cor == Branco) // se encontrar algum vertice branco, começa a busca fazendo ele como vertice raiz
                  {
                    aux->cor = Cinza;
                    aux->d = cont;
                    cont ++;
                    inserirVertice(&Q,aux->id); // empilha (reaproveitado a funcao inserir vertice)
                    cont = DFS(&G,aux,&Q, cont);
                  }
                  aux = aux->down;
                }
                aux = G.inicioG;
                while(aux != NULL) // imprimi o resultado
                {
                  printf("v: %d - d: %d - f: %d - pai: %d \n",aux->id , aux->d, aux->f, aux->pai);
                  aux = aux->down;
                }
              }
              else
              {
                printf("tente outro vertice\n");
              }
        break;

        case 13:
          //Caminho Mínimo(Algoritmo de Dijkstra)
          printf("por qual vertice comecar? : \n");
          scanf("%d",&vertice );
          if(verificaV(&G,vertice)==1) // verifica se o vertice raiz pertence ao grafo
          {
            Dijkstra(&G,buscaV(&G,1) ,&Q);
          }
          else
          {
            printf("tente outro vertice\n");
          }
          aux = G.inicioG;
          while(aux != NULL) // imprimi o resultado
          {
            printf("v: %d - pai: %d - d: %d\n",aux->id , aux->pai, aux->d);
            aux = aux->down;
          }
        break;

        case 14:
          //árvore geradora mínima(Algoritmo de Prim)

          printf("por qual vertice comecar? : \n");
          scanf("%d",&vertice );
          if(verificaV(&G,vertice)==1) // verifica se o vertice raiz pertence ao grafo
          {
            AGMPrim(&G,buscaV(&G,1),&Q); // começa o algoritmo de prim
          }
          else
          {
            printf("tente outro vertice\n");
          }

          aux = G.inicioG;
          while(aux != NULL) // imprimi o resultado
          {
            printf("v: %d - pai: %d - key: %d\n",aux->id , aux->pai, aux->key);
            aux = aux->down;
          }
          break;

        case 15:
        esvaziaGrafo(&G); // desaloca memoria utilizada para o grafo
        break;

        case 16:
        GrafoTeste(&G); // adiciona grafo teste
        break;
     }
  }while(opc != 6);
  return 0;
}
