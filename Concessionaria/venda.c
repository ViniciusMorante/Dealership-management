#include "venda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funções para gerenciamento de vendas
void registrarVenda(Venda** vendas, int* tamanho, Venda novaVenda) {
    *vendas = realloc(*vendas, (*tamanho + 1) * sizeof(Venda));
    (*vendas)[*tamanho] = novaVenda;
    (*tamanho)++;
    printf("Venda registrada com sucesso! Codigo: %d\n", novaVenda.codigo);
}

void listarVendasPorMes(Venda* vendas, int tamanho, char* mes) {
    printf("\n===== RELATORIO DE VENDAS =====\n");
    float totalVendas = 0.0;
    for (int i = 0; i < tamanho; i++) {
        if (strncmp(vendas[i].dataVenda + 3, mes, 7) == 0) {
            printf("Codigo Venda: %d, Codigo Veiculo: %d, Codigo Vendedor: %d, Codigo Cliente: %d, Preco: %.2f, Data: %s\n",
                   vendas[i].codigo, vendas[i].codigoVeiculo, vendas[i].codigoVendedor,
                   vendas[i].codigoCliente, vendas[i].preco, vendas[i].dataVenda);
            totalVendas += vendas[i].preco;
        }
    }
    printf("Total de Vendas no Mes: %.2f\n", totalVendas);
}

void salvarVendasEmBinario(Venda* vendas, int tamanho) {
    FILE* arquivo = fopen("vendas.dat", "wb");
    fwrite(&tamanho, sizeof(int), 1, arquivo);
    fwrite(vendas, sizeof(Venda), tamanho, arquivo);
    fclose(arquivo);
}

void carregarVendasDeBinario(Venda** vendas, int* tamanho) {
    FILE* arquivo = fopen("vendas.dat", "rb");
    if (arquivo) {
        fread(tamanho, sizeof(int), 1, arquivo);
        *vendas = malloc(*tamanho * sizeof(Venda));
        fread(*vendas, sizeof(Venda), *tamanho, arquivo);
        fclose(arquivo);
    }
}
