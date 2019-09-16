#include "../all.cpp"
class Solution {
public:
    TreeNode* dfs_build(vector<int>& preorder, vector<int>& inorder, int left, int right,int& order)
    {
        if (left >= right)
        {
            return NULL;
        }
        int node_val = preorder[order];
        ++order;
        TreeNode* sub_root = new TreeNode(node_val);
        for (int root_pos = left;root_pos<right; ++root_pos)
        {
            if (inorder[root_pos] != node_val)
            {
                continue;
            }
            sub_root->left = dfs_build(preorder,inorder,left,root_pos,order);
            sub_root->right = dfs_build(preorder,inorder,root_pos+1,right,order);
            break;
        }
        return sub_root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int order = 0;
        return dfs_build(preorder, inorder, 0, preorder.size(),order);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}