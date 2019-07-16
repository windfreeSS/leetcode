#include "../all.cpp"

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL)
        {
            return q==NULL;
        }
        if(q==NULL)
        {
            return false;
        }
        bool flag = p->val == q->val;
        flag = flag && isSameTree(p->left,q->left);
        flag = flag && isSameTree(p->right,q->right);
        return flag;
    }
};

int main()
{
    
}