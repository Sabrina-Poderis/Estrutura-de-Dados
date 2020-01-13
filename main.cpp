#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listadupla.h"

void cadastrar();
void cadastro_automatico();
void excluir();
void exibe();
void exibe_reverso();
void buscar();
void total();
void media();
void maior_menor();
void vizinhos();
void esvazia();

Lista2 *lst = lista_cria(); /*Lista declarada como global
para percorrer funções sem precisar utilizar parâmetros*/

void menu(){
	system ("cls");
	int opcao=0;
	printf("-------- CRUD de Números --------");
	lista_exibe(lst);
	printf("1.  Cadastrar Números\n");
	printf("2.  Cadastro Automático\n");
	printf("3.  Excluir Números\n");
	printf("4.  Exibir Números\n");
	printf("5.  Exibir Números Inversamente\n");
	printf("6.  Procura Número\n");
	printf("7.  Total de Números\n");
	printf("8.  Média de Números\n");
	printf("9.  Maior e Menor Números\n");
	printf("10. Vizinhos\n");
	printf("11. Zerar Lista\n");
	printf("12. Sair do Programa\n\n");
	printf("Escolha uma opção: ");
	
	do scanf("%d", &opcao);
	while(opcao==0 || opcao > 12);
	
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
			exibe();
		break;
			
		case 5:
			exibe_reverso();
		break;
			
		case 6:
			buscar();
		break;
		
		case 7:
			total();
		break;
		
		case 8:
			media();
		break;
		
		case 9:
			maior_menor();
		break;
		
		case 10:
			vizinhos();
		break;
						
		case 11:
			esvazia();
		break;
		
		case 12:
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
		menu();
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
		system("pause"); menu();
	} else {
		printf("A lista deve estar vazia para inserir automaticamente\n\n");
		system("pause"); menu();
	}
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
		menu();
}

void exibe(){
	system ("cls");
	lista_exibe(lst);
	system("pause"); menu();
}

void exibe_reverso(){
	system ("cls");
	lista_exibe_reverso(lst);
	system("pause"); menu();
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
		menu();
}

void total(){
	system ("cls");
	printf("*** Total de Números ***\n\n");
	
	if(lst != NULL)
		printf("O Total de números é: %d\n\n", total_numeros(lst));
	else
		printf("Não é possível obter o total porque a lista está vazia\n\n");
	
	system("pause"); menu();
}

void media(){
	system ("cls");
	printf("*** Média de Números ***\n\n");
	
	if(lst != NULL)
		printf("A Média dos números é: %.2f\n\n", media_numeros(lst));
	else
		printf("Não é possível obter a média porque a lista está vazia\n\n");
	
	system("pause"); menu();
}

void maior_menor(){
	system ("cls");
	printf("*** Maior e Menor Números ***\n\n");
	
	if(lst != NULL)
		printf("O Maior Número é: %d\nO Menor Número é: %d\n\n", maior_numero(lst), menor_numero(lst));
	else
		printf("Não é possível obter o maior e menor número porque a lista está vazia\n\n");
	
	system("pause"); menu();
}

void vizinhos(){
	int num; char repetir;	
	system ("cls");
	
	printf("*** Vizinhos ***\n\n");
	printf("Cada elemento de uma Lista Duplamente encadeada tem um ponteiro tanto\n");
	printf("para o seu próximo como para o seu anterior. Busque um número da lista\n"); 
	printf("para saber o seu próximo e o seu anterior!");
	lista_exibe(lst);
	
	if(lst != NULL){
		printf("Insira um número:  ");	
		scanf("%d", &num);
			
		if(lista_busca(lst, num) == NULL)
			printf("\nNão foi achado o número!\n");
		else
			vizinhos(lst, num);	
		
		printf("\nDeseja buscar outro número? [s]Sim [n]Não:  ");
		do scanf("%c", &repetir);
		while((repetir != 's')  && (repetir != 'n'));
			
		if(repetir == 's')
			vizinhos();
		else if (repetir == 'n')
			menu();
	} else {
		printf("Não é possível encontrar os vizinhos porque a lista está vazia\n\n");
	}
}

void esvazia(){
	system ("cls");
	lista_esvazia(lst);//retira elementos da lista
	lst = lista_cria();//cria lista novamente
	printf("Lista zerada!\n\n");
	system("pause"); menu();
}

int main (){
	setlocale(LC_ALL,"");
	menu();	
}
