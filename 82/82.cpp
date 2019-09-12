#include "../all.cpp"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode ln(0);
        ln.next = head;

        ListNode* pre_visit = &ln;
        ListNode* visit = head;
        ListNode* next;

        while (true)
        {
            if (visit == NULL)
            {
                break;
            }
            next = visit->next;
            while (next && next->val == visit->val)
            {
                next = next->next;
            }

            // delete mem
            if (next != visit->next)
            {
                for (ListNode* it = visit;;)
                {
                    ListNode* tmp_n = it;
                    it = it->next;
                    delete tmp_n;
                    if (it == next)
                    {
                        break;
                    }
                }
                visit = next;
                pre_visit->next = visit;
            }
            else
            {
                pre_visit=pre_visit->next;
                visit=pre_visit->next;
            }

        }
        return ln.next;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}