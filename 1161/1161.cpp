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
    void add_level(TreeNode* node ,vector<long long>& lvl_sum,int lvl)
    {
        if(node==NULL)
        {
            return ;
        }
        if(lvl_sum.size()<lvl)
        {
            lvl_sum.push_back(0);
        }
        lvl_sum[lvl-1] += node->val;
        add_level(node->left,lvl_sum,lvl+1);
        add_level(node->right,lvl_sum,lvl+1);
    }
    int maxLevelSum(TreeNode* root) {
        vector<long long> lvl_sum;
        add_level(root,lvl_sum,1);
        int ret = 0;
        for(int i=1;i<lvl_sum.size();++i)
        {
            if(lvl_sum[i]>lvl_sum[ret])
            {
                ret = i;
            }
        }
        return (ret+1);
    }
};