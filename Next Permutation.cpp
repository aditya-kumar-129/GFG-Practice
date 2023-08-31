#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextPermutation(int N, vector<int> arr) {
    int i, index1 = -1, index2 = -1;
    // Finds the last peak that is present in the number (which has the least weightage)
    // Index2 will point on the peak element 
    // while index1 point to the element just below the peak element
    for (i = 0; i < N - 1; i++) {
      if (arr[i] < arr[i + 1]) {
        index1 = i;
        index2 = i + 1;
      }
    }
    // In case the input numbers are in descending order then in that just sort the array(nlogn) 
    // OR DIVIDE THE ARRAY INTO TWO PARTS AND THEN SWAP THE CONTENT FROM THE FRONT AND END i,e., swap(arr[front],arr[end]) tales O(n) time;
    if (index1 == -1) reverse(arr.begin(), arr.end());
    // Find the smallet element that is present on the right side of the peak which can be swaped with the content present at index1 with the condition that IT IS GREATER THAN THE ELEMENT THAT IS PRESENT ON THE INDEX1 AND SMALLER THAN THE PEAK ELEMENT.
    // After swapping sort the array from the PEAK to the end so as to get the least value on the (PEAK-END) part
    else {
      int mx = arr[index1], smallest = index2;
      for (i = index2; i < N; i++) {
        if (arr[i] > mx && arr[i] < arr[smallest]) smallest = i;
      }
      swap(arr[smallest], arr[index1]);
      sort(arr.begin() + index2, arr.end());
    }
    return arr;
  }
};

// Using Inbuilt Function
vector<int> nextPermutation(int N, vector<int> arr) {
  next_permutation(arr.begin(), arr.end());
  return arr;
}