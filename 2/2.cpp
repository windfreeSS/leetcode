/*
* @Author: 朱亚冰
* @Date:   2018-11-19
* @Last Modified by:   windf
* @Last Modified time: 2018-11-20
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <time.h>
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };




class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(l1->val + l2->val);
        result->next = 0;

        ListNode* it_result = result;
        ListNode* it_l1 = l1->next;
        ListNode* it_l2 = l2->next;

        int to_add = (it_result->val) / 10;
        it_result->val = (it_result->val) % 10;

        while (it_l1 != 0
                && it_l2 != 0)
        {
            to_add = to_add + (it_l1->val + it_l2->val);
            ListNode* new_node = new ListNode(to_add % 10);
            to_add = to_add / 10;
            new_node->next = 0;
            it_result->next = new_node;

            it_result = it_result->next;
            it_l1 = it_l1->next;
            it_l2 = it_l2->next;
        }

        ListNode* remain_it = 0;
        if (it_l1 == 0)
        {
            remain_it = it_l2;
        }
        else if (it_l2 == 0)
        {
            remain_it = it_l1;
        }

        while (remain_it != 0)
        {
            to_add = to_add + remain_it->val;
            ListNode* new_node = new ListNode(to_add % 10);
            to_add = to_add / 10;
            new_node->next = 0;
            it_result->next = new_node;

            it_result = it_result->next;
            remain_it = remain_it->next;
        }
        if (to_add != 0)
        {
            ListNode* new_node = new ListNode(to_add);
            new_node->next = 0;
            it_result->next = new_node;
            it_result = it_result->next;
        }
        return result;
    }
};

int FillNode(ListNode*&node_head,char* digit_str)
{
    int digit_len = strlen(digit_str);
    node_head = new ListNode(digit_str[0]-'0');
    node_head->next = 0;
    ListNode* node_it = node_head;

    for(int i=1;i<digit_len;++i)
    {
        ListNode* one_node = new ListNode(digit_str[i]-'0');
        one_node->next = 0;
        node_it->next = one_node;
        node_it = node_it->next;
    }
    return 0;
}
void PrintListNode(ListNode* ln)
{
    ListNode* node_it = ln;
    while(node_it)
    {
        printf("%d",node_it->val);
        node_it = node_it->next;
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    ListNode* l1=0;
    ListNode* l2=0;

    clock_t t1 = clock();
    
        FillNode(l1,argv[1]);
        FillNode(l2,argv[2]);
    
    

    clock_t t2 = clock();
    Solution ss;

    
        ListNode* result = ss.addTwoNumbers(l1,l2);    
    
    
    // PrintListNode(result);
    clock_t t3 = clock();

    // printf("%d vs %d \n",t2-t1,t3-t2);
    return 0;
}