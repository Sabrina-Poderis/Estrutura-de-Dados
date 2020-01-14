#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

Lista *lst = lista_cria(); /*Lista declarada como global
para percorrer fun��es sem precisar utilizar par�metros*/

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
	printf("1.  Cadastrar N�meros\n");
	printf("2.  Cadastro Autom�tico\n");
	printf("3.  Excluir N�meros\n");
	printf("4.  Procura N�mero\n");
	printf("5.  Total de N�meros\n");
	printf("6.  Soma elementos\n");
	printf("7.  Mostra �mpares\n");
	printf("8.  Mostra pares\n");
	printf("9.  Pr�ximo elemento da lista\n");
	printf("10. Zerar Lista\n");
	printf("11. Sair do Programa\n\n");
	printf("Escolha uma op��o: ");
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
	printf("Insira um n�mero: ");	
	scanf("%d", &num);
			
	if(lista_busca(lst, num) == NULL)
		lst=lista_insere(lst,num);
	else
		printf("\nN�o � poss�vel inserir um numero repetido!\n");
		
	lista_exibe(lst);
	
	printf("\nDeseja inserir outro n�mero? [s]Sim [n]N�o:  ");	
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
	
	printf("*** Cadastro Autom�tico de Numeros ***");
	printf("\nInser��o de v�rios n�meros na lista"); 
	lista_exibe(lst);	
	
	if(lista_vazia(lst) != NULL){
		printf("Insira um n�mero para ser o inicio:  ");	
		scanf("%d", &inicio);
		
		printf("Insira um n�mero para ser o final(deve ser maior que o in�cio):  ");
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
	
	printf("*** Exclus�o de N�meros ***");
	lista_exibe(lst);	
	
	printf("Exclua um n�mero:  ");	
	scanf("%d", &num);	
	
	if(lista_busca(lst, num) == NULL)
		printf("\nN�o � poss�vel remover um n�mero que n�o est� na lista!\n");
	else
		lst=lista_retira(lst,num);		
		
	lista_exibe(lst);
	
	printf("\nDeseja excluir outro n�mero? [s]Sim [n]N�o:  ");
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
	
	printf("*** Busca de N�meros ***\n\n");
	lista_exibe(lst);
	printf("Busque um n�mero:  ");	
	scanf("%d", &num);	
	
	if(lista_busca(lst, num) == NULL)
		printf("\nN�o foi achado o n�mero!\n");
	else
		printf("\nO numero %d est� na lista!\n");	
		
	printf("\nDeseja buscar outro n�mero? [s]Sim [n]N�o:  ");
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
	
	printf("*** Pr�ximo ***\n\n");
	printf("Cada elemento de uma Lista simplesmente encadeada tem um ponteiro para\n");
	printf("o seu pr�ximo. Busque um n�mero da lista para saber o seu pr�ximo!");
	lista_exibe(lst);
	
	if(lst != NULL){
		printf("Insira um n�mero:  ");	
		scanf("%d", &num);
			
		if(lista_busca(lst, num) == NULL)
			printf("\nN�o foi achado o n�mero!\n");
		else
			lista_proximo(lst, num);	
		
		printf("\nDeseja buscar outro n�mero? [s]Sim [n]N�o:  ");
		do scanf("%c", &repetir);
		while((repetir != 's')  && (repetir != 'n'));
			
		if(repetir == 's')
			proximo();
		else if (repetir == 'n')
			main();
	} else {
		printf("N�o � poss�vel encontrar os vizinhos porque a lista est� vazia\n\n");
		system("pause"); main();
	}
}

void esvazia(){
	system ("cls");
	lista_esvazia(lst);//retira elementos da lista
	lst = lista_cria();//cria lista novamente
	system("pause"); main();
}
