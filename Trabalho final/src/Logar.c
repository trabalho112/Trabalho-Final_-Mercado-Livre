#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "../include/Logado.h"
#include "../include/Logar.h"



int* RealocaInt(int tamanho, int* vetor){

    vetor = (int*)realloc(vetor, tamanho*sizeof(int));

    return vetor; 
}

produto_s* RealocProd(int n_prod, produto_s* produtos){

    produtos = (produto_s*)realloc(produtos, n_prod*sizeof(produto_s));

    return produtos;
}

perfis_s* Reallocarperfis(int n_perfis, perfis_s* perfis){
    
    perfis = (perfis_s*)realloc(perfis, n_perfis*sizeof(perfis_s));

    return perfis;
}

void CadastrarProduto(produto_s* produtos, int n_produtos, perfis_s* perfis, int n_perfis){


    produtos[n_produtos-1].id_produto = n_produtos;

    printf("Digite o nome do produto: \n");
    fgets(produtos[n_produtos-1].nome,TAM_NOME,stdin);
    produtos[n_produtos-1].nome[strcspn(produtos[n_produtos-1].nome, "\n")] = '\0';

    printf("Digite uma breve descricao do produto:\n");
    fgets(produtos[n_produtos-1].descricao,TAM_NOME,stdin);
    produtos[n_produtos-1].descricao[strcspn(produtos[n_produtos-1].descricao, "\n")] = '\0';

    printf("Digite a quantidade desse produto\n");
    scanf("%d",&produtos[n_produtos-1].qntd);

    printf("Insira o ID do usuario a qual esse produto pertence: \n");
    scanf("%d",&produtos[n_produtos-1].identificador_vendedor);

    perfis_s* perfilEscolhido = &perfis[produtos[n_produtos-1].identificador_vendedor-1];

    perfilEscolhido->tam_produtos_Vendidos++;

    perfilEscolhido->id_produtos_Vendidos = RealocaInt(perfilEscolhido->tam_produtos_Vendidos,perfilEscolhido->id_produtos_Vendidos);

    perfilEscolhido->id_produtos_Vendidos[perfilEscolhido->tam_produtos_Vendidos-1] = produtos[n_produtos-1].id_produto;

    printf("Produto Cadastrado!\n");

    return;
}

void CadastrarPerfil(perfis_s* perfis, int n_perfis){
    int erro, arroba;

    perfis[n_perfis-1].tam_produtos_Vendidos = 0;
    perfis[n_perfis-1].id_produtos_Vendidos = NULL;
    perfis[n_perfis-1].tam_produtos_Favoritos = 0;
    perfis[n_perfis-1].id_produtos_Favoritos = NULL;


    perfis[n_perfis-1].indentificador = n_perfis;

    printf("Diga o nome: ");
    fgets(perfis[n_perfis-1].nome, TAM_NOME, stdin);  
    perfis[n_perfis-1].nome[strcspn(perfis[n_perfis-1].nome, "\n")] = '\0';

    do
    {
        erro = 0;
        arroba = 0;
        printf("Diga o email: ");
    
        fgets(perfis[n_perfis-1].email, TAM_MAX_EMAIL, stdin);  
        perfis[n_perfis-1].email[strcspn(perfis[n_perfis-1].email, "\n")] = '\0';

        for(int i=1; i<n_perfis; i++){

            if(strcmp(perfis[n_perfis-1].email, perfis[i-1].email) == 0){
                erro = 1;
                printf("Email ja utilizado por outro usario. Tente novamente!\n");
            }
       }

        for(int i=0; i<=TAM_MAX_EMAIL; i++){

            if(perfis[n_perfis-1].email[i] == '@'){
                    arroba = 1;   
                }
        }

        if (arroba != 1) printf("Email invalido, '@' nao encontrado. Tente novamente!\n");
        

    } while (erro == 1 || arroba != 1);
    
    
    printf("Diga a senha: ");
    fgets(perfis[n_perfis-1].senha, TAM_MAX_SENHA, stdin);  
    perfis[n_perfis-1].senha[strcspn(perfis[n_perfis-1].senha, "\n")] = '\0';

    do{
        erro = 1;

        printf("Diga o ID: ");

        fgets(perfis[n_perfis-1].id, TAM_ID, stdin);
        perfis[n_perfis-1].id[strcspn(perfis[n_perfis-1].id, "\n")] = '\0';

        for(int i=1; i<n_perfis; i++){

            if(strcmp(perfis[n_perfis-1].id, perfis[i-1].id) == 0){
                erro = 0;
                printf("ID ja utilizado por outro usario. Tente novamente!\n");
            }
        }
    }while (erro == 0);

    
}

