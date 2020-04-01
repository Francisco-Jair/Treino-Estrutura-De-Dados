#include "ListaDinamica.h"

int main()
{
	t_Book library;
	int esc;

	for(;;)
	{
		printf("1 - Adicionar Livro\n");
		printf("2 - Remover Livro \n");
		printf("3 - Mostrar Lista\n");
		printf("4 - Pesquisar Livro\n");
		printf("5 - Quantidade de elemento\n");
		printf("0 - Sair \n\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &esc);

		system("cls");

		if(esc == 1)
		{
			// addElementList(library, &aux);
		}
		else if(esc == 2)
		{
			// removerElement(&aux);
		}
		else if(esc == 3)
		{
			// showAllElementList(library, aux);
		}
		else if(esc == 4)
		{
			//serachElementtoList(library, aux);
		}
		else if(esc == 5)
		{
			// printf("A lista tem %d elementos\n", aux + 1);
		}
		else if(esc == 0)
		{
			exit(0);
		}

		system("PAUSE");
		system("cls");
	}


	return 0;
}
