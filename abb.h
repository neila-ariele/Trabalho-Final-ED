#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int tam_abb = 0;

typedef struct Vertice { 
    int id;
    char *nome_aluno;
    int matricula;
    char *descricao;
    struct Vertice *esq;
    struct Vertice *dir;
} VERTICE;

VERTICE *raiz = NULL; 

int gera_id() {
    int id;
    if(tam_abb==0){
        id = 1000;
    }else if((tam_abb%2) == 0){ 
        srand( (unsigned)time(NULL));
        id =rand() % 1000;
    }else{
        srand( (unsigned)time(NULL));
        id = 1001 + ( rand() % 999 );
    }
    return id;
};

VERTICE *buscar_add(int id, VERTICE *aux_add) {
    if (aux_add != NULL) {
        if (aux_add->id == id) {
            return aux_add;
        } else if (id < aux_add->id) {
            if (aux_add->esq != NULL) {
                return buscar_add(id, aux_add->esq);
            } else {
                return aux_add;
            }
        } else if (id > aux_add->id) {
            if (aux_add->dir != NULL) {
                return buscar_add(id, aux_add->dir);
            } else {
                return aux_add;
            }
        }
    } else {
        return NULL;
    }
}

void add_abb(int id, char *nome_aluno, int matricula, char *descricao) {

    VERTICE *aux = buscar_add(id, raiz);

    if (aux != NULL && aux->id == id) { 
        printf("Insercao invalida!\n");
    } else {
        VERTICE *novo = malloc(sizeof(VERTICE));
        novo->id = id;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->esq = NULL;
        novo->dir = NULL;

        if (aux == NULL) {
            raiz = novo;
        } else {// 
            if (id < aux->id) {
                aux->esq = novo;
            } else {
                aux->dir = novo;
            }
        }
        tam_abb++;
    }
}

VERTICE *remover_abb(int id, VERTICE *aux_rem){
    if(aux_rem == NULL){
        return NULL;
    }else if (id < aux_rem->id){
        aux_rem->esq = remover_abb(id,aux_rem->esq);
    }else if (id > aux_rem->id){
        aux_rem->dir = remover_abb(id,aux_rem->dir);
    }else{
        //nó sem filhos
        if(aux_rem->esq == NULL && aux_rem->dir == NULL){
            //free(aux_rem);
            aux_rem = NULL;
        }else if (aux_rem->esq == NULL){
            //free(aux_rem);
            aux_rem = aux_rem->dir;
        }else if (aux_rem->dir == NULL){
            //free(aux_rem);
            aux_rem = aux_rem->esq;
        }else{
            //Nó tem dois filhos
            VERTICE *aux_dois_fi = aux_rem->esq;
            while (aux_rem->dir != NULL){
                aux_dois_fi = aux_dois_fi->dir;
            }
            aux_rem->id = aux_dois_fi->id;
            aux_rem->nome_aluno = aux_dois_fi->nome_aluno;
            aux_rem->matricula = aux_dois_fi->matricula;
            aux_rem->descricao = aux_dois_fi->descricao;
            int idi = aux_dois_fi->id;
            aux_rem->esq = remover_abb(idi,aux_rem->esq);
        }
    }
    return aux_rem;
}



void in_ordem(VERTICE *aux){
    if (aux->esq != NULL) {
        in_ordem(aux->esq);
    }
    printf("id: %d\n", aux->id);
    printf("nome: %s\n", aux->nome_aluno);
    printf("matrícula: %d\n", aux->matricula);
    printf("descrição: %s\n\n", aux->descricao);
    if (aux->dir != NULL) {
        in_ordem(aux->dir);
    }
}
