#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
  int petrol;
  int distance;
};

class Solution
{
public:
  // See the youtube video for more info:- https://www.youtube.com/watch?v=zcnVaVJkLhY
  int tour(petrolPump p[], int n)
  {
    int start = 0, deficit = 0;
    int capacity = 0;
    for (int i = 0; i < n; i++)
    {
      capacity += p[i].petrol - p[i].distance;
      if (capacity < 0)
      {
        start = i + 1; // If this particular step is not done then the between steps would be redundant
        deficit += capacity;
        capacity = 0;
      }
    }
    return (capacity + deficit > 0) ? start : -1;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    petrolPump p[n];
    for (int i = 0; i < n; i++)
      cin >> p[i].petrol >> p[i].distance;
    Solution obj;
    cout << obj.tour(p, n) << endl;
  }
}

// Method 2:- In this method we use the same concept as in the above method but we have traverse each index twice here as we are not storing the value prev values

int tour(petrolPump arr[], int n)
{
  int start;
  for (int i = 0; i < n; i++)
  {
    if (arr[i].petrol >= arr[i].distance)
    {
      start = i;
      break;
    }
  }

  int curr_petrol = 0;
  int i;
  for (i = start; i < n;)
  {
    curr_petrol += (arr[i].petrol - arr[i].distance);
    if (curr_petrol < 0)
    {
      i++;
      for (; i < n; i++)
      {
        if (arr[i].petrol >= arr[i].distance)
        {
          start = i;
          curr_petrol = 0;
          break;
        }
      }
    }
    else
      i++;
  }
  if (curr_petrol < 0)
    return -1;

  for (int j = 0; j < start; j++)
  {
    curr_petrol += (arr[j].petrol - arr[j].distance);
    if (curr_petrol < 0)
      return -1;
  }
  return start;
}

// Method 2 :-  Using Queue

int tour(petrolPump p[], int n)
{
  int start = 0, val = (p[0].petrol - p[0].distance), end = 1;
  while (start != end || val < 0)
  {
    while (start != end && val < 0)
    {
      val -= (p[start].petrol - p[start].distance);
      start = (start + 1) % n;
      if (start == 0)
        return -1;
    }
    val += (p[end].petrol - p[end].distance);
    end = (end + 1) % n;
  }
  return start;
}
