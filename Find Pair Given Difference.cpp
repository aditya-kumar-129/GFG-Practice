#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{
  unordered_set<int> s;
  for (int i = 0; i < size; i++)
    s.insert(arr[i]);
  for (int i = 0; i < size; i++)
    if (s.find(arr[i] + n) != s.end())
      return true;
  return false;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int l, n;
    cin >> l >> n;
    int arr[l];
    for (int i = 0; i < l; i++)
      cin >> arr[i];
    if (findPair(arr, l, n))
      cout << 1 << endl;
    else
      cout << "-1" << endl;
  }

  return 0;
}

// Method 2.) It's space complexity will be O(1).

// bool findPair(int arr[], int size, int n)
// {
//   sort(arr, arr + size);
//   int i = 0, j = 1;
//   while (i < size && j < size)
//   {
//     if (arr[j] - arr[i] == n)
//       return true;
//     else if (arr[j] - arr[i] < n)
//       j++;
//     else
//       i++;
//   }
//   return false;
// }

//Method 3 :- This method also takes a space complexity of O(1) but uses INBUILT binary search Function to find whether the sum is present or not
// The below article will help in learning about INBUILT binary search Function
// https://www.geeksforgeeks.org/binary-search-algorithms-the-c-standard-template-library-stl/

// bool findPair(int arr[], int size, int n)
// {
//   sort(arr, arr + size);
//   for (int i = 0; i < size - 1; i++)
//     if (binary_search(arr, arr + size, (arr[i] + n)))
//       return true;
//   return false;
// }

