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
 * $Date: 2024/05/03 18:31:02 $
 * $Log: aula0201.h,v $
 * Revision 1.3  2024/05/03 18:31:02  joao.vitor
 * Adicao da descricao do arquivo.
 *
 * Revision 1.1  2024/05/03 03:26:13  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

/*Caso a macro "AULA0201" nao tenha sido definida, o que esta abaixo sera executado.*/
#ifndef AULA0201

/*Definicao da macro "AULA0201".*/
#define AULA0201			"@(#)aula0201.h $Revision: 1.3 $"

/*Macro correspondente ao caso onde os dois numeros inseridos na funcao "CalcularMaximoDivisorComum" valem zero. */
#define NUMEROS_INSERIDOS_IGUAIS_A_ZERO		0

/*Atribuicao do tipo unsigned long long ao termo ull.*/
typedef unsigned long long ull;

/*Prototipo da funcao "CalcularMaximoDivisorComum".*/
ull
CalcularMaximoDivisorComum (ull, ull);

/*Fim da condicao.*/
#endif

/* $RCSfile: aula0201.h,v $ */
