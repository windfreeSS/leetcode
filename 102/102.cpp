#include "../all.cpp"

#include <list>
class Solution {
public:
	bool visit_bfs(list<TreeNode*>& curr,list<TreeNode*>&next,vector<vector<int>>& result)
	{
		vector<int> data;
		next.clear();
		for(list<TreeNode*>::iterator it = curr.begin();it!=curr.end();++it)
		{
			TreeNode* &visit_node = (*it);
			if(visit_node==NULL)
			{
				continue;
			}
			data.push_back(visit_node->val);
			next.push_back(visit_node->left);
			next.push_back(visit_node->right);
		}
		if(next.empty())
		{
			return false;
		}
		curr.clear();
		result.push_back(data);
		return true;
	}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bool is_odd = true;
        bool visit_ok = true;
        list<TreeNode*> odd_list;
        list<TreeNode*> even_list;

        odd_list.push_back(root);
        while(true)
        {
        	if(is_odd)
        	{
        		visit_ok = visit_bfs(odd_list,even_list,result);
        	}
        	else
        	{
        		visit_ok = visit_bfs(even_list,odd_list,result);
        	}
        	if(!visit_ok)
        	{
        		break;
        	}
        	is_odd = !is_odd;
        }
        return result;

    }
};
int main()
{
	int val = 12;
	int &n = val;
	printf("%p,%p\n",&val,&n);

	char *ptr = new char[10];
	char *ptr1 = ptr;
	char *&ptr2=ptr;
	printf("%p,%p,%p\n",ptr,ptr1,ptr2);
	printf("%p,%p,%p\n",&ptr,&ptr1,&ptr2);
}