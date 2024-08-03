/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Codigo-Fonte de um programa de testes para a funcao "LimparMonitor", "ObterCodigoAnsiCor", "MostrarMonitor" e "GerarDistribuicaoInicial".
 *
 * $Author: joao.vitor $
 * $Date: 2024/07/23 02:08:48 $
 * $Log: aula0704.c,v $
 * Revision 1.2  2024/07/23 02:08:48  joao.vitor
 * alteracao de macro
 *
 * Revision 1.1  2024/07/21 15:53:54  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE	600
#endif

/*Include's.*/
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <float.h>
#include "aula0701.h"

/*Definicao das Macros.*/
#define SUCESSO								0
#define NUMERO_ARGUMENTOS_VALIDOS					14
					
#define NUMERO_ARGUMENTOS_INVALIDOS					1
#define ARGUMENTO_INSERIDO_INVALIDO					2
#define NUMERO_ULTRAPASSOU_LIMITE_LONG					3
#define INSERIDO_NUMERO_NEGATIVO					4
#define NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED				5
#define	NUMERO_LINHAS_E_COLUNAS_ULTRAPASSADO				6
#define	NUMERO_LINHAS_ULTRAPASSADO					7
#define	NUMERO_COLUNAS_ULTRAPASSADO					8
#define NUMERO_ULTRAPASSOU_LIMITE_LONG_DOUBLE				9
#define ERRO_TEMPO_DE_CONGELAMENTO_NEGATIVO				10
#define ERRO_TEMPO_DE_CONGELAMENTO_INVALIDO				11
#define ERRO_PERCENTUAL_DEFEITUOSOS_NEGATIVO				12
#define ERRO_PERCENTUAL_DEFEITUOSOS_INVALIDO				13
#define ERRO_PERCENTUAL_DEFEITUOSOS_ULTRAPASSOU_LIMITE_FLOAT		14
#define ERRO_PERCENTUAL_APAGADOS_NEGATIVO				15
#define ERRO_PERCENTUAL_APAGADOS_INVALIDO				16
#define ERRO_PERCENTUAL_APAGADOS_ULTRAPASSOU_LIMITE_FLOAT		17
#define ERRO_LINHA_PONTO_1_NEGATIVA					18
#define ERRO_LINHA_PONTO_1_INVALIDA					19
#define ERRO_LINHA_PONTO_1_ULTRAPASSOU_LIMITE_FLOAT			20
#define ERRO_COLUNA_PONTO_1_NEGATIVA					21
#define ERRO_COLUNA_PONTO_1_INVALIDA					22
#define ERRO_COLUNA_PONTO_1_ULTRAPASSOU_LIMITE_FLOAT			23
#define ERRO_LINHA_PONTO_2_NEGATIVA					24
#define ERRO_LINHA_PONTO_2_INVALIDA					25
#define ERRO_LINHA_PONTO_2_ULTRAPASSOU_LIMITE_FLOAT			26
#define ERRO_COLUNA_PONTO_2_NEGATIVA					27
#define ERRO_COLUNA_PONTO_2_INVALIDA					28
#define ERRO_COLUNA_PONTO_2_ULTRAPASSOU_LIMITE_FLOAT			29

#define END_OF_STRING							'\0'

