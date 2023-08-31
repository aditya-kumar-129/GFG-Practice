#include <bits/stdc++.h>
using namespace std;

// Method1 :- converting the given array to string and then using next_permutation
long long getSum(int arr[], int n) {
  string str;
  for (int i = 0; i < n; i++) str += arr[i] + '0';
  sort(str.begin(), str.end());
  long long res = 0;
  do {
    res = (res + stoi(str)) % 1000000007;
  } while (next_permutation(str.begin(), str.end()));
  return res;
}

// Method 2:- Converting the given array to Number and then using next permutation

long long getSum(int A[], int n) {
  long long int sum = 0;
  sort(A, A + n);
  long long int num = 0;
  for (long long int i = 0; i < n; i++) num = (num * 10) + A[i];
  sum += num;
  while (next_permutation(A, A + n)) {
    num = 0;
    for (long long int i = 0; i < n; i++) num = (num * 10) + A[i];
    sum += num;
  }
  return sum % 1000000007;
}