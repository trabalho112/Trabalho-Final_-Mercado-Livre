#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "../include/Logar.h"
#include "../include/Menu.h"
#include "../include/Produtos.h"


produto_s* RealocProd(int n_prod, produto_s* produtos){

    produtos = (produto_s*)realloc(produtos, n_prod*sizeof(produto_s));

    return produtos;
}

void CadastrarProduto(produto_s* produtos, int n_produtos, perfis_s* perfis, int n_perfis,int n_logado) {
    produtos[n_produtos - 1].id_produto = n_produtos;

    printf("Digite o nome do produto: \n");
    fgets(produtos[n_produtos - 1].nome, TAM_NOME, stdin);
    produtos[n_produtos - 1].nome[strcspn(produtos[n_produtos - 1].nome, "\n")] = '\0';

    printf("Digite uma breve descricao do produto:\n");
    fgets(produtos[n_produtos - 1].descricao, TAM_DESC, stdin);
    produtos[n_produtos - 1].descricao[strcspn(produtos[n_produtos - 1].descricao, "\n")] = '\0';

    printf("Digite a quantidade desse produto\n");
    scanf("%d", &produtos[n_produtos - 1].qntd);
    getchar();

    /*printf("Insira o ID do usuario a qual esse produto pertence: \n");
    fgets(produtos[n_produtos - 1].identificador_vendedor, TAM_ID, stdin);
    produtos[n_produtos - 1].identificador_vendedor[strcspn(produtos[n_produtos - 1].identificador_vendedor, "\n")] = '\0';
*/

    strcpy(produtos[n_produtos-1].identificador_vendedor, perfis[n_logado].id);

    perfis_s* perfilEscolhido = NULL;

    for (int i = 0; i < n_perfis; i++) {
        if (strcmp(perfis[i].id, produtos[n_produtos - 1].identificador_vendedor) == 0) {

            perfilEscolhido = &perfis[i];
            break;
        }
    }
 }

void ListarProdutos(produto_s* produtos, int n_produtos) {

    printf("Lista de produtos cadastrados:\n");

    for (int i = 0; i < n_produtos; i++) {

        printf("ID: %d | Nome: %s | Descricao: %s | Quantidade: %d | ID Vendedor: %s\n", produtos[i].id_produto, produtos[i].nome, produtos[i].descricao, produtos[i].qntd, produtos[i].identificador_vendedor);
    }
}

void ListarProdutosPorVendedor(produto_s* produtos, int n_produtos, const char* id_vendedor) {


    printf("Produtos do vendedor com ID %s:\n", id_vendedor);

    int encontrado = 0;

    for (int i = 0; i < n_produtos; i++) {
        if (strcmp(produtos[i].identificador_vendedor, id_vendedor) == 0) {

            printf("ID: %d | Nome: %s | Descricao: %s | Quantidade: %d\n", produtos[i].id_produto, produtos[i].nome, produtos[i].descricao, produtos[i].qntd);

            encontrado = 1;
        }
    }

    if (!encontrado) {

        printf("Nenhum produto encontrado para este vendedor.\n");
    }
}

