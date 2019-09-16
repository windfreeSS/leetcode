
#include "../all.cpp"


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)        
        {
            return head;
        }

        ListNode vir_node(0);
        vir_node.next = head;

        ListNode* pre_node = &vir_node;
        for(int i=0;i<m-1;++i)
        {
            pre_node = pre_node->next;
        }   
        ListNode* m_node = pre_node->next;
        ListNode* flag;

        for(int i=m;i<n;++i)
        {
            flag = pre_node->next;
            pre_node->next = m_node->next;
            m_node->next = m_node->next->next;
            pre_node->next->next = flag;
        }

        return vir_node.next;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}