#include "../all.cpp"

class Solution {
    vector<int> ret;
public:
    void visit(TreeNode* node)
    {
        if(node==NULL)
        {
            return ;
        }
        ret.push_back(node->val);
        if(node->right)
        {
            visit(node->right);
        }
        else
        {
            visit(node->left);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        visit(root);
        return ret;
    }
};