void ImprimirDados(perfis_s* perfis, int n_perfis){


    printf("|%-*s|%-*s|%-*s|\n", TAM_NOME,"Nome_perfil",TAM_MAX_EMAIL, "email",TAM_ID, "Id");

    for (int i = 0; i < n_perfis; i++){

        printf("|%-50s|%-50s|%-20s|\n", perfis[i].nome, perfis[i].email, perfis[i].id);

    }

}

int LogarComId(perfis_s* perfis, int n_perfis){
    char ID[TAM_ID];
    char Senha[TAM_MAX_SENHA];
    while (1){
    
    printf("Diga o ID(0 para sair): ");
    fgets(ID, TAM_ID, stdin); 
    ID[strcspn(ID, "\n")] = '\0';

    for(int i=0; i < n_perfis; i++){
        if(strcmp(ID, perfis[i].id) == 0){
            printf("Diga a senha: ");
            fgets(Senha, TAM_MAX_SENHA, stdin); 
            Senha[strcspn(Senha, "\n")] = '\0';

            if (strcmp(Senha, perfis[i].senha) == 0)
            {
                return perfis[i].indentificador;
            }else printf("senha incorreta\n");
            
            
        }
    }

    if (ID[0] == '0'){
            return 0;
    }
        
        
        printf("cadastro invalido, tente novamente\n");
    }
    

    
}

int LogarComEmail(perfis_s* perfis, int n_perfis){
    char Email[TAM_MAX_EMAIL], Senha[TAM_MAX_SENHA];
    while (1){
    
    printf("Diga o Email(0 para sair): ");
    fgets(Email, TAM_MAX_EMAIL, stdin); 
    Email[strcspn(Email, "\n")] = '\0';

    for(int i=0; i < n_perfis; i++){
        if(strcmp(Email, perfis[i].email) == 0){
            printf("Diga a senha: ");
            fgets(Senha, TAM_MAX_SENHA, stdin); 
            Senha[strcspn(Senha, "\n")] = '\0';

            if (strcmp(Senha, perfis[i].senha) == 0)
            {
                return perfis[i].indentificador;
            }else printf("senha incorreta\n");
            
            
        }
    }

    if (Email[0] == '0'){
            return 0;
    }
        
        
        printf("Login invalido, tente novamente\n");
    }
    

    
}

void Logar(perfis_s * perfis, int n_perfis){
    
    int opcao;
    int cadastrado;
    int n_logado;

    

    do{
        printf("Qual opcao voce deseja?\n");
        printf("\t1 - Logar com ID\n");
        printf("\t2 - Logar com Email\n");
        printf("\t0 - Nao cadastrar\n");
        scanf("%d%*c", &opcao);

        switch (opcao){

            case 1:
                n_logado = LogarComId(perfis, n_perfis);
                if(n_logado == 0){
                    return;
                }
                opcao = Logado(perfis, n_perfis, n_logado);
                break;

            case 2:
                n_logado = LogarComEmail(perfis, n_perfis);
                if(n_logado == 0){
                    return;
                }
                opcao = Logado(perfis, n_perfis, n_logado);
                break;    

            case 0:

                printf("ate!\n");
                return;
                
            default:
                printf("opcao invalida\n");
                break;
        }

    }while(opcao!=0);
}
