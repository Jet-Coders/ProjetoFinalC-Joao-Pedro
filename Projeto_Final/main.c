#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lib.h"


int main()
{
    Lista *li;
    li = criaLista();
    char resp = 'Y';
    int escolha;


    while(resp == 'Y' || resp == 'y') {
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tMENU - CLIENTES");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tEscolha uma opcao:\n");
        printf("\n\t1. Inserir novo contato.\n");
        printf("\n\t2. Gerar Relatorio Total\n");
        printf("\n\t3. Gerar Relatorio Individual(Por Codigo)\n");
        printf("\n\t4. Gerar Relatorio Individual(Por Nome)\n");
        printf("\n\t5. Editar Dados\n");
        printf("\n\t6. Remover Cliente\n");
        printf("\n\t7. Sair do programa\n");
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\t Insira a opcao desejada: ");
        scanf("%d", &escolha);
        limparTerminal();


    switch (escolha) {
        case 1:
            insere_lista_ordenada(li);
            break;
        case 2:
            relatorioTotal(li);
            break;
        case 3:
            consultaCodigo(li);
            break;
        case 4:
            consultaNome(li);
            break;
        case 5:
            editaContato(li);
            break;
        case 6:
            deletaCliente(li);
            break;
        case 7:
            printf("\n\n\tNada aqui ainda!");
            break;
    }
    }
    return 0;
}
