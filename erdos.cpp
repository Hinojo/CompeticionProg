/*
 * Solución al problema de los números de Erdös.
 * Implementación con arrays.
 */

#include <cstdio>
#include <iostream>
#include <climits>
#include <cassert>
#include <string>
#include <map>

using namespace std;

const string nombre_de_erdos = "Erdos, P.";
const int infinito = INT_MAX - 10;

#define N_P 50000
#define N_A 8000
#define N_A_x_P 130

int articulos[N_P][N_A_x_P];
int contador_erdos[N_A];

char nombre_autor[2048];

int main(int argc, char *argv[])
{
	int num_casos, N, P, ch;

	map<string, int> autores;

	scanf("%d", &num_casos);

	cout << "Numero de casos: " << num_casos << endl;

	for (int caso = 0; caso < num_casos; caso++)
	{

		scanf("%d%d", &P, &N);
		while ((ch = getchar()) != EOF && ch != '\n')
			;

		assert(P <= N_P);

		autores.clear();

		autores[nombre_de_erdos] = 0;
		contador_erdos[0] = 0;
		int num_autores = 1;

		for (int p = 0; p < P; p++)
		{

			articulos[p][0] = 0;
			int num_comas = 0, i = 0, nap = 1;

			bool fin_articulo = false;

			while (!fin_articulo)
			{

				ch = getchar();

				switch (ch)
				{

				case ':':
					while ((ch = getchar()) != EOF && ch != '\n')
						;
					fin_articulo = true;
					num_comas = 1;

				case ',':
					if (num_comas == 1)
					{
						nombre_autor[i] = '\0';
						num_comas = 0;
						i = 0;

						if (autores.count(nombre_autor) == 0)
							autores[nombre_autor] = num_autores++;

						articulos[p][nap++] = autores[nombre_autor];
					}
					else
					{
						nombre_autor[i++] = ch;
						num_comas++;
					}
					break;

				case ' ':
					if (i > 0)
						nombre_autor[i++] = ch;
					break;

				case '\r':
					break;
				case '\n':
					break;

				default:
					nombre_autor[i++] = ch;
				}
			}
			articulos[p][0] = nap - 1;
			assert(articulos[p][0] <= N_A_x_P);
		}

		assert(num_autores <= N_A);

		cout << "mapa autores\n";
		for (map<string, int>::const_iterator it = autores.begin(); it != autores.end(); ++it)
		{
			cout <<  it->first << endl;
		}
		// AQUÍ DEBE EL ALGORITMO QUE CALCULA LA SOLUCIÓN

		printf("Scenario %d\n", caso + 1);

	// 	for (int n = 0; n < N; n++)
	// 	{

	// 		int i = 0;
	// 		while ((ch = getchar()) != EOF && ch != '\n')
	// 			if (ch != '\r')
	// 				nombre_autor[i++] = ch;

	// 		nombre_autor[i] = '\0';

	// 		if (autores.count(nombre_autor) == 0)
	// 		{
	// 			printf("%s infinity\n", nombre_autor);
	// 		}
	// 		else
	// 		{
	// 			int valor = contador_erdos[autores[nombre_autor]];
	// 			if (valor == infinito)
	// 			{
	// 				printf("%s infinity\n", nombre_autor);
	// 			}
	// 			else
	// 			{
	// 				printf("%s %d\n", nombre_autor, valor);
	// 			}
	// 		}
	// 	}
	 }

	return 0;
}