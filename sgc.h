#ifndef sgc_h
#define sgc_h

char adicionarUsuario(char nomeUsuario[], int senha[], char privilegio);
void autenticar(char nomeAdmin[], int senha);
char adicionarProduto(char nomeProduto[], float precoProduto, int quantidade);
char excluirUsuario(char nomeUsuario[]);
char realizarPedido(char nomeProduto[], int quantidade, int numPedido);
char cancelarPedido(int numPedido);
char listarProdutos();

#endif