//Name: Tamilselvi, Github id: tamilselvi53
import java.util.*;
public class Main
{
    //T(n): O(n logn)
    //S(n): O(n)
    public static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    public static void merge(int[] arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int[] a = new int[n1];
        int[] b = new int[n2];
        //Copying first half
        for (int i = 0; i < n1; i++) {
            a[i] = arr[l + i];
        }
        //Copying 2nd half
        for (int j = 0; j < n2; j++) {
            b[j] = arr[m + 1 + j];
        }
        int i = 0, j = 0, k = 0;
        //Sorting using 2 pointers
        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                arr[k++] = a[i++]; 
            } else {
                arr[k++] = b[j++];
            }
        }
        while (i < n1) {
            arr[k++] = a[i++];
        }
        while (j < n2) {
            arr[k++] = a[j++];
        }
    }
    public static int[] merge2(int[] arr, int l, int m, int r) {
        //GAP method --> O(1)
        //T(n): O(nlogn)
        int len = r - l + 1; //8/2, 4/2, 2/2
        while (len >= 1) {
            int i = l, j = l + len;
            while (i <= r && j <= r) {
                if (arr[i] > arr[j]) {
                    swap(arr, i, j);
                }
                i++;
                j++;
            }
            len /= 2;
        }
        return arr;
    }
    public static void mergeSort(int[] arr, int l, int r) {
        if (l < r) {
            int mid = (l + r) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge2(arr, l, mid, r);
        }
        
    }
    
    //Stable sorting
    //Not inplace sorting - using extra space
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arr = {11, 6, 2, 9, 3};
		mergeSort(arr, 0, arr.length - 1);
		for (int i: arr) {
		    System.out.println(i);
		}
	}
}
