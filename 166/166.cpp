#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        if(num==0)
        {
            return "0";
        }
        bool is_postive = true;
        long long numerator = num;
        long long denominator = deno;
        
        if(numerator<0)
        {
            is_postive=!is_postive;
            numerator=-numerator;
        }
        if(denominator<0)
        {
            is_postive=!is_postive;
            denominator=-denominator;
        }
        long long  integer = numerator/denominator;
        long long  remain = numerator % denominator;
        if(remain==0)
        {
            char chs[100]={0};
            if(is_postive)
            {
                sprintf(chs,"%lld",integer);    
            }
            else
            {
                sprintf(chs,"-%lld",integer);  
            }
            
            return chs;
        }
        string radix;
        int  radix_size=0;
        vector<long long > pre_remain;
        while(true)
        {
            pre_remain.push_back(remain);
            if(remain==0)
            {
                break;
            }
            remain*=10;
            radix+= (remain/denominator)+'0';
            remain = remain%denominator;
           
            // find if ever 
            bool find_loop=false;
            for(int i =0;i<pre_remain.size();++i)
            {
                if(remain==pre_remain[i])
                {
                    find_loop=true;
                    radix = radix.substr(0,i) +"(" +radix.substr(i,radix_size-i+1)+")";
                    break;
                }
            }
            if(find_loop)
            {
                break;
            }

            ++radix_size;
        }
        char chs[20]={0};
        if(is_postive)
        {
            sprintf(chs,"%lld.",integer);    
        }
        else 
        {
            sprintf(chs,"-%lld.",integer);    
        }
        
        return string(chs)+radix;
    }
};

int main()
{   
    Solution s;
    cout<<s.fractionToDecimal(-2147483648,1)<<endl;
}