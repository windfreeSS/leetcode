
 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL
        	|| headB==NULL)
        {
        	return NULL;
        }
        ListNode* it_a = headA;
        ListNode* it_b = headB;
        int len_a = 1;
        int len_b = 1;
        while(it_a->next !=NULL)
        {
        	++len_a;
        	it_a = it_a->next;
        }
        while(it_b->next !=NULL)
        {
        	++len_b;
        	it_b = it_b->next;
        }
        if(it_a!=it_b)
        {
        	return NULL;
        }
        it_a = headA;
        it_b = headB;
        if(len_a>len_b)
        {
        	for(int i=0;i<(len_a-len_b);++i)
        	{
        		it_a = it_a->next;
        	}
        }
        else
        {
        	for(int i=0;i<(len_b-len_a);++i)
        	{
        		it_b = it_b->next;
        	}
        }

        while(true)
        {
        	if(it_b==it_a)
        	{
        		return it_a;
        	}
        	it_a = it_a->next;
        	it_b = it_b->next;
        }
        return NULL;

    }
};

int main()
{

}