/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Codigo-Fonte de um programa de testes para a funcao "LimparMonitor", "ObterCodigoAnsiCor", "MostrarMonitor", "GerarDistribuicaoInicial", "DesenharReta" e "DesenharPoligono".
 *
 * $Author: joao.vitor $
 * $Date: 2024/07/23 16:15:21 $
 * $Log: aula0705.c,v $
 * Revision 1.1  2024/07/23 16:15:21  joao.vitor
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
#define NUMERO_ARGUMENTOS_VALIDOS					11 + NUMERO_MAXIMO_VERTICES * 2 
					
#define NUMERO_ARGUMENTOS_INVALIDOS					1
#define ARGUMENTO_INSERIDO_INVALIDO					2
#define NUMERO_ULTRAPASSOU_LIMITE_LONG					3
#define INSERIDO_NUMERO_NEGATIVO					4
#define NUMERO_ULTRAPASSOU_LIMITE_UNSIGNED				5
#define	NUMERO_LINHAS_E_COLUNAS_ULTRAPASSADO				6
#define	NUMERO_LINHAS_ULTRAPASSADO					7
#define	NUMERO_COLUNAS_ULTRAPASSADO					8
#define ERRO_TEMPO_DE_CONGELAMENTO_NEGATIVO				9
#define ERRO_TEMPO_DE_CONGELAMENTO_INVALIDO				10
#define ERRO_PERCENTUAL_DEFEITUOSOS_NEGATIVO				11
#define ERRO_PERCENTUAL_DEFEITUOSOS_INVALIDO				12
#define ERRO_PERCENTUAL_DEFEITUOSOS_ULTRAPASSOU_LIMITE_FLOAT		13
#define ERRO_PERCENTUAL_APAGADOS_NEGATIVO				14
#define ERRO_PERCENTUAL_APAGADOS_INVALIDO				15
#define ERRO_PERCENTUAL_APAGADOS_ULTRAPASSOU_LIMITE_FLOAT		16
#define ERRO_NUMERO_DE_VERTICES_NEGATIVO				17
#define ERRO_NUMERO_DE_VERTICES_INVALIDO				18

#define END_OF_STRING							'\0'

/*Inicializacao da Funcao Principal.*/
int
main (int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	useconds_t tempoDeCongelamentoConvertido;
	tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
	unsigned tamanhoLinhasConvertido, tamanhoColunasConvertido;
	unsigned linhasVertices [NUMERO_MAXIMO_VERTICES], colunasVertices [NUMERO_MAXIMO_COLUNAS];
	unsigned numeroAuxiliar, numeroVertices, numeroVerticesConvertido, index;
	float percentualPixelsDefeituosos, percentualPixelsApagados;
	long tamanhoLinhasMatriz, tamanhoColunasMatriz;
	long tempoDeCongelamento;
	char *validacaoTamanhoLinhas, *validacaoTamanhoColunas;
	char *validacaoTempoDeCongelamento, *validacaoNumeroVertices;
	char *validacaoPercentualDefeituosos, *validacaoPercentualApagados;
	char *validacaoLinhasVertices, *validacaoColunasVertices;
	char *corFundo, *corApagado, *corAceso, *corDefeituoso;

	/*Caso o numero de argumentos inseridos for invalido, aparecera uma mensagem de erro.*/
	if (argc > NUMERO_ARGUMENTOS_VALIDOS)
	{
		printf ("\n%sErro! Numero invalido de argumentos.%s\n", RED, RESET);
		printf ("%sUso: ./aula0702 <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> ... <linha-vertice-N> <coluna-vertice-N> <cor-fundo> <cor-apagado> <cor-aceso> <cor-defeituoso>%s\n\n", RED, RESET);
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

	/*Converte o numero de vertices inserido em um valor real do tipo long.*/
	numeroVertices = strtol (argv [6], &validacaoNumeroVertices, 10);

	/*Caso o numero de vertices inserido nao for um numero, aparecera uma mensagem de erro.*/
	if (*validacaoNumeroVertices != END_OF_STRING)
	{
		printf ("\n%sNumero de Vertices Invalido.\nPor favor, insira um numero.%s\n\n", RED, RESET);
		exit (ERRO_NUMERO_DE_VERTICES_INVALIDO);
	}

	/*Caso o numero de vertices inserido for um numero negativo, aparecera uma mensagem de erro.*/
	if (argv [6][0] == '-')
	{
		printf ("\n%sNumero de Vertices Invalido.\nPor favor, insira somente numeros positivos.%s\n\n", RED, RESET);
		exit (ERRO_NUMERO_DE_VERTICES_NEGATIVO);
	}	

	/*Caso o numero de vertices inserido ultrapasse o limite do tipo long, aparecera uma mensagem de erro.*/	
	if (errno == ERANGE)
	{
		printf ("\n%sErro! O numero de vertices excedeu o limite do tipo Long (%ld).%s\n\n", RED, LONG_MAX, RESET); 
		exit (NUMERO_ULTRAPASSOU_LIMITE_LONG);
	}

	/*Armazena o valor da conversao de tipo do numero de vertices inserido (long para unsigned).*/
	numeroVerticesConvertido = (unsigned) numeroVertices;

	/*Designacao dos index das cores.*/
	corFundo = argv [7 + (numeroVerticesConvertido * 2)];
	corApagado = argv [8 + (numeroVerticesConvertido * 2)];
	corAceso = argv [9 + (numeroVerticesConvertido * 2)];
	corDefeituoso = argv [10 + (numeroVerticesConvertido * 2)];

	index = 7;
	usleep (3000000);

	for (numeroAuxiliar = 1; numeroAuxiliar <= numeroVertices; numeroAuxiliar++)
	{
		linhasVertices[numeroAuxiliar-1] = (unsigned) strtol (argv [index + (numeroAuxiliar-1)], &validacaoLinhasVertices, 10);
		colunasVertices[numeroAuxiliar-1] = (unsigned) strtol (argv [index + (numeroAuxiliar-1) + numeroVertices], &validacaoColunasVertices, 10);
	}

	/*Chamada da funcao "GerarDistribuicaoInicial".*/
	GerarDistribuicaoInicial (monitor, tamanhoLinhasConvertido, tamanhoColunasConvertido, percentualPixelsDefeituosos, percentualPixelsApagados);

	/*Chamada da funcao "MostrarMonitor".*/
	MostrarMonitor (tempoDeCongelamentoConvertido, monitor, tamanhoLinhasConvertido, tamanhoColunasConvertido, corFundo, corApagado, corAceso, corDefeituoso);

	/*Chamada da funcao "LimparMonitor".*/
	LimparMonitor (monitor, tamanhoLinhasConvertido, tamanhoColunasConvertido, corFundo, corApagado, corAceso, corDefeituoso);

	/*Chamada da funcao "DesenharPoligono".*/
	DesenharPoligono (monitor, tamanhoLinhasConvertido, tamanhoColunasConvertido, numeroVertices, linhasVertices, colunasVertices, corFundo, corApagado, corAceso, corDefeituoso);

	/*Chamada da funcao "MostrarMonitor".*/
	MostrarMonitor (tempoDeCongelamentoConvertido, monitor, tamanhoLinhasConvertido, tamanhoColunasConvertido, corFundo, corApagado, corAceso, corDefeituoso);

	return SUCESSO;
}

/* $RCSfile: aula0705.c,v $ */
