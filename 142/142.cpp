#include <iostream>
#include <vector>
using namespace std;

 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 // 只适用于，后续节点地址(堆中分配)，逐步递增的情况
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	if(head==0)
    	{
    		return 0;
    	}
    	while(true)
    	{
    		if(head->next==0)
    		{
    			return 0;
    		}
    		if(head->next <= head)
    		{
    			return head->next;
    		}
    		head=head->next;
    	}
    	return 0;
        
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
	for(ListNode* it= root;it!=0;it=it->next)
	{
		printf("%p\n",it);
	}
}

int main()
{
	vector<int> data = {123,23,23,232,323,323,23232,323};
	ListNode * root = gen_list(data);
	print(root);
}