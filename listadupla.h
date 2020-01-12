typedef struct lista2{
	int info;
	struct lista2 *ant;
	struct lista2 *prox;
}Lista2;

/*inicializa uma lista dupla*/
Lista2 * lista_cria(){
	return NULL;
}

/* retorna 1 se vazia ou zero se falso*/
int lista_vazia(Lista2* li){
	return(li==NULL);
}

/* insere o novo dado no início da lista  e retorna a lista atualizada*/
Lista2* lista_insere( Lista2* li, int dado){
	Lista2 *novo = (Lista2*) malloc (sizeof(Lista2));
	novo->info=dado;
	novo->prox=li;
	novo->ant=NULL;
	if(li!= NULL)
		li->ant=novo;         
	return novo;
}

/* percorre a lista do inicio até o fim mostrando os elementos*/
void lista_exibe(Lista2* li) {
	Lista2 *aux;
	printf("\n\nLista\n\n");
	if(lista_vazia(li)){
		printf("Sem elementos no momento");
	}else{
		for(aux=li;aux!=NULL;aux=aux->prox)
    	printf("%d\t", aux->info);
	}
	printf("\n\n");
}       

/* retorna o elemento ou NULL se não achou*/
Lista2* lista_busca(Lista2* li, int dado) {
	Lista2 *a; 
	for(a=li;a!=NULL;a=a->prox)
	    if(a->info == dado) return a;
	return NULL;
}
  
/* retorna o novo inicio ou a lista original*/
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

/* libera o espaço ocupado pela lista*/
void lista_libera(Lista2 *li){
    Lista2 *p,*t;
    p=li;
    while(p!=NULL){
    	t=p->prox;
    	free(p);// libera o item da lista
    	p=t;
	}                   
}
