/*
In merge process, let i is used for indexing left sub-array and j for right sub-array. At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]
For detail explaination like how merge sort algorithm help in solving this problem see the below youtube video:-
https://youtu.be/uojx--MK_n0
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void merge(int start, int mid, int end, long long arr[], long long int& count)
  {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    vector<long long int> left(n1);
    vector<long long int> right(n2);
    int i, j, k;
    for (i = 0; i < n1; i++)
      left[i] = arr[start + i];
    for (i = 0; i < n2; i++)
      right[i] = arr[mid + i + 1];
    i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
      if (left[i] > right[j])
      {
        // the only extra line in the code and the other whole codes are of merge sort
        count += (n1 - i);
        arr[k++] = right[j++];
      }
      else
        arr[k++] = left[i++];
    }
    while (i < n1)
      arr[k++] = left[i++];
    while (j < n2)
      arr[k++] = right[j++];
  }

  void mergesort(int start, int end, long long arr[], long long int& count)
  {
    if (start < end)
    {
      int mid = (start + end) / 2;
      mergesort(start, mid, arr, count);
      mergesort(mid + 1, end, arr, count);
      merge(start, mid, end, arr, count);
    }
  }

  long long int inversionCount(long long arr[], long long N)
  {
    long long int count = 0;
    mergesort(0, N - 1, arr, count);
    return count;
  }
};

int main()
{
  long long T;
  cin >> T;
  while (T--)
  {
    long long N;
    cin >> N;
    long long A[N];
    for (long long i = 0; i < N; i++)
      cin >> A[i];
    Solution obj;
    cout << obj.inversionCount(A, N) << endl;
  }
  return 0;
}