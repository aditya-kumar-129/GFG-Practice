#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void frequencyCount(vector<int> &input, int n, int P)
  {
    for (int i = 0; i < n; i++)
      input[i]--;
    for (int i = 0; i < n; i++)
      input[input[i] % n] += n;
    for (int i = 0; i < n; i++)
    {
      if (input[i] / n)
        cout << "Element " << (i + 1) << " occurs " << input[i] / n << " times" << endl;
      // Changing the element back to original value
      input[i] = input[i] % n + 1;
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

// BRUTE FORCE APPROACH
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