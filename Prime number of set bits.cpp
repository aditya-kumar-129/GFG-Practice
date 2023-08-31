#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int decToBinary(int n) {
    int temp = n;
    int binaryNum[32] = { 0 };
    int i = 0;
    while (n > 0) {
      binaryNum[i] = n % 2;
      n = n / 2;
      i++;
    }
    int count = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (binaryNum[j] == 1) count++;
    }
    if (count == 2 || count == 3 || count == 5 || count == 7) return 1;
    else return 0;
  }
  int primeSetBits(int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++) {
      int temp = decToBinary(i);
      if (temp == 1) count++;
    }
    return count;
  }
};

// Short code to solve the above problem is :-
/*
Read the below article in order to understand the approach to solve the problem
https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/
*/
int primeSetBits(int l, int r) {
  int count = 0;
  for (int i = l; i <= r; i++) {
    int temp = __builtin_popcount(i);
    if (temp == 2 || temp == 3 || temp == 5 || temp == 7) count++;
  }
  return count;
}