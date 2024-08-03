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
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

/*Caso a macro "_AULA08_" nao tenha sido definida, o que esta abaixo sera executado.*/
#ifndef _AULA08_

/*Definicao da macro "_AULA08_".*/
#define _AULA08_			"@(#)aula0801.h $Revision$"

/*Definicao do numero de digitos do RG.*/
#define	NUMERO_DE_DIGITOS_DO_RG			9

/*Atribuicoes de tipos a termos.*/
typedef unsigned char byte;
typedef enum
{
	ok,
	enderecoDaMatrizInvalido,
	digitosVerificadoresIncompativeis
} 
tipoErros;

/*Prototipo da funcao "CodificarBase16".*/
tipoErros
CodificarBase16 (byte [NUMERO_DE_DIGITOS_DO_RG]);

ValidarRg (byte *, unsigned long long, char *);

/*Fim da condicao.*/
#endif

/* $RCSfile: aula0601.h,v $ */








/* $RCSfile$ */
