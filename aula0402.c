/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Codigo-Fonte de um programa de testes para a funcao "CalcularExponencial".
 *
 * $Author: joao.vitor $
 * $Date: 2024/05/27 04:08:14 $
 * $Log: aula0402.c,v $
 * Revision 1.1  2024/05/27 04:08:14  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Include's.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <float.h>

#include "cores.h"
#include "aula0401.h"

/*Definicao das Macros.*/
#define SUCESSO								0
#define NUMERO_ARGUMENTOS_VALIDOS					3
					
#define NUMEROS_ARGUMENTOS_INVALIDOS					1
#define ARGUMENTO_INSERIDO_INVALIDO					2
#define NUMERO_ULTRAPASSOU_LIMITE_DOUBLE				3
#define NUMERO_ULTRAPASSOU_LIMITE_LONG					4
#define NUMERO_ULTRAPASSOU_LIMITE_INT					5		

#define END_OF_STRING							'\0'

/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	ld valorExponencial;
	double valorBaseInserida;
	int valorExpoenteInserido;
	int valorExpoenteConvertido;
	char *validacaoBase;
	char *validacaoExpoente;

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if (argc != NUMERO_ARGUMENTOS_VALIDOS)
	{
		printf ("\nErro! Numero invalido de argumentos.\n\n");
		exit (NUMEROS_ARGUMENTOS_INVALIDOS);
	}
	
	/*Converte a string inserida em um valor real do tipo double.*/
	valorBaseInserida = strtod(argv [1], &validacaoBase);
	
	/*Caso a base inserida nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoBase != END_OF_STRING)
	{
		printf ("\n%sErro! Base Invalida.%s\n\n", RED, RESET);
		exit (ARGUMENTO_INSERIDO_INVALIDO);
	}
	
	/*Caso a base inserida ultrapasse o limite do tipo double, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! Limite do tipo Double excedido (%f).%s\n\n", RED, DBL_MAX, RESET); 
		exit (NUMERO_ULTRAPASSOU_LIMITE_DOUBLE);
	}

	/*Converte a string inserida em um valor inteiro do tipo long.*/
	valorExpoenteInserido = strtol(argv [2], &validacaoExpoente, 10);
	
	/*Caso o expoente inserido nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoExpoente != END_OF_STRING)
	{
		printf ("\n%sErro! Expoente Invalido.%s\n\n", RED, RESET);
		exit (ARGUMENTO_INSERIDO_INVALIDO);
	}
		
	/*Caso o expoente inserido ultrapasse o limite do tipo long, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! Limite do tipo Long excedido (%ld).%s\n\n", RED, LONG_MAX, RESET); 
		exit (NUMERO_ULTRAPASSOU_LIMITE_LONG);
	}

	/*Caso o expoente inserido esteja fora do limite do tipo int, aparecera uma mensagem de erro.*/
	if ((valorExpoenteInserido > INT_MAX) || (valorExpoenteInserido < INT_MIN))
	{ 
		printf ("\n%sErro! Por favor, insira um expoente que esteja entre os valores %d e %d.%s\n\n", RED, INT_MIN, INT_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_LIMITE_INT);
	}

	/*Armazena o valor da conversao de tipo do expoente inserido (long para int).*/
	valorExpoenteConvertido = (int) valorExpoenteInserido;

	/*Armazena o resultado da funcao.*/
	valorExponencial = CalcularExponencial (valorBaseInserida, valorExpoenteConvertido); 

	/*Quebra de linha.*/
	printf ("\n");

	printf ("%s%s%lf ^ %d:%s%s %Lf%s\n", YELLOW, BLUE_BACKGROUND, valorBaseInserida, valorExpoenteConvertido, RED, WHITE_BACKGROUND, valorExponencial, RESET);

	/*Quebra de linha.*/
	printf ("\n");

	return SUCESSO;
}

/* $RCSfile: aula0402.c,v $ */
