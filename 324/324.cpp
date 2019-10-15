#include "../all.cpp"

// 题目的关键是找出中位数，然后将数据分成两部分。
// 算法名字叫做BFPRT分割算法，标准库里面实现的为 nth_element。
// 目前尚未完全理解此方法。
// 

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        bool find_big = true;
        ret[0]=nums[0];
        for(int i=1;i<n;++i)
        {
            if(find_big)
            {
                
            }
            else
            {

            }
            find_big = !find_big;
        }
    }
};