#include "../all.cpp"

//回溯+剪枝
//
class Solution {
public:
    void tree_backtrack(TreeNode* node , int target, vector<int>&track, vector<vector<int>>& result)
    {
        if (node == NULL)
        {
            return ;
        }
        target -= node->val;
        track.push_back(node->val);
        if (node->left == NULL
                && node->right == NULL)
        {
            if (target == 0)
            {
                result.push_back(track);
            }
            track.pop_back();
            return ;
        }

        
        tree_backtrack(node->left, target, track, result);
        tree_backtrack(node->right, target, track, result);
        track.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> track;
        tree_backtrack(root, sum, track, result);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}