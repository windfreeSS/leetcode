#include "../all.cpp"

class Solution {
private:
    vector<vector<int>> result;
    vector<int> curr_comb;
public:
    bool search_comb(vector<int>& nums, int start_pos, int target, int max_size)
    {
        if(target<0)
        {
            return false;
        }
        else if(target==0)
        {
            result.push_back(curr_comb);
            return true;
        }
        for (int i = start_pos; i < max_size; ++i)
        {
            if (i!=start_pos && nums[i]==nums[i-1])
            {
                continue;
            }
            curr_comb.push_back(nums[i]);
            search_comb(nums, i + 1, target - nums[i], max_size);
            curr_comb.pop_back();
        }

        return false;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort
        std::sort(candidates.begin(), candidates.end());

        int can_len = candidates.size();

        for (int i = 0; i < can_len; ++i)
        {
            if (i != 0 && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            curr_comb.push_back(candidates[i]);
            search_comb(candidates, i + 1, target - candidates[i], can_len);
            curr_comb.pop_back();
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    vector<int> data = {10,1,2,7,6,1,5};
    int target = 10;
    vector<vector<int>> result = s.combinationSum2(data,target);
    for(int i=0;i<result.size();++i)
    {
        print(result[i]);
    }
    return 0;
}

// 使用回溯
// 根据相邻的两个数，是否相同，来去重。