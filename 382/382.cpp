#include "../all.cpp"

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        curr = org_ = head;
    }

    void move(int n)
    {
        for(int i=0;i<n;++i)
        {
            curr = curr->next;
            if(curr==NULL)
            {
                curr=org_;
            }
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int choice = rand() % 10;
        int remain = 10-choice;
        int ret;
        move(choice);
        ret = curr->val;
        move(remain);
        return ret;

    }
    ListNode* org_;
    ListNode* curr;
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}