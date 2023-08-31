// Have a look at the below Youtube video:-
#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n) {
  int i = 0, j = n - 1;
  while (i < j) {
    while (i <= n - 1 and arr[i] > 0) i++;
    while (j >= 0 and arr[j] < 0) j--;
    if (i < j) swap(arr[i], arr[j]);
  }
  if (i == 0 || i == n) return;
  int k = 0;
  while (k < n && i < n) {
    swap(arr[k], arr[i]);
    i = i + 1;
    k = k + 2;
  }
}