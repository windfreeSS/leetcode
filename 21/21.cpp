#include <iostream>


struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==0)
        {
            return l2;
        }
        if(l2==0)
        {
            return l1;
        }
        ListNode* head_node;
        if( (l1->val) > (l2->val) )
        {
            head_node = l2;
            l2=l2->next;
        }
        else
        {
            head_node=l1;
            l1=l1->next;
        }
        ListNode* tail_node = head_node;
        while(true)
        {
            if(l1==0)
            {
                break;
            }
            if(l2==0)
            {
                break;
            }
            if((l1->val) < (l2->val) )
            {
                tail_node->next = l1;
                tail_node=tail_node->next;
                l1=l1->next;
            }
            else
            {
                tail_node->next = l2;
                tail_node=tail_node->next;
                l2=l2->next;
            }
        }
        if(l1!=0)
        {
            tail_node->next = l1;
        }
        else if(l2!=0)
        {
            tail_node->next = l2;
        }
        return head_node;
    }
};

int main()
{

}