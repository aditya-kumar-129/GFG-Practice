#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMidSum(int arr1[], int arr2[], int n)
  {
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
      v.push_back(arr1[i]);
      v.push_back(arr2[i]);
    }
    sort(v.begin(), v.end());
    int sum = v[n - 1] + v[n];
    return sum;
  }
};

// Method 2 :- Using Inbuilt function to merge to array
/*
Have a llok on the below article about the merge() present in STL of c++
https://www.geeksforgeeks.org/merge-in-cpp-stl/
*/
int findMidSum(int ar1[], int ar2[], int n)
{
  int m = n + n;
  int c[m];
  merge(ar1, ar1 + n, ar2, ar2 + n, c);
  int s = c[n] + c[n - 1];
  return s;
}