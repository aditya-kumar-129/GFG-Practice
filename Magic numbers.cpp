/* in this problem I get to know about inbuilt gcd function in c++ which is present in algorithm header file
 Below is the link have a look on it
 https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007

class Solution {
public:
  long long getVal(int N, int A[]) {
    int ans;
    if (N == 1) ans = A[0] % MAX;
    else ans = __gcd(A[0] % MAX, A[1] % MAX);
    for (int i = 2; i < N; i++) ans = __gcd(ans, A[i] % MAX);
    long long int res = 1;
    for (int i = 0; i < N; i++) res = res * A[i] % MAX;
    long long int x = pow(res, ans);
    return x % MAX;
  }
};