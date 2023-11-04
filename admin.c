#include <stdio.h>
#include <string.h>
#include "sgc.h"

struct Usuarios {
    char nome[50];
    int senha;
    char privilegio[2];  // Aumente o tamanho para acomodar "a" ou "c" e o caractere nulo '\0'
};

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

void adicionarUsuario() {
    FILE *usuariosTxt;
    usuariosTxt = fopen("usuarios.txt", "w");
    struct Usuarios usuario;

    if (usuariosTxt == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        return;
    }

    printf("Informe o nome do novo usuário: ");
    scanf("%s", usuario.nome);

    printf("Informe a senha do novo usuário: ");
    scanf("%d", &usuario.senha);

    // Limpar o buffer após a leitura do inteiro
    while (getchar() != '\n');

    printf("Informe o privilégio do novo usuário (a = admin / c = comum): ");
    scanf("%s", usuario.privilegio);

    fprintf(usuariosTxt, "%s %d %s\n", usuario.nome, usuario.senha, usuario.privilegio);
    fclose(usuariosTxt);

    printf("Usuário cadastrado com sucesso.\n");
}


/// @brief Função para apagar usuários
void excluirUsuario();

/// @brief Função para cadastrar novos produtos
void adicionarProduto(){
    FILE* estoqueTxt;
    estoqueTxt = fopen("estoque.txt", "w");
    struct Produto produtos;

    printf("Informe o nome do novo produto: ");
    scanf("%s", produtos.nome);

    printf("Informe o preço do novo produto: ");
    scanf("%f", &produtos.preco);

    while (getchar() != '\n');

    printf("Informe a quantidade em estoque do novo produto: ");
    scanf("%d", &produtos.quantidade);

    while (getchar() != '\n');

    fprintf(estoqueTxt, "%s %.2f %d\n", produtos.nome, produtos.preco, produtos.quantidade);
    fclose(estoqueTxt);
}

/// @brief Função para apagar pedidos
/// @param numPedido
void cancelarPedido();

/// @brief Função para autenticar um administrador
void autenticar(){
    FILE* usuariosTxt;
    usuariosTxt = fopen("usuarios.txt", "r");

    if(usuariosTxt == NULL){
        printf("ERRO AO ABRIR ARQUIVO!");
        return;
    }
    
    char nomeUsuario[50];
    char senhaUsuario[50];
    char privilegioUsuario[2];

    printf("Digite o nome de usuário: ");
    scanf("%s", nomeUsuario);

    printf("Digite a senha: ");
    scanf("%s", senhaUsuario);

    printf("Digite o caractere de privilégio (a = admin / c = comum): ");
    scanf("%s", privilegioUsuario);

    struct Usuarios usuario;

    while(fscanf(usuariosTxt, "%49s %49s %1s", usuario.nome, usuario.senha, usuario.privilegio) != EOF){
        if(strcmp(usuario.nome, nomeUsuario) == 0 &&
        strcmp(usuario.senha, senhaUsuario) == 0 &&
        strcmp(usuario.privilegio, privilegioUsuario) == 0){
            printf("Usuário autenticado com sucesso.\n");
            break;
        }
    }

    if(feof(usuariosTxt)){
        printf("Usuário não encontrado ou credenciais incorretas");
    }

    fclose(usuariosTxt);
    
    return;

}