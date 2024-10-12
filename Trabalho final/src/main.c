#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "../include/Logado.h"
#include "../include/Logar.h"

    

int main(int argc, char const *argv[]){

    perfis_s* perfis= NULL;
    produto_s* produtos = NULL;
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
        printf("\t4 - Cadastrar produto\n");
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
        case 4:

            n_produtos++;
            produtos = RealocProd(n_produtos,produtos);
            CadastrarProduto(produtos,n_produtos,perfis,n_perfis);

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

    free(produtos);
    free(perfis);

    return sucesso;

}