#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// ordenacao vetor
void swap(int v[], int i, int fim) {
	int aux = v[i];
	v[i]    = v[fim];
	v[fim]  = aux;
}

int partition(int v[], int inicio, int fim, int *c) {
	int pivo = v[fim];	   // pivo eh o ultimo elemento da particao
	int i    = inicio - 1; // indica a posicao correta do pivo ate entao
	int j 	 = 0;
	(*c)++;
	
	for (j = inicio; j <= fim - 1; j++) {
		if (v[j] < pivo) { // verifica se o elemento atual eh menor que o pivo
			i++;
			
			swap(v, i, j); // realiza a troca do elemento atual
			(*c)++;
		}
	}
	
	swap(v, i + 1, fim); // posiciona o pivo na posicao correta
	
	(*c)++;
	return i + 1; // informa o indice a ser utilizado para o proximo particionamento
}

void _quicksort(int v[], int inicio, int fim, int *c) {
	(*c)++;
		
 	if (inicio < fim) {
 		int meio = partition(v, inicio, fim, c);
 		
 		_quicksort(v, inicio, meio - 1, c); // antes do pivo
 		_quicksort(v, meio + 1, fim, c);    // depois do pivo
 	}
}

void quicksort(int v[], int n) {
	int c = 0;
	
 	_quicksort(v, 0, n - 1, &c);
}


// pesquisa vetor
int pesquisaInterpolacao(int chave, int v[], int n, int* c) {
 	int ini = 0, meio;
	int fim = n - 1;
 	*c = 1;
 
  	(*c) += 3;
 	while (ini <= fim && chave >= v[ini] && chave <= v[fim]) {
  		if (ini == fim) {
  			(*c)++;
			return v[ini] == chave ? ini : -1;
		}
		
 		meio = ini + (((double) (fim - ini) / (v[fim] - v[ini])) * (chave - v[ini]));
 		
 		 (*c)++;
		if (chave == v[meio]) {
 			return meio;
 			
		} else if (chave < v[meio]) {
 			fim = meio - 1;

		} else {
			ini = meio + 1;
 		}
 		
 		(*c) += 4;
 	}
 		
 	return -1; // indice invalido
}


int main(const int arvc, const char* argv) {
	int i, j, k = 0, len;
	
	printf("Por favor, informe o tamanho do vetor: ");
	scanf("%d", &len);
	int v[len];

	for (i = 0; i < len; i++) {
		v[i] = rand() % len;
	}
	
	quicksort(v, len);

	for (i = 0; i < len; i++) {
		printf("%d, ", v[i]);
	}

	printf("\n\nPor favor, informe o valor a ser pesquisado: ");
	scanf("%d", &j);

	printf("Indice: %d", pesquisaInterpolacao(j, v, len, &k));

	printf("\nO esforco computacional realizado eh de: %d", k);

	return 0;
}
