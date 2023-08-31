#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int minelem;
void push(stack<int>& s, int a) {
  if (s.empty()) minelem = a;
  if (a >= minelem) s.push(a);
  else {
    s.push(2 * a - minelem);
    minelem = a;
  }
  return;
}

bool isFull(stack<int>& s, int n) {
  return s.size() >= n;
}

bool isEmpty(stack<int>& s) {
  return s.empty();
}

int pop(stack<int>& s) {
  if (s.top() >= minelem) {
    int temp = s.top();
    s.pop();
    return temp;
  }
  else {
    int temp = minelem;
    minelem = 2 * minelem - s.top();
    s.pop();
    return temp;
  }
}

int getMin(stack<int>& s) {
  return minelem;
}