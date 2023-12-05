#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lib.h"

typedef struct elemento{
    CLIENTE dados;
    struct elemento *prox;
}ELEM;

Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void limparTerminal() {
    system("cls");
}

CLIENTE pegaDados(){

    CLIENTE no;
    printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    printf("\n\n\tINSERINDO DADOS");
    printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

    printf("\n\tInsira o codigo do cliente: ");
    scanf("%d", &no.codigo);
    while (getchar() != '\n');


    printf("\n\tDigite o nome do cliente: ");
    fgets(no.nome, sizeof(no.nome), stdin);
    fflush(stdin);

    printf("\n\tDigite a empresa do cliente: ");
    fgets(no.empresa, sizeof(no.empresa), stdin);
    fflush(stdin);


    printf("\n\tDigite o departamento do cliente: ");
    fgets(no.departamento, sizeof(no.departamento), stdin);
    fflush(stdin);

    printf("\n\tDigite o telefone do cliente: ");
    fgets(no.telefone, sizeof(no.telefone), stdin);
    fflush(stdin);


    printf("\n\tDigite o celular do cliente: ");
    fgets(no.celular, sizeof(no.celular), stdin);
    fflush(stdin);

    printf("\n\tDigite o email do cliente: ");
    fgets(no.email, sizeof(no.email), stdin);
    fflush(stdin);

    printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

    limparTerminal();


    return no;
}

int listaVazia(Lista *li){

    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;

}

void insere_lista_ordenada(Lista *li){
    int result;
    if(li == NULL){
        result = 0;
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        result = 0;
    }
    no->dados = pegaDados();
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        result = 1;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.codigo < no->dados.codigo){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        result = 1;
    }

    if(result == 1){
        printf("\n\tInserido ordenadamente com sucesso!");
    }else{
        printf("\n\tNao foi possivel inserir ordenamente");
    }

    printf("\n\n\tPressione Enter para continuar...");
    getchar();

    limparTerminal();


}

void exibeCliente(CLIENTE dados){

    printf("\n\n\tCodigo: %d", dados.codigo);
    printf("\n\n\tNome: %s", dados.nome);
    printf("\n\n\tEmpresa: %s", dados.empresa);
    printf("\n\n\tDepartamento: %s", dados.departamento);
    printf("\n\n\tTelefone: %s", dados.telefone);
    printf("\n\n\tCelular: %s", dados.celular);
    printf("\n\n\tEmail: %s", dados.email);




}

void relatorioTotal(Lista *li){
    int result = 1;
    if(li == NULL){
        result = 0;
    }

    if(result == 1){
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tRELATORIO TOTAL");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

        ELEM *no = *li;
        while(no != NULL){
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        exibeCliente(no->dados);
        no = no->prox;
        printf("\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

        }
    }else{
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("Não foi possivel listar os clientes");
        printf("\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    }
    printf("\n\n\tPressione Enter para continuar...");
    getchar();
    limparTerminal();

}

void consultaCodigo(Lista *li){

    int result = 1;
    int codigo;
    ELEM *no = *li;

    if(li == NULL){
        result = 0;
    }

    if(result == 1){

        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tRELATORIO POR CODIGO");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tInsira o Codigo do cliente desejado:");
        scanf("%d", &codigo);
        fflush(stdin);
    }

        while(no != NULL && no->dados.codigo != codigo){
        no = no->prox;
    }

    if(no == NULL){
        printf("\n\n\tCodigo nao encontrado!");
        result = 0;
    }else{
        exibeCliente(no->dados);
    }

    //printf("\n\n\tPressione Enter para continuar...");
    //getchar();
    //limparTerminal();


}

void consultaNome(Lista *li){


    int result = 1;
    char nome[100];
    char aux[100];

    if(li == NULL){
        result = 0;
    }

    if(result == 1){

        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tRELATORIO POR NOME");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tInsira o Nome do cliente desejado: ");
        fgets(nome, sizeof(nome), stdin);
        fflush(stdin);
        strupr(nome);
        result = 0;
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

    }
    ELEM *no = *li;
    while(no != NULL){
        strcpy(aux, no->dados.nome);
        strupr(aux);
        if(strcmp(aux, nome) == 0){
            exibeCliente(no->dados);
            printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

            result = 1;
        }
        no = no->prox;

    }

    if(no == NULL && result != 1){
        printf("\n\n\tNome nao encontrado!");
        result = 0;
    }

    printf("\n\n\tPressione Enter para continuar...");
    getchar();
    limparTerminal();
}

void editaContato(Lista *li){

    //INCOMPLETA

    int result = 1;
    int codigo;
    ELEM *no = *li;

    if(li == NULL){
        result = 0;
    }

    if(result == 1){

        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tEDICAO DE DADOS");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tInsira o Codigo do cliente desejado:");
        scanf("%d", &codigo);
        fflush(stdin);
    }

        while(no != NULL && no->dados.codigo != codigo){
        no = no->prox;
    }

    if(no == NULL){
        printf("\n\n\tCodigo nao encontrado!");
        result = 0;
    }else{
        exibeCliente(no->dados);
        printf("Tem certeza que deseja alterar os dados do cliente");
    }



}
