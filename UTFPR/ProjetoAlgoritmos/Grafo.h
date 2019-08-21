#define Branco 0
#define Cinza  1
#define Preto 2


typedef struct NoTag
{
    int peso;
    int id;
    int cor;
    int d;
    int pai;
    int f;
    int key;
    struct NoTag *prox;
    struct NoTag *down;

}no;

typedef struct
{
    no *inicioG;
    int numV;
}Grafo;

void Define(Grafo *G)
{
  G->inicioG = NULL;
  G->numV = 0;
}

int verificaV(Grafo *G,int v) // funcao que verifica se o vertice pertence ao grafo
{
  no *aux;
  aux = G->inicioG;

  while(aux!= NULL)
  {
    if(aux->id == v)
    {
      return 1;
    }
    aux = aux->down;
  }
  return 0;
}

no* buscaV(Grafo *G, int x) // funcao que retorna o vertice caso ele pertecer ao grafo
{
  no *aux;
  aux = G->inicioG;
  while(aux!= NULL)
  {
    if(aux->id == x)
    {
      return (aux);
    }
    aux = aux->down;
  }
  return NULL;
}

void inserirVertice(Grafo *G, int v) // funcao que insere o vertice no grafo
{
  no *novo;
  no *aux;

  if((G->inicioG == NULL) ) // caso nao existir nenhum vertice no grafo
  {
    novo = (no*)malloc(sizeof(no));
    novo->prox = NULL;
    novo->down = NULL;
    novo->id = v;
    novo->cor = Branco;
    G->inicioG = novo;
    G->numV++;
    printf("Inserido com sucesso o vertice : %d\n",v);
  }
  else if(verificaV(G,v) != 1 ) // verifica se o vertice ja existe no grafo ou nao
  {
    aux = G->inicioG;

    while(aux->down != NULL) // while para percorrer ate o final da lista de vertices
    {
      aux = aux->down;
    }

    novo = (no*)malloc(sizeof(no)); // aloca a memoria para o novo vertice e insere no final
    aux->down = novo;
    novo->prox = NULL;
    novo->down = NULL;
    novo->id = v;
    novo->cor = Branco;
    G->numV++; // aumenta o num de vertice
    printf("Inserido com sucesso o vertice : %d\n",v);
  }
  else
  {
    printf("O vertice : %d já existe no grafo.\n",v); // caso o vertice já existir no grafo
  }
}

int inserirAresta(Grafo *G, int v1, int v2, int peso)
{
  no *novo1;
  no *novo2;
  no *aux1;
  no *aux2;
  int flag =0;
  aux1 = G->inicioG;
  aux2 = G->inicioG;
  if((verificaV(G,v1)==1) && (verificaV(G,v2)==1) && (v1!=v2) &&(G->numV>1)) //verifica se existe os dois vertices digitados pelo usuário ou se o num de vertice é maior que 1 para poder realizar a insercao
  {

    while((aux2->id != v1) )  // encontra o primeiro vertice quando percorrido
    {
      aux2 = aux2->down;
    }
      aux1 = aux2; // aux1 recebe a mesma posicao que o ponteiro aux2

      if(aux1->prox == NULL) // caso nao tenha nenhuma aresta no vertice
      {
        novo1 = (no*)malloc(sizeof(no));
        novo1->prox = NULL;
        novo1->down = NULL;
        novo1->id = v2;
        novo1->peso = peso;
        aux1->prox = novo1;
      }
      else
      {
        aux1 = aux1->prox;

        while(aux1->prox != NULL) // while para percorrer ate o ultimo elemento da lista de arestas
        {
          if(aux1->id == v2)
          {
           return 1; //Retorna 1 caso a aresta ja tenha sido inserido entre esses dois vertices
          }
          aux1 = aux1->prox;
        }

        if(aux1->id == v2)
        {
          return 1; //Retorna 1 caso a aresta ja tenha sido inserido entre esses dois vertices(ultimo elemento que nao e verificado no while)
        }
          // caso a aresta nao tenha sido inserida anteriormente, aloca espaço para a aresta e insere no final lista
        novo1 = (no*)malloc(sizeof(no));
        novo1->prox = NULL;
        novo1->down = NULL;
        novo1->id = v2;
        novo1->peso = peso;
        aux1->prox = novo1;
      }
       // CASO O GRAFO NAO FOR DIRECIONADO, INSERE O PAR ORDENADO DIRETO
      // while(aux2->id != v2) // continua da onde o aux2 parou, percorre, e encontra o segundo vertice
      // {
      //   aux2 = aux2->down;
      // }
      //
      // aux1 = aux2;
      // // percorre ate a ultima posicao
      // while(aux1->prox != NULL)
      // {
      //   aux1 = aux1->prox;
      // } // * ****** insere na ultima posicao da lista de arestas
      //
      // novo2 = (no*)malloc(sizeof(no));
      // novo2->prox = NULL;
      // novo2->down = NULL;
      // novo2->id = v1;
      // novo2->peso = 0;
      // aux1->prox = novo2;
      // flag = 1;
    }
    else
    {
      return 1;
    }

      // Caso encontre o v2 primeiro
    // if(aux2->id == v2 && flag ==0)
    // {
    //   aux1 = aux2;
    //
    //   if(aux1->prox == NULL) // caso nao tenha nenhuma aresta no vertice
    //   {
    //     novo1 = (no*)malloc(sizeof(no));
    //     novo1->prox = NULL;
    //     novo1->down = NULL;
    //     novo1->id = v1;
    //     novo1->peso = 0;
    //     aux1->prox = novo1;
    //   }
    //   else
    //   {
    //     aux1 = aux1->prox;
    //
    //     while(aux1->prox != NULL)
    //     {
    //       if(aux1->id == v2 || aux1->id ==v1)    return 1; //Retorna 1 caso a aresta ja tenha sido inserido entre esses dois vertices
    //       aux1 = aux1->prox;
    //     }
    //
    //     if(aux1->id == v2 || aux1->id ==v1)
    //     {
    //       return 1; //Retorna 1 caso a aresta ja tenha sido inserido entre esses dois vertices(ultimo elemento que nao e verificado no while)
    //     }
    //
    //     novo1 = (no*)malloc(sizeof(no));
    //     novo1->prox = NULL;
    //     novo1->down = NULL;
    //     novo1->id = v1;
    //     novo1->peso = 0;
    //     aux1->prox = novo1;
    //   }
    //
    //   while(aux2->id != v1) // encontra o v1
    //   {
    //     aux2 = aux2->down;
    //   }
    //
    //   aux1 = aux2;
    //   // percorre ate a ultima posicao
    //   while(aux1->prox != NULL)
    //   {
    //     aux1 = aux1->prox;
    //   }
    //
    //   novo2 = (no*)malloc(sizeof(no));
    //   novo2->prox = NULL;
    //   novo2->down = NULL;
    //   novo2->id = v2;
    //   novo2->peso = 0;
    //   aux1->prox = novo2;
    // }
    // else
    // {
    //   return 1;
    // }
  return 0;
}

