/*
There are two ways twom solve this problem
*/

// Method 1:- (HINT)

// #include <bits/stdc++.h>
// using namespace std;

// class SortedStack
// {
// public:
//   stack<int> s;
//   void sort();
// };

// void printStack(stack<int> s)
// {
//   while (!s.empty())
//   {
//     printf("%d ", s.top());
//     s.pop();
//   }
//   printf("\n");
// }

// int main()
// {
//   int t;
//   cin >> t;
//   while (t--)
//   {
//     SortedStack *ss = new SortedStack();
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//       int k;
//       cin >> k;
//       ss->s.push(k);
//     }
//     ss->sort();
//     printStack(ss->s);
//   }
// }

// void SortedStack ::sort()
// {
//   stack<int> tmp;
//   int x;
//   while (!s.empty())
//   {
//     x = s.top();
//     s.pop();
//     tmp.push(x);
//   }

//   while (!tmp.empty())
//   {
//     x = tmp.top();
//     tmp.pop();
//     if (s.empty())
//       s.push(x);
//     else
//     {
//       int topTmp = s.top();
//       if (topTmp <= x)
//         s.push(x);
//       else
//       {
//         while (!s.empty() && s.top() > x)
//         {
//           int y = s.top();
//           s.pop();
//           tmp.push(y);
//         }
//         s.push(x);
//       }
//     }
//   }
// }

// Method 2:- (Me because the time complexity needed to solve this problem is O(n^2) that's why we can use any sorting algorithm to sort the array and here i have used insertion sort)

#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
  stack<int> s;
  void sort();
};

void printStack(stack<int> s)
{
  while (!s.empty())
  {
    printf("%d ", s.top());
    s.pop();
  }
  printf("\n");
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    SortedStack *ss = new SortedStack();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;
      ss->s.push(k);
    }
    ss->sort();
    printStack(ss->s);
  }
}
void SortedStack ::sort()
{
  // We have used here vector because we don't know thw number of element present in the stack so we have taken the dynamic array in c++ ie. vector
  vector<int> v;
  while (!s.empty())
  {
    int x = s.top();
    v.push_back(x);
    s.pop();
  }
  // Sorted the content of array using insertion sort
  int i, key, j;
  for (i = 1; i < v.size(); i++)
  {
    key = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > key)
    {
      v[j + 1] = v[j];
      j = j - 1;
    }
    v[j + 1] = key;
  }
  for (int i = 0; i < v.size(); i++)
    s.push(v[i]);
}