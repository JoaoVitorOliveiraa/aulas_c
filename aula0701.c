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
 * $Date: 2024/07/23 02:16:09 $
 * $Log: aula0701.c,v $
 * Revision 1.4  2024/07/23 02:16:09  joao.vitor
 * adicoes das funcoes de desenhar e preencher poligono
 *
 * Revision 1.3  2024/07/21 15:54:54  joao.vitor
 * adicao da funcao de desenhar reta
 *
 * Revision 1.1  2024/07/19 22:35:33  joao.vitor
 * Initial revision
 *
 *
 *******************************************************************************/

#if defined (__FreeBSD) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE	600
#endif

#include <math.h>
#include <string.h>
#include "aula0701.h"

#define ERRO_OPCAO_INVALIDA			1

/*Cabecalho da funcao "ObterCodigoAnsiCor".*/
char *
ObterCodigoAnsiCor (char *nomeCor, tipoFundoTexto fundoTexto)
{
	if (!(nomeCor))
		return fundoTexto == fundo ? BLACK_BACKGROUND : WHITE;
	
	/*Estrutura condicional que verifica a cor de fundo inserida.*/
	if (fundoTexto == fundo)
	{
		if (!(strcmp (nomeCor, "preto")))
			return BLACK_BACKGROUND;
			
		else if (!(strcmp (nomeCor, "vermelho")))
			return RED_BACKGROUND;

		else if (!(strcmp (nomeCor, "verde")))
			return GREEN_BACKGROUND;

		else if (!(strcmp (nomeCor, "amarelo")))
			return YELLOW_BACKGROUND;

		else if (!(strcmp (nomeCor, "azul")))
			return BLUE_BACKGROUND;

		else if (!(strcmp (nomeCor, "magenta")))
			return MAGENTA_BACKGROUND;

		else if (!(strcmp (nomeCor, "ciano")))
			return CYAN_BACKGROUND;

		else if (!(strcmp (nomeCor, "branco")))
			return WHITE_BACKGROUND;

		else
			return BLACK_BACKGROUND;
	}

	/*Estrutura condicional que verifica a cor de texto inserida.*/
	if (fundoTexto == texto)
	{
		if (!(strcmp (nomeCor, "preto")))
			return BLACK;
			
		else if (!(strcmp (nomeCor, "vermelho")))
			return RED;

		else if (!(strcmp (nomeCor, "verde")))
			return GREEN;

		else if (!(strcmp (nomeCor, "amarelo")))
			return YELLOW;

		else if (!(strcmp (nomeCor, "azul")))
			return BLUE;

		else if (!(strcmp (nomeCor, "magenta")))
			return MAGENTA;

		else if (!(strcmp (nomeCor, "ciano")))
			return CYAN;

		else if (!(strcmp (nomeCor, "branco")))
			return WHITE;

		else
			return WHITE;
	}

	return fundoTexto == fundo ? BLACK_BACKGROUND : WHITE;
}