int removerA(no *vertice, int id)  // perceorre as arestas daquele vertice
{

  if(vertice->prox == NULL) // verifica se nao tem nenhuma aresta naquele vertice
  {
    // printf("nenhuma aresta a ser removida\n");
    return 0;
  }
  else
  {
    no *aux1;
    no *aux2;
    aux1 = vertice->prox;
    aux2 = vertice;

    while(aux1 != NULL) // percorre a lista de aresta ate chegar no null
    {
      if(aux1 ->id == id) // se encontrar aresta remove
      {
        aux2->prox = aux1->prox;
        aux1->prox = NULL;
        free(aux1); //desaloca a memoria daquela aresta
        return 1; // retorna 1 para avisar que houve uma aresta que foi removida
      }
      aux1 = aux1->prox;
      aux2 = aux2->prox;
    }
return 0; // caso 0  -> nao teve nenhuma aresta que foi removida
  }

}

int removerAresta(Grafo *G, int v1, int v2)  // perceorre as arestas daquele vertice
{

  if((verificaV(G,v1)==1) && (verificaV(G,v2)==1) && (v1!=v2) ) //verifica se existe os dois vertices digitados pelo usuário
  {
    no *aux1;
    aux1 = buscaV(G,v1);
    if(aux1->prox == NULL) // verifica se nao tem nenhuma aresta naquele vertice
    {
      // printf("nenhuma aresta a ser removida\n");
      return 0;
    }
    else
    {
      no *aux2;
      aux2 = aux1->prox;
      while(aux2 != NULL) // percorre a lista de aresta ate chegar no null
      {
        if(aux2->id == v2) // se encontrar aresta remove
        {
          aux1->prox = aux2->prox;
          aux2->prox = NULL;
          free(aux2); //desaloca a memoria daquela aresta
          return 1; // retorna 1 para avisar que houve uma aresta que foi removida
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
      }
      printf("Aresta a ser removida nao encontrada\n");
    }
  }
  printf("Aresta não encontrada\n");
}

void removerVertice(Grafo *G, int v)
{
  no *aux1;
  no *aux2;
  no *aux3;

  int flag = 0;
  aux3 = G->inicioG;
  // TRATAMENTO PARA O CASO SEJA PRIMEIRO VERTICE DO GRAFO
  if(verificaV(G,v) == 1) // verifica se o vertice inserido para remover pertence ao grafo -> se sim remove
  {
    if(aux3->id == v && aux3 == G->inicioG)
    {
      aux1 = aux3;

      if(aux1->prox!=NULL) // verifica se tem alguma aresta no primeiro vertice da da lista de vertices
      {
          while(aux1->prox != NULL) // while para remover arestas até o o prox de vertice apontar para nulo
          {
            aux2 = aux1->prox;
              while(aux2->prox != NULL) // percorre as arestas ate o prox do aux2 ser nulo
              {
                aux2 = aux2->prox;
                aux1 = aux1->prox;
              }
            aux1->prox = aux2->prox;
            aux2->prox = NULL;
            free(aux2); // limpa a memoria alocada para aquele no
            aux1 = aux3; // aux1 recebe a posicao do vertice que esta sendo percorrido
          }
      }
        // quando termina de eliminar as arestas, remove o vertice da lista
        if(aux3->down == NULL)
        {
          G->inicioG = aux3->down;
          free(aux3);
        }
        else
        {
          aux3 = aux3->down;
          G->inicioG = aux3;  // RECEBE O PROXIMO VERTICE COMO INICIO DO GRAFO
          aux1->down = NULL; // o proximo ponteiro recebe os ponteiros de inicio
          free(aux1); // e limpa a memoria alocada para aquele vertice
          aux2 = aux3->prox;
        }
    }

    while(aux3 != NULL) // enquanto o aux3 nao chega no final da lista de vertices (nulo)
    {
      if(aux3->id != v) // caso o vertice que o ponteiro aux3 aponta for diferente do valor informado pelo usuario
      {
        removerA(aux3,v); // funcao que verifica se tem alguma aresta conectada com o vertice que esta sendo excluido se sim elimina a aresta
        if(aux3->down != NULL)    aux1 = aux3->down; // caso o proximo vertice do aux3 nao seja nulo o aux1 recebe o vertice abaixo de aux3
      }

      if(aux1->id == v) // caso o id do aux1 seja o vertice passado pelo usuario
      {
        if(aux1->prox != NULL) // se o prox do aux1 nao seja nulo
        {
          while(aux1->prox != NULL) // enquanto o prox do aux1 nao seja null
          {
              aux2 = aux1->prox;
              while(aux2->prox != NULL) // enquanto o prox do aux2 nao seja null
              {
                aux2 = aux2->prox; // aux2 recebe o proximo
                aux1 = aux1->prox; // aux1 recebe o proximo
              }
              aux1->prox = aux2->prox;
              aux2->prox = NULL;
              free(aux2); // aux1 recebe o prox do aux2 e da free no aux2
              aux1 = aux3->down; // aux1 recebe o vertice que esta sendo removido
            }
        }
        aux3->down = aux1->down;
        aux1->down = NULL; // desconecta vertice do grafo
        free(aux1); // desaloca memoria
      }
      aux3 = aux3->down; // aux3 recebe o vertice abaixo dele
    }
          G->numV--;
           printf("Removido com Sucesso\n\n");
  }
  else
  {
    printf("Vertice nao pertence ao grafo\n");
  }


}

void visualizarGrafo(Grafo *G)
{
  no *aresta;
  no *vertice;
  vertice = G->inicioG;
  aresta = G->inicioG;

  if((G->inicioG == NULL) )
  {
    printf("nenhum vertice ou aresta inserido\n");
  }
  else
  {
    while((aresta!= NULL) && (vertice != NULL)) // enquanto o ponteiro vertice e aresta nao apontar para nulo
    {
      printf("%d->\t", vertice->id); // imprimi vertice
      while(aresta->prox !=NULL)
      {
        aresta = aresta->prox;  //
        printf("%d-\t", aresta->id); // imprimi aresta
      }
      printf("\n");
      vertice = vertice->down;  // vertice recebe o proximo
      aresta = vertice; // aresta recebe a posicao do proximo vertice que sera percorrido
    }
  }
  printf("\n");
}

void grauVertice(Grafo *G,no *p)
{
  int grau=0;
  while(p->prox != NULL) /**enquanto diferente de nulo, incrementa grau do vertice**/
  {
    grau++;
    p = p->prox;
  }
  printf("O vertice é de grau %d\n", grau);
}

void esvaziaGrafo(Grafo *G)
{
    if(G->inicioG == NULL)
    {
      printf("Grafo vazio\n");
    }
    else
    {
      no *aux;
      aux = G->inicioG;
      while(aux != NULL)
      {
        if(aux->down == NULL)
        {
          removerVertice(G,aux->id);
          aux = G->inicioG;
        }
        else
        {
          aux = aux->down;
        }
      }
      printf("grafo esvaziada\n" );
    }
}

int verificaGrafo(Grafo *G)
{
  no *vertice;
  no *aresta;

  vertice = G->inicioG;
  while(vertice != NULL)
  {
    aresta = vertice->prox;
    while(aresta != NULL)
    {
      if(verificaV(G,aresta->id) == 1) // verifica se vertice existe, se não existe entao grafo é desconexo
        aresta = aresta->prox;
      else
        return 1;
    }
    vertice = vertice->down;
  }
  return 0;
}
