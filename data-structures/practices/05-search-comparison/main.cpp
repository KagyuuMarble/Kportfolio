//ALUNO: Kevin Kurpias Rodrigues
//RA:22017826


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 1000
#define quant 1000
 
int vetor[n];
int sorted[n];
float cont_arv_binaria = 0;
float cont_avl = 0;
float cont_seq = 0;
float cont_bin = 0;
 
/* struct para arvore AVL e arvore binaria*/
struct no {
                int dado;
                struct no *esq;
                struct no *dir;
                int bal;
                                          };
 
struct no *raiz=NULL;
struct no *raiz2=NULL;
 
/* Funcoes para o algoritmo da arvore AVL
 
/* Função que faz uma rotação para a esquerda no nó apontado por aux */
void direita(struct no *aux) {
         struct no *aux2=NULL;
 
         aux2 = aux -> esq;
         aux -> esq = aux2 -> dir;
         aux2 -> dir = aux;
}
 
/* Função que faz uma rotação para a direita no nó apontado por aux */
void esquerda(struct no *aux) {
         struct no *aux2=NULL;
 
         aux2 = aux -> dir;
         aux -> dir = aux2 -> esq;
         aux2 -> esq = aux;
}
 
/* Função que cria um novo nó, insere valores nele, e retorna um ponteiro para ele*/
struct no *cria_no(int x) {
         struct no *aux;
 
         aux = (struct no*) malloc(sizeof(struct no));
         aux -> dado = x;
         aux -> dir = NULL;
         aux -> esq = NULL;
         aux -> bal = 0;
 
         return aux;
}
 
/* Funçao que insere um elemento em uma árvore AVL */
void insere_bal(int chave){
         struct no *pp=NULL, *p=raiz2, *pajovem=NULL, *ajovem=raiz2, *q, *filho;
         int imbal;
 
   if (p==NULL) {                 /* Arvore vazia */
                  raiz2 = cria_no(chave);  /* Funcao para criacao de um novo no */
          return;
   }
 
/* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
   while (p!=NULL) {
                if (chave < p->dado)
                    q = p->esq;
             else q = p->dir;
          if (q!=NULL)
                    if (q->bal != 0) {
                        pajovem=p;
                ajovem=q;
          }
          pp = p;
          p = q;
   }
 
   q = cria_no(chave);
 
   if (chave<pp->dado)
                pp->esq=q;
          else pp->dir=q;
 
/* Balanceamento de todos os nós entre ajovem e q devem ser ajustados */
   if (chave<ajovem->dado)
                filho = ajovem->esq;
          else filho = ajovem->dir;
 
   p = filho;
 
   while (p!=q) {
                if (chave < p->dado) {
                    p->bal=1;
             p=p->esq;
                } else {
                                          p->bal = -1;
            p=p->dir;
                                          }
   }
 
   if (chave<ajovem->dado)
                imbal = 1;
          else imbal = -1;
 
   if (ajovem->bal==0) {          /*Não houve desbalanceamento */
                ajovem->bal=imbal;
          return;
   }
 
 
               if (ajovem->bal!=imbal) {   /*Não houve desbalanceamento */
                ajovem->bal=0;
          return;
   }
 
               /* Houve desbalanceamento */
   if (filho->bal == imbal) {
                p=filho;
          if (imbal==1)            /* Faz rotação simples */
           direita(ajovem);
                    else esquerda(ajovem);
      ajovem->bal=0;
          filho->bal=0;
   } else {
                           if (imbal==1) {          /*Faz rotação dupla */
                                   p=filho->dir;
              esquerda(filho);
                ajovem->esq=p;
              direita(ajovem);
                    } else {
              p=filho->esq;
              direita(filho);
              ajovem->dir=p;
              esquerda(ajovem);
             }
             if (p->bal==0) {
                ajovem->bal=0;
            filho->bal=0;
             } else {
                               if (p->bal == imbal) {
                                  ajovem->bal = - imbal;
                  filho->bal = 0;
                   } else {
                                  ajovem->bal = 0;
                  filho->bal = imbal;
                   }
             }
          p->bal=0;
   }
 
   if (pajovem == NULL)  /* Ajusta ponteiro do pai do ancestral mais jovem */
                  raiz2 = p;
          else if (ajovem==pajovem->dir)
                                               pajovem->dir = p;
                    else pajovem->esq = p;
 
   return;
}
 
