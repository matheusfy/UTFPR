#include <stdbool.h>
#include <time.h>
#define Branco 0
#define Cinza  1
#define Preto 2


int inicializaGuloso(Grafo *G) // inicializa guloso, pintando todos vertices e arestas de branco
{
  no *vertice;
  no *aresta;
  vertice = G->inicioG;
  while(vertice != NULL) // limpa a cor das arestas e vertices
  {
    aresta = vertice->prox;
    while(aresta != NULL)
    {
      vertice->naresta++;
      aresta->cor = Branco;
      aresta = aresta->prox;
    }
    vertice->cor = Branco;
    vertice = vertice->down;
  }

  return 0;
}

no *buscaVertice(Grafo *G) // funcao que busca o vertice de maior grau que ainda não tem todas as arestas cobertas
{
    no *aux;
    no *vertice;
    vertice = G->inicioG;
    aux = vertice->down;

    while(aux != NULL)
    {
      if((grauVertice(G,aux) > grauVertice(G,vertice) && aux->cor != Preto) || (aux->prox == NULL && aux->cor == Branco && vertice->cor == Preto))
      {
        vertice = aux;
      }
      aux = aux->down;
    }
    if(vertice->cor == Preto)
    {
      return NULL;
    }

    return vertice;
}

int pintaVertice(Grafo *G, int vertice, int aresta)
{
    no *aux;
    aux = G->inicioG;
    while(aux->id != vertice) // percorre ate encontrar o vertice
    {
      aux = aux->down;
    }
    if(aux->cor!= Preto) // se a cor do vertice nao é preta
    {
      no * aux2;
      aux2 = aux->prox; // recebe a aresta do vertice
      while(aux2->id != aresta) // percorre ate encontrar o id da aresta a ser pintada
      {
        aux2 = aux2->prox;
      }
      aux2->cor = Preto; // pinta a aresta encontrada de preto
      aux->naresta--; // diminui o num de aresta do vertice
      if(aux->naresta == 0) // se o vertice nao tem mais ligacoes entao esta coberto e pinta de preto
      {
        aux->cor = Preto;
      }
      return true;
    }
    else
    {
      return false;
    }


}

int guloso(Grafo *G, int vetor[], double *tempo)
{
    no *vertice;
    no *aresta;
    no *noGrau;
    int flag = 0, sorteado = 0;
    // adicionando aleatoriedade
    // srand(time(NULL));
    // sorteado = rand()% G->numV+1;
    // printf("sorteado %d, tamanho vetor: %d\n", sorteado, G->numV);
    inicializaGuloso(G); // prepara grafo para realizar a busca

    clock_t init = clock(); // começa a medir o tempo
    while(buscaVertice(G) != NULL) // busca o vertice com maior numero de arestas não cobertas
    {
        // if(flag == 0)
        // {
        //   noGrau = buscaV(G,sorteado);
        //   flag = 1;
        // }
        // else
        // {
          noGrau = buscaVertice(G);
        // }
        aresta = noGrau->prox;

        while(aresta != NULL) // loop para percorrer as arestas do vertice
        {
          pintaVertice(G,aresta->id,noGrau->id); // pula para uma funcao que pinta a adjacencia do vertice
          if(aresta->cor != Preto) // se a aresta nao tem a cor preta entao pinta
          {
            aresta->cor = Preto;
            noGrau->naresta--; // diminui o grau do vertice
          }
          aresta = aresta->prox; // proxima aresta
        }
        noGrau->cor = Preto; // pinta o vertice de preto
        // printf("pintou %d\n", noGrau->id);
        vetor[noGrau->id-1] = 1; // seta o indice do vertice que foi pintado no vetor final
    }
    clock_t end = clock(); // pega o tempo final
    *tempo = (double)(end - init)/ CLOCKS_PER_SEC; // calculo do tempo de execucao

}




