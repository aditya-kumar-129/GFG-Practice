/*
Few articles whose concept has been used to solve the below problem is:-
https://www.geeksforgeeks.org/stdstol-and-stdstoll-functions-in-c/

To understand how Next permuatation has been implemented and what is the logic behind it see the below video:-
https://www.youtube.com/watch?v=6qXO72FkqwM
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long getNextEven(string str) {
    int p = stoll(str);
    while (next_permutation(str.begin(), str.end()))
      //in the first part of the if condition, we are checking wheather the number is even or not and in the second part of the if condition we are checking if its numeric value is greater than the one that has been given as the input in the function.
      // A number is divisible by 2 if the digit at unit place is either 0 or multiple of 2.
      if (str[str.length() - 1] % 2 == 0 && stoll(str) > p)
        return stoll(str);
    // well the next permutation function always makes sure that the outgoing number is always greater than the incoming number so we may skip the second part of the IF CONDITION
    return -1;
  }
};

// if you don't want to use the inbuilt function then here is the implementation of next permutation (method applied in the code is same as the one that has been explained in the youtube video link that has been shared above!!)

long long getNextEven(string str) {
  while (true) {
    int index = -1;
    for (int i = 1; i < str.length(); i++) {
      if (str[i] > str[i - 1]) index = i;
    }
    if (index == -1)
      return -1LL;
    //according to leetcode problem when the given number is in descending order i.e you won't be able to find the pivot element then in that case just sort the array and that is the answer of the question
    int index = index;
    for (int i = index; i < str.length(); i++)
    {
      if (str[i] > str[index - 1] and str[i] < str[index])
        index = i;
    }
    swap(str[index - 1], str[index]);
    sort(str.begin() + index, str.end());
    if (str[str.length() - 1] % 2 == 0) return stoll(str);
  }
}
