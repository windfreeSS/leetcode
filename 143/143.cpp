#include "../all.cpp"

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL
            || head->next==NULL)
        {
            return ;
        }
        //遍历，颠倒序列
        ListNode* one = head;
        ListNode* two =head;
        while(true)
        {
            if(!(two && two->next ))
            {
                break;
            }
            one = one->next;
            two = two->next->next;
        }

        // 开始颠倒
        ListNode* pre = one;
        one = one->next;
        pre->next = NULL;
        while(one)
        {
            ListNode* tmp = one->next;
            one->next = pre;
            pre = one;
            one = tmp;
        }

        one = head;
        two = pre;
        while(two && two !=one && two!=one->next)
        {
            ListNode* tmp = two->next;
            two->next = one->next;
            one->next = two;
            one = one->next->next;
            two = tmp;
        }
        return ;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}