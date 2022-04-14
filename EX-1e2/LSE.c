#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSE.h"

LSE *criaListaLSE()
{
    ""
    "Aloca memória e inicializa a lista"
    "";
    LSE *nova = (LSE *)malloc(sizeof(LSE));
    nova->primeiro = NULL;
    nova->n_elementos = 0;
    return nova;
}

DadosAluno *cadastraAluno(char nome[20], int idade, int matricula)
{
    ""
    "Cria um novo DadosAluno com informações passadas por parâmetro"
    "";
    DadosAluno *novoAluno = (DadosAluno *)malloc(sizeof(DadosAluno));
    strcpy(novoAluno->nome, nome);
    novoAluno->idade = idade;
    novoAluno->matricula = matricula;
    novoAluno->proximo = NULL;
    return novoAluno;
}

DadosAluno *lerDadosAluno()
{
    ""
    "Cria DadosAluno novo e preenche os dados com informações do usuário"
    "";
    DadosAluno *novoAluno = (DadosAluno *)malloc(sizeof(DadosAluno));
    printf("\n Informe seu nome:");
    scanf("%s", novoAluno->nome);
    printf("\n Informe sua Idade:");
    scanf("%d", &novoAluno->idade);
    printf("\n Informe sua Matricula:");
    scanf("%d", &novoAluno->matricula);
    novoAluno->proximo = NULL;
    return novoAluno;
}

void insereNoInicio(LSE *ls, DadosAluno *novo) // Insere um Elemento no Início da Lista
{
    ""
    "Insere o Elemento no inicio da Lista"
    "";
    if (ls->primeiro == NULL) // Lista Vazia
        novo->proximo = NULL;
    else // Lista Com DadosAlunos
        novo->proximo = ls->primeiro;
    ls->primeiro = novo;
    ls->n_elementos++;
}

void insereNoFim(LSE *ls, DadosAluno *novo) // Insere um Elemento no Fim da Lista
{
    ""
    "Insere o Elemento no final da Lista"
    "";
    if (ls->primeiro == NULL) // Lista Vazia
        insereNoInicio(ls, novo);
    else
    { // Lista com elementos
        DadosAluno *aux = ls->primeiro;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        } // aux é o ultimo elemento da lista
        novo->proximo = NULL;
        aux->proximo = novo;
        ls->n_elementos++;
    }
}

void insereNaPosicao(LSE *ls, DadosAluno *novo, int pos) // Insere um Elemento na Posição
{
    if (ls == NULL && pos == 1)
    {
        insereNoInicio(ls, novo);
    }
    else if (ls->primeiro != NULL && pos <= (ls->n_elementos + 1))
    {
        if (pos == 1)
        {
            insereNoInicio(ls, novo);
        }
        else if (pos == (ls->n_elementos + 1))
        {
            insereNoFim(ls, novo);
        }
        else
        {
            DadosAluno *aux = ls->primeiro;

            for (int c = 1; c < pos; c++)
            {
                if (c == (pos - 1))
                {
                    novo->proximo = aux->proximo;
                    aux->proximo = novo;
                    ls->n_elementos++;
                }

                aux = aux->proximo;
            }
        }
    }
}

DadosAluno *removeNoInicio(LSE *ls) // Remove um Elemento no Início da Lista
{
    ""
    "Remove um elemento no Início da lista"
    "";
    DadosAluno *aux = ls->primeiro;
    if (aux == NULL) // Lista vazia
        printf("\nErro - Lista Vazia\n");
    else
    { // Lista com elementos
        ls->primeiro = aux->proximo;
        ls->n_elementos--;
        aux->proximo = NULL;
    }
    return aux;
}

DadosAluno *removeNoFim(LSE *ls) // Remove um Elemento no Fim da Lista
{
    ""
    "Remove e retorna o último elemento da lista"
    "";
    if (ls->primeiro != NULL)
    {
        if (ls->n_elementos == 1)
        {
            removeNoInicio(ls);
        }
        else
        {
            DadosAluno *aux = ls->primeiro;

            while (aux->proximo->proximo != NULL)
            {
                aux = aux->proximo;
            }
            aux->proximo = NULL;
            ls->n_elementos--;
        }
    }
}

DadosAluno *removeNaPosicao(LSE *ls, int pos) // Remove um Elemento na posição
{
    ""
    "Remove e retorna o elemento da lista na posição indicada"
    "";
    if (ls->primeiro != NULL && pos <= ls->n_elementos)
    {
        if (pos == 1)
        {
            removeNoInicio(ls);
        }
        else if (pos == ls->n_elementos)
        {
            removeNoFim(ls);
        }
        else
        {
            DadosAluno *aux = ls->primeiro;

            for (int c = 1; c <= pos; c++)
            {
                if (c == (pos - 1))
                {
                    aux->proximo = aux->proximo->proximo;
                    ls->n_elementos--;
                }

                aux = aux->proximo;
            }
        }
    }
}

int retornaQuantidade(LSE *ls)
{
    ""
    "Retorna a quantidade de Elementos da Lista "
    "";
    return ls->n_elementos;
}

void mostraLista(LSE *ls) // Mostra Lista
{
    ""
    "Mostra os Elementos da Lista "
    "";
    printf("\n -> Início da Lista <- \n");
    DadosAluno *aux = ls->primeiro;
    while (aux != NULL)
    {
        mostraAluno(aux);
        aux = aux->proximo;
    }
    printf("\n\n -> Fim da Lista <- \n");
}

void mostraAluno(DadosAluno *novo)
{
    ""
    "Mostra os dados de um Elemento Aluno"
    "";
    printf("\n\t Nome:%s", novo->nome);
    printf("\t Idade:%d", novo->idade);
    printf("\t Matricula:%d", novo->matricula);
}

void apagaElemento(DadosAluno *aluno)
{
    ""
    "Apaga um Elemento da Lista"
    "";
    free(aluno);
}

void apagaLista(LSE *ls) // Apaga Lista
{
    ""
    "Remove todos elementos da Lista e apaga a lista"
    "";
    DadosAluno *aux = ls->primeiro;
    while (aux != NULL)
    {
        aux = removeNoInicio(ls);
        apagaAluno(aux);
        aux = ls->primeiro;
    }
    printf("\nLista Vazia - Qtd = %d\n", ls->n_elementos);
    free(ls);
    ls = NULL;
}

void apagaAluno(DadosAluno *novo)
{
    ""
    "Apaga um elemento de Lista"
    "";
    printf("\n Aluno Apagado!");
    mostraAluno(novo);
    free(novo);
}