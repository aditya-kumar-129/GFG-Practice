/*
Refer the below article for more information:-
https://www.geeksforgeeks.org/sum-of-all-subarrays/
*/

// METHOD :- 1 (Brute force approach)
/*
If the array is [1,2,3]
then below is how for loop is being executed:-
1
1+2
1+2+3
2
2+3
3
*/

// #include<bits/stdc++.h>
// using namespace std;

// long int SubArraySum(int arr[], int n)
// {
// 	long int result = 0,temp=0;

// 	for (int i=0; i <n; i++)
// 	{
// 		temp=0;
// 		for (int j=i; j<n; j++)
// 		{
// 			temp+=arr[j];
// 			result += temp ;
// 		}
// 	}
// 	return result ;
// }

// int main()
// {
// 	int arr[] = {1, 2, 3} ;
// 	int n = sizeof(arr)/sizeof(arr[0]);
// 	cout << "Sum of SubArray : " << SubArraySum(arr, n) << endl;
// 	return 0;
// }

// Method 2:- Efficient Solution:-
// Question link:- https://practice.geeksforgeeks.org/problems/sum-of-subarrays2229/1#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long subarraySum(long long a[], long long n)
  {
    long long res = 0;
    for (int i = 0; i < n; i++)
      res = (res + a[i] * (i + 1) * (n - i)) % 1000000007;
    return res;
  }
};

int main()
{
  long long t;
  cin >> t;
  while (t--)
  {
    long long n;
    cin >> n;
    long long a[n + 5];
    for (long long i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    cout << ob.subarraySum(a, n) << endl;
  }
  return 0;
}