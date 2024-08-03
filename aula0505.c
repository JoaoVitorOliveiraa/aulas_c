/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Codigo-Fonte de um programa de testes para a funcao "CalcularDeterminanteMatriz".
 *
 * $Author: joao.vitor $
 * $Date: 2024/06/10 07:26:03 $
 * $Log: aula0505.c,v $
 * Revision 1.1  2024/06/10 07:26:03  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Include's.*/
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <float.h>

#include "aula0501.h"

/*Definicao das Macros.*/
#define SUCESSO								0
#define NUMERO_ARGUMENTOS_VALIDOS					2 + (NUMERO_MAXIMO_LINHAS * NUMERO_MAXIMO_COLUNAS)
					
#define NUMERO_ARGUMENTOS_INVALIDO					1
#define ARGUMENTO_INSERIDO_INVALIDO					2
#define NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED_LONG				3
#define INSERIDO_NUMERO_NEGATIVO					4
#define NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED_INT				5
#define NUMERO_ULTRAPASSOU_LIMITE_LONG_DOUBLE				6

#define END_OF_STRING							'\0'

/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	us linha, coluna;
	us indexInicial, ordemDaMatrizConvertida;
	ld determinante;
	unsigned long ordemDaMatrizInserida;
	char *validacaoOrdemDaMatriz, *validacaoMatriz;

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if ((argc > NUMERO_ARGUMENTOS_VALIDOS) || (argc < 3))
	{
		printf ("\n%sErro! Numero invalido de argumentos.%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	/*Converte a ordem da matriz inserida em um valor real do tipo unsigned long.*/
	ordemDaMatrizInserida = strtoul(argv [1], &validacaoOrdemDaMatriz, 10);
	
	/*Caso o tamanho inserido nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoOrdemDaMatriz != END_OF_STRING)
	{
		printf ("\n%sErro! Ordem da matriz invalida.%s\n\n", RED, RESET);
		exit (ARGUMENTO_INSERIDO_INVALIDO);
	}

	/*Caso a ordem da matriz inserida for negativa, aparecera uma mensagem de erro.*/
	if (argv [1][0] == '-')
	{
		printf ("\n%sErro! A ordem da matriz nao pode ser negativa.%s\n\n", RED, RESET);
		exit (INSERIDO_NUMERO_NEGATIVO);
	}	

	/*Caso a ordem da matriz ultrapasse o limite do tipo unsigned long, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! A ordem da matriz inserida excedeu o limite do tipo Unsigned Long (%lu).%s\n\n", RED, ULONG_MAX, RESET); 
		exit (NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED_LONG);
	}
	
	/*Caso o tamanho da ordem da matriz esteja fora do limite do tipo unsigned int, aparecera uma mensagem de erro.*/
	if (ordemDaMatrizInserida > USHRT_MAX)
	{ 
		printf ("\n%sErro! A ordem da matriz ultrapassou o limite do tipo Unsigned Short (%d).%s\n\n", RED, USHRT_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED_INT);
	}

	/*Armazena o valor da conversao de tipo da ordem da matriz (unsigned long para unsigned int).*/
	ordemDaMatrizConvertida = (us) ordemDaMatrizInserida;
	
	/*Inicializacao da matriz.*/
	ld matriz [ordemDaMatrizConvertida][ordemDaMatrizConvertida];
	indexInicial = 2;

	/*Estrutura de Repeticao que valida a matriz inserida.*/
	for (linha = 0; linha < ordemDaMatrizConvertida; linha++)
	{
		for (coluna = 0; coluna < ordemDaMatrizConvertida; coluna++)
		{
			matriz [linha][coluna] = strtold (argv [indexInicial], &validacaoMatriz);
			indexInicial++;

			/*Caso o tenha um argumento que nao seja um numero, aparecera uma mensagem de erro.*/
			if (*validacaoMatriz != END_OF_STRING)
			{
				printf ("\n%sErro! A matriz possui algum argumento invalido.%s\n\n", RED, RESET);
				exit (ARGUMENTO_INSERIDO_INVALIDO);
			}
		}
	}

	/*Caso algum argumento da matriz exceda algum limite do tipo long double, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! Algum argumento da matriz excedeu os limites do tipo long double.%s\n\n", RED, RESET); 
		exit (NUMERO_ULTRAPASSOU_LIMITE_LONG_DOUBLE);
	}

	/*Exibe da matriz e de seu determinante.*/
	printf ("\nMatriz Inserida:\n");
	ExibirMatriz (ordemDaMatrizConvertida, ordemDaMatrizConvertida, matriz);
	CalcularDeterminanteMatriz (ordemDaMatrizConvertida, matriz, &determinante);
	printf ("Determinante da matriz inserida: %Lf.\n\n", determinante);

	return SUCESSO;
}

/* $RCSfile: aula0505.c,v $ */
