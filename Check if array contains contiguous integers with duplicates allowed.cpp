/*
following articles are used to solve the below problem :-
https://www.techiedelight.com/convert-array-set-cpp/   method-2
https://www.techiedelight.com/convert-set-vector-cpp/  method-1
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool areElementsContiguous(int arr[], int n)
  {
    set<int> s(arr, arr + n);
    vector<int> v(s.begin(), s.end());
    for (int i = 1; i < v.size(); i++)
      if (v[i] != v[i - 1] + 1)
        return false;
    return true;
  }
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    if (ob.areElementsContiguous(arr, n))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}