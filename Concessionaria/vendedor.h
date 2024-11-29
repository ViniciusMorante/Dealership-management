#ifndef VENDEDOR_H
#define VENDEDOR_H

//Ddados para o Vendedor
typedef struct {
    int codigo;
    char nome[100];
    char cpf[15];
    float salario;
    char dataCadastro[20];
} Vendedor;

// Funções para gerenciamento de vendedores
void cadastrarVendedor(Vendedor** vendedores, int* tamanho, Vendedor novoVendedor);
void listarVendedores(Vendedor* vendedores, int tamanho);
void removerVendedor(Vendedor** vendedores, int* tamanho, int codigo);
void salvarVendedoresEmBinario(Vendedor* vendedores, int tamanho);
void carregarVendedoresDeBinario(Vendedor** vendedores, int* tamanho);

#endif

// De que adianta
// Tantos códigos
// Se a vida não
// Pode ser programada?
