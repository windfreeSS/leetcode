#include "../all.cpp"



class Solution {
public:
    void walk_tree(TreeNode* node , int pre_val, int&sum)
    {
        pre_val = 10 * pre_val + node->val;
        if (node->left == NULL
                && node->right == NULL)
        {
            sum += pre_val;
            return ;
        }
        if (node->left)
        {
            walk_tree(node->left, pre_val, sum);
        }
        if (node->right)
        {
            walk_tree(node->right, pre_val, sum);
        }


    }
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        int sum = 0 ;
        walk_tree(root, 0, sum);

        return sum;

    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}