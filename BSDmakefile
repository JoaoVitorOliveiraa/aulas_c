# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# Prof. Marcelo Luiz Drumond Lanza
# EEL270 - Computacao II - Turma 2024/1

# Descricao: Arquivo de Dependencias especifico para os sistemas operacionais da familia FreeBSD, na qual éreferente as aulas praticas da disciplina.  
 
# $Author: joao.vitor $
# $Date: 2024/07/25 02:50:16 $
# $Log: BSDmakefile,v $
# Revision 1.39  2024/07/25 02:50:16  joao.vitor
# adicao da aula0606b
#
# Revision 1.38  2024/07/25 02:31:18  joao.vitor
# adicao da aula0606a
#
# Revision 1.37  2024/07/24 22:41:53  joao.vitor
# adicao da aula0605b
#
# Revision 1.36  2024/07/24 06:41:05  joao.vitor
# adicao da aula0605a
#
# Revision 1.35  2024/07/23 23:33:12  joao.vitor
# adicoes da aula0602b e aula0603a
#
# Revision 1.34  2024/07/23 16:16:20  joao.vitor
# adicao da aula0705
#
# Revision 1.33  2024/07/21 15:55:15  joao.vitor
# adicao da aula0704
#
# Revision 1.32  2024/07/20 22:19:56  joao.vitor
# adicao da aula0703
#
# Revision 1.31  2024/07/19 22:36:11  joao.vitor
# adicao da aula0702 e libmonitor
#
# Revision 1.30  2024/06/24 07:18:29  joao.vitor
# adicao aula0602a
#
# Revision 1.29  2024/06/10 09:16:32  joao.vitor
# adicao da aula0507
#
# Revision 1.28  2024/06/10 08:53:28  joao.vitor
# adicao da aula0506
#
# Revision 1.27  2024/06/10 07:26:50  joao.vitor
# adicao da aula0505
#
# Revision 1.26  2024/06/10 05:04:09  joao.vitor
# adicao da aula0504
#
# Revision 1.25  2024/06/10 03:29:19  joao.vitor
# adicao da libmatematica.a e da aula0503
#
# Revision 1.24  2024/06/06 13:53:11  joao.vitor
# Adicao da aula0502
#
# Revision 1.23  2024/05/28 02:00:31  joao.vitor
# adicao da aula402d e atualizacao da libmatematica-for.a
#
# Revision 1.22  2024/05/28 01:34:36  joao.vitor
# adicao da aula0402c
#
# Revision 1.19  2024/05/27 04:08:48  joao.vitor
# adicao aula04
#
# Revision 1.18  2024/05/10 19:38:24  joao.vitor
# Atualizacao da biblioteca libmatematica-while.a
#
# Revision 1.17  2024/05/10 19:23:42  joao.vitor
# Adicao da aula0302d
#
# Revision 1.16  2024/05/10 19:06:44  joao.vitor
# Atualizacao da biblioteca libmatematica-for.a
#
# Revision 1.15  2024/05/10 16:00:44  joao.vitor
# Adicao da aula0302c
#
# Revision 1.14  2024/05/10 15:52:59  joao.vitor
# Atualizacao da biblioteca libmatematica-dowhile.a
#
# Revision 1.11  2024/05/10 03:01:50  joao.vitor
# Adicao da aula03 e de seu codigo com recursao
#
# Revision 1.10  2024/05/05 16:41:28  joao.vitor
# Adicao de hifens nos nomes das bibliotecas
#
# Revision 1.9  2024/05/04 03:44:18  joao.vitor
# Adicao da libmatematicawhile
#
# Revision 1.8  2024/05/04 03:18:03  joao.vitor
# Adicao da aula0201d e libmatematicafor
#
# Revision 1.7  2024/05/03 20:29:01  joao.vitor
# Adicao da aula0202c e libmatematicadowhile
#
# Revision 1.6  2024/05/03 19:36:52  joao.vitor
# Adicao da au�la020b e libmatematicarecursao
#
# Revision 1.5  2024/05/03 03:26:36  joao.vitor
# Adicao da aula02
#
# Revision 1.4  2024/04/22 06:27:46  joao.vitor
# *** empty log message ***
#
# Revision 1.3  2024/04/20 08:22:13  joao.vitor
# *** empty log message ***
#
# Revision 1.2  2024/04/20 06:14:37  joao.vitor
# *** empty log message ***
#
# Revision 1.1  2024/04/19 18:44:44  joao.vitor
# Initial revision
#


