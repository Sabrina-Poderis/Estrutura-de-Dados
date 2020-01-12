#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listadupla.h"

void cadastrar();
void excluir();
void exibe();
void buscar();
void libera();

Lista2 *lst = lista_cria(); /*Lista declarada como global
para percorrer funções sem precisar utilizar parâmetros*/

void menu(){
	int opcao=0;
	printf("CRUD de Números\n\n");
	printf("1. Cadastrar Números\n");
	printf("2. Excluir Números\n");
	printf("3. Exibir Números\n");
	printf("4. Procura Número\n");
	printf("5. Zerar Lista\n");
	printf("6. Sair do Programa\n\n");
	printf("Escolha uma opção: ");
	S
	do{
	 	scanf("%d", &opcao);
	} while(opcao==0 || opcao > 6);
	
	system("cls");
	switch(opcao){	
		case 1:
			cadastrar();
		break;
			
		case 2:
			excluir();
		break;
			
		case 3:
			exibe();
		break;
			
		case 4:
			buscar();
		break;
			
		case 5:
			libera();
		break;
				
		case 6:
			exit(1);
	}
}

void cadastrar(){
	int num;
	char repetir;
	
	printf("*** Cadastro de Numeros ***");	
	lista_exibe(lst);
	
	printf("Insira um número\n\n");	
	scanf("%d", &num);
	
	if(lista_busca(lst, num) == NULL){
		lst=lista_insere(lst,num);
	}else{
		printf("\nNão é possível inserir um numero repetido!\n");
	}
	
	printf("\nDeseja inserir outro número? [s]Sim [n]Não ");
	do{
	 	scanf("%c", &repetir);
	} while((repetir != 's')  && (repetir != 'n'));
	
	if(repetir == 's'){
		system("cls"); cadastrar();
	}
	else if (repetir == 'n'){
		system ("cls"); menu();
	}
}

void excluir(){
	int num;
	char repetir;
	
	printf("*** Exclusão de Números ***");
	lista_exibe(lst);
	
	printf("Exclua um número\n\n");	
	scanf("%d", &num);
	
	if(lista_busca(lst, num) == NULL){
		printf("\nNão é possível remover um número que não está na lista!\n");
	}else{
		lst=lista_retira(lst,num);
	}
		
	printf("\nDeseja excluir outro número? [s]Sim [n]Não ");
	do{
	 	scanf("%c", &repetir);
	} while((repetir != 's')  && (repetir != 'n'));
	
	if(repetir == 's'){
		system("cls"); excluir();
	}
	else if (repetir == 'n'){
		system ("cls"); menu();
	}
}

void exibe(){
	lista_exibe(lst);
	system("pause");
	system ("cls");
	menu();
}

void buscar(){
	int num;
	char repetir;
	
	printf("*** Busca de Números ***\n\n");
	printf("Busque um número\n\n");	
	scanf("%d", &num);
	
	if(lista_busca(lst, num) == NULL){
		printf("\nNão foi achado o número!\n");
	}else{
		printf("\nO numero %d está na lista!\n");
	}
	
	printf("\nDeseja buscar outro número? [s]Sim [n]Não ");
	do{
	 	scanf("%c", &repetir);
	} while((repetir != 's')  && (repetir != 'n'));
	
	if(repetir == 's'){
		system("cls"); buscar();
	}
	else if (repetir == 'n'){
		system ("cls"); menu();
	}
}

void libera(){
	lista_libera(lst);//retira elementos da lista
	lst = lista_cria();//cria lista novamente
	printf("Lista zerada!\n\n");
	system("pause");
	system ("cls");
	menu();
}

int main (){
	setlocale(LC_ALL,"");
	menu();	
}
