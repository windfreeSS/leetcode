#include <stdio.h>
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    void connect_by_level(Node* l)
    {
        if (l == NULL || l->left == NULL)
        {
            return ;
        }
        l->left->next = l->right;
        if (l->next)
        {
            l->right->next = l->next->left;
        }
        connect_by_level(l->left);
        connect_by_level(l->right);

    }
    Node* connect(Node* root) {
        connect_by_level(root);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
// 分层遍历
// 如果当前节点，是父节点的左侧子节点，则直接将next指向父节点的右节点即可
// 如果当前节点，是父节点的右侧子节点，则根据父节点的next，先找到堂节点。然后找到堂节点的左侧节点