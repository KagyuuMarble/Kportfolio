//Trabalho 1º Bimestre - Listas Sequenciais e Dinâmicas
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Alunos Gustavo Guse Martins RA: 22009526
//Alunos Kevin Kurpias Rodrigues RA: 22017826




LISTA DINÂMICA ORDENADA
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct no  // declara o nó
{


    int valor;
    struct no *prox;


};


struct no *frente = NULL;
struct no *inicio = NULL;


int cabecalho;
//contem o numero de elementos da lista


int buscaLista(int valor)
//busca o valor na lista
{


    int posicao = 1;
    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));
    aux = frente;


    if (cabecalho != 0)
    {
        while(aux != NULL)
        {


            if(aux->valor == valor)
            {
                return posicao;
                //se aux achou o numero retorna a posicao
                system("cls");
            }
            else
            {
                aux = aux-> prox;
                //se aux nao achou passa aux para a proxima posicao
                ++posicao;
            }


        }


    }
    else
    {
        return 0;
        system("cls");
    }
}


void inserir(int valor)
{


    if(buscaLista(valor) == 0 )
    {
        struct no *aux;
        aux = (struct no*)malloc(sizeof(struct no));
        aux->valor = valor;
        struct no *src;
        src = (struct no*)malloc(sizeof(struct no));
        struct no *src2;
        src2 = (struct no*)malloc(sizeof(struct no));




        if(cabecalho == 0)//se nao tiver nada na lista, a inicia
        {


            aux->prox = NULL;//aux é ligado ao primeiro elemento
            frente = aux; //frente e inicio viram aux
            inicio = aux;
            ++cabecalho;
            printf("Numero inserido com sucesso.\n");
            getch();
            system("cls");


            return;


        }
        else //caso nao seja o primeiro elemento
        {


            src = frente;
            //criam 2 variaveis para comparar com o valor na frente e atras
            src2->prox = src;


            while(src!= NULL)
            {


                if(src->valor > aux->valor)//se aux for menor que src(search)
                {




                    aux->prox = src;
                    //aux é inserido entre src e src2
                    src2->prox = aux;




                    if(src == frente)
                    {


                        frente = aux;
                        //se src for a frente, frente vira o novo elemento


                    }
                    printf("Numero inserido com sucesso.\n");
                    getch();
                    system("cls");
                    ++cabecalho;


                    return;
                }
                else if(src == inicio && src->valor < aux->valor)
                //se src for inicio, insere aux na sua frente, fazendo ligacao com null
                {


                    aux->prox = src->prox;
                    src->prox = aux;
                    inicio = aux;
                    ++cabecalho;
                    printf("Numero inserido com sucesso.\n");
                    getch();
                    system("cls");
                    return;


                }
                else
                {


                    src = src->prox;
                    src2 = src2->prox;


                }
            }


        }
        return;
    }


    printf("Numero repetido! Tente novamente.");
    getch();
    system("cls");


}


void removeLista(int valor)
//remove o valor indicado
{


    if(cabecalho == 0)
    {
        printf("Fila vazia.\n");
        getch();
        system("cls");
        return;
    }
    else if(buscaLista(valor)== 0)
    {
        printf("Numero nao encontrado.\n");
        getch();
        system("cls");
        return;
    }
    else
    {


        struct no *aux;
        struct no *src;
        aux = (struct no*)malloc(sizeof(struct no));
        aux = frente;
        src = (struct no*)malloc(sizeof(struct no));
        src->prox = aux;


        while(aux != NULL)
        {
            if(aux->valor == valor)
            {
                if(aux == inicio)
                {
                    inicio = src;
                }
                if(aux == frente)
                {
                    frente = aux->prox;
                }
                src->prox = aux->prox;
                free(aux);
                printf("Valor removido com sucesso.\n");
                getch();
                system("cls");
                --cabecalho;
                return;
            }
            else
            {
                aux = aux-> prox;
                src = src->prox;
            }
        }
        --cabecalho;
    }


}


void imprimir()
{


    if(cabecalho!= 0)
    {
        struct no *aux;
        aux = (struct no*)malloc(sizeof(struct no));
        aux = frente;
        while(aux!=NULL)
        {
            printf("%d\n", aux->valor);
            aux=aux->prox;
        }
    }
    else
    {
        printf("Fila vazia.\n");
    }
}


void verCabecalho()
{


    printf("O numero de elementos na lista e %d\n", cabecalho);
    getch();
    system("cls");


}


int main()
{


    int opcao,j;
    while (opcao < 6)
    {


        printf("***LISTA DINAMICA ORDENADA***\n\n");
        printf("DIGITE UM NUMERO DE 1 A 6\n\n");
        printf("1-INSERIR \n2-REMOVER \n3-IMPRIMIR \n4-BUSCAR POR NUMERO \n5-VER NUMERO DE ELEMENTOS \n6-SAIR \nDIGITE:");
        scanf("%d", &opcao);
        system("cls");


        switch(opcao)
        {


        case 1:
            printf("Digite o numero que deseja inserir na lista\n");
            scanf("%d",&j);
            system("cls");
            inserir(j);
            break;
        case 2:
            printf("Digite o valor que deseja remover.\n");
            scanf("%d",&j);
            system("cls");
            removeLista(j);
            break;
        case 3:
            imprimir();
            getch();
            system("cls");
            break;
        case 4:
            printf("Digite o valor que deseja procurar.\n");
            scanf("%d",&j);
            system("cls");


            if(buscaLista(j)!= 0)
            {
                printf("O numero %d ja esta na lista na posicao %d.", j, buscaLista(j));
                getch();
                system("cls");
            }
            else
            {
                printf("O numero %d ainda nao esta na lista.\n", j);
                getch();
                system("cls");
            }
            break;
        case 5:
            verCabecalho();
            break;
        default:
            printf("Saindo do menu.\n");
            break;
        }
    }
    return 0;
}