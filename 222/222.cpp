#include "../all.cpp"

// 先遍历最左侧，得出深度。
// 再依次从最右侧遍历，直到其深度和最左侧一样
// 最快的答案，竟然是遍历，

class Solution {
public:
    void count_depth(TreeNode* node,int&dep)
    {
        if(node==NULL)
        {
            return ;
        }
        ++dep;
        count_depth(node->left,dep);
    }
    bool count_right_lacks(TreeNode*node ,const int& depth,int level,int& lack)
    {
        if(node==NULL)
        {
            if(level==depth)
            {
                return true;
            }
            ++lack;
            return false;
        }
        return count_right_lacks(node->right,depth,level+1,lack) || count_right_lacks(node->left,depth,level+1,lack);
    }
    int countNodes(TreeNode* root) {
        int depth = 0;
        int lack = 0;
        count_depth(root,depth);
        count_right_lacks(root,depth,0,lack);

        long long ret = (1<<(depth)) - 1;
        ret -= lack;

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}