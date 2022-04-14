
typedef struct DadosAluno{
    char nome[100];
    int idade;
    int matricula;
    struct DadosAluno *proximo;
}DadosAluno;

typedef struct lse{
    DadosAluno *primeiro;
    int n_elementos;
}LSE;


LSE* criaListaLSE();

LSE* copiaLista(LSE *ls);

DadosAluno* cadastraAluno(char nome[20],int idade, int matricula);

DadosAluno* lerDadosAluno();

void insereNoInicio(LSE *ls, DadosAluno *novo);

void insereNoFim(LSE *ls, DadosAluno *novo);

void insereNaPosicao(LSE *ls, DadosAluno *novo, int pos);

DadosAluno* removeNoInicio(LSE *ls);

DadosAluno* removeNoFim(LSE *ls);

DadosAluno* removeNaPosicao(LSE *ls, int pos);

int retornaQuantidade(LSE *ls);

void mostraLista(LSE *ls);

void mostraAluno(DadosAluno *novo);

void apagaElemento(DadosAluno *aluno);

void apagaLista(LSE *ls);

void apagaAluno(DadosAluno *novo);
