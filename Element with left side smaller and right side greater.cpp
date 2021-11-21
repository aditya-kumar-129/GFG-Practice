#include <bits/stdc++.h>
using namespace std;

int findElement(int a[], int n)
{
  int mini[n], maxi[n];
  mini[0] = a[0];
  maxi[n - 1] = a[n - 1];
  int ele = -1, big = a[0], small = a[n - 1];
  for (int i = 1; i < n; i++)
    mini[i] = max(mini[i - 1], a[i]);
  for (int i = n - 2; i >= 0; i--)
    maxi[i] = min(maxi[i + 1], a[i]);

  for (int i = 0; i < n; i++)
    if (i != 0 && i != n - 1 && mini[i] == maxi[i])
      return mini[i];
  return -1;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
      cin >> a[i];
    cout << findElement(a, n) << endl;
  }
  return 0;
}

// Need to understand the logic of below code:-

// int findElement(int arr[], int n)
// {
//   int min = arr[n - 1], max = arr[0], i;
//   unordered_map<int, bool> map;
//   for (i = n - 2; i > 0; i--)
//   {
//     if (arr[i] <= min)
//     {
//       map[i] = true;
//       min = arr[i];
//     }
//   }
//   for (i = 1; i < n - 1; i++)
//   {
//     if (arr[i] >= max)
//     {
//       if (map.count(i) > 0)
//         return arr[i];
//       max = arr[i];
//     }
//   }
//   return -1;
// }

// Also the optimisation method so as to reduce the space complexity of the problem below is the article to get about it (NOT ABLE TO GET THE OPTIMISATION PART)
// https://www.geeksforgeeks.org/find-the-element-before-which-all-the-elements-are-smaller-than-it-and-after-which-all-are-greater-than-it/
