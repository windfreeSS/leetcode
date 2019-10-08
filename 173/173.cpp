#include "../all.cpp"

// 题目要求next复杂度为 o(1) ，没有想到好的方法，因为中序遍历完左节点和当前节点后，需要查找右子树的最左节点，此操作可能需要o(h)
// 除非保存中序遍历的每个节点，但是又不符合空间o(H)的要求
// 

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        
    }
    
    /** @return the next smallest number */
    int next() {
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */