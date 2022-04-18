#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>	
#include <locale.h> 
#include <string.h>

// Funções

void menuPrincipal();
void limpaBuffer();
void menuControleLocacao();
void menuCadCarro();
void cadCarro();
void gravaCarro();
void listaCarroDisponivel();
void listaLocacao();
void novaLocacao();
void gravaLocacao();
void menuCadCliente();
void gravaCliente();
void listaCliente();
void removeCliente();
void cadCliente();
void pesquisarCliente();
void pesquisarCarro();
void menuDevolucao();
void cadastrarDevolucao();
void removeCarro();

// Variáveis

int op;
char valida;
int juridica, empresaParceira, diarias, cortesia, continuar, contador_geral = 1, escolha_cliente, escolha_carro;
float valorTotal, descontoTotal, valorAluguel, desconto;
int escolhaCar, escolha;

int i, aux;
int totaldias;
int anot, mest, diat;

int hora[2], min[2];
int dia[2];
int mes[2];
int ano[2];

// Structs

//----------Struct do aluguel----------

typedef struct aluguel
{

	char *aplaca;
	char *clienteCpf;
} Alugar;
Alugar alugar[1000];
int a, cont_a = 0;

//----------Struct da devolucao----------

typedef struct devolucao
{
	char *placaCar;

} Cadastro_devolucao;
Cadastro_devolucao devolucao[1000];
int d;
int escolhaCli, cont_d = 0;
float multa;

//----------Struct do carro----------

typedef struct carro
{
	char modelo[50];
	char marca[50];
	char cor[50];
	unsigned int ano;
	char placa[7];
	int estado; // 0 = disponivel 1 = alugado
	float valorDiaria;
} Cadastro_carro;

Cadastro_carro carro[1000];
int c, cont_c = 0;

//----------Struct do cliente----------

typedef struct cliente
{
	char nomec[50];
	char cpf[15];
	int idade;
	char endereco[99];
} Cadastro_cliente;

Cadastro_cliente cliente[1000];
int C, cont_C = 0;

int main(int argc, char *argv[])
{

	int menu, i, continuar, contador_geral = 1, escolha_cliente, escolha_carro;

inicio: // Rótulo

	do
	{
		menuPrincipal();
		printf("Selecione uma das opções do menu:\n");
		scanf(" %d", &op);
		printf("\n");
		fflush(stdin); // Limpar o buffer do teclado.

		switch (op)
		{
		case 1:
			goto cadCarro;
			break;
		case 2:
			goto cadCliente;
			break;
		case 3:
			goto locacao;
			break;
		case 4:
			goto devolucao;
			break;
		case 0:
			printf("Deseja encerrar o sistema?  ([S] - Sim / [N] - Não) \n");
			scanf("%c", &valida);
			valida = toupper(valida); // toupper converte o que for digitado para maiúsculo
			fflush(stdin);			  // Limpar o buffer do teclado.
			if (valida == 'S')
			{
				exit(0);
			}
			else if (valida == 'N')
			{
				goto inicio; // Retorna ao menu inicial
			}
			else if (valida != 'S' && valida != 'N')
			{
				printf("Selecione corretamente uma das opções! ([S] - Sim / [N] - Não) \n\n\n");
				system("pause");
				fflush(stdin);
				goto inicio;
			}
			break;

		default:
			printf("Selecione uma das opções contidas no menu acima.\n\n");
			system("\n\npause");
			goto inicio;
			break;
		}

		return 0;
	} // do
	while (valida != '6');

	// Menu controle de locação

locacao:
	menuControleLocacao();
	printf("\nSelecione uma das opções do menu:\n");
	scanf(" %d", &op);
	printf("\n");
	fflush(stdin);
	switch (op)
	{
	case 1:
		while (cont_c == 0 || cont_C == 0)
		{
			printf("\n Cadastre pelo menos um carro e um cliente para continuar! \n");
			system("pause");
			goto inicio;
		}
		novaLocacao();
		system("pause");
		goto locacao;
		break;
	case 2:
		listaLocacao();
		goto locacao;
		break;
	case 0:
		goto inicio; // Retorna ao menu inicial
		break;
	default:
		printf("Selecione uma das opções contidas no menu acima.\n\n");
		system("\n\npause");
		goto locacao; // Retorna ao menu de opções
		break;
	}

// Menu devolução

devolucao:
	menuDevolucao();
	printf("\nSelecione uma das opções do menu:\n");
	scanf("%d", &op);
	printf("\n");
	fflush(stdin);
	switch (op)
	{
	case 1:
		if (cont_a == 0)
		{
			printf("Deve haver pelo menos um carro alugado\n");
		}
		else
		{
			cadastrarDevolucao();
		}
		goto devolucao;
		break;
	case 0:
		goto inicio;
		break;
	default:
		printf("Selecione uma das opções contidas no menu acima.\n\n");
		system("\n\npause");
		goto devolucao; // Retorna ao menu de op��es
		break;
	}
	
	// Menu Controle de clientes

cadCliente:
	menuCadCliente();
	printf("\nSelecione uma das opções do menu:\n");
	scanf(" %d", &op);
	printf("\n");
	fflush(stdin);
	switch (op)
	{
	case 1:
		gravaCliente();
		goto cadCliente;
		break;
	case 2:
		if (cont_C == 0)
		{
			printf("Nenhum cliente cadastrado \n");
		}
		else
		{
			removeCliente();
			goto cadCliente;
		}
		break;
	case 3:
		listaCliente();
		goto cadCliente;
		break;
	case 0:
		goto inicio;
		break;
	default:
		printf("Selecione uma das opções do menu acima.\n\n");
		system("\n\npause");
		goto cadCliente; // Retorna ao menu de opções
		break;
	}

	// Menu Controle de carro

cadCarro: 
	menuCadCarro();
	printf("\nSelecione uma das opções do menu:\n");
	scanf(" %d", &op);
	printf("\n");
	fflush(stdin); // Limpar o buffer do teclado.
	switch (op)
	{
	case 1:
		gravaCarro();
		goto cadCarro;
		break;
	case 2:
		if (cont_c == 0 || (carro[c].estado == 0) == 0)
		{
			printf("Nenhum carro cadastrado ou estão todos locados \n");
		}
		else
		{
			removeCarro();
			goto cadCarro;
		}
		break;
	case 3:
		listaCarroDisponivel();
		goto cadCarro;
		break;
	case 4:
		listaLocacao();
		goto cadCarro;
		break;
	case 0:
		goto inicio;
		break;
	default:
		printf("Selecione uma das opções contidas no menu acima .\n\n");
		system("\n\npause");
		goto cadCarro;
		break;
	}

}

// Menu Principal

void menuPrincipal() 
{
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf(" Locação de veículos Acosta's Car\n\n");
	printf("***************************************\n");
	printf("***************************************\n\n");
	

	printf("Menu Principal:\n\n");
	printf("[1] -> Controle de Veículos \n");
	printf("[2] -> Controle de Clientes \n");
	printf("[3] -> Controle de Locações \n");
	printf("[4] -> Fazer Devolução \n");
	printf("[0] -> Sair \n\n");
}

// Locação

void novaLocacao()
{
	if ((carro[c].estado == 0) == 0)
	{
		printf("Nenhum veículo disponível para locar \n");
	}
	else
	{
		do
		{
			contador_geral = 1;
			listaCarroDisponivel();

			printf("\n Número do veículo:\n"); 
			scanf("%d", &escolha_carro);
			fflush(stdin);
			c = escolha_carro - 1;
			carro[c].estado = 1;
			alugar[a].aplaca = carro[c].placa;

			printf("Placa do veículo: %s \n", alugar[a].aplaca);
			printf("Valor da diária para esse veículo: %.2f \n\n", carro[c].valorDiaria);

			printf("Digite a quantidade de diarias que deseja contratar: \n");
			scanf("%d", &diarias);

			valorAluguel = diarias *carro[c].valorDiaria;
			printf("O cliente é empresa parceira da Acosta's Car? [1]-Sim [0]-Não \n");
			scanf("%d", &empresaParceira);
			if (empresaParceira == 1)
			{
				printf("Por ser empresa parceira, o cliente receberá um desconto de 5 por cento \n\n");
				desconto = 5.00;
			}
			system("pause");

			contador_geral = 1;
			listaCliente();
			printf("\nNúmero do cliente:\n"); 
			scanf("%d", &escolha_cliente);
			fflush(stdin);
			C = escolha_cliente - 1;
			alugar[a].clienteCpf = cliente[C].cpf;

			printf("Digite o dia da locação: \n"); 
			scanf("%d", &dia[0]);
			fflush(stdin);
			printf("Digite o mês da locação: \n");
			scanf("%d", &mes[0]);
			fflush(stdin);
			printf("Digite o ano da localção: \n");
			scanf("%d", &ano[0]);
			fflush(stdin);
			printf("Digite a horas da locação: \n");
			scanf("%d", &hora[0]);
			fflush(stdin);
			printf("Digite os minutos da locaçao: \n");
			scanf("%d", &min[0]);
			fflush(stdin);
			printf("Digite o dia previsto da devolução: \n");
			scanf("%d", &dia[1]);
			fflush(stdin);
			printf("Digite o mês previsto da devolução: \n");
			scanf("%d", &mes[1]);
			fflush(stdin);
			printf("Digite o ano previsto da devolução: \n");
			scanf("%d", &ano[1]);
			fflush(stdin);
			printf("Digite a horas prevista da devolução: \n");
			scanf("%d", &hora[1]);
			fflush(stdin);
			printf("Digite os minutos previsto da devolução: \n");
			scanf("%d", &min[1]);
			fflush(stdin);

			if (diarias >= 5)
			{
				printf("\n\n O cliente tem direito a uma diária grátis a mais, deseja utilizar esta cortesia? 1-Sim 2-Não \n\n");
				scanf("%d", &cortesia);
				if (cortesia == 1)
				{
					printf("O cliente aderiu a cortesia \n\n");
					diarias = diarias + 1;
					dia[1] = dia[1] + 1;
				}
			}

			if (cliente[C].idade >= 65)
			{
				printf("Pela idade do cliente ser maior que 65 terá direito a desconto de 10% \n");
				desconto = 10.00;
			}
			descontoTotal = valorAluguel * (desconto / 100);
			valorTotal = valorAluguel - descontoTotal;
			printf("Valor da locação: %.2f \n", valorAluguel);
			if (desconto > 0)
			{
				printf("Valor sem desconto: %.2f \n", valorAluguel);
				printf("Valor com desconto: %.2f \n ", descontoTotal);
			}

			printf("\nO Cliente efetuou o pagamento de %.2f ? 1-Sim 0-Não \n ", valorTotal);
			scanf("%d", &op);
			while (op == 0)
			{
				printf("O sistema não pode concluir a locação enquanto não houver o pagamento do valor de %.2f \n", valorTotal);
				printf("O Cliente efetuou o pagamento de %.2f ? 1-Sim 0-Não \n ", valorTotal);
				scanf("%d", &op);
			}

			a++;
			printf("****[Ticket de Locação]*****\n");
			printf("Nome do cliente: %s \n", cliente[C].nomec);
			printf("CPF do cliente: %s \n", cliente[C].cpf);
			printf("Endereço do cliente: %s \n", cliente[C].endereco);
			printf("Idade do cliente: %d \n", cliente[C].idade);
			printf("Diárias Contratadas: %d \n", diarias);
			printf("Valor da locação(Pago): %.2f \n", valorTotal);
			printf("Data da Locação: %d/%d/%d \n", dia[0], mes[0], ano[0]);
			printf("Hora da Locação: %d:%d \n", hora[0], min[0]);
			printf("Data de devolução prevista: %d/%d/%d \n", dia[1], mes[1], ano[1]);
			printf("Hora prevista da devolução: %d:%d \n", hora[1], min[1]);
			cont_a++;
			printf("\nLocação cadastrada com sucesso!\n");
			printf("\n[1] - Continuar cadastrando\n[0] - Retornar ao menu principal\n");
			scanf("%d", &continuar);
			fflush(stdin);

		} while (continuar != 0 && continuar == 1 && cont_a < 1000 && (carro[c].estado == 0) == 1);
		
		 //----------Validação do continuar

		if (continuar != 0 && continuar != 1)
		{
			printf("\n*****************[OPÇÃO INVÁLIDA]*****************\n\n\a");
		}
		if (cont_a == 1000)
		{ //Verificação da quantidade de cadastros

		printf("\n*************[Número máximo de locação cadastrados atingido!]*************\n\n\a");
		}
		if (cont_c == 0)
		{
			printf("\n*************[Nenhum veículo cadastrado!]*************\n\n\a");
		}
	}
}

// cadastro de devolução

void cadastrarDevolucao()
{
	if ((carro[c].estado == 1) == 0)
	{
		printf("Nenhum veículo locado para devolver \n");
	}
	else
	{
		do
		{
			listaLocacao();

			printf("Digite o número da locação:\n");
			scanf("%d", &escolhaCar);
			fflush(stdin);
			d = escolhaCar - 1;
			carro[c].estado = 0; // muda o estado para disponivel
			devolucao[d].placaCar = carro[c].placa;

			printf("Placa do veículo: %s \n", devolucao[d].placaCar);

			// Manipulação de horas

			int mintotal(int hora, int minuto)
			{
				int r = (hora * 60) + minuto;
				return r;
			}
			int r1, r2, total, horas;

			r1 = mintotal(hora[1], min[1]);

			printf("Digite o dia da devolução: \n");
			scanf("%d", &dia[2]);
			fflush(stdin);
			printf("Digite o m�s da devolução: \n");
			scanf("%d", &mes[2]);
			fflush(stdin);
			printf("Digite o ano da devolução: \n");
			scanf("%d", &ano[2]);
			fflush(stdin);
			printf("Digite a horas da devolução: \n");
			scanf("%d", &hora[2]);
			fflush(stdin);
			printf("Digite o minutos da devolução: \n");
			scanf("%d", &min[2]);
			fflush(stdin);

			r2 = mintotal(hora[2], min[2]);
			total = r2 - r1;
			horas = total / 60;
			if (total < 0)
			{
				total += 1440; // calculo
				printf("%d Horas de diferença!\n\n", horas);
			} // impressão do resultado
			else
				printf("%d Horas de diferençaa!\n\n", horas);

			if (horas > 0)
			{
				multa = diarias * (horas / 24);
				printf("Por haver atraso na devolução o cliente receberá uma multa de: %.2f \n", multa);
			}

			printf("O Cliente efetuou o pagamento de %.2f ? [1]-Sim [0]-Não \n ", multa);
			scanf("%d", &op);
			while (op == 0)
			{
				printf("O sistema não pode concluir a devolução enquanto não houver o pagamento da multa por atraso de %.2f \n", multa); // nao aparece o valor da multa, em andamento
				printf("O Cliente efetuou o pagamento de %.2f ? [1]-Sim [0]-Não \n ", multa);
				scanf("%d", &op);
			}
			d++;
			cont_a--;
			carro[c].estado = 0;

			system("pause");
			printf("Devolução feita com sucesso! \n\n");
			printf("\n[1] - Continuar devolvendo veículos \n [0] - Retornar ao menu principal\n");
			scanf("%d", &continuar);
			fflush(stdin);

		} while (continuar != 0 && continuar == 1 && cont_a > 0); 
		if (continuar != 0 && continuar != 1)
		{
			printf("\n*****************[OPÇÃO INVÁLIDA]*****************\n\n\a");
		}
	}
}

// Menu controle de devolução

void menuControleDevolucao() 
{
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf(" Locação de veículos Acosta's Car\n\n");
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf("*****[Controle de Devolução]*****\n\n");
	printf("[1] -> Devolver Veículo \n");
	printf("[2] -> Listar Devoluções  \n");
	printf("[0] -> Voltar ao Menu Anterior \n");
}

// Listar devolução
void menuDevolucao()
{
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf(" Locação de veículos Acosta's Car\n\n");
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf("*****[Controle de devolução]***** \n\n");
	printf("[1] -> Cadastrar devolução \n");
	printf("[0] -> Menu Principal \n");
}
// Controle de locação

void menuControleLocacao()
{
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf(" Locação de veículos Acosta's Car\n\n");
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf("*****[Controle de Alocação]*****\n\n");
	printf("[1] -> Cadastrar nova locação. \n");
	printf("[2] -> Listar Locações . \n");
	printf("([0] -> Voltar ao Menu Anterior. \n");
}

// Menu Controle de veículos

void menuCadCarro() 
{
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf(" Locação de veículos Acosta's Car\n\n");
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf("*****[Controle de Veículos]*****\n\n");
	printf("[1] -> Incluir novo veículo. \n");
	printf("[2] -> Remover Veículo. \n");
	printf("[3] -> Listar Veículos Disponíveis. \n");
	printf("[4] -> Listar Veículos Locados. \n");
	printf("[0] -> Voltar ao Menu Anterior. \n");
}
/// Menu Controle de clientes

