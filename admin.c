#include <stdio.h>
#include <C:\Users\anton\OneDrive\Documentos\GitHub\SGCsimples\sgc.h>

/// @brief Função para cadastrar novos usuários
/// @param nomeUsusario
/// @param senha
/// @param privilegio
char adicionarUsuario(char nomeUsuario[], int senha[], char privilegio);

/// @brief Função para apagar usuários
/// @param nomeUsuario
char excluirUsuario(char nomeUsuario[]);

/// @brief Função para cadastrar novos produtos
/// @param nomeProduto
/// @param precoProduto
/// @param quantidade
char adicionarProduto(char nomeProduto[], float precoProduto, int quantidade);

/// @brief Função para apagar pedidos
/// @param numPedido
char cancelarPedido(int numPedido);

/// @brief Função para autenticar um administrador
/// @param nomeProduto
/// @param precoProduto
void autenticar(char nomeAdmin[], int senha);

