/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Codigo-Fonte de um programa de testes para a funcao "CalcularMaximoDivisorComum".
 *
 * $Author: joao.vitor $
 * $Date: 2024/05/03 18:55:16 $
 * $Log: aula0202.c,v $
 * Revision 1.3  2024/05/03 18:55:16  joao.vitor
 * Adicao da descricao do codigo-fonte
 *
 * Revision 1.2  2024/05/03 17:42:45  joao.vitor
 * Adicao da macro ERRO_NUMEROS_INSERIDOS_IGUAIS_A_ZERO
 *
 * Revision 1.1  2024/05/03 03:25:48  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Definicoes importantes para a utilizacao da funcao "strtoull" e do valor "ULLONG_MAX".*/
#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

/*Include's.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "cores.h"
#include "aula0201.h"

/*Definicao das Macros.*/
#define SUCESSO								0
#define NUMERO_ARGUMENTOS_VALIDOS					3
					
#define NUMEROS_ARGUMENTOS_INVALIDOS					1
#define ARGUMENTO_INSERIDO_INVALIDO					2
#define NUMERO_ULTRAPASSOU_VALOR_MAXIMO_LONG_LONG_UNSIGNED		3
#define INSERIDO_NUMERO_NEGATIVO					4
#define ERRO_NUMEROS_INSERIDOS_IGUAIS_A_ZERO				5

#define END_OF_STRING							'\0'


/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	ull primeiroValorInserido;
	ull segundoValorInserido;
	ull valorMaximoDivisorComum;
	char *validacaoPrimeiroNumero;
	char *validacaoSegundoNumero;

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if (argc != NUMERO_ARGUMENTOS_VALIDOS)
	{
		printf ("\n%sErro! Numero invalido de argumentos.%s\n\n", RED, RESET);
		exit (NUMEROS_ARGUMENTOS_INVALIDOS);
	}
	
	/*Converte as strings inseridas em valores inteiros do tipo unsigned long long.*/
	primeiroValorInserido = strtoull(argv [1], &validacaoPrimeiroNumero, 10);	
	segundoValorInserido = strtoull(argv [2], &validacaoSegundoNumero, 10);
	
	/*Caso algum dos argumentos inseridos nao for um numero, aparecera uma mensagem de erro.*/
	if ((*validacaoPrimeiroNumero != END_OF_STRING) || (*validacaoSegundoNumero != END_OF_STRING))
	{
		printf ("\n%sErro! Argumento(s) inserido(s) invalido(s).%s\n\n", RED, RESET);
		exit (ARGUMENTO_INSERIDO_INVALIDO);
	}
	
	/*Caso algum dos numeros inseridos for negativo, aparecera uma mensagem de erro.*/
	if ((argv [1][0] == '-') || (argv [2][0] == '-'))
	{
		printf ("\n%sErro! Por favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (INSERIDO_NUMERO_NEGATIVO);
	}	
	
	/*Caso os valores inseridos ultrapassarem o limite do tipo long long unsigned, aparecera uma mensagem de erro.*/
	if (errno == ERANGE)
	{ 
		printf ("\n%sErro! Limite do tipo Long Long Unsigned excedido (%llu).%s\n\n", RED, ULLONG_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_VALOR_MAXIMO_LONG_LONG_UNSIGNED);
	}

	/*Armazena o valor do Maximo Divisor Comum entre os dois numeros inseridos.*/
	valorMaximoDivisorComum = CalcularMaximoDivisorComum(primeiroValorInserido, segundoValorInserido);

	/*Caso o valor retornado pela funcao for zero, aparecera uma mensagem de erro, alertando uma divisao por zero entre os numeros inseridos.*/
	if (valorMaximoDivisorComum == NUMEROS_INSERIDOS_IGUAIS_A_ZERO)
	{	
		printf ("\n%sErro! Pelo menos um dos numeros deve ser diferente de zero.%s\n\n", RED, RESET);
		exit (ERRO_NUMEROS_INSERIDOS_IGUAIS_A_ZERO);
	}

	/*Caso o valor retornado pela funcao for diferente de zero, aparecera o valor do Maximo Divisor Comum na tela.*/
	else
		printf ("\n%sMDC (%llu, %llu) = %llu%s\n\n", GREEN, primeiroValorInserido, segundoValorInserido, valorMaximoDivisorComum, RESET);

	return SUCESSO;
}
















/* $RCSfile: aula0202.c,v $ */
