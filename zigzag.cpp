#include <iostream>
#include <fstream>

using namespace std;

#define MIN_N 2
#define MAX_N 1000

int main()
{
	int N, i, v[MAX_N];

	ifstream fin("ZigZag.in");

	if (fin.is_open())
	{
		fin >> N;

		if (N < MIN_N || N > MAX_N)
		{
			cout << "Eroare valoare N\n";
			return 2;
		}

		for (i = 0; i < N; i++)
		{
			fin >> v[i];
		}

		fin.close();
	}
	else
	{
		cout << "Nu am putut deschide fisierul ZigZag.in\n";
		return 1;
	}

	int j, aux;

	for (i = 0; i < N-1; i++)
	{
		for (j = i+1; j < N; j++)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}

	ofstream fout("ZigZag.out");

	for (i = 0, j = N-1; i < j; i++, j--)
	{
		fout << v[i] << ' ' << v[j] << ' ';
	}

	if (i == j)
	{
		fout << v[i];
	}
	
	fout << '\n';

	fout.close();
	
	return 0;
}
