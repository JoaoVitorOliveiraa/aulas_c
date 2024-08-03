/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Descricao: Codigo-Fonte de um programa de testes para a funcao "ValidarRg".
 *
 * $Author: joao.vitor $
 * $Date: 2024/07/25 02:46:24 $
 * $Log: aula0606b.c,v $
 * Revision 1.1  2024/07/25 02:46:24  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Include's.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cores.h"
#include "aula0604.h"

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
	us totalDeDigitosInseridos;
	us digitoInserido;
	char digito [2];
	char digitosRg [NUMERO_TOTAL_DE_CARACTERES_VALIDOS];

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if (argc != NUMERO_ARGUMENTOS_VALIDOS) 
	{
		printf ("\n%sErro! Numero invalido de argumentos.%s\n", RED, RESET);
		printf ("%sUso: ./aula0606b XX.XXX.XXX-X%s\n\n", RED, RESET);
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
		
		printf ("\n%sErro! Numero invalido de caracteres. Por favor, insira 9 digitos (com pontos apos o segundo e quinto numero, e hifen apos o oitavo numero).%s\n", RED, RESET);
		printf ("%sUso: ./aula0606a XX.XXX.XXX-X%s\n\n", RED, RESET);
		exit (NUMERO_CARACTERES_INVALIDO);
	}

	/*Inicializa cada elemento da string dos digitos do RG como END_OF_STRING.*/
	for (indexDosDigitos = 0; indexDosDigitos < NUMERO_TOTAL_DE_CARACTERES_VALIDOS; indexDosDigitos++)
		digitosRg [indexDosDigitos] = END_OF_STRING;

	/*Coloca os digitos inseridos em uma matriz.*/
	for (indexDosDigitos = 0; indexDosDigitos < NUMERO_TOTAL_DE_CARACTERES_VALIDOS; indexDosDigitos++)
	{
		/*Condicao que verifica os pontos inseridos.*/
		if (!((argv [1][indexDosDigitos] == '.') || (argv [1][indexDosDigitos] == '-')))
		{
			/*Armazena os valores de cada digito, subtraindo o valor do zero da tabela tabela ascii.*/
			digitoInserido = argv [1][indexDosDigitos] - '0';	
		
			/*Caso algum digito seja maior que nove ou menos que zero, aparecera uma mensagem de erro.*/	
			if ((digitoInserido > 9) || (digitoInserido < 0))
			{
				printf ("\n%sErro! Digito Invalido: (%c).%s\n\n", RED, argv [1][indexDosDigitos], RESET);
				exit (ERRO_DIGITO_INVALIDO);
			}
		}		
		
		/*Converte cada caractere dos digitos para uma string (digito), adicionando o END_OF_STRING em seu fim.*/
		digito [0] = argv [1][indexDosDigitos];
		digito [1] = END_OF_STRING;

		/*Armazena a concatenacao (juncao) das strings "digitosRg" e "digito".*/
		strcat (digitosRg, digito);
	}

	/*Chamada da funcao "ValidarRg".*/
	ValidarRg (digitosRg);

	return SUCESSO;
}

/* $RCSfile: aula0606b.c,v $ */
