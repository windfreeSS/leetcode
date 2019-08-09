#include "../all.cpp"


class SolutionV_1 {
public:
    void visitTreeByLevel(vector<vector<int>>& result, bool left2right, list<TreeNode*>& node_list)
    {
        vector<int> level_data;
        list<TreeNode*> level_nodes;
        if(node_list.empty())
        {
            return ;
        }

        for (list<TreeNode*>::iterator it = node_list.begin(); it != node_list.end(); ++it)
        {
            TreeNode* &curr_node = *it;
            level_data.push_back(curr_node->val);
            if (left2right)
            {
                curr_node->left != NULL ? level_nodes.push_front(curr_node->left) : void_var();
                curr_node->right != NULL ? level_nodes.push_front(curr_node->right) : void_var();
            }
            else
            {
                curr_node->right != NULL ? level_nodes.push_front(curr_node->right) : void_var();
                curr_node->left != NULL ? level_nodes.push_front(curr_node->left) : void_var();
            }

        }
        result.push_back(level_data);
        visitTreeByLevel(result, !left2right, level_nodes);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }
        list<TreeNode*> node_list;
        node_list.push_back(root);
        visitTreeByLevel(result, true, node_list);
        return result;
    }
};


class Solution {
public:
    void visitTreeByLevel(vector<vector<int>>& result, int lvl,bool left2right, TreeNode* node)
    {
        if(node==NULL)
        {
            return ;
        }
        if(result.size()<lvl)
        {
            result.push_back(vector<int>());
        }
        if(left2right)
        {
            result[lvl-1].insert(result[lvl-1].begin(),node->val);
        }
        else
        {
            result[lvl-1].push_back(node->val);
        }
        visitTreeByLevel(result,lvl+1,!left2right,node->right);
        visitTreeByLevel(result,lvl+1,!left2right,node->left);

        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        visitTreeByLevel(result,1, true, root);
        return result;
    }
};

int main()
{

}