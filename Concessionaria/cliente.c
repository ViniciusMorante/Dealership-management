#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funções para gerenciamento de clientes
void cadastrarCliente(Cliente** clientes, int* tamanho, Cliente novoCliente) {
    *clientes = realloc(*clientes, (*tamanho + 1) * sizeof(Cliente));
    (*clientes)[*tamanho] = novoCliente;
    (*tamanho)++;
    printf("Cliente cadastrado com sucesso! Codigo: %d\n", novoCliente.codigo);
}

void listarClientes(Cliente* clientes, int tamanho) {
    printf("\n===== LISTA DE CLIENTES =====\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Codigo: %d, Nome: %s, CPF: %s, Endereco: %s\n",
               clientes[i].codigo, clientes[i].nome, clientes[i].cpf, clientes[i].endereco);
    }
}

void removerCliente(Cliente** clientes, int* tamanho, int codigo) {
    for (int i = 0; i < *tamanho; i++) {
        if ((*clientes)[i].codigo == codigo) {
            for (int j = i; j < *tamanho - 1; j++) {
                (*clientes)[j] = (*clientes)[j + 1];
            }
            (*clientes) = realloc(*clientes, (*tamanho - 1) * sizeof(Cliente));
            (*tamanho)--;
            printf("Cliente removido com sucesso! Codigo: %d\n", codigo);
            return;
        }
    }
    printf("Cliente nao encontrado!\n");
}

void salvarClientesEmBinario(Cliente* clientes, int tamanho) {
    FILE* arquivo = fopen("clientes.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, arquivo);
    fwrite(clientes, sizeof(Cliente), tamanho, arquivo);
    fclose(arquivo);
}

void carregarClientesDeBinario(Cliente** clientes, int* tamanho) {
    FILE* arquivo = fopen("clientes.dat", "rb");
    if (arquivo) {
        fread(tamanho, sizeof(int), 1, arquivo);
        *clientes = malloc(*tamanho * sizeof(Cliente));
        fread(*clientes, sizeof(Cliente), *tamanho, arquivo);
        fclose(arquivo);
    }
}

//A parte de banco binário eh pura gambiarra
