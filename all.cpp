#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;

template <typename T>
void print(vector<T>& data)
{
    for(int i=0;i<data.size();++i)
    {
        cout<<data[i]<<",";
    }
    cout<<endl;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

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

void print(ListNode* root)
{
    for(ListNode* it= root;it!=0;it=it->next)
    {
        printf("%d->",it->val);
    }
    printf("null\n");
}

void void_var()
{
    return;
}