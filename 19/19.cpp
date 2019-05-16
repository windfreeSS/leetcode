#include <iostream>
#include <vector>
using namespace std;
// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
// 题目的关键在于，是用两个指针保持遍历，这两个指针的间隔为n
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// version 2
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* target_node = 0;
        ListNode* target_pre_node =0;
        ListNode* node_it = head;
        int i=0;
        while(i<n)
        {
            node_it=node_it->next;
            ++i;
        }
        target_node = head;
        while(node_it!=0)
        {
            target_pre_node=target_node;
            target_node=target_node->next;
            node_it=node_it->next;
        }
        if(target_node==head)
        {
            ListNode* del_node = head;
            head = head->next;
            delete del_node;
            return head;
        }
        target_pre_node->next = target_node->next;
        delete target_node;
        return head;

    }
};

// version 1
class Solution_V1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> tmp_info;
        ListNode* node_it = head;
        while(node_it!=0)
        {
            tmp_info.push_back(node_it);
            node_it = node_it->next;
        }

        int node_size = tmp_info.size();
        if(n==node_size)
        {
            ListNode* del_node = head;
            head = head->next;
            delete del_node;
            return head;
        }

        ListNode* del_node = tmp_info[node_size-n];
        tmp_info[node_size-n-1]->next = tmp_info[node_size-n]->next;
        delete del_node;
        return head;
    }
};
