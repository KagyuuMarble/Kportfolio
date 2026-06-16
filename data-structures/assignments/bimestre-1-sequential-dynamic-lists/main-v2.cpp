//Trabalho 1º Bimestre - Listas Sequenciais e Dinâmicas
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Alunos Gustavo Guse Martins RA: 22009526
//Alunos Kevin Kurpias Rodrigues RA: 22017826


LISTA SEQUENCIAL


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 5


void insereLista(int valor);
int buscaLista(int valor);
void removeLista(int valor);
void imprime();


int lista[N];
int contador = -1;


int main(){


    int opcao,j;
    while (opcao < 5){


        printf("---DIGITE UM NUMERO DE 1 A 5---\n\n");
        printf("1-INSERIR\n2-REMOVER \n3-IMPRIMIR \n4-BUSCAR POR NUMERO \n5-SAIR \nDIGITE:");
        scanf("%d", &opcao);
        system("cls");


        switch(opcao){


        case 1:
            printf("Digite o numero que deseja inserir na lista\n");
            scanf("%d",&j);
            system("cls");
            insereLista(j);
        break;
        case 2:
            printf("Digite o valor que deseja remover.\n");
            scanf("%d",&j);
            system("cls");
            removeLista(j);
        break;
        case 3:
            imprime();
            getch();
            system("cls");
        break;
        case 4:
            printf("Digite o valor que deseja procurar.\n");
            scanf("%d",&j);
            printf("O numero %d esta na posicao %d.\n", j,buscaLista(j));
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


int buscaLista(int valor){
    //busca o valor e retorna a posicao que o achar
    int posicao = -1;
    for(int i=0;i<=contador;i++){


        if(valor==lista[i]){
            posicao = i;
        }
    }
    return posicao;
    system("cls");
}


void insereLista(int valor){


    if(contador == N-1){
        printf("Fila cheia!\n");
        getch();
        system("cls");
    }
        else{
            if(buscaLista(valor)!= -1){


                printf("Valor ja existente.\n");
                getch();
                system("cls");
            }
                else{


                    ++contador;
                    int aux = contador-1;
                    for(int i = 0 ; i<= contador; ++i){
                            //faz um loop que percorre a fila e insere o valor onde Ã© maior que o anterior e menor que o posterior




                        if(lista[aux]<valor){
                            //se a posicao x conter um numero menor que o valor, insere o valor na posicao posterior
                            lista[aux+1] = valor;
                            return;


                        }
                        else{


                            lista[aux+1] = lista[aux];
                            --aux;


                        }


                    }
                }
            }
}


void removeLista(int valor){//remove um valor
    if(contador == -1){


        printf("Fila vazia!\n");
        getch();
        system("cls");
        return;


    }
        else if(buscaLista(valor) == -1){


                printf("Valor nao existente!\n");
                getch();
                system("cls");


            }
                else{
                        int aux = buscaLista(valor);
                        for(int i = aux; i<=contador;i++){


                            lista[i] = lista[i+1];


                        }
                        printf("Valor removido!\n");
                        getch();
                        system("cls");
                        --contador;


                }
        }




void imprime(){
    if(contador== -1){
        printf("Lista vazia!\n");
    }
        else{
            for(int i = 0; i<=contador; i++){
                printf("%d\n", lista[i]);
            }
        }
}