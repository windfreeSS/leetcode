#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int begin =1;
        int end = x+1;
        int val =0;
        while(begin<end)
        {
        	int mid = (begin+end)/2;
        	long long tmp = mid*mid;
        	if( tmp <x )
        	{
        		val = mid;
        		begin = mid+1;
        	}
        	else if( tmp>x )
        	{
        		end=mid;
        	}
        	else
        	{
        		return mid;
        	}
        }
        return val;
    }
};
int main()
{
	Solution s;
	cout<<s.mySqrt(4)<<endl;
}