#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sgc.h"

char linha[100];

struct Leitura {
    char dado1[51];
    char dado2[51];
    char dado3[51];
};

struct UsuariosLogin {
    char nome[51];        // Maior tamanho para acomodar 50 caracteres + caractere nulo
    char senha[51];       // Maior tamanho para acomodar 50 caracteres + caractere nulo
    char privilegio[2];   // Aumente o tamanho para acomodar "a" ou "c" e o caractere nulo '\0'
};

struct Usuarios {
    char nome[51];        // Maior tamanho para acomodar 50 caracteres + caractere nulo
    char senha[51];       // Maior tamanho para acomodar 50 caracteres + caractere nulo
    char privilegio[2];   // Aumente o tamanho para acomodar "a" ou "c" e o caractere nulo '\0'
};

struct Produto {
    char nome[51];        // Maior tamanho para acomodar 50 caracteres + caractere nulo
    float preco;
    int quantidade;
};

void adicionarUsuario() {
    FILE *usuariosTxt;
    usuariosTxt = fopen("usuarios.txt", "a"); // Modo "a" para acrescentar ao arquivo

    if (usuariosTxt == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        return;
    }

    struct UsuariosLogin usuario;

    printf("Informe o nome do novo usuario: ");
    scanf("%50s", usuario.nome);

    printf("Informe a senha do novo usuario: ");
    scanf("%50s", usuario.senha);

    // Limpar o buffer após a leitura do inteiro
    while (getchar() != '\n');

    printf("Informe o privilégio do novo usuario (a = admin / c = comum): ");
    scanf("%1s", usuario.privilegio);

    fprintf(usuariosTxt, "%s %s %s\n", usuario.nome, usuario.senha, usuario.privilegio);
    fclose(usuariosTxt);

    printf("Usuario cadastrado com sucesso.\n");
    return;
}

void adicionarProduto() {
    FILE *estoqueTxt;
    estoqueTxt = fopen("estoque.txt", "w+"); // Modo "a" para acrescentar ao arquivo

    if (estoqueTxt == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        return;
    }

    struct Produto produtos;

    printf("Informe o nome do novo produto: ");
    scanf("%50s", produtos.nome);

    printf("Informe o preço do novo produto: ");
    scanf("%f", &produtos.preco);

    // Limpar o buffer após a leitura do float
    while (getchar() != '\n');

    printf("Informe a quantidade em estoque do novo produto: ");
    scanf("%d", &produtos.quantidade);

    // Limpar o buffer após a leitura do inteiro
    while (getchar() != '\n');

    fprintf(estoqueTxt, "%s %.2f %d\n", produtos.nome, produtos.preco, produtos.quantidade);
    fclose(estoqueTxt);

    printf("Produto cadastrado com sucesso.\n");
}

void autenticar() {
    FILE *usuariosTxt;
    usuariosTxt = fopen("usuarios.txt", "r");

    if (usuariosTxt == NULL) {
        printf("ERRO AO ABRIR ARQUIVO!\n");
        return;
    }

    char nomeUsuario[51];          // Maior tamanho para acomodar 50 caracteres + caractere nulo
    char senhaUsuario[51];         // Maior tamanho para acomodar 50 caracteres + caractere nulo
    char privilegioUsuario[2];

    printf("Digite o nome de usuario: ");
    scanf("%50s", nomeUsuario);

    printf("Digite a senha: ");
    scanf("%50s", senhaUsuario);

    printf("Digite o caractere de privilegio (a = admin / c = comum): ");
    scanf("%1s", privilegioUsuario);

    struct Usuarios usuario;

    while (fscanf(usuariosTxt, " %50s %50s %1s", usuario.nome, usuario.senha, usuario.privilegio) != EOF) {
        if (strcmp(usuario.nome, nomeUsuario) == 0 &&
            strcmp(usuario.senha, senhaUsuario) == 0 &&
            strcmp(usuario.privilegio, privilegioUsuario) == 0) {
            printf("Usuario autenticado com sucesso.\n");
            break;
        }
    }

    if (feof(usuariosTxt)) {
        printf("Usuario nao encontrado ou credenciais incorretas.\n");
    }

    fclose(usuariosTxt);

    return;
}

