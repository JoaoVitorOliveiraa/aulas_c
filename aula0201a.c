/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Arquivo responsavel pelo cabecalho da funcao "CalcularMaximoDivisorComum". Nesse caso, foi utilizado recursividade em seu calculo.
 *
 * $Author: joao.vitor $
 * $Date: 2024/05/05 16:39:34 $
 * $Log: aula0201a.c,v $
 * Revision 1.4  2024/05/05 16:39:34  joao.vitor
 * Remocao de um else desnecessario
 *
 * Revision 1.3  2024/05/03 18:29:09  joao.vitor
 * Adicao da descricao do arquivo
 *
 * Revision 1.2  2024/05/03 17:41:08  joao.vitor
 * Adicacao da macro ERRO_NUMEROS_INSERIDOS_IGUAIS_A_ZERO
 *
 * Revision 1.1  2024/05/03 03:25:02  joao.vitor
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

	/*Caso o resto da divisao for zero e o primeiro e segundo numero forem diferentes de zero, 
	 * a funcao retorna o segundo numero.*/
	if (restoDaDivisao == 0)
		return segundoNumero;
	
	/*Caso o resto da divisao for diferente de zero e o primeiro e segundo numero forem diferentes de zero,
	 * a funcao retorna o valor da recursividade da propria funcao, sendo seus parametros o segundo numero e o resto da divisao.*/ 
	return CalcularMaximoDivisorComum (segundoNumero, restoDaDivisao);
}

/* $RCSfile: aula0201a.c,v $ */

