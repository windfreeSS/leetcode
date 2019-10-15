/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if ((N & 0x01) == 0)
        {
            return vector<TreeNode*>();
        }
        vector<TreeNode*> vt;
        if(N==1)
        {
            TreeNode* tn = new TreeNode(0);
            vt.push_back(tn);
            return vt;
        }
        
        for (int i = 1; i < N; i += 2)
        {
            // printf("i:%d\n",i);
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N - i - 1);
            // printf("N:%d,left:%d,right:%d\n",N,left.size(),right.size());
            for (int li = 0; li < left.size(); ++li)
            {
                for (int ri = 0; ri < right.size(); ++ri)
                {
                    TreeNode* tn = new TreeNode(0);
                    tn->left = left[li];
                    tn->right = right[ri];
                    vt.push_back(tn);
                }
            }
        }
        return vt;
    }
};