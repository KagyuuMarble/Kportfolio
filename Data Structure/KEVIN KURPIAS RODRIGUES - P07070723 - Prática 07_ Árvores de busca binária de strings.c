//P07070723 - Prática 07/ Árvores de busca binária de strings
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Kevin Kurpias Rodrigues RA: 220178


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define STR_SIZE 40
struct node
{
    int num_rep;
    char str[STR_SIZE];
    struct node *direita;
    struct node *esquerda;
};


struct node *root = NULL;


void insrtnd(char *str)
{
    struct node *atl;
    struct node *ant;
    struct node *temp;
    temp = (struct node*)calloc(1, sizeof(struct node));
    strcpy(temp->str, str);
    temp->direita = NULL;
    temp->esquerda = NULL;
    temp->num_rep = 1;


    if(root == NULL)
    {
            root = temp;
            printf("Inseriu na raiz!\n");
            return;
    }
    else
    {
            atl = root;
            ant = NULL;
            
            while(atl != NULL)
            {
                    ant = atl;
                    if(strncmp(temp->str, atl->str, STR_SIZE) == 0)
                    {
                            atl->num_rep = atl->num_rep + 1;
                            free(temp);
                            printf("String repetida!\n");
                            return;
                    }
                    if(strncmp(temp->str, atl->str, STR_SIZE) < 0)
                    {
                            atl = atl->esquerda;
                    }
                    else
                    {
                            atl = atl->direita;
                    }
            }
            if(strncmp(temp->str, ant->str, STR_SIZE) < 0)
            {
                    ant->esquerda = temp;
            }
            else
            {
                    ant->direita = temp;
            }
            printf("Inserido!\n");
    }
}


void treeOut(struct node *temp)
{
    if(temp != NULL)
    {
            treeOut(temp->esquerda);
            printf("|String: %s\t\t|Repetiu: %d\n", temp->str, temp->num_rep);
            treeOut(temp->direita);
    }
}




int main(void)
{
    FILE *file;
    char str[STR_SIZE];
    file = fopen("arq.txt", "r");
    if(file == NULL)
    {
            printf("Arquivo nao encontrado!\n");
            return 1;
    }
    while(feof(file) == 0)
    {
            if(fscanf(file, "%s", str) != EOF)
            {
                    insrtnd(str);
            }
    }
    treeOut(root);
    fclose(file);
    return 0;
}