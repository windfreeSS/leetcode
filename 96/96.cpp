/**
 *
解法见评论。动态规划
假设n个节点存在二叉排序树的个数是G(n)，令f(i)为以i为根的二叉搜索树的个数

即有:G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)

n为根节点，当i为根节点时，其左子树节点个数为[1,2,3,...,i-1]，右子树节点个数为[i+1,i+2,...n]，所以当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i，即f(i) = G(i-1)*G(n-i),

上面两式可得:G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)
 *
 *
 *
 *
 */

#include "../all.cpp"

class Solution {
public:
    int numTrees(int n) {

        vector<int> g_v(n + 1, 0);
        g_v[0] = 1;
        g_v[1] = 1;

        for (int i = 2; i < n + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                g_v[i] += g_v[j] * g_v[i - j - 1];
            }
        }
        return g_v[n];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}