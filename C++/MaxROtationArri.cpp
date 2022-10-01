#include <bits/stdc++.h>
#include <climits>
#include <String>
using namespace std;

int main()
{
    int x, maxsum = 0, n;
    cout << "Enter the size of array" << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (n--)
    {

        int x = arr[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = x;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i] * i;
        }
        maxsum = max(maxsum, sum);
    }
    cout << "Max Sum is : " << maxsum;

    return 0;
}