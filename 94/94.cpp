#include "../all.cpp"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        list<TreeNode*> visit_list;
        TreeNode* curr_node = root;
        while( (curr_node!=NULL) !visit_list.empty())
        {
            if(curr_node!=NULL)
            {
                visit_list.push_back(curr_node);
                curr_node = curr_node->left;
            }
            else
            {
                curr_node = visit_list.back();
                visit_list.pop_back();
                result.push_back(curr_node->val);
                curr_node=curr_node->right;
            }
        }
        return result;
    }
};

int main()
{

}