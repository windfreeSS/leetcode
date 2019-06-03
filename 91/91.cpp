#include <iostream>
#include <string>
#include <vector>
using namespace std;



// partition 
class Solution {
public:
    int calc_partition(const string&s ,int begin,int count)
    {
        if(count<1)
        {
            return 0;
        }
        if(count==1)
        {
            return 1;
        }
        int half = count/2;
        int part_sum = calc_partition(s,begin,half)*calc_partition(s,begin+half,count-half);
        int comb_sum =0;
         if(s[begin+half-1] =='1' ||
           (s[begin+half-1] =='2' && s[begin+half] < '7') )
        {
            int left_comb = 1;
            int left_remain = half-1;
            int right_comb = 1;
            int right_remain = count-half-1;
            if(left_remain > 0)
            {
                left_comb = calc_partition(s,begin,left_remain);
            }
            if( right_remain > 0)
            {
                right_comb = calc_partition(s,begin+half+1,right_remain);
            }
            comb_sum = left_comb*right_comb;
        }
        return part_sum + comb_sum;
    }
    int numDecodings(string s) {
        int s_len = s.size();
        int sum = 1;
        int last_not_isolated = 0;
        // find isolated point 
        for(int i=0;i<s_len;++i)
        {
           if(s[i]=='0')
            {
                if(i==0 || s[i-1]>'2' || s[i-1]=='0')
                {
                    return 0;
                }
                int calc_size = i-last_not_isolated-1;
                if(calc_size>0)
                {
                    sum*= calc_partition(s,last_not_isolated,calc_size);
                }
                last_not_isolated = i+1;
                continue;
            }
        }
        if(last_not_isolated<s_len)
        {
            sum*= calc_partition(s,last_not_isolated,s_len-last_not_isolated);
        }
        return sum;
    }
};

int main()
{
    Solution s;
    cout<<s.numDecodings("121212121212121212121212122222222222222")<<endl;
}