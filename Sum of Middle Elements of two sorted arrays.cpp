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

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, i;
    cin >> n;
    int ar1[n], ar2[n];
    for (i = 0; i < n; i++)
      cin >> ar1[i];
    for (i = 0; i < n; i++)
      cin >> ar2[i];
    Solution ob;
    auto ans = ob.findMidSum(ar1, ar2, n);
    cout << ans << "\n";
  }
  return 0;
}

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