#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历
class Solution {
public:
    bool visitBST(TreeNode* root,bool& has_pre,int & pre_num)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->left!=NULL)
        {
            if(!visitBST(root->left,has_pre,pre_num))
            {
                return false;
            }
        }

        if(!has_pre)
        {
            has_pre= true;
            pre_num=root->val;
        }
        else 
        {
            if(pre_num >=root->val)
            {
                return false;
            }
            pre_num = root->val;
        }

        if(root->right!=NULL)
        {
            if(!visitBST(root->right,has_pre,pre_num))
            {
                return false;
            }

        }
        
        return true;

    }

    bool isValidBST(TreeNode* root) {
        bool has_pre = false;
        int pre_num=0;
        return visitBST(root,has_pre,pre_num);
    }
};

int main()
{

}