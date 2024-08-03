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
 * $Date: 2024/07/23 23:24:26 $
 * $Log: aula0601.h,v $
 * Revision 1.3  2024/07/23 23:24:26  joao.vitor
 * atualizacao do tipoerros
 *
 * Revision 1.2  2024/07/23 16:55:30  joao.vitor
 * adicao da funcao de validar rg
 *
 * Revision 1.1  2024/06/24 07:19:27  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Caso a macro "AULA0601" nao tenha sido definida, o que esta abaixo sera executado.*/
#ifndef AULA0601

/*Definicao da macro "AULA0601".*/
#define AULA0601			"@(#)aula0601.h $Revision: 1.3 $"

/*Definicao do numero de digitos do RG.*/
#define	NUMERO_DE_DIGITOS_DO_RG			9

/*Atribuicoes de tipos a termos.*/
typedef unsigned char byte;
typedef unsigned short us;
typedef enum
{
	ok,
	enderecoDaMatrizInvalido,
	digitosVerificadoresIncompativeis
} 
tipoErros;

/*Prototipo da funcao "GerarDigitosVerificadoresRg".*/
tipoErros
GerarDigitosVerificadoresRg (byte [NUMERO_DE_DIGITOS_DO_RG]);

/*Prototipo da funcao "ValidarRg".*/
tipoErros
ValidarRg (byte [NUMERO_DE_DIGITOS_DO_RG]);

/*Fim da condicao.*/
#endif

/* $RCSfile: aula0601.h,v $ */
