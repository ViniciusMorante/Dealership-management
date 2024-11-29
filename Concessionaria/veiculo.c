#include "veiculo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funções para gerenciamento de veículos
void cadastrarVeiculo(Veiculo** veiculos, int* tamanho, Veiculo novoVeiculo) {
    *veiculos = realloc(*veiculos, (*tamanho + 1) * sizeof(Veiculo));
    (*veiculos)[*tamanho] = novoVeiculo;
    (*tamanho)++;
    printf("Veiculo cadastrado com sucesso! Codigo: %d\n", novoVeiculo.codigo);
}

void listarVeiculos(Veiculo* veiculos, int tamanho) {
    printf("\n===== LISTA DE VEICULOS =====\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Codigo: %d, Modelo: %s, Marca: %s, Ano: %d, Preco: %.2f\n",
               veiculos[i].codigo, veiculos[i].modelo, veiculos[i].marca,
               veiculos[i].ano, veiculos[i].preco);
    }
}

void removerVeiculo(Veiculo** veiculos, int* tamanho, int codigo) {
    for (int i = 0; i < *tamanho; i++) {
        if ((*veiculos)[i].codigo == codigo) {
            for (int j = i; j < *tamanho - 1; j++) {
                (*veiculos)[j] = (*veiculos)[j + 1];
            }
            (*veiculos) = realloc(*veiculos, (*tamanho - 1) * sizeof(Veiculo));
            (*tamanho)--;
            printf("Veiculo removido com sucesso! Codigo: %d\n", codigo);
            return;
        }
    }
    printf("Veiculo nao encontrado!\n");
}

void salvarVeiculosEmBinario(Veiculo* veiculos, int tamanho) {
    FILE* arquivo = fopen("veiculos.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, arquivo);
    fwrite(veiculos, sizeof(Veiculo), tamanho, arquivo);
    fclose(arquivo);
}

void carregarVeiculosDeBinario(Veiculo** veiculos, int* tamanho) {
    FILE* arquivo = fopen("veiculos.dat", "rb");
    if (arquivo) {
        fread(tamanho, sizeof(int), 1, arquivo);
        *veiculos = malloc(*tamanho * sizeof(Veiculo));
        fread(*veiculos, sizeof(Veiculo), *tamanho, arquivo);
        fclose(arquivo);
    }
}

//A parte de banco binário eh pura gambiarra
