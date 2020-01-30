#define N 10 //tamanho da pilha

typedef struct pilha{
	int topo;
    int vet[N];
}Pilha;

/* inicializa uma pilha */
Pilha *pilha_cria(){
    Pilha *p=(Pilha*)malloc(sizeof(Pilha));
	p->topo=0;
    return p;
} 

/* retorna 1 se vazia ou zero se falso */
int pilha_vazia(Pilha *p){
	if (p->topo==0) return 1;
	else return 0;
}

/* insere o novo dado no início da pilha*/
void pilha_push(Pilha *p, int v) {
	if(p->topo==N){
		printf("Capacidade da pilha esgotada.\n");
		return;
	}
	p->vet[p->topo]=v;
	p->topo++;
}

/*remove o topo da pilha e retorna valor retirado*/
int pilha_pop(Pilha *p){
    int v;
    v=p->vet[p->topo-1];
    p->topo--;
    return v;
}

/* percorre a pilha do inicio até o fim mostrando os elementos */
void pilha_mostra(Pilha *p) {
	printf("\n\n-------- Pilha --------\n\n");
	if(pilha_vazia(p)){
		printf("(Sem elementos no momento)");
	}else{
		for(int i=p->topo-1;i>=0;i--)
        printf("%d\n",p->vet[i]);
	}
	printf("\n\n-----------------------\n\n");
}

/* retorna o elemento ou NULL se não achou*/
Pilha* pilha_busca(Pilha* p, int dado){    
	for (int i=0; i <= N; i++)
		if(p->vet[i] == dado) return p;
	return NULL;
}

/* libera o espaço ocupado pela pilha */
void pilha_esvazia(Pilha *p){
	free(p); 
}

/* soma todos os elementos da pilha e mostra o valor */
void pilha_soma(Pilha *p){
	Pilha *aux=pilha_cria();
	int soma=0, v;
	if(pilha_vazia(p)){
		printf("Não é possível somar porque a pilha está vazia \n\n");
		return;
	}else{
		while(!pilha_vazia(p)){
			v=pilha_pop(p);
			pilha_push(aux,v);
			soma=soma+v;
		}
		while(!pilha_vazia(aux)){
			v=pilha_pop(aux);
			pilha_push(p,v);
		}
		pilha_esvazia(aux);
		printf("A soma de todos os elementos da pilha é %d\n\n", soma);
	}
}

/* cria uma nova pilha, com todos os elementos da pilha original ao quadrado */
void *pilha_quadrado(Pilha *p){
	Pilha *aux = pilha_cria();
	Pilha *quad = pilha_cria();
	int v;
	
	printf("\n\n-------- Pilha ao Quadrado --------\n\n");
	if(pilha_vazia(p)){
		printf("(Sem elementos no momento)");
	}else{
		while (!pilha_vazia(p)){
			pilha_push(aux, pilha_pop(p));
		}
		while(!pilha_vazia(aux)){
			v=pilha_pop(aux);
			pilha_push(p,v);
			pilha_push(quad, v+v);
		}
		pilha_esvazia(aux);
		for(int i=p->topo-1;i>=0;i--)
        	printf("%d\n",quad->vet[i]);
	}
	printf("\n\n-----------------------\n\n");
}

/* exibe a base da pilha */
void pilha_base(Pilha *p){
	int v;
	Pilha *aux = pilha_cria();
	if (pilha_vazia(p)){
		printf("Não é possível encontrar a base porque a pilha está vazia \n\n");
		return;
	}else{
		while(!pilha_vazia(p)){ 
			v=pilha_pop(p);
			pilha_push(aux,v);
		}	
		while(!pilha_vazia(aux)){
			pilha_push(p, pilha_pop(aux));
		}
		pilha_esvazia(aux);
		printf("A base da pilha é %d\n\n", v);
	}
	
}
