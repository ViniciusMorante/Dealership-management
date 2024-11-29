#ifndef CLIENTE_H
#define CLIENTE_H

// Dados para o Cliente
typedef struct {
    int codigo;
    char nome[100];
    char cpf[15];
    char endereco[200];
    char dataCadastro[20];
} Cliente;

// Funções para gerenciamento de clientes
void cadastrarCliente(Cliente** clientes, int* tamanho, Cliente novoCliente);
void listarClientes(Cliente* clientes, int tamanho);
void removerCliente(Cliente** clientes, int* tamanho, int codigo);
void salvarClientesEmBinario(Cliente* clientes, int tamanho);
void carregarClientesDeBinario(Cliente** clientes, int* tamanho);

#endif
