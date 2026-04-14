//P01140423 - Prática 01 Pilha
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Kevin Kurpias Rodrigues RA: 22017826




#include <stdio.h>
#include <stdlib.h>
#define N 4
int pilha[N];
int topo = -1;


void push(int valor);
void pop();
void topopilha();
void imprimir();


int main(void){
    
    int opcao,j;
    while (opcao < 5){
            
        printf("Digite um numero de 1 a 5\n");
        scanf("%d", &opcao);
        
        switch(opcao){ 
    
        case 1:
            printf("Digite o numero que deseja inserir no topo da pilha\n");
            scanf("%d",&j);
            push(j);
        break;
        case 2:
            pop();
        break;    
        case 3:
            topopilha();
        break;
        case 4:
            imprimir();
        break;    
        default:
            printf("Sair do menu\n");
        break;
        }
        
    }
        return 0;
}


void imprimir(){
    if(topo==-1){
        printf("Pilha Vazia\n");
        return;
    }
    for(int i = topo; i > -1; i--){
        printf("%d\n", pilha[i]);
    }
}


void push(int valor){


    if(topo == N-1){
        printf("Pilha cheia.\n");
        return;
    }
    topo ++;
    pilha[topo] = valor;
}


void pop(){
    if(topo==-1){
        printf("Pilha vazia.\n");
        return;
    }
    int aux = pilha[top];
    topo--;
    printf("Elemento removido: %d\n", aux);
}


void topopilha(){
    if(topo==-1){
        printf("Pilha vazia.\n");
        return;
    }
    printf("Topo da pilha: %d\n", pilha[topo]);
}