#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct no {
int info;
struct no* proximo;
}No;

No* inicia() {
return NULL;
}

No* insere(No* lista, int num) { 
	No* novo_no;
	int tamanho=sizeof(No);
	novo_no = (No*) malloc(tamanho); 
	novo_no->info = num;
	novo_no->proximo = lista;
	return novo_no;
}

No* retira(No* lista, int num) {
	No* anterior = NULL; /* ponteiro para o no anterior */
	No* aux = lista; /* ponteiro auxiliar para percorrer
	lista */
	/* procura o no na lista, guardando o no anterior */
	while (aux != NULL && aux->info != num) {
		anterior = aux;
		aux = aux->proximo;
	}
	/* Verifica se achou o no */
	if (aux == NULL) {
		return lista; /* nao achou, retorna lista original */
	}
	/* achou, retira o no da lista */
	if (anterior == NULL) {
		lista = aux->proximo; /* retira no do inicio da lista */
	}
	else {
		anterior->proximo = aux->proximo; /* retira no do meio da lista */
	}
	free(aux); /* libera espaco na memoria usado para alocar a variavel */
	return lista;
}

No* busca(No* lista, int num) {
	No* aux; /* variavel auxiliar para percorrer a lista */
	for (aux = lista; aux != NULL; aux = aux->proximo) {
		if (aux->info == num)
			return aux;
		}	
	return NULL;
}

void imprime(No* lista) {
	No* aux; /* variavel auxiliar para percorrer a lista */
	for (aux = lista; aux != NULL; aux = aux->proximo)
		printf("\n Número: %d\n", aux->info);
}

int main(int argc, char *argv[]) {
	//setlocale(LC_ALL, "");
	
	printf("Listas Ligadas \n\n");
	
	No* lista;
	lista=inicia();
	lista=insere(lista, 23);
	lista=insere(lista, 56);
	lista=insere(lista, 45);
	lista=insere(lista, 90);
	
	printf("\n %x \n", &lista);
	imprime(lista);
	
	lista=retira(lista, 45);
	printf("Após remoção do 45 \n\n");
	imprime(lista);
	
	return 0;
}