#include <stdio.h>
#include "sgc.h"

void autenticar();
void adicionarUsuario();
void adicionarProduto();

int main(){
    int indiceMenu;
    int indiceUsuario;
    int indiceAdmin;

    printf("===== BEM VINDO =====\n");
    printf("\n");
    printf("Escolha uma opção: ");
    printf("1. Acesso comum\n 2. Acesso administrativo\n");
    scanf("%d", &indiceMenu);
    system("clear");

    switch (indiceMenu)
    {
    case 1:
        printf("Que função você deseja operar?\n 1. Listar produtos\n 2. Realizar pedido\n");
        break;
    
    case 2:
        printf("Que função você deseja operar?\n 1. Listar pedidos\n 2. Cancelar pedidos\n 3. Adicionar usuário");
        printf("4. Deletar usuário\n");
        break;


    default:
        printf("Opção inválida. Tente novamente!\n");
        while(indiceMenu != 1 || indiceMenu != 2){
            printf("\n");
            printf("Escolha uma opção: ");
            printf("1. Acesso comum\n 2. Acesso administrativo\n");
            scanf("%d", &indiceMenu);
            system("clear");
        }
        break;
    }

}