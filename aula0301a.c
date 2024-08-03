/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Arquivo responsavel pelo cabecalho da funcao "CalcularTermoSerieFibonacci". Neste caso, foi utilizado recursividade em seu calculo.
 *
 * $Author: joao.vitor $
 * $Date: 2024/05/10 17:57:17 $
 * $Log: aula0301a.c,v $
 * Revision 1.2  2024/05/10 17:57:17  joao.vitor
 * Remocao de condicao if
 *
 * Revision 1.1  2024/05/10 03:00:44  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#include "aula0301.h"

/*Cabecalho da Funcao "CalcularTermoSerieFibonacci".*/
ull
CalcularTermoSerieFibonacci (us limiteSuperior)
{	
	/*Caso o numero inserido for menor ou igual a zero, a funcao retorna o proprio numero.*/
	if (limiteSuperior <= 1)
		return limiteSuperior;

	/*Caso nao ultrapasse, a funcao retorna a soma de duas recursoes.*/
	return CalcularTermoSerieFibonacci(limiteSuperior-1) + CalcularTermoSerieFibonacci(limiteSuperior-2);
}

/* $RCSfile: aula0301a.c,v $ */
