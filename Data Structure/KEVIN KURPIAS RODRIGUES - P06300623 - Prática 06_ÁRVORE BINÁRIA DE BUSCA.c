//P06300623 - Prática 06/ÁRVORE BINÁRIA DE BUSCA
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Kevin Kurpias Rodrigues RA: 22017826


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
typedef int bool;
struct node
{
    int dado;
    struct node *ptrRight;
    struct node *ptrLeft;
};
void seedTree(struct node **ptrRoot)
{
    *ptrRoot = NULL;
}
void insertNode(struct node **ptrRoot, int dado)
{
   if(*ptrRoot == NULL)
    {
        *ptrRoot = (struct node*)malloc(sizeof(struct node));
        (*ptrRoot)->dado = dado;
        (*ptrRoot)->ptrLeft = NULL;
        (*ptrRoot)->ptrRight = NULL;
    }
   else
    {
        if(dado < (*ptrRoot)->dado)
        {
            insertNode(&(*ptrRoot)->ptrLeft, dado);
        }
        else
        {
            insertNode(&(*ptrRoot)->ptrRight, dado);
        }
    }
}


struct node *greater(struct node **aux)
{
    if((*aux)->ptrRight != NULL)
    {
        return greater(&(*aux)->ptrRight);
    }
    else
    {
        struct node *temp = *aux;
        if((*aux)->ptrLeft != NULL)
        {
            *aux = (*aux)->ptrLeft;
        }
        else
        {
            *aux = NULL;
            return temp;
        }
    }
}
struct node *lesser(struct node **aux)
{
    if((*aux)->ptrLeft != NULL)
    {
        return lesser(&(*aux)->ptrLeft);
    }
    else
    {
        struct node *temp = *aux;
        if((*aux)->ptrRight != NULL)
        {
            *aux = (*aux)->ptrRight;
        }
        else
        {
            *aux = NULL;
            return temp;
        }
    }
}
void removeNode(struct node **ptrRoot, int dado)
{
    if(*ptrRoot == NULL)
    {
        printf("Node nao encontrado!");
        getch();
        return;
    }
    else
    {
        if(dado < (*ptrRoot)->dado)
        {
            removeNode(&(*ptrRoot)->ptrLeft, dado);
        }
        else
        {
            if(dado > (*ptrRoot)->dado)
            {
                removeNode(&(*ptrRoot)->ptrRight, dado);
            }
            else
            {
                struct node *aux = *ptrRoot;
                if(((*ptrRoot)->ptrLeft == NULL)&&((*ptrRoot)->ptrRight == NULL))
                {
                    free(aux);
                    *ptrRoot = NULL;
                }
                else
                {
                    if((*ptrRoot)->ptrLeft == NULL)
                    {
                        (*ptrRoot) = (*ptrRoot)->ptrRight;
                        (*ptrRoot)->ptrRight = NULL;
                        free(aux);
                        aux = NULL;
                    }
                    else
                    {
                        if((*ptrRoot)->ptrRight == NULL)
                        {
                            (*ptrRoot) = (*ptrRoot)->ptrLeft;
                            (*ptrRoot)->ptrLeft = NULL;
                            free(aux);
                            aux = NULL;
                        }
                        else
                        {
                            aux = lesser(&(*ptrRoot)->ptrRight);
                            aux->ptrLeft = (*ptrRoot)->ptrLeft;
                            aux->ptrRight = (*ptrRoot)->ptrRight;
                            (*ptrRoot)->ptrLeft = NULL;
                            (*ptrRoot)->ptrRight = NULL;
                            free((*ptrRoot));
                            *ptrRoot = aux;
                            aux = NULL;
                        }
                    }
                }
            }
        }
    }
}
void OutputOrdem(struct node *ptrRoot)
{
    if(ptrRoot != NULL)
    {
        OutputOrdem(ptrRoot->ptrLeft);
        printf("%d\n", ptrRoot->dado);
        OutputOrdem(ptrRoot->ptrRight);
    }
}
void OutputPosOrdem(struct node *ptrRoot)
{
    if(ptrRoot != NULL)
    {
        OutputPosOrdem(ptrRoot->ptrLeft);
        OutputPosOrdem(ptrRoot->ptrRight);
        printf("%d\n", ptrRoot->dado);
    }
}
void OutputPreOrdem(struct node *ptrRoot)
{
    if(ptrRoot != NULL)
    {
        printf("%d\n", ptrRoot->dado);
        OutputPreOrdem(ptrRoot->ptrLeft);
        OutputPreOrdem(ptrRoot->ptrRight);
    }
}
bool seek(struct node **ptrRoot, int dado)
{
    struct node *aux = *ptrRoot;
    bool stop = FALSE;
    if(*ptrRoot == NULL)
    {
        printf("Arvore vazia!\n");
        return FALSE;
    }
    else
    {
        if((aux->ptrLeft == NULL)&&(aux->ptrRight == NULL))
        {
            if(aux->dado == dado)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
           if(aux->dado == dado)
            {
                return TRUE;
            }
            else
            {
                while(stop == FALSE)
                {
                    if(aux->dado < dado)
                    {
                        if(aux->ptrLeft == NULL)
                        {
                            stop = TRUE;
                            if(aux->dado == dado)
                            {
                                break;
                                return TRUE;
                            }
                            else
                            {
                                return FALSE;
                            }
                        }
                        else
                        {
                            aux = aux->ptrRight;
                            if(aux->dado == dado)
                            {
                                return TRUE;
                                break;
                            }
                        }
                    }
                    else
                    {
                        if(aux->dado > dado)
                        {
                            if(aux->ptrRight == NULL)
                            {
                                stop = TRUE;
                                if(aux->dado == dado)
                                {
                                    return TRUE;
                                    break;
                                }
                                else
                                {
                                    return FALSE;
                                }
                            }
                        }
                        else
                        {
                            aux = aux->ptrLeft;
                            if(aux->dado == dado)
                            {
                                return TRUE;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    struct node **ptrRoot;
    seedTree(&(*ptrRoot));
    bool menu = TRUE;
    int choice;
    int valor;
    while(menu == TRUE)
    {
        printf("Escolha uma das opcoes abaixo:\n");
        printf("1.Inserir\n2.Remover\n3.Buscar\n4.Imprimir Ordem\n5.Imprimir Pos-Ordem\n6.Imprimir Pre-Ordem\n7.Sair\n");
        scanf("%d", &choice);
        system("cls");
        switch(choice)
        {
            case 1:
                printf("Inserir dado:\n");
                scanf("%d", &valor);
                insertNode(&(*ptrRoot), valor);
                system("cls");
            break;
            case 2:
                printf("Valor a ser removido:\n");
                scanf("%d", &valor);
                removeNode(&(*ptrRoot), valor);
                system("cls");
            break;
            case 3:
                printf("Valor a ser Buscado:\n");
                scanf("%d", &valor);
                if(seek(&(*ptrRoot), valor) == TRUE)
                {
                    printf("Valor encontrado!\n");
                }
                else
                {
                    printf("Valor NAO encontrado!\n");
                }
                getch();
                system("cls");
            break;
            case 4:
                OutputOrdem(*ptrRoot);
                getch();
                system("cls");
            break;
            case 5:
                OutputPosOrdem(*ptrRoot);
                getch();
                system("cls");
            break;
            case 6:
                OutputPreOrdem(*ptrRoot);
                getch();
                system("cls");
            break;
            default:
                menu = FALSE;
            break;
        }
    }
    return 0;
}