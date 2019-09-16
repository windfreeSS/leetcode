#include "../all.cpp"


class Solution {
public:
    TreeNode* gen_binary(ListNode* start,ListNode*end)
    {
        if(start==NULL || start==end)
        {
            return NULL;
        }
        if(start->next == end)
        {
            TreeNode* t_n = new TreeNode(start->val);

            return t_n;
        }



        ListNode* mid = start;
        ListNode* mid_2 = start;
        while(mid_2 !=end  && mid_2->next !=end)
        {
            mid = mid->next;
            mid_2 = mid_2->next->next;
        }

        TreeNode* t_n = new TreeNode(mid->val);
        t_n->left = gen_binary(start,mid);
        t_n->right = gen_binary(mid->next,end);

        return t_n;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        return gen_binary(head,NULL);
    }
};

// 二分划分


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}