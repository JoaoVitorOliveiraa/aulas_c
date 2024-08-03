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
 * $Date: 2024/07/24 06:36:05 $
 * $Log: aula0604.h,v $
 * Revision 1.1  2024/07/24 06:36:05  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Caso a macro "AULA0604" nao tenha sido definida, o que esta abaixo sera executado.*/
#ifndef AULA0604

/*Definicao da macro "AULA0604".*/
#define AULA0604			"@(#)aula0604.h $Revision: 1.1 $"

/*Definicao do numero de digitos do RG.*/
#define	NUMERO_DE_DIGITOS_DO_RG			9

/*Include's.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cores.h"

/*Atribuicoes de tipos a termos.*/
typedef unsigned short us;
typedef enum
{
	ok,
	digitosVerificadoresIncompativeis
} 
tipoErros;

/*Prototipo da funcao "GerarDigitosVerificadoresRg".*/
tipoErros
GerarDigitosVerificadoresRg (char *, char *);

/*Prototipo da funcao "ValidarRg".*/
tipoErros
ValidarRg (char *);

/*Fim da condicao.*/
#endif

/* $RCSfile: aula0604.h,v $ */
