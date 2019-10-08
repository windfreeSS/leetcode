#include "../all.cpp"

// 此解法，与46题目相同，因为46是根据字母序生成的，已经能处理重复的情况。
// 如果使用回溯算法，则不能直接处理重复情况。


class Solution {
public:

    vector<vector<int>> calc_permute_dict_sequence(vector<int>& nums)
    {
        int num_len = nums.size();
        vector<vector<int>> result;
        if (num_len == 0)
        {
            result.push_back(vector<int>());
            return result;
        }

        
        vector<int> first_permute = nums;
        std::sort(first_permute.begin(),first_permute.end());
        result.push_back(first_permute);

        while(true)//find next 
        {
            int first_less=-1;
            for(int i=num_len-2;i>=0;--i)
            {
                if(first_permute[i]<first_permute[i+1])
                {
                    first_less = i;
                    break;
                }
            }
            if(first_less==-1)
            {
                break;
            }

            int bigger_pos=-1;
            for(int i=num_len-1;i>first_less;--i)
            {
                if(first_permute[i]>first_permute[first_less])
                {
                    bigger_pos=i;
                    break;
                }
            }
            // swap less 
            int temp= first_permute[first_less];
            first_permute[first_less] = first_permute[bigger_pos];
            first_permute[bigger_pos] = temp;

            // swap range
            int exch_left=  first_less+1;
            int exch_right = num_len-1;
            while(exch_left<exch_right)
            {
                temp = first_permute[exch_left];
                first_permute[exch_left] = first_permute[exch_right];
                first_permute[exch_right] = temp;
                ++exch_left;
                --exch_right;
            }
            result.push_back(first_permute);

        }
        return result;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        return calc_permute_dict_sequence(nums);
    }
};