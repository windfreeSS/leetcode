#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        else if(x==0)
        {
            return true;
        }
        else if( (x%10) == 0 )
        {
            return false;
        }
        int from_head = x;
        int exchange_ = 0 ;
        while(x > 0)
        {
            exchange_ = exchange_ * 10 + (x%10);
            x/=10;
            if(exchange_ == x)
            {
                return true;
            }
            else if( exchange_ > x && x>0 )
            {
                exchange_/=10;
                return exchange_ ==x;
            }
        }
        if(exchange_==from_head)
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.isPalindrome(121)<<endl;
    cout<<s.isPalindrome(-121)<<endl;
    cout<<s.isPalindrome(10)<<endl;
    cout<<s.isPalindrome(0)<<endl;
    return 0;
}