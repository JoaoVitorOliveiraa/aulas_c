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
 * $Date: 2024/07/25 03:24:19 $
 * $Log: aula0601.c,v $
 * Revision 1.3  2024/07/25 03:24:19  joao.vitor
 * alteracao de impressao
 *
 * Revision 1.2  2024/07/23 23:25:22  joao.vitor
 * adicao da funcao de validar rg
 *
 * Revision 1.1  2024/06/24 07:19:44  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include "aula0601.h"

/*Cabecalho da funcao "GerarDigitosVerificadoresRg".*/
tipoErros
GerarDigitosVerificadoresRg (byte matrizDeDigitosDoRg [NUMERO_DE_DIGITOS_DO_RG])
{	
	/*Inicializacao das variaveis.*/
	us indexDosDigitosDoRg, digitoVerificador;
	us somaDosProdutosDosDigitosPelosPesos;
	
	/*Inicializa a varialvel que armazena a soma dos produtos dos dígitos anteriores pelos respectivos peso com zero.*/
	somaDosProdutosDosDigitosPelosPesos = 0;

	/*Condicao que verifica se o usuario inseriu uma matriz com um endereco invalido.*/
	if (!matrizDeDigitosDoRg)
		return enderecoDaMatrizInvalido;
	
	printf ("\nRG: ");

	/*Estrutura de Repeticao que imprime todos os digitos do Rg, com excecao do digito verificador.*/
	for (indexDosDigitosDoRg = 0; indexDosDigitosDoRg < NUMERO_DE_DIGITOS_DO_RG; indexDosDigitosDoRg++)
	{
		/*Condicao que realiza a impressao dos digitos inseridos.*/
		if (indexDosDigitosDoRg < 8)
		{
			/*Impressao dos digitos do RG.*/
			printf ("%u", matrizDeDigitosDoRg [indexDosDigitosDoRg]);

			/*Condicao que realiza a impressao dos pontos.*/
			if ((indexDosDigitosDoRg == 1) || (indexDosDigitosDoRg == 4))
				printf (".");
	
			/*Soma a variavel ao produto de cada digito pelo seu respectivo peso.*/
			somaDosProdutosDosDigitosPelosPesos += (matrizDeDigitosDoRg [indexDosDigitosDoRg] * (indexDosDigitosDoRg + 2));
		}

		/*Condicao que realiza a impressao do hifen.*/
		else
			printf ("-");
	}

	/*Armazena o calculo do digito verificador.*/
	digitoVerificador = 11 - (somaDosProdutosDosDigitosPelosPesos % 11);

	/*Caso o digito verificador for onze, o oitavo index da matriz de digitos vale zero.*/
	if (digitoVerificador == 11)
		matrizDeDigitosDoRg [8] = 0;

	/*Caso o digito verificador for dez, o oitavo index da matriz de digitos vale "X".*/
	if (digitoVerificador == 10)
		matrizDeDigitosDoRg [8] = 'X';
		
	/*Caso o digito verificador for diferente de dez ou onze, o oitavo index da matriz de digitos vale o valor da variavel do digito.*/
	else
		matrizDeDigitosDoRg [8] = digitoVerificador;

	return matrizDeDigitosDoRg [8];
}

/*Cabecalho da funcao "ValidarRg".*/
tipoErros
ValidarRg (byte matrizDeDigitosDoRg [NUMERO_DE_DIGITOS_DO_RG])
{
	/*Inicializacao das variaveis.*/
	byte digitoVerificadorInserido;
	byte digitoVerificadorDevolvido;

	/*Condicao que verifica se o usuario inseriu uma matriz com um endereco invalido.*/
	if (!matrizDeDigitosDoRg)
		return enderecoDaMatrizInvalido;

	/*Armazena o digito verificador inserido pelo usuario.*/
	digitoVerificadorInserido = matrizDeDigitosDoRg [8];

	/*Chamada da funcao "GerarDigitosVerificadoresRg".*/
	GerarDigitosVerificadoresRg (matrizDeDigitosDoRg);

	/*Armazena o valor do digito verificador devolvido pela funcao.*/
	digitoVerificadorDevolvido = matrizDeDigitosDoRg [8];

	/*Impressao do digito verificador inserido.*/
	printf ("%u", digitoVerificadorInserido);

	/*Condicao que compara se os dois digitos verificadores sao diferentes.
	 * Caso sejam, o digito inserido pelo usuario e invalido.*/
	if (digitoVerificadorInserido != digitoVerificadorDevolvido)
	{
		printf (" - invalido.\n\n");
		return digitosVerificadoresIncompativeis;
	}

	/*Caso contrario, o digito inserido pelo usuario e invalido.*/
	printf (" - valido.\n\n");
	return ok;
}

/* $RCSfile: aula0601.c,v $ */
