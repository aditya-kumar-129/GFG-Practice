#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findMaxGuests(int arrl[], int exit[], int n)
  {
    sort(arrl, arrl + n);
    sort(exit, exit + n);
    int guests_in = 1, max_guests = 1, time = arrl[0];
    int i = 1, j = 0;
    while (i < n && j < n)
    {
      if (arrl[i] <= exit[j])
      {
        guests_in++;
        if (guests_in > max_guests)
        {
          max_guests = guests_in;
          time = arrl[i];
        }
        i++;
      }
      else
      {
        guests_in--;
        j++;
      }
    }
    vector<int> res;
    res.push_back(max_guests);
    res.push_back(time);
    return res;
  }
};
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, i;
    cin >> n;
    int entry[n], exit1[n];
    for (i = 0; i < n; i++)
      cin >> entry[i];
    for (i = 0; i < n; i++)
      cin >> exit1[i];
    Solution obj;
    vector<int> p = obj.findMaxGuests(entry, exit1, n);
    cout << p[0] << ' ' << p[1];
    cout << "\n";
  }
  return 0;
}