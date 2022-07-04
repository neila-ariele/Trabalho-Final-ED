#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "fila.h"
#include "lista_de_usuarios.h"

int main(){

    add_lis_us("Letícia", 629875415, 54287, "secretaria", 0);
    add_lis_us("Carla", 231463415, 92736, "secretaria", 1);
    add_lis_us("Francisca", 987972415, 84326, "secretaria", 2);
    add_lis_us("João", 996415321, 74386, "entregador", 0);
    add_lis_us("Mateus", 698465538, 15297, "entregador", 0);
    add_lis_us("Carlos", 932415787, 44654, "entregador", 0);
    add_lis_us("Francisco", 852413897, 33287, "entregador", 0);
    add_lis_us("José", 524162547, 56431, "entregador", 0);

    int resp = -1;
    while(resp != 0){
        printf("\n*************** SISTEMA DE ENCOMENDA DE LIVRO ***************\n");
        printf("* 1 - Encomendar um livro.                                  *\n");
        printf("* 2 - Remover uma encomenda de livro.                       *\n");
        printf("* 3 - Remover um pedido de livro.                           *\n");
        printf("* 0 - Sair do sistema!                                      *\n");
        printf("*************************************************************\n");
        printf("Digite a funcionalidade desejada:");
        scanf("%d", &resp);
        fflush (stdin);
        if(resp == 1) {
            //encomendar um livro
            printf("\n***************ENCOMENDAR UM LIVRO***************\n\n");

            int ident = gera_id();

            char* nome = malloc(sizeof (char));
            printf("Digite o nome do aluno:");
            scanf("%[^\n]s", nome);
            scanf("%*c");

            int matricula;
            printf("Digite a matrícula do aluno:");
            scanf("%d", &matricula);
            scanf("%*c");

            char* descricao = malloc(sizeof (char));
            printf("Digite a Descrição do livro:");
            scanf("%[^\n]s", descricao);
            scanf("%*c");

            add_abb(ident, nome, matricula, descricao);

        }else if (resp==2){
            printf("\n**************REMOVER UMA ENCOMENDA**************\n\n");
            printf("*****************LOGIN DO USUÁRIO****************\n\n");

            int cpf_usu_sec;
            printf("Digite o cpf do usuário:");
            scanf("%d", &cpf_usu_sec);
            scanf("%*c");

            int senha_usu_sec;
            printf("Digite a senha do usuário:");
            scanf("%d", &senha_usu_sec);
            scanf("%*c");

            char* cargo = malloc(sizeof (char));
            printf("Qual o seu cargo:");
            scanf("%[^\n]s", cargo);
            scanf("%*c");

            printf("\n*************************************************\n");

            int check = checar_usuario(cpf_usu_sec,senha_usu_sec, cargo);

            if(check==0){
                printf("\n*********LISTA DE ENCOMENDAS CADASTRADAS*********\n\n");
                in_ordem(raiz);
                printf("*************************************************\n");

                int identificador;

                printf("Qual o id da encomenda que quer remover? ");
                scanf("%d", &identificador);

                raiz =  remover_abb(identificador,raiz);

                printf("\n*****CADASTRO DE ENCOMENDA NA FILA DE PEDIDOS*****\n\n");

                int identificador_fila;
                printf("Digite o identificador:");
                scanf("%d", &identificador_fila);
                scanf("%*c");

                char* nome_fila = malloc(sizeof (char));
                printf("Digite o nome do aluno:");
                scanf("%[^\n]s", nome_fila);
                scanf("%*c");

                int matricula_fila;
                printf("Digite a matrícula do aluno:");
                scanf("%d", &matricula_fila);
                scanf("%*c");

                char* descricao_fila = malloc(sizeof (char));
                printf("Digite a Descrição do livro:");
                scanf("%[^\n]s", descricao_fila);
                scanf("%*c");

                char* campus_livro_fil = malloc(sizeof (char));
                printf("Campus do livro:");
                scanf("%[^\n]s", campus_livro_fil);
                scanf("%*c");

                char* campus_aluno_fil = malloc(sizeof (char));
                printf("Campus do aluno:");
                scanf("%[^\n]s", campus_aluno_fil);
                scanf("%*c");

                char* resp_enc_fila = malloc(sizeof (char));
                printf("Responsável pela encomenda:");
                scanf("%[^\n]s", resp_enc_fila);
                scanf("%*c");

                int prioridade_fila;
                printf("Digite a prioridade da encomenda entre 1 e 100:");
                scanf("%d", &prioridade_fila);
                scanf("%*c");

                add_fila(identificador_fila, nome_fila, matricula_fila,
                         descricao_fila, campus_livro_fil,campus_aluno_fil, resp_enc_fila, prioridade_fila);

            }else{
                printf("Usuario não autorizado");
            }

        }else if(resp==3){
            printf("\n****************REMOVER UM PEDIDO****************\n\n");
            printf("*****************LOGIN DO USUÁRIO****************\n\n");

            int cpf_usu_ent;
            printf("Digite o cpf do usuário:");
            scanf("%d", &cpf_usu_ent);
            scanf("%*c");

            int senha_usu_ent;
            printf("Digite a senha do usuário:");
            scanf("%d", &senha_usu_ent);
            scanf("%*c");

            char* cargo = malloc(sizeof (char));
            printf("Qual o seu cargo:");
            scanf("%[^\n]s", cargo);
            scanf("%*c");

            printf("\n*************************************************\n\n");

            int check = checar_usuario(cpf_usu_ent,senha_usu_ent, cargo);

            if(check==0){
                PEDIDO *retorno =remover_fila();
                if(retorno != NULL){
                    printf("Pedido removido com sucesso\n");
                }else{
                    printf("Não há pedidos a serem removidos\n");
                }
            }else{
                printf("Usuario não autorizado");
            }
        }else if (resp==0){
            return 0;
        }
    }
    return 0;
}


