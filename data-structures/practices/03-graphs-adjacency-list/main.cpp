//ALUNO: KEVIN KURPIAS RODRIGUES || RA: 22017826
#include <stdio.h>
#include <stdlib.h>


struct no_vertice{
        int vertice;
        struct no_vertice *prox;
        struct no_aresta *aresta;
};


struct no_aresta{
        int peso;
        int vertice_final;
        struct no_aresta *prox;
};


struct no_vertice *grafo = NULL;


void insere_vertice(int elem){
        struct no_vertice *aux, *atual;
        int encontrado = 0;


        aux = (struct no_vertice*) malloc(sizeof(struct no_vertice));


        aux -> vertice=elem;
        aux -> aresta=NULL;
        atual=grafo;


        while(atual != NULL ){
            if(atual -> vertice == elem){
                encontrado=1;
                printf("Vertice ja existente\n");
                return;
            }
            atual=atual->prox;
        }
        if(encontrado==0){
            aux->prox=grafo;
            grafo=aux;
        }
}


void insere_aresta(int peso,int ver1,int ver2){
        struct no_vertice *v_atual,*v_encontrado;
        struct no_aresta *aux, *a_atual;
        int encontrado=0;


        v_atual=grafo;


            while(v_atual != NULL && encontrado < 2){
                if(v_atual -> vertice == ver1){
                    encontrado++;
                    v_encontrado=v_atual;
                }
                if(v_atual->vertice==ver2){
                encontrado++;
                }
                v_atual=v_atual->prox;
            }


            if(encontrado != 2){
                printf("Vertice inexistente\n");
                return;
            }


            aux=(struct no_aresta*) malloc(sizeof(struct no_aresta));


            aux->peso=peso;
            aux->vertice_final=ver2;
            aux->prox=NULL;


            a_atual=v_encontrado->aresta;


            while(a_atual != NULL){
                if(a_atual->vertice_final==ver2){
                    a_atual->peso=peso;
                    return;
                }
                a_atual=a_atual->prox;
            }


            aux->prox=v_encontrado->aresta;
            v_encontrado->aresta=aux;
}


void remove_aresta(int ver1,int ver2){
        struct no_vertice *v_atual;
        struct no_aresta *a_atual,*a_ant,*freep;
        int encontrado = 0;


        v_atual=grafo;


        while(v_atual != NULL){
            if(v_atual->vertice==ver1){
                encontrado=1;
                break;
            }
            v_atual=v_atual->prox;
        }
        if(encontrado==0){
            printf("vertice inexistente\n");
            return;
        }
        encontrado=0;


        a_atual=v_atual->aresta;
        a_ant=a_atual;


        while(a_atual != NULL){
            if(a_atual->vertice_final==ver2){
                encontrado=1;
                if(a_ant==a_atual){
                    v_atual->aresta=a_atual->prox;
                    free(a_atual);
                }
                else{
                    a_ant->prox=a_atual->prox;
                    free(a_atual);
                }
                break;
            }
            a_ant=a_atual;
            a_atual=a_atual->prox;
        }
        if(encontrado==0){
            printf("Aresta inexistente\n");
        }
}


void imprime(){
        struct no_vertice *v_atual;
        struct no_aresta *a_atual;


        v_atual=grafo;


        while(v_atual != NULL){
            printf("%d ",v_atual-> vertice);
            a_atual=v_atual -> aresta;
            while(a_atual != NULL){
                printf("(%d %d)" , a_atual->peso,a_atual->vertice_final);
                a_atual=a_atual->prox;
            }
            v_atual=v_atual->prox;
            printf("\n");
        }
}


int main(){
        int op=-1;
        int ver1,ver2,peso;


        while(op<5){
        printf("Digite a operacao:\n 1-Inserir Vertice\n 2-Inserir Aresta\n 3-Remover Aresta\n 4-Imprimir\n 5-Sair\n");
        scanf("%d",&op);
        printf("\n");






            switch(op){
                case 1:
                    printf("Digite o vertice que sera inserido: ");
                    scanf("%d",&ver1);
                    insere_vertice(ver1);
                    printf("\n");
                    break;
                case 2:
                    printf("Digite a aresta que sera inserida(peso ver1 ver2): ");
                    scanf("%d %d %d",&peso,&ver1,&ver2);
                    insere_aresta(peso,ver1,ver2);
                    printf("\n");
                    break;
                case 3:
                    printf("Digite a aresta que sera removida: ");
                    scanf("%d %d",&ver1,&ver2);
                    remove_aresta(ver1,ver2);
                    printf("\n");
                    break;
                case 4:
                    imprime();
                    break;
                    }


        }
        return 0;
}