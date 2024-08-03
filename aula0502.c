/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Codigo-Fonte de um programa de testes para a funcao "ExibirMatriz".
 *
 * $Author: joao.vitor $
 * $Date: 2024/06/10 03:08:53 $
 * $Log: aula0502.c,v $
 * Revision 1.2  2024/06/10 03:08:53  joao.vitor
 * adicao de tabulacao
 *
 * Revision 1.1  2024/06/09 14:17:07  joao.vitor
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
#define NUMERO_ARGUMENTOS_VALIDOS					3 + (NUMERO_MAXIMO_LINHAS * NUMERO_MAXIMO_COLUNAS)
					
#define NUMERO_ARGUMENTOS_INVALIDO					1
#define ARGUMENTO_INSERIDO_INVALIDO					2
#define NUMERO_ULTRAPASSOU_LIMITE_LONG					3
#define INSERIDO_NUMERO_NEGATIVO					4
#define NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED_INT				5
#define	NUMERO_LINHAS_E_COLUNAS_ULTRAPASSADO				6
#define	NUMERO_LINHAS_ULTRAPASSADO					7
#define	NUMERO_COLUNAS_ULTRAPASSADO					8
#define NUMERO_ULTRAPASSOU_LIMITE_LONG_DOUBLE				9

#define END_OF_STRING							'\0'

