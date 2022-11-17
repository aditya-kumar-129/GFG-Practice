#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/even-numbers-even-index-odd-numbers-odd-index/

class Solution
{
public:
  void reArrange(int arr[], int n)
  {
    int oddInd = 1;
    int evenInd = 0;
    while (true)
    {
      while (evenInd < n && arr[evenInd] % 2 == 0)
        evenInd += 2;
      while (oddInd < n && arr[oddInd] % 2 == 1)
        oddInd += 2;
      if (evenInd < n && oddInd < n)
        swap(arr[evenInd], arr[oddInd]);
      else
        break;
    }
  }
};

int check(int arr[], int n)
{
  int flag = 1;
  int c = 0, d = 0;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      if (arr[i] % 2 ==1)
      {
        flag = 0;
        break;
      }
      else
        c++;
    }
    else
    {
      if (arr[i] % 2 == 0)
      {
        flag = 0;
        break;
      }
      else
        d++;
    }
  }
  if (c != d)
    flag = 0;
  return flag;
}

// Method :- 2
// Space Com[lexity :- O(n)
void reArrange(int arr[], int N) 
{
  int even = 0, odd = 1;
  int ans[N];
  for (int i = 0;i < N;i++) 
  {
    if (arr[i] % 2 == 0) 
    {
      ans[even] = arr[i];
      even += 2;
    }
    else if (arr[i] % 2 == 1) 
    {
      ans[odd] = arr[i];
      odd += 2;
    }
  }
  for (int i = 0;i < N;i++)
    arr[i] = ans[i];
}