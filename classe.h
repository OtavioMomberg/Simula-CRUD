#ifndef CLASSE_H
#define CLASSE_H

#define TAMANHO_NOME_PRODUTO 101
#define DEZ_PORCENTO 10.0
#define CINCO_PORCENTO 5.0
#define VALOR_BASE 500.0

void aplicarTaxa(float *preco);

typedef struct {
    void (*ptrTaxa)(float *);
    float preco;
    char nomeProduto[TAMANHO_NOME_PRODUTO];
} Classe;

#endif 