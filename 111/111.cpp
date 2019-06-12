#include "../all.cpp"
#include <list>
class Solution {
public:
	bool visit_bfs(list<TreeNode*>& curr,list<TreeNode*>&next)
	{
		next.clear();
		for(list<TreeNode*>::iterator it = curr.begin();it!=curr.end();++it)
		{
			TreeNode* visit_node = (*it);
			if(visit_node->left ==NULL
				&& visit_node->right==NULL)
			{
				return true;
			}
			if(visit_node->left!=NULL)
			{
				next.push_back(visit_node->left);	
			}
			if(visit_node->right!=NULL)
			{
				next.push_back(visit_node->right);
			}
			
		}
		curr.clear();
		return false;
	}
    int minDepth(TreeNode* root) {
    	if(root==NULL)
    	{
    		return 0;
    	}
    	int depth =0;
        bool is_odd = true;
        bool break_visit = false;
        list<TreeNode*> odd_list;
        list<TreeNode*> even_list;

        odd_list.push_back(root);
        while(true)
        {
        	if(is_odd)
        	{
        		break_visit = visit_bfs(odd_list,even_list);
        	}else
        	{
        		break_visit = visit_bfs(even_list,odd_list);
        	}
        	++depth;
        	if(break_visit)
        	{
        		break;
        	}
        	is_odd=!is_odd;
        }

        return depth;

    }
};

int main()
{

}