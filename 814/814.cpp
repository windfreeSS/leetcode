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
    bool can_prune(TreeNode*node)
    {
        if(node==NULL)
        {
            return true;
        }
        int prune_cnt = 0;
        if(can_prune(node->left))    
        {
            delete node->left;
            node->left = NULL;
            ++prune_cnt;
        }
        if(can_prune(node->right))
        {
            delete node->right;
            node->right = NULL;
            ++prune_cnt;
        }
        if(prune_cnt==2 && node->val==0)
        {
            return true;
        }
        return false;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        int prune_cnt = 0;
        if(can_prune(root->left))    
        {
            delete root->left;
            root->left = NULL;
            ++prune_cnt;
        }
        if(can_prune(root->right))
        {
            delete root->right;
            root->right = NULL;
            ++prune_cnt;
        }
        if(prune_cnt==2 && root->val ==0)
        {
            delete root;
            root = NULL;
        }
        return root;
    }
};

// 递归