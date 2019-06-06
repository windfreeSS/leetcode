#include "../all.cpp"
 
class Solution {
public:
    int visit_post_order(TreeNode* node,int &sum)
    {
        if(node==0)
        {
            return 0;
        }
        int left_child_remain = visit_post_order(node->left,sum);
        int right_child_remain = visit_post_order(node->right,sum);

        sum+=abs(left_child_remain);
        sum+=abs(right_child_remain);
        return (node->val+left_child_remain+right_child_remain-1);

    }
    int distributeCoins(TreeNode* root) {
        int sum=0;
        visit_post_order(root,sum);
        return sum;
    }
};
int main()
{
    Solution s;
    
}