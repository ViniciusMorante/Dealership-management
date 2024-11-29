#ifndef VENDA_H
#define VENDA_H

// Dados para a venda
typedef struct {
    int codigo;
    int codigoVeiculo;
    int codigoVendedor;
    int codigoCliente;
    float preco;
    char dataVenda[20];
} Venda;

// Funções para gerenciamento de vendas
void registrarVenda(Venda** vendas, int* tamanho, Venda novaVenda);
void listarVendasPorMes(Venda* vendas, int tamanho, char* mes);
void salvarVendasEmBinario(Venda* vendas, int tamanho);
void carregarVendasDeBinario(Venda** vendas, int* tamanho);

#endif