/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	useconds_t tempoDeCongelamentoConvertido;
	tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
	unsigned tamanhoLinhasConvertido, tamanhoColunasConvertido;
	float percentualPixelsDefeituosos, percentualPixelsApagados;
	float linhaPonto1, colunaPonto1, linhaPonto2, colunaPonto2;
	long tamanhoLinhasMatriz, tamanhoColunasMatriz;
	long tempoDeCongelamento;
	char *validacaoTamanhoLinhas, *validacaoTamanhoColunas;
	char *validacaoTempoDeCongelamento;
	char *validacaoPercentualDefeituosos, *validacaoPercentualApagados;
	char *validacaoLinhaPonto1, *validacaoColunaPonto1;
	char *validacaoLinhaPonto2, *validacaoColunaPonto2;

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if (argc != NUMERO_ARGUMENTOS_VALIDOS)
	{
		printf ("\n%sErro! Numero invalido de argumentos.%s\n", RED, RESET);
		printf ("%sUso: ./aula0702 <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <linha-ponto-1> <coluna-ponto-1> <linha-ponto-2> <coluna-ponto-2> <cor-apagado> <cor-aceso> <cor-defeituoso>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDOS);
	}
	
	/*Converte o tempo de congelamento inserido em um valor real do tipo long.*/
	tempoDeCongelamento = strtol (argv [1], &validacaoTempoDeCongelamento, 10);

	/*Caso o tempo de congelamento inserido nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoTempoDeCongelamento != END_OF_STRING)
	{
		printf ("\n%sTempo de Congelamento Invalido.\nPor favor, insira um numero.%s\n\n", RED, RESET);
		exit (ERRO_TEMPO_DE_CONGELAMENTO_INVALIDO);
	}

	/*Caso o tempo de congelamento inserido for um numero negativo, aparecera uma mensagem de erro.*/
	if (argv [1][0] == '-')
	{
		printf ("\n%sTempo de Congelamento Invalido.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (ERRO_TEMPO_DE_CONGELAMENTO_NEGATIVO);
	}

	/*Caso o tempo de congelamento inserido ultrapasse o limite do tipo long, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! O tempo de congelamento excedeu o limite do tipo Long (%ld).%s\n\n", RED, LONG_MAX, RESET); 
		exit (NUMERO_ULTRAPASSOU_LIMITE_LONG);
	}

	/*Armazena o valor da conversao de tipo do tempo de congelamento inserido (long para useconds_t).*/
	tempoDeCongelamentoConvertido = (useconds_t) tempoDeCongelamento;

	/*Converte o tamanho inserido em um valor real do tipo long.*/
	tamanhoLinhasMatriz = strtol (argv [2], &validacaoTamanhoLinhas, 10);
	
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
	if ((argv [2][0] == '-') && (argv [3][0] == '-'))
	{
		printf ("\n%sErro! Ambos os numeros de linhas e colunas sao invalidos.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (INSERIDO_NUMERO_NEGATIVO);
	}	

	/*Caso somente o numeros de linhas for negativo, aparecera uma mensagem de erro.*/
	if ((argv [2][0] == '-') && (argv[3][0] != '-'))
	{
		printf ("\n%sErro! Numero de linhas invalido.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (INSERIDO_NUMERO_NEGATIVO);
	}	

	/*Converte o tamanho inserido em um valor inteiro do tipo long.*/
	tamanhoColunasMatriz = strtol (argv [3], &validacaoTamanhoColunas, 10);
	
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
	if ((argv [2][0] != '-') && (argv[3][0] == '-'))
	{
		printf ("\n%sErro! Numero de colunas invalido.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (INSERIDO_NUMERO_NEGATIVO);
	}	
	
	/*Caso o tamanho dos numeros de linhas e colunas inseridos estejam fora do limite do tipo unsigned, aparecera uma mensagem de erro.*/
	if ((tamanhoLinhasMatriz > UINT_MAX) && (tamanhoColunasMatriz > UINT_MAX))
	{ 
		printf ("\n%sErro! Os numeros de linhas e colunas ultrapassaram o limite do tipo Unsigned (%d).%s\n\n", RED, UINT_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED);
	}

	/*Caso o tamanho do numero de linhas inserido esteja fora do limite do tipo unsigned, aparecera uma mensagem de erro.*/
	if (tamanhoLinhasMatriz > UINT_MAX) 
	{ 
		printf ("\n%sErro! O numero de linhas ultrapassou o limite do tipo Unsigned (%d).%s\n\n", RED, UINT_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED);
	}

	/*Caso o tamanho do numero de colunas inserido esteja fora do limite do tipo unsigned, aparecera uma mensagem de erro.*/
	if (tamanhoColunasMatriz > UINT_MAX) 
	{ 
		printf ("\n%sErro! O numero de colunas ultrapassou o limite do tipo Unsigned (%d).%s\n\n", RED, UINT_MAX, RESET);
		exit (NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED);
	}

	/*Armazena o valor da conversao de tipo do tamanho de linhas inserido (long para unsigned).*/
	tamanhoLinhasConvertido = (unsigned) tamanhoLinhasMatriz;
	
	/*Armazena o valor da conversao de tipo do tamanho de colunas inserido (long para unsigned).*/
	tamanhoColunasConvertido = (unsigned) tamanhoColunasMatriz;

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

	/*Converte o percentual de pixels defeituosos inserido em um valor do tipo float.*/
	percentualPixelsDefeituosos = strtof (argv [4], &validacaoPercentualDefeituosos);
	
	/*Caso o percentual inserido nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoPercentualDefeituosos != END_OF_STRING)
	{
		printf ("\n%sErro! Percentual de Pixels Defeituosos Invalido.%s\n\n", RED, RESET);
		exit (ERRO_PERCENTUAL_DEFEITUOSOS_INVALIDO);
	}
	
	/*Caso o percentual de pixels defeituosos inserido for um numero negativo, aparecera uma mensagem de erro.*/
	if (argv [4][0] == '-')
	{
		printf ("\n%sPercentual de Pixels Defeituosos Invalido.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (ERRO_PERCENTUAL_DEFEITUOSOS_NEGATIVO);
	}

	/*Caso o percentual de pixels defeituosos inserido ultrapasse o limite do tipo float, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! O percentual de pixels defeituosos excedeu o limite do tipo Float (%f).%s\n\n", RED, FLT_MAX, RESET); 
		exit (ERRO_PERCENTUAL_DEFEITUOSOS_ULTRAPASSOU_LIMITE_FLOAT);
	}

	/*Converte o percentual de pixels apagados inserido em um valor do tipo float.*/
	percentualPixelsApagados = strtof (argv [5], &validacaoPercentualApagados);
	
	/*Caso o percentual inserido nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoPercentualApagados != END_OF_STRING)
	{
		printf ("\n%sErro! Percentual de Pixels Apagados Invalido.%s\n\n", RED, RESET);
		exit (ERRO_PERCENTUAL_APAGADOS_INVALIDO);
	}
	
	/*Caso o percentual de pixels apagados inserido for um numero negativo, aparecera uma mensagem de erro.*/
	if (argv [5][0] == '-')
	{
		printf ("\n%sPercentual de Pixels Apagados Invalido.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (ERRO_PERCENTUAL_APAGADOS_NEGATIVO);
	}

	/*Caso o percentual de pixels apagados inserido ultrapasse o limite do tipo float, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! O percentual de pixels apagados excedeu o limite do tipo Float (%f).%s\n\n", RED, FLT_MAX, RESET); 
		exit (ERRO_PERCENTUAL_APAGADOS_ULTRAPASSOU_LIMITE_FLOAT);
	}

	/*Converte a linha do ponto um em um valor do tipo float.*/
	linhaPonto1 = strtof (argv [6], &validacaoLinhaPonto1);
	
	/*Caso a linha inserida nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoLinhaPonto1 != END_OF_STRING)
	{
		printf ("\n%sErro! Linha do Ponto 1 Invalida.%s\n\n", RED, RESET);
		exit (ERRO_LINHA_PONTO_1_INVALIDA);
	}
	
	/*Caso a linha inserida for um numero negativo, aparecera uma mensagem de erro.*/
	if (argv [6][0] == '-')
	{
		printf ("\n%sLinha do Ponto 1 Invalida.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (ERRO_LINHA_PONTO_1_NEGATIVA);
	}

	/*Caso a linha inserida ultrapasse o limite do tipo float, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! A linha do ponto 1 excedeu o limite do tipo Float (%f).%s\n\n", RED, FLT_MAX, RESET); 
		exit (ERRO_LINHA_PONTO_1_ULTRAPASSOU_LIMITE_FLOAT);
	}

	/*Converte a coluna do ponto um em um valor do tipo float.*/
	colunaPonto1 = strtof (argv [7], &validacaoColunaPonto1);
	
	/*Caso a coluna inserida nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoColunaPonto1 != END_OF_STRING)
	{
		printf ("\n%sErro! Coluna do Ponto 1 Invalida.%s\n\n", RED, RESET);
		exit (ERRO_COLUNA_PONTO_1_INVALIDA);
	}
	
	/*Caso a coluna inserida for um numero negativo, aparecera uma mensagem de erro.*/
	if (argv [7][0] == '-')
	{
		printf ("\n%sColuna do Ponto 1 Invalida.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (ERRO_COLUNA_PONTO_1_NEGATIVA);
	}

	/*Caso a coluna inserida ultrapasse o limite do tipo float, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! A coluna do ponto 1 excedeu o limite do tipo Float (%f).%s\n\n", RED, FLT_MAX, RESET); 
		exit (ERRO_COLUNA_PONTO_1_ULTRAPASSOU_LIMITE_FLOAT);
	}

	/*Converte a linha do ponto dois em um valor do tipo float.*/
	linhaPonto2 = strtof (argv [8], &validacaoLinhaPonto2);
	
	/*Caso a linha inserida nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoLinhaPonto2 != END_OF_STRING)
	{
		printf ("\n%sErro! Linha do Ponto 2 Invalida.%s\n\n", RED, RESET);
		exit (ERRO_LINHA_PONTO_2_INVALIDA);
	}
	
	/*Caso a linha inserida for um numero negativo, aparecera uma mensagem de erro.*/
	if (argv [8][0] == '-')
	{
		printf ("\n%sLinha do Ponto 2 Invalida.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (ERRO_LINHA_PONTO_2_NEGATIVA);
	}

	/*Caso a linha inserida ultrapasse o limite do tipo float, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! A linha do ponto 2 excedeu o limite do tipo Float (%f).%s\n\n", RED, FLT_MAX, RESET); 
		exit (ERRO_LINHA_PONTO_2_ULTRAPASSOU_LIMITE_FLOAT);
	}

	/*Converte a coluna do ponto dois em um valor do tipo float.*/
	colunaPonto2 = strtof (argv [9], &validacaoColunaPonto2);
	
	/*Caso a coluna inserida nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoColunaPonto2 != END_OF_STRING)
	{
		printf ("\n%sErro! Coluna do Ponto 2 Invalida.%s\n\n", RED, RESET);
		exit (ERRO_COLUNA_PONTO_2_INVALIDA);
	}
	
	/*Caso a coluna inserida for um numero negativo, aparecera uma mensagem de erro.*/
	if (argv [9][0] == '-')
	{
		printf ("\n%sColuna do Ponto 2 Invalida.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (ERRO_COLUNA_PONTO_2_NEGATIVA);
	}

	/*Caso a coluna inserida ultrapasse o limite do tipo float, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! A coluna do ponto 2 excedeu o limite do tipo Float (%f).%s\n\n", RED, FLT_MAX, RESET); 
		exit (ERRO_COLUNA_PONTO_2_ULTRAPASSOU_LIMITE_FLOAT);
	}

	/*Chamada da funcao "GerarDistribuicaoInicial".*/
	GerarDistribuicaoInicial (monitor, tamanhoLinhasConvertido, tamanhoColunasConvertido, percentualPixelsDefeituosos, percentualPixelsApagados);

	/*Chamada da funcao "MostrarMonitor".*/
	MostrarMonitor (tempoDeCongelamentoConvertido, monitor, tamanhoLinhasConvertido, tamanhoColunasConvertido, argv [10], argv [11], argv [12], argv [13]);

	/*Chamada da funcao "LimparMonitor".*/
	LimparMonitor (monitor, tamanhoLinhasConvertido, tamanhoColunasConvertido, argv [10], argv [11], argv [12], argv [13]);

	/*Chamada da funcao "DesenharReta".*/
	DesenharReta (monitor, tamanhoLinhasConvertido, tamanhoColunasConvertido, linhaPonto1, colunaPonto1, linhaPonto2, colunaPonto2, argv [10], argv [11], argv [12], argv [13]);

	/*Chamada da funcao "MostrarMonitor".*/
	MostrarMonitor (tempoDeCongelamentoConvertido, monitor, tamanhoLinhasConvertido, tamanhoColunasConvertido, argv [10], argv [11], argv [12], argv [13]);

	return SUCESSO;
}

/* $RCSfile: aula0704.c,v $ */
