#include <bits/stdc++.h> 
using namespace std;

// Space complexity :- O(1)
// Transpose of a SQUARE MATRIX

class Solution
{
public:
  void transpose(vector<vector<int> >& matrix, int n)
  {
    for (int i = 0;i < n;i++)
      for (int j = i;j < n;j++)
        if (i != j)
          swap(matrix[i][j], matrix[j][i]);
  }
};