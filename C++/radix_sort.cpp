#include <iostream>
using namespace std;

void countSort(int arr[], int n, int place){
	int range = 10;
    int i;
	int freq[range] = {0};
    int output[n];
    for(i=0; i<n; i++)
        freq[(arr[i]/place)%range]++;
	for(i=1; i<range; i++)
        freq[i] += freq[i-1];
    for(i=n-1; i>=0; i--){
        output[freq[(arr[i]/place)%range]-1]=arr[i];
        freq[(arr[i]/place)%range]--;
    }
    for(i=0; i<n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n, int maxx){
    int mul=1;
    while(maxx){
        countSort(arr, n ,mul);
        mul *= 10;
        maxx /= 10;
    }
}

int getMax(int arr[], int n){ 
    int max = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
}

int main(){
	int n;
	int *arr;
	cout << "Enter number of elements: ";
	cin >> n;
	arr = new int[n];
	cout << "Enter elements: ";
	for(int i=0; i<n; i++)
		cin >> arr[i];
	radixSort(arr, n, getMax(arr, n));
	cout << "Radix Sorted array is: ";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
		
	return 0;
}
