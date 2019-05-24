#include <iostream>
#include <vector>
using namespace std;
// 双指针
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if(head==0)
    	{
    		return 0;
    	}
    	int node_count = 0;
    	for(ListNode* it = head;it!=0;it=it->next)
    	{
    		++node_count;
    	}
    	int move_step = k%node_count;
    	if(move_step==0)
    	{
    		return head;
    	}

    	ListNode* virtual_node = new ListNode(0);
    	virtual_node->next = head;

        ListNode* move_right_edge = head;
        ListNode* move_left_edge_before = head;
        for(int i=0;i<move_step;++i)
        {
        	move_right_edge = move_right_edge->next;
        }
        for(int i=move_step;i<node_count-1;++i)
        {
        	move_right_edge = move_right_edge->next;
        	move_left_edge_before = move_left_edge_before->next;
        }
        move_right_edge->next = virtual_node->next;
        virtual_node->next = move_left_edge_before->next;
        move_left_edge_before->next = 0;


     	ListNode* result = virtual_node->next;
     	delete virtual_node;
     	return result;

    }
};


ListNode* gen_list(vector<int> data)
{
	ListNode* root_node = new ListNode(data[0]);
	ListNode* result = root_node;
	for(int i=1;i<data.size();++i)
	{
		root_node->next= new ListNode(data[i]);
		root_node = root_node->next;
	}

	return result;
}

void print(ListNode* root)
{
	for(ListNode* root_it=root;root_it!=0;root_it=root_it->next)
	{
		printf("%d->",root_it->val);
	}
	cout<<endl;
}

int main()
{
	vector<int> data={1,2,3};
	ListNode* root = gen_list(data);
	Solution s;
	ListNode* result = s.rotateRight(root,10);
	print(result);
	return 0;
}