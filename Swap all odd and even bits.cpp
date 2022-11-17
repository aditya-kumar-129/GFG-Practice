#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    unsigned int swapBits(unsigned int x)
    {
    	unsigned int even_bits = x & 0xAAAAAAAA;
      unsigned int odd_bits = x & 0x55555555;
      even_bits >>= 1;
      odd_bits <<= 1;
      return (even_bits | odd_bits);
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned int n;
		cin>>n;
		Solution ob;
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}