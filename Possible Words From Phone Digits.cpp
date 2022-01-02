#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
  string getNumString(int n)
  {
    switch (n)
    {
    case 2: return "abc";
    case 3: return "def";
    case 4: return "ghi";
    case 5: return "jkl";
    case 6: return "mno";
    case 7: return "pqrs";
    case 8: return "tuv";
    case 9: return "wxyz";
    }
  }

  void getWords(int i, int n, int a[], string curr, vector<string> &res)
  {
    if (i == n)
    {
      res.push_back(curr);
      return;
    }
    string s = getNumString(a[i]);
    for (int j = 0; j < s.size(); j++)
      getWords(i + 1, n, a, curr + s[j], res);
  }

  //Function to find list of all words possible by pressing given numbers.
  vector<string> possibleWords(int a[], int N)
  {
    vector<string> res;
    getWords(0, N, a, "", res);
    return res;
  }
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
      cin >> a[i]; 
    Solution obj;
    vector<string> res = obj.possibleWords(a, N);
    for (string i : res)
      cout << i << " ";
    cout << endl;
  }
  return 0;
} 