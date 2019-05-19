#include<iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//use recursion
class Solution {
public:
	bool inorderVisitKth(TreeNode* curr_node ,int& count,int k,int& val)
	{
		if(count==k)
		{
			return true;
		}
		if(curr_node==0)
		{
			return false;
		}
		if(inorderVisitKth(curr_node->left,count,k,val))
		{
			return true;
		}
		val = curr_node->val;
		++count;
		if(count==k)
		{
			return true;
		}
		if(inorderVisitKth(curr_node->right,count,k,val))
		{
			return true;
		}
		return false;


	}
    int kthSmallest(TreeNode* root, int k) {
    	int result;
    	int count=0;
    	inorderVisitKth(root,count,k,result);
    	return result;
    }
};

 
class Solution_v1 {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> in_order_visit;
        vector<int> tree_data;
        map<int,int> visit_state; // 0 left 1 self 2 right
        TreeNode* visit_it = root;
        while(visit_it!=0)
        {
        	visit_state[visit_it->val] = 1;
        	in_order_visit.push_back(visit_it);
        	visit_it=visit_it->left;

        }
        int target_num=0;
        int visit_count=0;
        // in order 
        while(visit_count < k)
        {
        	TreeNode* top_node = in_order_visit.back();
        	if(visit_state[top_node->val]==0)
        	{
        		visit_state[top_node->val]=1;
        		if(top_node->left!=0)
        		{
        			in_order_visit.push_back(top_node->left);
        		}
     
        		continue;
        	}
        	else if( visit_state[top_node->val]==1)//self
        	{        		
    			visit_state[top_node->val]=2;
    			target_num = top_node->val;
    			++visit_count;
    			continue;
        
        	}
        	else if(visit_state[top_node->val]==2)//right
        	{
        		if(top_node->right==0)
        		{
        			in_order_visit.pop_back();
        			continue;
        		}
        		else
        		{
        			in_order_visit.push_back(top_node->right);
        			visit_state[top_node->right->val]=0;
        			++visit_state[top_node->val];
        			continue;	
        		}
        	}
        	else
        	{
        		in_order_visit.pop_back();
        	}
        }
        return target_num;
    }
};


int main()
{

}