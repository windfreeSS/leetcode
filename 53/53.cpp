#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int num_len = nums.size();
        int max_sum_for_sub = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < num_len; ++i)
        {
            if (max_sum_for_sub < 0)
            {
                max_sum_for_sub = nums[i];
            }
            else
            {
                max_sum_for_sub += nums[i];
            }
            if(max_sum_for_sub > max_sum)
            {
                max_sum = max_sum_for_sub;
            }
        }
        return max_sum;
    }
};

int main()
{
    Solution s;
    vector<int> data = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(data)<<endl;
}