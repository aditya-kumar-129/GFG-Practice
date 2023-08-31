#include <bits/stdc++.h>
using namespace std;

long long int count2sinRangeAtDigit(long long int number, long long int d) {
  int count = 0;
  for (int i = 0; i <= d; i++) {
    int temp = i;
    while (temp != 0) {
      int rem = temp % 10;
      if (rem == 2) count++;
      temp = temp / 10;
    }
  }
  return count;
}

long long int numberOf2sinRange(long long int number) {
  count2sinRangeAtDigit(0, number);
}

// Method 2 :- Convert the given number to string and then check if any character present is 2 or not
long long int numberOf2sinRange(long long int number) {
  int count = 0;
  for (int i = 0; i <= number; i++) {
    string s = to_string(i);
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '2') count++;
    }
  }
  return count;
}