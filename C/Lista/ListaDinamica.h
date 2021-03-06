#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


typedef struct
{
	char nameBook[MAX];
	char nameAuthor[MAX];
	int year;
	int id;
} t_Book;

typedef struct data
{
	t_Book livros;
	struct data *prox;
} t_Date;

typedef struct
{
	t_Date *inicio;
	t_Date *fin;
} t_Library;


void iniciar(t_Library *library)
{
	library->inicio = NULL;
	library->fin = NULL;
}

int quantidadeDeElementos(t_Library *library)
{
	int value = 0;
	t_Date *aux = library->inicio;


	while(aux != NULL)
	{
		value++;
		aux = aux->prox;
	}

	return value;
}

void AddList(t_Library *library, t_Book book)
{
	t_Date *auxEnd = library->fin;
	t_Date *newElemnt;

	newElemnt = (t_Date*)malloc(sizeof(t_Date));
	newElemnt->livros = book;


	if(library->inicio == NULL)
	{
		library->inicio = newElemnt;
		newElemnt->prox = NULL;
		library->fin = newElemnt;
	}
	else
	{
		auxEnd->prox = newElemnt;
		library->fin = newElemnt;
		newElemnt->prox = NULL;
	}
}

void createBook(t_Library *library)
{
	t_Book book_aux;

	setbuf(stdin, NULL);
	printf("Qual o nome do livro ?\n");
	scanf("%[^\n]s", book_aux.nameBook);
	setbuf(stdin, NULL);
	printf("Qual o nome do autor do livro ?\n");
	scanf("%[^\n]s", book_aux.nameAuthor);
	printf("Qual o ano de Lancamento ?\n");
	scanf("%d", &book_aux.year);

	book_aux.id = quantidadeDeElementos(library) + 1;

	AddList(library, book_aux);
}

void showList(t_Library *library)
{
	t_Date *aux = library->inicio;

	if(quantidadeDeElementos(library) == 0)
	{
		printf("Lista Vazia...\n");
		return;
	}

	while(aux != NULL)
	{
		printf("ID: %d\n", aux->livros.id);
		printf("Nome do Livro: %s\n", aux->livros.nameBook);
		printf("Nome do Autor: %s\n", aux->livros.nameAuthor);
		printf("Ano de Lacamento: %d\n", aux->livros.year);
		printf("\n");

		aux = aux->prox;
	}
}

void searchList(t_Library *library)
{
	t_Date *aux = library->inicio;
	int sear, cont = 0;

	if(quantidadeDeElementos(library) == 0)
	{
		printf("Lista Vazia...\n");
		return;
	}

	printf("A partir de qual ano deseja pesquisar os livros ?\n");
	scanf("%d", &sear);

	while(aux != NULL)
	{
		if(aux->livros.year >= sear)
		{
			printf("ID: %d\n", aux->livros.id);
			printf("Nome do Livro: %s\n", aux->livros.nameBook);
			printf("Nome do Autor: %s\n", aux->livros.nameAuthor);
			printf("Ano de Lacamento: %d\n", aux->livros.year);
			printf("\n");
			cont++;
		}

		aux = aux->prox;
	}

	if(cont == 0)
	{
		printf("Nenhum Livro encontrado.....\n");
	}
}

void removerElementList(t_Library *library)
{
	t_Date *eliminar = library->inicio;
	t_Date *ant = NULL;
	char searc_book[MAX];

	if(quantidadeDeElementos(library) == 0)
	{
		printf("Lista Vazia...\n");
		return;
	}


	setbuf(stdin, NULL);
	printf("Entre com o nome do livro que deseja excluir ?\n");
	scanf("%[^\n]s", searc_book);



	while(eliminar != NULL)
	{
		if(!strcmp(eliminar->livros.nameBook, searc_book))
		{
			//Se for o primeiro elemento
			if(eliminar == library->inicio)
			{
				//Ele e unico elemento
				if(quantidadeDeElementos(library) == 1)
				{
					library->inicio = NULL;
					library->fin = NULL;
				}
				else
				{
					//Tem mais do que 1 elemento
					library->inicio = eliminar->prox;
					free(eliminar);
				}
				return;
			}

			//Se for o ultimo elemento
			if(eliminar == library->fin)
			{
				library->fin = ant;
				ant->prox = NULL;
				free(eliminar);

				return;
			}

			ant->prox = eliminar->prox;
			free(eliminar);

			return;
		}

		ant = eliminar;
		eliminar = eliminar->prox;
	}
}
