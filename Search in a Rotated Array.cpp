#include <bits/stdc++.h>
using namespace std;
// https://stackoverflow.com/questions/4773807/searching-in-a-sorted-and-rotated-array
// https://www.youtube.com/watch?v=Le8bc8aHgBA

class Solution
{
public:
  int search(int A[], int l, int h, int key)
  {
    if (l > h)
      return -1;
    int mid = (l + h) / 2;
    if (A[mid] == key)
      return mid;
    //If left part is sorted
    if (A[l] <= A[mid])
    {
      if (key >= A[l] && key <= A[mid])
        return search(A, l, mid - 1, key);
      return search(A, mid + 1, h, key);
    }
    //if right part is sorted
    else
    {
      if (key >= A[mid] && key <= A[h])
        return search(A, mid + 1, h, key);
      return search(A, l, mid - 1, key);
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
    int A[n];
    for (int i = 0; i < n; i++)
      cin >> A[i];
    int key;
    cin >> key;
    Solution ob;
    cout << ob.search(A, 0, n - 1, key) << endl;
  }
  return 0;
}

// Iterative appproach:-
int search(int A[], int l, int h, int key)
{
  while (l <= h)
  {
    int mid = (l + h) / 2;
    if (A[mid] == key)
      return mid;
    if (A[l] < A[mid])
    {
      if (A[l] <= key && A[mid] > key)
        h = mid - 1;
      else
        l = mid + 1;
    }
    else
    {
      if (A[mid] < key && A[h] >= key)
        l = mid + 1;
      else
        h = mid - 1;
    }
  }
  return -1;
}