/*Cabecalho da funcao "MostrarMonitor".*/
tipoErros
MostrarMonitor (useconds_t tempoEspera,
		tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], 
		unsigned numeroLinhas, 
		unsigned numeroColunas,
		char *corFundo,  
		char *corPixelApagado, 
		char *corPixelAceso, 
		char *corPixelDefeituoso)
{
	/*Inicializacao das variaveis.*/
	us linha, coluna;
	char matrizMonitor [numeroLinhas][numeroColunas];

	/*Verifica se a matriz possui um endereco invalido.*/
	if (!monitor)
	{
		printf ("\n\n%sErro! Endereco da Matriz Invalido.%s\n", RED, RESET);
		return enderecoDaMatrizInvalido;
	}
	
	/*Verifica se o usuario inseriu um numero de linhas valido.*/
	if ((numeroLinhas > NUMERO_MAXIMO_LINHAS) || (numeroLinhas < 1))
	{
		printf ("\n\n%sNumero de Linhas Invalido.\nPor favor, insira um numero entre 1 e 250.%s\n", RED, RESET);
		return numeroDeLinhasInvalido;
	}

	/*Verifica se o usuario inseriu um numero de colunas valido.*/
	if ((numeroColunas > NUMERO_MAXIMO_COLUNAS) || (numeroColunas < 1))
	{
		printf ("\n\n%sNumero de Colunas Invalido.\nPor favor, insira um numero entre 1 e 800.%s\n", RED, RESET);
		return numeroDeColunasInvalido;
	}

	/*Verifica se a cor de fundo e a mesma das cores dos caracteres.*/
	if ((corFundo == corPixelApagado) || (corFundo == corPixelAceso) || (corFundo == corPixelDefeituoso))
	{
		printf ("\n\n%sErro! A cor de fundo deve ser diferente das cores dos caracteres.%s\n", RED, RESET);
		return coresIguais;
	}

	/*Limpa a tela do terminal.*/
	system ("clear");

	/*Estrutura de repeticao que armazena os caracteres de delimitacao e os pixels em uma matriz.*/
	for (linha = 1; linha <= numeroLinhas; linha++)
	{
		for (coluna = 1; coluna <= numeroColunas; coluna++)
		{
			if ((linha == 1) || (linha == numeroLinhas))
				matrizMonitor [linha-1][coluna-1] = '-'; 

			else
			{
				if ((coluna == 1) || (coluna == numeroColunas))
					matrizMonitor [linha-1][coluna-1] = '|';

				else
				{
					switch (monitor [linha-1][coluna-1])
					{
						case apagado:
							matrizMonitor [linha-1][coluna-1] = apagado;
							break;

						case aceso:
							matrizMonitor [linha-1][coluna-1] = aceso;
							break;

						case defeituoso:
							matrizMonitor [linha-1][coluna-1] = defeituoso;
							break;

						default:
							matrizMonitor [linha-1][coluna-1] = ' ';
					}
				}
			}
		}

		printf ("\n");
	}
	
	/*Quebra de Linha.*/
	printf ("\n\n");	

	/*Estrutura de repeticao que imprime os pixels e os caracteres de delimitacao na tela.*/
	for (linha = 1; linha <= numeroLinhas; linha++)
	{
		for (coluna = 1; coluna <= numeroColunas; coluna++)
		{
			if (matrizMonitor [linha-1][coluna-1] == apagado)
				printf ("%s%c%s", ObterCodigoAnsiCor (corPixelApagado, fundo), APAGADO, RESET);

			else if (matrizMonitor [linha-1][coluna-1] == aceso)
				printf ("%s%c%s", ObterCodigoAnsiCor (corPixelAceso, fundo), ACESO, RESET);

			else if (matrizMonitor [linha-1][coluna-1] == defeituoso)
				printf ("%s%s%c%s", ObterCodigoAnsiCor (corPixelDefeituoso, texto), ObterCodigoAnsiCor (corFundo, fundo), DEFEITUOSO, RESET);

			else if (matrizMonitor [linha-1][coluna-1] == ' ')
				printf ("%s%c%s", ObterCodigoAnsiCor (corFundo, fundo), ' ', RESET);

			else
				printf ("%c", matrizMonitor [linha-1][coluna-1]);
		}
		
		printf ("\n");
	}

	/*Quebra de Linha.*/
	printf ("\n\n");	

	/*Congela a tela por um determinado periodo.*/
	usleep (tempoEspera);

	return ok;
}


