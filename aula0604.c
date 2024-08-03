/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Arquivo responsavel pelo cabecalho de funcoes.
 *
 * $Author: joao.vitor $
 * $Date: 2024/07/25 02:47:48 $
 * $Log: aula0604.c,v $
 * Revision 1.2  2024/07/25 02:47:48  joao.vitor
 * adicao da funcao de validar rg
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aula0604.h"

#define END_OF_STRING		'\0'	

/*Cabecalho da funcao "GerarDigitosVerificadoresRg".*/
tipoErros
GerarDigitosVerificadoresRg (char *primeirosDigitosRg, char *digitoVerificador)
{	
	/*Inicializacao das variaveis.*/
	us indexDosDigitosDoRg, contagemDePontos;
	int somaDosProdutosDosDigitosPelosPesos;
	int resultadoDigitoVerificador;
	char stringResultadoDigitoVerificador [2];
	
	/*Inicializa a varialvel que armazena a soma dos produtos dos dígitos anteriores pelos respectivos peso com zero.*/
	somaDosProdutosDosDigitosPelosPesos = 0;
	
	/*Inicializa a varial que conta os pontos '.' da string do RG.*/
	contagemDePontos = 0; 

	printf ("\nRG: ");

	/*Estrutura de Repeticao que imprime todos os digitos do Rg, com excecao do digito verificador.*/
	for (indexDosDigitosDoRg = 0; indexDosDigitosDoRg < (NUMERO_DE_DIGITOS_DO_RG + contagemDePontos); indexDosDigitosDoRg++)
	{
		/*Condicao que verifica os pontos do RG.*/
		if (primeirosDigitosRg [indexDosDigitosDoRg] == '.')
		{
			contagemDePontos += 1;
			continue;
		}
		
		/*Condicao que realiza a impressao dos digitos inseridos.*/
		else if (indexDosDigitosDoRg < (8 + contagemDePontos))
		{
			/*Impressao dos digitos do RG.*/
			printf ("%c", primeirosDigitosRg [indexDosDigitosDoRg]);

			/*Condicao que realiza a impressao dos pontos.*/
			if ((indexDosDigitosDoRg == (1 + contagemDePontos)) || (indexDosDigitosDoRg == (4 + contagemDePontos)))
				printf (".");
	
			/*Soma a variavel ao produto de cada digito pelo seu respectivo peso.*/
			somaDosProdutosDosDigitosPelosPesos += ((primeirosDigitosRg [indexDosDigitosDoRg] - '0') * ((indexDosDigitosDoRg - contagemDePontos) + 2));
		}

		/*Condicao que realiza a impressao do hifen.*/
		else
			printf ("-");
	}

	/*Armazena o resultado do calculo do digito verificador.*/
	resultadoDigitoVerificador = 11 - (somaDosProdutosDosDigitosPelosPesos % 11);

	/*Converte o caractere do resultado em uma string.*/
	stringResultadoDigitoVerificador [0] = (char) (resultadoDigitoVerificador + '0');	
  	stringResultadoDigitoVerificador [1] = END_OF_STRING;	

	/*Caso o digito verificador for onze, o digito verificador vale zero.*/
	if (resultadoDigitoVerificador == 11)
		strcpy (digitoVerificador, "0");
	
	/*Caso o digito verificador for dez, o digito verificador vale "X".*/
	if (resultadoDigitoVerificador == 10)
		strcpy (digitoVerificador, "X");	

	/*Caso contrario, o digito verificador vale o valor da variavel da string do resultado.*/
	else
		strcpy (digitoVerificador, stringResultadoDigitoVerificador);

	return ok;
}

/*Cabecalho da funcao "ValidarRg".*/
tipoErros
ValidarRg (char *digitosRg)
{
	/*Inicializacao das variaveis.*/
	us index;
	char digitoVerificadorInserido [2];
	char digitoVerificadorDevolvido [2];

	/*Armazena o digito verificador inserido pelo usuario em uma string.*/
	digitoVerificadorInserido [0] = digitosRg [11];
	digitoVerificadorInserido [1] = END_OF_STRING;

	/*Inicializa os elementos da variavel (armazenadora do valor do digito verificador devolvido pela funcao) como END_OF_STRING.*/
	for (index = 0; index < 2; index++)
		digitoVerificadorDevolvido [index] = END_OF_STRING;

	/*Chamada da funcao "GerarDigitosVerificadoresRg".*/
	GerarDigitosVerificadoresRg (digitosRg, digitoVerificadorDevolvido);

	/*Impressao do digito verificador inserido.*/
	printf ("%s", digitoVerificadorInserido);

	/*Condicao que compara se os dois digitos verificadores sao diferentes.
	 * Caso sejam, o digito inserido pelo usuario e invalido.*/
	if (strcmp(digitoVerificadorInserido, digitoVerificadorDevolvido))
	{
		printf (" - invalido.\n\n");
		return digitosVerificadoresIncompativeis;
	}

	/*Caso contrario, o digito inserido pelo usuario e invalido.*/
	printf (" - valido.\n\n");
 	
	return ok;
}

/* $RCSfile: aula0604.c,v $ */
