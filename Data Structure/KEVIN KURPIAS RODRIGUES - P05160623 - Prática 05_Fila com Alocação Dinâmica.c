//P05160623 - Prática 05/Fila com Alocação Dinâmica
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Kevin Kurpias Rodrigues RA: 22017826




#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct no{


    int dado;
    struct no *prox;


};


struct no *inicio = NULL;
struct no *fim = NULL;


void insereFila(int valor){


    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));




    if (fim == NULL){


        aux->dado = valor;
        aux->prox = NULL;
        inicio = aux;
        fim = aux;
        return;


    }
        aux->dado = valor;
        aux->prox = NULL;
        fim->prox = aux;
        fim = aux;


}


void removeFila(){


    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));


    if(fim == NULL){


        printf("Fila vazia\n");


    }
        else if(inicio == fim){


            free(inicio);
            inicio = NULL;
            fim = NULL;
            printf("Numero removido.\n");


        }
            else{


                aux = inicio;
                inicio = inicio->prox;
                free(aux);
                printf("Numero removido.\n");


            }
}


void vazia(){


    if(fim == NULL){


        printf("Fila vazia\n");


    }
        else{


            printf("Fila nao esta vazia\n");


        }


}


void inicioFila(){


    if(fim == NULL){


        printf("Fila vazia\n");


    }
        else{


            printf("O inicio da fila e %d\n", inicio->dado);


        }


}


void imprimeFila(){


    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));
    aux = inicio;


    if(fim == NULL){


        printf("Fila vazia\n");


    }
        while(aux!=NULL){


            printf("%d\n", aux->dado);
            aux= aux->prox;


        }


}


int main (){




    int opcao,j;
    //opcao = 0;
    while (opcao < 6){


        printf("Digite um numero de 1 a 6\n");
        printf("1-Inserir \n2-Remover \n3-Imprimir \n4-Verificar Vazia \n5-Inicio da Fila \n6-Sair\n");
        scanf("%d", &opcao);
        system("cls");


        switch(opcao){


        case 1:
            printf("Digite o numero que deseja inserir na fila\n");
            scanf("%d",&j);
            system("cls");
            insereFila(j);
        break;
        case 2:
            printf("Digite o valor que deseja remover.\n");
            system("cls");
            removeFila();
            getch();
            system("cls");
        break;
        case 3:
            imprimeFila();
            getch();
            system("cls");
        break;
        case 4:
            //printf("Verificar se vazia.\n");
            vazia();
            getch();
            system("cls");
        break;
        case 5:
            inicioFila();
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