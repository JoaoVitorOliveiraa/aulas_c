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
 * $Date: 2024/05/10 18:58:53 $
 * $Log: aula0301.h,v $
 * Revision 1.2  2024/05/10 18:58:53  joao.vitor
 * Remocao das definicoes para o valor da macro ULLONG_MAX
 *
 * Revision 1.1  2024/05/10 02:59:59  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Caso a macro "AULA0301" nao tenha sido definida, o que esta abaixo sera executado.*/
#ifndef AULA0301

/*Definicao da macro "AULA0301".*/
#define AULA0301			"@(#)aula0301.h $Revision: 1.2 $"

/*Atribuicoes de tipos a termos.*/
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned short us;

/*Prototipo da funcao "CalcularTermoSerieFibonacci".*/
ull
CalcularTermoSerieFibonacci (us);

/*Fim da condicao.*/
#endif

/* $RCSfile: aula0301.h,v $ */
