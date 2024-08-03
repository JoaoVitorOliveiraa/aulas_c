/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Codigo-Fonte de um programa de testes para a funcao "CalcularTermoSerieFibonacci".
 *
 * $Author: joao.vitor $
 * $Date: 2024/05/10 18:54:52 $
 * $Log: aula0302.c,v $
 * Revision 1.3  2024/05/10 18:54:52  joao.vitor
 * Alteracao na condicao de erro onde o valor da funcao ultrapassa um valor unsigned lonfl on
 * *Correcao: unsigned long long
 *
 * Revision 1.2  2024/05/10 03:11:12  joao.vitor
 * Atualizacao da descricao do arquivo
 *
 * Revision 1.1  2024/05/10 03:01:12  joao.vitor
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
#include "aula0301.h"

/*Definicao das Macros.*/
#define SUCESSO								0
#define NUMERO_ARGUMENTOS_VALIDOS					2
					
#define NUMEROS_ARGUMENTOS_INVALIDOS					1
#define ARGUMENTO_INSERIDO_INVALIDO					2
#define NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED_SHORT			3
#define INSERIDO_NUMERO_NEGATIVO					4
#define NUMERO_ULTRAPASSOU_LIMITE_LONG_UNSIGNED				5
#define VALOR_ULTRAPASSOU_LIMITE_UNSIGNED_LONG_LONG			6		

#define END_OF_STRING							'\0'

/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	ull valorTermoSerieFibonacci;
	ull valorTermoAnteriorSerieFibonacci;
	ul valorInserido;
	us valorConvertido;
	us termoSerieFibonacci;
	char *validacaoDoArgumento;

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if (argc != NUMERO_ARGUMENTOS_VALIDOS)
	{
		printf ("\n%s%sErro! Numero invalido de argumentos.%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (NUMEROS_ARGUMENTOS_INVALIDOS);
	}
	
	/*Converte a string inserida em um valor inteiro do tipo unsigned long.*/
	valorInserido = strtoul(argv [1], &validacaoDoArgumento, 10);	
	
	/*Caso o argumento inserido nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoDoArgumento != END_OF_STRING)
	{
		printf ("\n%s%sErro! Argumento(s) inserido(s) invalido(s).%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (ARGUMENTO_INSERIDO_INVALIDO);
	}
	
	/*Caso o numero inserido for negativo, aparecera uma mensagem de erro.*/
	if (argv [1][0] == '-')
	{
		printf ("\n%s%sErro! Por favor, insira somente numeros positivos.%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (INSERIDO_NUMERO_NEGATIVO);
	}	
	
	/*Caso o valor inserido ultrapasse o limite do tipo long unsigned, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%s%sErro! Limite do tipo Long Unsigned excedido (%lu).%s\n\n", RED, WHITE_BACKGROUND, ULONG_MAX, RESET); 
		exit (NUMERO_ULTRAPASSOU_LIMITE_LONG_UNSIGNED);
	
	}

	/*Caso o valor inserido ultrapasse o limite do tipo unsigned short, aparecera uma mensagem de erro.*/
	if (valorInserido > USHRT_MAX)
	{ 
		printf ("\n%s%sErro! Limite do tipo Unsigned Short excedido (%u).%s\n\n", RED, WHITE_BACKGROUND, USHRT_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED_SHORT);
	}

	/*Armazena o valor da conversao de tipo do numero inserido (unsigned long para unsigned short).*/
	valorConvertido = (us) valorInserido;

	/*Quebra de linha.*/
	printf ("\n");

	/*Estrutura de Repeticao que calcula o valor de cada termo da serie de Fibonacci ate o numero inserido pelo usuario.*/
	for (termoSerieFibonacci = 0; termoSerieFibonacci <= valorConvertido; termoSerieFibonacci++)
	{
		/*Armazena o valor da serie de Fibonacci de cada termo.*/
		valorTermoSerieFibonacci = CalcularTermoSerieFibonacci (termoSerieFibonacci);
		
		/*Caso o termo seja zero, o valor do termo anterior vale zero (para nao gerar erros).*/
		if (termoSerieFibonacci == 0)
			valorTermoAnteriorSerieFibonacci = 0;
		
		else
			valorTermoAnteriorSerieFibonacci = CalcularTermoSerieFibonacci (termoSerieFibonacci - 1);

		/*Caso o resultado da funcao ultrapasse o limite do tipo unsigned long long, aparecera uma mensagem de erro.*/
		if (valorTermoSerieFibonacci < valorTermoAnteriorSerieFibonacci)
		{
			printf ("%s%sF (%u) ultrapassa o limite superior permitido para o tipo unsigned long long.%s\n\n", RED, WHITE_BACKGROUND, termoSerieFibonacci, RESET);
			exit (VALOR_ULTRAPASSOU_LIMITE_UNSIGNED_LONG_LONG);		
		}

		else
			printf ("%s%sF (%u) = %llu%s\n", BLACK, WHITE_BACKGROUND, termoSerieFibonacci, valorTermoSerieFibonacci, RESET);
	}

	/*Quebra de linha.*/
	printf ("\n");

	return SUCESSO;
}

/* $RCSfile: aula0302.c,v $ */
