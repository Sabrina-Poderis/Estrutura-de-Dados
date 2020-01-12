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
para percorrer fun��es sem precisar utilizar par�metros*/

void menu(){
	int opcao=0;
	printf("CRUD de N�meros\n\n");
	printf("1. Cadastrar N�meros\n");
	printf("2. Excluir N�meros\n");
	printf("3. Exibir N�meros\n");
	printf("4. Procura N�mero\n");
	printf("5. Zerar Lista\n");
	printf("6. Sair do Programa\n\n");
	printf("Escolha uma op��o: ");
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
	
	printf("Insira um n�mero\n\n");	
	scanf("%d", &num);
	
	if(lista_busca(lst, num) == NULL){
		lst=lista_insere(lst,num);
	}else{
		printf("\nN�o � poss�vel inserir um numero repetido!\n");
	}
	
	printf("\nDeseja inserir outro n�mero? [s]Sim [n]N�o ");
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
	
	printf("*** Exclus�o de N�meros ***");
	lista_exibe(lst);
	
	printf("Exclua um n�mero\n\n");	
	scanf("%d", &num);
	
	if(lista_busca(lst, num) == NULL){
		printf("\nN�o � poss�vel remover um n�mero que n�o est� na lista!\n");
	}else{
		lst=lista_retira(lst,num);
	}
		
	printf("\nDeseja excluir outro n�mero? [s]Sim [n]N�o ");
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
	
	printf("*** Busca de N�meros ***\n\n");
	printf("Busque um n�mero\n\n");	
	scanf("%d", &num);
	
	if(lista_busca(lst, num) == NULL){
		printf("\nN�o foi achado o n�mero!\n");
	}else{
		printf("\nO numero %d est� na lista!\n");
	}
	
	printf("\nDeseja buscar outro n�mero? [s]Sim [n]N�o ");
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
