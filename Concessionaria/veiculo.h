#ifndef VEICULO_H
#define VEICULO_H

// dados para o Ve�culo
typedef struct {
    int codigo;
    char modelo[50];
    char marca[50];
    int ano;
    float preco;
    char dataCadastro[20];
} Veiculo;

// Fun��es para gerenciamento de ve�culos
void cadastrarVeiculo(Veiculo** veiculos, int* tamanho, Veiculo novoVeiculo);
void listarVeiculos(Veiculo* veiculos, int tamanho);
void removerVeiculo(Veiculo** veiculos, int* tamanho, int codigo);
void salvarVeiculosEmBinario(Veiculo* veiculos, int tamanho);
void carregarVeiculosDeBinario(Veiculo** veiculos, int* tamanho);

#endif
