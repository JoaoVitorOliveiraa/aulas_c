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
 * $Date: 2024/07/25 03:15:20 $
 * $Log: aula0602a.c,v $
 * Revision 1.5  2024/07/25 03:15:20  joao.vitor
 * alteracao de impressao
 *
 * Revision 1.4  2024/07/23 23:03:47  joao.vitor
 * adicao de quebra de linha
 *
 * Revision 1.3  2024/07/23 18:15:53  joao.vitor
 * atualizacao da descricao do arquivo
 *
 * Revision 1.2  2024/07/23 18:08:56  joao.vitor
 * correcao de codigo
 *
 * Revision 1.1  2024/06/24 07:20:10  joao.vitor
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
#define NUMERO_ARGUMENTOS_VALIDOS					9 
					
#define NUMERO_ARGUMENTOS_INVALIDO					1
#define INSERIDO_DIGITO_NEGATIVO					2
#define ERRO_DIGITO_INVALIDO						3
#define DIGITO_ULTRAPASSOU_LIMITE_UNSIGNED_LONG				4
#define ERRO_DIGITO_MAIOR_QUE_UM_BYTE					5

#define END_OF_STRING							'\0'

/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	us indexDosDigitos;
	unsigned long digitoInserido;
	byte digitoInseridoConvertido;
	byte matrizDeDigitosInserida [NUMERO_DE_DIGITOS_DO_RG];
	char *validacaoDigitos;

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if (argc != NUMERO_ARGUMENTOS_VALIDOS) 
	{
		printf ("\n%sErro! Numero invalido de argumentos.%s\n", RED, RESET);
		printf ("%sUso: ./aula0602a <oito-primeiros-digitos-do-rg>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	/*Coloca os digitos inseridos em uma matriz.*/
	for (indexDosDigitos = 0; indexDosDigitos < 8; indexDosDigitos++)
	{			
		/*Converte o digito inserido em um valor real do tipo unsigned long.*/
		digitoInserido = strtoul (argv [1+indexDosDigitos], &validacaoDigitos, 10);
		
		/*Caso algum digito inserido nao for um numero, aparecera uma mensagem de erro.*/
		if (*validacaoDigitos != END_OF_STRING)
		{
			printf ("\n%sDigito Invalido Detectado.\nPor favor, insira somente numeros.%s\n\n", RED, RESET);
			exit (ERRO_DIGITO_INVALIDO);
		}

		/*Verifica se foi inserido algum numero negativo.*/
		if (argv [1+indexDosDigitos][0] == '-')
		{
			printf ("\n%sErro! Por favor, insira somente digitos positivos.%s\n\n", RED, RESET);
			exit (INSERIDO_DIGITO_NEGATIVO);
		}
	
		/*Caso algum digito ultrapasse o limite do tipo unsigned long, aparecera uma mensagem de erro.*/	
		if (errno == ERANGE)
		{
			printf ("\n%sErro! Algum digito excedeu o limite do tipo Unsigned Long (%lu).%s\n\n", RED, ULONG_MAX, RESET); 
			exit (DIGITO_ULTRAPASSOU_LIMITE_UNSIGNED_LONG);
		}
		
		/*Caso algum digito ultrapasse o valor de um byte, aparecera uma mensagem de erro.*/	
		if (digitoInserido > 255)
		{
			printf ("\n%sErro! Digito ultrapassou o valor de 1 byte (255): (%lu).%s\n\n", RED, digitoInserido, RESET);
			exit (ERRO_DIGITO_MAIOR_QUE_UM_BYTE);
		}

		/*Armazena o valor da conversao de tipo do digito inserido (unsigned long para byte).*/
		digitoInseridoConvertido = (byte) digitoInserido;

		matrizDeDigitosInserida [indexDosDigitos] = digitoInseridoConvertido;
	}

	/*Inicializa o index oito com algo, a fim de evitar erros.*/
	matrizDeDigitosInserida [8] = 0;

	/*Geracao do digito verificador.*/
	GerarDigitosVerificadoresRg (matrizDeDigitosInserida);

	/*Impressao do digito verificador.*/
	printf ("%u\n\n", matrizDeDigitosInserida [8]);

	return SUCESSO;
}

/* $RCSfile: aula0602a.c,v $ */
