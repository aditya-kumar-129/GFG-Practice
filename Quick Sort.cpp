#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

class Solution
{
public:
  //Function to sort an array using quick sort algorithm.
  void quickSort(int arr[], int low, int high)
  {
    if (low < high)
    {
      int pi = partition(arr, low, high);
      quickSort(arr, low, pi);
      quickSort(arr, pi + 1, high);
    }
  }

public:
  int partition(int arr[], int low, int high)
  {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (1)
    {
      //Find leftmost element greater than or equal to pivot
      do
      {
        i++;
      } while (arr[i] < pivot);
      //Find leftmost element greater than or equal to pivot
      do
      {
        j--;
      } while (arr[j] > pivot);
      // If two pointers met.
      if (i >= j)
        return j;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
};
int main()
{
  int arr[1000], n, T, i;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%d", &arr[i]);
    Solution ob;
    ob.quickSort(arr, 0, n - 1);
    printArray(arr, n);
  }
  return 0;
}