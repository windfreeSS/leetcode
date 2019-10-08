#include "../all.cpp"

// 查找环

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> flags(nums.size());
        int ret = 0;
        for(int i=0;i<nums.size();++i)
        {
            int one = find_from(i,flags,nums);
            if(one>ret)
            {
                ret = one;
            }
        }
        return ret;
    }

    int find_from(int start,vector<bool>& flag,vector<int>&nums )
    {
        if(flag[start])
        {
            return 0;
        }

        int len = 1;
        flag[start] = true;
        int next = nums[start];

        while(!flag[next])
        {
            flag[next] = true;
            next = nums[next];
            ++len;
        }
        return len;

    }
};