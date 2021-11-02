#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findUnion(int arr1[], int arr2[], int n, int m)
  {
    set<int> s;
    for (int i = 0; i < n; i++)
      s.insert(arr1[i]);
    for (int i = 0; i < m; i++)
      s.insert(arr2[i]);
    vector<int> v;
    for (auto it : s)
      v.push_back(it);
    return v;
  }
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, M;
    cin >> N >> M;
    int arr1[N];
    int arr2[M];
    for (int i = 0; i < N; i++)
      cin >> arr1[i];
    for (int i = 0; i < M; i++)
      cin >> arr2[i];
    Solution ob;
    vector<int> ans = ob.findUnion(arr1, arr2, N, M);
    for (int i : ans)
      cout << i << ' ';
    cout << endl;
  }
  return 0;
}