void excluirUsuario(){
    FILE *usuariosTxt, *newUsuariosTxt;
    usuariosTxt = fopen("usuarios.txt", "r");
    struct UsuariosLogin usuarioDeletar;
    struct UsuariosLogin usuarios;
    
    if(usuariosTxt == NULL){
        printf("ERRO AO ABRIR O ARQUIVO");
    }

    newUsuariosTxt = fopen("temp.txt", "w+");

    if(newUsuariosTxt == NULL){
        printf("ERRO AO CRIAR NOVO ARQUIVO");
    }
    
    printf("Informe o nome do usuario a ser deletado: ");
    scanf("%s", usuarioDeletar.nome);

    printf("Informe a senha do usuario a ser deletado: ");
    scanf("%s", usuarioDeletar.senha);

    printf("Informe o privilegio do usuario a ser deletado: ");
    scanf("%s", usuarioDeletar.privilegio);

    while (fscanf(usuariosTxt, "%s %s %s", usuarios.nome, usuarios.senha, usuarios.privilegio) != EOF)
    {
        if(strcmp(usuarioDeletar.nome, usuarios.nome) != 0){
            fprintf(newUsuariosTxt, "%s %s %s", usuarios.nome, usuarios.senha, usuarios.privilegio);
        }
    }

    if (feof(usuariosTxt)) {
        printf("Usuario não encontrado ou credenciais incorretas.\n");
    }
    
    fclose(usuariosTxt);
    fclose(newUsuariosTxt);

    if(remove("usuarios.txt") != 0){
        printf("ERRO AO APAGAR ARQUIVO ORIGINAL");
        return;
    }

    if(rename("temp.txt", "usuarios.txt") != 0){
        printf("ERRO AO RENOMEAR ARQUIVO");
    }

}

void listarProdutos(){
    FILE *produtosTxt;
    produtosTxt = fopen("estoque.txt", "r+");

    if(produtosTxt == NULL){
        printf("ERRO AO ABRIR O ARQUIVO");
    }    

    struct Leitura produtos;

    printf("\n=== PRODUTOS EM ESTOQUE ===\n");

    while (fgets(linha, sizeof(linha), produtosTxt) != NULL)
    {
        printf("\nPRODUTO - PRECO - QUANTIDADE\n");
        printf("%s\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n", linha);
    }
    
    fclose(produtosTxt);
    
}

void listarUsuarios(){
    FILE *usuariosTxt;
    usuariosTxt = fopen("usuarios.txt", "r+");

    if(usuariosTxt == NULL){
        printf("ERRO AO ABRIR O ARQUIVO");
    }    

    struct Leitura produtos;

    printf("\n=== USUARIOS CADASTRADOS ===\n");

    while (fgets(linha, sizeof(linha), usuariosTxt) != NULL)
    {
        printf("\nNOME - SENHA - PRIVILEGIO\n");
        printf("%s\n=-=-=-=-=-=-=-=-=-=-=-=-==-=-=\n\n", linha);
    }
    
    fclose(usuariosTxt);
    
}

void deletarProduto(){
    FILE *estoqueOriginalTxt, *novoEstoqueTxt;
    struct Leitura produto;
    char produtoDeletar[50];

    estoqueOriginalTxt = fopen("estoque.txt", "r");

    if(estoqueOriginalTxt == NULL){
        printf("ERRO AO ABRIR ARQUIVO");
    }

    novoEstoqueTxt = fopen("temp.txt", "w");

    if (novoEstoqueTxt == NULL)
    {
        printf("Erro ao criar novo arquivo");
    }
    
    printf("Informe o nome do produto a ser excluido: ");
    scanf("%s", produtoDeletar);
    
    while (fscanf(estoqueOriginalTxt, "%s %s %s", produto.dado1, produto.dado2, produto.dado3) != EOF)
    {
        if(strcmp(produtoDeletar, produto.dado1) != 0){
            fprintf(novoEstoqueTxt, "%s %s %s", produto.dado1, produto.dado2, produto.dado3);
        }
    }
    
    fclose(estoqueOriginalTxt);
    fclose(novoEstoqueTxt);

    if(remove("estoque.txt") != 0){
        printf("ERRO AO APAGAR ARQUIVO ANTIGO");
    }

    if(rename("temp.txt", "estoque.txt") != 0){
        printf("ERRO AO RENOMEAR ARQUIVO");
    }

}