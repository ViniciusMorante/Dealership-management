#include "vendedor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funções para gerenciamento de vendedores
void cadastrarVendedor(Vendedor** vendedores, int* tamanho, Vendedor novoVendedor) {
    *vendedores = realloc(*vendedores, (*tamanho + 1) * sizeof(Vendedor));
    (*vendedores)[*tamanho] = novoVendedor;
    (*tamanho)++;
    printf("Vendedor cadastrado com sucesso! Codigo: %d\n", novoVendedor.codigo);
}

void listarVendedores(Vendedor* vendedores, int tamanho) {
    printf("\n===== LISTA DE VENDEDORES =====\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Codigo: %d, Nome: %s, CPF: %s, Salario: %.2f\n",
               vendedores[i].codigo, vendedores[i].nome, vendedores[i].cpf,
               vendedores[i].salario);
    }
}

void removerVendedor(Vendedor** vendedores, int* tamanho, int codigo) {
    for (int i = 0; i < *tamanho; i++) {
        if ((*vendedores)[i].codigo == codigo) {
            for (int j = i; j < *tamanho - 1; j++) {
                (*vendedores)[j] = (*vendedores)[j + 1];
            }
            (*vendedores) = realloc(*vendedores, (*tamanho - 1) * sizeof(Vendedor));
            (*tamanho)--;
            printf("Vendedor removido com sucesso! Codigo: %d\n", codigo);
            return;
        }
    }
    printf("Vendedor nao encontrado!\n");
}

void salvarVendedoresEmBinario(Vendedor* vendedores, int tamanho) {
    FILE* arquivo = fopen("vendedores.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, arquivo);
    fwrite(vendedores, sizeof(Vendedor), tamanho, arquivo);
    fclose(arquivo);
}

void carregarVendedoresDeBinario(Vendedor** vendedores, int* tamanho) {
    FILE* arquivo = fopen("vendedores.dat", "rb");
    if (arquivo) {
        fread(tamanho, sizeof(int), 1, arquivo);
        *vendedores = malloc(*tamanho * sizeof(Vendedor));
        fread(*vendedores, sizeof(Vendedor), *tamanho, arquivo);
        fclose(arquivo);
    }
}
//A parte de banco binário eh pura gambiarra
