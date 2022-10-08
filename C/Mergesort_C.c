#include<stdio.h>

void mergeSort(int[],int,int); 
void merge(int[],int,int,int);

void display(int arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void main() 
{
    int a[10]= {11, 9, 6, 19, 33, 64, 15, 75, 67, 88}; 
    int i; 

    int size = sizeof(a)/sizeof(a[0]);
	printf("Input: ");
    display(a, size);

    mergeSort(a, 0, size-1);
	printf("Output: ");
    display(a, size);
}

void mergeSort(int a[], int left, int right)
{
    int mid;
    if(left < right)
    {
        // can also use mid = left + (right - left) / 2
        // this can avoid data type overflow
        mid = (left + right)/2;
        
        // recursive calls to sort first half and second half subarrays
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void merge(int a[], int left, int mid, int right)
{
    int i = left, j = mid + 1, p, index = left;
    int temp[10];

    while(i<=mid && j<=right)
    {
        if(a[i]<a[j]) { temp[index] = a[i]; i = i+1; } else { temp[index] = a[j]; j = j+1; } index++; } if(i>mid)
    {
        while(j<=right)
        {
            temp[index] = a[j];
            index++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index] = a[i];
            index++;
            i++;
        }
    }
    p = left;
    while(p<index)
    {
        a[p]=temp[p];
        p++;
    }
}
