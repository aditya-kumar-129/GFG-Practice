#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool check_elements(int arr[], int n, int A, int B)
  {
    sort(arr, arr + n);
    for (int i = A; i <= B; i++)
      if (!binary_search(arr, arr + n, i))
        return false;
    return true;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, A, B;
    cin >> n >> A >> B;
    int a[n];
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    Solution ob;
    if (ob.check_elements(a, n, A, B))
      cout << "Yes";
    else
      cout << "No";
    cout << "\n";
  }
  return 0;
}

// Method 2:-

bool check_elements(int arr[], int n, int A, int B)
{
  map<int, int> mp;
  for (int i = 0; i < n; i++)
    if (arr[i] >= A && arr[i] <= B)
      mp[arr[i]]++;
  int count = mp.size();
  if (count == (B - A + 1))
    return true;
  return false;
}

// method 3 :- 
// OPTIMUM SOLUTION Time Complexity :- O(n)
bool check_elements(int arr[], int n, int A, int B)
{
  for (int i = 0; i < n; i++)
  {
    if ((abs(arr[i])) >= A && (abs(arr[i])) <= B)
    {
      int z = abs(arr[i]) - A;
      if (z < n && arr[z] > 0)
        arr[z] = arr[z] * -1;
    }
  }
  int range = B - A;
  int count = 0;
  for (int i = 0; i <= range; i++)
  {
    if (arr[i] > 0)
      return false;
    else
      count++;
  }
  if (count != range + 1)
    return false;
  else
    return true;
}