# Macro correspondente ao sistema operacional.
OS = `uname -s`

# Macros correspondentes ao compilador "gcc".
CC = gcc

# Caso o usuario queira alterar o compilador para "clang", o valor da macro "CC" é alterao para "clang".
.ifdef CLANG
CC = clang
.endif

# Macro correspondente ao valor da macro "CC".
LD = $(CC)

# Macros correspondentes ao dialeto e valor padrao "ansi", respectivamente.
DIALECT = ansi
STANDARD = -ansi

# Caso o usuario queira alterar o dialeto e o valor padrao durante a execucao do comando "make", as macros "DIALECT" e "STANDARD" sao alteradas para algum dialeto e valor padrao abaixo.
.ifdef C89
DIALECT = c89
STANDARD = -std=c89
.elif C90
DIALECT = c90
STANDARD = -std=c90
.elif C99
DIALECT = c99
STANDARD = -std=c99
.elif C11
DIALECT = c11
STANDARD = -std=c11
.endif

# Macro correspondente a uma "string" vazia.
DEBUG =

# Caso o usuario queria que alguma depuracao seja mostrada, o valor da macro "DEBUG" éalterado para "-DDEPURACAO". 
.ifdef DEPURACAO
DEBUG = -DDEPURACAO
.endif

# Macro correspondente aos comandos "Wall", na qual relata todos os "warnings" presentes no codigo-fonte apos sua compilacao, "STANDARD" e "DEBUG".
CFLAGS = -Wall $(STANDARD) $(DEBUG)

# Macro correspondente ao comando "Wall".
LFLAGS = -Wall 

# Macro correspondente a todos os executaveis referentes a AULA01.
AULA01 = aula0102 aula0103\
	 aula0104 aula0105\
	 aula0106 aula0107

# Macro correspondente a todos os executaveis referentes a AULA02.
AULA02 = aula0202a aula0202b\
	 aula0202c aula0202d

# Macro correspondente a todos os executaveis referentes a AULA03.
AULA03 = aula0302a aula0302b\
	 aula0302c aula0302d

# Macro correspondente a todos os executaveis referentes a AULA04.
AULA04 = aula0402a aula0402b\
	 aula0402c aula0402d

# Macro correspondente a todos os executaveis referentes a AULA05.
AULA05 = aula0502 aula0503 aula0504\
	 aula0505 aula0506 aula0507

# Macro correspondente a todos os executaveis referentes a AULA06.
AULA06 = aula0602a aula0602b\
	 aula0603a aula0603b\
	 aula0605a aula0605b\
	 aula0606a aula0606b

# Macro correspondente a todos os executaveis referentes a AULA07.
AULA07 = aula0702 aula0703 aula0704 aula0705

# Macro correspondente aos codigos-objeto "aula0101.o" e "aula0102.o".
AULA0102OBJS = aula0101.o aula0102.o 

# Macro correspondente aos codigos-objeto "aula0101.o" e "aula0103.o".
AULA0103OBJS = aula0101.o aula0103.o 

# Macro correspondente aos codigos-objeto "aula0101.o" e "aula0104.o".
AULA0104OBJS = aula0101.o aula0104.o 

# Macro correspondente aos codigos-objeto "aula0101.o" e "aula0105.o".
AULA0105OBJS = aula0101.o aula0105.o 

# Macro correspondente aos codigos-objeto "aula0101.o" e "aula0106.o".
AULA0106OBJS = aula0101.o aula0106.o

# Macro correspondente aos codigos-objeto "aula0101.o" e "aula0107.o".
AULA0107OBJS = aula0101.o aula0107.o

# Macro correspondente aos codigos-objeto "aula0201a.o" e "aula0202.o".
AULA0202AOBJS = aula0201a.o aula0202.o

# Macro correspondente aos codigos-objeto da biblioteca "libmatematica-recursao.a".
LIBMATEMATICARECURSAOOBJS = aula0201a.o aula0301a.o aula0401a.o

# Macro correspondente a biblioteca "libmatematica-recursao.a".
LIBMATEMATICARECURSAO = libmatematica-recursao.a

