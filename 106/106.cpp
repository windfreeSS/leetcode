#include "../all.cpp"


class Solution {
public:
    TreeNode* buildSubStree(int in_begin, int in_end, vector<int>& inorder, int&post_pos, vector<int>&postorder)
    {
        if (in_begin >= in_end)
        {
            return NULL;
        }
        int root_pos=-1;
        for(int i = in_begin;i<in_end;++i)
        {
            if(inorder[i]!=postorder[post_pos])
            {
                continue;
            }
            root_pos = i;
            break;
        }
        if(root_pos==-1)
        {
            return NULL;
        }
        TreeNode* sub_node = new TreeNode(inorder[root_pos]);
        --post_pos;
        sub_node->right = buildSubStree(root_pos+1,in_end,inorder,post_pos,postorder);
        sub_node->left  =  buildSubStree(in_begin,root_pos,inorder,post_pos,postorder);

        return sub_node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in_begin = 0;
        int in_end = inorder.size();
        int post_pos = postorder.size() - 1;

        return buildSubStree(in_begin, in_end, inorder, post_pos, postorder);
    }
};
int main()
{
    
}