void menuCadCliente()
{
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf(" Locação de veículos Acosta's Car\n\n");
	printf("***************************************\n");
	printf("***************************************\n\n");
	printf("*****[Controle de Clientes]****\n\n");
	printf("[1] -> Incluir Novo Registro. \n");
	printf("[2] -> Remover Registro. \n");
	printf("[3] -> Listar Clientes\n");
	printf("[0] -> Voltar ao Menu Anterior. \n");
}

// Função para gravar registro de carro

void gravaCarro() 
{
	do
	{
		printf("Digite a marca do carro:\n");
		gets(carro[c].marca);
		fflush(stdin);
		printf("Digite o modelo do carro:\n");
		gets(carro[c].modelo);
		fflush(stdin);
		printf("Digite a cor do carro:\n");
		gets(carro[c].cor);
		fflush(stdin);
		printf("Digite o ano do carro:\n");
		scanf("%d", &carro[c].ano);
		fflush(stdin);
		printf("Digite a placa do carro:\n");
		gets(carro[c].placa);
		fflush(stdin);
		printf("Digite o valor da diária para este veículo:\n");
		scanf("%f", &carro[c].valorDiaria);
		fflush(stdin);

		c++;
		cont_c++;
		carro[c].estado = 0; //----------Coloca o veículo como disponível para locar----------

		printf("\nCarro cadastrado com sucesso!\n");
		printf("\n1 - Continuar cadastrando\n0 - Menu princial\n");
		scanf("%d", &continuar);
		fflush(stdin);
		if (cont_c == 1000)
		{ //----------Verificação da quantidade de cadastros
		printf("\n*************[Número máximo de veículos cadastrados atingido!]*************\n\n\a");
		}
		if (continuar != 0 && continuar != 1)
		{
			printf("\n*****************[OPÇÃO INVÁLIDA]*****************\n\n\a");
		}
	} while (continuar != 0 && continuar == 1 && cont_c < 1000); //----------Validação do continuar
}
//  Listar locações

void listaLocacao()
{
	for (a = 0; a < cont_a; a++)
	{
		if (carro[c].estado == 1)
		{
			printf("***********[Locações]************\n");
			printf("Número - %d\n", contador_geral);
			printf("Modelo:%s \n", carro[c].modelo);
			printf("Marca:%s \n", carro[c].marca);
			printf("Placa:%s \n", carro[c].placa);
			printf("Ano:%d \n", carro[c].ano);
			printf("Cor:%s \n", carro[c].cor);
			printf("Preço da diaria:%.2f \n", carro[c].valorDiaria);
			printf("Dados do cliente que esta locando: \n");
			printf("Nome do cliente: %s \n", cliente[C].nomec);
			printf("CPF do cliente: %s \n", cliente[C].cpf);
			printf("Endereço do cliente: %s \n", cliente[C].endereco);
			printf("Idade do cliente: %d \n", cliente[C].idade);
			printf("Diárias Contratadas: %d \n", diarias);
			printf("Valor do Aluguel(Pago): %.2f \n", valorTotal);
			printf("Data da Locação: %d/%d/%d \n", dia[0], mes[0], ano[0]);
			printf("Hora da Locação: %d:%d \n", hora[0], min[0]);
			printf("Data de devolução prevista: %d/%d/%d \n", dia[1], mes[1], ano[1]);
			printf("Hora prevista da devolução: %d:%d \n", hora[1], min[1]);
			printf("**************************************************************\n");
			contador_geral++;
		}
		if ((carro[c].estado == 1) == 0)
		{
			printf("Nenhum veículo locado \n");
			system("pause");
		}
		contador_geral = 1;
		printf("\n\n***************[Fim do relatório]***************\n\n");
		system("pause");
	}
	if ((carro[c].estado == 1) == 0)
	{
		printf("Nenhum veículo locado \n");
		system("pause");
	}
}
// lstar carros disponiveis

void listaCarroDisponivel()
{
	for (c = 0; c < cont_c; c++)
	{
		if (carro[c].estado == 0)
		{
			printf("***********[Carros Disponíveis]************\n");
			printf("Número - %d\n", contador_geral);
			printf("Modelo:%s \n", carro[c].modelo);
			printf("Marca:%s \n", carro[c].marca);
			printf("Placa:%s \n", carro[c].placa);
			printf("Ano:%d \n", carro[c].ano);
			printf("Cor:%s \n", carro[c].cor);
			printf("Preço da diária:%2.2f \n", carro[c].valorDiaria);
			printf("********************************************\n");
			contador_geral++;
		}
		if ((carro[c].estado == 0) == 0)
		{
			printf("Nenhum veículo disponível \n");
			system("pause");
		}
		contador_geral = 1;
	}
	printf("\n\n***************[Fim do relatório]***************\n\n");
	system("pause");
}
// remover cliente

