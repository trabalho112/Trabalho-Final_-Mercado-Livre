#ifndef ProdutosH
#define ProdutosH


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>


#include "../include/Logar.h"
#include "../include/Menu.h"


produto_s* RealocProd(int n_prod, produto_s* produtos);

void CadastrarProduto(produto_s* produtos, int n_produtos, perfis_s* perfis, int n_perfis,int n_logado);

void ListarProdutos(produto_s* produtos, int n_produtos);

void ListarProdutosPorVendedor(produto_s* produtos, int n_produtos, const char* id_vendedor);




#endif
