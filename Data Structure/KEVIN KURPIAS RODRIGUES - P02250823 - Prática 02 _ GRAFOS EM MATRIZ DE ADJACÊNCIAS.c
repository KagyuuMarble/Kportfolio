//ALUNO:KEVIN KURPIAS RODRIGUES || RA: 22017826


 #include <stdio.h>
#include <stdlib.h>
#define vertice int // eu não sabia que dava pra fazer isso
#define TAM 4


void inicializar();
void insereVertice(int valor);//: insere um vértice em um grafo. Deve verificar se há espaço no vetor e não pode inserir vértices repetidos.
void insereAresta(int origem, int destino);//: insere uma aresta entre dois vértices. Deve verificar inicialmente se os vértices existem.
void removeAresta(int origem, int destino);//: remove uma aresta entre dois vértices. Deve verificar inicialmente se os vértices existem e se a aresta existe.
void haAresta(int origem, int destino);//: imprime se existe uma aresta entre dois vértices. Deve verificar inicialmente se os vértices existem.
void imprimeGrafo();//: imprime o grafo.


vertice vetor[TAM];
int adj[TAM][TAM];
int cont = 0;


void inicializar()
{
        int i, j;
        for(i=0;i<TAM;i++)
        {
            for(j=0;j<TAM;j++)
            {
                adj[i][j] = 0;
            }
        }
}


void insereVertice(int valor)
{
        int i;
        if(cont == TAM)
        {
            printf("Vetor cheio.\n");
            return;
        }


        for(i=0;i<cont;i++)
        {
            if(vetor[i]==valor)
            {
                printf("Valor repetido.\n");
                return;
            }
        }
        vetor[cont] = valor;
        cont++;
}


void insereAresta(int origem, int destino)
{
        int i;
        int aux1 = -1;
        int aux2 = -1;


        for(i=0;i<cont;i++)
        {
            if(vetor[i] == origem)
            {
                aux1 = i;
            }
            if(vetor[i] == destino)
            {
                aux2 = i;
            }
        }


        if(aux1 == -1 || aux2 == -1)
        {
            printf("Vertices nao encontrados!\n");
            return;
        }
        if(adj[aux1][aux2] == 1)
        {
            printf("Aresta repetida nao inserida!\n");
        }
        adj[aux1][aux2] = 1;
}


void removeAresta(int origem, int destino)
{
        int i;
        int aux1 = -1;
        int aux2 = -1;


        for(i=0;i<cont;i++)
        {
            if(vetor[i] == origem)
            {
                aux1 = i;
            }
            if(vetor[i] == destino)
            {
                aux2 = i;
            }
        }


        if(aux1 == -1 || aux2 == -1)
        {
            printf("Vertices nao encontrados!\n");
            return;
        }
        if(adj[aux1][aux2] == 0)
        {
            printf("Aresta nao existe!\n");
            return;
        }
        adj[aux1][aux2] = 0;
}


void haAresta(int origem, int destino)
{
        int i;
        int aux1 = -1;
        int aux2 = -1;


        for(i=0;i<cont;i++)
        {
            if(vetor[i] == origem)
            {
                aux1 = i;
            }
            if(vetor[i] == destino)
            {
                aux2 = i;
            }
        }


        if(aux1 == -1 || aux2 == -1)
        {
            printf("Vertices nao encontrados!\n");
            return;
        }
        if(adj[aux1][aux2] == 0)
        {
            printf("Aresta nao existe!\n");
            return;
        }
        else
        {
            printf("Aresta <[%d][%d]> existe!\n", aux1, aux2);
        }
}


void imprimeGrafo()
{
        int i, j;
        printf("\t");
        for(i=0;i<cont;i++)
        {
            printf("<%d>\t", vetor[i]);
        }
        printf("\n");
        for(i=0;i<cont;i++)
        {
            for(j=0;j<cont;j++)
            {
                if(j == 0)
                {
                    printf("<%d>\t", vetor[i]);
                }
                printf("[%d]\t", adj[i][j]);
            }
            printf("\n");
        }
}


int main()
{
        int menu = 0;
        int aux = 0;
        int aux2 = 0;
        inicializar();
        while(menu < 6)
        {
            printf("1.Inserir Vertice\n");
            printf("2.Inserir Aresta\n");
            printf("3.Remover Aresta\n");
            printf("4.Checkar Aresta\n");
            printf("5.Imprimir Matriz\n");
            printf("6.Sair\n");


            scanf("%d", &menu);


            switch(menu)
            {
                case 1:
                    scanf("%d", &aux);
                    insereVertice(aux);
                    break;
                case 2:
                    printf("Origem:\n");
                    scanf("%d", &aux);
                    printf("Destino:\n");
                    scanf("%d", &aux2);
                    insereAresta(aux, aux2);
                    break;
                case 3:
                    printf("Origem:\n");
                    scanf("%d", &aux);
                    printf("Destino:\n");
                    scanf("%d", &aux2);
                    removeAresta(aux, aux2);
                    break;
                case 4:
                    printf("Origem:\n");
                    scanf("%d", &aux);
                    printf("Destino:\n");
                    scanf("%d", &aux2);
                    haAresta(aux, aux2);
                    break;
                case 5:
                    imprimeGrafo();
                    break;
                default:
                    break;


            }
        }


        return 0;
}