#include "../all.cpp"


//dp solution,与96题基本一样

class Solution {
public:
    vector<TreeNode*> solution_dp(int n ,int base_num)
    {
        if (n <= 0 )
        {
            vector<TreeNode*> result;
            result.push_back(NULL);
            return result; 
        }
        if (n == 1)
        {
            TreeNode* c_n = new TreeNode(1+base_num);
            vector<TreeNode*> result;
            result.push_back(c_n);
            return result;
        }
        vector<TreeNode*> result;
        for(int i=0;i<n;++i)
        {
            vector<TreeNode*> left = solution_dp(i,base_num);
            vector<TreeNode*> right = solution_dp(n-i-1,i+1+base_num);
            for(int l_i =0;l_i<left.size();++l_i)
            {
                for(int r_i=0;r_i<right.size();++r_i)
                {
                    TreeNode* tr = new TreeNode(i+1+base_num);
                    tr->left = left[l_i];
                    tr->right= right[r_i];
                    result.push_back(tr);
                }
            }
        }

        return result;

    }

    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
        {
            return vector<TreeNode*>();
        }
        return solution_dp(n,0);
    }
};

int main()
{
    Solution s;
    vector<TreeNode*> data = s.generateTrees(4);
    cout << data.size() << endl;
}