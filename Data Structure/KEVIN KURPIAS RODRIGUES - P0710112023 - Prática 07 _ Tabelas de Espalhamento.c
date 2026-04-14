/*  ALUNO:KEVIN KURPIAS RODRIGUES
        RA:22017826                         */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


#define MAX_TAM 10


int tabela_de_espalhamento[MAX_TAM] = {0};
short count = 0;


int espalha(int chave)//implementa a função de espalhamento
{
        int pos = chave % MAX_TAM;


        if(tabela_de_espalhamento[pos] != 0)
        {
            return reespalha(pos);
        }


        return pos;
}


int reespalha(int pos)//implementa a função de reespalhamento
{


        pos = (pos + 1) % MAX_TAM;


        if(tabela_de_espalhamento[pos] != 0 && count < 10)
        {
            return reespalha(pos);
        }
        else if(count >= 10)
        {
            printf("Tabela cheia!\n");
            return -1;
        }


        return pos;
}
void insere(int chave)//insere um valor em uma tabela de espalhamento
{
        int pos = espalha(chave);
        if(pos > -1 && pos < 10)
        {
            tabela_de_espalhamento[pos] = chave;
            count++;
            printf("Elemento <%d> inserido em [%d]!\n", chave, pos);
        }
}
void busca(int chave)//busca um valor em uma tabela de espalhamento
{
        int i;
        for(i = 0; i < MAX_TAM; i++)
        {
            if(tabela_de_espalhamento[i] == chave)
            {
                printf("Elemento <%d> encontrado em [%d]!\n", chave, i);
                return;
            }
        }
        printf("Elemento não encontrado na tabela!\n");
}
void imprime()//imprime o vetor inteiro (para testar a tabela de espalhamento)
{
        int i;
        printf("Posição\t<=\Chave:\n");
        for(i = 0; i < MAX_TAM; i++)
        {
            if(tabela_de_espalhamento[i] != 0)
            {
                printf("[%d]\t<=\t<%d>\n", i, tabela_de_espalhamento[i]);
            }
        }
}


int main()
{
        setlocale(LC_ALL, "Portuguese");
        bool menu = true;
        int escolha, chave;
        while(menu != false)
        {
            printf("Tabela de espalhamento:\n");
            printf("1\)Inserção.\n2\)Busca.\n3\)Impressão.\n4\)Sair.\n");
            scanf("%d", &escolha);


            switch(escolha)
            {
            case 1:
                        printf("Informe a chave:\n");
                        scanf("%d", &chave);
                        insere(chave);
                        break;
            case 2:
                        printf("Informe a chave:\n");
                        scanf("%d", &chave);
                        busca(chave);
                        break;
            case 3:
                        imprime();
                        break;
            default:
                        menu = false;
                        break;
                    }
}
}