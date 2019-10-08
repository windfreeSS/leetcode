#include "../all.cpp"

// 异或后，根据异或的特性，进行分组
// 因为两个数不同，所以异或的结果不可能是0.
// 找出为1的位，比如第五位为1，再对所有第五位为1的数据进行异或，则可以排除掉另外一个数据e

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        {
            return vector<int>();
        }
        int xor_val = 0 ;
        for (int i = 0; i < n; ++i )
        {
            xor_val ^= nums[i];
        }

        int pos ;
        for(pos=0;pos<31;++pos)
        {
            if( (xor_val & (1<<pos))!=0)
            {
                break;
            }
        }
        int xor_a = 0;
        for(int i=0;i<n;++i)
        {
            if( (nums[i] & (1<<pos))==0)
            {
                continue;
            }
            xor_a ^=nums[i];
        }
        vector<int> result;
        result.push_back(xor_a);
        result.push_back(xor_a^xor_val);
        return result;
    }
};