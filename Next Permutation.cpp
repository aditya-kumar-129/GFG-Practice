#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextPermutation(int N, vector<int> arr)
  {
    int i, index1 = -1, index2 = -1;
    for (i = 0; i < N - 1; i++)
    {
      if (arr[i] < arr[i + 1])
      {
        index1 = i;
        index2 = i + 1;
      }
    }
    if (index1 == -1)
      reverse(arr.begin(), arr.end());
    else
    {
      int mx = arr[index1], smallest = index2;
      for (i = index2; i < N; i++)
        if (arr[i] > mx && arr[i] < arr[smallest])
          smallest = i;
      swap(arr[smallest], arr[index1]);
      sort(arr.begin() + index2, arr.end());
    }
    return arr;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
      cin >> arr[i];
    Solution ob;
    vector<int> ans = ob.nextPermutation(N, arr);
    for (int u : ans)
      cout << u << " ";
    cout << "\n";
  }
  return 0;
}