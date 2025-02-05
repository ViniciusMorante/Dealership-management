#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"
#include "vendedor.h"
#include "cliente.h"
#include "venda.h"

    // Primeiramente, o banco de dados em bin�rio foi complicado
    // (Ps. Utilizei um c�digo do gpt como exemplo e fui implementando no sistema)

//  Exibir o menu principal
void exibirMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Cadastrar um novo veiculo\n");
    printf("2. Listar os veiculos\n");
    printf("3. Desativar um veiculo\n");
    printf("4. Cadastrar um novo vendedor\n");
    printf("5. Listar os vendedores\n");
    printf("6. Remover um vendedor\n");
    printf("7. Cadastrar novo cliente\n");
    printf("8. Listar clientes\n");
    printf("9. Desativar um cliente\n");
    printf("10. Registrar uma nova venda\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Veiculo* veiculos = NULL;
    Vendedor* vendedores = NULL;
    Cliente* clientes = NULL;
    Venda* vendas = NULL;
    int tamanhoVeiculos = 0, tamanhoVendedores = 0, tamanhoClientes = 0, tamanhoVendas = 0;
    int opcao;
    int proximoCodigoVeiculo = 1, proximoCodigoVendedor = 1, proximoCodigoCliente = 1, proximoCodigoVenda = 1;

    // Carregar dados do banco em binario
    carregarVeiculosDeBinario(&veiculos, &tamanhoVeiculos);
    carregarVendedoresDeBinario(&vendedores, &tamanhoVendedores);
    carregarClientesDeBinario(&clientes, &tamanhoClientes);
    carregarVendasDeBinario(&vendas, &tamanhoVendas);

    // N�o sei como, mas est� funcionando,
    // precisei modificar alguns dos dados
    // de cadastro

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                // Cadastro de veiculo
                char modelo[50], marca[50];
                int ano;
                float preco;

                printf("Informe o modelo: ");
                scanf("%s", modelo);
                printf("Informe a marca: ");
                scanf("%s", marca);
                printf("Informe o ano do veiculo: ");
                scanf("%d", &ano);
                printf("Informe o preco do veiculo: ");
                scanf("%f", &preco);

                Veiculo novoVeiculo;
                novoVeiculo.codigo = proximoCodigoVeiculo++;
                strcpy(novoVeiculo.modelo, modelo);
                strcpy(novoVeiculo.marca, marca);
                novoVeiculo.ano = ano;
                novoVeiculo.preco = preco;
                strcpy(novoVeiculo.dataCadastro, "N/A");

                cadastrarVeiculo(&veiculos, &tamanhoVeiculos, novoVeiculo);
                salvarVeiculosEmBinario(veiculos, tamanhoVeiculos);  // Salva os dados ap�s cadastro
                break;
            }

            case 2: {
                // Listar veiculos
                listarVeiculos(veiculos, tamanhoVeiculos);
                break;
            }

            case 3: {
                // Remover veiculo
                int codigo;
                printf("Informe o codigo do veiculo a ser removido: ");
                scanf("%d", &codigo);
                removerVeiculo(&veiculos, &tamanhoVeiculos, codigo);
                salvarVeiculosEmBinario(veiculos, tamanhoVeiculos);  // Salva ap�s remo��o
                break;
            }

            case 4: {
                // Cadastro de vendedor
                char nome[100], cpf[15];
                float salario;

                printf("Informe o nome do vendedor: ");
                scanf("%s", nome);
                printf("Informe o CPF do vendedor: ");
                scanf("%s", cpf);
                printf("Informe o salario do vendedor: ");
                scanf("%f", &salario);

                Vendedor novoVendedor;
                novoVendedor.codigo = proximoCodigoVendedor++;
                strcpy(novoVendedor.nome, nome);
                strcpy(novoVendedor.cpf, cpf);
                novoVendedor.salario = salario;
                strcpy(novoVendedor.dataCadastro, "N/A");

                cadastrarVendedor(&vendedores, &tamanhoVendedores, novoVendedor);
                salvarVendedoresEmBinario(vendedores, tamanhoVendedores);  // Salva ap�s cadastro
                break;
            }

            case 5: {
                // Listar vendedores
                listarVendedores(vendedores, tamanhoVendedores);
                break;
            }

            case 6: {
                // Remover vendedor
                int codigo;
                printf("Informe o codigo do vendedor a ser removido: ");
                scanf("%d", &codigo);
                removerVendedor(&vendedores, &tamanhoVendedores, codigo);
                salvarVendedoresEmBinario(vendedores, tamanhoVendedores);  // Salva apos remo��o
                break;
            }

            case 7: {
                // Cadastro de cliente
                char nome[100], cpf[15], endereco[200];

                printf("Informe o nome do cliente: ");
                scanf("%s", nome);
                printf("Informe o CPF do cliente: ");
                scanf("%s", cpf);
                printf("Informe o endereco do cliente: ");
                scanf(" %[^\n]%*c", endereco);

                Cliente novoCliente;
                novoCliente.codigo = proximoCodigoCliente++;
                strcpy(novoCliente.nome, nome);
                strcpy(novoCliente.cpf, cpf);
                strcpy(novoCliente.endereco, endereco);
                strcpy(novoCliente.dataCadastro, "N/A");

                cadastrarCliente(&clientes, &tamanhoClientes, novoCliente);
                salvarClientesEmBinario(clientes, tamanhoClientes);  // Salva ap�s cadastro
                break;
            }

            case 8: {
                // Listar clientes
                listarClientes(clientes, tamanhoClientes);
                break;
            }

            case 9: {
                // Remover cliente
                int codigo;
                printf("Informe o codigo do cliente a ser removido: ");
                scanf("%d", &codigo);
                removerCliente(&clientes, &tamanhoClientes, codigo);
                salvarClientesEmBinario(clientes, tamanhoClientes);  // Salva ap�s remo��o
                break;
            }

            case 10: {
                // Registrar venda
                int codigoVeiculo, codigoVendedor, codigoCliente;
                float preco;

                printf("Informe o codigo do veiculo: ");
                scanf("%d", &codigoVeiculo);
                printf("Informe o codigo do vendedor: ");
                scanf("%d", &codigoVendedor);
                printf("Informe o codigo do cliente: ");
                scanf("%d", &codigoCliente);
                printf("Informe o preco da venda: ");
                scanf("%f", &preco);

                Venda novaVenda;
                novaVenda.codigo = proximoCodigoVenda++;
                novaVenda.codigoVeiculo = codigoVeiculo;
                novaVenda.codigoVendedor = codigoVendedor;
                novaVenda.codigoCliente = codigoCliente;
                novaVenda.preco = preco;
                strcpy(novaVenda.dataVenda, "N/A");

                registrarVenda(&vendas, &tamanhoVendas, novaVenda);
                salvarVendasEmBinario(vendas, tamanhoVendas);  // Salva ap�s registro
                break;
            }

            case 0:
                // Salvar tudo e sair
                salvarVeiculosEmBinario(veiculos, tamanhoVeiculos);
                salvarVendedoresEmBinario(vendedores, tamanhoVendedores);
                salvarClientesEmBinario(clientes, tamanhoClientes);
                salvarVendasEmBinario(vendas, tamanhoVendas);
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }

        // Aguarda o usu�rio pressionar qualquer tecla para continuar
        printf("\nPressione qualquer tecla para continuar...");
        getchar();  // Limpar o buffer de entrada
        getchar();
    } while (opcao != 0);

    // Liberar mem�ria antes de sair
    free(veiculos);
    free(vendedores);
    free(clientes);
    free(vendas);
    return 0;
}
