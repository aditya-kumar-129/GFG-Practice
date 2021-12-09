#include <bits/stdc++.h>
using namespace std;

//upper_bound() is a standard library function in C++ which returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found.
// https://www.geeksforgeeks.org/upper_bound-in-cpp/

vector<long long> find(vector<long long> a, vector<long long> b, vector<long long> q)
{
  vector<long long> ans;
  sort(b.begin(), b.end());
  for (auto it : q)
  {
    long long ind = it;
    long long n = a[ind];
    long long k = upper_bound(b.begin(), b.end(), n) - b.begin();
    ans.push_back(k);
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<long long> a, b, ans;
    int input;
    for (int i = 0; i < n; i++)
    {
      cin >> input;
      a.push_back(input);
    }
    for (int i = 0; i < n; i++)
    {
      cin >> input;
      b.push_back(input);
    }
    int qsz;
    cin >> qsz;
    vector<long long> q;
    for (int i = 0; i < qsz; i++)
    {
      cin >> input;
      q.push_back(input);
    }
    ans = find(a, b, q);
    for (int i = 0; i < qsz; i++)
      cout << ans[i] << endl;
  }
  return 0;
}