#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 5

// estrutura da pilha
typedef struct {
    int topo; // variavel para topo
    int itens[TAM_MAX]; // variavel para itens
} Pilha; // a estrutura se chama Pilha

// funcao para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1; // topo da pilha = -1, vazia
}

// funcao para verificar se a pilha ta cheia
int cheia(Pilha *p) {
    return (p->topo == TAM_MAX - 1); // se o topo for indice 4, esta cheia
}

// funcao para verificar se a pilha ta vazia
int vazia(Pilha *p) {
    return (p->topo == -1); // se o topo for -1, esta vazia
}

// funcao para empilhar um elemento
void push(Pilha *p, int valor) { // push = empilha
    if (cheia(p)) { // se tiver cheia
        printf("Não deu para adicionar mais... a pilha está cheia!\n\n");
    } else { 
        p->itens[++(p->topo)] = valor; //adiciona no topo e insere o valor na nova posição do topo
    }
}

// funcao para desempilhar no topo
int pop(Pilha *p) { // tirar do topo
    if (vazia(p)) { // se tiver vazia 
        printf("Não deu para retirar nada... pilha está vazia!\n\n");
        return -1; // retorna -1 para indicar erro
    } else {
        return p->itens[(p->topo)--]; // tirar do topo
    }
}

// funcao para visualizar o elemento no topo da pilha
int peek(Pilha *p) {
    if (vazia(p)) { // se tiver vazia
        printf("Não deu para mostrar o topo... pilha está vazia.\n\n");
        return -1; // erro
    } else {
        return p->itens[p->topo]; // ir para o topo e exibir
    }
}

// funcao para imprimir a pilha atual
void imprimir(Pilha *p){
  if(!vazia(p)){  // se tiver vazia mostra nada
    printf("[");
    for(int i = 0; i<p->topo;i++){ // para i = 0 e i percorrer ate o topo
        printf("%d, ",p->itens[i]); // print os itens ate o topo
    }
    printf("%d]\n",peek(p));} // senao imprima o unico e feche a sessao
}


int main() {
    Pilha p; //cria uma nova pilha
    inicializar(&p); //inicializa a pilha com topo -1;
    
    push(&p,10); // adiciona o primeiro
    push(&p,4); // segundo
    push(&p,2); // terceiro
    push(&p,8); // quarto
    push(&p,20); // quinto
    push(&p,30);
    
    imprimir(&p);
    
    pop(&p); // tira o quarto, topo
    
    imprimir(&p); // imprima tudo

    return 0;
}
