#include "../all.cpp"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::list<TreeNode*> bfs_nodes;
        bfs_nodes.push_back(root);
        int val=0;
        while(!bfs_nodes.empty())
        {
            TreeNode* curr = bfs_nodes.front();
            bfs_nodes.pop_front();
            if(curr==NULL)
            {
                continue;
            }
            val = curr->val;
            bfs_nodes.push_back(curr->right);
            bfs_nodes.push_back(curr->left);
        }
        return val;
    }
};

int main()
{

}