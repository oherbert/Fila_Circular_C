#include <iostream>
#include <stdio.h>

#define MAX 5

typedef struct{
	float elementos[MAX];
	int posAtual;
	int ocupacao;
} filaCircular;

void printFila(filaCircular fila);
void addElement(filaCircular *fila, float valor);
void removeElement(filaCircular *fila);

int main(int argc, char** argv) {
	
	filaCircular fila;
	
	fila.posAtual = 0;
	fila.ocupacao = MAX;
	
	while(true){
	int selecao;
	printf("\n Digite a operacao desejada: ");
	printf("\n [0] Para Adicionar");
	printf("\n [1] Para Remover");
	printf("\n [2] Para Fechar\n");
	scanf("%d",&selecao);
	
	if(selecao == 0){
		float val;
		printf("\nDigite um numero para ser armazenado:");
		scanf("%f",&val);
		system("CLS");
		addElement(&fila,val);	
	} 
		else if (selecao == 1){
			system("CLS");
			removeElement(&fila);	
	}
		else if(selecao == 2){
			exit(0);
	}
		printFila(fila);
	}
	
	printFila(fila);
	
	return 0;
}

void printFila(filaCircular fila){
	
for(int i=0; i< MAX; i++){
		printf("Pos:%d\t", i);
}

printf("\n");

for(int i=0; i< MAX; i++){
		printf("%.2f \t", fila.elementos[i]);
}
	printf("\n\n");
}

void addElement(filaCircular *fila, float valor){
	
	int posicao = (MAX  - fila->ocupacao) + fila->posAtual;

	posicao = (posicao >= MAX)?posicao%MAX : posicao;
	
	if ( fila->ocupacao > 0){
		fila->elementos[posicao] = valor;
		printf("Valor %.2f, foi adicionado na posicao %d\n\n", fila->elementos[posicao],posicao);
		fila->ocupacao --;
	}else
		{
			printf("Fila cheia!!!!!!!\n\n");
		}
}

void removeElement(filaCircular *fila){
	
	if(fila->ocupacao < MAX){
		
		fila->elementos[fila->posAtual] = 0;
		
		if(fila->posAtual == MAX-1){
			fila->posAtual = 0;	
		}else{
			fila->posAtual++;
		}
	
		printf("Posicao %d removida com sucesso \n\n", fila->posAtual);	
		fila->ocupacao++;
	}
	
}
