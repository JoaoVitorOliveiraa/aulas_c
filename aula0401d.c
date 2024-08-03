/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Arquivo responsavel pelo cabecalho da funcao "CalcularExponencial". Neste caso, foi utilizada a estrutura de repeticao "while" em seu calculo.
 *
 * $Author: joao.vitor $
 * $Date: 2024/05/28 02:00:06 $
 * $Log: aula0401d.c,v $
 * Revision 1.1  2024/05/28 02:00:06  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#include "aula0401.h"

/*Cabecalho da Funcao "CalcularExponencial".*/
ld
CalcularExponencial (double numero,int expoente)
{	
	/*Inicializacao das variaveis.*/
	ld resultadoExponencial;
	int numeroAuxiliar;

	resultadoExponencial = 1;
	numeroAuxiliar = 0;

	/*Caso o expoente seja zero, retorna-se "1".*/
	if (expoente == 0)
		return 1;
	
	/*Caso o valor da base seja zero e o expoente um valor negativo, retorna-se infinito.*/
	if ((numero == 0) && (expoente < 0))
		return HUGE_VAL;
	
	/*Caso os valores do expoente e da base forem diferentes de zero, o calculo e realizado.*/
	if ((expoente != 0) && (numero != 0))
	{
		while (numeroAuxiliar < expoente)
		{
			resultadoExponencial *= numero;
			numeroAuxiliar++;
		}
	}
	
	/*Retorno do resultado.*/
	return resultadoExponencial;
}

/* $RCSfile: aula0401d.c,v $ */
