#include "../all.cpp"


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode vir_node(0);
        vir_node.next = head;
        ListNode* small_flag = &vir_node;
        ListNode* big_flag = & vir_node;
        ListNode* it = head;
        while(true)
        {
            if(it==NULL)
            {
                break;
            }

            if(it->val < x )
            {
                if(big_flag==small_flag) //目前为止，都是小的
                {
                    small_flag = small_flag->next;
                    big_flag = small_flag;
                }
                else
                {
                    big_flag->next = it->next;
                    it->next = small_flag->next;
                    small_flag->next = it;
                    small_flag = it;
                }
            }
            else
            {// it->val >=x
                big_flag = it;
            }
            it = big_flag->next;
        }

        return vir_node.next;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}