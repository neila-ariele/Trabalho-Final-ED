#include <stdio.h>
#include <stdlib.h>

typedef struct pedido {
    int identificador_fila;
    char *nome_alunof;
    int matricula_alunof;
    char *descricaof;
    char *campus_livro;
    char *campus_aluno;
    char *responsavel_enc;
    int prioridade;
    struct pedido *prox;
} PEDIDO;


PEDIDO *inicio_fila = NULL;
PEDIDO *fim_fila = NULL;
int tam_fila = 0;

void add_fila(int identificador, char *nome_aluno, int matricula, char descricao, char *campus_livro,
              char *campus_aluno, char *responsavel, int prioridade) {

    PEDIDO *novo_ped = malloc(sizeof(PEDIDO));
    novo_ped->identificador_fila = identificador;
    novo_ped->nome_alunof = nome_aluno;
    novo_ped->matricula_alunof = matricula;
    novo_ped->descricaof = descricao;
    novo_ped->campus_livro = campus_livro;
    novo_ped->campus_aluno = campus_aluno;
    novo_ped->responsavel_enc = responsavel;
    novo_ped->prioridade = prioridade;
    novo_ped->prox = NULL;

    if (inicio_fila == NULL) { //fila vazia
        inicio_fila = novo_ped;
        fim_fila = novo_ped;
        tam_fila++;
    }else if(inicio_fila->prioridade < novo_ped->prioridade){
        novo_ped->prox = inicio_fila;
        inicio_fila = novo_ped;
    }else if (fim_fila->prioridade > novo_ped->prioridade){
        fim_fila->prox = novo_ped;
        fim_fila = novo_ped;
        tam_fila++;
    }else{
        PEDIDO *aux_add_fila = inicio_fila;
        while(aux_add_fila->prox != NULL && aux_add_fila->prox->prioridade > novo_ped->prioridade){
            aux_add_fila = aux_add_fila->prox;
        }
        novo_ped->prox = aux_add_fila->prox;
        aux_add_fila->prox = novo_ped;
    }
}


void imprimir_fila() {
    PEDIDO *aux_print = inicio_fila;
    while (aux_print != NULL){
        printf("Identificador: %d\n", aux_print->identificador_fila);
        printf("Nome do aluno: %s\n", aux_print->nome_alunof);
        printf("Matrícula: %d\n", aux_print->matricula_alunof);
        printf("Nome do aluno: %s\n", aux_print->descricaof);
        printf("Campus do Livro: %d\n", aux_print->campus_livro);
        printf("Campus do Aluno: %d\n", aux_print->campus_aluno);
        printf("Responsável pela encomenda: %d\n", aux_print->responsavel_enc);
        printf("Prioridade: %d\n", aux_print->prioridade);
        aux_print = aux_print->prox;
    }
}

PEDIDO *remover_fila() {

    if (inicio_fila == NULL) { //remover do antigo inicio da lista!
        return NULL;
    }else if (tam_fila ==1){
        PEDIDO *lixo = inicio_fila;
        inicio_fila = NULL;
        fim_fila = NULL;
        free(lixo);
        tam_fila--;
        return lixo;
    }else {
        PEDIDO *lixo = inicio_fila;
        inicio_fila = inicio_fila->prox;
        free(lixo);
        tam_fila--;
        return lixo;
    }
}

/*}else if(resp == 2){
                //remover uma encomenda de livro da ABB (id)
                //para remover eu preciso:
                //1 - visualizar as encomendas (in_ordem)
                in_ordem();
                //2 - verificar o usuario
                printf(" Digite seu cpf:\n");
                char cpf[100];
                scanf("%s", &cpf);
                printf(" Digite sua senha:\n");
                char senha[100];
                scanf("%s", &senha);
                //int retorno = verificar(cpf, senha);
                if(retorno == 1){
                    //3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
                    //4 - setar novos dados (faltando)
                    //5 - add_fila(....);
                }else if(resp == 3){

                    //2 - verificar o usuario
                        printf(" Digite seu cpf:\n");
                        char cpf[100];
                        scanf("%s", &cpf);
                        printf(" Digite sua senha:\n");
                        char senha[100];
                        scanf("%s", &senha);
                        //int retorno = verificar(cpf, senha);
                        if(retorno == 1){
                            //remover da fila de prioridade
                        }
                }

            }*/

/*
add_fila(1,"Alef",654,"quixada","russas","Fatima",10);
add_fila(2,"Alef",654,"quixada","russas","Fatima",9);
add_fila(3,"Alef",654,"quixada","russas","Fatima",8);
add_fila(4,"Alef",654,"quixada","russas","Fatima",11);
*/