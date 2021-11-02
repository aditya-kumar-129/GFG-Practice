#include <bits/stdc++.h>
using namespace std;
// How to get the maximum element in the unordered set is important otherwise all are easy

class Solution
{
public:
  int missingNumber(int arr[], int n)
  {
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
      s.insert(arr[i]);
    int a = *max_element(s.begin(), s.end());
    for (int i = 1; i <= a; i++)
      if (s.find(i) == s.end())
        return i;
    return a + 1;
  }
  /*
  int missingNumber(int arr[], int n) 
    { 
      int max=1;
      sort(arr,arr+n);
      for(int i=0;i<n;i++)
      {
        if(arr[i]==max)
            max++;
        else if(arr[i]>max)
            return max;
        }
      return max;
    }
  */
};

int missingNumber(int arr[], int n);
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    cout << ob.missingNumber(arr, n) << endl;
  }
  return 0;
}