#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        static unsigned int pow_base_table[] = {1, 2 , 4 , 8 , 16 , 32 , 64 , 128 , 256 , 512 , 1024 , 2048 , 4096 , 8192 , 16384 , 32768 , 65536 , 131072 , 262144 , 524288 , 1048576 , 2097152 , 4194304 , 8388608 , 16777216 , 33554432 , 67108864 , 134217728 , 268435456 , 536870912 , 1073741824 , 2147483648 };
        if (dividend == 0)
        {
            return 0;
        }

        // int  [−2^31,  2^31 − 1] from   -2147483648 to 2147483647
        if (divisor == 1)
        {
            return dividend;
        }
        else if (divisor == -1)
        {
            if (dividend == -2147483648)
            {
                return 2147483647;
            }
            return -dividend;
        }


        vector<long long> pow_list;
        int result;
        if ( (dividend > 0) && (divisor > 0) )
        {
            long long pow_data = divisor;
            while (pow_data <= dividend)
            {
                pow_list.push_back(pow_data);
                pow_data +=pow_data;
            }
            if(pow_list.empty())
            {
                return 0;
            }
            result=0;
            int test_div = dividend;
            for(int i= pow_list.size()-1;i>=0;--i)
            {
                if(test_div >= pow_list[i])
                {
                    result += pow_base_table[i];
                    test_div-=pow_list[i];
                }
            }
        }
        else //dividend<0 or divisor<0 
        {
            bool is_result_neg = false;
            long long long_dividend = dividend;
            long long pow_data = divisor;//
            if(dividend<0)
            {
                long_dividend = -long_dividend;
                is_result_neg = !is_result_neg;
            }
            if(divisor<0)
            {
                pow_data = -pow_data;
                is_result_neg = !is_result_neg;
            }
            while (pow_data <= long_dividend)
            {
                pow_list.push_back(pow_data);
                pow_data +=pow_data;
            }
            if(pow_list.empty())
            {
                return 0;
            }
            result=0;

            long long test_div = long_dividend;
            for(int i= pow_list.size()-1;i>=0;--i)
            {
                if(test_div >= pow_list[i])
                {
                    result += pow_base_table[i];
                    test_div-=pow_list[i];
                }
            }
            if(test_div!=0)
            {
                // ++result;  //no round 
            }
            if(is_result_neg)
            {
                result = -result;
            }
            return result;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.divide(-2147483648,2)<<endl;
}