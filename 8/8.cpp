#include <iostream>
#include <limits.h>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        //数字长度超过12位，则直接返回0
        int valid_start= -1;
        int str_len = str.size();
        //排除空格
        for(int i=0;i<str_len;++i)
        {
            if(str[i]==' ')
            {
                continue;
            }
            valid_start = i;
            break;
        }
        if(valid_start==-1)
        {
            return 0;
        }

        int neg = 1;
        if(str[valid_start]=='+')
        {
            ++valid_start;
        }
        else if(str[valid_start]=='-')
        {
            neg = -1;
            ++valid_start;
        }


        long long big_val =0;
        int valid_end;
        while(valid_start<str_len)
        {
            if(str[valid_start]!='0')
            {
                break;
            }
            ++valid_start;
        }
        for(valid_end =valid_start;valid_end<str_len;++valid_end)
        {
            if( str[valid_end] >='0' && str[valid_end]<='9')
            {
                big_val = big_val*10 + (str[valid_end]-'0');
                continue;
            }
            break;
        }
        if( (valid_end-valid_start) > 13)        
        {
            if(neg==1)
            {
                return INT_MAX;
            }
            else
            {
                return INT_MIN;
            }
        }
        big_val = big_val * neg;
        if(big_val > INT_MAX)
        {
            return INT_MAX;
        }
        else if(big_val < INT_MIN)
        {
            return INT_MIN;
        }
        return big_val;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.myAtoi("42")<<endl;
    cout<<s.myAtoi("   -42")<<endl;
    cout<<s.myAtoi("+1")<<endl;
    cout<<s.myAtoi("4193 with words")<<endl;
    cout<<s.myAtoi("words and 987")<<endl;
    cout<<s.myAtoi("-91283472332")<<endl;
    cout<<s.myAtoi("9999999999999999999999999999999999999999999999999999999999999999999")<<endl;
    cout<<s.myAtoi("0000000000012345678")<<endl;
    return 0;
}