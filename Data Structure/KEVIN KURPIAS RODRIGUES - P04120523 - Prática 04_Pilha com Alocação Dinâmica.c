//P04120523 - Prática 04/Pilha com Alocação Dinâmica
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Kevin Kurpias Rodrigues RA: 22017826


#include <stdio.h>
#include <stdlib.h>


struct no {
        int dado;
        struct no *prox;
};


struct no *pilha = NULL;


void push(int valor){


    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));
    aux -> dado = valor;
    aux -> prox = pilha;
    pilha=aux;


}


void pop(){


    struct no *p;
    int i;


    if(pilha== NULL){
        printf("Pilha vazia.\n");
    }
        else{
            p = pilha;
            pilha = pilha ->prox;
            free(p);
            printf("Elemento removido.\n");
        }
}


void topopilha(){
    if(pilha == NULL){
        printf("Pilha vazia.\n");
    }
        else{


            printf("O topo da pilha e %d.\n",pilha->dado);


        }
}


void imprimir(){


    struct no *aux2;
    aux2 = pilha;
    while(pilha != NULL){




        printf("%d\n", pilha->dado);
        pilha = pilha->prox;


    }
    pilha = aux2;
}
int main(){


    int opcao,j;
    while (opcao < 5){


        printf("Digite um numero de 1 a 5\n");
        printf("1-Inserir\n2-Remover \n3-Imprimir \n4-Topo pilha \n5-Sair\n");
        scanf("%d", &opcao);
        system("cls");


        switch(opcao){


        case 1:
            printf("Digite o numero que deseja inserir na pilha\n");
            scanf("%d",&j);
            system("cls");
            push(j);
        break;
        case 2:
            printf("Digite o valor que deseja remover.\n");
            system("cls");
            pop();
        break;
        case 3:
            imprimir();
            getch();
            system("cls");
        break;
        case 4:
            printf("Topo pilha.\n");
            topopilha();
            getch();
            system("cls");
        break;
        default:
            printf("Sair do menu\n");
        break;
        }


    }


return 0;
}