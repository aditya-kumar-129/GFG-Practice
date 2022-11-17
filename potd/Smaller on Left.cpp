#include <bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(int arr[], int n)
{
  set<int>s;
  vector<int> v;
  for (int i = 0;i < n;i++)
  {
    auto itr = s.lower_bound(arr[i]);
    if (itr == s.begin())
      v.push_back(-1);
    else
    {
      itr--;
      v.push_back(*itr);
    }
    s.insert(arr[i]);
  }
  return v;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0;i < n;i++)
      cin >> arr[i];
    vector<int> b;
    b = Smallestonleft(arr, n);
    for (int i = 0;i < n;i++)
      cout << b[i] << " ";
    cout << endl;
  }
  return 0;
}


