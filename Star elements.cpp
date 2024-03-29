#include <bits/stdc++.h>
using namespace std;

vector<int> getStarAndSuperStar(int arr[], int n) {
  vector<int> ans;
  int maxi = n - 1;
  ans.push_back(maxi);
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] >= arr[maxi]) {
      if (arr[i] > arr[maxi]) ans.push_back(i);
      maxi = i;
    }
  }
  n = ans.size();
  if (maxi != ans[n - 1]) ans.push_back(-1);
  else ans.push_back(ans[n - 1]);
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < n + 1; i++) {
    if (ans[i] != -1) ans[i] = arr[ans[i]];
  }
  return ans;
}