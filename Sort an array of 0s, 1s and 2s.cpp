#include<bits/stdc++.h>
using namespace std;

// Have a look on the below video to understand the logic:-
// https://www.youtube.com/watch?v=oaVa-9wmpns

class Solution
{
public:
  void sort012(int arr[], int n)
  {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
      switch (arr[mid])
      {
      case 0:
        // we have kept the zero at low, so now we can increment low, and we have kept the one at mid, so we can increment that too
        swap(arr[low++], arr[mid++]);
        break;
      case 1:
        // we can increment the mid as its already 1
        mid++;
        break;
      case 2:
        // we wont increment mid here, as there could be chances that mid is not 1, so we would be needing to reconsider mid
        swap(arr[mid], arr[high--]);
        break;
      }
    }
  }
};

int main() 
{
  int t;
  cin >> t;
  while (t--) 
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++) 
      cin >> a[i];
    Solution ob;
    ob.sort012(a, n);
    for (int i = 0;i < n;i++) 
      cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}