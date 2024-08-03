/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Arquivo responsavel por exibir as "256" possiveis cores de um terminal.
 *
 * $Author: joao.vitor $
 * $Date: 2024/04/21 00:48:20 $
 * $Log: aula0104.c,v $
 * Revision 1.2  2024/04/21 00:48:20  joao.vitor
 * *** empty log message ***
 *
 * Revision 1.1  2024/04/20 08:23:25  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "aula0101.h"

/*Definicao da macro "SUCESSO" e "TABULACAO_DA_TABELA".*/
#define SUCESSO				0
#define TABULACAO_DA_TABELA		1111

/*Inicializacao da Funcao.*/
int
main()
{
	/*Inicializacao da Variavel "cor".*/
	int cor;
		
	/*Quebra de Linha.*/
	printf ("\n");
	
	/*Funcao que exibe um cabecalho de numeros, onde a quantidade e dada pelo numero inserido.*/	
	ExibirCabecalho(80);
	
	/*Quebra de Linha.*/
	printf ("\n");
	
	/*Estrutura de Repeticao que passa por todas as "256" possiveis cores.*/
	for(cor = 0; cor <= 255; cor++)
	{
		/*Caso o valor da cor for multiplo de "16", serao exibidos na tela quatro numeros, onde suas cores possuem o valor zero.*/ 
		/*Os quatro numeros sao definidos na macro "TABULACAO_DA_TABELA" e sao responsaveis pela tabulacao da tabela, 
		 * tomando como referencia os "80" numeros que a funcao "ExibirCabecalho" exibe.*/ 
		if (cor % 16 == 0)
		{	
			printf ("\e[38;5;%dm%d\e[38;5;%dm", 0, TABULACAO_DA_TABELA, 0);
		} 
		
		/*Caso o valor da cor for menor que "10", o respectivo valor e exibido na tela, com dois zeros a sua esquerda.*/
		if (cor < 10)
		{
			printf ("\e[38;5;%dm00%d\e[38;5;%dm ", cor, cor, cor);
		}
	
		/*Caso o valor da cor for maior que "10" e menor que "100", o respectivo valor e exibido na tela, com um zero a sua esquerda.*/
		if ((cor >= 10) && (cor < 100))
		{
			printf ("\e[38;5;%dm0%d\e[38;5;%dm ", cor, cor, cor);
		}

		/*Caso o valor da cor for maior que "100", o respectivo valor e exibido na tela, sem zeros a sua esquerda.*/
		if (cor >= 100)
		{
			printf ("\e[38;5;%dm%d\e[38;5;%dm ", cor, cor, cor);
		}
		
		/*Caso a numeracao da cor (equivalente a "cor + 1", por conta de seu valor inicial ser "0") for um valor multiplo de "16" (excluindo o zero), 
		 * a linha se quebra no final, a fim de continuar a exibicao na linha seguinte.*/
		if ((cor + 1) % 16 == 0)
		{
			printf ("\n");
		}
	}	

	/*Quebra de Linha.*/
	printf ("\n");

	return SUCESSO; 	
}	

/* $RCSfile: aula0104.c,v $ */
