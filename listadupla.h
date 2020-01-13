typedef struct lista2{
	int info;
	struct lista2 *ant;
	struct lista2 *prox;
}Lista2;

/* inicializa uma lista dupla */
Lista2 * lista_cria(){
	return NULL;
}

/* retorna 1 se vazia ou zero se falso */
int lista_vazia(Lista2* li){
	return(li==NULL);
}

/* insere o novo dado no início da lista  e retorna a lista atualizada */
Lista2* lista_insere( Lista2* li, int dado){
	Lista2 *novo = (Lista2*) malloc (sizeof(Lista2));
	novo->info=dado;
	novo->prox=li;
	novo->ant=NULL;
	if(li!= NULL)
		li->ant=novo;         
	return novo;
}

/* percorre a lista do inicio até o fim mostrando os elementos */
void lista_exibe(Lista2* li) {
	Lista2 *aux;
	printf("\n\n-------- Lista --------\n\n");
	if(lista_vazia(li)){
		printf("(Sem elementos no momento)");
	}else{
		for(aux=li;aux!=NULL;aux=aux->prox)
    	printf("%d\t", aux->info);
	}
	printf("\n\n-----------------------\n\n");
}   

/* exibe lista reversa */
void lista_exibe_reverso(Lista2 *li) {
	Lista2 *aux, *aux1;
	printf("\n\n --------Lista Reversa --------\n\n");
	if(lista_vazia(li)){
		printf("(Sem elementos no momento)");
	}else{
		for(aux=li; aux->prox!=NULL; aux=aux->prox);		
		for(aux1=aux; aux1!=NULL; aux1=aux1->ant){
			printf("%d\t", aux1->info);
		}	
	}
	printf("\n\n-----------------------\n\n");
}    

/* retorna o elemento ou NULL se não achou */
Lista2* lista_busca(Lista2* li, int dado) {
	Lista2 *a; 
	for(a=li;a!=NULL;a=a->prox)
	    if(a->info == dado) return a;
	return NULL;
}
  
/* retorna o novo inicio ou a lista original */
Lista2* lista_retira(Lista2* li, int dado){
	//procura o elemento na lista usando a função busca
	Lista2* aux=lista_busca(li, dado);
	if (aux==NULL) //não achou o elemento
		return li; 
	//retira o elemento encadeado
	if(li==aux) //verifica se é o primeiro da lista
		li=aux->prox;
	else
		aux->ant->prox=aux->prox;
	//testa para ver se é o ultimo da lista
	if (aux->prox!=NULL)        
		aux->prox->ant=aux->ant;
	free(aux);
	return li;
}

/* libera o espaço ocupado pela lista */
void lista_esvazia(Lista2 *li){
    Lista2 *p,*t;
    p=li;
    while(p!=NULL){
    	t=p->prox;
    	free(p);//libera o item da lista
    	p=t;
	}                   
}

/*retorna total de numeros maior que o numero informado*/
int total_numeros (Lista2 *li){
	Lista2 *aux; int tot=0;
	for(aux=li;aux!=NULL; aux=aux->prox){
		tot++;
	}
	return tot;
}

/*retorna media dos numeros*/
float media_numeros (Lista2 *prox){
	Lista2 *aux; float tot, soma;
	for(aux=prox;aux!=NULL; aux=aux->prox){
		soma = soma + aux->info;
		tot++;
	}
	return soma/tot;
}

/* retorna maior numero */
int maior_numero(Lista2 *li){
	int maior; Lista2 *aux = li;
	if(aux!=NULL){
		maior = aux->info;
	} else {
		return 0;
	}
	aux=aux->prox;
	while(aux!=NULL){
		if(aux->info > maior){
			maior = aux->info;
		}
		aux=aux->prox;
	}
	return maior;
}

/* retorna menor numero */
int menor_numero(Lista2 *li){
	int menor; Lista2 *aux = li;
	if(aux!=NULL){
		menor = aux->info;
	} else {
		return 0;
	}
	aux=aux->prox;
	while(aux!=NULL){
		if(aux->info < menor){
			menor = aux->info;
		}
		aux=aux->prox;
	}
	return menor;
}

/* printa os elementos adjacentes de um elemento X*/
void vizinhos(Lista2 *li, int dado) {
	Lista2 *aux = li;
	if(aux==NULL){
		printf("Lista Vazia\n\n");
	}else{
		for(aux=li;aux!=NULL;aux=aux->prox){
			if(aux->info == dado) {
				if(aux->ant != NULL){
					printf("Anterior: %d\n", aux->ant->info);
				}else{
					printf("Não tem anterior\n");
				}
				if(aux->prox != NULL){
					printf("Próximo: %d\n", aux->prox->info);
				}else{
					printf("Não tem próximo\n");
				}
			}	
		}
	}
}