/* Funcao para inserçao na arvore de busca binaria */
 
void insere_abb(int i){
         struct no *aux, *atual=NULL;
 
         aux = cria_no(i);
 
         if(raiz == NULL){
            raiz = aux;
            return;
         }
         atual = raiz;
         while(1){
 
               if(aux -> dado >= atual -> dado){ /* elemento deve ir pra direita */
                  if(atual -> dir == NULL){ /* elemento folha, achou o lugar para inserir */
                     atual -> dir = aux;
                 return;
                  }
                  atual = atual -> dir; /* passa para o proximo elemento */
               }
               else{ /* elemento deve ir para esquerda */
               if(atual -> esq == NULL){
                  atual -> esq = aux;
                  return;
                   }
                   atual = atual -> esq;
               }
         }
}
 
// Busca em Arvore
void busca(int i){
         struct no *atual=raiz;
 
         if(raiz==NULL) return;
 
 
     while(atual!=NULL){
        cont_arv_binaria++;
        if(atual->dado == i) return;
 
         if(i <= atual->dado) atual=atual->esq;
         else atual=atual->dir;
         }
 
}
 
//Busca em Arvore AVL
void busca_avl(int i){
         struct no *atual=raiz2;
 
         if(raiz==NULL){
            return;
            }
 
         while(atual!=NULL){
            cont_avl++;
        if(atual->dado == i)
               return;
 
         if(i < atual->dado) atual=atual->esq;
         else atual=atual->dir;
         }
         return;
 
}
 
void geradorVetor(){
        int i;
        srand(time(NULL));
    for(i=0;i<n;i++){
                vetor[i] = rand() % n;
                sorted[i] = vetor[i];
        }
}
 
void imprimirVetor(){
        int i;
    for(i=0;i<n;i++){
            printf("%d ", sorted[i]);
        }
}
 
int partition(int *v,int p,int r){
        int aux,piv,i,j;
 
        piv=v[p];
        i=p-1;
        j=r+1;
        while(1){
            do
                j=j-1;
        while(v[j]>piv);
            do
                i=i+1;
        while(v[i]<piv);
            if(i<j){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
            else
                return j;
        }
}
 
void quickSort(int *v,int p, int r){
        int q;
 
        if(p<r){
        q=partition(v,p,r);
        quickSort(v,p,q);
            quickSort(v,q+1,r);
        }
}
 
void sequencial (int chave){
        int i = 0;
        while (i < n){
            if (vetor [i] == chave){
                cont_seq ++;
                return;
            }
            cont_seq ++;
            i++;
        }
}
 
void binaria (int chave){
        int inicio = 0, fim = n -1, meio;
 
        while(inicio <= fim){
                meio = (inicio + fim)/ 2;
            if(sorted[meio] == chave){
                    cont_bin ++;
                    return;
                }
                if (chave > sorted[meio]){
                    cont_bin ++;
                    inicio = meio + 1;
                }
                else {
                    cont_bin ++;
                    fim = meio - 1;
                }
        }
        }
 
void zerarVariaveis(){
         cont_arv_binaria = 0;
         cont_avl = 0;
         cont_seq = 0;
         cont_bin = 0;
}
 
void mostrarResultado(float mS,float mB,float mAB,float mAVL){
        printf("***** Numero de Comparacoes *****\n");
        printf("Busca Sequencial: %.3f\n", mS);
        printf("Busca Binaria: %.3f\n", mB);
        printf("Busca Arvore Binaria: %.3f\n", mAB);
        printf("Busca Arvore AVL: %.3f\n", mAVL);
}
 
int main(){
        int i, num = 1000, chave;
        float mS = 0, mB = 0, mAB = 0, mAVL = 0;
        srand(time(NULL));
        geradorVetor();
    quickSort(sorted,0,n-1);
    for(i=0;i<n;i++){
            insere_bal(vetor[i]);
            insere_abb(vetor[i]);
        }
        while(num > 0){
            chave = rand() % n;
            sequencial(chave);
            binaria(chave);
            busca(chave);
            busca_avl(chave);
                mS += cont_seq/quant;
                mB += cont_bin/quant;
                mAB += cont_arv_binaria/quant;
                mAVL += cont_avl/quant;
            zerarVariaveis();
                num--;
        }
    mostrarResultado(mS,mB,mAB,mAVL);
        return 0;
}