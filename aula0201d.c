/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Arquivo responsavel pelo cabecalho da funcao "CalcularMaximoDivisorComum". Nesse caso, foi utilizada a estrutura de repeticao "while" em seu calculo.
 *
 * $Author: joao.vitor $
 * $Date: 2024/05/04 03:17:18 $
 * $Log: aula0201d.c,v $
 * Revision 1.1  2024/05/04 03:17:18  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#include "aula0201.h"

/*Cabecalho da Funcao "CalcularMaximoDivisorComum".*/
ull
CalcularMaximoDivisorComum (ull primeiroNumero, ull segundoNumero)
{	
	/*Inicializacao da variavel que armazena o valor do resto da divisao entre os numeros.*/
	ull restoDaDivisao;
	
	/*Caso os dois numeros forem zero, a funcao retorna zero.*/
	if ((primeiroNumero == 0) && (segundoNumero == 0))
		return NUMEROS_INSERIDOS_IGUAIS_A_ZERO;

	/*Caso o segundo numero for zero e o primeiro diferente de zero, a funcao retorna o primeiro numero.*/
	if ((primeiroNumero != 0) && (segundoNumero == 0))
		return primeiroNumero;
	
	/*Caso o primeiro numero for zero e o segundo diferente de zero, a funcao retorna o segundo numero.*/
	if ((primeiroNumero == 0) && (segundoNumero != 0))
		return segundoNumero;	
			
	/*Calcula o valor do resto da divisao de "primeiroNumero" por "segundoNumero".*/
	restoDaDivisao = primeiroNumero % segundoNumero;	
	
	/*O loop ocorre ate que o valor do resto da divisao entre os numeros for diferente de zero. */
	while (restoDaDivisao != 0)
	{
		/*Ao final do loop, o valor do primeiro numero se torna o do segundo, 
		 * e o valor do segundo se torna o do resto da divisao.*/
		primeiroNumero = segundoNumero;
		segundoNumero = restoDaDivisao;
		
		/*Calcula o valor do resto da divisao de "primeiroNumero" por "segundoNumero".*/
		restoDaDivisao = primeiroNumero % segundoNumero;	
	}

	/*Caso o resto da divisao for zero, a funcao retorna o valor do segundo numero.*/
	return segundoNumero;
}

/* $RCSfile: aula0201d.c,v $ */
