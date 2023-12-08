#ifndef lib_h
#define lib_h
    #include <stdio.h>
    #include <stdlib.h>

    /************************
    //Declaracoes iniciais;
    ************************/

     //Criando um alias ponteiro da struct elemento
    typedef struct elemento* Lista;
    //Cria um ponteiro para ponteiro do tipo Lista para iniciar uma lista
    Lista *criaLista();
    //Criando um alias ponteiro da struct elemento
    typedef struct cliente{
        int codigo;
        char nome[100];
        char empresa[50];
        char departamento[50];
        char telefone[11];
        char celular[11];
        char email[50];
    }CLIENTE;

   
    /************************
    //Edicao de clientes;
    ************************/

    //Insere clientes dentro da lista
    void insere_lista_ordenada(Lista *li);
    //Deletar cliente diretamente;
    int deleteCli(Lista *li, int codigo);
    //Menu para deletar cliente;
    void deleteSelection(Lista *li);
    //Função para apresentar relatorio dos usuarios cadastrados;
    void relatorioTotal(Lista *li);
    //Função para consultar usuario atraves de codigo;
    void consultaCodigo(Lista *li);
    //Função para consultar usuario atraves do nome;
    void consultaNome(Lista *li);
    //Função para editar dados dos usuarios;
    void editaContato(Lista *li);

    /************************
    //Utilitarios do sistema;
    ************************/

    //Função para tornar palavras maiúsculas(para funcionar em Mac e Windows)
    char *strupper(char *str);
    //Função para limpar a tela(para funcionar em Mac e Windows)
    void limparTerminal();
    //Função para verificar o tamanho da lista
    int tamanhoLista(Lista *li);
    //Função para salvar os registros no arquivo data.bin, caso o arquivo nao exista ele cria um;
    void salvaDados(Lista *li);
    //Função para abrir o arquivo data.bin e incorporar seus registros no sistema.
    void abrirDados(Lista *li);
    

#endif
