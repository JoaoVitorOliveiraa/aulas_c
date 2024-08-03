/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Codigo-Fonte de um programa de testes para a funcao "ExibirHifens".
 *
 * $Author: joao.vitor $
 * $Date: 2024/04/21 01:10:00 $
 * $Log: aula0103.c,v $
 * Revision 1.2  2024/04/21 01:10:00  joao.vitor
 * *** empty log message ***
 *
 * Revision 1.1  2024/04/20 06:17:24  joao.vitor
 * Initial revision
 *
 * Revision 1.1  2024/04/20 02:33:14  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "cores.h"
#include "aula0101.h"

/*Definicao das Macros*/
#define NUMERO_ARGUMENTOS_VALIDOS			2
#define SUCESSO						0

#define NUMERO_ARGUMENTOS_INVALIDOS			1
#define BASE_INVALIDA					2
#define NUMERO_ULTRAPASSOU_VALOR_LONG_UNSIGNED		3
#define NUMERO_ULTRAPASSOU_VALOR_SHORT_UNSIGNED		4
#define ARGUMENTO_INSERIDO_INVALIDO			5
#define VALOR_NAO_ESTA_ENTRE_1_E_500			6

#define END_OF_STRING					'\0'


int
main(int argc, char *argv[])
{
	/*Inicializacao das Variaveis.*/
	ul numeroInserido;
	us numeroConvertido;
	char *verificacaoNumero;	
	
	/*Condicao responsavel por mostrar uma mensagem de erro, caso o numero de argumentos for invalido.*/
	if (argc != NUMERO_ARGUMENTOS_VALIDOS)
	{
		printf ("\n%sNumero Invalido de Argumentos.%s\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDOS);
	}
	
	/*A variavel "numeroInserido" armazena o valor correspondente a conversao da string "argv[1]" (inserida pelo usuario) para seu valor equivalente na base "10", sendo seu tipo "long unsigned".
	 *OBS: Essa conversao érealizada pela funcao "strtoul".*/
	numeroInserido = strtoul(argv[1], &verificacaoNumero, 10);

	/*Condicao responsavel por mostrar uma mensagem de erro, caso o usuario insira um argumento invalido, como uma letra.*/
	if (*verificacaoNumero != END_OF_STRING)
	{
		printf ("\n%sO Argumento Inserido e Invalido.%s\n", RED, RESET);
		exit (ARGUMENTO_INSERIDO_INVALIDO);
	}

	/*Condicao responsavel por mostrar uma mensagem de erro, caso o numero inserido for de uma base invalida.*/
	if (errno == EINVAL)
	{
		printf ("\n%sO Numero Inserido e de uma Base Invalida.%s\n", RED, RESET);
		exit (BASE_INVALIDA);
	}
	
	/*Condicao responsavel por mostrar uma mensagem de erro, caso o numero inserido ultrapasse o valor maximo que o tipo "long unsigned" e capaz de armazenar.*/
	if (errno == ERANGE)
	{
		printf ("\n%sO Numero Inserido Ultrapassou o Valor Maximo do Tipo Long Unsigned (%lu).%s\n", RED, ULONG_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_VALOR_LONG_UNSIGNED);
	}
	
	/*Condicao responsavel por mostrar uma mensagem de erro, caso o valor do numero inserido nao esteja entre zero e o valor maximo que o tipo "short unsigned" e capaz de armazenar.*/
	if (numeroInserido > USHRT_MAX)
	{
		printf ("\n%sO Numero Inserido nao se encontra no Intervalo entre 0 e o Valor Maximo do Tipo Short Unsigned (%u).%s\n", RED, UINT_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_VALOR_SHORT_UNSIGNED);
	}	
	
	/*Condicao responsavel por mostrar uma mensagem de erro, caso o usuario insira um numero que nao esteja entre "1" e "500", ou igual a zero.*/
	if (((numeroInserido > 500) && (numeroInserido < ULONG_MAX)) || (numeroInserido == 0)) 
	{
		printf ("\n%sO Numero Inserido deve ser um Valor entre 1 e 500.%s\n", RED, RESET);
		exit (VALOR_NAO_ESTA_ENTRE_1_E_500);
	}	
	
	/*Conversao de tipo do numero inserido pelo usuario, atraves do uso de "cast". Foi convertido de "long unsigned" para "short unsigned".*/
	numeroConvertido = (us) numeroInserido;

	/*Insercao do numero convertido na funcao "ExibirHifens".*/
	ExibirHifens(numeroConvertido);
	
	return SUCESSO;
}

/* $RCSfile: aula0103.c,v $ */
