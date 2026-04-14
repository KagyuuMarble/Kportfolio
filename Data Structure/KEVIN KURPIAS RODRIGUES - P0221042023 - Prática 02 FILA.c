//P0221042023 - Prática 02 FILA
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Kevin Kurpias Rodrigues RA: 22017826


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 3


int fila[N];
int fim = -1,inicio = 0, count = 0;


void insereFila(int valor){


    if(count == N){
        printf("Fila cheia.\n");
    }
        else{
            if(fim == N-1){
                fim = -1;
            }
            fila[fim+1] = valor;
            fim ++;
            count ++;
        }
}


void removeFila(){
    if(count == 0){
        printf("Fila vazia.\n");
    }
        else{
            if(inicio == N-1){
                inicio = -1;
            }
            inicio ++;
            count --;
        }
}


void inicioFila(){
    if(count == 0){
        printf("Fila vazia.\n");
    }
        else{
            printf("%d", fila[inicio]);
        }
}


void imprime(){
    if(count == 0){
        printf("Fila vazia.\n");
    }
        else{
            if(inicio <= fim){
                for(int i = inicio; i<= fim; i++){
                    printf("%d\n", fila[i]);
                }


            }else {
                for(int i = inicio; i<= N-1 ; i++){
                printf("%d\n", fila[i]);
                }
            for(int i = 0; i<=fim; i++){
                printf("%d\n", fila[i]);
                }
            }




         }






 }
 
 int main(){


    int opcao,j;
    while (opcao < 5){


        printf("Digite um numero de 1 a 5\n");
        printf("1-Inserir\n2-Remover \n3-Imprimir \n4-Imprimir inicio da fila \n5-Sair\n");
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
            removeFila();
        break;
        case 3:
            imprime();
            getch();
            system("cls");
        break;
        case 4:
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