#include <iostream>
#include<stdio.h>

/* Tabela Hash */


// 1- Criar a estrutura hash
typedef struct {
	int codigo;
	char nome[50];
	float salario;
} Funcionario;

Funcionario tabelahash[100];


// 2- Fazer a funcao hash de calculo de resto da divisao chave pelo tamanho

int CalcularPosicao(int codigo){
	return codigo % 100;
}

// inicializar a tabelahash com matricula -1

void inicializar(){
	
	int i;
	for(i = 0; i < 100; i++){
		
		tabelahash[i].codigo = -1;
	}
}

// 3- Previnir a colisao



int main(int argc, char** argv) {
	
	inicializar();
	Funcionario a;
	int posicao;
	int opcao;
	do{
		printf("1- Incluir\n");
		printf("2- Mostrar\n");
		printf("3- Listar dados\n");
		printf("0 - Sair\n");
		printf("Digite uma opcao:");
		scanf("%i", &opcao);
		
		switch (opcao){
			
			case 1:
				Funcionario novo;
				printf("Digite o código: ");
				scanf("%d", &novo.codigo);
				printf("Digite o nome: ");
				scanf("%s", &novo.nome);
				printf("Digite o salário: ");
				scanf("%f", &novo.salario);
				int posicao;
				posicao = CalcularPosicao(novo.codigo);
				while (posicao != 0){
					if(tabelahash[posicao].codigo == -1){
						tabelahash[posicao] = novo;
						posicao = 0;
					}else {
						posicao++;
					}
					
				}
				posicao = CalcularPosicao(novo.codigo);
				tabelahash[posicao] = novo;
				break;
				
			case 2:
				int codigo;
				printf("Digite o código: ");
				scanf("%d", &novo.codigo);
				posicao = CalcularPosicao(codigo);
				a = tabelahash[posicao];
				printf("\nCódigo: %i Funcionário: %s\n", a.codigo, a.nome);
				break;
				
			case 3:
				int i;
				for(i = 0; i < 100; i++){	
					printf("\nCódigo: %i\n Funcionário: %s", tabelahash[i].codigo, tabelahash[i].nome);
				}
				break;
		}
		
	}while(opcao != 0);
	
	
	
	
	return 0;
}
