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

int main() 
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int> > matrix(n);
    for (int i = 0; i < n; i++)
    {
      matrix[i].assign(n, 0);
      for (int j = 0; j < n; j++)
        cin >> matrix[i][j];
      }
    Solution ob;
    ob.transpose(matrix, n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cout << matrix[i][j] << " ";
    cout << endl;
  }
  return 0;
}  