/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 *
 * Descricao: Arquivo responsavel por exibir um nome sublinhado e centralizado na tela, sendo vermelha as cores do texto e do sublinhado.
 * 		Alem disso, tambem exibem-se um cabecalho de numeros e uma sequencia de hifens.
 *
 * $Author: joao.vitor $
 * $Date: 2024/04/21 16:58:40 $
 * $Log: aula0105.c,v $
 * Revision 1.2  2024/04/21 16:58:40  joao.vitor
 * *** empty log message ***
 *
 * Revision 1.1  2024/04/20 10:57:27  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cores.h"
#include "aula0101.h"

/*Definicao das Macros.*/
#define SUCESSO						0
#define NUMERO_ARGUMENTOS_INVALIDO			1
#define NOME_INSERIDO_POR_UNICO_ARGUMENTO		2
#define TABULACAO_ARGUMENTO				3

/*Inicializacao da Funcao Principal.*/
int
main(int argc, char *argv [])
{
	/*Inicializacao das variaveis.*/
	int posicaoPrimeiraLetra;
	int tamanhoNome;
	int coluna;
	int quantidadeArgumentos;
	int quantidadeEspacos;
	int argumento;
	
	/*Caso o usuario nao insira um argumento, sera exibida uma mensagem de erro na tela.*/	
	if (argc == NUMERO_ARGUMENTOS_INVALIDO)
	{
		printf ("\n%sNumero de Argumentos Invalido.%s\n", RED, RESET);
		printf ("\n%sInsira um Nome que possua entre 1 e 50 caracteres.%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	/*Condicao que verifica se o usuario inseriu o nome por meio de um unico argumento.*/
	if (argc == NOME_INSERIDO_POR_UNICO_ARGUMENTO) 
	{	
		/*Variavel que contem o tamanho do nome inserido.*/
		tamanhoNome = strlen(argv [1]);
		
		/*Caso o usuario insira um nome com mais de "50" caracteres, sera exibida uma mensagem de erro na tela.*/	
		if (tamanhoNome > 50)
		{
			printf ("\n%sNumero de Argumentos Invalido.%s\n", RED, RESET);
			printf ("\n%sInsira um Nome que possua entre 1 e 50 caracteres.%s\n\n", RED, RESET);
			exit (NUMERO_ARGUMENTOS_INVALIDO);
		}
			
		/*Quebra de Linha.*/
		printf ("\n");
	
		/*Funcao que exibe um cabecalho contendo uma quantidade de numeros (inserida dentro dos parenteses). 
		 * Neste caso, exibem-se "100" numeros.*/
		ExibirCabecalho(100);		
		
		/*Quebra de Linha.*/
		printf ("\n");

		/*Variavel que contem a posicao da primeira letra do nome inserido, sendo necessaria na sua centralizacao.
		 * OBS: Como serao exibidas "100" colunas na tela, a posicao da primeira letra sera a metade do numero de colunas ("48") 
		 * menos a metade do tamanho do nome. Pois, o decremento da metade se refere a primeira letra, enquanto o incremento a ultima.*/
		posicaoPrimeiraLetra = (48 - (tamanhoNome/2));
		
		/*Estrutura de Repeticao que passa pelas colunas do terminal ate a posicao da primeira letra do nome.*/
		for(coluna = 0; coluna <= posicaoPrimeiraLetra; coluna++)
		{
			/*Caso a numeracao da coluna for igual a posicao da primeira letra da palavra, a palavra e exibida.*/
			if (coluna == posicaoPrimeiraLetra)
			{
				printf ("%s%s\"%s\"%s\n", RED, UNDERLINE_RED, argv [1], RESET);
			}
			
			/*Caso a numeracao da coluna for diferente da posicao da primeira letra da palavra, realiza-se uma tabulacao na tela atraves
			 * do valor da macro "TABULACAO_ARGUMENTO".*/
			else
			{
				printf ("%s%d%s", BLACK, TABULACAO_ARGUMENTO, RESET);
			}
		}
	}
	
	/*Condicao que verifica se o usuario inseriu o nome por meio de varios argumentos.*/
	if (argc > NOME_INSERIDO_POR_UNICO_ARGUMENTO)
	{	
		/*Inicializa a variavel "tamanhoNome" com o valor "0".*/
		tamanhoNome = 0;

		/*A quantidade de argumentos inseridos pelo usuario, equivale a quantidade total de argumentos ("argc") menos o nome do executavel (uma unidade).*/
		quantidadeArgumentos = argc - 1;

		/*A quantidade de espacos entre os argumentos, equivale quantidade de argumentos menos uma unidade.*/
		quantidadeEspacos = quantidadeArgumentos - 1;

		/*Estrutura de Repeticao que passa por todos os argumentos inseridos, sendo representados pela variavel "argumento".*/
		for(argumento = 1; argumento <= quantidadeArgumentos; argumento++)
		{
			/*Soma o tamanho de cada argumento na variavel "tamanhoNome".*/
			tamanhoNome += strlen(argv [argumento]);
		}
		
		/*Caso o usuario insira um nome com mais de "50" caracteres, sera exibida uma mensagem de erro na tela.*/	
		if (tamanhoNome > 50)
		{
			printf ("\n%sNumero de Caracteres Invalido.%s\n", RED, RESET);
			printf ("\n%sInsira um Nome que possua entre 1 e 50 caracteres.%s\n\n", RED, RESET);
			exit (NUMERO_ARGUMENTOS_INVALIDO);
		}
	
		/*Quebra de Linha.*/
		printf ("\n");
	
		/*Funcao que exibe um cabecalho contendo uma quantidade de numeros (inserida dentro dos parenteses). 
	 	* Neste caso, exibem-se "100" numeros.*/
		ExibirCabecalho(100);		
		
		/*Quebra de Linha.*/
		printf ("\n");

		/*Variavel que contem a posicao da primeira letra do nome inserido, sendo necessaria na sua centralizacao.
		 * OBS: Como serao exibidas "100" colunas na tela, a posicao da primeira letra sera a metade do numero de colunas ("48") 
		 * menos a metade da soma do tamanho do nome com a quantidade de espacos. 
		 * Pois, o decremento da metade se refere a primeira letra, enquanto o incremento a ultima.*/
		posicaoPrimeiraLetra = (48 - ((tamanhoNome + quantidadeEspacos) / 2));

		/*Estrutura de Repeticao que passa pelas colunas do terminal ate a posicao da primeira letra do nome.*/
		for(coluna = 0; coluna <= posicaoPrimeiraLetra; coluna++)
		{
			/*Caso a numeracao da coluna for igual a posicao da primeira letra da palavra, a palavra e exibida.*/
			if (coluna == posicaoPrimeiraLetra)
			{
				/*Estrutura de Repeticao que passa por todos os argumentos inseridos, sendo representados pela variavel "argumento".*/
				for(argumento = 1; argumento <= quantidadeArgumentos; argumento++)
				{
					/*No primeiro argumento, serao exibidas aspas na sua esquerda.*/
					if (argumento == 1)
					{
						printf ("%s%s\"%s ", RED, UNDERLINE_RED, argv [argumento]);
					}
					
					/*No ultimo argumento, serao exibidas aspas na sua direita e havera uma quebra de linha.*/
					if (argumento == quantidadeArgumentos)
					{
						printf ("%s\"%s\n", argv [argumento], RESET);

					}
					
					/*Exibe os argumentos do meio sem aspas.*/
					if ((argumento > 1) && (argumento < quantidadeArgumentos))
					{
						printf ("%s ", argv [argumento]);
					}
				}
			}
			
			/*Caso a numeracao da coluna for diferente da posicao da primeira letra da palavra, realiza-se uma tabulacao na tela atraves
			 * do valor da macro "TABULACAO_ARGUMENTO".*/
			else
			{
				printf ("%s%d%s", BLACK, TABULACAO_ARGUMENTO, RESET);
			}
		}
	}
	
	/*Funcao que exibe uma certa quantidade de hifens, sendo ela inserida dentro dos parenteses. 
	* Neste caso, exibem-se "100" hifens.*/
	ExibirHifens(100);

	return SUCESSO;
}

/* $RCSfile: aula0105.c,v $ */
