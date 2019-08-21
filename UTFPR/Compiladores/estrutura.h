#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NoTag
{
    char info[30];  // caracter do arquivo
    int linha;
    struct NoTag *prox;
    struct Notag *down;
} no;
typedef struct
{
    no *inicio;
    no *fim;
    int nelem;
} Lista;

void Definir(Lista*L)
{
    L->inicio = NULL;
    L->fim = NULL;
    L->nelem = 0;
}

void Inserir(Lista*L, no *novo)   // insere nó na ultima posicao
{
    if(L->inicio == NULL)
    {
        novo->prox= NULL;
        novo->down = NULL;
        L->inicio = novo;
        L->fim = novo;
        L->nelem++;
    }
    else
    {
        novo->prox = NULL;
        novo->down = NULL;
        L->fim->prox = novo;
        L->fim = novo;
        L->nelem++;
    }

}

void imprimir(Lista*L)
{
    no *p;
    if (L->inicio==NULL) // verificacao se a lista ta vazia
    {
        printf("Lista vazia\n");
    }
    p=L->inicio;
    printf("***************LISTA DE TOKENS***************\n"   );
    while(p!=NULL)
    {

        printf("<%s,%d>\n",p->info,p->linha);
        p=p->prox;

    }

}

no compara(char *str, no *p,int *erro) // funcao que verifica se é palavra reservada, identificador ou numero e se é valido ou nao, retornando um no
{
  int i=0;
  if(strcmp(str, "if") == 0)
  {
    strcpy(p->info,"IF"); // Funcao que copia string em outra
  }
  else if(strcmp(str, "then")==0)
  {
    strcpy(p->info,"THEN");
  }
  else if(strcmp(str, "else")==0)
  {
    strcpy(p->info,"ELSE");
  }
  // else if(strcmp(str, "end")==0)
  // {
  //   strcpy(p->info,"END");
  // }
  else if(strcmp(str, "repeat")==0)
  {
      strcpy(p->info,"REPEAT");
  }
  else if(strcmp(str, "until")==0)
  {
    strcpy(p->info,"UNTIL");
  }
  else if(strcmp(str, "read")==0)
  {
    strcpy(p->info,"READ");
  }
  else if(strcmp(str, "write")==0)
  {
      strcpy(p->info,"WRITE");
}
  else if(strcmp(str, "+")==0)
  {
      strcpy(p->info,"PLUS");
  }
  else if(strcmp(str, "-")==0)
  {
      strcpy(p->info,"MINUS");
  }
  else if(strcmp(str, "*")==0)
  {
    strcpy(p->info,"TIMES");
  }
  else if(strcmp(str, "/")==0)
  {
    strcpy(p->info,"DIV");
  }
  else if(strcmp(str, "=")==0)
  {
    strcpy(p->info,"EQUAL");
  }
  else if(strcmp(str, "<")==0)
  {
    strcpy(p->info,"LESS");
  }
  else if(strcmp(str, "(")==0)
  {
    strcpy(p->info,"LBRACKET");
  }
  else if(strcmp(str, ")")==0)
  {
    strcpy(p->info,"RBRACKET");
  }
  else if(strcmp(str, ";")==0)
  {
    strcpy(p->info,"DOTCOMA");
  }
  else if(strcmp(str, ":=")==0)
  {
    strcpy(p->info,"ATRIB");
  }
  else if((str[0]>96 && str[0]<123)  ||  (str[0]>64 && str[0]<91)) // verifica se o caracter inicial do vetor é uma letra maiuscula ou minuscula
  {
    int flag=0;
    for(i=0; i<strlen(str); i++)
    {
      if((str[i]>32 &&str[i]<48) || (str[i]>57 &&str[i]<65) || (str[i]>90 &&str[i]<97) || (str[i]>122 &&str[i]<127)  )
      {
        flag =1;   // quando encontrado algum caracter especial aciona a flag para retornar que o identificador é invalido
      }
    }

    if(flag == 1)
    {
      printf("ERRO LINHA %d: Identificador invalido!\n", p->linha); // retorna o erro
      *erro = 1;
    }
    else
    {
        strcpy(p->info, "ID");
    }

  }
  else if((str[i]>47 && str[i]<58)) // verifica se o caracter inicial do vetor é um numero
  {

      int flag = 0;
      for(i=0; i<strlen(str); i++)
      {
        if(str[i]<48 || str[i]>57)
        {
          flag =1; // quando encontrado algum caracter apos um numero aciona a flag para retornar que o numero é invalido
        }
      }
      if(flag == 1 )
      {
        printf("ERRO LINHA %d: Numero invalido!\n", p->linha);
        *erro = 1;
      }
      else
      {
        strcpy(p->info, "NUM");
      }

  }
  else if(str[0]>122 &&str[0]<127) // tratamento da chave do comentario
  {
     printf("ERRO LINHA %d: Identificador invalido!\n", p->linha); // retorna o erro
     *erro = 1;
  }
  return *p;
}

