//ALUNO: KEVIN KURPIAS RODRIGUES || RA: 22017826


#include <stdio.h>
#include <stdlib.h>
#define N 10
int vetor[] = {1,2,3,4,5,6,7,8,9,10};
void busca_sequencial(int chave)
{
    int i;
    int comp = 1;
    for(i=0;i<N;i++)
    {
        if(vetor[i] == chave)
        {
            printf("Elemento <%d> encontrado na posicao [%d]; Comparações:<%d>\n", chave, i, comp);
            return;
        }
        else
        {
            comp++;
        }
    }
}


void busca_binaria(int chave)
{
    int encontrado = 0;
    int pivo = N/2;
    int comp = 1;


    while(encontrado != 1)
    {
        if(chave == vetor[pivo])
        {
            encontrado++;
            printf("Elemento <%d> encontrado na posicao [%d]; Comparações:<%d>\n", chave, pivo, comp);
            return;
        }
        else
        {
            comp++;
            if(chave < vetor[pivo])
            {
                pivo = pivo/2;
            }
            else
            {
                pivo = (N + pivo)/2;
            }
        }
    }
}


int main()
{
    int menu = 0;
    int chave = 0;


    while(menu < 3)
    {
        printf("1.Sequencial\n2.Binaria\n3.sair\n");
        scanf("%d", &menu);


        switch(menu)
        {
            case 1:
                printf("Chave:\n");
                scanf("%d", &chave);
                busca_sequencial(chave);
                break;
            case 2:
                printf("Chave:\n");
                scanf("%d", &chave);
                busca_binaria(chave);
                break;
            default:
                break;
        }
    }
}