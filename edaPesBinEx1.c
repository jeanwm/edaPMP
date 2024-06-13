#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int pesquisaBinaria(int chave, int v[], int n, int* c) {
 	int inicio = 0, meio, fim;
 	fim = n - 1;
 	*c  = 1;
 	
	while (inicio <= fim) {
 		meio = (inicio + fim) / 2;
 		
		(*c)++;
		if (chave == v[meio]) {
 			return meio;
 			
 		} else if (chave < v[meio]) {
 			fim = meio - 1;
 			
 		} else {
 			inicio = meio + 1;
 		}
 		
 		(*c) += 2;
 	}
 	 
	return -1; // indice invalido
}

int main(const int arvc, const char* argv) {
	int i, j, k = 0, len;
	
	scanf("%d", &len);
	int v[len];

	for (i = 0; i < len; i++) {
		v[i] = i + 1;
	}

	for (i = 0; i < len; i++) {
		printf("%d, ", v[i]);
	}

	printf("\n\nPor favor, informe o valor a ser pesquisado: ");
	scanf("%d", &j);

	printf("%d", pesquisaBinaria(j, v, len, &k));

	printf("\nO esforco computacional realizado eh de: %d", k);

	return 0;
}
