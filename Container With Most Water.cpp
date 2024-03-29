/*
For explanation of the logic see the below video:-
https://youtu.be/qUDp8IUbZto
https://youtu.be/ZHQg07n_tbg
*/
#include <iostream>
using namespace std;

long long maxArea(long long A[], int len) {
  long long int l = 0, r = len - 1, area = 0;
  while (l < r) {
    area = max(area, min(A[l], A[r]) * (r - l));
    if (A[l] < A[r]) l++;
    else r--;
  }
  return area;
}