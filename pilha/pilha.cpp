#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"

Pilha *pi=pilha_cria();/*Pilha declarada como global
para percorrer funções sem precisar utilizar parâmetros*/

void empilhar();
void empilhar_automatico();
void retirar();
void buscar();
void soma();
void pilha_quadrada();
void base_pilha();
void esvazia();

void menu(){
    system ("cls");
	pilha_mostra(pi);
	printf("1.  Empilhar (push)\n");
	printf("2.  Empilhar Automático\n");
	printf("3.  Retirar (pop)\n");
	printf("4.  Buscar\n");
	printf("5.  Somar Pilha\n");
	printf("6.  Pilha ao quadrado\n");
	printf("7.  Base pilha\n");
	printf("8.  Zerar Pilha\n");
	printf("9.  Sair do Programa\n\n");
	printf("Escolha uma opção: ");
}

main(){     
	int opcao=0;
	setlocale(LC_ALL,"");
	menu();
	
	do scanf("%d", &opcao);
	while(opcao==0 || opcao > 9);
	
	system("cls");
	switch(opcao){	
		case 1:
			empilhar();
		break;
		
		case 2:
			empilhar_automatico();
		break;
			
		case 3:
			retirar();
		break;
		
		case 4:
			buscar();
		break;
		
		case 5:
			soma();
		break;
		
		case 6:
			pilha_quadrada();
		break;
		
		case 7:
			base_pilha();
		break;
			
		case 8:
			esvazia();
		break;
		
		case 9:
			exit(1);
	}
}

void empilhar(){
	int num; char repetir;	
	system ("cls");
	
	printf("*** Empilhar Numeros ***");	
	pilha_mostra(pi);	
	printf("Insira um número: ");	
	scanf("%d", &num);
			
	pilha_push(pi,num);	
	pilha_mostra(pi);
	
	printf("\nDeseja inserir outro número? [s]Sim [n]Não:  ");	
	do scanf("%c", &repetir);
	while((repetir != 's')  && (repetir != 'n'));	
	
	if(repetir == 's')
		empilhar();
	else if (repetir == 'n')
		main();
}

void empilhar_automatico(){
	int inicio, fim; char repetir;	
	system ("cls");
	
	printf("*** Empilhar Automático ***");
	printf("\nInserção de vários números na pilha"); 
	pilha_mostra(pi);	
	
	if(pilha_vazia(pi) != NULL){
		printf("Insira um número para ser o começo da pilha:  ");	
		scanf("%d", &inicio);
		
		printf("Insira um número para ser o final/topo da pilha (deve ser maior que o início):  ");
		do scanf("%d", &fim);
		while (fim <= inicio);	
			
		for (int i=inicio; i<=fim; i++)
			pilha_push(pi,i);	

		pilha_mostra(pi);
	} else {
		printf("A pilha deve estar vazia para empilhar automaticamente\n\n");
	}
	system("pause"); main();
}

void retirar(){
	char repetir;	
	system ("cls");
	
	printf("*** Retirar da Pilha ***");
	pilha_mostra(pi);
	
	if(pilha_vazia(pi) != NULL){
		printf("A pilha está vazia, não é possível retirar elementos\n\n");
		system("pause"); main();
	} else {
		system("pause");
		pilha_pop(pi);
		pilha_mostra(pi);
		printf("\nDeseja excluir outro número? [s]Sim [n]Não:  ");
		do scanf("%c", &repetir);
		while((repetir != 's')  && (repetir != 'n'));
		
		if(repetir == 's')
			retirar();
		else if (repetir == 'n')
			main();
	}
}

void buscar(){
	int num; char repetir;	
	system ("cls");	
	printf("*** Buscar na Pilha ***");
	pilha_mostra(pi);
	
	if(pilha_vazia(pi) != NULL){
		printf("Não é possível buscar porque a pilha está vaiza\n\n");
		system("pause"); main();
	} else {
		printf("Busque um número:  ");	
		scanf("%d", &num);	
		if(pilha_busca(pi, num) == NULL)
			printf("\nNão foi achado o número!\n");
		else
			printf("\nO numero %d está na lista!\n", num);	
			
		printf("\nDeseja buscar outro número? [s]Sim [n]Não:  ");
		do scanf("%c", &repetir);
		while((repetir != 's')  && (repetir != 'n'));
			
		if(repetir == 's')
			buscar();
		else if (repetir == 'n')
			main();
	}
}

void soma(){
	system ("cls");
	printf("*** Soma dos Numeros da Pilha ***\n\n");
	pilha_soma(pi);
	system("pause"); main();
}

void pilha_quadrada(){
	system ("cls");
	pilha_quadrado(pi);
	system("pause"); main();
}

void base_pilha(){
	system ("cls");
	printf("*** Base da Pilha ***\n\n");
	pilha_base(pi);
	system("pause"); main();
}

void esvazia(){
	system ("cls");
	pilha_esvazia(pi);//retira elementos da pilha
	printf("Pilha zerada!\n\n");
	pi = pilha_cria();//cria pilha novamente
	system("pause"); main();
}
