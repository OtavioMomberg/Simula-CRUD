#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "classe.h"

#ifdef _WIN32
    #define LIMPAR_TELA() system("cls")
#else
    #define LIMPAR_TELA() system("clear")
#endif

#define QTD_ACOES 5
#define TAMANHO_PADRAO_VETOR 3
#define AUMENTO_VETOR 3
#define NOME_PRODUTO 101

int tamanhoVetor = 0;
int capacidadeMaximaVetor = TAMANHO_PADRAO_VETOR + 0;

void retornarMenu() {
    while(getchar() != '\n');
    printf("\nClique \'Enter\' para retornar ao menu.");
    getchar();
}

void deletarProduto(Classe *Produto) {
    char nome[NOME_PRODUTO];
    int index = -1;

    printf("Insira o nome do produto que deseja deletar => ");
    scanf(" %[^\n]", nome);

    for(int i=0; i<tamanhoVetor; i++) {
        if(strcmp(nome, Produto[i].nomeProduto) == 0) {
            index = i;
            break;
        }
    }
    
    if(index >= 0) {
        int resposta = 0;

        printf("!========== Produto encontrado! ==========!\n\n");
        printf("Nome: %s\nPreço: %.2f\n\n", Produto[index].nomeProduto, Produto[index].preco);
        printf("Deseja continuar? 1-Sim | 0- Não => ");
        scanf("%d", &resposta);

        if(resposta == 1) {

            if(index < (tamanhoVetor-1)) {
                for(int i=index; i<tamanhoVetor-1; i++) {
                    strcpy(Produto[i].nomeProduto, Produto[i+1].nomeProduto);
                    Produto[i].preco = Produto[i+1].preco;
                }
            } else {
                strcpy(Produto[index].nomeProduto, " ");
                Produto[index].preco = 0.0;
            }
            
            tamanhoVetor--;
        }
    }else {
        printf("!========== Produto não encontrado ==========!\n\n");
        printf("Nome não encontrado, verifique novamente.\n");
    }
}
void mostrarProdutos(Classe *Produto) {
    printf("!========== Produtos Cadastrados ==========!\n\n");
    for(int i=0; i<tamanhoVetor; i++) {
        printf("Nome: %s\tPreço: %.2f\n", Produto[i].nomeProduto, Produto[i].preco);
    }

    retornarMenu();
}
void atualizarProduto(Classe *Produto) {
    char nome[NOME_PRODUTO];
    int index = -1;

    printf("Insira o nome do produto que deseja atualizar => ");
    scanf(" %[^\n]", nome);

    for(int i=0; i<tamanhoVetor; i++) {
        if(strcmp(nome, Produto[i].nomeProduto) == 0) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        char aux[NOME_PRODUTO];
        float auxPreco = 0.0;

        printf("!========== Produto encontrado! ==========!\n\n");
        printf("Nome: %s\nPreço: %.2f\n\n", Produto[index].nomeProduto, Produto[index].preco);

        printf("Digite o novo nome (Se não quiser, basta digitar \'pass\') => ");
        scanf(" %[^\n]", aux);

        if(strcmp(aux, "pass") != 0) {
            strcpy(Produto[index].nomeProduto, aux);
        }

        printf("Digite o novo preço (Se não quiser, basta digitar \'0.0\') => ");
        scanf(" %f", &auxPreco);    

        if (auxPreco != 0.0) {
            Produto[index].preco = auxPreco;
        }
    } else { 
        printf("!========== Produto não encontrado ==========!\n\n");
        printf("Nome não encontrado, verifique novamente.\n");
    }

    retornarMenu(); 

}
void cadastrarProduto(Classe *Produto) {
    printf("Insira o nome do produto => ");
    scanf(" %[^\n]", Produto[tamanhoVetor].nomeProduto);

    do{
        printf("Insira o preço do produto => ");
        if(scanf("%f", &Produto[tamanhoVetor].preco) != 1) {
            Produto[tamanhoVetor].preco = 0.0;
            while(getchar() != '\n');
        }
    }while(Produto[tamanhoVetor].preco == 0.0);

    Produto[tamanhoVetor].ptrTaxa(&Produto[tamanhoVetor].preco);
    tamanhoVetor++;
    
    retornarMenu();   
}

void encaminhaAcoes(int opcao, Classe *Produto) {
    void (*ptrEncaminha[QTD_ACOES])(Classe *) = {cadastrarProduto, atualizarProduto, mostrarProdutos, deletarProduto};
    if (opcao-1 == 0) {
        if (tamanhoVetor >= capacidadeMaximaVetor) {
            printf("Vetor atingiu o tamanho maximo, aumente sua capacidade.\n");
            retornarMenu();
        } else {
            ptrEncaminha[opcao-1](Produto);
        } 
    } else {
        ptrEncaminha[opcao-1](Produto);
    }
}

void selecionarAcao(int *opcao) {
    do{
        printf("Selecione uma das opções acima => ");
        if(scanf("%d", opcao) != 1) {
            *opcao = -1;
            while(getchar() != '\n');
        }
    }while(*opcao <= 0 || *opcao > 6);
    LIMPAR_TELA();
}

void menu() {
    printf("!========== Simulação de CRUD ==========!\t\tCapacidade do vetor: %d\n\n", capacidadeMaximaVetor);
    printf("1- Cadastrar novo produto\n2- Atualizar produto\n3- Visualizar produtos\n4- Deletar produtos\n5- Aumentar vetor\n6-Sair\n\n");
}

Classe *construtor() {
    Classe *Produto = (Classe*) malloc(TAMANHO_PADRAO_VETOR * sizeof(Classe));

    if(Produto == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for(int i=0; i<TAMANHO_PADRAO_VETOR; i++) {
        Produto[i].ptrTaxa = aplicarTaxa;
        Produto[i].preco = 0.0;
        strcpy(Produto[i].nomeProduto, " ");
    }

    return Produto;
}

int main() {
    setlocale(LC_ALL, "pr_BR.UTF-8");
    LIMPAR_TELA();
    
    int opcao = 0;
    
    Classe *Produto = construtor();

    while (opcao != 6) {
        LIMPAR_TELA();
        menu();
        selecionarAcao(&opcao);

        if (opcao < 5) {
            encaminhaAcoes(opcao, Produto);
        } else if (opcao == 5) {
            Classe *temp = realloc(Produto, (capacidadeMaximaVetor + AUMENTO_VETOR) * sizeof(Classe));

            if(temp == NULL) {
                printf("Erro ao aumentar o vetor.\n");
                free(Produto);
                exit(1);
            }

            Produto = temp;
            capacidadeMaximaVetor += AUMENTO_VETOR;

            for(int i=tamanhoVetor; i<capacidadeMaximaVetor; i++) {
                Produto[i].ptrTaxa = aplicarTaxa;
            }

            printf("Vetor aumentado com sucesso!\n");

            retornarMenu();
        }
    }
    free(Produto);
}