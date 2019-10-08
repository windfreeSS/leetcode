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
    Node* find_next(Node*l)
    {// 因为此题，可能缺少多个节点，所以，查找节点需要遍历查找
        
         //                 o 
        //                 / \
        //                o   o  
        //               /   / \
        //          (B) o(C)o   o (D)
        //             /       / \
        //        (A) o       o   o
        // 对于上图A处的节点，则不能通过一次next查找到，需要经过B->C->D,然后找到D的right
         
        while(l!=NULL)
        {
            if(l->left!=NULL)
            {
                return l->left;
            }
            if(l->right!=NULL)
            {
                return l->right;
            }
            l = l->next;
        }
        return l;
    }
    void connect_by_level(Node* l)
    {
        if (l == NULL )
        {
            return ;
        }

        if(l->left)
        {
            if(l->right)
            {
                l->left->next = l->right;    
            }
            else if(l->next)
            {
                l->left->next = find_next(l->next);
            }
            
        }

        if (l->right)
        {
            if(l->next)
            {
                l->right->next = find_next(l->next);
            }
        }
        
        connect_by_level(l->right); //与116的区别，需要先递归右侧，可以见 评论区 Angus-Liu 的图解
        connect_by_level(l->left);

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
// 与116题目类似
// 
// 