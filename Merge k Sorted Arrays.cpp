#include <bits/stdc++.h>
#define N 105
using namespace std;

void printArray(vector<int> arr, int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
}

class Solution
{
public:
  // BRUTE FORCE APPROACH
  // Complexity Analysis :
  // Time Complexity : O(n *k *log(n *k)).since resulting array is of N *k size.
  // Space Complexity : O(n *k), The output array is of size n *k.
  vector<int> mergeKArrays(vector<vector<int>> arr, int K)
  {
    vector<int> v;
    for (int i = 0; i < K; i++)
      for (int j = 0; j < K; j++)
        v.push_back(arr[i][j]);
    sort(v.begin(), v.end());
    return v;
  }
};