void empilha(Lista *L,  char car[])
{
    no *novo;
    novo = malloc(sizeof(no));
    strcpy(novo->info, car);

    if(L->inicio == NULL)
    {
        L->inicio = novo;
        L->fim = novo;
        novo->down = NULL;
        novo->prox = NULL;
    }
    else
    {
        novo->prox = NULL;
        novo->down = L->inicio;
        L->inicio = novo;
    }
}

void desempilha(Lista*L)
{
  no *aux;
  aux = L->inicio;
  L->inicio = aux->down;
  aux->down = NULL;
  free(aux);
}

void mostrapilha(Lista *pilha)
{
  no *p;
  if (pilha->inicio==NULL) // verificacao se a lista ta vazia
  {
      printf("Lista vazia\n");
  }
  p = pilha->inicio;
  printf("***************PILHA***************\n"   );
  while(p!=NULL)
  {

      printf("<%s,%d>\n",p->info,p->linha);
      p = p->down;

  }

}

int tabela(Lista *entrada, Lista *pilha)
{
  /* inicia analise (Top-down)*/
  empilha(pilha, "$");
  empilha(pilha, "S");
  mostrapilha(pilha);
  no *topo;
  no *lista;
  lista = entrada->inicio;


  while(pilha->inicio->info[0] != '$')
  {
    topo = pilha->inicio;
    if(strcmp(topo->info,lista->info) == 0)// cabaça da pilha = terminal da fita
    {
      desempilha(pilha);
      lista = lista->prox;
      printf("Fita : %s\n",lista->info ); // imprimi o proximo da fita
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"S")==0 && (strcmp(lista->info, "IF")==0 || strcmp(lista->info, "ELSE")==0 || strcmp(lista->info, "REPEAT")==0 || strcmp(lista->info, "READ")==0 || strcmp(lista->info, "ID")==0
    || strcmp(lista->info, "WRITE")==0)) // tratamendo modo panico feito para todas situações
    {
      desempilha(pilha); // desempilha variavel na cabeça da fita
      empilha(pilha,"A"); // empilha produçao que condiz com a tabela
      // empilha(pilha,"C");
      mostrapilha(pilha); // mostra a situaçao atual da pilha
    }
    else if(strcmp(topo->info,"A")==0 && (strcmp(lista->info, "IF")==0 || strcmp(lista->info, "ELSE")==0 || strcmp(lista->info, "REPEAT")==0 || strcmp(lista->info, "READ")==0 || strcmp(lista->info, "ID")==0
    || strcmp(lista->info, "WRITE")==0))
    {
      desempilha(pilha);
      empilha(pilha,"A'");
      empilha(pilha,"B");
      // empilha(pilha,"C");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"A'")==0 && (strcmp(lista->info, "$")==0 || strcmp(lista->info, "ELSE")==0 ||strcmp(lista->info, "UNTIL")==0) )
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"A'")==0 && strcmp(lista->info, "DOTCOMA")==0)
    {
      desempilha(pilha);
      empilha(pilha,"A'");
      empilha(pilha,"B");
      empilha(pilha,"DOTCOMA");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"B")==0 && strcmp(lista->info, "IF")==0)
    {
      desempilha(pilha);
      empilha(pilha,"C");
      // empilha(pilha,"B");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"B")==0 && strcmp(lista->info, "REPEAT")==0)
    {
      desempilha(pilha);
      empilha(pilha,"D");
      // empilha(pilha,"B");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"B")==0 && strcmp(lista->info, "ID")==0)
    {
      desempilha(pilha);
      empilha(pilha,"E");
      // empilha(pilha,"B");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"B")==0 && strcmp(lista->info, "READ")==0)
    {
      desempilha(pilha);
      empilha(pilha,"F");
      // empilha(pilha,"B");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"B")==0 && strcmp(lista->info, "WRITE")==0)
    {
      desempilha(pilha);
      empilha(pilha,"G");
      // empilha(pilha,"B");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"B")==0 && strcmp(lista->info, "DOTCOMA")==0)
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"C")==0 && strcmp(lista->info, "IF")==0)
    {
      desempilha(pilha);
      empilha(pilha,"C'");
      empilha(pilha,"A");
      empilha(pilha,"THEN");
      empilha(pilha,"H");
      empilha(pilha,"IF");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"C")==0 && strcmp(lista->info, "DOTCOMA")==0)
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"C'")==0 && (strcmp(lista->info, "DOTCOMA")==0 ||strcmp(lista->info, "$")==0 ))
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"C'")==0 && (strcmp(lista->info, "ELSE")==0 ))
    {
      desempilha(pilha);
      // empilha(pilha,"END");
      empilha(pilha,"A");
      empilha(pilha,"ELSE");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"D")==0 && strcmp(lista->info, "REPEAT")==0)
    {
      desempilha(pilha);
      empilha(pilha,"H");
      empilha(pilha,"UNTIL");
      empilha(pilha,"A");
      empilha(pilha,"REPEAT");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"D")==0 && (strcmp(lista->info, "DOTCOMA")==0))
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"E")==0 && strcmp(lista->info, "ID")==0)
    {
      desempilha(pilha);
      empilha(pilha,"H");
      empilha(pilha,"ATRIB");
      empilha(pilha,"ID");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"E")==0 && (strcmp(lista->info, "DOTCOMA")==0))
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"F")==0 && strcmp(lista->info, "READ")==0)
    {
      desempilha(pilha);
      empilha(pilha,"ID");
      empilha(pilha,"READ");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"F")==0 && (strcmp(lista->info, "DOTCOMA")==0))
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"G")==0 && strcmp(lista->info, "WRITE")==0)
    {
      desempilha(pilha);
      empilha(pilha,"H");
      empilha(pilha,"WRITE");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"G")==0 && (strcmp(lista->info, "DOTCOMA")==0))
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"H")==0 && (strcmp(lista->info, "LBRACKET")==0 || strcmp(lista->info, "NUM")==0 || strcmp(lista->info, "ID")==0) )
    {
      desempilha(pilha);
      empilha(pilha,"H'");
      empilha(pilha,"J");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"H")==0 && (strcmp(lista->info, "RBRACKET")==0 || strcmp(lista->info, "THEN")==0 || strcmp(lista->info, "DOTCOMA")==0) )
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"H'")==0 && (strcmp(lista->info, "UNTIL")==0 ||strcmp(lista->info, "THEN")==0 || strcmp(lista->info, "DOTCOMA")==0
    || strcmp(lista->info, "$")==0|| strcmp(lista->info, "ELSE")==0))
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"H'")==0 && (strcmp(lista->info, "LESS")==0 || strcmp(lista->info, "EQUAL")==0) )
    {
      desempilha(pilha);
      empilha(pilha,"J");
      empilha(pilha,"I");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"I")==0 &&  strcmp(lista->info, "EQUAL")==0 )
    {
      desempilha(pilha);
      empilha(pilha,"EQUAL");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"I")==0 &&  strcmp(lista->info, "LESS")==0 )
    {
      desempilha(pilha);
      empilha(pilha,"LESS");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"I")==0 && (strcmp(lista->info, "LBRACKET")==0 || strcmp(lista->info, "NUM")==0 || strcmp(lista->info, "ID")==0) )
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"J")==0 && (strcmp(lista->info,"LBRACKET")==0 || strcmp(lista->info,"NUM")==0 || strcmp(lista->info,"ID")==0) )
    {
      desempilha(pilha);
      empilha(pilha,"J'");
      empilha(pilha,"L");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"J")==0 && (strcmp(lista->info, "LESS")==0 || strcmp(lista->info, "EQUAL")==0 || strcmp(lista->info, "RBRACKET")==0 || strcmp(lista->info, "THEN")==0 || strcmp(lista->info, "DOTCOMA")==0))
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"J'")==0 && (strcmp(lista->info, "PLUS")==0 || strcmp(lista->info, "MINUS")==0) )
    {
      desempilha(pilha);
      empilha(pilha,"J'");
      empilha(pilha,"L");
      empilha(pilha,"K");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"J'")==0 && (strcmp(lista->info, "UNTIL")==0 ||strcmp(lista->info, "THEN")==0 || strcmp(lista->info, "LESS")==0 || strcmp(lista->info, "DOTCOMA")==0
    || strcmp(lista->info, "$")==0 || strcmp(lista->info, "EQUAL")==0 ||  strcmp(lista->info, "ELSE")==0 ))
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"K")==0 &&  strcmp(lista->info, "PLUS")==0 )
    {
      desempilha(pilha);
      empilha(pilha,"PLUS");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"K")==0 &&  strcmp(lista->info, "MINUS")==0 )
    {
      desempilha(pilha);
      empilha(pilha,"MINUS");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"L")==0 && (strcmp(lista->info, "LBRACKET")==0 || strcmp(lista->info, "NUM")==0 || strcmp(lista->info, "ID")==0) )
    {
      desempilha(pilha);
      empilha(pilha,"L'");
      empilha(pilha,"N");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"L")==0 && (strcmp(lista->info, "PLUS")==0|| strcmp(lista->info, "MINUS")==0) )
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"L'")==0 &&  (strcmp(lista->info, "DIV")==0 || strcmp(lista->info, "TIMES")==0))
    {
      desempilha(pilha);
      empilha(pilha,"L'");
      empilha(pilha,"N");
      empilha(pilha,"M");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"L'")==0 && (strcmp(lista->info, "UNTIL")==0 ||strcmp(lista->info, "THEN")==0 || strcmp(lista->info, "LESS")==0 || strcmp(lista->info, "DOTCOMA")==0||strcmp(lista->info, "PLUS")==0
    || strcmp(lista->info, "MINUS")==0 || strcmp(lista->info, "$")==0 || strcmp(lista->info, "EQUAL")==0 || strcmp(lista->info, "ELSE")==0))
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"M")==0 &&  strcmp(lista->info, "TIMES")==0 )
    {
      desempilha(pilha);
      empilha(pilha,"TIMES");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"M")==0 &&  strcmp(lista->info, "DIV")==0 )
    {
      desempilha(pilha);
      empilha(pilha,"DIV");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"M")==0 && (strcmp(lista->info, "LBRACKET")==0 || strcmp(lista->info, "NUM")==0 || strcmp(lista->info, "ID")==0) )
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"N")==0 && strcmp(lista->info, "LBRACKET")==0  )
    {
      desempilha(pilha);
      empilha(pilha,"LBRACKET");
      empilha(pilha,"H");
      empilha(pilha,"RBRACKET");

      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"N")==0 && strcmp(lista->info, "NUM")==0  )
    {
      desempilha(pilha);
      empilha(pilha,"NUM");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"N")==0 && strcmp(lista->info, "ID")==0  )
    {
      desempilha(pilha);
      empilha(pilha,"ID");
      mostrapilha(pilha);
    }
    else if(strcmp(topo->info,"N")==0 && (strcmp(lista->info, "DIV")==0|| strcmp(lista->info, "TIMES")==0 ))
    {
      desempilha(pilha);
      mostrapilha(pilha);
    }
    else // caso espaço vazio da tabela ou terminal da cabaça da pilha diferente da entrada da fita , retorna erro
    {
      return 1;
    }

  }
  return 0; // entrada aceita
}
