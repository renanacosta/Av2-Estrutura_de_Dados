#include <stdio.h>
#include <stdlib.h>
#include "LSE.c"

int menu(LSE *ls);

int main()
{

    LSE *ListaMatematica = criaListaLSE();

    insereNoInicio(ListaMatematica, cadastraAluno("Pedro", 44, 11230000));
    insereNoInicio(ListaMatematica, cadastraAluno("Paulo", 34, 11230001));

    insereNoFim(ListaMatematica, cadastraAluno("Maria", 60, 11230002));
    insereNoFim(ListaMatematica, cadastraAluno("Beatriz", 38, 11230003));

    mostraLista(ListaMatematica);

    int op = 1;
    while (op != 0)
    {
        op = menu(ListaMatematica);
    };
    return (1);
}

int menu(LSE *ls)
{
    printf("\n");
    printf("===================================================\n");
    printf("           ->  MENU DE OPERAÇÕES LSE  <-           \n");
    printf("===================================================\n");
    printf("\n");
    printf("[ 1 ] - Inserir um Elemento no Início:\n");
    printf("[ 2 ] - Inserir um Elemento no Fim:\n");
    printf("[ 3 ] - Inserir um Elemento na Posição:\n");
    printf("[ 4 ] - Remove um Elemento no Início:\n");
    printf("[ 5 ] - Remove um Elemento no Fim:\n");
    printf("[ 6 ] - Remove um Elemento na Posição:\n");
    printf("[ 7 ] - Mostra Lista:\n");
    printf("[ 8 ] - Apaga um Elemento da Lista:\n");
    printf("[ 9 ] - Apaga a Lista\n");
    printf("[ 0 ] - Fim do Programa - Lista de Chamada:\n");
    printf("\n");
    printf("===================================================\n");
    printf("\n");
    printf("Digite a opção desejada: ");
    int op, pos;
    scanf("%d", &op);
    DadosAluno *novo;
    if (op == 1) // Inserir um Elemento no Início
    {
        novo = lerDadosAluno();
        insereNoInicio(ls, novo);
    }
    else if (op == 2) // Inserir um Elemento no Fim
    {
        novo = lerDadosAluno();
        insereNoFim(ls, novo);
    }
    else if (op == 3) // Inserir um Elemento na Posição
    {
        printf("\nInforme a Posição:");
        scanf("%d", &pos);
        novo = lerDadosAluno();
        insereNaPosicao(ls, novo, pos); // Primeiro elemento = 1
    }
    else if (op == 4) // Remove um Elemento no Início
    {
        novo = removeNoInicio(ls);
    }
    else if (op == 5) // Remove um Elemento no Fim
    {
        novo = removeNoFim(ls);
    }
    else if (op == 6) // Remove um Elemento na Posição
    {
        printf("\nInforme a Posição:");
        scanf("%d", &pos);
        novo = removeNaPosicao(ls, pos);
    }
    else if (op == 7) // Mostra Lista
    {
        mostraLista(ls);
    }
    else if (op == 8) // Apaga um Elemento da Lista
    {
        printf("\nInforme a Posição:");
        scanf("%d", &pos);
        novo = removeNoInicio(ls);
        apagaElemento(novo);
    }
    else if (op == 9) // Apaga a Lista
    {
        apagaLista(ls);
    }
    else if (op == 0) // Fim do Programa
    {
        printf("\nFim do Programa - Lista de Chamada\n");
    }
    return op;
}