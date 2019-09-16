#include "../all.cpp"

// 思路
// 递归平铺，递归函数返回的结果是，子树的最后一个节点位置

class Solution {
public:
    TreeNode* flatten_sub(TreeNode* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return root;
        }
        

        TreeNode* left_end = flatten_sub(root->left);
        TreeNode* right_end = flatten_sub(root->right);
        
        if(left_end!=NULL)
        {
            left_end->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        if(right_end!=NULL)
        {
            return right_end;    
        }
        return left_end;
        
    }
    void flatten(TreeNode* root) {

        if (root == NULL)
        {
            return ;
        }
        flatten_sub(root);

    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}