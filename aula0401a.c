/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Arquivo responsavel pelo cabecalho da funcao "CalcularExponencial". Neste caso, foi utilizado recursividade em seu calculo.
 *
 * $Author: joao.vitor $
 * $Date: 2024/05/27 22:28:08 $
 * $Log: aula0401a.c,v $
 * Revision 1.2  2024/05/27 22:28:08  joao.vitor
 * correcao de um if
 *
 * Revision 1.1  2024/05/27 04:07:53  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#include "aula0401.h"

/*Cabecalho da Funcao "CalcularExponencial".*/
ld
CalcularExponencial (double numero,int expoente)
{	
	ld calculoExponencial;
	
	/*Caso o valor da base seja zero e o expoente um valor negativo, retorna-se infinito.*/
	if ((numero == 0) && (expoente < 0))
		return HUGE_VAL;
	
	/*Caso o expoente seja zero, retorna-se "1".*/
	if (expoente == 0)
		return 1;
	
	/*Caso o valor do expoente for menor que zero, a base e o expoente sao ajustados para a conta.*/
	if (expoente < 0)
	{
		numero = (1/numero);
		expoente *= (-1); 
		calculoExponencial = numero * CalcularExponencial (numero, expoente-1);
	}

	else
		/*Realizacao do calculo do exponencial*/
		calculoExponencial = numero * CalcularExponencial (numero, expoente-1);
	
	/*Retorno do resultado.*/
	return calculoExponencial;
}

/* $RCSfile: aula0401a.c,v $ */
