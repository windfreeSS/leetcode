#include "../all.cpp"

class Solution {
public:
    int base_dp(vector<int>& nums)
    {//最开始实现的
        int n = nums.size();
        vector<int> dp_lens(n, 1);
        for (int i = n - 2; i >= 0; --i)
        {
            int max_len = 0;
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] < nums[j] && max_len < dp_lens[j])
                {
                    max_len = dp_lens[j];
                }
            }
            dp_lens[i] = max_len + 1;
        }
        int max_len = 0;
        for (int i = 0; i < dp_lens.size(); ++i)
        {
            if (max_len < dp_lens[i])
            {
                max_len = dp_lens[i];
            }
        }

        return max_len;
    
    }
    int better_dp(vector<int>& nums)
    {// n logn 的题解，没有看到比较明确的证明
        return 0;
    }
    int lengthOfLIS(vector<int>& nums) {return base_dp(nums);}
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}