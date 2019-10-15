#include "../all.cpp"


class Solution {
public:
    TreeNode* cmbt(vector<int>&nums,int begin,int end)
    {
        if(begin>=end)
        {
            return NULL;
        }
        int max_pos = begin;
        for(int i=begin+1;i<end;++i)
        {
            if(nums[i]>nums[max_pos])
            {
                max_pos = i;
            }
        }
        TreeNode* tn = new TreeNode(nums[max_pos]);
        tn->left = cmbt(nums,begin,max_pos);
        tn->right = cmbt(nums,max_pos+1,end);
        return tn;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return cmbt(nums,0,nums.size());
    }
};