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
 * $Date: 2024/07/25 01:47:22 $
 * $Log: aula0606a.c,v $
 * Revision 1.1  2024/07/25 01:47:22  joao.vitor
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
#define NUMERO_ARGUMENTOS_VALIDOS					10 
					
#define NUMERO_ARGUMENTOS_INVALIDO					1
#define INSERIDO_DIGITO_NEGATIVO					2
#define ERRO_DIGITO_INVALIDO						3

#define END_OF_STRING							'\0'

/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	us indexDosDigitos;
	char digitoInserido;
	char digito [2];
	char digitosRg [NUMERO_DE_DIGITOS_DO_RG + 3];

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if (argc != NUMERO_ARGUMENTOS_VALIDOS) 
	{
		printf ("\n%sErro! Numero invalido de argumentos.%s\n", RED, RESET);
		printf ("%sUso: ./aula0606a <nove-digitos-do-rg>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/*Inicializa cada elemento da string dos numeros do RG como END_OF_STRING.*/
	for (indexDosDigitos = 0; indexDosDigitos < (NUMERO_DE_DIGITOS_DO_RG + 3); indexDosDigitos++)
		digitosRg [indexDosDigitos] = END_OF_STRING;

	/*Coloca os digitos inseridos em uma string, incluindo os pontos e o hifen.*/
	for (indexDosDigitos = 0; indexDosDigitos < NUMERO_DE_DIGITOS_DO_RG; indexDosDigitos++)
	{			
		digitoInserido = argv [1+indexDosDigitos][0];
		
		/*Caso for inserido algum numero negativo, aparecera uma mensagem de erro.*/
		if (digitoInserido == '-')
		{
			printf ("\n%sErro! Por favor, insira somente digitos positivos.%s\n\n", RED, RESET);
			exit (INSERIDO_DIGITO_NEGATIVO);
		}

		/*Caso algum digito inserido nao for um numero, aparecera uma mensagem de erro.*/
		if (((digitoInserido - '0') > 9) || ((digitoInserido - '0') < 0))
		{
			printf ("\n%sDigito Invalido Detectado (%c).\nPor favor, insira somente numeros.%s\n\n", RED, digitoInserido, RESET);
			exit (ERRO_DIGITO_INVALIDO);
		}

		/*Condicao que adiciona os pontos na string de digitos do RG.*/
		if ((indexDosDigitos == 2) || (indexDosDigitos == 5))
			strcat (digitosRg, ".");

		/*Condicao que adiciona o hifen na string de digitos do RG.*/
		if (indexDosDigitos == 8)
			strcat (digitosRg, "-");

		/*Converte cada caractere dos digitos para uma string (digito), adicionando o END_OF_STRING em seu fim.*/
		digito [0] = digitoInserido;
		digito [1] = END_OF_STRING;

		/*Armazena a concatenacao (juncao) das strings "primeirosDigitosRg" e "digito".*/
		strcat (digitosRg, digito);
	}

	/*Chamada da funcao "ValidarRg".*/
	ValidarRg (digitosRg);

	return SUCESSO;
}

/* $RCSfile: aula0606a.c,v $ */
