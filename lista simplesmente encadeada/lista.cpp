#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

Lista *lst = lista_cria(); /*Lista declarada como global
para percorrer funções sem precisar utilizar parâmetros*/

void cadastrar();
void cadastro_automatico();
void excluir();
void buscar();
void total();
void soma();
void impar();
void par();
void proximo();
void esvazia();

void menu(){
	system ("cls");
	printf("-------- Lista Simplesmente Encadeada --------");
	lista_exibe(lst);
	printf("1.  Cadastrar Números\n");
	printf("2.  Cadastro Automático\n");
	printf("3.  Excluir Números\n");
	printf("4.  Procura Número\n");
	printf("5.  Total de Números\n");
	printf("6.  Soma elementos\n");
	printf("7.  Mostra ímpares\n");
	printf("8.  Mostra pares\n");
	printf("9.  Próximo elemento da lista\n");
	printf("10. Zerar Lista\n");
	printf("11. Sair do Programa\n\n");
	printf("Escolha uma opção: ");
}

int main (){
	int opcao=0;
	setlocale(LC_ALL,"");
	menu();
	
	do scanf("%d", &opcao);
	while(opcao==0 || opcao > 10);
	
	system("cls");
	switch(opcao){	
		case 1:
			cadastrar();
		break;
		
		case 2:
			cadastro_automatico();
		break;
			
		case 3:
			excluir();
		break;
			
		case 4:
			buscar();
		break;
			
		case 5:
			total();
		break;
			
		case 6:
			soma();
		break;
		
		case 7:
			impar();
		break;
		
		case 8:
			par();
		break;
		
		case 9:
			proximo();
		break;
		
		case 10:
			esvazia();
		break;
		
		case 11:
			exit(1);
	}
}

void cadastrar(){
	int num; char repetir;	
	system ("cls");
	
	printf("*** Cadastro de Numeros ***");	
	lista_exibe(lst);	
	printf("Insira um número: ");	
	scanf("%d", &num);
			
	if(lista_busca(lst, num) == NULL)
		lst=lista_insere(lst,num);
	else
		printf("\nNão é possível inserir um numero repetido!\n");
		
	lista_exibe(lst);
	
	printf("\nDeseja inserir outro número? [s]Sim [n]Não:  ");	
	do scanf("%c", &repetir);
	while((repetir != 's')  && (repetir != 'n'));	
	
	if(repetir == 's')
		cadastrar();
	else if (repetir == 'n')
		main();
}

void cadastro_automatico(){
	int inicio, fim; char repetir;	
	system ("cls");
	
	printf("*** Cadastro Automático de Numeros ***");
	printf("\nInserção de vários números na lista"); 
	lista_exibe(lst);	
	
	if(lista_vazia(lst) != NULL){
		printf("Insira um número para ser o inicio:  ");	
		scanf("%d", &inicio);
		
		printf("Insira um número para ser o final(deve ser maior que o início):  ");
		do scanf("%d", &fim);
		while (fim <= inicio);	
			
		for (int i=inicio; i<=fim; i++)
			lst = lista_insere(lst, i);

		lista_exibe(lst);
	} else {
		printf("A lista deve estar vazia para inserir automaticamente\n\n");
	}
	system("pause"); main();
}

void excluir(){
	int num; char repetir;	
	system ("cls");
	
	printf("*** Exclusão de Números ***");
	lista_exibe(lst);	
	
	printf("Exclua um número:  ");	
	scanf("%d", &num);	
	
	if(lista_busca(lst, num) == NULL)
		printf("\nNão é possível remover um número que não está na lista!\n");
	else
		lst=lista_retira(lst,num);		
		
	lista_exibe(lst);
	
	printf("\nDeseja excluir outro número? [s]Sim [n]Não:  ");
	do scanf("%c", &repetir);
	while((repetir != 's')  && (repetir != 'n'));
	
	if(repetir == 's')
		excluir();
	else if (repetir == 'n')
		main();
}

void buscar(){
	int num; char repetir;	
	system ("cls");
	
	printf("*** Busca de Números ***\n\n");
	lista_exibe(lst);
	printf("Busque um número:  ");	
	scanf("%d", &num);	
	
	if(lista_busca(lst, num) == NULL)
		printf("\nNão foi achado o número!\n");
	else
		printf("\nO numero %d está na lista!\n");	
		
	printf("\nDeseja buscar outro número? [s]Sim [n]Não:  ");
	do scanf("%c", &repetir);
	while((repetir != 's')  && (repetir != 'n'));
		
	if(repetir == 's')
		buscar();
	else if (repetir == 'n')
		main();
}

void total(){
	system ("cls");
	total_numeros(lst);	
	system("pause"); main();
}

void soma(){
	system ("cls");
	soma_numeros(lst);
	system("pause"); main();
}

void impar(){
	system ("cls");
	lista_impares(lst);
	system("pause"); main();
}

void par(){
	system ("cls");
	lista_pares(lst);
	system("pause"); main();
}

void proximo(){
	int num; char repetir;	
	system ("cls");
	
	printf("*** Próximo ***\n\n");
	printf("Cada elemento de uma Lista simplesmente encadeada tem um ponteiro para\n");
	printf("o seu próximo. Busque um número da lista para saber o seu próximo!");
	lista_exibe(lst);
	
	if(lst != NULL){
		printf("Insira um número:  ");	
		scanf("%d", &num);
			
		if(lista_busca(lst, num) == NULL)
			printf("\nNão foi achado o número!\n");
		else
			lista_proximo(lst, num);	
		
		printf("\nDeseja buscar outro número? [s]Sim [n]Não:  ");
		do scanf("%c", &repetir);
		while((repetir != 's')  && (repetir != 'n'));
			
		if(repetir == 's')
			proximo();
		else if (repetir == 'n')
			main();
	} else {
		printf("Não é possível encontrar os vizinhos porque a lista está vazia\n\n");
		system("pause"); main();
	}
}

void esvazia(){
	system ("cls");
	lista_esvazia(lst);//retira elementos da lista
	lst = lista_cria();//cria lista novamente
	system("pause"); main();
}
