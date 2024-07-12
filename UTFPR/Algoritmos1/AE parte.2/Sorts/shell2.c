#include <stdio.h>
#include <stdlib.h>

struct TipoItem {
  int Chave;
};

const n = 10;
typedef TipoItem TipoVetor[n + 1];

void ShellSort(TipoVetor A);

void main() {
  TipoVetor A, Original;
  int x, i;
// entrada: gerar nros aleatórios para armazenar no vetor
  randomize();
  for (i=1; i<=n; i++) {
    x = random(100);
    A[i].Chave = x;		// vetor a ser ordenado
    Original[i].Chave = x; 	// ordem original nros armazenados no vetor
  }

  ShellSort(A);

// saída: imprime os resultados
  printf(" i- Vetor Original       Vetor Ordenado\n");
  for (i=1; i<=n; i++)
    printf("%2d- %8d %20d\n", i, Original[i], A[i]);
}

// processamento: classificação por inserção (ShellSort)
void ShellSort(TipoVetor A) {
  int i, j, h;
  TipoItem x;
  h = 1;
  do {
    h = 3 * h + 1;
  } while (h <= n);

  do {
    h = h / 3;
    for (i=(h+1); i<=n; i++) {
      x = A[i];
      j = i;
      while ((j > h) && (A[j-h].Chave > x.Chave)) {
        A[j] = A[j-h];
        j = j - h;
      }
      A[j] = x;
    }
  } while (h != 1);
}
