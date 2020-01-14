#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listadupla.h"

Lista2 *lst = lista_cria(); /*Lista declarada como global
para percorrer fun��es sem precisar utilizar par�metros*/

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

void menu(){
	system ("cls");
	printf("-------- Lista Duplamente Encadeada --------");
	lista_exibe(lst);
	printf("1.  Cadastrar N�meros\n");
	printf("2.  Cadastro Autom�tico\n");
	printf("3.  Excluir N�meros\n");
	printf("4.  Exibir N�meros\n");
	printf("5.  Exibir N�meros Inversamente\n");
	printf("6.  Procura N�mero\n");
	printf("7.  Total de N�meros\n");
	printf("8.  M�dia de N�meros\n");
	printf("9.  Maior e Menor N�meros\n");
	printf("10. Vizinhos\n");
	printf("11. Zerar Lista\n");
	printf("12. Sair do Programa\n\n");
	printf("Escolha uma op��o: ");
}

int main (){
	int opcao=0;
	setlocale(LC_ALL,"");
	menu();
	
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

void exibe(){
	system ("cls");
	lista_exibe(lst);
	system("pause"); main();
}

void exibe_reverso(){
	system ("cls");
	lista_exibe_reverso(lst);
	system("pause"); main();
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

void media(){
	system ("cls");	
	media_numeros(lst);	
	system("pause"); main();
}

void maior_menor(){
	system ("cls");
	printf("*** Maior e Menor N�meros ***\n\n");
	
	if(lst != NULL)
		printf("O Maior N�mero �: %d\nO Menor N�mero �: %d\n\n", maior_numero(lst), menor_numero(lst));
	else
		printf("N�o � poss�vel obter o maior e menor n�mero porque a lista est� vazia\n\n");
	
	system("pause"); main();
}

void vizinhos(){
	int num; char repetir;	
	system ("cls");
	
	printf("*** Vizinhos ***\n\n");
	printf("Cada elemento de uma Lista Duplamente encadeada tem um ponteiro tanto\n");
	printf("para o seu pr�ximo como para o seu anterior. Busque um n�mero da lista\n"); 
	printf("para saber o seu pr�ximo e o seu anterior!");
	lista_exibe(lst);
	
	if(lst != NULL){
		printf("Insira um n�mero:  ");	
		scanf("%d", &num);
			
		if(lista_busca(lst, num) == NULL)
			printf("\nN�o foi achado o n�mero!\n");
		else
			lista_vizinhos(lst, num);	
		
		printf("\nDeseja buscar outro n�mero? [s]Sim [n]N�o:  ");
		do scanf("%c", &repetir);
		while((repetir != 's')  && (repetir != 'n'));
			
		if(repetir == 's')
			vizinhos();
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
