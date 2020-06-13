#include "pch.h"
#include <iostream>
#include <vector>
#include "NQueen.h"
using namespace std;

void printStar(int nQueen) {
	for (int i = 0; i < nQueen * 7; i++) { printf("*"); }
	printf("\n");
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Arg : size of board number of queens");
		return -1;
	}

	int nSize  = atoi(argv[1]);
	int nQueen = atoi(argv[2]);

	if (nSize < 1 || nQueen < 0)
	{
		printf("invalid input!\n");
		return -1;
	}

	vector<vector<bool>> matrix;
	matrix.resize(nSize);
	for (int i = 0; i < nSize; i++) matrix[i].resize(nSize, false);

	if (do_nQueen(matrix, nQueen, 0))
	{
		printStar(nQueen);
		for (int i = 0; i < nSize; i++)
		{
			for (int j = 0; j < nSize; j++)
			{
				if (matrix[i][j]) { printf("Q\t"); }
				else              { printf(".\t"); }
			} printf("\n");
		}

		printStar(nQueen);
	}
	else { printf("no solution!\n"); }
	return 0;
} 