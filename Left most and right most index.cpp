#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	pair<long, long> indexes(vector<long long> v, long long x) {
		pair<long, long> p = { -1,-1 };
		for (int i = 0; i < v.size(); i++) {
			if (p.first == -1 && v[i] == x) p.first = i;
			else if (v[i] == x) p.second = i;
		}
		if (p.first != -1 && p.second == -1) p.second = p.first;
		return p;
	}
};