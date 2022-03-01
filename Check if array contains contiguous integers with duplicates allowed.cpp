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

// Method :- 2

bool areElementsContiguous(int a[], int n)
{
  set<int> s;
  int mn = 987654, mx = -987654;
  for (int i = 0; i < n; i++)
  {
    s.insert(a[i]);
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  for (int i = mn; i <= mx; i++)
    if (s.find(i) == s.end())
      return 0;
  return 1;
}

// Method 3 :-

bool areElementsContiguous(int arr[], int n)
{
  set<int> st;
  set<int> s(arr, arr + n);
  int start = *(st.begin()), end = *(--st.end()), size = st.size();
  if (end - start + 1 == size)
    return true;
  else
    return false;
}

// Method :- 4
// Have a look on the below article for understanding the below method:-
// https://www.geeksforgeeks.org/stdnext-in-cpp/

bool areElementsContiguous(int arr[], int n)
{
  set<int> s;
  set<int> s(arr, arr + n);
  int prev = *(s.begin());
  auto it = next(s.begin(), 1);
  while (it != s.end())
  {
    int diff = *it - prev;
    prev = *it;
    it++;
    if (diff != 1)
      return false;
  }
  return true;
}