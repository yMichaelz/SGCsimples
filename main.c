#include <stdio.h>
#include <stdlib.h>
#include "sgc.h"

void autenticar();
void adicionarUsuario();
void adicionarProduto();

int main(){
    int indiceMenu;
    int indiceUsuario;
    int indiceAdmin;
    int shouldRun = 0;

    while(shouldRun == 0){
        printf("===== BEM VINDO =====\n");
    printf("\n");
    printf("Escolha uma opção: \n");
    printf("1. Acesso comum\n 2. Acesso administrativo\n 3. Sair\n");
    scanf("%d", &indiceMenu);
    system("clear");

    switch (indiceMenu)
    {
    case 1:
        printf("Que função você deseja operar?\n 1. Listar produtos\n 2. Realizar pedido\n");
        scanf("%d", &indiceUsuario);
        break;
    
    case 2:
        printf("Que função você deseja operar?\n 1. Listar pedidos\n 2. Cancelar pedidos\n 3. Adicionar usuário\n");
        printf("4. Deletar usuário\n 5. Adicionar produto\n");
        scanf("%d", &indiceAdmin);
        switch (indiceAdmin)
        {
        case 1:
            //listarPedidos();
            break;
        
        case 2:
            //cancelarPedido();
            break;
        case 3:
            adicionarUsuario();
            break;
        case 4:
            excluirUsuario();
            break;
        case 5:
            adicionarProduto();
            break;
        default:
            printf("Opção inválida.");
            break;
        }
        break;
    
    case 3:
        return 0;

    default:
        printf("Opção inválida!! Tente novamente!\n");
        while(indiceMenu != 1 || indiceMenu != 2){
            printf("\n");
            printf("===== Escolha uma opção: =====\n");
            printf("1. Acesso comum\n 2. Acesso administrativo\n");
            scanf("%d", &indiceMenu);
            system("clear");
            break;
        }
        break;
    }
    }

}