# Macro correspondente aos codigos-objeto "aula0201b.o" e "aula0202.o".
AULA0202BOBJS = aula0201b.o aula0202.o

# Macro correspondente aos codigos-objeto da biblioteca "libmatematica-dowhile.a".
LIBMATEMATICADOWHILEOBJS = aula0201b.o aula0301b.o aula0401b.o

# Macro correspondente a biblioteca "libmatematica-dowhile.a".
LIBMATEMATICADOWHILE = libmatematica-dowhile.a

# Macro correspondente aos codigos-objeto "aula0201c.o" e "aula0202.o".
AULA0202COBJS = aula0201c.o aula0202.o

# Macro correspondente aos codigos-objeto da biblioteca "libmatematica-for.a".
LIBMATEMATICAFOROBJS = aula0201c.o aula0301c.o aula0401c.o

# Macro correspondente a biblioteca "libmatematica-for.a".
LIBMATEMATICAFOR = libmatematica-for.a

# Macro correspondente aos codigos-objeto "aula0201d.o" e "aula0202.o".
AULA0202DOBJS = aula0201d.o aula0202.o

# Macro correspondente aos codigos-objeto da biblioteca "libmatematica-while.a".
LIBMATEMATICAWHILEOBJS = aula0201d.o aula0301d.o aula0401d.o

# Macro correspondente a biblioteca "libmatematica-while.a".
LIBMATEMATICAWHILE = libmatematica-while.a

# Macro correspondente aos codigos-objeto "aula0301a.o" e "aula0302.o".
AULA0302AOBJS = aula0301a.o aula0302.o

# Macro correspondente aos codigos-objeto "aula0301b.o" e "aula0302.o".
AULA0302BOBJS = aula0301b.o aula0302.o

# Macro correspondente aos codigos-objeto "aula0301c.o" e "aula0302.o".
AULA0302COBJS = aula0301c.o aula0302.o

# Macro correspondente aos codigos-objeto "aula0301d.o" e "aula0302.o".
AULA0302DOBJS = aula0301d.o aula0302.o

# Macro correspondente aos codigos-objeto "aula0401a.o" e "aula0402.o".
AULA0402AOBJS = aula0401a.o aula0402.o

# Macro correspondente aos codigos-objeto "aula0401b.o" e "aula0402.o".
AULA0402BOBJS = aula0401b.o aula0402.o

# Macro correspondente aos codigos-objeto "aula0401c.o" e "aula0402.o".
AULA0402COBJS = aula0401c.o aula0402.o

# Macro correspondente aos codigos-objeto "aula0401d.o" e "aula0402.o".
AULA0402DOBJS = aula0401d.o aula0402.o

# Macro correspondente aos codigos-objeto "aula0501.o" e "aula0502.o".
AULA0502OBJS = aula0501.o aula0502.o

# Macro correspondente aos codigos-objeto da biblioteca "libmatematica.a".
LIBMATEMATICAOBJS = aula0501.o

# Macro correspondente a biblioteca "libmatematica.a".
LIBMATEMATICA = libmatematica.a

# Macro correspondente aos codigos-objeto "aula0501.o" e "aula0503.o".
AULA0503OBJS = aula0501.o aula0503.o

# Macro correspondente aos codigos-objeto "aula0501.o" e "aula0504.o".
AULA0504OBJS = aula0501.o aula0504.o

# Macro correspondente aos codigos-objeto "aula0501.o" e "aula0505.o".
AULA0505OBJS = aula0501.o aula0505.o

# Macro correspondente aos codigos-objeto "aula0501.o" e "aula0506.o".
AULA0506OBJS = aula0501.o aula0506.o

# Macro correspondente aos codigos-objeto "aula0501.o" e "aula0507.o".
AULA0507OBJS = aula0501.o aula0507.o

# Macro correspondente aos codigos-objeto "aula0601.o" e "aula0602a.o".
AULA0602AOBJS = aula0601.o aula0602a.o

# Macro correspondente aos codigos-objeto "aula0601.o" e "aula0602b.o".
AULA0602BOBJS = aula0601.o aula0602b.o

# Macro correspondente aos codigos-objeto "aula0601.o" e "aula0603a.o".
AULA0603AOBJS = aula0601.o aula0603a.o