/*Cabecalho da funcao "GerarDistribuicaoInicial".*/
tipoErros
GerarDistribuicaoInicial (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
			  unsigned numeroLinhas,
			  unsigned numeroColunas,
			  float percentualDefeituosos,
			  float percentualApagados)
{
	/*Inicializacao das variaveis.*/
	us linha, coluna, numeroAuxiliar;
	unsigned numeroTotalPixels;
	unsigned numeroPixelsAcesos;
	unsigned numeroPixelsDefeituosos;
	unsigned numeroPixelsApagados;

	/*Verifica se a matriz possui um endereco invalido.*/
	if (!monitor)
	{
		printf ("\n\n%sErro! Endereco da Matriz Invalido.%s\n", RED, RESET);
		return enderecoDaMatrizInvalido;
	}
	
	/*Verifica se o usuario inseriu um numero de linhas valido.*/
	if ((numeroLinhas > NUMERO_MAXIMO_LINHAS) || (numeroLinhas < 1))
	{
		printf ("\n\n%sNumero de Linhas Invalido.\nPor favor, insira um numero entre 1 e 250.%s\n", RED, RESET);
		return numeroDeLinhasInvalido;
	}

	/*Verifica se o usuario inseriu um numero de colunas valido.*/
	if ((numeroColunas > NUMERO_MAXIMO_COLUNAS) || (numeroColunas < 1))
	{
		printf ("\n\n%sNumero de Colunas Invalido.\nPor favor, insira um numero entre 1 e 800.%s\n", RED, RESET);
		return numeroDeColunasInvalido;
	}

	/*Verifica se o usuario inseriu um percentual de pixels defeituosos valido.*/
	if (!((percentualDefeituosos >= 0) && (percentualDefeituosos <= 100)))
	{
		printf ("\n\n%sPercentual de Pixels Defeituosos Invalido.\nPor favor, insira um numero entre 0 e 100.%s\n", RED, RESET);
		return percentualDefeituososInvalido;
	}

	/*Verifica se o usuario inseriu um percentual de pixels apagados valido.*/
	if (!((percentualApagados >= 0) && (percentualApagados <= 100)))
	{
		printf ("\n\n%sPercentual de Pixels Apagados Invalido.\nPor favor, insira um numero entre 0 e 100.%s\n", RED, RESET);
		return percentualApagadosInvalido;
	}

	srand(time(NULL));

	/*Calculos dos valores das variaveis.*/
	numeroTotalPixels = numeroLinhas * numeroColunas;
	numeroPixelsDefeituosos = (unsigned) (numeroTotalPixels * (percentualDefeituosos / 100.0));
	numeroPixelsApagados = (unsigned) (numeroTotalPixels * (percentualApagados / 100.0));
	numeroPixelsAcesos = numeroTotalPixels - numeroPixelsDefeituosos - numeroPixelsApagados;

	/*Inicializa a matriz com os pixels apagados.*/
	for (linha = 1; linha <= numeroLinhas; linha++)
	{
		for (coluna = 1; coluna <= numeroColunas; coluna++)
		{
			monitor[linha-1][coluna-1] = apagado;
		}
	}

	/*Preenche os pixels defeituosos de forma aleatoria.*/
	if (numeroPixelsDefeituosos)
	{
		for (numeroAuxiliar = 0; numeroAuxiliar <= numeroPixelsDefeituosos; numeroAuxiliar++)
		{
			do{
				linha = rand() % numeroLinhas;
				coluna = rand() % numeroColunas;	
			} while (monitor [linha][coluna] != apagado);

			monitor [linha][coluna] = defeituoso;
		}
	}

	/*Preenche os pixels acesos de forma aleatoria.*/
	for (numeroAuxiliar = 0; numeroAuxiliar >= numeroPixelsAcesos; numeroAuxiliar++)
	{
		do{
			linha = rand() % numeroLinhas;
			coluna = rand() % numeroColunas;	
		} while (monitor [linha][coluna] != apagado);

		monitor [linha][coluna] = aceso;
	}

	return ok;
}

/*Cabecalho da funcao "LimparMonitor".*/
tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		unsigned numeroLinhas,
		unsigned numeroColunas,
		char *corFundo,
		char *corPixelApagado,
		char *corPixelAceso,
		char *corPixelDefeituoso)
{
	/*Inicializacao das variaveis.*/
	us linha, coluna;

	/*Estrutura de repeticao que apaga os pixels, com excecao dos defeituosos.*/
	for (linha = 1; linha <= numeroLinhas; linha++)
	{
		for (coluna = 1; coluna <= numeroColunas; coluna++)
		{
			if (monitor [linha-1][coluna-1] != defeituoso)
			{
				monitor [linha-1][coluna-1] = apagado;
			}

			else
			{
				continue;
			}
		}
	}

	return ok;
}

