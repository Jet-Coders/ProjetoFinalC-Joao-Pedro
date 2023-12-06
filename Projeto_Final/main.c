#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lib.h"

int main()
{
    Lista *li;
    li = criaLista();

    insere_lista_ordenada(li);
    insere_lista_ordenada(li);

    //consultaCodigo(li);
    //consultaNome(li);
    relatorioTotal(li);
    deletaCliente(li);
    relatorioTotal(li);

    return 0;
}
