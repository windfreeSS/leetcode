#include <iostream > 
#include <vector>
using namespace std;



struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
void print(ListNode* root);

class Solution {
public:
	ListNode* sortVirtualList(ListNode* virtual_first,ListNode* virtual_second,int sort_size)
	{
		int first_step=0;
		int second_step=0;
		int sorted_num = 0;
		ListNode* first_pre_it = virtual_first;
		ListNode* second_pre_it = virtual_second;
		ListNode* first_it = first_pre_it->next;
		ListNode* second_it = second_pre_it->next;
		while(true)
		{
			if(second_step >=sort_size
				|| first_step >= sort_size)
			{
				break;
			}
			if(second_pre_it->next==0
			|| first_pre_it->next==0 )
			{
				break;
			}
			
			first_it = first_pre_it->next;
			second_it = second_pre_it->next;

			if(sorted_num>=(2*sort_size-1))
			{
				break;
			}
			
			if(first_it->val >  second_it->val)
			{
				second_pre_it->next = second_it->next;
				second_it->next = first_pre_it->next;
				first_pre_it->next = second_it;
				first_pre_it = first_pre_it->next;

				++sorted_num;
				++second_step;
				continue;
			}
			else
			{
				first_pre_it = first_pre_it->next;
				++first_step;
				++sorted_num;
				continue;
			}
		}
		while(second_step<sort_size)
		{
			if(second_pre_it->next==0)
			{
				break;
			}
			++second_step;
			second_pre_it=second_pre_it->next;
		}
		return second_pre_it;
	}
    ListNode* sortList(ListNode* head) {
    	if(head==0 || head->next==0)
    	{
    		return head;
    	}
    	int node_size =0;
    	for(ListNode* it = head;it!=0;it=it->next)
    	{
    		++node_size;
    	}

    	ListNode* virtual_head = new ListNode(0);
    	virtual_head->next= head;

        int step=1;
        ListNode* pre_sorted_head;
        ListNode* next_sorted_head;

        while(step < node_size)
        {
        	next_sorted_head  = virtual_head;
        	while(true)
        	{
        		pre_sorted_head = next_sorted_head;
        		for(int i=0;i<step;++i)
        		{
        			if(next_sorted_head->next==0)
        			{
        				break;
        			}
        			next_sorted_head=next_sorted_head->next;
        		}
        		if(next_sorted_head->next==0)
        		{
        			break;
        		}

        		next_sorted_head = sortVirtualList(pre_sorted_head,next_sorted_head,step);
        	}
        	step<<=1;
        	cout<<endl<<endl;
        }
        ListNode* result= virtual_head->next;
        delete virtual_head;
        return result;
    }
};

void print(ListNode* root)
{
	for(ListNode* root_it=root;root_it!=0;root_it=root_it->next)
	{
		printf("%d->",root_it->val);
	}
	cout<<endl;
}

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

int main()
{
	vector<int> data={324,234,4,12312,31231,3123,123,1231,2313,123,1231,100,200,300,500,800,99,98,97,9,8,7,6,5,4,3,2,1};
	ListNode* root = gen_list(data);
	
	print(root);

	Solution s;

	ListNode* sort_root = s.sortList(root);
	
	for(ListNode* root_it=sort_root;root_it!=0;root_it=root_it->next)
	{
		printf("%d->",root_it->val);
	}
	return 0;
}