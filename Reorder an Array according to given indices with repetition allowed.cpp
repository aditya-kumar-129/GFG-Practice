#include <bits/stdc++.h>
using namespace std;

void reorder(vector<int> &arr, vector<int> &index)
{
  vector<int> ans;
  int n = arr.size();
  for (int i = 0; i < n; i++)
    ans.insert(ans.begin() + index[i], arr[i]);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
}

int main()
{
  vector<int> arr = {0, 1, 2, 3, 4};
  vector<int> index = {0, 1, 2, 2, 1};
  reorder(arr, index);
  return 0;
}
