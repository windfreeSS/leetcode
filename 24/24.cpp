#include <iostream>
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	if(head==NULL)
    	{
    		return NULL;
    	}
    	ListNode* virtual_node = new ListNode(0);
    	virtual_node->next= head;
    	ListNode* pre =virtual_node;
    	ListNode* next = head;
    	while(true)
    	{
    		if(pre->next==NULL 
    			|| next->next==NULL)
    		{
    			break;
    		}
    		pre->next = next->next;
    		next->next =next->next->next;
    		pre->next->next = next;

    		pre = pre->next->next ;
    		next = pre->next;
    	}

    	ListNode* result = virtual_node->next;
    	delete virtual_node;
    	return result;
     
    }
};

int main()
{

}