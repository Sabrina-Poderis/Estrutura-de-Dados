typedef struct lista{
	int info;
	struct lista *prox;
}Lista; //definição da lista

/* inicializa uma lista*/
Lista * lista_cria(){
	return NULL;
}

/* retorna 1 se vazia ou zero se falso*/
int lista_vazia(Lista* li){     
	return (li==NULL);
}

/* insere o novo dado no início da lista , e retorna a lista atualizada*/
Lista * lista_insere(Lista *li, int dado){
	Lista *novo=(Lista*) malloc (sizeof(Lista));
	novo->info =dado;
	novo->prox=li;
	return novo;
}

/* percorre a lista do inicio até o fim mostrando os elementos*/
void lista_exibe(Lista* li){
	Lista *aux;
	printf("\n\n-------- Lista --------\n\n");
	if(lista_vazia(li)){
		printf("(Sem elementos no momento)");
	}else{
		for(aux=li;aux!=NULL;aux=aux->prox)
			printf("%d\t", aux->info);
	}
	printf("\n\n-----------------------\n\n");
}    

/* retorna o elemento ou NULL se não achou*/
Lista* lista_busca(Lista* li, int dado){    
	Lista *aux;
	for(aux=li;aux!=NULL;aux=aux->prox)
		if(aux->info == dado) return aux;
	return NULL;
}

/* retorna o elemento ou a lista original*/
Lista* lista_retira(Lista* li, int dado){
	Lista* ant=NULL; //ponteiro para o anterior
	Lista *aux=li;// ponteiro para percorrer a lista
	//procura o elemento na lista guardando seu anterior
	while(aux!=NULL && aux->info!=dado){
	    ant=aux;
	    aux=aux->prox;
	}
	//verifica se achou o elemento
	if(aux==NULL) {
		printf("\nNao localizado\n");
		return li; //não achou - retorna a lista
	}
	//retira o elemento
	if (ant==NULL) //primeiro da lista
		li=aux->prox;
	else //retira do meio/fim da lista
		ant->prox=aux->prox;
	free(aux);
	return li;
}

void lista_esvazia(Lista *li){
	Lista *p,*t;
	p=li;
	if (p == NULL){
    	printf("A lista já está vazia!\n\n");
	} else {
		while(p!=NULL){
	    	t=p->prox;
	    	free(p);//libera o item da lista
	    	p=t;
		}  	
		printf("Lista zerada!\n\n");
	}
}

/*retorna total de numeros maior que o numero informado*/
void total_numeros (Lista *li){
	Lista *aux; int tot=0;
	printf("*** Total de Números ***\n\n");
	if(li != NULL){
		for(aux=li;aux!=NULL; aux=aux->prox)
			tot++;
		printf("O Total de números é: %d\n\n", tot);
	}else{
		printf("Não é possível obter o total porque a lista está vazia\n\n");
	}
}

/*exibe a soma dos numeros*/
void soma_numeros (Lista *prox){
	Lista *aux; int soma;
	printf("*** Soma de Números ***\n\n");
	
	if(prox != NULL){
		for(aux=prox;aux!=NULL; aux=aux->prox)
			soma = soma + aux->info;
		printf("A Soma dos números é: %d\n\n", soma);
	}else{
		printf("Não é possível obter a soma porque a lista está vazia\n\n");
	}
}

/*exibe impares*/
void lista_impares(Lista* li){
	Lista *aux;
	printf("\n\n-------- Lista de Impares--------\n\n");
	if(lista_vazia(li)){
		printf("(Sem elementos no momento)");
	}else{
		for(aux=li;aux!=NULL;aux=aux->prox){
			if(aux->info % 2 == 1)
				printf("%d\t", aux->info);
		}
	}
	printf("\n\n-----------------------\n\n");
}

/*exibe pares*/
void lista_pares(Lista* li){
	Lista *aux;
	printf("\n\n-------- Lista de Pares--------\n\n");
	if(lista_vazia(li)){
		printf("(Sem elementos no momento)");
	}else{
		for(aux=li;aux!=NULL;aux=aux->prox){
			if(aux->info % 2 == 0)
				printf("%d\t", aux->info);
		}
	}
	printf("\n\n-----------------------\n\n");
}

/*proximos*/
void lista_proximo(Lista *li, int dado) {
	Lista *aux = li;
	/*if(aux==NULL){ 				 O programa principal já verifica se a lista está vazia,
		printf("Lista Vazia\n\n");  adicionar esta linha se necessário
	}else{*/
		for(aux=li;aux!=NULL;aux=aux->prox){
			if(aux->info == dado) {
				if(aux->prox != NULL)
					printf("Próximo: %d\n", aux->prox->info);
				else
					printf("Não tem próximo\n");
			}	
		}
	//}
}
