#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int pesquisaSequencial(int chave, int v[], int n, int* c) {
 	int i = 0;

	v[n] = chave;
	
	(*c)++;
	while (v[i] != chave) {
		(*c)++;
		i++;
	} 
	
	(*c)++;	
	if (i < n) {
		return i;
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
