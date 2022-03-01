#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void rearrange(int arr[], int n)
  {
    vector<int> neg, pos;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] < 0)
        neg.push_back(arr[i]);
      else
        pos.push_back(arr[i]);
    }
    int i = 0, j = 0, k = 0;
    while (i < neg.size() && j < pos.size())
    {
      arr[k++] = pos[j++];
      arr[k++] = neg[i++];
    }
    // Number of positive and negative numbers need not be equal. 
    // If there are more positive numbers they appear at the end of the array. 
    // If there are more negative numbers, they too appear in the end of the array.
    while (j < pos.size())
      arr[k++] = pos[j++];
    while (i < neg.size())
      arr[k++] = neg[i++];
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
    int arr[n];
    for (i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    ob.rearrange(arr, n);
    for (i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << "\n";
  }
  return 0;
}