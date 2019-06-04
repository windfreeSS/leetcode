#include "../all.cpp"

class Solution_V1 {
public:
    ListNode* oddEvenList_v1(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* odd_node_root = head;
        ListNode* even_node_root = head;
        ListNode* tail_node = NULL;
        while (true)
        {
            if (even_node_root->next == NULL
                    || even_node_root->next->next == NULL)
            {
                break;
            }
            even_node_root = even_node_root->next->next;
        }
        tail_node = even_node_root->next;

        ListNode* odd_it = odd_node_root;
        ListNode* even_it = even_node_root;
        while (true)
        {
            if (odd_it == even_node_root)
            {
                break;
            }
            even_it->next = odd_it->next;
            odd_it->next = odd_it->next->next;

            even_it = even_it->next;
            odd_it = odd_it->next;

        }
        even_it->next = tail_node;
        return odd_node_root;
    }
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* even_root = head->next;
        ListNode* even_it = even_root;
        ListNode* odd_it = head;
        while(true)
        {
            if( odd_it->next==NULL ||
                odd_it->next->next==NULL)
            {
                break;
            }
            odd_it->next = odd_it->next->next;
            odd_it = odd_it->next;
            even_it->next = odd_it->next;
            even_it = even_it->next;
           
        }
        odd_it->next = even_root;
        return head;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* even_root = head->next;
        ListNode* even_it = even_root;
        ListNode* odd_it = head;
        while(true)
        {
            if( odd_it->next==NULL ||
                odd_it->next->next==NULL)
            {
                break;
            }
            odd_it->next = odd_it->next->next;
            odd_it = odd_it->next;
            even_it->next = odd_it->next;
            even_it = even_it->next;
           
        }
        odd_it->next = even_root;
        return head;
    }
};

int main()
{
    vector<int> data = {1, 2, 3, 4, 5};
    ListNode* root = gen_list(data);
    Solution s;
    ListNode* result = s.oddEvenList(root);
    print(result);

}