#include <bits/stdc++.h>
using namespace std;

int findElement(int a[], int n)
{
  int mini[n], maxi[n];
  mini[0] = a[0];
  maxi[n - 1] = a[n - 1];
  for (int i = 1; i < n; i++)
    mini[i] = max(mini[i - 1], a[i]);
  for (int i = n - 2; i >= 0; i--)
    maxi[i] = min(maxi[i + 1], a[i]);
  // https://stackoverflow.com/questions/38053539/find-the-element-in-an-array-in-which-left-elements-are-smaller-and-right-eleme
  for (int i = 1; i < n - 1; i++)
    if (mini[i] == maxi[i])  // if(maxi[i+1]>=a[i] && a[i]>=mini[i-1])
      return mini[i];
  return -1;
}

/*optimisation method so as to reduce the space complexity of the problem below is the article to get about it (NOT ABLE TO GET THE OPTIMISATION PART)
https://www.geeksforgeeks.org/find-the-element-before-which-all-the-elements-are-smaller-than-it-and-after-which-all-are-greater-than-it/
*/