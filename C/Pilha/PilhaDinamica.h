#include <stdio.h>
#include <stdlib.h>
#define MAX 50


/* Uma pilha que guarda dados de uma biblioteca */

typedef struct
{
	char nameBook[MAX];
	char nameAuthor[MAX];
	int numberStock;
	int id_book;
	int yearLaunch;
} t_Livro;

typedef struct date
{
	t_Livro book;
	struct date *prox;
} t_Date;

typedef struct
{
	t_Date *begin;
} t_Library;

void addElementStack(t_Library )