/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	us linha, coluna;
	us tamanhoLinhasConvertido, tamanhoColunasConvertido;
	long tamanhoLinhasMatriz, tamanhoColunasMatriz;
	char *validacaoTamanhoLinhas, *validacaoTamanhoColunas;
	char *validacaoMatrizInserida;

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if ((argc > NUMERO_ARGUMENTOS_VALIDOS) || (argc < 3))
	{
		printf ("\n%sErro! Numero invalido de argumentos.%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	/*Converte o tamanho inserido em um valor real do tipo long.*/
	tamanhoLinhasMatriz = strtol(argv [1], &validacaoTamanhoLinhas, 10);
	
	/*Caso o tamanho inserido nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoTamanhoLinhas != END_OF_STRING)
	{
		printf ("\n%sErro! Numero de Linhas Invalido.%s\n\n", RED, RESET);
		exit (ARGUMENTO_INSERIDO_INVALIDO);
	}
	
	/*Caso o numero de linhas inserido ultrapasse o limite do tipo long, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! O numero de linhas excedeu o limite do tipo Long (%ld).%s\n\n", RED, LONG_MAX, RESET); 
		exit (NUMERO_ULTRAPASSOU_LIMITE_LONG);
	}

	/*Caso os numeros de linhas e colunas forem negativos, aparecera uma mensagem de erro.*/
	if ((argv [1][0] == '-') && (argv [2][0] == '-'))
	{
		printf ("\n%sErro! Ambos os numeros de linhas e colunas sao invalidos.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (INSERIDO_NUMERO_NEGATIVO);
	}	

	/*Caso somente o numeros de linhas for negativo, aparecera uma mensagem de erro.*/
	if ((argv [1][0] == '-') && (argv[2][0] != '-'))
	{
		printf ("\n%sErro! Numero de linhas invalido.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (INSERIDO_NUMERO_NEGATIVO);
	}	

	/*Converte o tamanho inserido em um valor inteiro do tipo long.*/
	tamanhoColunasMatriz = strtol(argv [2], &validacaoTamanhoColunas, 10);
	
	/*Caso o tamanho inserido nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoTamanhoColunas != END_OF_STRING)
	{
		printf ("\n%sErro! Numero de Colunas Invalido.%s\n\n", RED, RESET);
		exit (ARGUMENTO_INSERIDO_INVALIDO);
	}
		
	/*Caso o tamanho de colunas inserido ultrapasse o limite do tipo long, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! O numero de colunas excedeu o limite do tipo Long (%ld).%s\n\n", RED, LONG_MAX, RESET); 
		exit (NUMERO_ULTRAPASSOU_LIMITE_LONG);
	}
	
	/*Caso somente o numeros de colunas for negativo, aparecera uma mensagem de erro.*/
	if ((argv [1][0] != '-') && (argv[2][0] == '-'))
	{
		printf ("\n%sErro! Numero de colunas invalido.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (INSERIDO_NUMERO_NEGATIVO);
	}	
	
	/*Caso o tamanho dos numeros de linhas e colunas inseridos estejam fora do limite do tipo unsigned int, aparecera uma mensagem de erro.*/
	if ((tamanhoLinhasMatriz > USHRT_MAX) && (tamanhoColunasMatriz > USHRT_MAX))
	{ 
		printf ("\n%sErro! Os numeros de linhas e colunas ultrapassaram o limite do tipo Unsigned Short (%d).%s\n\n", RED, USHRT_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED_INT);
	}

	/*Caso o tamanho do numero de linhas inserido esteja fora do limite do tipo unsigned int, aparecera uma mensagem de erro.*/
	if (tamanhoLinhasMatriz > USHRT_MAX) 
	{ 
		printf ("\n%sErro! O numero de linhas ultrapassou o limite do tipo Unsigned Short (%d).%s\n\n", RED, USHRT_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED_INT);
	}

	/*Caso o tamanho do numero de colunas inserido esteja fora do limite do tipo unsigned int, aparecera uma mensagem de erro.*/
	if (tamanhoColunasMatriz > USHRT_MAX) 
	{ 
		printf ("\n%sErro! O numero de colunas ultrapassou o limite do tipo Unsigned Short (%d).%s\n\n", RED, USHRT_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED_INT);
	}

	/*Armazena o valor da conversao de tipo do tamanho de linhas inserido (long para unsigned int).*/
	tamanhoLinhasConvertido = (us) tamanhoLinhasMatriz;
	
	/*Armazena o valor da conversao de tipo do tamanho de colunas inserido (long para unsigned int).*/
	tamanhoColunasConvertido = (us) tamanhoColunasMatriz;

	/*Condicao que verifica se o numeros de argumentos condiz */
	if ((argc - 3) != (tamanhoLinhasConvertido * tamanhoColunasConvertido))
	{
		printf ("\n%sErro! A quantidade de argumentos nao se adequa ao tamanho da matriz (%hu X %hu).%s\n\n", RED, tamanhoLinhasConvertido, tamanhoColunasConvertido, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/*Condicao que verifica se os limites de linhas e colunas foram ultrapassados.*/
	if ((tamanhoLinhasConvertido > NUMERO_MAXIMO_LINHAS) && (tamanhoColunasConvertido > NUMERO_MAXIMO_COLUNAS))
	{
		printf ("\n%sErro! Numeros de linhas e colunas ultrapassaram o limite suportado%s", RED, RESET);
		printf ("\n%sPor favor, insira um numero de linhas que esteja entre 1 e %d.%s", RED, NUMERO_MAXIMO_LINHAS, RESET);
		printf ("\n%sPor favor, insira um numero de colunas que esteja entre 1 e %d.%s\n\n", RED, NUMERO_MAXIMO_COLUNAS, RESET);
		exit (NUMERO_LINHAS_E_COLUNAS_ULTRAPASSADO);
	}
	
	/*Condicao que verifica se somente o numero maximo de linhas foi ultrapassado.*/
	if (tamanhoLinhasConvertido > NUMERO_MAXIMO_LINHAS)
	{
		printf ("\n%sErro! Numero de linhas invalido.\nPor favor, insira um numero que esteja entre 1 e %d.%s\n\n", RED, NUMERO_MAXIMO_LINHAS, RESET);
		exit (NUMERO_LINHAS_ULTRAPASSADO);
	}

	/*Condicao que verifica se somente o numero maximo de colunas foi ultrapassado.*/
	if (tamanhoColunasConvertido > NUMERO_MAXIMO_COLUNAS)
	{
		printf ("\n%sErro! Numero de colunas invalido.\nPor favor, insira um numero de colunas que esteja entre 1 e %d.%s\n\n", RED, NUMERO_MAXIMO_COLUNAS, RESET);
		exit (NUMERO_COLUNAS_ULTRAPASSADO);
	}

	ld matrizInserida [tamanhoLinhasConvertido][tamanhoColunasConvertido];

	for (linha = 0; linha < tamanhoLinhasConvertido; linha++)
		for (coluna = 0; coluna < tamanhoColunasConvertido; coluna++)
			matrizInserida [linha][coluna] = strtold (argv[3 + coluna + (linha * tamanhoColunasConvertido)], &validacaoMatrizInserida);

			/*Caso a matriz inserida possua um argumento invalido, aparecera uma mensagem de erro.*/
			if (*validacaoMatrizInserida != END_OF_STRING)
			{
				printf ("\n%sErro! A matriz inserida possui algum argumento invalido.%s\n\n", RED, RESET);
				exit (ARGUMENTO_INSERIDO_INVALIDO);
			}
		
	/*Caso algum argumento da matriz ultrapasse o limite do tipo long double, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! Algum argumento da matriz excede os limites do tipo Long Double (%Lf).%s\n\n", RED, LDBL_MAX, RESET); 
		exit (NUMERO_ULTRAPASSOU_LIMITE_LONG_DOUBLE);
	}

	/*Chama a funcao para exibir a matriz.*/
	ExibirMatriz (tamanhoLinhasConvertido, tamanhoColunasConvertido, matrizInserida);

	return SUCESSO;
}

/* $RCSfile: aula0502.c,v $ */
