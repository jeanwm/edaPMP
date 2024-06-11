#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int pesquisaSequencial(int chave, int v[], int n, int* c) {
 	int i;

	for (i = 0; i < n; i++) {	
		(*c) += 2; // operacao for + if
 		if (v[i] == chave) {	
 			return i;
 		}
 	}
 	
 	return -1;
}

int main(const int arvc, const char* argv) {
	int v[10];
	int i, j, k = 0;
	
	for (i = 0; i < 10; i++) {
		v[i] = rand() % 10;
	}

	for (i = 0; i < 10; i++) {
		printf("%d, ", v[i]);
	}

	printf("\n\nPor favor, informe o valor a ser pesquisado: ");
	scanf("%d", &j);

	printf("%d", pesquisaSequencial(j, v, 10, &k));
	
	printf("\nO esforco computacional realizado eh de: %d", k);

	return 0;
}
