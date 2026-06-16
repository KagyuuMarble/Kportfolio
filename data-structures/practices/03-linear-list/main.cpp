//P03280423 - Prática 03 LISTA LINEAR
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Kevin Kurpias Rodrigues RA: 22017826


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 5


int lista[N];
int count = 0;
int i = 0;


int buscaLista(int valor)
{


    for(i = 0; i < N; i++)
    {
        if(valor == lista[i])
        {
            return i;
        }
    }
    return -1;
}


void insereLista(int valor)
{


    if(buscaLista(valor) != -1)
    {
        printf("Valor repetido nao inserido.\n");
    }
    else
    {
        if(count == N-1)
        {


            printf("Fila cheia.\n");


        }
        else
        {


            lista[count] = valor;
            count++;
        }
    }
}
void removeLista(int valor)
{
    if(count == 0)
    {
        printf("Lista vazia \n");
    }
    else
    {
        int j = buscaLista(valor);
        if(j != -1)
        {
            for(i = j; i < N-1; i++)
            {
                lista[i] = lista[i+1];
            }
            count--;
            printf("valor removido.\n");
        }
        else
        {
         printf("valor nao encontrado.\n");
        }
    }
}


void imprime()
{
    for(i = 0; i < count; i++)
    {
        printf("Lista[%d] = %d\n", i, lista[i]);
    }
}




int main(void)
{
    int menu = 0;
    int escolha = 0;
    int valor = 0;


    while(menu == 0)
    {
        printf("Escolha uma opcao\n1.inserir valor na lista\n2.remover valor na lista\n3.buscar valor na lista\n4.imprimir\n5.sair\n");
        scanf("%d", &escolha);
        fflush(stdin);


        switch(escolha)
        {


        case 1:
            printf("informe o valor a ser inserido:\n");
            scanf("%d", &valor);
            insereLista(valor);
            break;
        case 2:
            printf("informe o valor a ser remover:\n");
            scanf("%d", &valor);
            removeLista(valor);
            break;
        case 3:
            printf("informe o valor a ser buscado:\n");
            scanf("%d", &valor);
            if(buscaLista(valor)== -1)
            {
                printf("valor nao encontrado\n");
            }
            else
            {
                printf("valor encontrado na posicao: %d\n", buscaLista(valor));
            }
            break;
        case 4:
            imprime();
            break;
        default:
            menu = 1;
            break;
        }
    }
    return 0;
}