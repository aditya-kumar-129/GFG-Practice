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
  void merge(int arr[], int l, int m, int h)
  {
    int n1 = m - l + 1;
    int n2 = h - m;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
      L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
      M[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
      if (L[i] <= M[j])
        arr[k++] = L[i++];
      else
        arr[k++] = M[j++];
    }
    while (i < n1)
      arr[k++] = L[i++];
    while (j < n2)
      arr[k++] = M[j++];
  }
  void mergeSort(int arr[], int l, int h)
  {
    if (l >= h)
      return;
    int m = l + (h - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, h);
    merge(arr, l, m, h);
  }
};