/*Cabecalho da funcao "DesenharReta".*/
tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		unsigned numeroLinhas,
		unsigned numeroColunas,
		unsigned linhaA,
		unsigned colunaA,
		unsigned linhaB,
		unsigned colunaB,
		char *corFundo,
		char *corPixelApagado,
		char *corPixelAceso,
		char *corPixelDefeituoso)
{
	/*Inicializacao da variaveis.*/
	unsigned variavelX, variavelY;
	unsigned numeroAuxiliar;
	unsigned passadas;
	float coordenadaX, coordenadaY;
	float incrementoCoordenadaX, incrementoCoordenadaY;

	/*Consdicao que verifica se a dimencao e invalda.*/
	if ((linhaA >= numeroLinhas) || (colunaA >= numeroColunas) || (linhaB >= numeroLinhas) || (colunaB >= numeroColunas))
		return dimensaoInvalida;

	/*Calculos da reta.*/
	variavelX = colunaB - colunaA;
	variavelY = linhaB - linhaA;

	passadas = abs(variavelX) > abs(variavelY) ? abs(variavelX) : abs(variavelY);
	
	incrementoCoordenadaX = variavelX / (float) passadas;
	incrementoCoordenadaY = variavelY / (float) passadas;

	coordenadaX = colunaA;
	coordenadaY = linhaA;

	for (numeroAuxiliar = 0; numeroAuxiliar <= passadas; numeroAuxiliar++)
	{
		monitor [(unsigned) round(coordenadaY)][(unsigned) round(coordenadaX)] = aceso;
		coordenadaX += incrementoCoordenadaX;
		coordenadaY += incrementoCoordenadaY;
	}

	return ok;
}

/*Cabecalho da funcao "DesenharPoligono".*/
tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],
		  unsigned numeroLinhas, 
		  unsigned numeroColunas,
		  unsigned numeroVertices,
		  unsigned linhasVertices [NUMERO_MAXIMO_VERTICES],
		  unsigned colunasVertices [NUMERO_MAXIMO_VERTICES],
		  char *corFundo,
		  char *corPixelApagado,
		  char *corPixelAceso,
		  char *corPixelDefeituoso)
{
	/*Inicializacao das variaveis.*/
	unsigned linha1, coluna1;
	unsigned linha2, coluna2;
	unsigned numeroAuxiliar;

	/*Verifica se o numero de vertices e valido.*/
	if (numeroVertices < 3)
		return numeroVerticesInvalido;

	for (numeroAuxiliar = 0; numeroAuxiliar < (numeroVertices - 1); numeroAuxiliar++)
	{
		linha1 = linhasVertices [numeroAuxiliar];
		coluna1 = colunasVertices [numeroAuxiliar];
		linha2 = linhasVertices [numeroAuxiliar + 1];
		coluna2 = colunasVertices [numeroAuxiliar + 1];
	
		if ((linha1 >= numeroLinhas) || (linha2 >= numeroLinhas) || (coluna1 >= numeroColunas) || (coluna2 >= numeroColunas))
			return dimensaoInvalida;

		DesenharReta (monitor, numeroLinhas, numeroColunas, linha1, coluna1, linha2, coluna2, corFundo, corPixelApagado, corPixelAceso, corPixelDefeituoso); 
	}
	
	linha1 = linhasVertices [numeroVertices - 1];
	coluna1 = colunasVertices [numeroVertices - 1];
	linha2 = linhasVertices [0];
	coluna2 = colunasVertices [0];

	if ((linha1 >= numeroLinhas) || (linha2 >= numeroLinhas) || (coluna1 >= numeroColunas) || (coluna2 >= numeroColunas))
		return dimensaoInvalida;

	DesenharReta (monitor, numeroLinhas, numeroColunas, linha1, coluna1, linha2, coluna2, corFundo, corPixelApagado, corPixelAceso, corPixelDefeituoso); 
	
	return ok;
}

/*Cabecalho da funcao "PreencherPoligono".*/
tipoErros
PreencherPoligono (useconds_t tempoEspera,
		   tipoPixel monitor[NUMERO_MAXIMO_LINHAS ][NUMERO_MAXIMO_COLUNAS],
		   unsigned numeroLinhas, 
		   unsigned numeroColunas, 
		   unsigned linha,
		   unsigned coluna, 
		   char *corFundo, 
		   char *corPixelApagado, 
		   char *corPixelAceso,
		   char *corPixelDefeituoso)
{
	return ok;
}

/* $RCSfile: aula0701.c,v $ */
