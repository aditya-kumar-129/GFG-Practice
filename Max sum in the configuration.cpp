/*
  For better understanding watch the below video :-
  https://youtu.be/yroWfS5P2E4
*/
#include <bits/stdc++.h>
using namespace std;

int max_sum(int arr[], int n) {
  int sum = 0, S0 = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    S0 = S0 + (arr[i] * i);
  }
  int max = S0, Si = S0;
  for (int i = 0; i < n - 1; i++) {
    int Sip1 = Si + sum - n * arr[n - 1 - i];
    if (Sip1 > max) max = Sip1;
    Si = Sip1;
  }
  return max;
}