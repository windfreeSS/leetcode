#include "../all.cpp"


class Solution {
public:
    TreeNode* buildSubStree(int in_begin, int in_end, vector<int>& inorder, int&post_pos, vector<int>&postorder)
    {
        if (in_begin >= in_end)
        {
            return NULL;
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in_begin = 0;
        int in_end = inorder.size();
        int post_pos = postorder.size() - 1;

        return buildSubStree(in_begin, in_end, inorder, post_pos, postorder);
    }
};