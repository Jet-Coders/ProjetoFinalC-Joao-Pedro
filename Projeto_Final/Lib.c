#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

void limparTerminal(){
    printf("\n\n\tPressione Enter para continuar...");
    getchar();
    system("cls || clear");
}

CLIENTE pegaDados(){

    CLIENTE no;
    printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    printf("\n\n\tINSERINDO DADOS");
    printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

    printf("\n\tInsira o codigo do cliente: ");
    scanf("%d", &no.codigo);
    fflush(stdin);


    printf("\n\tDigite o nome do cliente: ");
    fgets(no.nome, sizeof(no.nome), stdin);

    printf("\n\tDigite a empresa do cliente: ");
    fgets(no.empresa, sizeof(no.empresa), stdin);

    printf("\n\tDigite o departamento do cliente: ");
    fgets(no.departamento, sizeof(no.departamento), stdin);

    printf("\n\tDigite o telefone do cliente: ");
    fgets(no.telefone, sizeof(no.telefone), stdin);

    printf("\n\tDigite o celular do cliente: ");
    fgets(no.celular, sizeof(no.celular), stdin);

    printf("\n\tDigite o email do cliente: ");
    fgets(no.email, sizeof(no.email), stdin);

    printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

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
    int result = 1;
    ELEM *aux = *li;
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));

    if(li == NULL){
        result = 0;
    }
    if(no == NULL){
        result = 0;
    }
    no->dados = pegaDados();

    while(aux != NULL){
        if(aux->dados.codigo == no->dados.codigo){
        printf("\n\n\tJa existe um cliente com esse codigo!!");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        result = 0;
        }
        aux = aux->prox;
    }

    if(result == 1){

    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
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
    }
    if(result == 1){
        printf("\n\n\tInserido ordenadamente com sucesso!");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    }else{
        printf("\n\n\tNao foi possivel inserir ordenamente");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

    }
    limparTerminal();

}
}

void exibeCliente(CLIENTE dados){

    printf("\n\n\tCodigo: %d", dados.codigo);
    printf("\n\n\tNome: %s", dados.nome);
    printf("\n\tEmpresa: %s", dados.empresa);
    printf("\n\tDepartamento: %s", dados.departamento);
    printf("\n\tTelefone: %s", dados.telefone);
    printf("\n\tCelular: %s", dados.celular);
    printf("\n\tEmail: %s", dados.email);
}

void relatorioTotal(Lista *li){
    int result = 1;

    if(*li == NULL){
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
        printf("\n\n\tNao foi possivel listar os clientes");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    }
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
    }

        while(no != NULL && no->dados.codigo != codigo){
        no = no->prox;
    }

    if(no == NULL){
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tCodigo nao encontrado!");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

        result = 0;
    }else{
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        exibeCliente(no->dados);
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

    }
    
    limparTerminal();


}

int buscaNome(Lista *li, const char *nome) {
    ELEM *atual = *li;
    while (atual != NULL) {
        if (strstr(atual->dados.nome, nome) != NULL) {
            printf("%s\n",atual->dados.nome);
            
        }
        atual = atual->prox;
    }
        return 0;
}

void consultaNome(Lista *li){
    int result = 1;
    char nome[100],aux[100];

    if(li == NULL){
        result = 0;
    }

    if(result == 1){
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tRELATORIO POR NOME");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tInsira o Nome do cliente desejado: ");
        scanf("%[^\n]", nome);
        getchar();
        strupper(nome);
        result = 0;
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        
    }
    ELEM *no = *li;
    while(no!= NULL){
        strcpy(aux, no->dados.nome);
        strupper(aux);
        if(strstr(aux, nome) != NULL){
            exibeCliente(no->dados);
            printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
            result = 1;
        }
        no = no->prox;
    }
        
    if(no == NULL && result != 1){
        printf("\n\n\tNome nao encontrado!");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

        result = 0;
    }

    limparTerminal();
}

