// Mudit - https://github.com/MuditJain5

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 14, 15, 3, 6, 10 };
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	printArray(arr, N);

	return 0;
}
