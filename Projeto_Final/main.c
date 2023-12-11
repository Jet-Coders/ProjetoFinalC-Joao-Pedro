#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lib.h"



int main(){
    Lista *li;
    li = criaLista();
    int escolha, mod;
    char res,*nome;
    int x;

     printf("\n\n\tAbrindo dados armazenados...");
            Sleep(2); // pausa de 2 segundos
            limparTerminal();
            abrirDados(li);

    while(escolha != 7) {
        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
        printf("\n\n\tGRUPO ACME\n\n\tMENU - CLIENTES");
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
                mod=1;
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
                mod=1;
                break;
            case 6:
                deleteSelection(li);
                mod = 1;
                break;
            case 7:
                if(mod>0){
                    printf("\n\n\tDeseja salvar as ultimas modificacoes antes de sair? (Y/N)");
                    scanf(" %c", &res);
                    fflush(stdin);
                    if(res == 'Y' || res == 'y'){
                        salvaDados(li);
                    }else{
                        printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
                        printf("\n\n\tModificacoes nao salvas.\n");
                    }
                    break;
                }else{
                    printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
                    printf("\n\n\tNao existem alteracoes nos cadastros!");
                    printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

                    break;
                }
            default:
            printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");
            printf("\n\n\tEscolha nao valida!!");
            printf("\n\n\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*");

            break;
        }
}
}
