#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	bool visitTargetNodeByValue(TreeNode* root,vector<int>& record,int val)
	{
		if(root==NULL)
		{
			return false;
		}
		if(root->val == val)
		{
			record.push_back(val);
			return true;
		}
		record.push_back(root->val);
		bool find_result = visitTargetNodeByValue(root->left,record,val) || visitTargetNodeByValue(root->right,record,val);
		if(!find_result)
		{
			record.pop_back();
			return false;
		}
		return true;
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	vector<int> p_route;
    	vector<int> q_route;

    	// find route of p use dfs
    	visitTargetNodeByValue(root,p_route,p->val);

    	// find route of q
    	visitTargetNodeByValue(root,q_route,q->val);

    	TreeNode* node_it = root;

    	int p_size= p_route.size();
    	int q_size= q_route.size();

    	for(int i=1;;++i) // assume i valid 
    	{
    		if( i>= p_size || i>=q_size)
    		{
    			break;
    		}
    		if(p_route[i]!=q_route[i])
    		{
    			break;
    		}
    		if( (node_it->left!=NULL) && (node_it->left->val == p_route[i]))
    		{
    			node_it=node_it->left;
    		}
    		else //assume right if not left
    		{
    			node_it=node_it->right;
    		}
    	}



        return node_it;
    }
};

int main()
{
	return 0;
}