#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>


#include "../include/Logar.h"
#include "../include/Menu.h"
#include "../include/Produtos.h"

int MenuLogado(perfis_s* perfis, int n_perfis, int n_logado){

    int opcao;

    
    produto_s* produtos = NULL;
    int n_produtos = 0;
    char id_vendedor[TAM_ID];
    

    do{
        printf("Qual opcao voce deseja?\n");
        printf("\t1 - Visitar os produtos de um vendedor\n");
        printf("\t2 - Lista os produtos favoritos\n");
        printf("\t4 - Cadastrar produto\n");
        printf("\t5 - Listar produtos\n");
        printf("\t6 - Listar produtos de um vendedor\n");
        printf("\t0 - Sair\n");
        scanf("%d%*c", &opcao);

        switch (opcao){

            case 1:
                break;

            case 2:
                break;    
            
            case 4:
                n_produtos++;
                produtos = RealocProd(n_produtos,produtos);
                CadastrarProduto(produtos,n_produtos,perfis,n_perfis, n_logado);
            break;

            case 5:
                if(n_produtos == 0){

                    printf("Nenhum produto cadastrado!\n");
                    continue;
                }

                ListarProdutos(produtos, n_produtos);
            break;

            case 6: 
            
                if(n_produtos == 0){

                    printf("Nenhum produto cadastrado!\n");
                    continue;
                }

                printf("Digite o ID do vendedor: ");
                fgets(id_vendedor, TAM_ID, stdin);
                id_vendedor[strcspn(id_vendedor, "\n")] = '\0';

                ListarProdutosPorVendedor(produtos, n_produtos, id_vendedor);

            break;

            case 0:

                printf("ate!\n");
                return 0;
                
            default:
                printf("opcao invalida\n");
            break;
        }

    }while(opcao!=0);


    return 0;

}

void MenuCadastro(){

    
    perfis_s* perfis= NULL;
    char id_vendedor[TAM_ID];
    int n_perfis = 0, n_produtos = 0;
    int opcao;

////    FILE * perfil_a;

  //  perfil_a = fopen ("perfils.txt","a");

   // perfis = LerNumperfis(perfis);
   // n_perfis = LerArquivo(perfis);
    

    do{
        printf("Qual opcao voce deseja?\n");
        printf("\t1 - Cadastrar perfil\n");
        printf("\t2 - Imprimir Perfis\n");
        printf("\t3 - Logar\n");
        printf("\t0 - Sair\n");
        scanf("%d%*c", &opcao);

        switch (opcao)
        {
        case 1:
            n_perfis++;
            perfis = Reallocarperfis(n_perfis, perfis);
            CadastrarPerfil(perfis, n_perfis);
            
            break;

        case 2:
            if (n_perfis>0)
            {
            ImprimirDados(perfis, n_perfis);
            }else
            {
                printf("nenhum perfil cadastrado!\n");
            }
            
            break;
        case 3:

            Logar(perfis, n_perfis);

            break;
       
        case 0:
            printf("Tchau!\n");
           // EscreverArquivo(perfis, n_perfis);
            break;
        default:
            break;
        }
    }while(opcao != 0);
  //  fclose(perfil_a);

    
    free(perfis);
}

