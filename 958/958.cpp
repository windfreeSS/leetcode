#include "../all.cpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 在val中，计算深度，左右深度差
class Solution {
public:
    bool check_tree(TreeNode* node, int&depth, bool& is_full)
    {
        if (node == NULL)
        {
            depth = 0;
            is_full = true;
            return true;
        }

        int left_depth;
        bool left_is_full;
        if (!check_tree(node->left, left_depth, left_is_full))
        {
            return false;
        }
        int right_depth;
        bool right_is_full;
        if (!check_tree(node->right, right_depth, right_is_full))
        {
            return false;
        }
        int diff_depth = left_depth - right_depth;
        if (diff_depth < 0
                || diff_depth > 1)
        {
            return false;
        }
        if (diff_depth == 0)
        {
            if (!left_is_full)
            {
                return false;
            }
            is_full = right_is_full;
        }
        else //diff_depth==1
        {
            if (!right_is_full)
            {
                return false;
            }
            is_full = false;
        }
        depth = left_depth + 1;
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        int depth = 0;
        bool is_full = false;
        return check_tree(root, depth, is_full);
    }
};

int main()
{

}