// int dequeue(Grafo *Q) // funcao que retorna o id do no retirado da fila
// {
//
//   no *aux1;
//   no *aux2;
//   int x =0;
//   aux1 = Q->inicioG;
//   if(Q->inicioG == NULL) // se vazio retorna -1
//   {
//     return -1;
//   }
//   else
//   {
//     if(aux1->down == NULL) // se unico na lista
//     {
//       x = aux1->id;
//       Q->numV--;
//       Q->inicioG = aux1->down;
//       free(aux1); //desaloca memoria
//       return x; // retorna id do no desalocado
//     }
//     else
//     {
//       /*********retiro o primeiro da fila***********/
//       aux2 = aux1->down;
//       Q->inicioG = aux2;
//       aux1->down = NULL;
//       Q->numV--;    // diminui num da lista
//       x = aux1->id;
//       free(aux1); // desaloca memoria
//       return x; // retorna id
//     }
//   }
// }
//
//   /*******inicialização da busca em largura *******/
// void inicializa(Grafo *G , no *s, Grafo *Q)
// {
//   no *u;
//   u = G->inicioG;
//   while(u != NULL) // pinta todos menos a raiz de branco
//   {
//     if(u != s)
//     {
//       u->cor = Branco;
//       u->d = -1;
//       u->pai = -1;
//     }
//
//     u = u->down;
//   }
//     // raiz recebe é pintado de cinza
//   s->cor = Cinza;
//   s->d = 0;
//   s->f = -1;
//   s->pai = -1;
//   inserirVertice(Q,s->id); // enfileirar (reaproveitado a funcao inserir vertice)
// }
//
//   /*******inicializa busca em profundidade**************/
//   void inicializabp(Grafo *G , no *s, Grafo *Q,int cont)
//   {
//     no *u;
//     u = G->inicioG;
//     while(u != NULL) // pinta todos menos a raiz de branco
//     {
//       if(u != s)
//       {
//         u->cor = Branco;
//         u->d = -1;
//         u->pai = -1;
//       }
//
//       u = u->down;
//     }
//       // raiz recebe é pintado de cinza
//     s->cor = Cinza;
//     s->d = cont;
//     s->f = -1;
//     s->pai = -1;
//     inserirVertice(Q,s->id); // enfileirar (reaproveitado a funcao inserir vertice)
//   }
//
//       /*******BUSCA EM LARGURA********/
// void bel(Grafo *G, no *s,Grafo *Q)
// {
//     int u;
//     no *aux;
//     no *aux2;
//     no *v;
//     no *fila;
//
//     inicializa(G,s,Q); // inicializacao dos vertices
//
//
//       while(Q->inicioG != NULL)
//       {
//
//         u = dequeue(Q);  //desempilha
//         // visualizarGrafo(G);
//
//         aux = buscaV(G,u); // busca o vertice
//         // visualizarGrafo(G);
//         aux2 = aux->prox;
//         while(aux2 != NULL) // verifica se tem aresta conectada com algum vertice
//         {
//             v = buscaV(G,aux2->id); //busca o vertice
//             if(v->cor == Branco) // verifica se é branco e entao pinta de cinza
//             {
//               v->cor = Cinza;
//               v->d = aux->d + 1;
//               v->pai = aux->id;
//               inserirVertice(Q,v->id); // empilha
//             }
//             aux2 = aux2->prox; // passa pra prox adj
//         }
//         aux->cor = Preto; //quando terminar de percorrer a adj(u) pinta de preto
//       }
// }
//
//
//
//   /******DESEMPILHA******/
//   int pop(Grafo *G)
//   {
//     no *aux;
//     no *aux1;
//     int x=0;
//     if(G->inicioG == NULL) // se vazio retorna -1
//     {
//       return -1;
//     }
//     else
//     {
//       aux = G->inicioG;
//       if(aux->down == NULL)
//       {
//           x = aux->id;
//           G->numV--;
//           G->inicioG = aux->down;
//           return x;
//           free(aux); //desaloca memoria
//       }
//       else
//       {
//         while(aux->down->down != NULL)
//         {
//           aux = aux->down;
//         }
//         x = aux->down->id;
//         G->numV--;
//         aux1 = aux->down;
//         aux->down = aux1->down;
//         free(aux1); //desaloca memoria
//         return x; // retorna id do no desalocado
//       }
//     }
//   }
//
//   /****** Busca em profundidade recursiva *****/
//   int DFS(Grafo *G, no *s, Grafo *pilha,int cont)
//   {
//     no *u;
//     no *v;
//     no *aux;
//     no *aux1;
//     if(pilha->inicioG==NULL && cont ==1) // caso seja a primeira vez a entrar na busca
//     {
//       inicializabp(G,s,pilha,cont); // inicializa os valores do vertice para a busca
//       cont++;
//     }
//       while(pilha->inicioG != NULL) // enquanto pilha nao esta vazia
//       {
//         u = pilha->inicioG; // recebe inicio
//
//         while(u->down != NULL) // vai para o topo da pilha
//             u = u->down;
//
//         v = buscaV(G,u->id); // recebe o vertice que esta no topo da pilha
//         aux = v->prox; // recebe a adjacencia do topo da pilha
//
//         while(aux != NULL) // enquanto nao chega no final da lista de adj
//         {
//           aux1 = buscaV(G,aux->id); //busca o valor do vertice
//           if(aux1->cor == Branco) // se vertice é branco
//           {
//             aux1->cor = Cinza; // pinta de cinza
//             aux1->d = cont; // recebe o valor em que foi encontrado
//             aux1->pai = v->id; // atribui o pai do vertice
//             cont++;
//             inserirVertice(pilha,aux1->id);
//              cont = DFS(G,s,pilha,cont);// cont recebe o valor que vai ser retornado na recursao
//           }
//           aux = aux->prox; // recebe proximo da lista de adj
//         }
//         v->cor = Preto; // finaliza vertice
//         v->f = cont; // adiciona valor do contador em que o vertice foi finalizado
//         pop(pilha); // desempilha
//         cont = cont +1; // incrementa contador
//         return cont; // retorna contador
//       }
//
//
//
//   }
//
//   /***************** Busca minimo para Algoritmo de Prim **************************/
//
//   int minimo(Grafo *Q)
//   {
//       no *aux;
//       int id;
//       no *chave;
//       no *aux1;
//       aux = Q->inicioG;
//
//       if(aux->down == NULL)
//       {
//         id = aux->id;
//         Q->inicioG = aux->down;
//         free (aux);
//         return(id);
//       }
//       else
//       {
//         id = aux->id; // guarda a chave do primeiro a ser comparado
//         aux1 = Q->inicioG;
//
//         while(aux->down != NULL) // enquanto nao chega no final da lista
//         {
//           if(aux1->key > aux->down->key) // se key do anterior maior que o do prox
//           {
//             id = aux->down->id; // entao minimo recebe a key do prox
//             aux1 = aux->down;
//           }
//           aux = aux->down;
//         }
//
//         aux = Q->inicioG;
//         if(aux == aux1) // se o elemnto com o menor key é o primeiro
//         {
//           //retorno a key e atualizo Q->inicioG
//           Q->inicioG = aux1->down;
//           aux1->down = NULL;
//           free(aux1);
//           return id;
//         }
//
//         while(aux->down != aux1 ) // percorre ate que o no guardado seja encontrada
//         {
//           aux = aux->down;
//         }
//         aux->down = aux1->down;
//         aux1->down = NULL;
//         free(aux1);
//         return id;
//       }
//
//   }
//
//   /***************** Algoritmo de Prim **************************/
//
//   void AGMPrim(Grafo *G, no *r,Grafo *Q)
//   {
//     int u;
//     no *vertice;
//     no *aux2;
//
//     vertice = G->inicioG;
//     aux2 = G->inicioG;
//     while(aux2!= NULL) /**inicializaçao dos vertices **/
//     {
//       aux2->pai = -1;
//       aux2->key = 999;
//       aux2 = aux2->down;
//     }
//     r->key = 0;
//
//     while(vertice!=NULL)// Q:= V[G]
//     {
//       inserirVertice(Q,vertice->id);
//       vertice = vertice->down;
//     }
//
//     aux2 = Q->inicioG;
//     while(aux2!= NULL) // atribuicao das key para os elementos em Q
//     {
//       if(aux2->id == r->id)
//         r->key = 0;
//       else
//         aux2->key = 999;
//       aux2 = aux2->down;
//     }
//
//     no *aux;
//     no *v;
//     while(Q->inicioG != NULL)
//     {
//       u = minimo(Q);
//       vertice = buscaV(G,u);
//       aux = vertice->prox;
//       while(aux != NULL) // percorre todas adj[u]
//       {
//         v  = buscaV(G,aux->id);
//         if((verificaV(Q,aux->id) == 1) && aux->peso < v->key ) // se vertice da adj[u] E em Q
//         {
//               v->pai = u; // vertice guarda o vertice pai
//               v->key = aux->peso; //vertice guarda o peso da aresta como key
//               buscaV(Q,aux->id)->key = aux->peso;
//               // printf("key : %d\n",buscaV(G,aux->id)->key ); // quando o valor do
//         }
//         else if(Q->inicioG == NULL)
//         {
//           if( aux->peso < v->key ) // se vertice da adj[u] E em Q
//           {
//                 v->pai = u; // vertice guarda o vertice pai
//                 v->key = aux->peso; //vertice guarda o peso da aresta como key
//           }
//         }
//         aux = aux->prox;
//       }
//     }
//
//   }
//
//   /******************Verifica Se Grafo é conexo*******************/
// int conexo(Grafo *G)
// {
//   no *teste;
//   teste = G->inicioG;
//
//   while(teste != NULL) // se encontrar algum no com a cor branca retorna 1
//   {
//     if(teste->cor == Branco)
//     {
//       return 1;
//     }
//     teste = teste->down;
//   }
//   return 0;
// }
//
// /***************** Algoritmo de relaxaçao **************************/
// void relax(Grafo *G, Grafo *Q, int u)
// {
//   no *v;
//   no *aux;
//   no *vertice;
//   vertice = buscaV(G,u);
//
//   aux = vertice->prox;
//   while(aux != NULL) // percorre todas adj[u]
//   {
//     v  = buscaV(G,aux->id);
//     if( v->d > (aux->peso + vertice->d)   ) // se vertice da adj[u] E em Q
//     {
//           v->pai = u; // vertice guarda o vertice pai
//           v->d = aux->peso + vertice->d; //vertice recebe a soma do peso e a distancia percorrida ate o anterior
//           // printf("key : %d\n",buscaV(G,aux->id)->key ); // quando o valor do
//     }
//     aux = aux->prox;
//   }
//
// }
//
//  /*****************busca do minimo para dijkstra****************************/
// int minimoDj(Grafo *Q)
// {
//     no *aux;
//     int id;
//     no *chave;
//     no *aux1;
//     aux = Q->inicioG;
//
//     if(aux->down == NULL)
//     {
//       id = aux->id;
//       Q->inicioG = aux->down;
//       free (aux);
//       return(id);
//     }
//     else
//     {
//       id = aux->id; // guarda a chave do primeiro a ser comparado
//       aux1 = Q->inicioG;
//
//       while(aux->down != NULL) // enquanto nao chega no final da lista
//       {
//         if(aux1->d > aux->down->d) // se key do anterior maior que o do prox
//         {
//           id = aux->down->id; // entao minimo recebe a key do prox
//           aux1 = aux->down;
//         }
//         aux = aux->down;
//       }
//
//       aux = Q->inicioG;
//       if(aux == aux1) // se o elemnto com o menor key é o primeiro
//       {
//         //retorno a key e atualizo Q->inicioG
//         Q->inicioG = aux1->down;
//         aux1->down = NULL;
//         free(aux1);
//         return id;
//       }
//
//       while(aux->down != aux1 )
//       {
//         aux = aux->down;
//       }
//       aux->down = aux1->down;
//       aux1->down = NULL;
//       // printf("aux1 : %d\n", aux1->id );
//       free(aux1);
//       return id;
//     }
//
// }
//    /***************** Algoritmo de Dijkstra **************************/
// int Dijkstra(Grafo *G, no *s, Grafo *Q)
// {
//   int u;
//   no *v;
//   no *aux;
//   no *aux1;
//   no *vertice;
//
//   vertice = G->inicioG;
//
//   while(vertice != NULL) // atribui distancia grande para todos os nos alem da raiz
//   {
//     if(vertice->id == s->id)
//     {
//       s->d = 0;
//       vertice->pai = -1;
//     }
//     else
//     {
//       vertice->d = 999;
//       vertice->pai = -1;
//     }
//     vertice = vertice->down;
//   }
//   vertice = G->inicioG;
//   while(vertice!=NULL)// Q:= V[G]
//   {
//     inserirVertice(Q,vertice->id);
//     vertice  = vertice->down;
//   }
//
//     vertice = Q->inicioG;
//     while(vertice!= NULL) // atribuicao da distancia para os elementos em Q
//     {
//       if(vertice->id == s->id)
//         vertice->d = 0;
//       else
//         vertice->d = 999;
//       vertice = vertice->down;
//     }
//   while(Q->inicioG != NULL)
//   {
//      u = minimo(Q); // retira o minimo
//      relax(G,Q,u); // começa o algortmo de relaxaçao
//   }
//
// }
