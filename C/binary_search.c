#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[20], n, key, l, h, mid;
    printf("Enter the value for n: ");
    scanf("%d", &n);
    printf("Enter %d elements in ascending order: ", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the key element to search: ");
    scanf("%d", &key);
    l = 0;
    h = n - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (a[mid] == key)
        {
            printf("The key is found at %d position", mid + 1);
        }
        if (key > a[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
}