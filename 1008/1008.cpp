/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* search_build(vector<int>& nums, int begin, int end)
    {
        if (begin >= end)
        {
            return NULL;
        }
        TreeNode* tn = new TreeNode(nums[begin]);

        int mid ;
        for (mid = begin + 1; mid < end; ++mid)
        {
            if (nums[mid] > nums[begin])
            {
                break;
            }
        }

        tn->left = search_build(nums, begin + 1, mid);
        tn->right = search_build(nums, mid, end);
        return tn;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return search_build(preorder, 0, preorder.size());
    }
};