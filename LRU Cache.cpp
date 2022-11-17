/*
Refer the below youtube video to understand the solution:-
https://www.youtube.com/watch?v=akFRa58Svug
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
public:
  //Constructor for initializing the cache capacity with the given value.
  unordered_map<int, list<pair<int, int>>::iterator> mp;
  list<pair<int, int>> l;
  int size;

  LRUCache(int cap)
  {
    size = cap;
  }

  //Function to return value corresponding to the key.
  int get(int key)
  {
    if (mp.find(key) != mp.end())
    {
      auto it = mp[key];
      pair<int, int> p = *it;
      l.erase(mp[key]);
      l.push_front(p);
      mp[key] = l.begin();
      return p.second;
    }
    return -1;
  }

  //Function for storing key-value pair.
  void set(int key, int value)
  {
    if (mp.find(key) != mp.end())
      l.erase(mp[key]);
    else
    {
      if (l.size() == size)
      {
        mp.erase(l.back().first);
        l.pop_back();
      }
    }
    l.push_front({key, value});
    mp[key] = l.begin();
  }
};