# SIMULAÇÃO DE CRUD EM C

## DESCRIÇÃO:

Um simples projeto desenvolvido em C, com o objetivo de simular 
as operações de um CRUD (create, read, update e delete). Neste 
projeto foi utilizado conceitos devalocação dinâmica de memória,
modularização de código, uso de ponteiros, separação do projeto em
arquivos separados e a utilização de struct para simular o funcionamento
de uma classe.

## FUNCIONALIDADES:

1. Cadastrar produtos;
2. Atualizar produtos;
3. Visualizar produtos;
4. Excluir produtos;
5. Aumentar a capacidade do vetor;
6. Aplicar taxa ao preco dos produtos por meio de um ponteiro de função.

## COMPILAÇÃO E EXECUÇÃO:

Para compilar o projeto utilizando o GCC, basta executar o segunte comando (Garanta que todos os arquivos estejam na mesma pasta):

```bash
gcc classe.c main.c -o crud.exe
```

Após compilado basta executar o projeto da seguinte forma:

```bash
.\crud.exe
```

## ESTRUTURA DO PROJETO:

```plaintext
crud-c/
├── src/                  
│   ├── main.c        # Arquivo principal com o menu e a lógica geral  
│   ├── classe.c      # Arquivo que implementa a função de taxa do preço  
│   └── classe.h      # Arquivo de declaração da struct Classe e da funçao aplicarTaxa
```

## TECNOLOGIAS E CONCEITOS UTILIZADOS:

1. Linguagem C
2. Ponteiros
3. Alocação dinâmica (malloc, realloc, free)
4. struct
5. modularização

## DEMOSTRAÇÃO DO PROJETO

```plaintext
!========== Simulação de CRUD ==========!               Capacidade do vetor: 3

1- Cadastrar novo produto
2- Atualizar produto
3- Visualizar produtos
4- Deletar produtos
5- Aumentar vetor
6-Sair

Selecione uma das opções acima => 1
```
```plaintext
Insira o nome do produto => Caderno 
Insira o preço do produto => 25.9

Clique 'Enter' para retornar ao menu.
```
```plaintext
!========== Simulação de CRUD ==========!               Capacidade do vetor: 3

1- Cadastrar novo produto
2- Atualizar produto
3- Visualizar produtos
4- Deletar produtos
5- Aumentar vetor
6-Sair

Selecione uma das opções acima => 3
```
```plaintext
!========== Produtos Cadastrados ==========!

Nome: Caderno   Preço: 27.19

Clique 'Enter' para retornar ao menu.
```
```plaintext
!========== Simulação de CRUD ==========!               Capacidade do vetor: 3

1- Cadastrar novo produto
2- Atualizar produto
3- Visualizar produtos
4- Deletar produtos
5- Aumentar vetor
6-Sair

Selecione uma das opções acima => 2
```
```plaintext
Insira o nome do produto que deseja atualizar => Caderno
!========== Produto encontrado! ==========!

Nome: Caderno
Preço: 27.19

Digite o novo nome (Se não quiser, basta digitar 'pass') => pass
Digite o novo preço (Se não quiser, basta digitar '0.0') => 28.5

Clique 'Enter' para retornar ao menu.
```
```plaintext
!========== Simulação de CRUD ==========!               Capacidade do vetor: 3

1- Cadastrar novo produto
2- Atualizar produto
3- Visualizar produtos
4- Deletar produtos
5- Aumentar vetor
6-Sair

Selecione uma das opções acima => 3
```
```plaintext
!========== Produtos Cadastrados ==========!

Nome: Caderno   Preço: 28.50

Clique 'Enter' para retornar ao menu.
```
```plaintext
!========== Simulação de CRUD ==========!               Capacidade do vetor: 3

1- Cadastrar novo produto
2- Atualizar produto
3- Visualizar produtos
4- Deletar produtos
5- Aumentar vetor
6-Sair

Selecione uma das opções acima => 4
```
```plaintext
Insira o nome do produto que deseja deletar => Caderno
!========== Produto encontrado! ==========!

Nome: Caderno
Preço: 28.50

Deseja continuar? 1-Sim | 0- Não => 1
```
```plaintext
!========== Simulação de CRUD ==========!               Capacidade do vetor: 3

1- Cadastrar novo produto
2- Atualizar produto
3- Visualizar produtos
4- Deletar produtos
5- Aumentar vetor
6-Sair

Selecione uma das opções acima => 3
```
```plaintext
!========== Produtos Cadastrados ==========!


Clique 'Enter' para retornar ao menu.
```
```plaintext
!========== Simulação de CRUD ==========!               Capacidade do vetor: 3

1- Cadastrar novo produto
2- Atualizar produto
3- Visualizar produtos
4- Deletar produtos
5- Aumentar vetor
6-Sair

Selecione uma das opções acima => 5
```
```plaintext
Vetor aumentado com sucesso!

Clique 'Enter' para retornar ao menu.
```
```plaintext
!========== Simulação de CRUD ==========!               Capacidade do vetor: 6

1- Cadastrar novo produto
2- Atualizar produto
3- Visualizar produtos
4- Deletar produtos
5- Aumentar vetor
6-Sair

Selecione uma das opções acima =>
```
