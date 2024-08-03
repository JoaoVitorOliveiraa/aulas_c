/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Arquivo reponsavel por prototipos de funcoes, definicao de macros e atribuicoes de tipos para algum termo.
 *
 * $Author: joao.vitor $
 * $Date: 2024/07/23 02:01:04 $
 * $Log: aula0701.h,v $
 * Revision 1.6  2024/07/23 02:01:04  joao.vitor
 * alteracao de macro
 *
 * Revision 1.5  2024/07/21 16:31:04  joao.vitor
 * adicao da funcao de preencher poligono
 *
 * Revision 1.4  2024/07/21 16:27:10  joao.vitor
 * adicao da funcao de desenhar poligono
 *
 * Revision 1.3  2024/07/21 15:54:11  joao.vitor
 * adicao da funcao de desenhar reta
 *
 * Revision 1.1  2024/07/19 22:34:44  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Caso a macro "AULA0701" nao tenha sido definida, o que esta abaixo sera executado.*/
#ifndef AULA0701

/*Definicao da macro "AULA0701".*/
#define AULA0701			"@(#)aula0701.h $Revision: 1.6 $"

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

/*Definicoes de macros.*/
#define	APAGADO				' '			
#define	ACESO				' '			
#define	DEFEITUOSO			'.'
#define NUMERO_MAXIMO_LINHAS		250
#define NUMERO_MAXIMO_COLUNAS		800
#define NUMERO_MAXIMO_VERTICES		50

/*Include's*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "cores.h"

/*Atribuicoes de tipos a termos.*/
typedef unsigned short us;
typedef enum
{
	fundo,
	texto
} 
tipoFundoTexto;

typedef enum
{
	apagado,
	aceso,
	defeituoso = -1
}
tipoPixel;

typedef enum
{
	ok,
	enderecoDaMatrizInvalido,
	numeroDeLinhasInvalido,
	numeroDeColunasInvalido,
	coresIguais,
	percentualDefeituososInvalido,
	percentualApagadosInvalido,
	dimensaoInvalida,
	numeroVerticesInvalido
}
tipoErros;

/*Prototipos de funcoes.*/
char *
ObterCodigoAnsiCor (char *nomeCor, tipoFundoTexto fundoTexto);

tipoErros
MostrarMonitor (useconds_t tempoEspera, 
 		tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		unsigned numeroLinhas, 
		unsigned numeroColunas,
		char *corFundo,  
		char *corPixelApagado, 
		char *corPixelAceso,
		char *corPixelDefeituoso);

tipoErros
GerarDistribuicaoInicial (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
			  unsigned numeroLinhas,
			  unsigned numeroColunas,
			  float percentualDefeituosos,
			  float percentualApagados);

tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		unsigned numeroLinhas,
		unsigned numeroColunas,
		char *corFundo,
		char *corPixelApagado,
		char *corPixelAceso,
		char *corPixelDefeituoso);

tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		unsigned numeroLinhas,
		unsigned numeroColunas,
		unsigned linhaA,
		unsigned colunaA,
		unsigned linhaB,
		unsigned colunaB,
		char *corFundo,
		char *corPixelApagado,
		char *corPixelAceso,
		char *corPixelDefeituoso);

tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		  unsigned numeroLinhas,
		  unsigned numeroColunas,
		  unsigned numeroVertices,
		  unsigned linhasVertices [NUMERO_MAXIMO_VERTICES],
		  unsigned colunasVertices [NUMERO_MAXIMO_VERTICES],
		  char *corFundo,
		  char *corPixelApagado,
		  char *corPixelAceso,
		  char *corPixelDefeituoso);

tipoErros
PreencherPoligono (useconds_t tempoEspera,
		   tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		   unsigned numeroLinhas, 
		   unsigned numeroColunas, 
		   unsigned linha, 
		   unsigned coluna, 
		   char *corFundo, 
		   char *corPixelApagado, 
		   char *corPixelAceso,
		   char *corPixelDefeituoso);

/*Fim da condicao.*/
#endif

/* $RCSfile: aula0701.h,v $ */
