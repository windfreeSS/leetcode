#include "../all.cpp"

// iterate

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result ;
        list<TreeNode*> node_queue;
        node_queue.push_back(root);

        while(!node_queue.empty())
        {
            TreeNode* curr_node = node_queue.front();
            node_queue.pop_front();
            if(curr_node==NULL)
            {
                continue;
            }
            result.push_back(curr_node->val);
            node_queue.push_front(curr_node->right);
            node_queue.push_front(curr_node->left);
        }
        return result;
    }
};

int main()
{
    
}