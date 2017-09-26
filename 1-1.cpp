#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
	srand((int)time(0));
	int size = 200;
	int **Arr = new int*[size];

	int *Arr2 = new int[size * size];
	int Arr2Count = 0;

	for (int i = 0; i < size; i++) {
		Arr[i] = new int[size];
		for (int j = 0; j < size; j++) {
			Arr[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << Arr[i][j] << " ";
		}
		std::cout << endl;
	}
	for (int i = size - 1; i >= 0; i--) { //a
		int k = 0;
		for (int j = size - i; j > 0; j--) {
			Arr2[Arr2Count] = Arr[k][i + k];
			Arr2Count++;
			k++;
		}
	}
	for (int i = 1; i < size; i++) {
		int k = i;
		for (int j = 0; j < size - i; j++) {
			//cout << k << " " << j << " " << Arr2Count << endl;
			Arr2[Arr2Count] = Arr[k][j];
			Arr2Count++;
			k++;
		}
	}

	cout << "a)";
	for (int i = 0; i < size * size; i++) {
		cout << Arr2[i] << " ";
	}
	cout << endl;
	Arr2Count = 0;

	for (int i = 0; i < size; i++) { //b
		int k = i;
		for (int j = 0; j <= i; j++) {
			Arr2[Arr2Count] = Arr[k][j];
			Arr2Count++;
			k--;
		}
	}
	for (int i = 1; i < size; i++) {
		int k = size - 1;
		for (int j = i; j < size; j++) {
			Arr2[Arr2Count] = Arr[k][j];
			Arr2Count++;
			k--;
		}
	}
	
	cout << "b)";
	for (int i = 0; i < size * size; i++) {
		cout << Arr2[i] << " ";
	}
	cout << endl;
	Arr2Count = 0;

	for (int i = (size - 1) / 2; i >= 0; i--) { //c
		if (size % 2 == 1 && i == (size - 1) / 2) {
			Arr2[Arr2Count] = Arr[i][i];
			Arr2Count++;
		}
		else {
			for (int j = i + 1; j < size - i; j++) {
				Arr2[Arr2Count] = Arr[j][i];
				Arr2Count++;
			}
			for (int j = i + 1; j < size - i; j++) {
				Arr2[Arr2Count] = Arr[size - i - 1][j];
				Arr2Count++;
			}
			for (int j = size - i - 2; j >= i ; j--) {
				Arr2[Arr2Count] = Arr[j][size - i - 1];
				Arr2Count++;
			}
			for (int j = size - i - 2; j >= i;  j--) {
				Arr2[Arr2Count] = Arr[i][j];
				Arr2Count++;
			}
		}
	}

	cout << "c)";
	for (int i = 0; i < size * size; i++) {
		cout << Arr2[i] << " ";
	}
	cout << endl;
	Arr2Count = 0;

	for (int i = 0; i <= (size - 1) / 2; i++) { //d
		if (size % 2 == 1 && i == (size - 1) / 2) {
			Arr2[Arr2Count] = Arr[i][i];
			Arr2Count++;
		}
		else {
			for (int j = i; j < size - i; j++) {
				Arr2[Arr2Count] = Arr[i][j];
				Arr2Count++;
			}
			for (int j = i + 1; j < size - i; j++) {
				Arr2[Arr2Count] = Arr[j][size - i - 1];
				Arr2Count++;
			}
			for (int j = size - i - 2; j >= i; j--) {
				Arr2[Arr2Count] = Arr[size - i - 1][j];
				Arr2Count++;
			}
			for (int j = size - i - 2; j > i; j--) {
				Arr2[Arr2Count] = Arr[j][i];
				Arr2Count++;
			}
		}
	}

	cout << "d)";
	for (int i = 0; i < size * size; i++) {
		cout << Arr2[i] << " ";
	}
	cout << endl;
	Arr2Count = 0;
	system("pause");
	return 0;
}