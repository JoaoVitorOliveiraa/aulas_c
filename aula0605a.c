/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Codigo-Fonte de um programa de testes para a funcao "GerarDigitosVerificadoresRg".
 *
 * $Author: joao.vitor $
 * $Date: 2024/07/25 01:38:19 $
 * $Log: aula0605a.c,v $
 * Revision 1.3  2024/07/25 01:38:19  joao.vitor
 * alteracao de impressao
 *
 * Revision 1.2  2024/07/24 22:47:21  joao.vitor
 * alteracao de impressao
 *
 * Revision 1.1  2024/07/24 06:36:50  joao.vitor
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
#define NUMERO_ARGUMENTOS_VALIDOS					9 
					
#define NUMERO_ARGUMENTOS_INVALIDO					1
#define INSERIDO_DIGITO_NEGATIVO					2
#define ERRO_DIGITO_INVALIDO						3
#define DIGITO_ULTRAPASSOU_LIMITE_UNSIGNED_LONG				4

#define END_OF_STRING							'\0'

/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	us indexDosDigitos;
	char digitoVerificador [2];
	char digito [2];
	char primeirosDigitosRg [NUMERO_ARGUMENTOS_VALIDOS - 1];
	
	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if (argc != NUMERO_ARGUMENTOS_VALIDOS) 
	{
		printf ("\n%sErro! Numero invalido de argumentos.%s\n", RED, RESET);
		printf ("%sUso: ./aula0605a <oito-primeiros-digitos-do-rg>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	/*Inicializa cada elemento da string dos primeiros numeros do RG como END_OF_STRING.*/
	for (indexDosDigitos = 0; indexDosDigitos < (NUMERO_ARGUMENTOS_VALIDOS - 1); indexDosDigitos++)
		primeirosDigitosRg [indexDosDigitos] = END_OF_STRING;

	/*Inicializa cada elemento da string do digito verificador como END_OF_STRING.*/
	for (indexDosDigitos = 0; indexDosDigitos < 2; indexDosDigitos++)
		digitoVerificador [indexDosDigitos] = END_OF_STRING;

	/*Estrutura de Repeticao que valida os caracteres inseridos.*/
	for (indexDosDigitos = 0; indexDosDigitos < 8; indexDosDigitos++)
	{			
		/*Caso for inserido algum numero negativo, aparecera uma mensagem de erro.*/
		if (argv [1+indexDosDigitos][0] == '-')
		{
			printf ("\n%sErro! Por favor, insira somente digitos positivos.%s\n\n", RED, RESET);
			exit (INSERIDO_DIGITO_NEGATIVO);
		}
		
		/*Caso algum digito inserido nao for um numero, aparecera uma mensagem de erro.*/
		if (((argv [1+indexDosDigitos][0] - '0') > 9) || ((argv [1+indexDosDigitos][0] - '0') < 0))
		{
			printf ("\n%sDigito Invalido Detectado.\nPor favor, insira somente numeros.%s\n\n", RED, RESET);
			exit (ERRO_DIGITO_INVALIDO);
		}
		
		/*Converte cada caractere dos digitos para uma string (digito), adicionando o END_OF_STRING em seu fim.*/
		digito [0] = argv [1+indexDosDigitos][0];
		digito [1] = END_OF_STRING;

		/*Armazena a concatenacao (juncao) das strings "primeirosDigitosRg" e "digito".*/
		strcat (primeirosDigitosRg, digito);
	}
	
	/*Geracao do digito verificador.*/
	GerarDigitosVerificadoresRg (primeirosDigitosRg, digitoVerificador);

	/*Impressao do digito verificador.*/
	printf ("%s\n\n", digitoVerificador);

	return SUCESSO;
}

/* $RCSfile: aula0605a.c,v $ */
