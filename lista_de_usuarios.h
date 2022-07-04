#ifndef TP_LED_2022_LISTA_DE_USUARIOS_H
#define TP_LED_2022_LISTA_DE_USUARIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Usuario {
    char *nome_usuario;
    int cpf_usuario;
    int senha_usuario;
    char *cargo_usuario;
    struct usuario *prox;
}usuario;

usuario * inicio = NULL;
usuario * fim = NULL;

int tam = 0;

void add_lis_us(char *nome_usuario, int cpf_usuario, int senha_usuario, char *cargo_usuario, int pos){

    if(pos >= 0 && pos <= tam){

        usuario * novo = malloc(sizeof(usuario));
        novo->nome_usuario = nome_usuario;
        novo->cpf_usuario = cpf_usuario;
        novo->senha_usuario = senha_usuario;
        novo->cargo_usuario = cargo_usuario;
        novo->prox = NULL;

        if(inicio == NULL){ 
            inicio = novo;
            fim = novo;
            tam++;
        }else if(pos == 0){ 
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }else if(pos == tam){ 
            fim->prox = novo;
            fim = novo;
            tam++;
        }else{ // "no meio"

            usuario * aux = inicio;
            for(int i = 0; i < pos-1; i++){
                aux = aux->prox;

            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tam++;

        }

    }else{
        printf("ERRO!!\n");
    }
}

int checar_usuario(int cpf, int senha , char *cargo){
    usuario * aux = inicio;
    int retorno;
    for(int i = 0; i < tam; i++){
        if(aux->cpf_usuario == cpf && aux->senha_usuario == senha && strcmp(aux->cargo_usuario, cargo) == 0){
            retorno = 0;
        }else if (aux->cpf_usuario != cpf || aux->senha_usuario != senha || strcmp(aux->cargo_usuario, cargo) != 0){
            aux = aux->prox;
        }else if (aux->prox == NULL){
            retorno = 1;
        }
    }
    return retorno;
}
#endif