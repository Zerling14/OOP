#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	srand((int)time(0));

	int size = 10;
	int **Arr = new int*[size];

	int *Arr2 = new int[size];
	int Arr2Count = 0;

	for (int i = 0; i < size; i++) {
		int NumRaw = rand() % 10;
		Arr[i] = new int[NumRaw];
		Arr2[i] = NumRaw;
		for (int j = 0; j < NumRaw; j++) {
			Arr[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < Arr2[i]; j++) {
			cout << Arr[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}