void removeCliente()
{
	do
	{
		listaCliente();
		printf("Remover Cliente \n\n");
		printf("Digite o número do cliente:\n");
		scanf("%d", &escolha);
		fflush(stdin);
		C = escolha - 1;
		printf("Deseja realmente remover este cliente [1]-Sim [0]-Não \n");
		scanf("%d", &op);
		if (op == 0)
		{
			printf("Remoção cancelada \n");
			system("pause");
		}
		else
		{
			C--;
			cont_C--;
			printf("Cliente removido com sucesso \n");
			printf("\n [1] - Continuar removendo\n [0] - Retornar ao Menu principal\n");
			scanf("%d", &continuar);
			fflush(stdin);

			if (continuar != 0 && continuar != 1)
			{
				printf("\n*****************[OPÇÃO INVÁLIDA]*****************\n\n\a");
			}
		}
	} while (continuar != 0 && continuar == 1 && cont_C > 0);
}
// remover veículo

void removeCarro()
{
	do
	{
		listaCarroDisponivel();
		printf("Remover Veículo \n\n");
		printf("Digite o número do veículo:\n");
		scanf("%d", &escolha);
		fflush(stdin);
		c = escolha - 1;
		if (carro[c].estado == 1)
		{
			printf("Veículo locado no momento, devolva-o primeiro para continuar \n");
		}
		else
		{
			printf("Deseja realmente remover este veículo? [1]-Sim [0]-Não \n");
			scanf("%d", &op);
			if (op == 0)
			{
				printf("Remoção cancelada \n");
				system("pause");
			}
			else
			{
				c--;
				cont_c--;
				printf("Veículo removido com sucesso \n");
				printf("\n [1] - Continuar removendo\n [0] - Retornar ao Menu principal\n");
				scanf("%d", &continuar);
				fflush(stdin);

				if (continuar != 0 && continuar != 1)
				{
					printf("\n*****************[OPÇÃO INVALIDA]*****************\n\n\a");
				}
			}
		}
	} while (continuar != 0 && continuar == 1 && cont_c > 0);
}
// // Função para gravar registro de Clientes

void gravaCliente() 
{
	do
	{
		printf("Digite o nome completo do cliente:\n");
		gets(cliente[C].nomec);
		fflush(stdin);

		printf("Digite o CPF do cliente:\n");
		gets(cliente[C].cpf);
		fflush(stdin);

		printf("Digite a idade do cliente:\n");
		scanf("%d", &cliente[C].idade);
		fflush(stdin);

		printf("Digite o endereço do cliente: ");
		gets(cliente[C].endereco);
		fflush(stdin);

		cont_C++;
		C++;

		printf("\nCliente cadastrado com sucesso!\n");
		printf("\n [1] - Continuar cadastrando\n [0] - Retornar ao Menu anterior\n");
		scanf("%d", &continuar);
		fflush(stdin);

		if (cont_C == 1000)
		{ //----------Verifica��o da quantidade de cadastros
		printf("\n*************[Número máximo de clientes cadastrados atingido!]*************\n\n\a");
		}
		if (continuar != 0 && continuar != 1)
		{
			printf("\n*****************[OPÇÃO INVÁLIDA]*****************\n\n\a");
		}
	} while (continuar != 0 && continuar == 1 && cont_c < 1000);
}

// lista de clientes

void listaCliente()
{
	for (C = 0; C < cont_C; C++)
	{
		printf("\n\n***************[Dados do cliente]***************\n\n");
		printf("Número do cliente: %d \n", contador_geral);
		printf("Nome: %s\n", cliente[C].nomec);
		printf("CPF: %s\n", cliente[C].cpf);
		printf("Endereço: %s\n", cliente[C].endereco);
		printf("Idade:%d \n", cliente[C].idade);
		contador_geral++;
	}
	printf("**********************************************************\n");
	contador_geral = 1;
	printf("\n\n***************[Fim do relatório]***************\n\n");
	system("pause");
}

void limpaBuffer() // função personalizada para limpeza de buffer do teclado
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}
