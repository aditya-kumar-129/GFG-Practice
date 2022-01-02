#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // OPTIMUM SOLUTION
  // Time Complexity:- O(log(n))
  // Have a look on the below Youtube video :- 
  // https://www.youtube.com/watch?v=4WmTRFZilj8
  int findKRotation(int arr[], int n)
  {
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
      int mid = start + (end - start) / 2;
      if ((arr[mid] < arr[(mid + n - 1) % n]) && (arr[mid] < arr[(mid + 1) % n]))
        return mid;
      else if (arr[mid] < arr[end])
        end = mid - 1;
      else
        start = mid + 1;
    }
    return start;
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
    int a[n];
    for (i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    auto ans = ob.findKRotation(a, n);
    cout << ans << "\n";
  }
  return 0;
}

// Method 2 :- 
// BRUTE FORCE APPROACH
// here min_element return a pointer to the index where the minimum elemen is present 
// and arr point to the start pointer and when the both are subtracted then we get the answer 
int findKRotation(int arr[], int n)
{
  int c = min_element(arr, arr + n) - arr;
  return c;
}

// BRUTE FORCE APPROACH
// Time Complexity :- O(n)
int findKRotation(int arr[], int n)
{
  int count = 0;
  int x = *min_element(arr, arr + n);
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > x)
      count++;
    else
      break;
  }
  return count;
}