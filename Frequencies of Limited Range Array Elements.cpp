#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void frequencyCount(vector<int> &arr, int N, int P)
  {
    map<int, int> m;
    for (int i = 0; i < N; i++)
      m[arr[i]]++;
    for (int i = 0; i < N; i++)
    {
      auto it = m.find(i + 1);
      if (it != m.end())
        arr[i] = it->second;
      else
        arr[i] = 0;
    }
  }
};

int main()
{
  long long t;
  cin >> t;
  while (t--)
  {
    int N, P;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
      cin >> arr[i];
    cin >> P;
    Solution ob;
    ob.frequencyCount(arr, N, P);
    for (int i = 0; i < N; i++)
      cout << arr[i] << " ";
    cout << endl;
  }
  return 0;
}