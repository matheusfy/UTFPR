#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}

void merge_sort (int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}

int main(void){
	int *vetor;
	int cont, ch;
	clock_t Ti, Tf;
	float DeltaT;

	srand((unsigned)time(NULL));
	 vetor=malloc(sizeof(int) * MAX);

	for(cont=0;cont<MAX;cont++){
		ch=rand()%1000000;
		vetor[cont]=ch;
	}


	for(cont=0;cont<MAX-1;cont++){
		printf("%d ",vetor[cont]);
	}
	printf("\n");
	Ti=clock();
	merge_sort(vetor,MAX-1);
	Tf=clock();
	for(cont=0;cont<MAX-1;cont++){
		printf("%d \n ",vetor[cont]);
	}
	DeltaT=Tf-Ti;
	DeltaT=DeltaT/1000;
	printf("\ncom tempo de %f",DeltaT);
	free(vetor);
	return 0;
}
