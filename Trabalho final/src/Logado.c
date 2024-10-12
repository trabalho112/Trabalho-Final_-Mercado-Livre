#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "../include/Logado.h"
#include "../include/Logar.h"


int Logado(perfis_s* perfis, int n_perfis, int n_logado){

    int opcao;

    

    do{
        printf("Qual opcao voce deseja?\n");
        printf("\t1 - Visitar os produtos de um vendedor\n");
        printf("\t2 - Lista os produtos favoritos\n");
        printf("\t0 - Sair\n");
        scanf("%d%*c", &opcao);

        switch (opcao){

            case 1:
                break;

            case 2:
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