# Macro correspondente aos codigos-objeto "aula0601.o" e "aula0603b.o".
AULA0603BOBJS = aula0601.o aula0603b.o

# Macro correspondente aos codigos-objeto "aula0604.o" e "aula0605a.o".
AULA0605AOBJS = aula0604.o aula0605a.o

# Macro correspondente aos codigos-objeto "aula0604.o" e "aula0605b.o".
AULA0605BOBJS = aula0604.o aula0605b.o

# Macro correspondente aos codigos-objeto "aula0604.o" e "aula0606a.o".
AULA0606AOBJS = aula0604.o aula0606a.o

# Macro correspondente aos codigos-objeto "aula0604.o" e "aula0606b.o".
AULA0606BOBJS = aula0604.o aula0606b.o

# Macro correspondente aos codigos-objeto da biblioteca "libmonitor.a".
LIBMONITOROBJS = aula0701.o

# Macro correspondente a biblioteca "libmonitor.a".
LIBMONITOR = libmonitor.a

# Macro correspondente aos codigos-objeto "aula0701.o" e "aula0702.o".
AULA0702OBJS = aula0701.o aula0702.o

# Macro correspondente aos codigos-objeto "aula0701.o" e "aula0703.o".
AULA0703OBJS = aula0701.o aula0703.o

# Macro correspondente aos codigos-objeto "aula0701.o" e "aula0704.o".
AULA0704OBJS = aula0701.o aula0704.o

# Macro correspondente aos codigos-objeto "aula0701.o" e "aula0705.o".
AULA0705OBJS = aula0701.o aula0705.o

# Macro correspondente aos valores das macros de todas as aulas.
EXECS = $(AULA01) $(AULA02) $(AULA03)\
       	$(AULA04) $(AULA05) $(AULA06)\
	$(AULA07)

# Macro correspondente aos valores das macros de todas as bibliotecas.
LIBS = $(LIBMATEMATICARECURSAO) $(LIBMATEMATICADOWHILE) $(LIBMATEMATICAFOR)\
       $(LIBMATEMATICAWHILE) $(LIBMATEMATICA) $(LIBMONITOR)

# Macro correspondente aos valores das macros "EXECS" e "LIBS".
ALL = $(EXECS) $(LIBS)

# Regra Implicita. Responsavel pela compilacao dos arquivos ".c".
.c.o:
	$(CC) $(CFLAGS) -c $<

# Responsavel pela criacao dos executaveis listados na macro "AULA01", com inclusao das bibliotecas.
all: $(ALL)

# Responsavel por listar as bibliotecas desenvolvidas.
libs: $(LIBS)

# Responsavel pela criacao dos executaveis listados nas macros das aulas, com excecao das bibliotecas.
execs: $(EXECS)

# Responsavel pela criacao dos executaveis listados na macro "AULA01", com excecao das bibliotecas.
aula01: $(AULA01)

# Responsavel pela criacao dos executaveis listados na macro "AULA02", com excecao das bibliotecas.
aula02: $(AULA02)

# Responsavel pela criacao dos executaveis listados na macro "AULA03", com excecao das bibliotecas.
aula03: $(AULA03)

# Responsavel pela criacao dos executaveis listados na macro "AULA04", com excecao das bibliotecas.
aula04: $(AULA04)

# Responsavel pela criacao dos executaveis listados na macro "AULA05", com excecao das bibliotecas.
aula05: $(AULA05)

# Responsavel pela criacao dos executaveis listados na macro "AULA06", com excecao das bibliotecas.
aula06: $(AULA06)

