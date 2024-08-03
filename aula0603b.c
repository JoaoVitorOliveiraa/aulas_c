/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Codigo-Fonte de um programa de testes para a funcao "ValidarRg".
 *
 * $Author: joao.vitor $
 * $Date: 2024/07/24 22:46:18 $
 * $Log: aula0603b.c,v $
 * Revision 1.2  2024/07/24 22:46:18  joao.vitor
 * alteracao de impressao
 *
 * Revision 1.1  2024/07/24 00:00:19  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Include's.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "cores.h"
#include "aula0601.h"

#define _XOPEN_SOURCE_	1000

/*Definicao das Macros.*/
#define SUCESSO								0
#define NUMERO_ARGUMENTOS_VALIDOS					2 
#define NUMERO_TOTAL_DE_CARACTERES_VALIDOS				12

#define NUMERO_ARGUMENTOS_INVALIDO					1
#define INSERIDO_DIGITO_NEGATIVO					2
#define ERRO_DIGITO_INVALIDO						3
#define NUMERO_CARACTERES_INVALIDO					4

#define END_OF_STRING							'\0'

/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	us indexDosDigitos;
	us contagemDosPontosEHifens;
	us totalDeDigitosInseridos;
	unsigned long digitoInserido;
	byte digitoInseridoConvertido;
	byte matrizDeDigitosInserida [NUMERO_DE_DIGITOS_DO_RG];

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if (argc != NUMERO_ARGUMENTOS_VALIDOS) 
	{
		printf ("\n%sErro! Numero invalido de argumentos.%s\n", RED, RESET);
		printf ("%sUso: ./aula0603b XX.XXX.XXX-X%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	/*Condicao que verifica se foi inserido algum numero negativo.*/
	for (indexDosDigitos = 1; indexDosDigitos < argc; indexDosDigitos++)
	{
		if (argv [indexDosDigitos][0] == '-')
		{
			printf ("\n%sErro! Por favor, insira somente digitos positivos.%s\n\n", RED, RESET);
			exit (INSERIDO_DIGITO_NEGATIVO);
		}
	}

	/*Estrutura de Repeticao que quantifica quantos digitos foram inseridos, incluindo os pontos.*/
	for (totalDeDigitosInseridos = 0; argv [1][totalDeDigitosInseridos] != END_OF_STRING; totalDeDigitosInseridos++)
		continue;

	/*Condicao que valida a quantidade de digitos inserida.*/
	if (totalDeDigitosInseridos != NUMERO_TOTAL_DE_CARACTERES_VALIDOS)
	{
		
		printf ("\n%sErro! Numero invalido de caracteres. Por favor, insira 8 digitos (com pontos apos o segundo e quinto numero, e hifen apos o oitavo numero).%s\n", RED, RESET);
		printf ("%sUso: ./aula0602a XX.XXX.XXX-X%s\n\n", RED, RESET);
		exit (NUMERO_CARACTERES_INVALIDO);
	}

	/*Variavel que conta os pontos '.' inseridos.*/
	contagemDosPontosEHifens = 0;

	/*Coloca os digitos inseridos em uma matriz.*/
	for (indexDosDigitos = 0; indexDosDigitos < NUMERO_TOTAL_DE_CARACTERES_VALIDOS; indexDosDigitos++)
	{
		/*Condicao que verifica os pontos inseridos.*/
		if ((argv [1][indexDosDigitos] == '.') || (argv [1][indexDosDigitos] == '-'))
		{
			contagemDosPontosEHifens += 1;
			continue;
		}		
		
		/*Armazena os valores de cada digito, subtraindo o valor do zero da tabela tabela ascii.*/
		digitoInserido = argv [1][indexDosDigitos] - '0';	
		
		/*Caso algum digito seja maior que nove ou menos que zero, aparecera uma mensagem de erro.*/	
		if ((digitoInserido > 9) || (digitoInserido < 0))
		{
			printf ("\n%sErro! Digito Invalido: (%c).%s\n\n", RED, argv [1][indexDosDigitos], RESET);
			exit (ERRO_DIGITO_INVALIDO);
		}

		/*Armazena o valor da conversao de tipo do digito inserido (long unsigned para byte).*/
		digitoInseridoConvertido = (byte) digitoInserido;

		matrizDeDigitosInserida [indexDosDigitos - contagemDosPontosEHifens] = digitoInseridoConvertido;
	}

	/*Chamada da funcao "ValidarRg".*/
	ValidarRg (matrizDeDigitosInserida);

	return SUCESSO;
}

/* $RCSfile: aula0603b.c,v $ */