void editaContato(Lista *li){

    int result = 1;
    int codigo;
    ELEM *no = *li;

    if(*li == NULL){
        result = 0;
    }

    if(result == 1){

        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tEDICAO DE DADOS");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tInsira o Codigo do cliente desejado:");
        scanf("%d", &codigo);
    }

        while(no != NULL && no->dados.codigo != codigo){
        no = no->prox;
    }

    if(no == NULL){
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tCodigo nao encontrado!");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        result = 0;
    }else{
        exibeCliente(no->dados);
        char resp;
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tTem certeza que deseja alterar os dados do cliente?(Y/N)");
        scanf(" %c", &resp);
        if(resp == 'Y' || resp == 'y'){
            deleteCli(li, codigo);
            insere_lista_ordenada(li);
            result = 1;
        }else{
            printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
            printf("\n\n\tCliente nao editado...");
            printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        }

    }

}

void deleteSelection(Lista *li){

    int result = 1;
    int codigo, x;
    char resp;

    if(*li == NULL){
        result = 0;
    }

    if(result == 1){

        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tDELETAR CLIENTE");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tInsira o Codigo do cliente desejado:");
        scanf("%d", &codigo);


        printf("\n\n\tTem certeza que deseja excluir o cliente?(Y/N)");
        scanf(" %c", &resp);
        if(resp == 'Y' || resp == 'y'){
        x = deleteCli(li, codigo);
            if(x == 1){
                printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
                printf("\n\n\tCliente deletado com sucesso...");
                printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
            }else{
                printf("\n\n\tErro ao deletar cliente...");
                printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");


            }
        }else{
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tCliente nao deletado...");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        }
    }
    else{
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tErro ao deletar cliente...");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

    }
    fflush(stdin);
    limparTerminal();

}

int deleteCli(Lista *li, int codigo){

        ELEM *ant, *no = *li;
        while(no != NULL && no->dados.codigo != codigo){
            ant = no;
            no = no->prox;
        }
        if(no == NULL){
            printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
            printf("\n\n\tCliente nao encontrado");
            printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
            return 0;
        }

        if(no == *li){
        *li = no->prox;

        }else{
        ant->prox = no->prox;

        }
        free(no);
        return 1;
}

char *strupper(char *str){
    char *ptr = str;
    while (*ptr != '\0') {
        *ptr = toupper((unsigned char)*ptr);
        ptr++;
    }
    return str;
}

int tamanhoLista(Lista *li){
    if(li == NULL){
        return 0;
    }
    int acum;
    ELEM *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}


void salvaDados(Lista *li){
    int result = 1;
    FILE *arq = fopen("data.bin", "w+b");
    if(arq == NULL){
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tErro ao salvar dados!");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        limparTerminal();
        result = 0;
    }
    ELEM *cliente = *li;
    while(cliente != NULL){
        fwrite(cliente,sizeof(ELEM),1,arq);
        cliente = cliente->prox;
    }
    fclose(arq);
    if(result == 1){
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tDados salvos com sucesso!");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        limparTerminal();
    }

}

void abrirDados(Lista *li){
    int result;
    FILE *arq = fopen("data.bin", "rb");
    if(arq == NULL){
       printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tErro na abertura dos dados!");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        limparTerminal();
        exit(1);
    }
        ELEM cliente;

        while (fread(&cliente, sizeof(ELEM), 1, arq) == 1) {
            ELEM *no = (ELEM *)malloc(sizeof(ELEM));
            if (no == NULL) {
                result = 0;
            }
            *no = cliente;
            no->prox = NULL;
            if (listaVazia(li)) {
                *li = no;
            } else {
                ELEM *ant, *atual = *li;
                while (atual != NULL && atual->dados.codigo < no->dados.codigo) {
                    ant = atual;
                    atual = atual->prox;
                }
                if (atual == *li) {
                    no->prox = *li;
                    *li = no;
                    result = 1;
                } else {
                    no->prox = ant->prox;
                    ant->prox = no;
                    result = 1;
                }
            }
        }

        fclose(arq);


    if(result == 1){
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tDados inseridos com sucesso");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
    }
    fclose(arq);

}