# Responsavel pela criacao dos executaveis listados na macro "AULA07", com excecao das bibliotecas.
aula07: $(AULA07)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0102".
aula0102: $(AULA0102OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0102OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0103".
aula0103: $(AULA0103OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0103OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0104".
aula0104: $(AULA0104OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0104OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0105".
aula0105: $(AULA0105OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0105OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0106".
aula0106: $(AULA0106OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0106OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0107".
aula0107: $(AULA0107OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0107OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0202a".
aula0202a: $(AULA0202AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao da biblioteca referente ao rotulo "libmatematicarecursao.a".
libmatematica-recursao.a: $(LIBMATEMATICARECURSAOOBJS)
	ar -r -c $@ $(LIBMATEMATICARECURSAOOBJS)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0202b".
aula0202b: $(AULA0202BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao da biblioteca referente ao rotulo "libmatematicadowhile.a".
libmatematica-dowhile.a: $(LIBMATEMATICADOWHILEOBJS)
	ar -r -c $@ $(LIBMATEMATICADOWHILEOBJS)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0202c".
aula0202c: $(AULA0202COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao da biblioteca referente ao rotulo "libmatematicafor.a".
libmatematica-for.a: $(LIBMATEMATICAFOROBJS)
	ar -r -c $@ $(LIBMATEMATICAFOROBJS)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0202d".
aula0202d: $(AULA0202DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao da biblioteca referente ao rotulo "libmatematicawhile.a".
libmatematica-while.a: $(LIBMATEMATICAWHILEOBJS)
	ar -r -c $@ $(LIBMATEMATICAWHILEOBJS)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0302a".
aula0302a: $(AULA0302AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0302b".
aula0302b: $(AULA0302BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0302c".
aula0302c: $(AULA0302COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0302d".
aula0302d: $(AULA0302DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0402a".
aula0402a: $(AULA0402AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0402b".
aula0402b: $(AULA0402BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0402c".
aula0402c: $(AULA0402COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0402d".
aula0402d: $(AULA0402DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0502".
aula0502: $(AULA0502OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao da biblioteca referente ao rotulo "libmatematica.a".
libmatematica.a: $(LIBMATEMATICAOBJS)
	ar -r -c $@ $(LIBMATEMATICAOBJS)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0503".
aula0503: $(AULA0503OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0503OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0504".
aula0504: $(AULA0504OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0504OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0505".
aula0505: $(AULA0505OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0505OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0506".
aula0506: $(AULA0506OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0506OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0507".
aula0507: $(AULA0507OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0507OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0602a".
aula0602a: $(AULA0602AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0602AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0602b".
aula0602b: $(AULA0602BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0602BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0603a".
aula0603a: $(AULA0603AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0603AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0603b".
aula0603b: $(AULA0603BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0603BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0605a".
aula0605a: $(AULA0605AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0605AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0605b".
aula0605b: $(AULA0605BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0605BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0606a".
aula0606a: $(AULA0606AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0606AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0606b".
aula0606b: $(AULA0606BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0606BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao da biblioteca referente ao rotulo "libmonitor.a".
libmonitor.a: $(LIBMONITOROBJS)
	ar -r -c $@ $(LIBMONITOROBJS)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0702".
aula0702: $(AULA0702OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0702OBJS) -lm -L. -lmonitor
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0703".
aula0703: $(AULA0703OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0703OBJS) -lm -L. -lmonitor
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0704".
aula0704: $(AULA0704OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0704OBJS) -lm -L. -lmonitor
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel pela criacao dos executaveis referentes ao rotulo "aula0705".
aula0705: $(AULA0705OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0705OBJS) -lm -L. -lmonitor
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# Responsavel por executar os rotulos abaixo, caso algum outro arquivo existente possua o mesmo nome.
.PHONY: clean-all clean clean-objs clean-bsd clean-linux clean-gcc clean-clang clean-ansi clean-c89 clean-90 clean-c99 clean-c11

# Rotulos clean.
clean-all:
	rm -f *.o $(ALL) *-FreeBSD-* *-Linux-* *.core

clean:
	rm -f *.o $(ALL) *.core

clean-objs:
	rm -f *.o *.core

clean-bsd:
	rm -f *.o $(ALL) *-FreeBSD-* *.core

clean-linux:
	rm -f *.o $(ALL) *-Linux-* *.core

clean-gcc:
	rm -f *.o $(ALL) *-gcc-* *.core

clean-clang:
	rm -f *.o $(ALL) *-clang-* *.core

clean-ansi:
	rm -f *.o $(ALL) *-ansi-* *.core

clean-c89:
	rm -f *.o $(ALL) *-c89-* *.core

clean-c90:
	rm -f *.o $(ALL) *-c90-* *.core

clean-c99:
	rm -f *.o $(ALL) *-c99-* *.core

clean-c11:
	rm -f *.o $(ALL) *-c11-* *.core

# $RCSfile: BSDmakefile,v $ 
