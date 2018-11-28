#include <limits.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int neg = 1;
        
        if(x<0)
        {  
            neg = -1;
            x = -x;
        }
        if(x==0)
        {
            return 0;
        }
        long long big_val = 0;
        while(x>0)
        {
            int digit = x % 10;
            x = x / 10;
            big_val = big_val * 10 + digit;
        }
        big_val = big_val * neg;
        if (big_val > INT_MAX 
            || big_val < INT_MIN)
        {
            return 0;
        }
        return big_val;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    cout<<s.reverse(0)<<endl;
    cout<<s.reverse(-199999999)<<endl;
    cout<<s.reverse(-120)<<endl;
    cout<<s.reverse(1999999999)<<endl;
    
    return 0;
}