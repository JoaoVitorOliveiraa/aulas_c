/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Arquivo responsavel pelo cabecalho da funcao "CalcularTermoSerieFibonacci". Neste caso, foi utilizada a estrutura de repeticao "for" em seu calculo.
 *
 * $Author: joao.vitor $
 * $Date: 2024/05/10 19:17:31 $
 * $Log: aula0301c.c,v $
 * Revision 1.2  2024/05/10 19:17:31  joao.vitor
 * Alteracao de comentario
 *
 * Revision 1.1  2024/05/10 16:08:41  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#include "aula0301.h"

/*Cabecalho da Funcao "CalcularTermoSerieFibonacci".*/
ull
CalcularTermoSerieFibonacci (us limiteSuperior)
{	
	/*Inicializacao das variaveis.*/
	ull resultado;
	ull numeroAuxiliar;
	ull somaDosNumeros;
	us termoSerieFibonacci;
	
	/*Caso o numero inserido for menor ou igual a zero, a funcao retorna o proprio numero.*/
	if (limiteSuperior <= 1)
		return limiteSuperior;
	
	/*Inicializacao dos valores para o calculo da funcao.*/
	resultado = 1;
	numeroAuxiliar = 0;
	
	/*Estrutura de Repeticao que executa o calculo da funcao ate o limite inserido.*/
	for (termoSerieFibonacci = 1; termoSerieFibonacci < limiteSuperior; termoSerieFibonacci++)
	{
		somaDosNumeros = resultado + numeroAuxiliar;
		numeroAuxiliar = resultado;
		resultado = somaDosNumeros;
	}
	
	/*Retorna o resultado.*/
	return resultado;
}

/* $RCSfile: aula0301c.c,v $ */
