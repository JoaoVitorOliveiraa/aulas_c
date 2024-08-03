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
 * $Date: 2024/07/23 16:43:50 $
 * $Log: aula0501.h,v $
 * Revision 1.5  2024/07/23 16:43:50  joao.vitor
 * adicao de macro
 *
 * Revision 1.4  2024/06/10 07:29:15  joao.vitor
 * adicoes das funcoes CalcularMenosComplementar, CalcularComplementarAlgebrico e CalcularDeterminanteMatriz
 *
 * Revision 1.3  2024/06/10 05:05:33  joao.vitor
 * adicao da funcao ObterMatrizTransposta
 *
 * Revision 1.2  2024/06/10 03:25:09  joao.vitor
 * adicao da funcao MultiplicarMatrizes
 *
 * Revision 1.1  2024/06/06 18:33:40  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Caso a macro "AULA0501" nao tenha sido definida, o que esta abaixo sera executado.*/
#ifndef AULA0501

/*Definicao da macro "AULA0501".*/
#define AULA0501			"@(#)aula0501.h $Revision: 1.5 $"

#define _XOPEN_SOURCE_ 1000

/*Definicao do tamanho maximo da matriz.*/
#define	NUMERO_MAXIMO_LINHAS			100
#define NUMERO_MAXIMO_COLUNAS			100

#include <stdio.h>
#include "cores.h"

/*Atribuicoes de tipos a termos.*/
typedef unsigned short us;
typedef long double ld;
typedef enum
{
	ok,
	enderecoDaMatrizInvalido,
	enderecosDasMatrizesInvalidos,
	enderecoDaMatrizAInvalido,
	enderecoDaMatrizBInvalido,
	matrizesIncompativeis
} 
tipoErros;

/*Prototipo da funcao "ExibirMatriz".*/
tipoErros
ExibirMatriz (us, us, ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]);

/*Prototipo da funcao "MultiplicarMatrizes".*/
tipoErros
MultiplicarMatrizes (us, us, us, us, 
			ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
			ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
			ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]);

/*Prototipo da funcao "ObterMatrizTransposta".*/
tipoErros
ObterMatrizTransposta (us, us, ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]);

/*Prototipo da funcao "CalcularMenorComplementar".*/
tipoErros
CalcularMenorComplementar (us, us, us, ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], ld *);

/*Prototipo da funcao "CalcularComplementoAlgebrico".*/
tipoErros
CalcularComplementoAlgebrico (us, us, us, ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], ld *);

/*Prototipo da funcao "CalcularDeterminanteMatriz".*/
tipoErros
CalcularDeterminanteMatriz (us, ld [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], ld *);

/*Fim da condicao.*/
#endif

/* $RCSfile: aula0501.h,v $ */
